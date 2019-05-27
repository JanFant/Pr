#ifndef SCM_H
#define SCM_H
// Подсистема scm:SCM
static char SimulOn=0;
static short CodeSub=1;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 3476
static char BUFFER[3476];

#define B1IC01UDU	 BUFFER[0]	//( - , SDu) Координата штока ББ2
#define idB1IC01UDU	 1	//( - , SDu) Координата штока ББ2
#define A1IC01UDU	 BUFFER[5]	//( - , SDu) Координата штока ББ1
#define idA1IC01UDU	 2	//( - , SDu) Координата штока ББ1
#define A1IS12LDU	 BUFFER[10]	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define idA1IS12LDU	 3	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define A1IS11LDU	 BUFFER[12]	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define idA1IS11LDU	 4	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define A1IS21LDU	 BUFFER[14]	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define idA1IS21LDU	 5	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define B6IS21LDU	 BUFFER[16]	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define idB6IS21LDU	 6	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define B6IS11LDU	 BUFFER[18]	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define idB6IS11LDU	 7	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define A6IS21LDU	 BUFFER[20]	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define idA6IS21LDU	 8	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define A6IS11LDU	 BUFFER[22]	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define idA6IS11LDU	 9	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define A8IS12LDU	 BUFFER[24]	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define idA8IS12LDU	 10	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define A8IS22LDU	 BUFFER[26]	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define idA8IS22LDU	 11	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define B8IS12LDU	 BUFFER[28]	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 12	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define B8IS22LDU	 BUFFER[30]	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define idB8IS22LDU	 13	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define R4IS12LDU	 BUFFER[32]	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define idR4IS12LDU	 14	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define R4IS22LDU	 BUFFER[34]	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define idR4IS22LDU	 15	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define R4IS21LDU	 BUFFER[36]	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define idR4IS21LDU	 16	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define R4IS11LDU	 BUFFER[38]	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define idR4IS11LDU	 17	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define R0IS02LDU	 BUFFER[40]	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define idR0IS02LDU	 18	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define R0EE04LZ2	 BUFFER[42]	//( - , SBz2) Питание  АКНП4  отключить
#define idR0EE04LZ2	 19	//( - , SBz2) Питание  АКНП4  отключить
#define R0EE03LZ2	 BUFFER[44]	//( - , SBz2) Питание  АКНП3  отключить
#define idR0EE03LZ2	 20	//( - , SBz2) Питание  АКНП3  отключить
#define R0EE02LZ2	 BUFFER[46]	//( - , SBz2) Питание  АКНП  отключить
#define idR0EE02LZ2	 21	//( - , SBz2) Питание  АКНП  отключить
#define R0EE04LZ1	 BUFFER[48]	//( - , SBz1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 22	//( - , SBz1) Питание  АКНП4  отключить
#define R0EE03LZ1	 BUFFER[50]	//( - , SBz1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 23	//( - , SBz1) Питание  АКНП3  отключить
#define R0EE02LZ1	 BUFFER[52]	//( - , SBz1) Питание  АКНП  отключить
#define idR0EE02LZ1	 24	//( - , SBz1) Питание  АКНП  отключить
#define R0EE01LZ2	 BUFFER[54]	//( - , SBz2) Питание  АКНП1  отключить
#define idR0EE01LZ2	 25	//( - , SBz2) Питание  АКНП1  отключить
#define R0EE01LZ1	 BUFFER[56]	//( - , SBz1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 26	//( - , SBz1) Питание  АКНП1  отключить
#define B4IS10LDU	 BUFFER[58]	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define idB4IS10LDU	 27	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define A4IS10LDU	 BUFFER[60]	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define idA4IS10LDU	 28	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define B1IE04LDU	 BUFFER[62]	//( - , SCM) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 29	//( - , SCM) Движение ББ2 назад (от БУШД)
#define B1IE03LDU	 BUFFER[64]	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 30	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[66]	//( - , SCM) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 31	//( - , SCM) Движение ББ1 назад (от БУШД)
#define A1IE03LDU	 BUFFER[68]	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 32	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define B1IS12LDU	 BUFFER[70]	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define idB1IS12LDU	 33	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define B1IS11LDU	 BUFFER[72]	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define idB1IS11LDU	 34	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define B1IS21LDU	 BUFFER[74]	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define idB1IS21LDU	 35	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define B2IC01UDU	 BUFFER[76]	//( - , SDu) Координата штока РБ2
#define idB2IC01UDU	 36	//( - , SDu) Координата штока РБ2
#define B2IS12LDU	 BUFFER[81]	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 37	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define B2IS11LDU	 BUFFER[83]	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define idB2IS11LDU	 38	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define B2IS21LDU	 BUFFER[85]	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define idB2IS21LDU	 39	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define B9IS21LDU	 BUFFER[87]	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 40	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define B9IS11LDU	 BUFFER[89]	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 41	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define A9IS21LDU	 BUFFER[91]	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 42	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define A9IS11LDU	 BUFFER[93]	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 43	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define B5IS21LDU	 BUFFER[95]	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define idB5IS21LDU	 44	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define B5IS11LDU	 BUFFER[97]	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define idB5IS11LDU	 45	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define A5IS21LDU	 BUFFER[99]	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define idA5IS21LDU	 46	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define A5IS11LDU	 BUFFER[101]	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define idA5IS11LDU	 47	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define B0VP81LZZ	 BUFFER[103]	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 48	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define A0VP81LZZ	 BUFFER[105]	//(do32_pti:110 - K03DO, - ) Давление АЗ1 в норме
#define idA0VP81LZZ	 49	//(do32_pti:110 - K03DO, - ) Давление АЗ1 в норме
#define B8IC01UDU	 BUFFER[107]	//( - , SDu) Координата АЗ2, мм
#define idB8IC01UDU	 50	//( - , SDu) Координата АЗ2, мм
#define A8IC01UDU	 BUFFER[112]	//( - , SDu) Координата ДС2
#define idA8IC01UDU	 51	//( - , SDu) Координата ДС2
#define R6IS68LZZ	 BUFFER[117]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 52	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define B4VP82LDU	 BUFFER[119]	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 53	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define A4VP82LDU	 BUFFER[121]	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 54	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define R2IS21LDU	 BUFFER[123]	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define idR2IS21LDU	 55	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define R2IS11LDU	 BUFFER[125]	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define idR2IS11LDU	 56	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define R1IS21LDU	 BUFFER[127]	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define idR1IS21LDU	 57	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define R1IS11LDU	 BUFFER[129]	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define idR1IS11LDU	 58	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define B4IS21LDU	 BUFFER[131]	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define idB4IS21LDU	 59	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define B4IS11LDU	 BUFFER[133]	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define idB4IS11LDU	 60	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define R8IS11LDU	 BUFFER[135]	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define idR8IS11LDU	 61	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define A4IS21LDU	 BUFFER[137]	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define idA4IS21LDU	 62	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define A4IS11LDU	 BUFFER[139]	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define idA4IS11LDU	 63	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define R5IS21LDU	 BUFFER[141]	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 64	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define R5IS11LDU	 BUFFER[143]	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 65	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define R3IS21LDU	 BUFFER[145]	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 66	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define R3IS11LDU	 BUFFER[147]	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 67	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define B2VP82LDU	 BUFFER[149]	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 68	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define B2IP01IZ2	 BUFFER[151]	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 69	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define B2IP01IZ1	 BUFFER[154]	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 70	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define R0MW11IP1	 BUFFER[157]	//( - , SCM) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 71	//( - , SCM) Переключатель ВЫСТРЕЛ
#define R0IS01FI0	 BUFFER[160]	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define idR0IS01FI0	 72	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define A0IT03IRP	 BUFFER[162]	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define idA0IT03IRP	 73	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define B0IT03IRP	 BUFFER[165]	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define idB0IT03IRP	 74	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define R0IN03FI3	 BUFFER[168]	//( - , SA3) Выход КНК53М Гц от ПТИ
#define idR0IN03FI3	 75	//( - , SA3) Выход КНК53М Гц от ПТИ
#define R0IN02FI3	 BUFFER[173]	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI3	 76	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI2	 BUFFER[178]	//( - , SA2) Выход КНК53М Гц от ПТИ
#define idR0IN03FI2	 77	//( - , SA2) Выход КНК53М Гц от ПТИ
#define R0IN07RIP	 BUFFER[183]	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define idR0IN07RIP	 78	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define R0IN06RIP	 BUFFER[188]	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define idR0IN06RIP	 79	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define TerR0IN06FRP	 BUFFER[193]	//( - , - ) Неисправности СНМ-11 -1,2
#define idTerR0IN06FRP	 80	//( - , - ) Неисправности СНМ-11 -1,2
#define R0IN03RIP	 BUFFER[196]	//( - , SRP) Выход КНК53М Гц от ПТИ
#define idR0IN03RIP	 81	//( - , SRP) Выход КНК53М Гц от ПТИ
#define R0IN02RIP	 BUFFER[201]	//( - , SRP) Выход КНК15- Гц от ПТИ
#define idR0IN02RIP	 82	//( - , SRP) Выход КНК15- Гц от ПТИ
#define R0IN01RIP	 BUFFER[206]	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define idR0IN01RIP	 83	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define R0IN02FI2	 BUFFER[211]	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI2	 84	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI1	 BUFFER[216]	//( - , SA1) Выход КНК53М Гц от ПТИ
#define idR0IN03FI1	 85	//( - , SA1) Выход КНК53М Гц от ПТИ
#define R0IN02FI1	 BUFFER[221]	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI1	 86	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI4	 BUFFER[226]	//( - , SA4) Выход КНК53М Гц от ПТИ
#define idR0IN03FI4	 87	//( - , SA4) Выход КНК53М Гц от ПТИ
#define B0SN07RIM	 BUFFER[231]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define idB0SN07RIM	 88	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define B0SN06RIM	 BUFFER[236]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define idB0SN06RIM	 89	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define B0SN05RIM	 BUFFER[241]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define idB0SN05RIM	 90	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define B0SN04RIM	 BUFFER[246]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define idB0SN04RIM	 91	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define B0SN03RIM	 BUFFER[251]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define idB0SN03RIM	 92	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define B0SN02RIM	 BUFFER[256]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define idB0SN02RIM	 93	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define A0SN07RIM	 BUFFER[261]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define idA0SN07RIM	 94	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define A0SN06RIM	 BUFFER[266]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define idA0SN06RIM	 95	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define A0SN05RIM	 BUFFER[271]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define idA0SN05RIM	 96	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define A0SN04RIM	 BUFFER[276]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define idA0SN04RIM	 97	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define A0SN03RIM	 BUFFER[281]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define idA0SN03RIM	 98	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define A0SN02RIM	 BUFFER[286]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define idA0SN02RIM	 99	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define R8AD22LDU	 BUFFER[291]	//(do32_pti:140 - K09DO, - ) Сигнал синхронизации с импульсом
#define idR8AD22LDU	 100	//(do32_pti:140 - K09DO, - ) Сигнал синхронизации с импульсом
#define ttlAknp1	 BUFFER[293]	//( - , SA1) 
#define idttlAknp1	 101	//( - , SA1) 
#define LTAKTS	 BUFFER[298]	//( - , - ) takt scm
#define idLTAKTS	 102	//( - , - ) takt scm
#define krb2	 BUFFER[303]	//( - , - ) 
#define idkrb2	 103	//( - , - ) 
#define krb1	 BUFFER[308]	//( - , - ) 
#define idkrb1	 104	//( - , - ) 
#define R0DEUMLSS	 BUFFER[313]	//( - , SCM) Сигнал управления моделью
#define idR0DEUMLSS	 105	//( - , SCM) Сигнал управления моделью
#define B6VS22LDU	 BUFFER[316]	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define idB6VS22LDU	 106	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[318]	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 107	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define A6VS22LDU	 BUFFER[320]	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 108	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define B8IS21LDU	 BUFFER[322]	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define idB8IS21LDU	 109	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define B8IS11LDU	 BUFFER[324]	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 110	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define A1VP81LZZ	 BUFFER[326]	//(do32_pti:110 - K01DO, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 111	//(do32_pti:110 - K01DO, - ) Давление СБРОС ББ1 в норме
#define B1VP81LZZ	 BUFFER[328]	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 112	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define B2IS33LDU	 BUFFER[330]	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define idB2IS33LDU	 113	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define A0VN01RIM	 BUFFER[332]	//( - , SCM) Период разгона  AЗ1
#define idA0VN01RIM	 114	//( - , SCM) Период разгона  AЗ1
#define B2IS32LIM	 BUFFER[337]	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define idB2IS32LIM	 115	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define B2IS11LIM	 BUFFER[339]	//( - , SCM) Магнит РБ2 обесточен
#define idB2IS11LIM	 116	//( - , SCM) Магнит РБ2 обесточен
#define A2IS32LIM	 BUFFER[341]	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define idA2IS32LIM	 117	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define A2IS11LIM	 BUFFER[343]	//( - , SCM) Магнит РБ1 обесточен
#define idA2IS11LIM	 118	//( - , SCM) Магнит РБ1 обесточен
#define B1IS32LIM	 BUFFER[345]	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define idB1IS32LIM	 119	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define B1IS11LIM	 BUFFER[347]	//( - , SCM) Магнит ББ2 обесточен
#define idB1IS11LIM	 120	//( - , SCM) Магнит ББ2 обесточен
#define A1IS32LIM	 BUFFER[349]	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define idA1IS32LIM	 121	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define A1IS11LIM	 BUFFER[351]	//( - , SCM) Магнит ББ1 обесточен
#define idA1IS11LIM	 122	//( - , SCM) Магнит ББ1 обесточен
#define A3AD34LDU	 BUFFER[353]	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define idA3AD34LDU	 123	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define R0IN02FI4	 BUFFER[355]	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI4	 124	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define R0IN01FI3	 BUFFER[360]	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI3	 125	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI2	 BUFFER[365]	//( - , SA2) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI2	 126	//( - , SA2) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI4	 BUFFER[370]	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI4	 127	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI1	 BUFFER[375]	//( - , SA1) Выход СНМ11 Гц от ПТИ
#define idR0IN01FI1	 128	//( - , SA1) Выход СНМ11 Гц от ПТИ
#define B7AP31LDU	 BUFFER[380]	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define idB7AP31LDU	 129	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define A7AP31LDU	 BUFFER[382]	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define idA7AP31LDU	 130	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define R4VS12LDU	 BUFFER[384]	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	 131	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define R4VS22LDU	 BUFFER[386]	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	 132	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define R1VS12LDU	 BUFFER[388]	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 133	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define R2VS12LDU	 BUFFER[390]	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 134	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	 BUFFER[392]	//( - , SCM) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 135	//( - , SCM) Движение МДЗ2 в сторону НУ
#define R1VS22LDU	 BUFFER[394]	//( - , SCM) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 136	//( - , SCM) Движение МДЗ1 в сторону НУ
#define B5VS12LDU	 BUFFER[396]	//( - , SCM) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 137	//( - , SCM) Движение НЛ2 в сторону ВУ
#define B5VS22LDU	 BUFFER[398]	//( - , SCM) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 138	//( - , SCM) Движение НЛ2 в сторону НУ
#define A5VS12LDU	 BUFFER[400]	//( - , SCM) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 139	//( - , SCM) Движение НЛ1 в сторону ВУ
#define A5VS22LDU	 BUFFER[402]	//( - , SCM) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 140	//( - , SCM) Движение НЛ1 в сторону НУ
#define B6VS12LDU	 BUFFER[404]	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define idB6VS12LDU	 141	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define A8AD10LDU	 BUFFER[406]	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 142	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define B8AD20LDU	 BUFFER[408]	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 143	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define B8AD10LDU	 BUFFER[410]	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 144	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define R4AD20LDU	 BUFFER[412]	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define idR4AD20LDU	 145	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define R4AD10LDU	 BUFFER[414]	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 146	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define B0SR01RIM	 BUFFER[416]	//( - , SCM) Текущая реактивность AЗ2
#define idB0SR01RIM	 147	//( - , SCM) Текущая реактивность AЗ2
#define B3AD33LDU	 BUFFER[421]	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 148	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B3AD05LDU	 BUFFER[423]	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 149	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define B3AD04LDU	 BUFFER[425]	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 150	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[427]	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 151	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define B3AD02LDU	 BUFFER[429]	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 152	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define B3AD01LDU	 BUFFER[431]	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 153	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define B3AD21LDU	 BUFFER[433]	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 154	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD11LDU	 BUFFER[435]	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 155	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define A3AD33LDU	 BUFFER[437]	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define idA3AD33LDU	 156	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define A3AD05LDU	 BUFFER[439]	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 157	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define A3AD04LDU	 BUFFER[441]	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 158	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define R0SR02RIM	 BUFFER[443]	//( - , SCM) Текущая мощность РУ (ватт)
#define idR0SR02RIM	 159	//( - , SCM) Текущая мощность РУ (ватт)
#define R0CR02RIM	 BUFFER[448]	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define idR0CR02RIM	 160	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define R0CR01RIM	 BUFFER[453]	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define idR0CR01RIM	 161	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define B0SN08RIM	 BUFFER[458]	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define idB0SN08RIM	 162	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define A0SN08RIM	 BUFFER[463]	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define idA0SN08RIM	 163	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define B5AD20LDU	 BUFFER[468]	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 164	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define B5AD10LDU	 BUFFER[470]	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 165	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define A5AD20LDU	 BUFFER[472]	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 166	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define A5AD10LDU	 BUFFER[474]	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 167	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define R2AD20LDU	 BUFFER[476]	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 168	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[478]	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	 169	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define R1AD20LDU	 BUFFER[480]	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 170	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define R1AD10LDU	 BUFFER[482]	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	 171	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define B6AD20LDU	 BUFFER[484]	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 172	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define B6AD10LDU	 BUFFER[486]	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 173	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define A6AD20LDU	 BUFFER[488]	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 174	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define A6AD10LDU	 BUFFER[490]	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 175	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define A8AD20LDU	 BUFFER[492]	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 176	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define A2AD01LDU	 BUFFER[494]	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 177	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define A2AD21LDU	 BUFFER[496]	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 178	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD11LDU	 BUFFER[498]	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 179	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define B1AD05LDU	 BUFFER[500]	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 180	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define B1AD04LDU	 BUFFER[502]	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 181	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[504]	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 182	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define B1AD02LDU	 BUFFER[506]	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define idB1AD02LDU	 183	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define B1AD01LDU	 BUFFER[508]	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 184	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define B1AD21LDU	 BUFFER[510]	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 185	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD11LDU	 BUFFER[512]	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 186	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define A1AD05LDU	 BUFFER[514]	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 187	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define A1AD04LDU	 BUFFER[516]	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 188	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[518]	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 189	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define A1AD02LDU	 BUFFER[520]	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 190	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define A1AD01LDU	 BUFFER[522]	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 191	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define A1AD21LDU	 BUFFER[524]	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 192	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD11LDU	 BUFFER[526]	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 193	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define A0SR01RIM	 BUFFER[528]	//( - , SCM) Текущая реактивность AЗ1
#define idA0SR01RIM	 194	//( - , SCM) Текущая реактивность AЗ1
#define A3AD03LDU	 BUFFER[533]	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 195	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define A3AD02LDU	 BUFFER[535]	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 196	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define A3AD01LDU	 BUFFER[537]	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 197	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define A3AD21LDU	 BUFFER[539]	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 198	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD11LDU	 BUFFER[541]	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 199	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define B2AD33LDU	 BUFFER[543]	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define idB2AD33LDU	 200	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define B2AD05LDU	 BUFFER[545]	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 201	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define B2AD04LDU	 BUFFER[547]	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 202	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[549]	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 203	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define B2AD02LDU	 BUFFER[551]	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 204	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define B2AD01LDU	 BUFFER[553]	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 205	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define B2AD21LDU	 BUFFER[555]	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 206	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD11LDU	 BUFFER[557]	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 207	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define A2AD33LDU	 BUFFER[559]	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define idA2AD33LDU	 208	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define A2AD05LDU	 BUFFER[561]	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 209	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define A2AD04LDU	 BUFFER[563]	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 210	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[565]	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 211	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define A2AD02LDU	 BUFFER[567]	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 212	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define A3IC01UDU	 BUFFER[569]	//( - , SDu) Координата штока ИС1
#define idA3IC01UDU	 213	//( - , SDu) Координата штока ИС1
#define A3IS31LDU	 BUFFER[574]	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define idA3IS31LDU	 214	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define A2VP82LDU	 BUFFER[576]	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 215	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define A2IP01IZ2	 BUFFER[578]	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 216	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define A2IP01IZ1	 BUFFER[581]	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 217	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define B3IS21LDU	 BUFFER[584]	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define idB3IS21LDU	 218	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define A3IS21LDU	 BUFFER[586]	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define idA3IS21LDU	 219	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define A2IS33LDU	 BUFFER[588]	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define idA2IS33LDU	 220	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define A2IC01UDU	 BUFFER[590]	//( - , SDu) Координата штока РБ1
#define idA2IC01UDU	 221	//( - , SDu) Координата штока РБ1
#define A2IS12LDU	 BUFFER[595]	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 222	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define A2IS11LDU	 BUFFER[597]	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define idA2IS11LDU	 223	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define A2IS21LDU	 BUFFER[599]	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define idA2IS21LDU	 224	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define B0IT02IZ2	 BUFFER[601]	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define idB0IT02IZ2	 225	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define B0IT01IZ1	 BUFFER[604]	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define idB0IT01IZ1	 226	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define A0IT02IZ2	 BUFFER[607]	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define idA0IT02IZ2	 227	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define A0IT01IZ1	 BUFFER[610]	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define idA0IT01IZ1	 228	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define R6IS21LDU	 BUFFER[613]	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 229	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define R6IS67LZZ	 BUFFER[615]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 230	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS66LZZ	 BUFFER[617]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 231	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS65LDU	 BUFFER[619]	//( - , - ) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 232	//( - , - ) Исправность ВИП ССДИ-35 2канал
#define R6IS64LDU	 BUFFER[621]	//( - , - ) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 233	//( - , - ) Исправность ВИП ССДИ-35 1канал
#define R6IS63LDU	 BUFFER[623]	//( - , - ) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 234	//( - , - ) Исправность ВИП ССДИ-39 2канал
#define R6IS62LDU	 BUFFER[625]	//( - , - ) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 235	//( - , - ) Исправность ВИП ССДИ-39 1канал
#define B3IS22LDU	 BUFFER[627]	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define idB3IS22LDU	 236	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define A3IS22LDU	 BUFFER[629]	//(do32_pti:110 - K02DO, - ) Приход на НУП ИС1
#define idA3IS22LDU	 237	//(do32_pti:110 - K02DO, - ) Приход на НУП ИС1
#define B3IS11LDU	 BUFFER[631]	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 238	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define A3IS11LDU	 BUFFER[633]	//(do32_pti:110 - K04DO, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 239	//(do32_pti:110 - K04DO, - ) Приход на ВУ ИС1
#define A3IP02IDU	 BUFFER[635]	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 240	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3VP81LDU	 BUFFER[638]	//( - , - ) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 241	//( - , - ) Давление СПУСК ИС2 в норме
#define A3VP81LDU	 BUFFER[640]	//( - , - ) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 242	//( - , - ) Давление СПУСК ИС1 в норме
#define B3IS33LDU	 BUFFER[642]	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idB3IS33LDU	 243	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define B3IC01UDU	 BUFFER[644]	//( - , SDu) Координата штока ИС2
#define idB3IC01UDU	 244	//( - , SDu) Координата штока ИС2
#define B3IS31LDU	 BUFFER[649]	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define idB3IS31LDU	 245	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define B3IP02IDU	 BUFFER[651]	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define idB3IP02IDU	 246	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define A3IS33LDU	 BUFFER[654]	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define idA3IS33LDU	 247	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define R0MW13LP2	 BUFFER[656]	//( - , SCM) Переключатель «СЕТЬ»
#define idR0MW13LP2	 248	//( - , SCM) Переключатель «СЕТЬ»
#define B3AD31LDU	 BUFFER[658]	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define idB3AD31LDU	 249	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define B2AD32LDU	 BUFFER[660]	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 250	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define B2AD31LDU	 BUFFER[662]	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define idB2AD31LDU	 251	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define B1AD32LDU	 BUFFER[664]	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 252	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define B1AD31LDU	 BUFFER[666]	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define idB1AD31LDU	 253	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define A3AD31LDU	 BUFFER[668]	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define idA3AD31LDU	 254	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define C1MD31LP1	 BUFFER[670]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define idC1MD31LP1	 255	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define C1MD31LP2	 BUFFER[672]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define idC1MD31LP2	 256	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define A1AD31LDU	 BUFFER[674]	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define idA1AD31LDU	 257	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define A1AD32LDU	 BUFFER[676]	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 258	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define A2AD31LDU	 BUFFER[678]	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define idA2AD31LDU	 259	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define C2MD31LP1	 BUFFER[680]	//( - , SCM) Кнопка «СБРОС РБ»
#define idC2MD31LP1	 260	//( - , SCM) Кнопка «СБРОС РБ»
#define A2AD32LDU	 BUFFER[682]	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 261	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define R0VZ71LZ2	 BUFFER[684]	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define idR0VZ71LZ2	 262	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define R0VZ71LZ1	 BUFFER[686]	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define idR0VZ71LZ1	 263	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define R8AD21LDU	 BUFFER[688]	//(vds32_pti:310 - K31VDSR, - ) Имитация прихода на ВУ ИС для КВДС
#define idR8AD21LDU	 264	//(vds32_pti:310 - K31VDSR, - ) Имитация прихода на ВУ ИС для КВДС
#define R0AD14LDU	 BUFFER[690]	//( - , SCM) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 265	//( - , SCM) Имитация срабатывания верхней АС II УР
#define B7AS31LDU	 BUFFER[692]	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define idB7AS31LDU	 266	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define A7AS31LDU	 BUFFER[694]	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define idA7AS31LDU	 267	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define B3IS35LDU	 BUFFER[696]	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define idB3IS35LDU	 268	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define B3AD34LDU	 BUFFER[698]	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define idB3AD34LDU	 269	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define A3IS35LDU	 BUFFER[700]	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define idA3IS35LDU	 270	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define R7II73LZ2	 BUFFER[702]	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ2	 271	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define R7II71LZ2	 BUFFER[704]	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ2	 272	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II72LZ2	 BUFFER[706]	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ2	 273	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R0AD16LDU	 BUFFER[708]	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 274	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define R7II72LZ1	 BUFFER[710]	//(do32_pti:110 - K07DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ1	 275	//(do32_pti:110 - K07DO, - ) Сработала АС IУР (датчик 2)
#define R7II71LZ1	 BUFFER[712]	//(do32_pti:110 - K08DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ1	 276	//(do32_pti:110 - K08DO, - ) Сработала АС IУР (датчик 1)
#define R7II73LZ1	 BUFFER[714]	//(do32_pti:110 - K09DO, - ) Сработала АС IIУР
#define idR7II73LZ1	 277	//(do32_pti:110 - K09DO, - ) Сработала АС IIУР
#define R0SR01RIM	 BUFFER[716]	//( - , SCM) Текущая реактивность PУ
#define idR0SR01RIM	 278	//( - , SCM) Текущая реактивность PУ
#define R0ST01RIM	 BUFFER[721]	//( - , SCM) Текущий период разгона РУ
#define idR0ST01RIM	 279	//( - , SCM) Текущий период разгона РУ
#define A4AD10LDU	 BUFFER[726]	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define idA4AD10LDU	 280	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define B4AD10LDU	 BUFFER[728]	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define idB4AD10LDU	 281	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define A9AD10LDU	 BUFFER[730]	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define idA9AD10LDU	 282	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define B9AD10LDU	 BUFFER[732]	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define idB9AD10LDU	 283	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define fEM_R0UL01RIM	 BUFFER[734]	//(R0UL01RIM) Среднее время генерации нейтронов
#define idfEM_R0UL01RIM	 284	//(R0UL01RIM) Среднее время генерации нейтронов
#define fEM_R0UN02RIM	 BUFFER[739]	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define idfEM_R0UN02RIM	 285	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define fEM_A1UR01RIM	 BUFFER[744]	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR01RIM	 286	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define fEM_A1UR00RIM	 BUFFER[749]	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR00RIM	 287	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define fEM_A3UR00RIM	 BUFFER[754]	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR00RIM	 288	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define fEM_A3UR01RIM	 BUFFER[759]	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR01RIM	 289	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define fEM_R0UT01RIM	 BUFFER[764]	//(R0UT01RIM) Температурный коэффициент (долл)
#define idfEM_R0UT01RIM	 290	//(R0UT01RIM) Температурный коэффициент (долл)
#define fEM_R0UT02RIM	 BUFFER[769]	//(R0UT02RIM) Масса топлива в АЗ
#define idfEM_R0UT02RIM	 291	//(R0UT02RIM) Масса топлива в АЗ
#define fEM_R0UT04RIM	 BUFFER[774]	//(R0UT04RIM) Удельная теплоёмкость топлива
#define idfEM_R0UT04RIM	 292	//(R0UT04RIM) Удельная теплоёмкость топлива
#define fEM_R0UT03RIM	 BUFFER[779]	//(R0UT03RIM) Нормальная температура АЗ град
#define idfEM_R0UT03RIM	 293	//(R0UT03RIM) Нормальная температура АЗ град
#define fEM_R0UT05RIM	 BUFFER[784]	//(R0UT05RIM) Энергия деления ядра
#define idfEM_R0UT05RIM	 294	//(R0UT05RIM) Энергия деления ядра
#define fEM_R0UT06RIM	 BUFFER[789]	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define idfEM_R0UT06RIM	 295	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define fEM_A1UC02RDU	 BUFFER[794]	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define idfEM_A1UC02RDU	 296	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define fEM_A1UC04RIM	 BUFFER[799]	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define idfEM_A1UC04RIM	 297	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define fEM_A1UC05RIM	 BUFFER[804]	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define idfEM_A1UC05RIM	 298	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define fEM_A1UC06RIM	 BUFFER[809]	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define idfEM_A1UC06RIM	 299	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define fEM_A2UC06RIM	 BUFFER[814]	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define idfEM_A2UC06RIM	 300	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define fEM_A2UC05RIM	 BUFFER[819]	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define idfEM_A2UC05RIM	 301	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define fEM_A2UC04RIM	 BUFFER[824]	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define idfEM_A2UC04RIM	 302	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define fEM_A2UC02RDU	 BUFFER[829]	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define idfEM_A2UC02RDU	 303	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define fEM_A3UC06RIM	 BUFFER[834]	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define idfEM_A3UC06RIM	 304	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define fEM_A3UC05RIM	 BUFFER[839]	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC05RIM	 305	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC04RIM	 BUFFER[844]	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define idfEM_A3UC04RIM	 306	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define fEM_A3UC02RDU	 BUFFER[849]	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define idfEM_A3UC02RDU	 307	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define fEM_R4UV80RDU	 BUFFER[854]	//(R4UV80RDU) Номинальная скорость тележки (см/с)
#define idfEM_R4UV80RDU	 308	//(R4UV80RDU) Номинальная скорость тележки (см/с)
#define fEM_R4UC10RIM	 BUFFER[859]	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define idfEM_R4UC10RIM	 309	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define fEM_R4UC20RIM	 BUFFER[864]	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define idfEM_R4UC20RIM	 310	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define fEM_B8UC21RIM	 BUFFER[869]	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define idfEM_B8UC21RIM	 311	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define fEM_B8UC20RIM	 BUFFER[874]	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define idfEM_B8UC20RIM	 312	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define fEM_B8UC11RIM	 BUFFER[879]	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define idfEM_B8UC11RIM	 313	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define fEM_B8UC10RIM	 BUFFER[884]	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define idfEM_B8UC10RIM	 314	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define fEM_B8UV80RDU	 BUFFER[889]	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define idfEM_B8UV80RDU	 315	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define fEM_A8UV80RDU	 BUFFER[894]	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define idfEM_A8UV80RDU	 316	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define fEM_A8UC10RIM	 BUFFER[899]	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define idfEM_A8UC10RIM	 317	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define fEM_A8UC11RIM	 BUFFER[904]	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define idfEM_A8UC11RIM	 318	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define fEM_A8UC20RIM	 BUFFER[909]	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define idfEM_A8UC20RIM	 319	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define fEM_A8UC21RIM	 BUFFER[914]	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define idfEM_A8UC21RIM	 320	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define fEM_A6UC10RIM	 BUFFER[919]	//(A6UC10RIM) Время полного хода БЗ (сек)
#define idfEM_A6UC10RIM	 321	//(A6UC10RIM) Время полного хода БЗ (сек)
#define fEM_R1UC10RIM	 BUFFER[924]	//(R1UC10RIM) Время полного хода МДЗ сек
#define idfEM_R1UC10RIM	 322	//(R1UC10RIM) Время полного хода МДЗ сек
#define fEM_A5UC10RIM	 BUFFER[929]	//(A5UC10RIM) Время полного хода НЛ сек
#define idfEM_A5UC10RIM	 323	//(A5UC10RIM) Время полного хода НЛ сек
#define fEM_A0UN01RIM	 BUFFER[934]	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define idfEM_A0UN01RIM	 324	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define fEM_R4UC22RIM	 BUFFER[939]	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define idfEM_R4UC22RIM	 325	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define fEM_A1UG01RDU	 BUFFER[944]	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define idfEM_A1UG01RDU	 326	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define fEM_A2UG01RDU	 BUFFER[949]	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define idfEM_A2UG01RDU	 327	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define fEM_A3UG01RDU	 BUFFER[954]	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define idfEM_A3UG01RDU	 328	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define fEM_R7UC10RIM	 BUFFER[959]	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define idfEM_R7UC10RIM	 329	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define fEM_R7UC19RIM	 BUFFER[964]	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define idfEM_R7UC19RIM	 330	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define fEM_R7UI02RIM	 BUFFER[969]	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define idfEM_R7UI02RIM	 331	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define fEM_R7UL01RIM	 BUFFER[974]	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define idfEM_R7UL01RIM	 332	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define fEM_A2UR00RIM	 BUFFER[979]	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define idfEM_A2UR00RIM	 333	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define fEM_A2UR01RIM	 BUFFER[984]	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define idfEM_A2UR01RIM	 334	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define fEM_A0UN02RIM	 BUFFER[989]	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define idfEM_A0UN02RIM	 335	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define fEM_R0UR30RIM	 BUFFER[994]	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define idfEM_R0UR30RIM	 336	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define fEM_R0UR01RIM	 BUFFER[999]	//(R0UR01RIM) Стартовая отрицательная реактивность
#define idfEM_R0UR01RIM	 337	//(R0UR01RIM) Стартовая отрицательная реактивность
#define fEM_R0UT02RDU	 BUFFER[1004]	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RDU	 338	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RDU	 BUFFER[1009]	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RDU	 339	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define fEM_A1UC03RDU	 BUFFER[1014]	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define idfEM_A1UC03RDU	 340	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define fEM_A2UP03RDU	 BUFFER[1019]	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP03RDU	 341	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UP04RDU	 BUFFER[1024]	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP04RDU	 342	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UC03RDU	 BUFFER[1029]	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define idfEM_A2UC03RDU	 343	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define fEM_A3UP03RDU	 BUFFER[1034]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 344	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1039]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 345	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UC03RDU	 BUFFER[1044]	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define idfEM_A3UC03RDU	 346	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define fEM_R7UI74RIM	 BUFFER[1049]	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define idfEM_R7UI74RIM	 347	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define fEM_A8UC03RDU	 BUFFER[1054]	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define idfEM_A8UC03RDU	 348	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define fEM_R0UV87RDU	 BUFFER[1059]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 349	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV81RDU	 BUFFER[1064]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 350	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1069]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 351	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1074]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 352	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1079]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 353	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1084]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 354	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1089]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 355	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A8UC08RDU	 BUFFER[1094]	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define idfEM_A8UC08RDU	 356	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define fEM_B8UC08RDU	 BUFFER[1099]	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define idfEM_B8UC08RDU	 357	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define fEM_R4UC08RDU	 BUFFER[1104]	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define idfEM_R4UC08RDU	 358	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define fEM_R0UH01RSS	 BUFFER[1109]	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define idfEM_R0UH01RSS	 359	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define fEM_A0UX00RSS	 BUFFER[1114]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 360	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_R7UX01RSS	 BUFFER[1119]	//(R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	 361	//(R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	 BUFFER[1124]	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	 362	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX04RSS	 BUFFER[1129]	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	 363	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	 BUFFER[1134]	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	 364	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	 BUFFER[1139]	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	 365	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define fEM_R7UX07RSS	 BUFFER[1144]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 366	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[1149]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 367	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[1154]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 368	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY01RSS	 BUFFER[1159]	//(R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	 369	//(R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	 BUFFER[1164]	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	 370	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY04RSS	 BUFFER[1169]	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	 371	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	 BUFFER[1174]	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	 372	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	 BUFFER[1179]	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	 373	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY07RSS	 BUFFER[1184]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 374	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[1189]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 375	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[1194]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 376	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_R7UX10RSS	 BUFFER[1199]	//(R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	 377	//(R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	 BUFFER[1204]	//(R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	 378	//(R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	 BUFFER[1209]	//(R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	 379	//(R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY10RSS	 BUFFER[1214]	//(R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	 380	//(R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	 BUFFER[1219]	//(R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	 381	//(R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	 BUFFER[1224]	//(R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	 382	//(R7UY12RSS) Y-координата камеры R7IN43
#define fEM_A0UX01RSS	 BUFFER[1229]	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	 383	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	 BUFFER[1234]	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	 384	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	 BUFFER[1239]	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	 385	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_A0UX04RSS	 BUFFER[1244]	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	 386	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	 BUFFER[1249]	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	 387	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	 BUFFER[1254]	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	 388	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_A0UX07RSS	 BUFFER[1259]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 389	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[1264]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 390	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[1269]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 391	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_A0UX10RSS	 BUFFER[1274]	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	 392	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	 BUFFER[1279]	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	 393	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	 BUFFER[1284]	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	 394	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX01RSS	 BUFFER[1289]	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	 395	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	 BUFFER[1294]	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	 396	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	 BUFFER[1299]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 397	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[1304]	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define idfEM_B0UX04RSS	 398	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define fEM_B0UX05RSS	 BUFFER[1309]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 399	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	 BUFFER[1314]	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	 400	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_B0UX07RSS	 BUFFER[1319]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 401	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[1324]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 402	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[1329]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 403	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_B0UX10RSS	 BUFFER[1334]	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	 404	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	 BUFFER[1339]	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	 405	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	 BUFFER[1344]	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	 406	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0UH02RSS	 BUFFER[1349]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define idfEM_R0UH02RSS	 407	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define fEM_R0UH03RSS	 BUFFER[1354]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define idfEM_R0UH03RSS	 408	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define fEM_R4US80RDU	 BUFFER[1359]	//(R4US80RDU) Тормозной путь тележки (мм)
#define idfEM_R4US80RDU	 409	//(R4US80RDU) Тормозной путь тележки (мм)
#define fEM_R7UI71RIM	 BUFFER[1364]	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define idfEM_R7UI71RIM	 410	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define fEM_R7UI72RIM	 BUFFER[1369]	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define idfEM_R7UI72RIM	 411	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define fEM_R7UI73RIM	 BUFFER[1374]	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define idfEM_R7UI73RIM	 412	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define fEM_A1UP01RIM	 BUFFER[1379]	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define idfEM_A1UP01RIM	 413	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define fEM_A2UP01RIM	 BUFFER[1384]	//(A2UP01RIM) Текущее давление на сброс РБ
#define idfEM_A2UP01RIM	 414	//(A2UP01RIM) Текущее давление на сброс РБ
#define fEM_A0UP02RIM	 BUFFER[1389]	//(A0UP02RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP02RIM	 415	//(A0UP02RIM) Текущее давление в АЗ1,2
#define fEM_A3UP01RIM	 BUFFER[1394]	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define idfEM_A3UP01RIM	 416	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define fEM_A1UP82RIM	 BUFFER[1399]	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define idfEM_A1UP82RIM	 417	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define fEM_A3UP02RDU	 BUFFER[1404]	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define idfEM_A3UP02RDU	 418	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define fEM_A1UV02RIM	 BUFFER[1409]	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define idfEM_A1UV02RIM	 419	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define fEM_A3UV02RIM	 BUFFER[1414]	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define idfEM_A3UV02RIM	 420	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define fEM_A2UV02RIM	 BUFFER[1419]	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define idfEM_A2UV02RIM	 421	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define fEM_B8US80RDU	 BUFFER[1424]	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define idfEM_B8US80RDU	 422	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define fEM_A8US80RDU	 BUFFER[1429]	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define idfEM_A8US80RDU	 423	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define fEM_A6US80RDU	 BUFFER[1434]	//(A6US80RDU) Тормозной путь БЗ (мм)
#define idfEM_A6US80RDU	 424	//(A6US80RDU) Тормозной путь БЗ (мм)
#define fEM_A1US07RDU	 BUFFER[1439]	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define idfEM_A1US07RDU	 425	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define fEM_A2US07RDU	 BUFFER[1444]	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define idfEM_A2US07RDU	 426	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define fEM_A3US07RDU	 BUFFER[1449]	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define idfEM_A3US07RDU	 427	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define fEM_R7UI75RIM	 BUFFER[1454]	//(R7UI75RIM) Множитель к уровню радиации
#define idfEM_R7UI75RIM	 428	//(R7UI75RIM) Множитель к уровню радиации
#define fEM_R0UH21RSS	 BUFFER[1459]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 429	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[1464]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 430	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[1469]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 431	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UH05RSS	 BUFFER[1474]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 432	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_A4UL10RIM	 BUFFER[1479]	//(A4UL10RIM) Время полного перемещения НИ сек
#define idfEM_A4UL10RIM	 433	//(A4UL10RIM) Время полного перемещения НИ сек
#define fEM_A9UL10RIM	 BUFFER[1484]	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define idfEM_A9UL10RIM	 434	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define fEM_R3UL10RIM	 BUFFER[1489]	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define idfEM_R3UL10RIM	 435	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define fEM_R5UL10RIM	 BUFFER[1494]	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define idfEM_R5UL10RIM	 436	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define fEM_R6UL10RIM	 BUFFER[1499]	//(R6UL10RIM) Время полного хода кран-балки сек
#define idfEM_R6UL10RIM	 437	//(R6UL10RIM) Время полного хода кран-балки сек
#define lEM_C1AD31LRP	 BUFFER[1504]	//(C1AD31LRP) Общий сброс от РПУ
#define idlEM_C1AD31LRP	 438	//(C1AD31LRP) Общий сброс от РПУ
#define lEM_R0IE01LRP	 BUFFER[1506]	//(R0IE01LRP) Отключение питание детекторов
#define idlEM_R0IE01LRP	 439	//(R0IE01LRP) Отключение питание детекторов
#define lEM_R0IE02LRP	 BUFFER[1508]	//(R0IE02LRP) Отключить питание ПР, ПУ
#define idlEM_R0IE02LRP	 440	//(R0IE02LRP) Отключить питание ПР, ПУ
#define fEM_A2UP02RIM	 BUFFER[1510]	//(A2UP02RIM) Текущее давление на подъём РБ
#define idfEM_A2UP02RIM	 441	//(A2UP02RIM) Текущее давление на подъём РБ
#define fEM_A2UP03RIM	 BUFFER[1515]	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define idfEM_A2UP03RIM	 442	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define fEM_A0UP01RIM	 BUFFER[1520]	//(A0UP01RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP01RIM	 443	//(A0UP01RIM) Текущее давление в АЗ1,2
#define fEM_A3UP02RIM	 BUFFER[1525]	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define idfEM_A3UP02RIM	 444	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define fEM_A4UP01RIM	 BUFFER[1530]	//(A4UP01RIM) Текущее давление на подъём НИ
#define idfEM_A4UP01RIM	 445	//(A4UP01RIM) Текущее давление на подъём НИ
#define fEM_A4UP02RIM	 BUFFER[1535]	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define idfEM_A4UP02RIM	 446	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define fEM_R7UI76RIM	 BUFFER[1540]	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define idfEM_R7UI76RIM	 447	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define fEM_R7UI77RIM	 BUFFER[1545]	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define idfEM_R7UI77RIM	 448	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define iEM_TERBB1	 BUFFER[1550]	//(TERBB1) Неисправности  ББ1
#define idiEM_TERBB1	 449	//(TERBB1) Неисправности  ББ1
#define fEM_A1MC02RC1	 BUFFER[1553]	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define idfEM_A1MC02RC1	 450	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define fEM_A1MV02RC1	 BUFFER[1558]	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define idfEM_A1MV02RC1	 451	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define iEM_TERBB2	 BUFFER[1563]	//(TERBB2) Неисправности  ББ2
#define idiEM_TERBB2	 452	//(TERBB2) Неисправности  ББ2
#define fEM_B1MC02RC1	 BUFFER[1566]	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define idfEM_B1MC02RC1	 453	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define fEM_B1MV02RC1	 BUFFER[1571]	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define idfEM_B1MV02RC1	 454	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define iEM_TERRB2	 BUFFER[1576]	//(TERRB2) Неисправности  РБ2
#define idiEM_TERRB2	 455	//(TERRB2) Неисправности  РБ2
#define fEM_B2MC02RC1	 BUFFER[1579]	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define idfEM_B2MC02RC1	 456	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define fEM_B2MV02RC1	 BUFFER[1584]	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define idfEM_B2MV02RC1	 457	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define iEM_TERRB1	 BUFFER[1589]	//(TERRB1) Неисправности  РБ1
#define idiEM_TERRB1	 458	//(TERRB1) Неисправности  РБ1
#define fEM_A2MC02RC1	 BUFFER[1592]	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define idfEM_A2MC02RC1	 459	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define fEM_A2MV02RC1	 BUFFER[1597]	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define idfEM_A2MV02RC1	 460	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define iEM_TERIS2	 BUFFER[1602]	//(TERIS2) Неисправности  ИС2
#define idiEM_TERIS2	 461	//(TERIS2) Неисправности  ИС2
#define fEM_B3MC02RC1	 BUFFER[1605]	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define idfEM_B3MC02RC1	 462	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define fEM_B3MV02RC1	 BUFFER[1610]	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define idfEM_B3MV02RC1	 463	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define iEM_TERIS1	 BUFFER[1615]	//(TERIS1) Неисправности  ИС1
#define idiEM_TERIS1	 464	//(TERIS1) Неисправности  ИС1
#define fEM_A3MC02RC1	 BUFFER[1618]	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define idfEM_A3MC02RC1	 465	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define fEM_A3MV02RC1	 BUFFER[1623]	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define idfEM_A3MV02RC1	 466	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define iEM_TERA1IE04LDU	 BUFFER[1628]	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define idiEM_TERA1IE04LDU	 467	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define iEM_TERA1IE03LDU	 BUFFER[1631]	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define idiEM_TERA1IE03LDU	 468	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define fEM_A1MC01RC1	 BUFFER[1634]	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define idfEM_A1MC01RC1	 469	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define iEM_TERB1IE03LDU	 BUFFER[1639]	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define idiEM_TERB1IE03LDU	 470	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define iEM_TERB1IE04LDU	 BUFFER[1642]	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define idiEM_TERB1IE04LDU	 471	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define fEM_B1MC01RC1	 BUFFER[1645]	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define idfEM_B1MC01RC1	 472	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define fEM_B1MV01RC1	 BUFFER[1650]	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define idfEM_B1MV01RC1	 473	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define fEM_B2MC01RC1	 BUFFER[1655]	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define idfEM_B2MC01RC1	 474	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define fEM_B2MV01RC1	 BUFFER[1660]	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define idfEM_B2MV01RC1	 475	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define fEM_A3MC01RC1	 BUFFER[1665]	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define idfEM_A3MC01RC1	 476	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define fEM_A3MV01RC1	 BUFFER[1670]	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define idfEM_A3MV01RC1	 477	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define fEM_B3MC01RC1	 BUFFER[1675]	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define idfEM_B3MC01RC1	 478	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define fEM_B3MV01RC1	 BUFFER[1680]	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define idfEM_B3MV01RC1	 479	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define iEM_TERA2SS21LIM	 BUFFER[1685]	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define idiEM_TERA2SS21LIM	 480	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define iEM_TERA2SS12LIM	 BUFFER[1688]	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define idiEM_TERA2SS12LIM	 481	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define iEM_TERR6SS21LIM	 BUFFER[1691]	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define idiEM_TERR6SS21LIM	 482	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define iEM_TERA2VP82LIM	 BUFFER[1694]	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define idiEM_TERA2VP82LIM	 483	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define iEM_TERA2SS11LIM	 BUFFER[1697]	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define idiEM_TERA2SS11LIM	 484	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define iEM_TERB3SS21LIM	 BUFFER[1700]	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define idiEM_TERB3SS21LIM	 485	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define iEM_TERA0MT01RIM	 BUFFER[1703]	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define idiEM_TERA0MT01RIM	 486	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define iEM_TERB0MT01RIM	 BUFFER[1706]	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define idiEM_TERB0MT01RIM	 487	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define iEM_TERA2SP01RIM	 BUFFER[1709]	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define idiEM_TERA2SP01RIM	 488	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define iEM_TERB2SP01RIM	 BUFFER[1712]	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define idiEM_TERB2SP01RIM	 489	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define iEM_TERB3SP02RIM	 BUFFER[1715]	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define idiEM_TERB3SP02RIM	 490	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define iEM_TERA3SC01RIM	 BUFFER[1718]	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define idiEM_TERA3SC01RIM	 491	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define iEM_TERA3VP81LIM	 BUFFER[1721]	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define idiEM_TERA3VP81LIM	 492	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define iEM_TERA2SC01RIM	 BUFFER[1724]	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define idiEM_TERA2SC01RIM	 493	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define iEM_TERA2SS33LIM	 BUFFER[1727]	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define idiEM_TERA2SS33LIM	 494	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define iEM_TERA3SS21LIM	 BUFFER[1730]	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define idiEM_TERA3SS21LIM	 495	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define iEM_TERA3SS33LIM	 BUFFER[1733]	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define idiEM_TERA3SS33LIM	 496	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define iEM_TERA3SS31LIM	 BUFFER[1736]	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define idiEM_TERA3SS31LIM	 497	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define iEM_TERB3SS31LIM	 BUFFER[1739]	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define idiEM_TERB3SS31LIM	 498	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define iEM_TERB3SS33LIM	 BUFFER[1742]	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idiEM_TERB3SS33LIM	 499	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define iEM_TERB3SC01RIM	 BUFFER[1745]	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define idiEM_TERB3SC01RIM	 500	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define iEM_TERA3SS11LIM	 BUFFER[1748]	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define idiEM_TERA3SS11LIM	 501	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define iEM_TERB3SS11LIM	 BUFFER[1751]	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define idiEM_TERB3SS11LIM	 502	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define iEM_TERR6IS64LIM	 BUFFER[1754]	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define idiEM_TERR6IS64LIM	 503	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define iEM_TERB3SS22LIM	 BUFFER[1757]	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define idiEM_TERB3SS22LIM	 504	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define iEM_TERA3SS22LIM	 BUFFER[1760]	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define idiEM_TERA3SS22LIM	 505	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define iEM_TERA3SP02RIM	 BUFFER[1763]	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define idiEM_TERA3SP02RIM	 506	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define iEM_TERR6IS62LIM	 BUFFER[1766]	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define idiEM_TERR6IS62LIM	 507	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define iEM_TERR6IS66LIM	 BUFFER[1769]	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idiEM_TERR6IS66LIM	 508	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define iEM_TERR6IS67LIM	 BUFFER[1772]	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idiEM_TERR6IS67LIM	 509	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define iEM_TERA0VP81LIM	 BUFFER[1775]	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define idiEM_TERA0VP81LIM	 510	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define iEM_TERB0VP81LIM	 BUFFER[1778]	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define idiEM_TERB0VP81LIM	 511	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define iEM_TERR0VP81LIM	 BUFFER[1781]	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define idiEM_TERR0VP81LIM	 512	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define iEM_TERR6IS68LIM	 BUFFER[1784]	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define idiEM_TERR6IS68LIM	 513	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define iEM_TERR7SI74RIM	 BUFFER[1787]	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define idiEM_TERR7SI74RIM	 514	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define iEM_TERA5SS21LIM	 BUFFER[1790]	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define idiEM_TERA5SS21LIM	 515	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define iEM_TERB5SS11LIM	 BUFFER[1793]	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define idiEM_TERB5SS11LIM	 516	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define iEM_TERA5SS11LIM	 BUFFER[1796]	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define idiEM_TERA5SS11LIM	 517	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define iEM_TERA9SS11LIM	 BUFFER[1799]	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define idiEM_TERA9SS11LIM	 518	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define iEM_TERB2SS11LIM	 BUFFER[1802]	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define idiEM_TERB2SS11LIM	 519	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define iEM_TERB2SS12LIM	 BUFFER[1805]	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define idiEM_TERB2SS12LIM	 520	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define iEM_TERB2SS21LIM	 BUFFER[1808]	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB2SS21LIM	 521	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERR3SS11LIM	 BUFFER[1811]	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define idiEM_TERR3SS11LIM	 522	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define iEM_TERB2SC01RIM	 BUFFER[1814]	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define idiEM_TERB2SC01RIM	 523	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define iEM_TERR3SS21LIM	 BUFFER[1817]	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define idiEM_TERR3SS21LIM	 524	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define iEM_TERR5SS11LIM	 BUFFER[1820]	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define idiEM_TERR5SS11LIM	 525	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define iEM_TERA4SS11LIM	 BUFFER[1823]	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define idiEM_TERA4SS11LIM	 526	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define iEM_TERR1SS11LIM	 BUFFER[1826]	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define idiEM_TERR1SS11LIM	 527	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define iEM_TERR1SS21LIM	 BUFFER[1829]	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define idiEM_TERR1SS21LIM	 528	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define iEM_TERR2SS11LIM	 BUFFER[1832]	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define idiEM_TERR2SS11LIM	 529	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define iEM_TERR2SS21LIM	 BUFFER[1835]	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define idiEM_TERR2SS21LIM	 530	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define iEM_TERA4VP82LIM	 BUFFER[1838]	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define idiEM_TERA4VP82LIM	 531	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define iEM_TERB4SS21LIM	 BUFFER[1841]	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define idiEM_TERB4SS21LIM	 532	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define iEM_TERR5SS21LIM	 BUFFER[1844]	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define idiEM_TERR5SS21LIM	 533	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define iEM_TERB6SS21LIM	 BUFFER[1847]	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define idiEM_TERB6SS21LIM	 534	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define iEM_TERB4SS11LIM	 BUFFER[1850]	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define idiEM_TERB4SS11LIM	 535	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define iEM_TERA4SS21LIM	 BUFFER[1853]	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define idiEM_TERA4SS21LIM	 536	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define iEM_TERA6MS11LIM	 BUFFER[1856]	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define idiEM_TERA6MS11LIM	 537	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define iEM_TERA6SS21LIM	 BUFFER[1859]	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define idiEM_TERA6SS21LIM	 538	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define iEM_TERB6SS11LIM	 BUFFER[1862]	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define idiEM_TERB6SS11LIM	 539	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define iEM_TERR4SS11LIM	 BUFFER[1865]	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define idiEM_TERR4SS11LIM	 540	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define iEM_TERR4MS21LIM	 BUFFER[1868]	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define idiEM_TERR4MS21LIM	 541	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define iEM_TERR4SS12LIM	 BUFFER[1871]	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define idiEM_TERR4SS12LIM	 542	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define iEM_TERR4SS22LIM	 BUFFER[1874]	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define idiEM_TERR4SS22LIM	 543	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define iEM_TERR8SS11LIM	 BUFFER[1877]	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define idiEM_TERR8SS11LIM	 544	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define iEM_TERB8SC01RIM	 BUFFER[1880]	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define idiEM_TERB8SC01RIM	 545	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define iEM_TERA8SC01RIM	 BUFFER[1883]	//(TERA8SC01RIM) Искажение: Координата ДС2
#define idiEM_TERA8SC01RIM	 546	//(TERA8SC01RIM) Искажение: Координата ДС2
#define iEM_TERB8SS12LIM	 BUFFER[1886]	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define idiEM_TERB8SS12LIM	 547	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define iEM_TERA8SS12LIM	 BUFFER[1889]	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define idiEM_TERA8SS12LIM	 548	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define iEM_TERB8SS22LIM	 BUFFER[1892]	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define idiEM_TERB8SS22LIM	 549	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define iEM_TERA8SS22LIM	 BUFFER[1895]	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define idiEM_TERA8SS22LIM	 550	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define iEM_TERA9SS21LIM	 BUFFER[1898]	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define idiEM_TERA9SS21LIM	 551	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define iEM_TERB9SS21LIM	 BUFFER[1901]	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define idiEM_TERB9SS21LIM	 552	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define iEM_TERB9SS11LIM	 BUFFER[1904]	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define idiEM_TERB9SS11LIM	 553	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define iEM_TERB5SS21LIM	 BUFFER[1907]	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define idiEM_TERB5SS21LIM	 554	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define iEM_TERA1SS21LIM	 BUFFER[1910]	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define idiEM_TERA1SS21LIM	 555	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define iEM_TERA1SS11LIM	 BUFFER[1913]	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define idiEM_TERA1SS11LIM	 556	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define iEM_TERA1SC01RIM	 BUFFER[1916]	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define idiEM_TERA1SC01RIM	 557	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define iEM_TERA1SS12LIM	 BUFFER[1919]	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define idiEM_TERA1SS12LIM	 558	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define iEM_TERB1SS21LIM	 BUFFER[1922]	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define idiEM_TERB1SS21LIM	 559	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define iEM_TERB1SS11LIM	 BUFFER[1925]	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define idiEM_TERB1SS11LIM	 560	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define iEM_TERB1MC01RIM	 BUFFER[1928]	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define idiEM_TERB1MC01RIM	 561	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define iEM_TERB1SS12LIM	 BUFFER[1931]	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define idiEM_TERB1SS12LIM	 562	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define iEM_TERTLG	 BUFFER[1934]	//(TERTLG) Неисправности  тележки от ИС
#define idiEM_TERTLG	 563	//(TERTLG) Неисправности  тележки от ИС
#define fEM_R4MC01RC1	 BUFFER[1937]	//(R4MC01RC1) Заданная координата тележки от ИС
#define idfEM_R4MC01RC1	 564	//(R4MC01RC1) Заданная координата тележки от ИС
#define fEM_R4MV01RC1	 BUFFER[1942]	//(R4MV01RC1) Заданная скорость тележки от ИС
#define idfEM_R4MV01RC1	 565	//(R4MV01RC1) Заданная скорость тележки от ИС
#define iEM_TERMAZ2	 BUFFER[1947]	//(TERMAZ2) Неисправности АЗ2 от ИС
#define idiEM_TERMAZ2	 566	//(TERMAZ2) Неисправности АЗ2 от ИС
#define fEM_B8MV01RC1	 BUFFER[1950]	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define idfEM_B8MV01RC1	 567	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define iEM_TERDS2	 BUFFER[1955]	//(TERDS2) Неисправности ДС2 от ИС
#define idiEM_TERDS2	 568	//(TERDS2) Неисправности ДС2 от ИС
#define fEM_A8MC01RC1	 BUFFER[1958]	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define idfEM_A8MC01RC1	 569	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define fEM_A8MV01RC1	 BUFFER[1963]	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define idfEM_A8MV01RC1	 570	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define iEM_TERBZ1	 BUFFER[1968]	//(TERBZ1) Неисправности БЗ1
#define idiEM_TERBZ1	 571	//(TERBZ1) Неисправности БЗ1
#define fEM_A6MC01RC1	 BUFFER[1971]	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define idfEM_A6MC01RC1	 572	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define fEM_A6MV01RC1	 BUFFER[1976]	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define idfEM_A6MV01RC1	 573	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define iEM_TERBZ2	 BUFFER[1981]	//(TERBZ2) Неисправности БЗ2
#define idiEM_TERBZ2	 574	//(TERBZ2) Неисправности БЗ2
#define fEM_B6MC01RC1	 BUFFER[1984]	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define idfEM_B6MC01RC1	 575	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define fEM_B6MV01RC1	 BUFFER[1989]	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define idfEM_B6MV01RC1	 576	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define lEM_R3AD10LC1	 BUFFER[1994]	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define idlEM_R3AD10LC1	 577	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define lEM_R3AD20LC1	 BUFFER[1996]	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define idlEM_R3AD20LC1	 578	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define lEM_R6AD10LC1	 BUFFER[1998]	//(R6AD10LC1) Выкатить кран-балку от ИС
#define idlEM_R6AD10LC1	 579	//(R6AD10LC1) Выкатить кран-балку от ИС
#define lEM_R5AD10LC1	 BUFFER[2000]	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define idlEM_R5AD10LC1	 580	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define lEM_R5AD20LC1	 BUFFER[2002]	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define idlEM_R5AD20LC1	 581	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define iEM_TERMDZ2	 BUFFER[2004]	//(TERMDZ2) Неисправности МДЗ2
#define idiEM_TERMDZ2	 582	//(TERMDZ2) Неисправности МДЗ2
#define fEM_R2MC01RC1	 BUFFER[2007]	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define idfEM_R2MC01RC1	 583	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define fEM_R2MV01RC1	 BUFFER[2012]	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define idfEM_R2MV01RC1	 584	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define iEM_TERMDZ1	 BUFFER[2017]	//(TERMDZ1) Неисправности МДЗ1
#define idiEM_TERMDZ1	 585	//(TERMDZ1) Неисправности МДЗ1
#define fEM_R1MC01RC1	 BUFFER[2020]	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define idfEM_R1MC01RC1	 586	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define fEM_R1MV01RC1	 BUFFER[2025]	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define idfEM_R1MV01RC1	 587	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define iEM_TERNL1	 BUFFER[2030]	//(TERNL1) Неисправности НЛ1
#define idiEM_TERNL1	 588	//(TERNL1) Неисправности НЛ1
#define fEM_A5MC01RC1	 BUFFER[2033]	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define idfEM_A5MC01RC1	 589	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define fEM_A5MV01RC1	 BUFFER[2038]	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define idfEM_A5MV01RC1	 590	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define iEM_TERNL2	 BUFFER[2043]	//(TERNL2) Неисправности НЛ2
#define idiEM_TERNL2	 591	//(TERNL2) Неисправности НЛ2
#define fEM_B5MC01RC1	 BUFFER[2046]	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define idfEM_B5MC01RC1	 592	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define fEM_B5MV01RC1	 BUFFER[2051]	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define idfEM_B5MV01RC1	 593	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define lEM_R8AD10LC1	 BUFFER[2056]	//(R8AD10LC1) Установить аварийный НИ от ИС
#define idlEM_R8AD10LC1	 594	//(R8AD10LC1) Установить аварийный НИ от ИС
#define fEM_A1UC08RIM	 BUFFER[2058]	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define idfEM_A1UC08RIM	 595	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define fEM_A2UC08RIM	 BUFFER[2063]	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define idfEM_A2UC08RIM	 596	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define fEM_A3UC08RIM	 BUFFER[2068]	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define idfEM_A3UC08RIM	 597	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define iEM_TERB2SS33LIM	 BUFFER[2073]	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define idiEM_TERB2SS33LIM	 598	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define iEM_TERA1VP81LIM	 BUFFER[2076]	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define idiEM_TERA1VP81LIM	 599	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define iEM_TERB1VP81LIM	 BUFFER[2079]	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define idiEM_TERB1VP81LIM	 600	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define fEM_A0UT03RSP	 BUFFER[2082]	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define idfEM_A0UT03RSP	 601	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define fEM_A0UR01RSP	 BUFFER[2087]	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define idfEM_A0UR01RSP	 602	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define fEM_A0UR02RSP	 BUFFER[2092]	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define idfEM_A0UR02RSP	 603	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define fEM_B0UT03RSP	 BUFFER[2097]	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define idfEM_B0UT03RSP	 604	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define fEM_A1MC01RSP	 BUFFER[2102]	//(A1MC01RSP) Стартовая координата  ББ1
#define idfEM_A1MC01RSP	 605	//(A1MC01RSP) Стартовая координата  ББ1
#define fEM_A1MC02RSP	 BUFFER[2107]	//(A1MC02RSP) Стартовая координата штока ББ1
#define idfEM_A1MC02RSP	 606	//(A1MC02RSP) Стартовая координата штока ББ1
#define fEM_B1MC01RSP	 BUFFER[2112]	//(B1MC01RSP) Стартовая координата  ББ2
#define idfEM_B1MC01RSP	 607	//(B1MC01RSP) Стартовая координата  ББ2
#define fEM_B1MC02RSP	 BUFFER[2117]	//(B1MC02RSP) Стартовая координата штока ББ2
#define idfEM_B1MC02RSP	 608	//(B1MC02RSP) Стартовая координата штока ББ2
#define fEM_A2MC01RC1	 BUFFER[2122]	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define idfEM_A2MC01RC1	 609	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define fEM_A2MV01RC1	 BUFFER[2127]	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define idfEM_A2MV01RC1	 610	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define fEM_A2MC01RSP	 BUFFER[2132]	//(A2MC01RSP) Стартовая координата  РБ1
#define idfEM_A2MC01RSP	 611	//(A2MC01RSP) Стартовая координата  РБ1
#define fEM_A2MC02RSP	 BUFFER[2137]	//(A2MC02RSP) Стартовая координата штока РБ1
#define idfEM_A2MC02RSP	 612	//(A2MC02RSP) Стартовая координата штока РБ1
#define fEM_B2MC01RSP	 BUFFER[2142]	//(B2MC01RSP) Стартовая координата  РБ2
#define idfEM_B2MC01RSP	 613	//(B2MC01RSP) Стартовая координата  РБ2
#define fEM_B2MC02RSP	 BUFFER[2147]	//(B2MC02RSP) Стартовая координата штока РБ2
#define idfEM_B2MC02RSP	 614	//(B2MC02RSP) Стартовая координата штока РБ2
#define fEM_A3MC01RSP	 BUFFER[2152]	//(A3MC01RSP) Стартовая координата  ИС1
#define idfEM_A3MC01RSP	 615	//(A3MC01RSP) Стартовая координата  ИС1
#define fEM_A3MC02RSP	 BUFFER[2157]	//(A3MC02RSP) Стартовая координата штока ИС1
#define idfEM_A3MC02RSP	 616	//(A3MC02RSP) Стартовая координата штока ИС1
#define fEM_B3MC01RSP	 BUFFER[2162]	//(B3MC01RSP) Стартовая координата  ИС2
#define idfEM_B3MC01RSP	 617	//(B3MC01RSP) Стартовая координата  ИС2
#define fEM_B3MC02RSP	 BUFFER[2167]	//(B3MC02RSP) Стартовая координата штока ИС2
#define idfEM_B3MC02RSP	 618	//(B3MC02RSP) Стартовая координата штока ИС2
#define fEM_B8MC01RSP	 BUFFER[2172]	//(B8MC01RSP) Стартовая координата АЗ2
#define idfEM_B8MC01RSP	 619	//(B8MC01RSP) Стартовая координата АЗ2
#define fEM_A8MC01RSP	 BUFFER[2177]	//(A8MC01RSP) Стартовая координата ДС2
#define idfEM_A8MC01RSP	 620	//(A8MC01RSP) Стартовая координата ДС2
#define fEM_A6MC01RSP	 BUFFER[2182]	//(A6MC01RSP) Стартовая координата БЗ1
#define idfEM_A6MC01RSP	 621	//(A6MC01RSP) Стартовая координата БЗ1
#define fEM_B6MC01RSP	 BUFFER[2187]	//(B6MC01RSP) Стартовая координата БЗ2
#define idfEM_B6MC01RSP	 622	//(B6MC01RSP) Стартовая координата БЗ2
#define fEM_R3UC01RSP	 BUFFER[2192]	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define idfEM_R3UC01RSP	 623	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define fEM_R5UC01RSP	 BUFFER[2197]	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define idfEM_R5UC01RSP	 624	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define fEM_R6UC01RSP	 BUFFER[2202]	//(R6UC01RSP) Стартовая координата Кран-балки
#define idfEM_R6UC01RSP	 625	//(R6UC01RSP) Стартовая координата Кран-балки
#define fEM_R2MC01RSP	 BUFFER[2207]	//(R2MC01RSP) Стартовая координата МДЗ2
#define idfEM_R2MC01RSP	 626	//(R2MC01RSP) Стартовая координата МДЗ2
#define fEM_R1MC01RSP	 BUFFER[2212]	//(R1MC01RSP) Стартовая координата МДЗ1
#define idfEM_R1MC01RSP	 627	//(R1MC01RSP) Стартовая координата МДЗ1
#define fEM_A5MC01RSP	 BUFFER[2217]	//(A5MC01RSP) Стартовая координата НЛ1
#define idfEM_A5MC01RSP	 628	//(A5MC01RSP) Стартовая координата НЛ1
#define fEM_B5MC01RSP	 BUFFER[2222]	//(B5MC01RSP) Стартовая координата НЛ2
#define idfEM_B5MC01RSP	 629	//(B5MC01RSP) Стартовая координата НЛ2
#define fEM_A9MC01RSP	 BUFFER[2227]	//(A9MC01RSP) Стартовая координата НИ ДС1
#define idfEM_A9MC01RSP	 630	//(A9MC01RSP) Стартовая координата НИ ДС1
#define fEM_B9MC01RSP	 BUFFER[2232]	//(B9MC01RSP) Стартовая координата НИ ДС2
#define idfEM_B9MC01RSP	 631	//(B9MC01RSP) Стартовая координата НИ ДС2
#define fEM_A4MC01RSP	 BUFFER[2237]	//(A4MC01RSP) Стартовая координата НИ1
#define idfEM_A4MC01RSP	 632	//(A4MC01RSP) Стартовая координата НИ1
#define fEM_B4MC01RSP	 BUFFER[2242]	//(B4MC01RSP) Стартовая координата НИ2
#define idfEM_B4MC01RSP	 633	//(B4MC01RSP) Стартовая координата НИ2
#define fEM_R4MC01RSP	 BUFFER[2247]	//(R4MC01RSP) Стартовая координата тележки
#define idfEM_R4MC01RSP	 634	//(R4MC01RSP) Стартовая координата тележки
#define fEM_A1MV01RC1	 BUFFER[2252]	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define idfEM_A1MV01RC1	 635	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define iEM_TERB7MS31LIM	 BUFFER[2257]	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define idiEM_TERB7MS31LIM	 636	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define iEM_TERA7MS31LIM	 BUFFER[2260]	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define idiEM_TERA7MS31LIM	 637	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define fEM_R7UY00RSS	 BUFFER[2263]	//(R7UY00RSS) Y-координата АЗ1 см
#define idfEM_R7UY00RSS	 638	//(R7UY00RSS) Y-координата АЗ1 см
#define iEM_TERA6VS12LIM	 BUFFER[2268]	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define idiEM_TERA6VS12LIM	 639	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define iEM_TERA6VS22LIM	 BUFFER[2271]	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define idiEM_TERA6VS22LIM	 640	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define iEM_TERB6VS12LIM	 BUFFER[2274]	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define idiEM_TERB6VS12LIM	 641	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define iEM_TERB6VS22LIM	 BUFFER[2277]	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define idiEM_TERB6VS22LIM	 642	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define iEM_TERA5VS22LIM	 BUFFER[2280]	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define idiEM_TERA5VS22LIM	 643	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define iEM_TERA5VS12LIM	 BUFFER[2283]	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define idiEM_TERA5VS12LIM	 644	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define iEM_TERB5VS12LIM	 BUFFER[2286]	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define idiEM_TERB5VS12LIM	 645	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define iEM_TERB5VS22LIM	 BUFFER[2289]	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define idiEM_TERB5VS22LIM	 646	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define iEM_TERR1VS12LIM	 BUFFER[2292]	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define idiEM_TERR1VS12LIM	 647	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define iEM_TERR1VS22LIM	 BUFFER[2295]	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define idiEM_TERR1VS22LIM	 648	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define iEM_TERR2VS12LIM	 BUFFER[2298]	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define idiEM_TERR2VS12LIM	 649	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define iEM_TERR2VS22LIM	 BUFFER[2301]	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define idiEM_TERR2VS22LIM	 650	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define iEM_TERR4VS12LDU	 BUFFER[2304]	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS12LDU	 651	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR4VS22LDU	 BUFFER[2307]	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS22LDU	 652	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define fEM_A0UX13RSS	 BUFFER[2310]	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	 653	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	 BUFFER[2315]	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	 654	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	 BUFFER[2320]	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	 655	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_R7UX13RSS	 BUFFER[2325]	//(R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	 656	//(R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	 BUFFER[2330]	//(R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	 657	//(R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	 BUFFER[2335]	//(R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	 658	//(R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY13RSS	 BUFFER[2340]	//(R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	 659	//(R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	 BUFFER[2345]	//(R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	 660	//(R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	 BUFFER[2350]	//(R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	 661	//(R7UY15RSS) Y-координата камеры R7IN53
#define fEM_R7UX16RSS	 BUFFER[2355]	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define idfEM_R7UX16RSS	 662	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define fEM_B8MC01RC1	 BUFFER[2360]	//(B8MC01RC1) Заданная координата АЗ2 от ИС
#define idfEM_B8MC01RC1	 663	//(B8MC01RC1) Заданная координата АЗ2 от ИС
#define fEM_A0UN07RIM	 BUFFER[2365]	//(A0UN07RIM) Доля запаздывающих нейтронов
#define idfEM_A0UN07RIM	 664	//(A0UN07RIM) Доля запаздывающих нейтронов
#define fEM_R0UL02RIM	 BUFFER[2370]	//(R0UL02RIM) Время удержания синхроимпульса
#define idfEM_R0UL02RIM	 665	//(R0UL02RIM) Время удержания синхроимпульса
#define fEM_R0UL04RDU	 BUFFER[2375]	//(R0UL04RDU) Время блокировки повторной генерации импульса
#define idfEM_R0UL04RDU	 666	//(R0UL04RDU) Время блокировки повторной генерации импульса
#define fEM_R0UL02RDU	 BUFFER[2380]	//(R0UL02RDU) Время задержки  ИНИ
#define idfEM_R0UL02RDU	 667	//(R0UL02RDU) Время задержки  ИНИ
#define fEM_R0UL03RDU	 BUFFER[2385]	//(R0UL03RDU) Максимальное время цикла, сек
#define idfEM_R0UL03RDU	 668	//(R0UL03RDU) Максимальное время цикла, сек
#define bFirstEnterFlag	 BUFFER[2390]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 669	//(bFirstEnterFlag) 
#define internal1_m39_reg	 BUFFER[2392]	//(internal1_m39_reg) режим работы квдс 0 - ожидание сигнала 1- выдан импульс 2 отсчет удержания синхроимпульса 3 -блокировка
#define idinternal1_m39_reg	 670	//(internal1_m39_reg) режим работы квдс 0 - ожидание сигнала 1- выдан импульс 2 отсчет удержания синхроимпульса 3 -блокировка
#define internal1_m39_tgen	 BUFFER[2395]	//(internal1_m39_tgen) задержки срабатывания генератора импульса
#define idinternal1_m39_tgen	 671	//(internal1_m39_tgen) задержки срабатывания генератора импульса
#define internal1_m39_tsin	 BUFFER[2400]	//(internal1_m39_tsin) время до конца удержания синхроимпульса
#define idinternal1_m39_tsin	 672	//(internal1_m39_tsin) время до конца удержания синхроимпульса
#define internal1_m39_tlock	 BUFFER[2405]	//(internal1_m39_tlock) время до конца блокировки
#define idinternal1_m39_tlock	 673	//(internal1_m39_tlock) время до конца блокировки
#define internal1_m39_fef	 BUFFER[2410]	//(internal1_m39_fef) fef
#define idinternal1_m39_fef	 674	//(internal1_m39_fef) fef
#define internal1_m880_Chim0	 BUFFER[2412]	//(internal1_m880_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m880_Chim0	 675	//(internal1_m880_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m870_Chim0	 BUFFER[2417]	//(internal1_m870_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m870_Chim0	 676	//(internal1_m870_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m862_Chim0	 BUFFER[2422]	//(internal1_m862_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m862_Chim0	 677	//(internal1_m862_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m817_Out10	 BUFFER[2427]	//(internal1_m817_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m817_Out10	 678	//(internal1_m817_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m816_Out10	 BUFFER[2429]	//(internal1_m816_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m816_Out10	 679	//(internal1_m816_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m999_Out10	 BUFFER[2431]	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m999_Out10	 680	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m998_Out10	 BUFFER[2433]	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m998_Out10	 681	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m997_Out10	 BUFFER[2435]	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m997_Out10	 682	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m996_Out10	 BUFFER[2437]	//(internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m996_Out10	 683	//(internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m675_Out10	 BUFFER[2439]	//(internal1_m675_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m675_Out10	 684	//(internal1_m675_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m674_Out10	 BUFFER[2441]	//(internal1_m674_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m674_Out10	 685	//(internal1_m674_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m653_Out10	 BUFFER[2443]	//(internal1_m653_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m653_Out10	 686	//(internal1_m653_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m652_Out10	 BUFFER[2445]	//(internal1_m652_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m652_Out10	 687	//(internal1_m652_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m673_Out10	 BUFFER[2447]	//(internal1_m673_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m673_Out10	 688	//(internal1_m673_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m672_Out10	 BUFFER[2449]	//(internal1_m672_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m672_Out10	 689	//(internal1_m672_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m651_Out10	 BUFFER[2451]	//(internal1_m651_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m651_Out10	 690	//(internal1_m651_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m650_Out10	 BUFFER[2453]	//(internal1_m650_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m650_Out10	 691	//(internal1_m650_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m517_Out10	 BUFFER[2455]	//(internal1_m517_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m517_Out10	 692	//(internal1_m517_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m533_Out10	 BUFFER[2457]	//(internal1_m533_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m533_Out10	 693	//(internal1_m533_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m405_Out10	 BUFFER[2459]	//(internal1_m405_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m405_Out10	 694	//(internal1_m405_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m478_q0	 BUFFER[2461]	//(internal1_m478_q0) q0 - внутренний параметр
#define idinternal1_m478_q0	 695	//(internal1_m478_q0) q0 - внутренний параметр
#define internal1_m479_q0	 BUFFER[2463]	//(internal1_m479_q0) q0 - внутренний параметр
#define idinternal1_m479_q0	 696	//(internal1_m479_q0) q0 - внутренний параметр
#define internal1_m466_q0	 BUFFER[2465]	//(internal1_m466_q0) q0 - внутренний параметр
#define idinternal1_m466_q0	 697	//(internal1_m466_q0) q0 - внутренний параметр
#define internal1_m467_q0	 BUFFER[2467]	//(internal1_m467_q0) q0 - внутренний параметр
#define idinternal1_m467_q0	 698	//(internal1_m467_q0) q0 - внутренний параметр
#define internal1_m626_tx	 BUFFER[2469]	//(internal1_m626_tx) tx - время накопленное сек
#define idinternal1_m626_tx	 699	//(internal1_m626_tx) tx - время накопленное сек
#define internal1_m626_y0	 BUFFER[2474]	//(internal1_m626_y0) y0
#define idinternal1_m626_y0	 700	//(internal1_m626_y0) y0
#define internal1_m614_tx	 BUFFER[2475]	//(internal1_m614_tx) tx - время накопленное сек
#define idinternal1_m614_tx	 701	//(internal1_m614_tx) tx - время накопленное сек
#define internal1_m614_y0	 BUFFER[2480]	//(internal1_m614_y0) y0
#define idinternal1_m614_y0	 702	//(internal1_m614_y0) y0
#define internal1_m602_tx	 BUFFER[2481]	//(internal1_m602_tx) tx - время накопленное сек
#define idinternal1_m602_tx	 703	//(internal1_m602_tx) tx - время накопленное сек
#define internal1_m602_y0	 BUFFER[2486]	//(internal1_m602_y0) y0
#define idinternal1_m602_y0	 704	//(internal1_m602_y0) y0
#define internal1_m600_tx	 BUFFER[2487]	//(internal1_m600_tx) tx - время накопленное сек
#define idinternal1_m600_tx	 705	//(internal1_m600_tx) tx - время накопленное сек
#define internal1_m600_y0	 BUFFER[2492]	//(internal1_m600_y0) y0
#define idinternal1_m600_y0	 706	//(internal1_m600_y0) y0
#define internal1_m210_Out10	 BUFFER[2493]	//(internal1_m210_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m210_Out10	 707	//(internal1_m210_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m228_Out10	 BUFFER[2495]	//(internal1_m228_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m228_Out10	 708	//(internal1_m228_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m47_Out10	 BUFFER[2497]	//(internal1_m47_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m47_Out10	 709	//(internal1_m47_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m62_Out10	 BUFFER[2499]	//(internal1_m62_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m62_Out10	 710	//(internal1_m62_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m970_Out10	 BUFFER[2501]	//(internal1_m970_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m970_Out10	 711	//(internal1_m970_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m967_Out10	 BUFFER[2503]	//(internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m967_Out10	 712	//(internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m966_Out10	 BUFFER[2505]	//(internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m966_Out10	 713	//(internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m969_Xtek0	 BUFFER[2507]	//(internal1_m969_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m969_Xtek0	 714	//(internal1_m969_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m952_Xtek0	 BUFFER[2512]	//(internal1_m952_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m952_Xtek0	 715	//(internal1_m952_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m953_Out10	 BUFFER[2517]	//(internal1_m953_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m953_Out10	 716	//(internal1_m953_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m950_Out10	 BUFFER[2519]	//(internal1_m950_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m950_Out10	 717	//(internal1_m950_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m949_Out10	 BUFFER[2521]	//(internal1_m949_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m949_Out10	 718	//(internal1_m949_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1037_Out10	 BUFFER[2523]	//(internal1_m1037_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1037_Out10	 719	//(internal1_m1037_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1018_Out10	 BUFFER[2525]	//(internal1_m1018_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1018_Out10	 720	//(internal1_m1018_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1017_Out10	 BUFFER[2527]	//(internal1_m1017_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1017_Out10	 721	//(internal1_m1017_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1016_Out10	 BUFFER[2529]	//(internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1016_Out10	 722	//(internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m838_Out10	 BUFFER[2531]	//(internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m838_Out10	 723	//(internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m840_Out10	 BUFFER[2533]	//(internal1_m840_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m840_Out10	 724	//(internal1_m840_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m837_Out10	 BUFFER[2535]	//(internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m837_Out10	 725	//(internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m839_Out10	 BUFFER[2537]	//(internal1_m839_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m839_Out10	 726	//(internal1_m839_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m813_Out10	 BUFFER[2539]	//(internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m813_Out10	 727	//(internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m814_Out10	 BUFFER[2541]	//(internal1_m814_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m814_Out10	 728	//(internal1_m814_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m812_Out10	 BUFFER[2543]	//(internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m812_Out10	 729	//(internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m811_Out10	 BUFFER[2545]	//(internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m811_Out10	 730	//(internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1032_Out10	 BUFFER[2547]	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1032_Out10	 731	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m984_Out10	 BUFFER[2549]	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m984_Out10	 732	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m983_Out10	 BUFFER[2551]	//(internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m983_Out10	 733	//(internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m982_Out10	 BUFFER[2553]	//(internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m982_Out10	 734	//(internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m981_Out10	 BUFFER[2555]	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m981_Out10	 735	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1033_Out10	 BUFFER[2557]	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1033_Out10	 736	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1014_Out10	 BUFFER[2559]	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1014_Out10	 737	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m815_Out10	 BUFFER[2561]	//(internal1_m815_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m815_Out10	 738	//(internal1_m815_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1015_Out10	 BUFFER[2563]	//(internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1015_Out10	 739	//(internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1013_Out10	 BUFFER[2565]	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1013_Out10	 740	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1034_Out10	 BUFFER[2567]	//(internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1034_Out10	 741	//(internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1012_Out10	 BUFFER[2569]	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1012_Out10	 742	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m995_Out10	 BUFFER[2571]	//(internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m995_Out10	 743	//(internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m980_Out10	 BUFFER[2573]	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m980_Out10	 744	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m534_Out10	 BUFFER[2575]	//(internal1_m534_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m534_Out10	 745	//(internal1_m534_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m415_Xtek0	 BUFFER[2577]	//(internal1_m415_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m415_Xtek0	 746	//(internal1_m415_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m406_Out10	 BUFFER[2582]	//(internal1_m406_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m406_Out10	 747	//(internal1_m406_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m408_Out10	 BUFFER[2584]	//(internal1_m408_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m408_Out10	 748	//(internal1_m408_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m407_Out10	 BUFFER[2586]	//(internal1_m407_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m407_Out10	 749	//(internal1_m407_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m853_Out10	 BUFFER[2588]	//(internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m853_Out10	 750	//(internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m854_Out10	 BUFFER[2590]	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m854_Out10	 751	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m852_Out10	 BUFFER[2592]	//(internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m852_Out10	 752	//(internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1036_Out10	 BUFFER[2594]	//(internal1_m1036_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1036_Out10	 753	//(internal1_m1036_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m688_Out10	 BUFFER[2596]	//(internal1_m688_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m688_Out10	 754	//(internal1_m688_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m689_Out10	 BUFFER[2598]	//(internal1_m689_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m689_Out10	 755	//(internal1_m689_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m686_Out10	 BUFFER[2600]	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m686_Out10	 756	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m687_Out10	 BUFFER[2602]	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m687_Out10	 757	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m550_Out10	 BUFFER[2604]	//(internal1_m550_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m550_Out10	 758	//(internal1_m550_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m549_Out10	 BUFFER[2606]	//(internal1_m549_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m549_Out10	 759	//(internal1_m549_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m834_Xtek0	 BUFFER[2608]	//(internal1_m834_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m834_Xtek0	 760	//(internal1_m834_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m836_Xtek0	 BUFFER[2613]	//(internal1_m836_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m836_Xtek0	 761	//(internal1_m836_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m685_Out10	 BUFFER[2618]	//(internal1_m685_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m685_Out10	 762	//(internal1_m685_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m669_Out10	 BUFFER[2620]	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m669_Out10	 763	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m649_Out10	 BUFFER[2622]	//(internal1_m649_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m649_Out10	 764	//(internal1_m649_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m668_Out10	 BUFFER[2624]	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m668_Out10	 765	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m648_Out10	 BUFFER[2626]	//(internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m648_Out10	 766	//(internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m336_Out10	 BUFFER[2628]	//(internal1_m336_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m336_Out10	 767	//(internal1_m336_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m335_Out10	 BUFFER[2630]	//(internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m335_Out10	 768	//(internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m320_Out10	 BUFFER[2632]	//(internal1_m320_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m320_Out10	 769	//(internal1_m320_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m319_Out10	 BUFFER[2634]	//(internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m319_Out10	 770	//(internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m551_Out10	 BUFFER[2636]	//(internal1_m551_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m551_Out10	 771	//(internal1_m551_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m349_Out10	 BUFFER[2638]	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m349_Out10	 772	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m333_Xtek0	 BUFFER[2640]	//(internal1_m333_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m333_Xtek0	 773	//(internal1_m333_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m348_Out10	 BUFFER[2645]	//(internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m348_Out10	 774	//(internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m346_Out10	 BUFFER[2647]	//(internal1_m346_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m346_Out10	 775	//(internal1_m346_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m326_Xtek0	 BUFFER[2649]	//(internal1_m326_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m326_Xtek0	 776	//(internal1_m326_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m347_Out10	 BUFFER[2654]	//(internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m347_Out10	 777	//(internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m318_Out10	 BUFFER[2656]	//(internal1_m318_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m318_Out10	 778	//(internal1_m318_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m334_Out10	 BUFFER[2658]	//(internal1_m334_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m334_Out10	 779	//(internal1_m334_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m427_Out10	 BUFFER[2660]	//(internal1_m427_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m427_Out10	 780	//(internal1_m427_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m428_Xtek0	 BUFFER[2662]	//(internal1_m428_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m428_Xtek0	 781	//(internal1_m428_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m426_Out10	 BUFFER[2667]	//(internal1_m426_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m426_Out10	 782	//(internal1_m426_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m425_Out10	 BUFFER[2669]	//(internal1_m425_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m425_Out10	 783	//(internal1_m425_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m424_Out10	 BUFFER[2671]	//(internal1_m424_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m424_Out10	 784	//(internal1_m424_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1035_Out10	 BUFFER[2673]	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1035_Out10	 785	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m152_Out10	 BUFFER[2675]	//(internal1_m152_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m152_Out10	 786	//(internal1_m152_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m151_Out10	 BUFFER[2677]	//(internal1_m151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m151_Out10	 787	//(internal1_m151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m470_X00	 BUFFER[2679]	//(internal1_m470_X00)  X00 - текущая координата механизма
#define idinternal1_m470_X00	 788	//(internal1_m470_X00)  X00 - текущая координата механизма
#define internal1_m470_V00	 BUFFER[2684]	//(internal1_m470_V00)  V00 - текущая скорость механизма
#define idinternal1_m470_V00	 789	//(internal1_m470_V00)  V00 - текущая скорость механизма
#define internal1_m470_Pav0	 BUFFER[2689]	//(internal1_m470_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m470_Pav0	 790	//(internal1_m470_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m470_Zav0	 BUFFER[2691]	//(internal1_m470_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m470_Zav0	 791	//(internal1_m470_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m470_Pv0	 BUFFER[2693]	//(internal1_m470_Pv0)  - Пер. выключатель механизма
#define idinternal1_m470_Pv0	 792	//(internal1_m470_Pv0)  - Пер. выключатель механизма
#define internal1_m470_Zv0	 BUFFER[2695]	//(internal1_m470_Zv0)  - Зад. выключатель механизма
#define idinternal1_m470_Zv0	 793	//(internal1_m470_Zv0)  - Зад. выключатель механизма
#define internal1_m470_RA00	 BUFFER[2697]	//(internal1_m470_RA00)  - последнее задание вперед
#define idinternal1_m470_RA00	 794	//(internal1_m470_RA00)  - последнее задание вперед
#define internal1_m470_RA10	 BUFFER[2699]	//(internal1_m470_RA10)  - последнее задание назад
#define idinternal1_m470_RA10	 795	//(internal1_m470_RA10)  - последнее задание назад
#define internal1_m470_MyFirstEnterFlag	 BUFFER[2701]	//(internal1_m470_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m470_MyFirstEnterFlag	 796	//(internal1_m470_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m482_X00	 BUFFER[2703]	//(internal1_m482_X00)  X00 - текущая координата механизма
#define idinternal1_m482_X00	 797	//(internal1_m482_X00)  X00 - текущая координата механизма
#define internal1_m482_V00	 BUFFER[2708]	//(internal1_m482_V00)  V00 - текущая скорость механизма
#define idinternal1_m482_V00	 798	//(internal1_m482_V00)  V00 - текущая скорость механизма
#define internal1_m482_Pav0	 BUFFER[2713]	//(internal1_m482_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m482_Pav0	 799	//(internal1_m482_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m482_Zav0	 BUFFER[2715]	//(internal1_m482_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m482_Zav0	 800	//(internal1_m482_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m482_Pv0	 BUFFER[2717]	//(internal1_m482_Pv0)  - Пер. выключатель механизма
#define idinternal1_m482_Pv0	 801	//(internal1_m482_Pv0)  - Пер. выключатель механизма
#define internal1_m482_Zv0	 BUFFER[2719]	//(internal1_m482_Zv0)  - Зад. выключатель механизма
#define idinternal1_m482_Zv0	 802	//(internal1_m482_Zv0)  - Зад. выключатель механизма
#define internal1_m482_RA00	 BUFFER[2721]	//(internal1_m482_RA00)  - последнее задание вперед
#define idinternal1_m482_RA00	 803	//(internal1_m482_RA00)  - последнее задание вперед
#define internal1_m482_RA10	 BUFFER[2723]	//(internal1_m482_RA10)  - последнее задание назад
#define idinternal1_m482_RA10	 804	//(internal1_m482_RA10)  - последнее задание назад
#define internal1_m482_MyFirstEnterFlag	 BUFFER[2725]	//(internal1_m482_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m482_MyFirstEnterFlag	 805	//(internal1_m482_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m472_X00	 BUFFER[2727]	//(internal1_m472_X00)  X00 - текущая координата механизма
#define idinternal1_m472_X00	 806	//(internal1_m472_X00)  X00 - текущая координата механизма
#define internal1_m472_V00	 BUFFER[2732]	//(internal1_m472_V00)  V00 - текущая скорость механизма
#define idinternal1_m472_V00	 807	//(internal1_m472_V00)  V00 - текущая скорость механизма
#define internal1_m472_Pav0	 BUFFER[2737]	//(internal1_m472_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m472_Pav0	 808	//(internal1_m472_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m472_Zav0	 BUFFER[2739]	//(internal1_m472_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m472_Zav0	 809	//(internal1_m472_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m472_Pv0	 BUFFER[2741]	//(internal1_m472_Pv0)  - Пер. выключатель механизма
#define idinternal1_m472_Pv0	 810	//(internal1_m472_Pv0)  - Пер. выключатель механизма
#define internal1_m472_Zv0	 BUFFER[2743]	//(internal1_m472_Zv0)  - Зад. выключатель механизма
#define idinternal1_m472_Zv0	 811	//(internal1_m472_Zv0)  - Зад. выключатель механизма
#define internal1_m472_RA00	 BUFFER[2745]	//(internal1_m472_RA00)  - последнее задание вперед
#define idinternal1_m472_RA00	 812	//(internal1_m472_RA00)  - последнее задание вперед
#define internal1_m472_RA10	 BUFFER[2747]	//(internal1_m472_RA10)  - последнее задание назад
#define idinternal1_m472_RA10	 813	//(internal1_m472_RA10)  - последнее задание назад
#define internal1_m472_MyFirstEnterFlag	 BUFFER[2749]	//(internal1_m472_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m472_MyFirstEnterFlag	 814	//(internal1_m472_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m605_X00	 BUFFER[2751]	//(internal1_m605_X00)  X00 - текущая координата механизма
#define idinternal1_m605_X00	 815	//(internal1_m605_X00)  X00 - текущая координата механизма
#define internal1_m605_V00	 BUFFER[2756]	//(internal1_m605_V00)  V00 - текущая скорость механизма
#define idinternal1_m605_V00	 816	//(internal1_m605_V00)  V00 - текущая скорость механизма
#define internal1_m605_Pav0	 BUFFER[2761]	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m605_Pav0	 817	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m605_Zav0	 BUFFER[2763]	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m605_Zav0	 818	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m605_Pv0	 BUFFER[2765]	//(internal1_m605_Pv0)  - Пер. выключатель механизма
#define idinternal1_m605_Pv0	 819	//(internal1_m605_Pv0)  - Пер. выключатель механизма
#define internal1_m605_Zv0	 BUFFER[2767]	//(internal1_m605_Zv0)  - Зад. выключатель механизма
#define idinternal1_m605_Zv0	 820	//(internal1_m605_Zv0)  - Зад. выключатель механизма
#define internal1_m605_RA00	 BUFFER[2769]	//(internal1_m605_RA00)  - последнее задание вперед
#define idinternal1_m605_RA00	 821	//(internal1_m605_RA00)  - последнее задание вперед
#define internal1_m605_RA10	 BUFFER[2771]	//(internal1_m605_RA10)  - последнее задание назад
#define idinternal1_m605_RA10	 822	//(internal1_m605_RA10)  - последнее задание назад
#define internal1_m605_MyFirstEnterFlag	 BUFFER[2773]	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m605_MyFirstEnterFlag	 823	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m604_X00	 BUFFER[2775]	//(internal1_m604_X00)  X00 - текущая координата механизма
#define idinternal1_m604_X00	 824	//(internal1_m604_X00)  X00 - текущая координата механизма
#define internal1_m604_V00	 BUFFER[2780]	//(internal1_m604_V00)  V00 - текущая скорость механизма
#define idinternal1_m604_V00	 825	//(internal1_m604_V00)  V00 - текущая скорость механизма
#define internal1_m604_Pav0	 BUFFER[2785]	//(internal1_m604_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m604_Pav0	 826	//(internal1_m604_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m604_Zav0	 BUFFER[2787]	//(internal1_m604_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m604_Zav0	 827	//(internal1_m604_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m604_Pv0	 BUFFER[2789]	//(internal1_m604_Pv0)  - Пер. выключатель механизма
#define idinternal1_m604_Pv0	 828	//(internal1_m604_Pv0)  - Пер. выключатель механизма
#define internal1_m604_Zv0	 BUFFER[2791]	//(internal1_m604_Zv0)  - Зад. выключатель механизма
#define idinternal1_m604_Zv0	 829	//(internal1_m604_Zv0)  - Зад. выключатель механизма
#define internal1_m604_RA00	 BUFFER[2793]	//(internal1_m604_RA00)  - последнее задание вперед
#define idinternal1_m604_RA00	 830	//(internal1_m604_RA00)  - последнее задание вперед
#define internal1_m604_RA10	 BUFFER[2795]	//(internal1_m604_RA10)  - последнее задание назад
#define idinternal1_m604_RA10	 831	//(internal1_m604_RA10)  - последнее задание назад
#define internal1_m604_MyFirstEnterFlag	 BUFFER[2797]	//(internal1_m604_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m604_MyFirstEnterFlag	 832	//(internal1_m604_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m592_X00	 BUFFER[2799]	//(internal1_m592_X00)  X00 - текущая координата механизма
#define idinternal1_m592_X00	 833	//(internal1_m592_X00)  X00 - текущая координата механизма
#define internal1_m592_V00	 BUFFER[2804]	//(internal1_m592_V00)  V00 - текущая скорость механизма
#define idinternal1_m592_V00	 834	//(internal1_m592_V00)  V00 - текущая скорость механизма
#define internal1_m592_Pav0	 BUFFER[2809]	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m592_Pav0	 835	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m592_Zav0	 BUFFER[2811]	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m592_Zav0	 836	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m592_Pv0	 BUFFER[2813]	//(internal1_m592_Pv0)  - Пер. выключатель механизма
#define idinternal1_m592_Pv0	 837	//(internal1_m592_Pv0)  - Пер. выключатель механизма
#define internal1_m592_Zv0	 BUFFER[2815]	//(internal1_m592_Zv0)  - Зад. выключатель механизма
#define idinternal1_m592_Zv0	 838	//(internal1_m592_Zv0)  - Зад. выключатель механизма
#define internal1_m592_RA00	 BUFFER[2817]	//(internal1_m592_RA00)  - последнее задание вперед
#define idinternal1_m592_RA00	 839	//(internal1_m592_RA00)  - последнее задание вперед
#define internal1_m592_RA10	 BUFFER[2819]	//(internal1_m592_RA10)  - последнее задание назад
#define idinternal1_m592_RA10	 840	//(internal1_m592_RA10)  - последнее задание назад
#define internal1_m592_MyFirstEnterFlag	 BUFFER[2821]	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m592_MyFirstEnterFlag	 841	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m591_X00	 BUFFER[2823]	//(internal1_m591_X00)  X00 - текущая координата механизма
#define idinternal1_m591_X00	 842	//(internal1_m591_X00)  X00 - текущая координата механизма
#define internal1_m591_V00	 BUFFER[2828]	//(internal1_m591_V00)  V00 - текущая скорость механизма
#define idinternal1_m591_V00	 843	//(internal1_m591_V00)  V00 - текущая скорость механизма
#define internal1_m591_Pav0	 BUFFER[2833]	//(internal1_m591_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m591_Pav0	 844	//(internal1_m591_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m591_Zav0	 BUFFER[2835]	//(internal1_m591_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m591_Zav0	 845	//(internal1_m591_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m591_Pv0	 BUFFER[2837]	//(internal1_m591_Pv0)  - Пер. выключатель механизма
#define idinternal1_m591_Pv0	 846	//(internal1_m591_Pv0)  - Пер. выключатель механизма
#define internal1_m591_Zv0	 BUFFER[2839]	//(internal1_m591_Zv0)  - Зад. выключатель механизма
#define idinternal1_m591_Zv0	 847	//(internal1_m591_Zv0)  - Зад. выключатель механизма
#define internal1_m591_RA00	 BUFFER[2841]	//(internal1_m591_RA00)  - последнее задание вперед
#define idinternal1_m591_RA00	 848	//(internal1_m591_RA00)  - последнее задание вперед
#define internal1_m591_RA10	 BUFFER[2843]	//(internal1_m591_RA10)  - последнее задание назад
#define idinternal1_m591_RA10	 849	//(internal1_m591_RA10)  - последнее задание назад
#define internal1_m591_MyFirstEnterFlag	 BUFFER[2845]	//(internal1_m591_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m591_MyFirstEnterFlag	 850	//(internal1_m591_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m634_y0	 BUFFER[2847]	//(internal1_m634_y0) y0 - внутренний параметр
#define idinternal1_m634_y0	 851	//(internal1_m634_y0) y0 - внутренний параметр
#define internal1_m799_Chim0	 BUFFER[2852]	//(internal1_m799_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m799_Chim0	 852	//(internal1_m799_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m790_Chim0	 BUFFER[2857]	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m790_Chim0	 853	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m782_Chim0	 BUFFER[2862]	//(internal1_m782_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m782_Chim0	 854	//(internal1_m782_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m773_Chim0	 BUFFER[2867]	//(internal1_m773_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m773_Chim0	 855	//(internal1_m773_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m764_Chim0	 BUFFER[2872]	//(internal1_m764_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m764_Chim0	 856	//(internal1_m764_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m756_Chim0	 BUFFER[2877]	//(internal1_m756_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m756_Chim0	 857	//(internal1_m756_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m747_Chim0	 BUFFER[2882]	//(internal1_m747_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m747_Chim0	 858	//(internal1_m747_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m738_Chim0	 BUFFER[2887]	//(internal1_m738_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m738_Chim0	 859	//(internal1_m738_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m730_Chim0	 BUFFER[2892]	//(internal1_m730_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m730_Chim0	 860	//(internal1_m730_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m721_Chim0	 BUFFER[2897]	//(internal1_m721_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m721_Chim0	 861	//(internal1_m721_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m712_Chim0	 BUFFER[2902]	//(internal1_m712_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m712_Chim0	 862	//(internal1_m712_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m702_Chim0	 BUFFER[2907]	//(internal1_m702_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m702_Chim0	 863	//(internal1_m702_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m579_X00	 BUFFER[2912]	//(internal1_m579_X00)  X00 - текущая координата механизма
#define idinternal1_m579_X00	 864	//(internal1_m579_X00)  X00 - текущая координата механизма
#define internal1_m579_V00	 BUFFER[2917]	//(internal1_m579_V00)  V00 - текущая скорость механизма
#define idinternal1_m579_V00	 865	//(internal1_m579_V00)  V00 - текущая скорость механизма
#define internal1_m579_Pav0	 BUFFER[2922]	//(internal1_m579_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m579_Pav0	 866	//(internal1_m579_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m579_Zav0	 BUFFER[2924]	//(internal1_m579_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m579_Zav0	 867	//(internal1_m579_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m579_Pv0	 BUFFER[2926]	//(internal1_m579_Pv0)  - Пер. выключатель механизма
#define idinternal1_m579_Pv0	 868	//(internal1_m579_Pv0)  - Пер. выключатель механизма
#define internal1_m579_Zv0	 BUFFER[2928]	//(internal1_m579_Zv0)  - Зад. выключатель механизма
#define idinternal1_m579_Zv0	 869	//(internal1_m579_Zv0)  - Зад. выключатель механизма
#define internal1_m579_RA00	 BUFFER[2930]	//(internal1_m579_RA00)  - последнее задание вперед
#define idinternal1_m579_RA00	 870	//(internal1_m579_RA00)  - последнее задание вперед
#define internal1_m579_RA10	 BUFFER[2932]	//(internal1_m579_RA10)  - последнее задание назад
#define idinternal1_m579_RA10	 871	//(internal1_m579_RA10)  - последнее задание назад
#define internal1_m579_MyFirstEnterFlag	 BUFFER[2934]	//(internal1_m579_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m579_MyFirstEnterFlag	 872	//(internal1_m579_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m565_X00	 BUFFER[2936]	//(internal1_m565_X00)  X00 - текущая координата механизма
#define idinternal1_m565_X00	 873	//(internal1_m565_X00)  X00 - текущая координата механизма
#define internal1_m565_V00	 BUFFER[2941]	//(internal1_m565_V00)  V00 - текущая скорость механизма
#define idinternal1_m565_V00	 874	//(internal1_m565_V00)  V00 - текущая скорость механизма
#define internal1_m565_Pav0	 BUFFER[2946]	//(internal1_m565_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m565_Pav0	 875	//(internal1_m565_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m565_Zav0	 BUFFER[2948]	//(internal1_m565_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m565_Zav0	 876	//(internal1_m565_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m565_Pv0	 BUFFER[2950]	//(internal1_m565_Pv0)  - Пер. выключатель механизма
#define idinternal1_m565_Pv0	 877	//(internal1_m565_Pv0)  - Пер. выключатель механизма
#define internal1_m565_Zv0	 BUFFER[2952]	//(internal1_m565_Zv0)  - Зад. выключатель механизма
#define idinternal1_m565_Zv0	 878	//(internal1_m565_Zv0)  - Зад. выключатель механизма
#define internal1_m565_RA00	 BUFFER[2954]	//(internal1_m565_RA00)  - последнее задание вперед
#define idinternal1_m565_RA00	 879	//(internal1_m565_RA00)  - последнее задание вперед
#define internal1_m565_RA10	 BUFFER[2956]	//(internal1_m565_RA10)  - последнее задание назад
#define idinternal1_m565_RA10	 880	//(internal1_m565_RA10)  - последнее задание назад
#define internal1_m565_MyFirstEnterFlag	 BUFFER[2958]	//(internal1_m565_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m565_MyFirstEnterFlag	 881	//(internal1_m565_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m456_X00	 BUFFER[2960]	//(internal1_m456_X00)  X00 - текущая координата механизма
#define idinternal1_m456_X00	 882	//(internal1_m456_X00)  X00 - текущая координата механизма
#define internal1_m456_V00	 BUFFER[2965]	//(internal1_m456_V00)  V00 - текущая скорость механизма
#define idinternal1_m456_V00	 883	//(internal1_m456_V00)  V00 - текущая скорость механизма
#define internal1_m456_Pav0	 BUFFER[2970]	//(internal1_m456_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m456_Pav0	 884	//(internal1_m456_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m456_Zav0	 BUFFER[2972]	//(internal1_m456_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m456_Zav0	 885	//(internal1_m456_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m456_Pv0	 BUFFER[2974]	//(internal1_m456_Pv0)  - Пер. выключатель механизма
#define idinternal1_m456_Pv0	 886	//(internal1_m456_Pv0)  - Пер. выключатель механизма
#define internal1_m456_Zv0	 BUFFER[2976]	//(internal1_m456_Zv0)  - Зад. выключатель механизма
#define idinternal1_m456_Zv0	 887	//(internal1_m456_Zv0)  - Зад. выключатель механизма
#define internal1_m456_RA00	 BUFFER[2978]	//(internal1_m456_RA00)  - последнее задание вперед
#define idinternal1_m456_RA00	 888	//(internal1_m456_RA00)  - последнее задание вперед
#define internal1_m456_RA10	 BUFFER[2980]	//(internal1_m456_RA10)  - последнее задание назад
#define idinternal1_m456_RA10	 889	//(internal1_m456_RA10)  - последнее задание назад
#define internal1_m456_MyFirstEnterFlag	 BUFFER[2982]	//(internal1_m456_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m456_MyFirstEnterFlag	 890	//(internal1_m456_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m442_X00	 BUFFER[2984]	//(internal1_m442_X00)  X00 - текущая координата механизма
#define idinternal1_m442_X00	 891	//(internal1_m442_X00)  X00 - текущая координата механизма
#define internal1_m442_V00	 BUFFER[2989]	//(internal1_m442_V00)  V00 - текущая скорость механизма
#define idinternal1_m442_V00	 892	//(internal1_m442_V00)  V00 - текущая скорость механизма
#define internal1_m442_Pav0	 BUFFER[2994]	//(internal1_m442_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m442_Pav0	 893	//(internal1_m442_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m442_Zav0	 BUFFER[2996]	//(internal1_m442_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m442_Zav0	 894	//(internal1_m442_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m442_Pv0	 BUFFER[2998]	//(internal1_m442_Pv0)  - Пер. выключатель механизма
#define idinternal1_m442_Pv0	 895	//(internal1_m442_Pv0)  - Пер. выключатель механизма
#define internal1_m442_Zv0	 BUFFER[3000]	//(internal1_m442_Zv0)  - Зад. выключатель механизма
#define idinternal1_m442_Zv0	 896	//(internal1_m442_Zv0)  - Зад. выключатель механизма
#define internal1_m442_RA00	 BUFFER[3002]	//(internal1_m442_RA00)  - последнее задание вперед
#define idinternal1_m442_RA00	 897	//(internal1_m442_RA00)  - последнее задание вперед
#define internal1_m442_RA10	 BUFFER[3004]	//(internal1_m442_RA10)  - последнее задание назад
#define idinternal1_m442_RA10	 898	//(internal1_m442_RA10)  - последнее задание назад
#define internal1_m442_MyFirstEnterFlag	 BUFFER[3006]	//(internal1_m442_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m442_MyFirstEnterFlag	 899	//(internal1_m442_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m493_X00	 BUFFER[3008]	//(internal1_m493_X00)  X00 - текущая координата механизма
#define idinternal1_m493_X00	 900	//(internal1_m493_X00)  X00 - текущая координата механизма
#define internal1_m493_V00	 BUFFER[3013]	//(internal1_m493_V00)  V00 - текущая скорость механизма
#define idinternal1_m493_V00	 901	//(internal1_m493_V00)  V00 - текущая скорость механизма
#define internal1_m493_Pav0	 BUFFER[3018]	//(internal1_m493_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m493_Pav0	 902	//(internal1_m493_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m493_Zav0	 BUFFER[3020]	//(internal1_m493_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m493_Zav0	 903	//(internal1_m493_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m493_Pv0	 BUFFER[3022]	//(internal1_m493_Pv0)  - Пер. выключатель механизма
#define idinternal1_m493_Pv0	 904	//(internal1_m493_Pv0)  - Пер. выключатель механизма
#define internal1_m493_Zv0	 BUFFER[3024]	//(internal1_m493_Zv0)  - Зад. выключатель механизма
#define idinternal1_m493_Zv0	 905	//(internal1_m493_Zv0)  - Зад. выключатель механизма
#define internal1_m493_RA00	 BUFFER[3026]	//(internal1_m493_RA00)  - последнее задание вперед
#define idinternal1_m493_RA00	 906	//(internal1_m493_RA00)  - последнее задание вперед
#define internal1_m493_RA10	 BUFFER[3028]	//(internal1_m493_RA10)  - последнее задание назад
#define idinternal1_m493_RA10	 907	//(internal1_m493_RA10)  - последнее задание назад
#define internal1_m493_MyFirstEnterFlag	 BUFFER[3030]	//(internal1_m493_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m493_MyFirstEnterFlag	 908	//(internal1_m493_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m394_X00	 BUFFER[3032]	//(internal1_m394_X00)  X00 - текущая координата механизма
#define idinternal1_m394_X00	 909	//(internal1_m394_X00)  X00 - текущая координата механизма
#define internal1_m394_V00	 BUFFER[3037]	//(internal1_m394_V00)  V00 - текущая скорость механизма
#define idinternal1_m394_V00	 910	//(internal1_m394_V00)  V00 - текущая скорость механизма
#define internal1_m394_Pav0	 BUFFER[3042]	//(internal1_m394_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m394_Pav0	 911	//(internal1_m394_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m394_Zav0	 BUFFER[3044]	//(internal1_m394_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m394_Zav0	 912	//(internal1_m394_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m394_Pv0	 BUFFER[3046]	//(internal1_m394_Pv0)  - Пер. выключатель механизма
#define idinternal1_m394_Pv0	 913	//(internal1_m394_Pv0)  - Пер. выключатель механизма
#define internal1_m394_Zv0	 BUFFER[3048]	//(internal1_m394_Zv0)  - Зад. выключатель механизма
#define idinternal1_m394_Zv0	 914	//(internal1_m394_Zv0)  - Зад. выключатель механизма
#define internal1_m394_RA00	 BUFFER[3050]	//(internal1_m394_RA00)  - последнее задание вперед
#define idinternal1_m394_RA00	 915	//(internal1_m394_RA00)  - последнее задание вперед
#define internal1_m394_RA10	 BUFFER[3052]	//(internal1_m394_RA10)  - последнее задание назад
#define idinternal1_m394_RA10	 916	//(internal1_m394_RA10)  - последнее задание назад
#define internal1_m394_MyFirstEnterFlag	 BUFFER[3054]	//(internal1_m394_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m394_MyFirstEnterFlag	 917	//(internal1_m394_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m379_X00	 BUFFER[3056]	//(internal1_m379_X00)  X00 - текущая координата механизма
#define idinternal1_m379_X00	 918	//(internal1_m379_X00)  X00 - текущая координата механизма
#define internal1_m379_V00	 BUFFER[3061]	//(internal1_m379_V00)  V00 - текущая скорость механизма
#define idinternal1_m379_V00	 919	//(internal1_m379_V00)  V00 - текущая скорость механизма
#define internal1_m379_Pav0	 BUFFER[3066]	//(internal1_m379_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m379_Pav0	 920	//(internal1_m379_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m379_Zav0	 BUFFER[3068]	//(internal1_m379_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m379_Zav0	 921	//(internal1_m379_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m379_Pv0	 BUFFER[3070]	//(internal1_m379_Pv0)  - Пер. выключатель механизма
#define idinternal1_m379_Pv0	 922	//(internal1_m379_Pv0)  - Пер. выключатель механизма
#define internal1_m379_Zv0	 BUFFER[3072]	//(internal1_m379_Zv0)  - Зад. выключатель механизма
#define idinternal1_m379_Zv0	 923	//(internal1_m379_Zv0)  - Зад. выключатель механизма
#define internal1_m379_RA00	 BUFFER[3074]	//(internal1_m379_RA00)  - последнее задание вперед
#define idinternal1_m379_RA00	 924	//(internal1_m379_RA00)  - последнее задание вперед
#define internal1_m379_RA10	 BUFFER[3076]	//(internal1_m379_RA10)  - последнее задание назад
#define idinternal1_m379_RA10	 925	//(internal1_m379_RA10)  - последнее задание назад
#define internal1_m379_MyFirstEnterFlag	 BUFFER[3078]	//(internal1_m379_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m379_MyFirstEnterFlag	 926	//(internal1_m379_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m363_X00	 BUFFER[3080]	//(internal1_m363_X00)  X00 - текущая координата механизма
#define idinternal1_m363_X00	 927	//(internal1_m363_X00)  X00 - текущая координата механизма
#define internal1_m363_V00	 BUFFER[3085]	//(internal1_m363_V00)  V00 - текущая скорость механизма
#define idinternal1_m363_V00	 928	//(internal1_m363_V00)  V00 - текущая скорость механизма
#define internal1_m363_Pav0	 BUFFER[3090]	//(internal1_m363_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m363_Pav0	 929	//(internal1_m363_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m363_Zav0	 BUFFER[3092]	//(internal1_m363_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m363_Zav0	 930	//(internal1_m363_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m363_Pv0	 BUFFER[3094]	//(internal1_m363_Pv0)  - Пер. выключатель механизма
#define idinternal1_m363_Pv0	 931	//(internal1_m363_Pv0)  - Пер. выключатель механизма
#define internal1_m363_Zv0	 BUFFER[3096]	//(internal1_m363_Zv0)  - Зад. выключатель механизма
#define idinternal1_m363_Zv0	 932	//(internal1_m363_Zv0)  - Зад. выключатель механизма
#define internal1_m363_RA00	 BUFFER[3098]	//(internal1_m363_RA00)  - последнее задание вперед
#define idinternal1_m363_RA00	 933	//(internal1_m363_RA00)  - последнее задание вперед
#define internal1_m363_RA10	 BUFFER[3100]	//(internal1_m363_RA10)  - последнее задание назад
#define idinternal1_m363_RA10	 934	//(internal1_m363_RA10)  - последнее задание назад
#define internal1_m363_MyFirstEnterFlag	 BUFFER[3102]	//(internal1_m363_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m363_MyFirstEnterFlag	 935	//(internal1_m363_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m892_X00	 BUFFER[3104]	//(internal1_m892_X00)  X00 - текущая координата механизма
#define idinternal1_m892_X00	 936	//(internal1_m892_X00)  X00 - текущая координата механизма
#define internal1_m892_V00	 BUFFER[3109]	//(internal1_m892_V00)  V00 - текущая скорость механизма
#define idinternal1_m892_V00	 937	//(internal1_m892_V00)  V00 - текущая скорость механизма
#define internal1_m892_Pav0	 BUFFER[3114]	//(internal1_m892_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m892_Pav0	 938	//(internal1_m892_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m892_Zav0	 BUFFER[3116]	//(internal1_m892_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m892_Zav0	 939	//(internal1_m892_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m892_Pv0	 BUFFER[3118]	//(internal1_m892_Pv0)  - Пер. выключатель механизма
#define idinternal1_m892_Pv0	 940	//(internal1_m892_Pv0)  - Пер. выключатель механизма
#define internal1_m892_Zv0	 BUFFER[3120]	//(internal1_m892_Zv0)  - Зад. выключатель механизма
#define idinternal1_m892_Zv0	 941	//(internal1_m892_Zv0)  - Зад. выключатель механизма
#define internal1_m892_RA00	 BUFFER[3122]	//(internal1_m892_RA00)  - последнее задание вперед
#define idinternal1_m892_RA00	 942	//(internal1_m892_RA00)  - последнее задание вперед
#define internal1_m892_RA10	 BUFFER[3124]	//(internal1_m892_RA10)  - последнее задание назад
#define idinternal1_m892_RA10	 943	//(internal1_m892_RA10)  - последнее задание назад
#define internal1_m892_MyFirstEnterFlag	 BUFFER[3126]	//(internal1_m892_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m892_MyFirstEnterFlag	 944	//(internal1_m892_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m185_C1	 BUFFER[3128]	//(internal1_m185_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m185_C1	 945	//(internal1_m185_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m185_C2	 BUFFER[3133]	//(internal1_m185_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m185_C2	 946	//(internal1_m185_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m185_C3	 BUFFER[3138]	//(internal1_m185_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m185_C3	 947	//(internal1_m185_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m185_C4	 BUFFER[3143]	//(internal1_m185_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m185_C4	 948	//(internal1_m185_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m185_C5	 BUFFER[3148]	//(internal1_m185_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m185_C5	 949	//(internal1_m185_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m185_C6	 BUFFER[3153]	//(internal1_m185_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m185_C6	 950	//(internal1_m185_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m185_N20	 BUFFER[3158]	//(internal1_m185_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m185_N20	 951	//(internal1_m185_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m185_N00	 BUFFER[3163]	//(internal1_m185_N00) N00 - Текущая концентрация нейтронов
#define idinternal1_m185_N00	 952	//(internal1_m185_N00) N00 - Текущая концентрация нейтронов
#define internal1_m185_R00	 BUFFER[3168]	//(internal1_m185_R00) R00 - Текущая реактивность
#define idinternal1_m185_R00	 953	//(internal1_m185_R00) R00 - Текущая реактивность
#define internal1_m185_T00	 BUFFER[3173]	//(internal1_m185_T00) T00 - Текущая температура
#define idinternal1_m185_T00	 954	//(internal1_m185_T00) T00 - Текущая температура
#define internal1_m185_ImpINI0	 BUFFER[3178]	//(internal1_m185_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m185_ImpINI0	 955	//(internal1_m185_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m185_MyFirstEnterFlag	 BUFFER[3180]	//(internal1_m185_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m185_MyFirstEnterFlag	 956	//(internal1_m185_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m299_X00	 BUFFER[3182]	//(internal1_m299_X00) X0 - текущая координата ОРР
#define idinternal1_m299_X00	 957	//(internal1_m299_X00) X0 - текущая координата ОРР
#define internal1_m299_Sh00	 BUFFER[3187]	//(internal1_m299_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m299_Sh00	 958	//(internal1_m299_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m299_RV00	 BUFFER[3192]	//(internal1_m299_RV00) V0 - текущая скорость ОРР
#define idinternal1_m299_RV00	 959	//(internal1_m299_RV00) V0 - текущая скорость ОРР
#define internal1_m299_ShV00	 BUFFER[3197]	//(internal1_m299_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m299_ShV00	 960	//(internal1_m299_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m299_Ppv0	 BUFFER[3202]	//(internal1_m299_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m299_Ppv0	 961	//(internal1_m299_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m299_Pav0	 BUFFER[3204]	//(internal1_m299_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m299_Pav0	 962	//(internal1_m299_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m299_Zav0	 BUFFER[3206]	//(internal1_m299_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m299_Zav0	 963	//(internal1_m299_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m299_RA00	 BUFFER[3208]	//(internal1_m299_RA00) RA00 - последнее задание вперед
#define idinternal1_m299_RA00	 964	//(internal1_m299_RA00) RA00 - последнее задание вперед
#define internal1_m299_RA10	 BUFFER[3210]	//(internal1_m299_RA10) RA10 - последнее задание назад
#define idinternal1_m299_RA10	 965	//(internal1_m299_RA10) RA10 - последнее задание назад
#define internal1_m299_RA30	 BUFFER[3212]	//(internal1_m299_RA30)  RA30 - разрешение движения
#define idinternal1_m299_RA30	 966	//(internal1_m299_RA30)  RA30 - разрешение движения
#define internal1_m299_RA50	 BUFFER[3214]	//(internal1_m299_RA50) Ra50 - последнее задание скорости
#define idinternal1_m299_RA50	 967	//(internal1_m299_RA50) Ra50 - последнее задание скорости
#define internal1_m299_fls	 BUFFER[3216]	//(internal1_m299_fls)  fls - флаг одношагового режима
#define idinternal1_m299_fls	 968	//(internal1_m299_fls)  fls - флаг одношагового режима
#define internal1_m299_flp	 BUFFER[3218]	//(internal1_m299_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m299_flp	 969	//(internal1_m299_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m299_MyFirstEnterFlag	 BUFFER[3220]	//(internal1_m299_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m299_MyFirstEnterFlag	 970	//(internal1_m299_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m134_X00	 BUFFER[3222]	//(internal1_m134_X00) X0 - текущая координата ОРР
#define idinternal1_m134_X00	 971	//(internal1_m134_X00) X0 - текущая координата ОРР
#define internal1_m134_Sh00	 BUFFER[3227]	//(internal1_m134_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m134_Sh00	 972	//(internal1_m134_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m134_RV00	 BUFFER[3232]	//(internal1_m134_RV00) V0 - текущая скорость ОРР
#define idinternal1_m134_RV00	 973	//(internal1_m134_RV00) V0 - текущая скорость ОРР
#define internal1_m134_ShV00	 BUFFER[3237]	//(internal1_m134_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m134_ShV00	 974	//(internal1_m134_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m134_Ppv0	 BUFFER[3242]	//(internal1_m134_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m134_Ppv0	 975	//(internal1_m134_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m134_Pav0	 BUFFER[3244]	//(internal1_m134_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m134_Pav0	 976	//(internal1_m134_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m134_Zav0	 BUFFER[3246]	//(internal1_m134_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m134_Zav0	 977	//(internal1_m134_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m134_RA00	 BUFFER[3248]	//(internal1_m134_RA00) RA00 - последнее задание вперед
#define idinternal1_m134_RA00	 978	//(internal1_m134_RA00) RA00 - последнее задание вперед
#define internal1_m134_RA10	 BUFFER[3250]	//(internal1_m134_RA10) RA10 - последнее задание назад
#define idinternal1_m134_RA10	 979	//(internal1_m134_RA10) RA10 - последнее задание назад
#define internal1_m134_RA30	 BUFFER[3252]	//(internal1_m134_RA30)  RA30 - разрешение движения
#define idinternal1_m134_RA30	 980	//(internal1_m134_RA30)  RA30 - разрешение движения
#define internal1_m134_RA50	 BUFFER[3254]	//(internal1_m134_RA50) Ra50 - последнее задание скорости
#define idinternal1_m134_RA50	 981	//(internal1_m134_RA50) Ra50 - последнее задание скорости
#define internal1_m134_fls	 BUFFER[3256]	//(internal1_m134_fls)  fls - флаг одношагового режима
#define idinternal1_m134_fls	 982	//(internal1_m134_fls)  fls - флаг одношагового режима
#define internal1_m134_flp	 BUFFER[3258]	//(internal1_m134_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m134_flp	 983	//(internal1_m134_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m134_MyFirstEnterFlag	 BUFFER[3260]	//(internal1_m134_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m134_MyFirstEnterFlag	 984	//(internal1_m134_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m269_X00	 BUFFER[3262]	//(internal1_m269_X00) X0 - текущая координата ОРР
#define idinternal1_m269_X00	 985	//(internal1_m269_X00) X0 - текущая координата ОРР
#define internal1_m269_Sh00	 BUFFER[3267]	//(internal1_m269_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m269_Sh00	 986	//(internal1_m269_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m269_RV00	 BUFFER[3272]	//(internal1_m269_RV00) V0 - текущая скорость ОРР
#define idinternal1_m269_RV00	 987	//(internal1_m269_RV00) V0 - текущая скорость ОРР
#define internal1_m269_ShV00	 BUFFER[3277]	//(internal1_m269_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m269_ShV00	 988	//(internal1_m269_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m269_Ppv0	 BUFFER[3282]	//(internal1_m269_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m269_Ppv0	 989	//(internal1_m269_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m269_Pav0	 BUFFER[3284]	//(internal1_m269_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m269_Pav0	 990	//(internal1_m269_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m269_Zav0	 BUFFER[3286]	//(internal1_m269_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m269_Zav0	 991	//(internal1_m269_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m269_RA00	 BUFFER[3288]	//(internal1_m269_RA00) RA00 - последнее задание вперед
#define idinternal1_m269_RA00	 992	//(internal1_m269_RA00) RA00 - последнее задание вперед
#define internal1_m269_RA10	 BUFFER[3290]	//(internal1_m269_RA10) RA10 - последнее задание назад
#define idinternal1_m269_RA10	 993	//(internal1_m269_RA10) RA10 - последнее задание назад
#define internal1_m269_RA30	 BUFFER[3292]	//(internal1_m269_RA30)  RA30 - разрешение движения
#define idinternal1_m269_RA30	 994	//(internal1_m269_RA30)  RA30 - разрешение движения
#define internal1_m269_RA50	 BUFFER[3294]	//(internal1_m269_RA50) Ra50 - последнее задание скорости
#define idinternal1_m269_RA50	 995	//(internal1_m269_RA50) Ra50 - последнее задание скорости
#define internal1_m269_fls	 BUFFER[3296]	//(internal1_m269_fls)  fls - флаг одношагового режима
#define idinternal1_m269_fls	 996	//(internal1_m269_fls)  fls - флаг одношагового режима
#define internal1_m269_flp	 BUFFER[3298]	//(internal1_m269_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m269_flp	 997	//(internal1_m269_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m269_MyFirstEnterFlag	 BUFFER[3300]	//(internal1_m269_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m269_MyFirstEnterFlag	 998	//(internal1_m269_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m100_X00	 BUFFER[3302]	//(internal1_m100_X00) X0 - текущая координата ОРР
#define idinternal1_m100_X00	 999	//(internal1_m100_X00) X0 - текущая координата ОРР
#define internal1_m100_Sh00	 BUFFER[3307]	//(internal1_m100_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m100_Sh00	 1000	//(internal1_m100_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m100_RV00	 BUFFER[3312]	//(internal1_m100_RV00) V0 - текущая скорость ОРР
#define idinternal1_m100_RV00	 1001	//(internal1_m100_RV00) V0 - текущая скорость ОРР
#define internal1_m100_ShV00	 BUFFER[3317]	//(internal1_m100_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m100_ShV00	 1002	//(internal1_m100_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m100_Ppv0	 BUFFER[3322]	//(internal1_m100_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m100_Ppv0	 1003	//(internal1_m100_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m100_Pav0	 BUFFER[3324]	//(internal1_m100_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m100_Pav0	 1004	//(internal1_m100_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m100_Zav0	 BUFFER[3326]	//(internal1_m100_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m100_Zav0	 1005	//(internal1_m100_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m100_RA00	 BUFFER[3328]	//(internal1_m100_RA00) RA00 - последнее задание вперед
#define idinternal1_m100_RA00	 1006	//(internal1_m100_RA00) RA00 - последнее задание вперед
#define internal1_m100_RA10	 BUFFER[3330]	//(internal1_m100_RA10) RA10 - последнее задание назад
#define idinternal1_m100_RA10	 1007	//(internal1_m100_RA10) RA10 - последнее задание назад
#define internal1_m100_RA30	 BUFFER[3332]	//(internal1_m100_RA30)  RA30 - разрешение движения
#define idinternal1_m100_RA30	 1008	//(internal1_m100_RA30)  RA30 - разрешение движения
#define internal1_m100_RA50	 BUFFER[3334]	//(internal1_m100_RA50) Ra50 - последнее задание скорости
#define idinternal1_m100_RA50	 1009	//(internal1_m100_RA50) Ra50 - последнее задание скорости
#define internal1_m100_fls	 BUFFER[3336]	//(internal1_m100_fls)  fls - флаг одношагового режима
#define idinternal1_m100_fls	 1010	//(internal1_m100_fls)  fls - флаг одношагового режима
#define internal1_m100_flp	 BUFFER[3338]	//(internal1_m100_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m100_flp	 1011	//(internal1_m100_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m100_MyFirstEnterFlag	 BUFFER[3340]	//(internal1_m100_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m100_MyFirstEnterFlag	 1012	//(internal1_m100_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m234_X00	 BUFFER[3342]	//(internal1_m234_X00) X0 - текущая координата ОРР
#define idinternal1_m234_X00	 1013	//(internal1_m234_X00) X0 - текущая координата ОРР
#define internal1_m234_Sh00	 BUFFER[3347]	//(internal1_m234_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m234_Sh00	 1014	//(internal1_m234_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m234_RV00	 BUFFER[3352]	//(internal1_m234_RV00) V0 - текущая скорость ОРР
#define idinternal1_m234_RV00	 1015	//(internal1_m234_RV00) V0 - текущая скорость ОРР
#define internal1_m234_ShV00	 BUFFER[3357]	//(internal1_m234_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m234_ShV00	 1016	//(internal1_m234_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m234_Ppv0	 BUFFER[3362]	//(internal1_m234_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m234_Ppv0	 1017	//(internal1_m234_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m234_Pav0	 BUFFER[3364]	//(internal1_m234_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m234_Pav0	 1018	//(internal1_m234_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m234_Zav0	 BUFFER[3366]	//(internal1_m234_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m234_Zav0	 1019	//(internal1_m234_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m234_RA00	 BUFFER[3368]	//(internal1_m234_RA00) RA00 - последнее задание вперед
#define idinternal1_m234_RA00	 1020	//(internal1_m234_RA00) RA00 - последнее задание вперед
#define internal1_m234_RA10	 BUFFER[3370]	//(internal1_m234_RA10) RA10 - последнее задание назад
#define idinternal1_m234_RA10	 1021	//(internal1_m234_RA10) RA10 - последнее задание назад
#define internal1_m234_RA30	 BUFFER[3372]	//(internal1_m234_RA30)  RA30 - разрешение движения
#define idinternal1_m234_RA30	 1022	//(internal1_m234_RA30)  RA30 - разрешение движения
#define internal1_m234_RA50	 BUFFER[3374]	//(internal1_m234_RA50) Ra50 - последнее задание скорости
#define idinternal1_m234_RA50	 1023	//(internal1_m234_RA50) Ra50 - последнее задание скорости
#define internal1_m234_fls	 BUFFER[3376]	//(internal1_m234_fls)  fls - флаг одношагового режима
#define idinternal1_m234_fls	 1024	//(internal1_m234_fls)  fls - флаг одношагового режима
#define internal1_m234_flp	 BUFFER[3378]	//(internal1_m234_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m234_flp	 1025	//(internal1_m234_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m234_MyFirstEnterFlag	 BUFFER[3380]	//(internal1_m234_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m234_MyFirstEnterFlag	 1026	//(internal1_m234_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m66_X00	 BUFFER[3382]	//(internal1_m66_X00) X0 - текущая координата ОРР
#define idinternal1_m66_X00	 1027	//(internal1_m66_X00) X0 - текущая координата ОРР
#define internal1_m66_Sh00	 BUFFER[3387]	//(internal1_m66_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m66_Sh00	 1028	//(internal1_m66_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m66_RV00	 BUFFER[3392]	//(internal1_m66_RV00) V0 - текущая скорость ОРР
#define idinternal1_m66_RV00	 1029	//(internal1_m66_RV00) V0 - текущая скорость ОРР
#define internal1_m66_ShV00	 BUFFER[3397]	//(internal1_m66_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m66_ShV00	 1030	//(internal1_m66_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m66_Ppv0	 BUFFER[3402]	//(internal1_m66_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m66_Ppv0	 1031	//(internal1_m66_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m66_Pav0	 BUFFER[3404]	//(internal1_m66_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m66_Pav0	 1032	//(internal1_m66_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m66_Zav0	 BUFFER[3406]	//(internal1_m66_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m66_Zav0	 1033	//(internal1_m66_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m66_RA00	 BUFFER[3408]	//(internal1_m66_RA00) RA00 - последнее задание вперед
#define idinternal1_m66_RA00	 1034	//(internal1_m66_RA00) RA00 - последнее задание вперед
#define internal1_m66_RA10	 BUFFER[3410]	//(internal1_m66_RA10) RA10 - последнее задание назад
#define idinternal1_m66_RA10	 1035	//(internal1_m66_RA10) RA10 - последнее задание назад
#define internal1_m66_RA30	 BUFFER[3412]	//(internal1_m66_RA30)  RA30 - разрешение движения
#define idinternal1_m66_RA30	 1036	//(internal1_m66_RA30)  RA30 - разрешение движения
#define internal1_m66_RA50	 BUFFER[3414]	//(internal1_m66_RA50) Ra50 - последнее задание скорости
#define idinternal1_m66_RA50	 1037	//(internal1_m66_RA50) Ra50 - последнее задание скорости
#define internal1_m66_fls	 BUFFER[3416]	//(internal1_m66_fls)  fls - флаг одношагового режима
#define idinternal1_m66_fls	 1038	//(internal1_m66_fls)  fls - флаг одношагового режима
#define internal1_m66_flp	 BUFFER[3418]	//(internal1_m66_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m66_flp	 1039	//(internal1_m66_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m66_MyFirstEnterFlag	 BUFFER[3420]	//(internal1_m66_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m66_MyFirstEnterFlag	 1040	//(internal1_m66_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m14_C1	 BUFFER[3422]	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m14_C1	 1041	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m14_C2	 BUFFER[3427]	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m14_C2	 1042	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m14_C3	 BUFFER[3432]	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m14_C3	 1043	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m14_C4	 BUFFER[3437]	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m14_C4	 1044	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m14_C5	 BUFFER[3442]	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m14_C5	 1045	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m14_C6	 BUFFER[3447]	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m14_C6	 1046	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m14_N20	 BUFFER[3452]	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m14_N20	 1047	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m14_N00	 BUFFER[3457]	//(internal1_m14_N00) N00 - Текущая концентрация нейтронов
#define idinternal1_m14_N00	 1048	//(internal1_m14_N00) N00 - Текущая концентрация нейтронов
#define internal1_m14_R00	 BUFFER[3462]	//(internal1_m14_R00) R00 - Текущая реактивность
#define idinternal1_m14_R00	 1049	//(internal1_m14_R00) R00 - Текущая реактивность
#define internal1_m14_T00	 BUFFER[3467]	//(internal1_m14_T00) T00 - Текущая температура
#define idinternal1_m14_T00	 1050	//(internal1_m14_T00) T00 - Текущая температура
#define internal1_m14_ImpINI0	 BUFFER[3472]	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m14_ImpINI0	 1051	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m14_MyFirstEnterFlag	 BUFFER[3474]	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m14_MyFirstEnterFlag	 1052	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,5	,1	, &B1IC01UDU},	//( - , SDu) Координата штока ББ2
	{ 2	,5	,1	, &A1IC01UDU},	//( - , SDu) Координата штока ББ1
	{ 3	,1	,1	, &A1IS12LDU},	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
	{ 4	,1	,1	, &A1IS11LDU},	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
	{ 5	,1	,1	, &A1IS21LDU},	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
	{ 6	,1	,1	, &B6IS21LDU},	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
	{ 7	,1	,1	, &B6IS11LDU},	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
	{ 8	,1	,1	, &A6IS21LDU},	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
	{ 9	,1	,1	, &A6IS11LDU},	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
	{ 10	,1	,1	, &A8IS12LDU},	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
	{ 11	,1	,1	, &A8IS22LDU},	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
	{ 12	,1	,1	, &B8IS12LDU},	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
	{ 13	,1	,1	, &B8IS22LDU},	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
	{ 14	,1	,1	, &R4IS12LDU},	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
	{ 15	,1	,1	, &R4IS22LDU},	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
	{ 16	,1	,1	, &R4IS21LDU},	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
	{ 17	,1	,1	, &R4IS11LDU},	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
	{ 18	,1	,1	, &R0IS02LDU},	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
	{ 19	,1	,1	, &R0EE04LZ2},	//( - , SBz2) Питание  АКНП4  отключить
	{ 20	,1	,1	, &R0EE03LZ2},	//( - , SBz2) Питание  АКНП3  отключить
	{ 21	,1	,1	, &R0EE02LZ2},	//( - , SBz2) Питание  АКНП  отключить
	{ 22	,1	,1	, &R0EE04LZ1},	//( - , SBz1) Питание  АКНП4  отключить
	{ 23	,1	,1	, &R0EE03LZ1},	//( - , SBz1) Питание  АКНП3  отключить
	{ 24	,1	,1	, &R0EE02LZ1},	//( - , SBz1) Питание  АКНП  отключить
	{ 25	,1	,1	, &R0EE01LZ2},	//( - , SBz2) Питание  АКНП1  отключить
	{ 26	,1	,1	, &R0EE01LZ1},	//( - , SBz1) Питание  АКНП1  отключить
	{ 27	,1	,1	, &B4IS10LDU},	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
	{ 28	,1	,1	, &A4IS10LDU},	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
	{ 29	,1	,1	, &B1IE04LDU},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{ 30	,1	,1	, &B1IE03LDU},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{ 31	,1	,1	, &A1IE04LDU},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{ 32	,1	,1	, &A1IE03LDU},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{ 33	,1	,1	, &B1IS12LDU},	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
	{ 34	,1	,1	, &B1IS11LDU},	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
	{ 35	,1	,1	, &B1IS21LDU},	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
	{ 36	,5	,1	, &B2IC01UDU},	//( - , SDu) Координата штока РБ2
	{ 37	,1	,1	, &B2IS12LDU},	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
	{ 38	,1	,1	, &B2IS11LDU},	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
	{ 39	,1	,1	, &B2IS21LDU},	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
	{ 40	,1	,1	, &B9IS21LDU},	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
	{ 41	,1	,1	, &B9IS11LDU},	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
	{ 42	,1	,1	, &A9IS21LDU},	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
	{ 43	,1	,1	, &A9IS11LDU},	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
	{ 44	,1	,1	, &B5IS21LDU},	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
	{ 45	,1	,1	, &B5IS11LDU},	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
	{ 46	,1	,1	, &A5IS21LDU},	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
	{ 47	,1	,1	, &A5IS11LDU},	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
	{ 48	,1	,1	, &B0VP81LZZ},	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
	{ 49	,1	,1	, &A0VP81LZZ},	//(do32_pti:110 - K03DO, - ) Давление АЗ1 в норме
	{ 50	,5	,1	, &B8IC01UDU},	//( - , SDu) Координата АЗ2, мм
	{ 51	,5	,1	, &A8IC01UDU},	//( - , SDu) Координата ДС2
	{ 52	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 53	,1	,1	, &B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	{ 54	,1	,1	, &A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	{ 55	,1	,1	, &R2IS21LDU},	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
	{ 56	,1	,1	, &R2IS11LDU},	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
	{ 57	,1	,1	, &R1IS21LDU},	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
	{ 58	,1	,1	, &R1IS11LDU},	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
	{ 59	,1	,1	, &B4IS21LDU},	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
	{ 60	,1	,1	, &B4IS11LDU},	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
	{ 61	,1	,1	, &R8IS11LDU},	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
	{ 62	,1	,1	, &A4IS21LDU},	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
	{ 63	,1	,1	, &A4IS11LDU},	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
	{ 64	,1	,1	, &R5IS21LDU},	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
	{ 65	,1	,1	, &R5IS11LDU},	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
	{ 66	,1	,1	, &R3IS21LDU},	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
	{ 67	,1	,1	, &R3IS11LDU},	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
	{ 68	,1	,1	, &B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	{ 69	,3	,1	, &B2IP01IZ2},	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
	{ 70	,3	,1	, &B2IP01IZ1},	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
	{ 71	,3	,1	, &R0MW11IP1},	//( - , SCM) Переключатель ВЫСТРЕЛ
	{ 72	,1	,1	, &R0IS01FI0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{ 73	,3	,1	, &A0IT03IRP},	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
	{ 74	,3	,1	, &B0IT03IRP},	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
	{ 75	,8	,1	, &R0IN03FI3},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{ 76	,8	,1	, &R0IN02FI3},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{ 77	,8	,1	, &R0IN03FI2},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{ 78	,8	,1	, &R0IN07RIP},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{ 79	,8	,1	, &R0IN06RIP},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{ 80	,3	,1	, &TerR0IN06FRP},	//( - , - ) Неисправности СНМ-11 -1,2
	{ 81	,8	,1	, &R0IN03RIP},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{ 82	,8	,1	, &R0IN02RIP},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{ 83	,8	,1	, &R0IN01RIP},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{ 84	,8	,1	, &R0IN02FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{ 85	,8	,1	, &R0IN03FI1},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{ 86	,8	,1	, &R0IN02FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{ 87	,8	,1	, &R0IN03FI4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{ 88	,8	,1	, &B0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{ 89	,8	,1	, &B0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{ 90	,8	,1	, &B0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{ 91	,8	,1	, &B0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{ 92	,8	,1	, &B0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{ 93	,8	,1	, &B0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{ 94	,8	,1	, &A0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{ 95	,8	,1	, &A0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{ 96	,8	,1	, &A0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{ 97	,8	,1	, &A0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{ 98	,8	,1	, &A0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{ 99	,8	,1	, &A0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{ 100	,1	,1	, &R8AD22LDU},	//(do32_pti:140 - K09DO, - ) Сигнал синхронизации с импульсом
	{ 101	,8	,1	, &ttlAknp1},	//( - , SA1) 
	{ 102	,8	,1	, &LTAKTS},	//( - , - ) takt scm
	{ 103	,8	,1	, &krb2},	//( - , - ) 
	{ 104	,8	,1	, &krb1},	//( - , - ) 
	{ 105	,3	,1	, &R0DEUMLSS},	//( - , SCM) Сигнал управления моделью
	{ 106	,1	,1	, &B6VS22LDU},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{ 107	,1	,1	, &A6VS12LDU},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{ 108	,1	,1	, &A6VS22LDU},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{ 109	,1	,1	, &B8IS21LDU},	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
	{ 110	,1	,1	, &B8IS11LDU},	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
	{ 111	,1	,1	, &A1VP81LZZ},	//(do32_pti:110 - K01DO, - ) Давление СБРОС ББ1 в норме
	{ 112	,1	,1	, &B1VP81LZZ},	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
	{ 113	,1	,1	, &B2IS33LDU},	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
	{ 114	,8	,1	, &A0VN01RIM},	//( - , SCM) Период разгона  AЗ1
	{ 115	,1	,1	, &B2IS32LIM},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{ 116	,1	,1	, &B2IS11LIM},	//( - , SCM) Магнит РБ2 обесточен
	{ 117	,1	,1	, &A2IS32LIM},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{ 118	,1	,1	, &A2IS11LIM},	//( - , SCM) Магнит РБ1 обесточен
	{ 119	,1	,1	, &B1IS32LIM},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	{ 120	,1	,1	, &B1IS11LIM},	//( - , SCM) Магнит ББ2 обесточен
	{ 121	,1	,1	, &A1IS32LIM},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{ 122	,1	,1	, &A1IS11LIM},	//( - , SCM) Магнит ББ1 обесточен
	{ 123	,1	,1	, &A3AD34LDU},	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
	{ 124	,8	,1	, &R0IN02FI4},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{ 125	,8	,1	, &R0IN01FI3},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{ 126	,8	,1	, &R0IN01FI2},	//( - , SA2) Выход СНМ-11 Гц от ПТИ
	{ 127	,8	,1	, &R0IN01FI4},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{ 128	,8	,1	, &R0IN01FI1},	//( - , SA1) Выход СНМ11 Гц от ПТИ
	{ 129	,1	,1	, &B7AP31LDU},	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
	{ 130	,1	,1	, &A7AP31LDU},	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
	{ 131	,1	,1	, &R4VS12LDU},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{ 132	,1	,1	, &R4VS22LDU},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{ 133	,1	,1	, &R1VS12LDU},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{ 134	,1	,1	, &R2VS12LDU},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{ 135	,1	,1	, &R2VS22LDU},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{ 136	,1	,1	, &R1VS22LDU},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{ 137	,1	,1	, &B5VS12LDU},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{ 138	,1	,1	, &B5VS22LDU},	//( - , SCM) Движение НЛ2 в сторону НУ
	{ 139	,1	,1	, &A5VS12LDU},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{ 140	,1	,1	, &A5VS22LDU},	//( - , SCM) Движение НЛ1 в сторону НУ
	{ 141	,1	,1	, &B6VS12LDU},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{ 142	,1	,1	, &A8AD10LDU},	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
	{ 143	,1	,1	, &B8AD20LDU},	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
	{ 144	,1	,1	, &B8AD10LDU},	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
	{ 145	,1	,1	, &R4AD20LDU},	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
	{ 146	,1	,1	, &R4AD10LDU},	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
	{ 147	,8	,1	, &B0SR01RIM},	//( - , SCM) Текущая реактивность AЗ2
	{ 148	,1	,1	, &B3AD33LDU},	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 149	,1	,1	, &B3AD05LDU},	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
	{ 150	,1	,1	, &B3AD04LDU},	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
	{ 151	,1	,1	, &B3AD03LDU},	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
	{ 152	,1	,1	, &B3AD02LDU},	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
	{ 153	,1	,1	, &B3AD01LDU},	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
	{ 154	,1	,1	, &B3AD21LDU},	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 155	,1	,1	, &B3AD11LDU},	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 156	,1	,1	, &A3AD33LDU},	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
	{ 157	,1	,1	, &A3AD05LDU},	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
	{ 158	,1	,1	, &A3AD04LDU},	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
	{ 159	,8	,1	, &R0SR02RIM},	//( - , SCM) Текущая мощность РУ (ватт)
	{ 160	,8	,1	, &R0CR02RIM},	//( - , SCM) Коэффициент 11 связи АЗ1,2
	{ 161	,8	,1	, &R0CR01RIM},	//( - , SCM) Коэффициент 12 связи АЗ1,2
	{ 162	,8	,1	, &B0SN08RIM},	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
	{ 163	,8	,1	, &A0SN08RIM},	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
	{ 164	,1	,1	, &B5AD20LDU},	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
	{ 165	,1	,1	, &B5AD10LDU},	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
	{ 166	,1	,1	, &A5AD20LDU},	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
	{ 167	,1	,1	, &A5AD10LDU},	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
	{ 168	,1	,1	, &R2AD20LDU},	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
	{ 169	,1	,1	, &R2AD10LDU},	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
	{ 170	,1	,1	, &R1AD20LDU},	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
	{ 171	,1	,1	, &R1AD10LDU},	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
	{ 172	,1	,1	, &B6AD20LDU},	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
	{ 173	,1	,1	, &B6AD10LDU},	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
	{ 174	,1	,1	, &A6AD20LDU},	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
	{ 175	,1	,1	, &A6AD10LDU},	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
	{ 176	,1	,1	, &A8AD20LDU},	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
	{ 177	,1	,1	, &A2AD01LDU},	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
	{ 178	,1	,1	, &A2AD21LDU},	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
	{ 179	,1	,1	, &A2AD11LDU},	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
	{ 180	,1	,1	, &B1AD05LDU},	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
	{ 181	,1	,1	, &B1AD04LDU},	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
	{ 182	,1	,1	, &B1AD03LDU},	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
	{ 183	,1	,1	, &B1AD02LDU},	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
	{ 184	,1	,1	, &B1AD01LDU},	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
	{ 185	,1	,1	, &B1AD21LDU},	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 186	,1	,1	, &B1AD11LDU},	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 187	,1	,1	, &A1AD05LDU},	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
	{ 188	,1	,1	, &A1AD04LDU},	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
	{ 189	,1	,1	, &A1AD03LDU},	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
	{ 190	,1	,1	, &A1AD02LDU},	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
	{ 191	,1	,1	, &A1AD01LDU},	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
	{ 192	,1	,1	, &A1AD21LDU},	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 193	,1	,1	, &A1AD11LDU},	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 194	,8	,1	, &A0SR01RIM},	//( - , SCM) Текущая реактивность AЗ1
	{ 195	,1	,1	, &A3AD03LDU},	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
	{ 196	,1	,1	, &A3AD02LDU},	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
	{ 197	,1	,1	, &A3AD01LDU},	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
	{ 198	,1	,1	, &A3AD21LDU},	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 199	,1	,1	, &A3AD11LDU},	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 200	,1	,1	, &B2AD33LDU},	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
	{ 201	,1	,1	, &B2AD05LDU},	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
	{ 202	,1	,1	, &B2AD04LDU},	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
	{ 203	,1	,1	, &B2AD03LDU},	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
	{ 204	,1	,1	, &B2AD02LDU},	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
	{ 205	,1	,1	, &B2AD01LDU},	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
	{ 206	,1	,1	, &B2AD21LDU},	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 207	,1	,1	, &B2AD11LDU},	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 208	,1	,1	, &A2AD33LDU},	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
	{ 209	,1	,1	, &A2AD05LDU},	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
	{ 210	,1	,1	, &A2AD04LDU},	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
	{ 211	,1	,1	, &A2AD03LDU},	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
	{ 212	,1	,1	, &A2AD02LDU},	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
	{ 213	,5	,1	, &A3IC01UDU},	//( - , SDu) Координата штока ИС1
	{ 214	,1	,1	, &A3IS31LDU},	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
	{ 215	,1	,1	, &A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	{ 216	,3	,1	, &A2IP01IZ2},	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
	{ 217	,3	,1	, &A2IP01IZ1},	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
	{ 218	,1	,1	, &B3IS21LDU},	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
	{ 219	,1	,1	, &A3IS21LDU},	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
	{ 220	,1	,1	, &A2IS33LDU},	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
	{ 221	,5	,1	, &A2IC01UDU},	//( - , SDu) Координата штока РБ1
	{ 222	,1	,1	, &A2IS12LDU},	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
	{ 223	,1	,1	, &A2IS11LDU},	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
	{ 224	,1	,1	, &A2IS21LDU},	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
	{ 225	,3	,1	, &B0IT02IZ2},	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
	{ 226	,3	,1	, &B0IT01IZ1},	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
	{ 227	,3	,1	, &A0IT02IZ2},	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
	{ 228	,3	,1	, &A0IT01IZ1},	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
	{ 229	,1	,1	, &R6IS21LDU},	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
	{ 230	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 231	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 232	,1	,1	, &R6IS65LDU},	//( - , - ) Исправность ВИП ССДИ-35 2канал
	{ 233	,1	,1	, &R6IS64LDU},	//( - , - ) Исправность ВИП ССДИ-35 1канал
	{ 234	,1	,1	, &R6IS63LDU},	//( - , - ) Исправность ВИП ССДИ-39 2канал
	{ 235	,1	,1	, &R6IS62LDU},	//( - , - ) Исправность ВИП ССДИ-39 1канал
	{ 236	,1	,1	, &B3IS22LDU},	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
	{ 237	,1	,1	, &A3IS22LDU},	//(do32_pti:110 - K02DO, - ) Приход на НУП ИС1
	{ 238	,1	,1	, &B3IS11LDU},	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
	{ 239	,1	,1	, &A3IS11LDU},	//(do32_pti:110 - K04DO, - ) Приход на ВУ ИС1
	{ 240	,3	,1	, &A3IP02IDU},	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 241	,1	,1	, &B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	{ 242	,1	,1	, &A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	{ 243	,1	,1	, &B3IS33LDU},	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 244	,5	,1	, &B3IC01UDU},	//( - , SDu) Координата штока ИС2
	{ 245	,1	,1	, &B3IS31LDU},	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
	{ 246	,3	,1	, &B3IP02IDU},	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
	{ 247	,1	,1	, &A3IS33LDU},	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
	{ 248	,1	,1	, &R0MW13LP2},	//( - , SCM) Переключатель «СЕТЬ»
	{ 249	,1	,1	, &B3AD31LDU},	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
	{ 250	,1	,1	, &B2AD32LDU},	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
	{ 251	,1	,1	, &B2AD31LDU},	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
	{ 252	,1	,1	, &B1AD32LDU},	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
	{ 253	,1	,1	, &B1AD31LDU},	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
	{ 254	,1	,1	, &A3AD31LDU},	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
	{ 255	,1	,1	, &C1MD31LP1},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{ 256	,1	,1	, &C1MD31LP2},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{ 257	,1	,1	, &A1AD31LDU},	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
	{ 258	,1	,1	, &A1AD32LDU},	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
	{ 259	,1	,1	, &A2AD31LDU},	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
	{ 260	,1	,1	, &C2MD31LP1},	//( - , SCM) Кнопка «СБРОС РБ»
	{ 261	,1	,1	, &A2AD32LDU},	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
	{ 262	,1	,1	, &R0VZ71LZ2},	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
	{ 263	,1	,1	, &R0VZ71LZ1},	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
	{ 264	,1	,1	, &R8AD21LDU},	//(vds32_pti:310 - K31VDSR, - ) Имитация прихода на ВУ ИС для КВДС
	{ 265	,1	,1	, &R0AD14LDU},	//( - , SCM) Имитация срабатывания верхней АС II УР
	{ 266	,1	,1	, &B7AS31LDU},	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
	{ 267	,1	,1	, &A7AS31LDU},	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
	{ 268	,1	,1	, &B3IS35LDU},	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
	{ 269	,1	,1	, &B3AD34LDU},	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
	{ 270	,1	,1	, &A3IS35LDU},	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
	{ 271	,1	,1	, &R7II73LZ2},	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
	{ 272	,1	,1	, &R7II71LZ2},	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
	{ 273	,1	,1	, &R7II72LZ2},	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
	{ 274	,1	,1	, &R0AD16LDU},	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
	{ 275	,1	,1	, &R7II72LZ1},	//(do32_pti:110 - K07DO, - ) Сработала АС IУР (датчик 2)
	{ 276	,1	,1	, &R7II71LZ1},	//(do32_pti:110 - K08DO, - ) Сработала АС IУР (датчик 1)
	{ 277	,1	,1	, &R7II73LZ1},	//(do32_pti:110 - K09DO, - ) Сработала АС IIУР
	{ 278	,8	,1	, &R0SR01RIM},	//( - , SCM) Текущая реактивность PУ
	{ 279	,8	,1	, &R0ST01RIM},	//( - , SCM) Текущий период разгона РУ
	{ 280	,1	,1	, &A4AD10LDU},	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
	{ 281	,1	,1	, &B4AD10LDU},	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
	{ 282	,1	,1	, &A9AD10LDU},	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
	{ 283	,1	,1	, &B9AD10LDU},	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
	{ 284	,8	,1	, &fEM_R0UL01RIM},	//(R0UL01RIM) Среднее время генерации нейтронов
	{ 285	,8	,1	, &fEM_R0UN02RIM},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{ 286	,8	,1	, &fEM_A1UR01RIM},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{ 287	,8	,1	, &fEM_A1UR00RIM},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{ 288	,8	,1	, &fEM_A3UR00RIM},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{ 289	,8	,1	, &fEM_A3UR01RIM},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{ 290	,8	,1	, &fEM_R0UT01RIM},	//(R0UT01RIM) Температурный коэффициент (долл)
	{ 291	,8	,1	, &fEM_R0UT02RIM},	//(R0UT02RIM) Масса топлива в АЗ
	{ 292	,8	,1	, &fEM_R0UT04RIM},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{ 293	,8	,1	, &fEM_R0UT03RIM},	//(R0UT03RIM) Нормальная температура АЗ град
	{ 294	,8	,1	, &fEM_R0UT05RIM},	//(R0UT05RIM) Энергия деления ядра
	{ 295	,8	,1	, &fEM_R0UT06RIM},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{ 296	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{ 297	,8	,1	, &fEM_A1UC04RIM},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{ 298	,8	,1	, &fEM_A1UC05RIM},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{ 299	,8	,1	, &fEM_A1UC06RIM},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{ 300	,8	,1	, &fEM_A2UC06RIM},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{ 301	,8	,1	, &fEM_A2UC05RIM},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{ 302	,8	,1	, &fEM_A2UC04RIM},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{ 303	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{ 304	,8	,1	, &fEM_A3UC06RIM},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{ 305	,8	,1	, &fEM_A3UC05RIM},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{ 306	,8	,1	, &fEM_A3UC04RIM},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{ 307	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{ 308	,8	,1	, &fEM_R4UV80RDU},	//(R4UV80RDU) Номинальная скорость тележки (см/с)
	{ 309	,8	,1	, &fEM_R4UC10RIM},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{ 310	,8	,1	, &fEM_R4UC20RIM},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{ 311	,8	,1	, &fEM_B8UC21RIM},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{ 312	,8	,1	, &fEM_B8UC20RIM},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{ 313	,8	,1	, &fEM_B8UC11RIM},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{ 314	,8	,1	, &fEM_B8UC10RIM},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{ 315	,8	,1	, &fEM_B8UV80RDU},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{ 316	,8	,1	, &fEM_A8UV80RDU},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{ 317	,8	,1	, &fEM_A8UC10RIM},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{ 318	,8	,1	, &fEM_A8UC11RIM},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{ 319	,8	,1	, &fEM_A8UC20RIM},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{ 320	,8	,1	, &fEM_A8UC21RIM},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{ 321	,8	,1	, &fEM_A6UC10RIM},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{ 322	,8	,1	, &fEM_R1UC10RIM},	//(R1UC10RIM) Время полного хода МДЗ сек
	{ 323	,8	,1	, &fEM_A5UC10RIM},	//(A5UC10RIM) Время полного хода НЛ сек
	{ 324	,8	,1	, &fEM_A0UN01RIM},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{ 325	,8	,1	, &fEM_R4UC22RIM},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{ 326	,8	,1	, &fEM_A1UG01RDU},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{ 327	,8	,1	, &fEM_A2UG01RDU},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{ 328	,8	,1	, &fEM_A3UG01RDU},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{ 329	,8	,1	, &fEM_R7UC10RIM},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{ 330	,8	,1	, &fEM_R7UC19RIM},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{ 331	,8	,1	, &fEM_R7UI02RIM},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{ 332	,8	,1	, &fEM_R7UL01RIM},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{ 333	,8	,1	, &fEM_A2UR00RIM},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{ 334	,8	,1	, &fEM_A2UR01RIM},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{ 335	,8	,1	, &fEM_A0UN02RIM},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{ 336	,8	,1	, &fEM_R0UR30RIM},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{ 337	,8	,1	, &fEM_R0UR01RIM},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{ 338	,8	,1	, &fEM_R0UT02RDU},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{ 339	,8	,1	, &fEM_R0UT01RDU},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{ 340	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{ 341	,8	,1	, &fEM_A2UP03RDU},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{ 342	,8	,1	, &fEM_A2UP04RDU},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{ 343	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{ 344	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 345	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 346	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{ 347	,8	,1	, &fEM_R7UI74RIM},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{ 348	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{ 349	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 350	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 351	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 352	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 353	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 354	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 355	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 356	,8	,1	, &fEM_A8UC08RDU},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{ 357	,8	,1	, &fEM_B8UC08RDU},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{ 358	,8	,1	, &fEM_R4UC08RDU},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{ 359	,8	,1	, &fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
	{ 360	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 361	,8	,1	, &fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{ 362	,8	,1	, &fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{ 363	,8	,1	, &fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{ 364	,8	,1	, &fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{ 365	,8	,1	, &fEM_R7UX06RSS},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{ 366	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 367	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 368	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 369	,8	,1	, &fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{ 370	,8	,1	, &fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{ 371	,8	,1	, &fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{ 372	,8	,1	, &fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{ 373	,8	,1	, &fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{ 374	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 375	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 376	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 377	,8	,1	, &fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{ 378	,8	,1	, &fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{ 379	,8	,1	, &fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{ 380	,8	,1	, &fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{ 381	,8	,1	, &fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{ 382	,8	,1	, &fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{ 383	,8	,1	, &fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{ 384	,8	,1	, &fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{ 385	,8	,1	, &fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{ 386	,8	,1	, &fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{ 387	,8	,1	, &fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{ 388	,8	,1	, &fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{ 389	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 390	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 391	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 392	,8	,1	, &fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{ 393	,8	,1	, &fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{ 394	,8	,1	, &fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{ 395	,8	,1	, &fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{ 396	,8	,1	, &fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{ 397	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 398	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{ 399	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 400	,8	,1	, &fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{ 401	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 402	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 403	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 404	,8	,1	, &fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{ 405	,8	,1	, &fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{ 406	,8	,1	, &fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{ 407	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{ 408	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{ 409	,8	,1	, &fEM_R4US80RDU},	//(R4US80RDU) Тормозной путь тележки (мм)
	{ 410	,8	,1	, &fEM_R7UI71RIM},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{ 411	,8	,1	, &fEM_R7UI72RIM},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{ 412	,8	,1	, &fEM_R7UI73RIM},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{ 413	,8	,1	, &fEM_A1UP01RIM},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{ 414	,8	,1	, &fEM_A2UP01RIM},	//(A2UP01RIM) Текущее давление на сброс РБ
	{ 415	,8	,1	, &fEM_A0UP02RIM},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{ 416	,8	,1	, &fEM_A3UP01RIM},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{ 417	,8	,1	, &fEM_A1UP82RIM},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{ 418	,8	,1	, &fEM_A3UP02RDU},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{ 419	,8	,1	, &fEM_A1UV02RIM},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{ 420	,8	,1	, &fEM_A3UV02RIM},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{ 421	,8	,1	, &fEM_A2UV02RIM},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{ 422	,8	,1	, &fEM_B8US80RDU},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{ 423	,8	,1	, &fEM_A8US80RDU},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{ 424	,8	,1	, &fEM_A6US80RDU},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{ 425	,8	,1	, &fEM_A1US07RDU},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{ 426	,8	,1	, &fEM_A2US07RDU},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{ 427	,8	,1	, &fEM_A3US07RDU},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{ 428	,8	,1	, &fEM_R7UI75RIM},	//(R7UI75RIM) Множитель к уровню радиации
	{ 429	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 430	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 431	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 432	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 433	,8	,1	, &fEM_A4UL10RIM},	//(A4UL10RIM) Время полного перемещения НИ сек
	{ 434	,8	,1	, &fEM_A9UL10RIM},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{ 435	,8	,1	, &fEM_R3UL10RIM},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{ 436	,8	,1	, &fEM_R5UL10RIM},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{ 437	,8	,1	, &fEM_R6UL10RIM},	//(R6UL10RIM) Время полного хода кран-балки сек
	{ 438	,1	,1	, &lEM_C1AD31LRP},	//(C1AD31LRP) Общий сброс от РПУ
	{ 439	,1	,1	, &lEM_R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов
	{ 440	,1	,1	, &lEM_R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{ 441	,8	,1	, &fEM_A2UP02RIM},	//(A2UP02RIM) Текущее давление на подъём РБ
	{ 442	,8	,1	, &fEM_A2UP03RIM},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{ 443	,8	,1	, &fEM_A0UP01RIM},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{ 444	,8	,1	, &fEM_A3UP02RIM},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{ 445	,8	,1	, &fEM_A4UP01RIM},	//(A4UP01RIM) Текущее давление на подъём НИ
	{ 446	,8	,1	, &fEM_A4UP02RIM},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{ 447	,8	,1	, &fEM_R7UI76RIM},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{ 448	,8	,1	, &fEM_R7UI77RIM},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{ 449	,3	,1	, &iEM_TERBB1},	//(TERBB1) Неисправности  ББ1
	{ 450	,8	,1	, &fEM_A1MC02RC1},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{ 451	,8	,1	, &fEM_A1MV02RC1},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{ 452	,3	,1	, &iEM_TERBB2},	//(TERBB2) Неисправности  ББ2
	{ 453	,8	,1	, &fEM_B1MC02RC1},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{ 454	,8	,1	, &fEM_B1MV02RC1},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{ 455	,3	,1	, &iEM_TERRB2},	//(TERRB2) Неисправности  РБ2
	{ 456	,8	,1	, &fEM_B2MC02RC1},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{ 457	,8	,1	, &fEM_B2MV02RC1},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{ 458	,3	,1	, &iEM_TERRB1},	//(TERRB1) Неисправности  РБ1
	{ 459	,8	,1	, &fEM_A2MC02RC1},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{ 460	,8	,1	, &fEM_A2MV02RC1},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{ 461	,3	,1	, &iEM_TERIS2},	//(TERIS2) Неисправности  ИС2
	{ 462	,8	,1	, &fEM_B3MC02RC1},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{ 463	,8	,1	, &fEM_B3MV02RC1},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{ 464	,3	,1	, &iEM_TERIS1},	//(TERIS1) Неисправности  ИС1
	{ 465	,8	,1	, &fEM_A3MC02RC1},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{ 466	,8	,1	, &fEM_A3MV02RC1},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{ 467	,3	,1	, &iEM_TERA1IE04LDU},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{ 468	,3	,1	, &iEM_TERA1IE03LDU},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{ 469	,8	,1	, &fEM_A1MC01RC1},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{ 470	,3	,1	, &iEM_TERB1IE03LDU},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{ 471	,3	,1	, &iEM_TERB1IE04LDU},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{ 472	,8	,1	, &fEM_B1MC01RC1},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{ 473	,8	,1	, &fEM_B1MV01RC1},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{ 474	,8	,1	, &fEM_B2MC01RC1},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{ 475	,8	,1	, &fEM_B2MV01RC1},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{ 476	,8	,1	, &fEM_A3MC01RC1},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{ 477	,8	,1	, &fEM_A3MV01RC1},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{ 478	,8	,1	, &fEM_B3MC01RC1},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{ 479	,8	,1	, &fEM_B3MV01RC1},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{ 480	,3	,1	, &iEM_TERA2SS21LIM},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{ 481	,3	,1	, &iEM_TERA2SS12LIM},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{ 482	,3	,1	, &iEM_TERR6SS21LIM},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{ 483	,3	,1	, &iEM_TERA2VP82LIM},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{ 484	,3	,1	, &iEM_TERA2SS11LIM},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{ 485	,3	,1	, &iEM_TERB3SS21LIM},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{ 486	,3	,1	, &iEM_TERA0MT01RIM},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{ 487	,3	,1	, &iEM_TERB0MT01RIM},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{ 488	,3	,1	, &iEM_TERA2SP01RIM},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{ 489	,3	,1	, &iEM_TERB2SP01RIM},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{ 490	,3	,1	, &iEM_TERB3SP02RIM},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{ 491	,3	,1	, &iEM_TERA3SC01RIM},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{ 492	,3	,1	, &iEM_TERA3VP81LIM},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{ 493	,3	,1	, &iEM_TERA2SC01RIM},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{ 494	,3	,1	, &iEM_TERA2SS33LIM},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{ 495	,3	,1	, &iEM_TERA3SS21LIM},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{ 496	,3	,1	, &iEM_TERA3SS33LIM},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{ 497	,3	,1	, &iEM_TERA3SS31LIM},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{ 498	,3	,1	, &iEM_TERB3SS31LIM},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{ 499	,3	,1	, &iEM_TERB3SS33LIM},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 500	,3	,1	, &iEM_TERB3SC01RIM},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{ 501	,3	,1	, &iEM_TERA3SS11LIM},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{ 502	,3	,1	, &iEM_TERB3SS11LIM},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{ 503	,3	,1	, &iEM_TERR6IS64LIM},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{ 504	,3	,1	, &iEM_TERB3SS22LIM},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{ 505	,3	,1	, &iEM_TERA3SS22LIM},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{ 506	,3	,1	, &iEM_TERA3SP02RIM},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{ 507	,3	,1	, &iEM_TERR6IS62LIM},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{ 508	,3	,1	, &iEM_TERR6IS66LIM},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 509	,3	,1	, &iEM_TERR6IS67LIM},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 510	,3	,1	, &iEM_TERA0VP81LIM},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{ 511	,3	,1	, &iEM_TERB0VP81LIM},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{ 512	,3	,1	, &iEM_TERR0VP81LIM},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{ 513	,3	,1	, &iEM_TERR6IS68LIM},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{ 514	,3	,1	, &iEM_TERR7SI74RIM},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{ 515	,3	,1	, &iEM_TERA5SS21LIM},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{ 516	,3	,1	, &iEM_TERB5SS11LIM},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{ 517	,3	,1	, &iEM_TERA5SS11LIM},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{ 518	,3	,1	, &iEM_TERA9SS11LIM},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{ 519	,3	,1	, &iEM_TERB2SS11LIM},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{ 520	,3	,1	, &iEM_TERB2SS12LIM},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{ 521	,3	,1	, &iEM_TERB2SS21LIM},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{ 522	,3	,1	, &iEM_TERR3SS11LIM},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{ 523	,3	,1	, &iEM_TERB2SC01RIM},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{ 524	,3	,1	, &iEM_TERR3SS21LIM},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{ 525	,3	,1	, &iEM_TERR5SS11LIM},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{ 526	,3	,1	, &iEM_TERA4SS11LIM},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{ 527	,3	,1	, &iEM_TERR1SS11LIM},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{ 528	,3	,1	, &iEM_TERR1SS21LIM},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{ 529	,3	,1	, &iEM_TERR2SS11LIM},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{ 530	,3	,1	, &iEM_TERR2SS21LIM},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{ 531	,3	,1	, &iEM_TERA4VP82LIM},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{ 532	,3	,1	, &iEM_TERB4SS21LIM},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{ 533	,3	,1	, &iEM_TERR5SS21LIM},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{ 534	,3	,1	, &iEM_TERB6SS21LIM},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{ 535	,3	,1	, &iEM_TERB4SS11LIM},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{ 536	,3	,1	, &iEM_TERA4SS21LIM},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{ 537	,3	,1	, &iEM_TERA6MS11LIM},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{ 538	,3	,1	, &iEM_TERA6SS21LIM},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{ 539	,3	,1	, &iEM_TERB6SS11LIM},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{ 540	,3	,1	, &iEM_TERR4SS11LIM},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{ 541	,3	,1	, &iEM_TERR4MS21LIM},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{ 542	,3	,1	, &iEM_TERR4SS12LIM},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{ 543	,3	,1	, &iEM_TERR4SS22LIM},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{ 544	,3	,1	, &iEM_TERR8SS11LIM},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{ 545	,3	,1	, &iEM_TERB8SC01RIM},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{ 546	,3	,1	, &iEM_TERA8SC01RIM},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{ 547	,3	,1	, &iEM_TERB8SS12LIM},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{ 548	,3	,1	, &iEM_TERA8SS12LIM},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{ 549	,3	,1	, &iEM_TERB8SS22LIM},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{ 550	,3	,1	, &iEM_TERA8SS22LIM},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{ 551	,3	,1	, &iEM_TERA9SS21LIM},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{ 552	,3	,1	, &iEM_TERB9SS21LIM},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{ 553	,3	,1	, &iEM_TERB9SS11LIM},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{ 554	,3	,1	, &iEM_TERB5SS21LIM},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{ 555	,3	,1	, &iEM_TERA1SS21LIM},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{ 556	,3	,1	, &iEM_TERA1SS11LIM},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{ 557	,3	,1	, &iEM_TERA1SC01RIM},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{ 558	,3	,1	, &iEM_TERA1SS12LIM},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{ 559	,3	,1	, &iEM_TERB1SS21LIM},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{ 560	,3	,1	, &iEM_TERB1SS11LIM},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{ 561	,3	,1	, &iEM_TERB1MC01RIM},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{ 562	,3	,1	, &iEM_TERB1SS12LIM},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{ 563	,3	,1	, &iEM_TERTLG},	//(TERTLG) Неисправности  тележки от ИС
	{ 564	,8	,1	, &fEM_R4MC01RC1},	//(R4MC01RC1) Заданная координата тележки от ИС
	{ 565	,8	,1	, &fEM_R4MV01RC1},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{ 566	,3	,1	, &iEM_TERMAZ2},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{ 567	,8	,1	, &fEM_B8MV01RC1},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{ 568	,3	,1	, &iEM_TERDS2},	//(TERDS2) Неисправности ДС2 от ИС
	{ 569	,8	,1	, &fEM_A8MC01RC1},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{ 570	,8	,1	, &fEM_A8MV01RC1},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{ 571	,3	,1	, &iEM_TERBZ1},	//(TERBZ1) Неисправности БЗ1
	{ 572	,8	,1	, &fEM_A6MC01RC1},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{ 573	,8	,1	, &fEM_A6MV01RC1},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{ 574	,3	,1	, &iEM_TERBZ2},	//(TERBZ2) Неисправности БЗ2
	{ 575	,8	,1	, &fEM_B6MC01RC1},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{ 576	,8	,1	, &fEM_B6MV01RC1},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{ 577	,1	,1	, &lEM_R3AD10LC1},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{ 578	,1	,1	, &lEM_R3AD20LC1},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{ 579	,1	,1	, &lEM_R6AD10LC1},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{ 580	,1	,1	, &lEM_R5AD10LC1},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{ 581	,1	,1	, &lEM_R5AD20LC1},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{ 582	,3	,1	, &iEM_TERMDZ2},	//(TERMDZ2) Неисправности МДЗ2
	{ 583	,8	,1	, &fEM_R2MC01RC1},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{ 584	,8	,1	, &fEM_R2MV01RC1},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{ 585	,3	,1	, &iEM_TERMDZ1},	//(TERMDZ1) Неисправности МДЗ1
	{ 586	,8	,1	, &fEM_R1MC01RC1},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{ 587	,8	,1	, &fEM_R1MV01RC1},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{ 588	,3	,1	, &iEM_TERNL1},	//(TERNL1) Неисправности НЛ1
	{ 589	,8	,1	, &fEM_A5MC01RC1},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{ 590	,8	,1	, &fEM_A5MV01RC1},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{ 591	,3	,1	, &iEM_TERNL2},	//(TERNL2) Неисправности НЛ2
	{ 592	,8	,1	, &fEM_B5MC01RC1},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{ 593	,8	,1	, &fEM_B5MV01RC1},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{ 594	,1	,1	, &lEM_R8AD10LC1},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{ 595	,8	,1	, &fEM_A1UC08RIM},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{ 596	,8	,1	, &fEM_A2UC08RIM},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{ 597	,8	,1	, &fEM_A3UC08RIM},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{ 598	,3	,1	, &iEM_TERB2SS33LIM},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{ 599	,3	,1	, &iEM_TERA1VP81LIM},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{ 600	,3	,1	, &iEM_TERB1VP81LIM},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{ 601	,8	,1	, &fEM_A0UT03RSP},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{ 602	,8	,1	, &fEM_A0UR01RSP},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{ 603	,8	,1	, &fEM_A0UR02RSP},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{ 604	,8	,1	, &fEM_B0UT03RSP},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{ 605	,8	,1	, &fEM_A1MC01RSP},	//(A1MC01RSP) Стартовая координата  ББ1
	{ 606	,8	,1	, &fEM_A1MC02RSP},	//(A1MC02RSP) Стартовая координата штока ББ1
	{ 607	,8	,1	, &fEM_B1MC01RSP},	//(B1MC01RSP) Стартовая координата  ББ2
	{ 608	,8	,1	, &fEM_B1MC02RSP},	//(B1MC02RSP) Стартовая координата штока ББ2
	{ 609	,8	,1	, &fEM_A2MC01RC1},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{ 610	,8	,1	, &fEM_A2MV01RC1},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{ 611	,8	,1	, &fEM_A2MC01RSP},	//(A2MC01RSP) Стартовая координата  РБ1
	{ 612	,8	,1	, &fEM_A2MC02RSP},	//(A2MC02RSP) Стартовая координата штока РБ1
	{ 613	,8	,1	, &fEM_B2MC01RSP},	//(B2MC01RSP) Стартовая координата  РБ2
	{ 614	,8	,1	, &fEM_B2MC02RSP},	//(B2MC02RSP) Стартовая координата штока РБ2
	{ 615	,8	,1	, &fEM_A3MC01RSP},	//(A3MC01RSP) Стартовая координата  ИС1
	{ 616	,8	,1	, &fEM_A3MC02RSP},	//(A3MC02RSP) Стартовая координата штока ИС1
	{ 617	,8	,1	, &fEM_B3MC01RSP},	//(B3MC01RSP) Стартовая координата  ИС2
	{ 618	,8	,1	, &fEM_B3MC02RSP},	//(B3MC02RSP) Стартовая координата штока ИС2
	{ 619	,8	,1	, &fEM_B8MC01RSP},	//(B8MC01RSP) Стартовая координата АЗ2
	{ 620	,8	,1	, &fEM_A8MC01RSP},	//(A8MC01RSP) Стартовая координата ДС2
	{ 621	,8	,1	, &fEM_A6MC01RSP},	//(A6MC01RSP) Стартовая координата БЗ1
	{ 622	,8	,1	, &fEM_B6MC01RSP},	//(B6MC01RSP) Стартовая координата БЗ2
	{ 623	,8	,1	, &fEM_R3UC01RSP},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{ 624	,8	,1	, &fEM_R5UC01RSP},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{ 625	,8	,1	, &fEM_R6UC01RSP},	//(R6UC01RSP) Стартовая координата Кран-балки
	{ 626	,8	,1	, &fEM_R2MC01RSP},	//(R2MC01RSP) Стартовая координата МДЗ2
	{ 627	,8	,1	, &fEM_R1MC01RSP},	//(R1MC01RSP) Стартовая координата МДЗ1
	{ 628	,8	,1	, &fEM_A5MC01RSP},	//(A5MC01RSP) Стартовая координата НЛ1
	{ 629	,8	,1	, &fEM_B5MC01RSP},	//(B5MC01RSP) Стартовая координата НЛ2
	{ 630	,8	,1	, &fEM_A9MC01RSP},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{ 631	,8	,1	, &fEM_B9MC01RSP},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{ 632	,8	,1	, &fEM_A4MC01RSP},	//(A4MC01RSP) Стартовая координата НИ1
	{ 633	,8	,1	, &fEM_B4MC01RSP},	//(B4MC01RSP) Стартовая координата НИ2
	{ 634	,8	,1	, &fEM_R4MC01RSP},	//(R4MC01RSP) Стартовая координата тележки
	{ 635	,8	,1	, &fEM_A1MV01RC1},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{ 636	,3	,1	, &iEM_TERB7MS31LIM},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{ 637	,3	,1	, &iEM_TERA7MS31LIM},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{ 638	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 см
	{ 639	,3	,1	, &iEM_TERA6VS12LIM},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{ 640	,3	,1	, &iEM_TERA6VS22LIM},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{ 641	,3	,1	, &iEM_TERB6VS12LIM},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{ 642	,3	,1	, &iEM_TERB6VS22LIM},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{ 643	,3	,1	, &iEM_TERA5VS22LIM},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{ 644	,3	,1	, &iEM_TERA5VS12LIM},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{ 645	,3	,1	, &iEM_TERB5VS12LIM},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{ 646	,3	,1	, &iEM_TERB5VS22LIM},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{ 647	,3	,1	, &iEM_TERR1VS12LIM},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{ 648	,3	,1	, &iEM_TERR1VS22LIM},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{ 649	,3	,1	, &iEM_TERR2VS12LIM},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{ 650	,3	,1	, &iEM_TERR2VS22LIM},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{ 651	,3	,1	, &iEM_TERR4VS12LDU},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 652	,3	,1	, &iEM_TERR4VS22LDU},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 653	,8	,1	, &fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{ 654	,8	,1	, &fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{ 655	,8	,1	, &fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{ 656	,8	,1	, &fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{ 657	,8	,1	, &fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{ 658	,8	,1	, &fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{ 659	,8	,1	, &fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{ 660	,8	,1	, &fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{ 661	,8	,1	, &fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{ 662	,8	,1	, &fEM_R7UX16RSS},	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
	{ 663	,8	,1	, &fEM_B8MC01RC1},	//(B8MC01RC1) Заданная координата АЗ2 от ИС
	{ 664	,8	,1	, &fEM_A0UN07RIM},	//(A0UN07RIM) Доля запаздывающих нейтронов
	{ 665	,8	,1	, &fEM_R0UL02RIM},	//(R0UL02RIM) Время удержания синхроимпульса
	{ 666	,8	,1	, &fEM_R0UL04RDU},	//(R0UL04RDU) Время блокировки повторной генерации импульса
	{ 667	,8	,1	, &fEM_R0UL02RDU},	//(R0UL02RDU) Время задержки  ИНИ
	{ 668	,8	,1	, &fEM_R0UL03RDU},	//(R0UL03RDU) Максимальное время цикла, сек
	{ 669	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 670	,3	,1	, &internal1_m39_reg},	//(internal1_m39_reg) режим работы квдс 0 - ожидание сигнала 1- выдан импульс 2 отсчет удержания синхроимпульса 3 -блокировка
	{ 671	,8	,1	, &internal1_m39_tgen},	//(internal1_m39_tgen) задержки срабатывания генератора импульса
	{ 672	,8	,1	, &internal1_m39_tsin},	//(internal1_m39_tsin) время до конца удержания синхроимпульса
	{ 673	,8	,1	, &internal1_m39_tlock},	//(internal1_m39_tlock) время до конца блокировки
	{ 674	,1	,1	, &internal1_m39_fef},	//(internal1_m39_fef) fef
	{ 675	,8	,1	, &internal1_m880_Chim0},	//(internal1_m880_Chim0) измеренная частота импульсов камеры Гц
	{ 676	,8	,1	, &internal1_m870_Chim0},	//(internal1_m870_Chim0) измеренная частота импульсов камеры Гц
	{ 677	,8	,1	, &internal1_m862_Chim0},	//(internal1_m862_Chim0) измеренная частота импульсов камеры Гц
	{ 678	,1	,1	, &internal1_m817_Out10},	//(internal1_m817_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 679	,1	,1	, &internal1_m816_Out10},	//(internal1_m816_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 680	,1	,1	, &internal1_m999_Out10},	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 681	,1	,1	, &internal1_m998_Out10},	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 682	,1	,1	, &internal1_m997_Out10},	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 683	,1	,1	, &internal1_m996_Out10},	//(internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 684	,1	,1	, &internal1_m675_Out10},	//(internal1_m675_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 685	,1	,1	, &internal1_m674_Out10},	//(internal1_m674_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 686	,1	,1	, &internal1_m653_Out10},	//(internal1_m653_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 687	,1	,1	, &internal1_m652_Out10},	//(internal1_m652_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 688	,1	,1	, &internal1_m673_Out10},	//(internal1_m673_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 689	,1	,1	, &internal1_m672_Out10},	//(internal1_m672_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 690	,1	,1	, &internal1_m651_Out10},	//(internal1_m651_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 691	,1	,1	, &internal1_m650_Out10},	//(internal1_m650_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 692	,1	,1	, &internal1_m517_Out10},	//(internal1_m517_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 693	,1	,1	, &internal1_m533_Out10},	//(internal1_m533_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 694	,1	,1	, &internal1_m405_Out10},	//(internal1_m405_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 695	,1	,1	, &internal1_m478_q0},	//(internal1_m478_q0) q0 - внутренний параметр
	{ 696	,1	,1	, &internal1_m479_q0},	//(internal1_m479_q0) q0 - внутренний параметр
	{ 697	,1	,1	, &internal1_m466_q0},	//(internal1_m466_q0) q0 - внутренний параметр
	{ 698	,1	,1	, &internal1_m467_q0},	//(internal1_m467_q0) q0 - внутренний параметр
	{ 699	,8	,1	, &internal1_m626_tx},	//(internal1_m626_tx) tx - время накопленное сек
	{ 700	,18	,1	, &internal1_m626_y0},	//(internal1_m626_y0) y0
	{ 701	,8	,1	, &internal1_m614_tx},	//(internal1_m614_tx) tx - время накопленное сек
	{ 702	,18	,1	, &internal1_m614_y0},	//(internal1_m614_y0) y0
	{ 703	,8	,1	, &internal1_m602_tx},	//(internal1_m602_tx) tx - время накопленное сек
	{ 704	,18	,1	, &internal1_m602_y0},	//(internal1_m602_y0) y0
	{ 705	,8	,1	, &internal1_m600_tx},	//(internal1_m600_tx) tx - время накопленное сек
	{ 706	,18	,1	, &internal1_m600_y0},	//(internal1_m600_y0) y0
	{ 707	,1	,1	, &internal1_m210_Out10},	//(internal1_m210_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 708	,1	,1	, &internal1_m228_Out10},	//(internal1_m228_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 709	,1	,1	, &internal1_m47_Out10},	//(internal1_m47_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 710	,1	,1	, &internal1_m62_Out10},	//(internal1_m62_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 711	,1	,1	, &internal1_m970_Out10},	//(internal1_m970_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 712	,1	,1	, &internal1_m967_Out10},	//(internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 713	,1	,1	, &internal1_m966_Out10},	//(internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 714	,8	,1	, &internal1_m969_Xtek0},	//(internal1_m969_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 715	,8	,1	, &internal1_m952_Xtek0},	//(internal1_m952_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 716	,1	,1	, &internal1_m953_Out10},	//(internal1_m953_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 717	,1	,1	, &internal1_m950_Out10},	//(internal1_m950_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 718	,1	,1	, &internal1_m949_Out10},	//(internal1_m949_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 719	,1	,1	, &internal1_m1037_Out10},	//(internal1_m1037_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 720	,1	,1	, &internal1_m1018_Out10},	//(internal1_m1018_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 721	,1	,1	, &internal1_m1017_Out10},	//(internal1_m1017_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 722	,1	,1	, &internal1_m1016_Out10},	//(internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 723	,1	,1	, &internal1_m838_Out10},	//(internal1_m838_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 724	,1	,1	, &internal1_m840_Out10},	//(internal1_m840_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 725	,1	,1	, &internal1_m837_Out10},	//(internal1_m837_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 726	,1	,1	, &internal1_m839_Out10},	//(internal1_m839_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 727	,1	,1	, &internal1_m813_Out10},	//(internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 728	,1	,1	, &internal1_m814_Out10},	//(internal1_m814_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 729	,1	,1	, &internal1_m812_Out10},	//(internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 730	,1	,1	, &internal1_m811_Out10},	//(internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 731	,1	,1	, &internal1_m1032_Out10},	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 732	,1	,1	, &internal1_m984_Out10},	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 733	,1	,1	, &internal1_m983_Out10},	//(internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 734	,1	,1	, &internal1_m982_Out10},	//(internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 735	,1	,1	, &internal1_m981_Out10},	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 736	,1	,1	, &internal1_m1033_Out10},	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 737	,1	,1	, &internal1_m1014_Out10},	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 738	,1	,1	, &internal1_m815_Out10},	//(internal1_m815_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 739	,1	,1	, &internal1_m1015_Out10},	//(internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 740	,1	,1	, &internal1_m1013_Out10},	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 741	,1	,1	, &internal1_m1034_Out10},	//(internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 742	,1	,1	, &internal1_m1012_Out10},	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 743	,1	,1	, &internal1_m995_Out10},	//(internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 744	,1	,1	, &internal1_m980_Out10},	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 745	,1	,1	, &internal1_m534_Out10},	//(internal1_m534_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 746	,8	,1	, &internal1_m415_Xtek0},	//(internal1_m415_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 747	,1	,1	, &internal1_m406_Out10},	//(internal1_m406_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 748	,1	,1	, &internal1_m408_Out10},	//(internal1_m408_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 749	,1	,1	, &internal1_m407_Out10},	//(internal1_m407_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 750	,1	,1	, &internal1_m853_Out10},	//(internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 751	,1	,1	, &internal1_m854_Out10},	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 752	,1	,1	, &internal1_m852_Out10},	//(internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 753	,1	,1	, &internal1_m1036_Out10},	//(internal1_m1036_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 754	,1	,1	, &internal1_m688_Out10},	//(internal1_m688_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 755	,1	,1	, &internal1_m689_Out10},	//(internal1_m689_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 756	,1	,1	, &internal1_m686_Out10},	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 757	,1	,1	, &internal1_m687_Out10},	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 758	,1	,1	, &internal1_m550_Out10},	//(internal1_m550_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 759	,1	,1	, &internal1_m549_Out10},	//(internal1_m549_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 760	,8	,1	, &internal1_m834_Xtek0},	//(internal1_m834_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 761	,8	,1	, &internal1_m836_Xtek0},	//(internal1_m836_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 762	,1	,1	, &internal1_m685_Out10},	//(internal1_m685_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 763	,1	,1	, &internal1_m669_Out10},	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 764	,1	,1	, &internal1_m649_Out10},	//(internal1_m649_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 765	,1	,1	, &internal1_m668_Out10},	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 766	,1	,1	, &internal1_m648_Out10},	//(internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 767	,1	,1	, &internal1_m336_Out10},	//(internal1_m336_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 768	,1	,1	, &internal1_m335_Out10},	//(internal1_m335_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 769	,1	,1	, &internal1_m320_Out10},	//(internal1_m320_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 770	,1	,1	, &internal1_m319_Out10},	//(internal1_m319_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 771	,1	,1	, &internal1_m551_Out10},	//(internal1_m551_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 772	,1	,1	, &internal1_m349_Out10},	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 773	,8	,1	, &internal1_m333_Xtek0},	//(internal1_m333_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 774	,1	,1	, &internal1_m348_Out10},	//(internal1_m348_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 775	,1	,1	, &internal1_m346_Out10},	//(internal1_m346_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 776	,8	,1	, &internal1_m326_Xtek0},	//(internal1_m326_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 777	,1	,1	, &internal1_m347_Out10},	//(internal1_m347_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 778	,1	,1	, &internal1_m318_Out10},	//(internal1_m318_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 779	,1	,1	, &internal1_m334_Out10},	//(internal1_m334_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 780	,1	,1	, &internal1_m427_Out10},	//(internal1_m427_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 781	,8	,1	, &internal1_m428_Xtek0},	//(internal1_m428_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 782	,1	,1	, &internal1_m426_Out10},	//(internal1_m426_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 783	,1	,1	, &internal1_m425_Out10},	//(internal1_m425_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 784	,1	,1	, &internal1_m424_Out10},	//(internal1_m424_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 785	,1	,1	, &internal1_m1035_Out10},	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 786	,1	,1	, &internal1_m152_Out10},	//(internal1_m152_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 787	,1	,1	, &internal1_m151_Out10},	//(internal1_m151_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 788	,8	,1	, &internal1_m470_X00},	//(internal1_m470_X00)  X00 - текущая координата механизма
	{ 789	,8	,1	, &internal1_m470_V00},	//(internal1_m470_V00)  V00 - текущая скорость механизма
	{ 790	,1	,1	, &internal1_m470_Pav0},	//(internal1_m470_Pav0)  - Пер.аварийный выключатель механизма
	{ 791	,1	,1	, &internal1_m470_Zav0},	//(internal1_m470_Zav0)  - Зад.аварийный выключатель механизма
	{ 792	,1	,1	, &internal1_m470_Pv0},	//(internal1_m470_Pv0)  - Пер. выключатель механизма
	{ 793	,1	,1	, &internal1_m470_Zv0},	//(internal1_m470_Zv0)  - Зад. выключатель механизма
	{ 794	,1	,1	, &internal1_m470_RA00},	//(internal1_m470_RA00)  - последнее задание вперед
	{ 795	,1	,1	, &internal1_m470_RA10},	//(internal1_m470_RA10)  - последнее задание назад
	{ 796	,1	,1	, &internal1_m470_MyFirstEnterFlag},	//(internal1_m470_MyFirstEnterFlag) MyFirstEnterFlag
	{ 797	,8	,1	, &internal1_m482_X00},	//(internal1_m482_X00)  X00 - текущая координата механизма
	{ 798	,8	,1	, &internal1_m482_V00},	//(internal1_m482_V00)  V00 - текущая скорость механизма
	{ 799	,1	,1	, &internal1_m482_Pav0},	//(internal1_m482_Pav0)  - Пер.аварийный выключатель механизма
	{ 800	,1	,1	, &internal1_m482_Zav0},	//(internal1_m482_Zav0)  - Зад.аварийный выключатель механизма
	{ 801	,1	,1	, &internal1_m482_Pv0},	//(internal1_m482_Pv0)  - Пер. выключатель механизма
	{ 802	,1	,1	, &internal1_m482_Zv0},	//(internal1_m482_Zv0)  - Зад. выключатель механизма
	{ 803	,1	,1	, &internal1_m482_RA00},	//(internal1_m482_RA00)  - последнее задание вперед
	{ 804	,1	,1	, &internal1_m482_RA10},	//(internal1_m482_RA10)  - последнее задание назад
	{ 805	,1	,1	, &internal1_m482_MyFirstEnterFlag},	//(internal1_m482_MyFirstEnterFlag) MyFirstEnterFlag
	{ 806	,8	,1	, &internal1_m472_X00},	//(internal1_m472_X00)  X00 - текущая координата механизма
	{ 807	,8	,1	, &internal1_m472_V00},	//(internal1_m472_V00)  V00 - текущая скорость механизма
	{ 808	,1	,1	, &internal1_m472_Pav0},	//(internal1_m472_Pav0)  - Пер.аварийный выключатель механизма
	{ 809	,1	,1	, &internal1_m472_Zav0},	//(internal1_m472_Zav0)  - Зад.аварийный выключатель механизма
	{ 810	,1	,1	, &internal1_m472_Pv0},	//(internal1_m472_Pv0)  - Пер. выключатель механизма
	{ 811	,1	,1	, &internal1_m472_Zv0},	//(internal1_m472_Zv0)  - Зад. выключатель механизма
	{ 812	,1	,1	, &internal1_m472_RA00},	//(internal1_m472_RA00)  - последнее задание вперед
	{ 813	,1	,1	, &internal1_m472_RA10},	//(internal1_m472_RA10)  - последнее задание назад
	{ 814	,1	,1	, &internal1_m472_MyFirstEnterFlag},	//(internal1_m472_MyFirstEnterFlag) MyFirstEnterFlag
	{ 815	,8	,1	, &internal1_m605_X00},	//(internal1_m605_X00)  X00 - текущая координата механизма
	{ 816	,8	,1	, &internal1_m605_V00},	//(internal1_m605_V00)  V00 - текущая скорость механизма
	{ 817	,1	,1	, &internal1_m605_Pav0},	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
	{ 818	,1	,1	, &internal1_m605_Zav0},	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
	{ 819	,1	,1	, &internal1_m605_Pv0},	//(internal1_m605_Pv0)  - Пер. выключатель механизма
	{ 820	,1	,1	, &internal1_m605_Zv0},	//(internal1_m605_Zv0)  - Зад. выключатель механизма
	{ 821	,1	,1	, &internal1_m605_RA00},	//(internal1_m605_RA00)  - последнее задание вперед
	{ 822	,1	,1	, &internal1_m605_RA10},	//(internal1_m605_RA10)  - последнее задание назад
	{ 823	,1	,1	, &internal1_m605_MyFirstEnterFlag},	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
	{ 824	,8	,1	, &internal1_m604_X00},	//(internal1_m604_X00)  X00 - текущая координата механизма
	{ 825	,8	,1	, &internal1_m604_V00},	//(internal1_m604_V00)  V00 - текущая скорость механизма
	{ 826	,1	,1	, &internal1_m604_Pav0},	//(internal1_m604_Pav0)  - Пер.аварийный выключатель механизма
	{ 827	,1	,1	, &internal1_m604_Zav0},	//(internal1_m604_Zav0)  - Зад.аварийный выключатель механизма
	{ 828	,1	,1	, &internal1_m604_Pv0},	//(internal1_m604_Pv0)  - Пер. выключатель механизма
	{ 829	,1	,1	, &internal1_m604_Zv0},	//(internal1_m604_Zv0)  - Зад. выключатель механизма
	{ 830	,1	,1	, &internal1_m604_RA00},	//(internal1_m604_RA00)  - последнее задание вперед
	{ 831	,1	,1	, &internal1_m604_RA10},	//(internal1_m604_RA10)  - последнее задание назад
	{ 832	,1	,1	, &internal1_m604_MyFirstEnterFlag},	//(internal1_m604_MyFirstEnterFlag) MyFirstEnterFlag
	{ 833	,8	,1	, &internal1_m592_X00},	//(internal1_m592_X00)  X00 - текущая координата механизма
	{ 834	,8	,1	, &internal1_m592_V00},	//(internal1_m592_V00)  V00 - текущая скорость механизма
	{ 835	,1	,1	, &internal1_m592_Pav0},	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
	{ 836	,1	,1	, &internal1_m592_Zav0},	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
	{ 837	,1	,1	, &internal1_m592_Pv0},	//(internal1_m592_Pv0)  - Пер. выключатель механизма
	{ 838	,1	,1	, &internal1_m592_Zv0},	//(internal1_m592_Zv0)  - Зад. выключатель механизма
	{ 839	,1	,1	, &internal1_m592_RA00},	//(internal1_m592_RA00)  - последнее задание вперед
	{ 840	,1	,1	, &internal1_m592_RA10},	//(internal1_m592_RA10)  - последнее задание назад
	{ 841	,1	,1	, &internal1_m592_MyFirstEnterFlag},	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
	{ 842	,8	,1	, &internal1_m591_X00},	//(internal1_m591_X00)  X00 - текущая координата механизма
	{ 843	,8	,1	, &internal1_m591_V00},	//(internal1_m591_V00)  V00 - текущая скорость механизма
	{ 844	,1	,1	, &internal1_m591_Pav0},	//(internal1_m591_Pav0)  - Пер.аварийный выключатель механизма
	{ 845	,1	,1	, &internal1_m591_Zav0},	//(internal1_m591_Zav0)  - Зад.аварийный выключатель механизма
	{ 846	,1	,1	, &internal1_m591_Pv0},	//(internal1_m591_Pv0)  - Пер. выключатель механизма
	{ 847	,1	,1	, &internal1_m591_Zv0},	//(internal1_m591_Zv0)  - Зад. выключатель механизма
	{ 848	,1	,1	, &internal1_m591_RA00},	//(internal1_m591_RA00)  - последнее задание вперед
	{ 849	,1	,1	, &internal1_m591_RA10},	//(internal1_m591_RA10)  - последнее задание назад
	{ 850	,1	,1	, &internal1_m591_MyFirstEnterFlag},	//(internal1_m591_MyFirstEnterFlag) MyFirstEnterFlag
	{ 851	,8	,1	, &internal1_m634_y0},	//(internal1_m634_y0) y0 - внутренний параметр
	{ 852	,8	,1	, &internal1_m799_Chim0},	//(internal1_m799_Chim0) измеренная частота импульсов камеры Гц
	{ 853	,8	,1	, &internal1_m790_Chim0},	//(internal1_m790_Chim0) измеренная частота импульсов камеры Гц
	{ 854	,8	,1	, &internal1_m782_Chim0},	//(internal1_m782_Chim0) измеренная частота импульсов камеры Гц
	{ 855	,8	,1	, &internal1_m773_Chim0},	//(internal1_m773_Chim0) измеренная частота импульсов камеры Гц
	{ 856	,8	,1	, &internal1_m764_Chim0},	//(internal1_m764_Chim0) измеренная частота импульсов камеры Гц
	{ 857	,8	,1	, &internal1_m756_Chim0},	//(internal1_m756_Chim0) измеренная частота импульсов камеры Гц
	{ 858	,8	,1	, &internal1_m747_Chim0},	//(internal1_m747_Chim0) измеренная частота импульсов камеры Гц
	{ 859	,8	,1	, &internal1_m738_Chim0},	//(internal1_m738_Chim0) измеренная частота импульсов камеры Гц
	{ 860	,8	,1	, &internal1_m730_Chim0},	//(internal1_m730_Chim0) измеренная частота импульсов камеры Гц
	{ 861	,8	,1	, &internal1_m721_Chim0},	//(internal1_m721_Chim0) измеренная частота импульсов камеры Гц
	{ 862	,8	,1	, &internal1_m712_Chim0},	//(internal1_m712_Chim0) измеренная частота импульсов камеры Гц
	{ 863	,8	,1	, &internal1_m702_Chim0},	//(internal1_m702_Chim0) измеренная частота импульсов камеры Гц
	{ 864	,8	,1	, &internal1_m579_X00},	//(internal1_m579_X00)  X00 - текущая координата механизма
	{ 865	,8	,1	, &internal1_m579_V00},	//(internal1_m579_V00)  V00 - текущая скорость механизма
	{ 866	,1	,1	, &internal1_m579_Pav0},	//(internal1_m579_Pav0)  - Пер.аварийный выключатель механизма
	{ 867	,1	,1	, &internal1_m579_Zav0},	//(internal1_m579_Zav0)  - Зад.аварийный выключатель механизма
	{ 868	,1	,1	, &internal1_m579_Pv0},	//(internal1_m579_Pv0)  - Пер. выключатель механизма
	{ 869	,1	,1	, &internal1_m579_Zv0},	//(internal1_m579_Zv0)  - Зад. выключатель механизма
	{ 870	,1	,1	, &internal1_m579_RA00},	//(internal1_m579_RA00)  - последнее задание вперед
	{ 871	,1	,1	, &internal1_m579_RA10},	//(internal1_m579_RA10)  - последнее задание назад
	{ 872	,1	,1	, &internal1_m579_MyFirstEnterFlag},	//(internal1_m579_MyFirstEnterFlag) MyFirstEnterFlag
	{ 873	,8	,1	, &internal1_m565_X00},	//(internal1_m565_X00)  X00 - текущая координата механизма
	{ 874	,8	,1	, &internal1_m565_V00},	//(internal1_m565_V00)  V00 - текущая скорость механизма
	{ 875	,1	,1	, &internal1_m565_Pav0},	//(internal1_m565_Pav0)  - Пер.аварийный выключатель механизма
	{ 876	,1	,1	, &internal1_m565_Zav0},	//(internal1_m565_Zav0)  - Зад.аварийный выключатель механизма
	{ 877	,1	,1	, &internal1_m565_Pv0},	//(internal1_m565_Pv0)  - Пер. выключатель механизма
	{ 878	,1	,1	, &internal1_m565_Zv0},	//(internal1_m565_Zv0)  - Зад. выключатель механизма
	{ 879	,1	,1	, &internal1_m565_RA00},	//(internal1_m565_RA00)  - последнее задание вперед
	{ 880	,1	,1	, &internal1_m565_RA10},	//(internal1_m565_RA10)  - последнее задание назад
	{ 881	,1	,1	, &internal1_m565_MyFirstEnterFlag},	//(internal1_m565_MyFirstEnterFlag) MyFirstEnterFlag
	{ 882	,8	,1	, &internal1_m456_X00},	//(internal1_m456_X00)  X00 - текущая координата механизма
	{ 883	,8	,1	, &internal1_m456_V00},	//(internal1_m456_V00)  V00 - текущая скорость механизма
	{ 884	,1	,1	, &internal1_m456_Pav0},	//(internal1_m456_Pav0)  - Пер.аварийный выключатель механизма
	{ 885	,1	,1	, &internal1_m456_Zav0},	//(internal1_m456_Zav0)  - Зад.аварийный выключатель механизма
	{ 886	,1	,1	, &internal1_m456_Pv0},	//(internal1_m456_Pv0)  - Пер. выключатель механизма
	{ 887	,1	,1	, &internal1_m456_Zv0},	//(internal1_m456_Zv0)  - Зад. выключатель механизма
	{ 888	,1	,1	, &internal1_m456_RA00},	//(internal1_m456_RA00)  - последнее задание вперед
	{ 889	,1	,1	, &internal1_m456_RA10},	//(internal1_m456_RA10)  - последнее задание назад
	{ 890	,1	,1	, &internal1_m456_MyFirstEnterFlag},	//(internal1_m456_MyFirstEnterFlag) MyFirstEnterFlag
	{ 891	,8	,1	, &internal1_m442_X00},	//(internal1_m442_X00)  X00 - текущая координата механизма
	{ 892	,8	,1	, &internal1_m442_V00},	//(internal1_m442_V00)  V00 - текущая скорость механизма
	{ 893	,1	,1	, &internal1_m442_Pav0},	//(internal1_m442_Pav0)  - Пер.аварийный выключатель механизма
	{ 894	,1	,1	, &internal1_m442_Zav0},	//(internal1_m442_Zav0)  - Зад.аварийный выключатель механизма
	{ 895	,1	,1	, &internal1_m442_Pv0},	//(internal1_m442_Pv0)  - Пер. выключатель механизма
	{ 896	,1	,1	, &internal1_m442_Zv0},	//(internal1_m442_Zv0)  - Зад. выключатель механизма
	{ 897	,1	,1	, &internal1_m442_RA00},	//(internal1_m442_RA00)  - последнее задание вперед
	{ 898	,1	,1	, &internal1_m442_RA10},	//(internal1_m442_RA10)  - последнее задание назад
	{ 899	,1	,1	, &internal1_m442_MyFirstEnterFlag},	//(internal1_m442_MyFirstEnterFlag) MyFirstEnterFlag
	{ 900	,8	,1	, &internal1_m493_X00},	//(internal1_m493_X00)  X00 - текущая координата механизма
	{ 901	,8	,1	, &internal1_m493_V00},	//(internal1_m493_V00)  V00 - текущая скорость механизма
	{ 902	,1	,1	, &internal1_m493_Pav0},	//(internal1_m493_Pav0)  - Пер.аварийный выключатель механизма
	{ 903	,1	,1	, &internal1_m493_Zav0},	//(internal1_m493_Zav0)  - Зад.аварийный выключатель механизма
	{ 904	,1	,1	, &internal1_m493_Pv0},	//(internal1_m493_Pv0)  - Пер. выключатель механизма
	{ 905	,1	,1	, &internal1_m493_Zv0},	//(internal1_m493_Zv0)  - Зад. выключатель механизма
	{ 906	,1	,1	, &internal1_m493_RA00},	//(internal1_m493_RA00)  - последнее задание вперед
	{ 907	,1	,1	, &internal1_m493_RA10},	//(internal1_m493_RA10)  - последнее задание назад
	{ 908	,1	,1	, &internal1_m493_MyFirstEnterFlag},	//(internal1_m493_MyFirstEnterFlag) MyFirstEnterFlag
	{ 909	,8	,1	, &internal1_m394_X00},	//(internal1_m394_X00)  X00 - текущая координата механизма
	{ 910	,8	,1	, &internal1_m394_V00},	//(internal1_m394_V00)  V00 - текущая скорость механизма
	{ 911	,1	,1	, &internal1_m394_Pav0},	//(internal1_m394_Pav0)  - Пер.аварийный выключатель механизма
	{ 912	,1	,1	, &internal1_m394_Zav0},	//(internal1_m394_Zav0)  - Зад.аварийный выключатель механизма
	{ 913	,1	,1	, &internal1_m394_Pv0},	//(internal1_m394_Pv0)  - Пер. выключатель механизма
	{ 914	,1	,1	, &internal1_m394_Zv0},	//(internal1_m394_Zv0)  - Зад. выключатель механизма
	{ 915	,1	,1	, &internal1_m394_RA00},	//(internal1_m394_RA00)  - последнее задание вперед
	{ 916	,1	,1	, &internal1_m394_RA10},	//(internal1_m394_RA10)  - последнее задание назад
	{ 917	,1	,1	, &internal1_m394_MyFirstEnterFlag},	//(internal1_m394_MyFirstEnterFlag) MyFirstEnterFlag
	{ 918	,8	,1	, &internal1_m379_X00},	//(internal1_m379_X00)  X00 - текущая координата механизма
	{ 919	,8	,1	, &internal1_m379_V00},	//(internal1_m379_V00)  V00 - текущая скорость механизма
	{ 920	,1	,1	, &internal1_m379_Pav0},	//(internal1_m379_Pav0)  - Пер.аварийный выключатель механизма
	{ 921	,1	,1	, &internal1_m379_Zav0},	//(internal1_m379_Zav0)  - Зад.аварийный выключатель механизма
	{ 922	,1	,1	, &internal1_m379_Pv0},	//(internal1_m379_Pv0)  - Пер. выключатель механизма
	{ 923	,1	,1	, &internal1_m379_Zv0},	//(internal1_m379_Zv0)  - Зад. выключатель механизма
	{ 924	,1	,1	, &internal1_m379_RA00},	//(internal1_m379_RA00)  - последнее задание вперед
	{ 925	,1	,1	, &internal1_m379_RA10},	//(internal1_m379_RA10)  - последнее задание назад
	{ 926	,1	,1	, &internal1_m379_MyFirstEnterFlag},	//(internal1_m379_MyFirstEnterFlag) MyFirstEnterFlag
	{ 927	,8	,1	, &internal1_m363_X00},	//(internal1_m363_X00)  X00 - текущая координата механизма
	{ 928	,8	,1	, &internal1_m363_V00},	//(internal1_m363_V00)  V00 - текущая скорость механизма
	{ 929	,1	,1	, &internal1_m363_Pav0},	//(internal1_m363_Pav0)  - Пер.аварийный выключатель механизма
	{ 930	,1	,1	, &internal1_m363_Zav0},	//(internal1_m363_Zav0)  - Зад.аварийный выключатель механизма
	{ 931	,1	,1	, &internal1_m363_Pv0},	//(internal1_m363_Pv0)  - Пер. выключатель механизма
	{ 932	,1	,1	, &internal1_m363_Zv0},	//(internal1_m363_Zv0)  - Зад. выключатель механизма
	{ 933	,1	,1	, &internal1_m363_RA00},	//(internal1_m363_RA00)  - последнее задание вперед
	{ 934	,1	,1	, &internal1_m363_RA10},	//(internal1_m363_RA10)  - последнее задание назад
	{ 935	,1	,1	, &internal1_m363_MyFirstEnterFlag},	//(internal1_m363_MyFirstEnterFlag) MyFirstEnterFlag
	{ 936	,8	,1	, &internal1_m892_X00},	//(internal1_m892_X00)  X00 - текущая координата механизма
	{ 937	,8	,1	, &internal1_m892_V00},	//(internal1_m892_V00)  V00 - текущая скорость механизма
	{ 938	,1	,1	, &internal1_m892_Pav0},	//(internal1_m892_Pav0)  - Пер.аварийный выключатель механизма
	{ 939	,1	,1	, &internal1_m892_Zav0},	//(internal1_m892_Zav0)  - Зад.аварийный выключатель механизма
	{ 940	,1	,1	, &internal1_m892_Pv0},	//(internal1_m892_Pv0)  - Пер. выключатель механизма
	{ 941	,1	,1	, &internal1_m892_Zv0},	//(internal1_m892_Zv0)  - Зад. выключатель механизма
	{ 942	,1	,1	, &internal1_m892_RA00},	//(internal1_m892_RA00)  - последнее задание вперед
	{ 943	,1	,1	, &internal1_m892_RA10},	//(internal1_m892_RA10)  - последнее задание назад
	{ 944	,1	,1	, &internal1_m892_MyFirstEnterFlag},	//(internal1_m892_MyFirstEnterFlag) MyFirstEnterFlag
	{ 945	,8	,1	, &internal1_m185_C1},	//(internal1_m185_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 946	,8	,1	, &internal1_m185_C2},	//(internal1_m185_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 947	,8	,1	, &internal1_m185_C3},	//(internal1_m185_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 948	,8	,1	, &internal1_m185_C4},	//(internal1_m185_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 949	,8	,1	, &internal1_m185_C5},	//(internal1_m185_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 950	,8	,1	, &internal1_m185_C6},	//(internal1_m185_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 951	,8	,1	, &internal1_m185_N20},	//(internal1_m185_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 952	,8	,1	, &internal1_m185_N00},	//(internal1_m185_N00) N00 - Текущая концентрация нейтронов
	{ 953	,8	,1	, &internal1_m185_R00},	//(internal1_m185_R00) R00 - Текущая реактивность
	{ 954	,8	,1	, &internal1_m185_T00},	//(internal1_m185_T00) T00 - Текущая температура
	{ 955	,1	,1	, &internal1_m185_ImpINI0},	//(internal1_m185_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 956	,1	,1	, &internal1_m185_MyFirstEnterFlag},	//(internal1_m185_MyFirstEnterFlag) MyFirstEnterFlag
	{ 957	,8	,1	, &internal1_m299_X00},	//(internal1_m299_X00) X0 - текущая координата ОРР
	{ 958	,8	,1	, &internal1_m299_Sh00},	//(internal1_m299_Sh00) Sh0 - текущая координата штока ОРР
	{ 959	,8	,1	, &internal1_m299_RV00},	//(internal1_m299_RV00) V0 - текущая скорость ОРР
	{ 960	,8	,1	, &internal1_m299_ShV00},	//(internal1_m299_ShV00) V0 - текущая скорость штока ОРР
	{ 961	,1	,1	, &internal1_m299_Ppv0},	//(internal1_m299_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 962	,1	,1	, &internal1_m299_Pav0},	//(internal1_m299_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 963	,1	,1	, &internal1_m299_Zav0},	//(internal1_m299_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 964	,1	,1	, &internal1_m299_RA00},	//(internal1_m299_RA00) RA00 - последнее задание вперед
	{ 965	,1	,1	, &internal1_m299_RA10},	//(internal1_m299_RA10) RA10 - последнее задание назад
	{ 966	,1	,1	, &internal1_m299_RA30},	//(internal1_m299_RA30)  RA30 - разрешение движения
	{ 967	,1	,1	, &internal1_m299_RA50},	//(internal1_m299_RA50) Ra50 - последнее задание скорости
	{ 968	,1	,1	, &internal1_m299_fls},	//(internal1_m299_fls)  fls - флаг одношагового режима
	{ 969	,1	,1	, &internal1_m299_flp},	//(internal1_m299_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 970	,1	,1	, &internal1_m299_MyFirstEnterFlag},	//(internal1_m299_MyFirstEnterFlag) MyFirstEnterFlag
	{ 971	,8	,1	, &internal1_m134_X00},	//(internal1_m134_X00) X0 - текущая координата ОРР
	{ 972	,8	,1	, &internal1_m134_Sh00},	//(internal1_m134_Sh00) Sh0 - текущая координата штока ОРР
	{ 973	,8	,1	, &internal1_m134_RV00},	//(internal1_m134_RV00) V0 - текущая скорость ОРР
	{ 974	,8	,1	, &internal1_m134_ShV00},	//(internal1_m134_ShV00) V0 - текущая скорость штока ОРР
	{ 975	,1	,1	, &internal1_m134_Ppv0},	//(internal1_m134_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 976	,1	,1	, &internal1_m134_Pav0},	//(internal1_m134_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 977	,1	,1	, &internal1_m134_Zav0},	//(internal1_m134_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 978	,1	,1	, &internal1_m134_RA00},	//(internal1_m134_RA00) RA00 - последнее задание вперед
	{ 979	,1	,1	, &internal1_m134_RA10},	//(internal1_m134_RA10) RA10 - последнее задание назад
	{ 980	,1	,1	, &internal1_m134_RA30},	//(internal1_m134_RA30)  RA30 - разрешение движения
	{ 981	,1	,1	, &internal1_m134_RA50},	//(internal1_m134_RA50) Ra50 - последнее задание скорости
	{ 982	,1	,1	, &internal1_m134_fls},	//(internal1_m134_fls)  fls - флаг одношагового режима
	{ 983	,1	,1	, &internal1_m134_flp},	//(internal1_m134_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 984	,1	,1	, &internal1_m134_MyFirstEnterFlag},	//(internal1_m134_MyFirstEnterFlag) MyFirstEnterFlag
	{ 985	,8	,1	, &internal1_m269_X00},	//(internal1_m269_X00) X0 - текущая координата ОРР
	{ 986	,8	,1	, &internal1_m269_Sh00},	//(internal1_m269_Sh00) Sh0 - текущая координата штока ОРР
	{ 987	,8	,1	, &internal1_m269_RV00},	//(internal1_m269_RV00) V0 - текущая скорость ОРР
	{ 988	,8	,1	, &internal1_m269_ShV00},	//(internal1_m269_ShV00) V0 - текущая скорость штока ОРР
	{ 989	,1	,1	, &internal1_m269_Ppv0},	//(internal1_m269_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 990	,1	,1	, &internal1_m269_Pav0},	//(internal1_m269_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 991	,1	,1	, &internal1_m269_Zav0},	//(internal1_m269_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 992	,1	,1	, &internal1_m269_RA00},	//(internal1_m269_RA00) RA00 - последнее задание вперед
	{ 993	,1	,1	, &internal1_m269_RA10},	//(internal1_m269_RA10) RA10 - последнее задание назад
	{ 994	,1	,1	, &internal1_m269_RA30},	//(internal1_m269_RA30)  RA30 - разрешение движения
	{ 995	,1	,1	, &internal1_m269_RA50},	//(internal1_m269_RA50) Ra50 - последнее задание скорости
	{ 996	,1	,1	, &internal1_m269_fls},	//(internal1_m269_fls)  fls - флаг одношагового режима
	{ 997	,1	,1	, &internal1_m269_flp},	//(internal1_m269_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 998	,1	,1	, &internal1_m269_MyFirstEnterFlag},	//(internal1_m269_MyFirstEnterFlag) MyFirstEnterFlag
	{ 999	,8	,1	, &internal1_m100_X00},	//(internal1_m100_X00) X0 - текущая координата ОРР
	{ 1000	,8	,1	, &internal1_m100_Sh00},	//(internal1_m100_Sh00) Sh0 - текущая координата штока ОРР
	{ 1001	,8	,1	, &internal1_m100_RV00},	//(internal1_m100_RV00) V0 - текущая скорость ОРР
	{ 1002	,8	,1	, &internal1_m100_ShV00},	//(internal1_m100_ShV00) V0 - текущая скорость штока ОРР
	{ 1003	,1	,1	, &internal1_m100_Ppv0},	//(internal1_m100_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1004	,1	,1	, &internal1_m100_Pav0},	//(internal1_m100_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1005	,1	,1	, &internal1_m100_Zav0},	//(internal1_m100_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1006	,1	,1	, &internal1_m100_RA00},	//(internal1_m100_RA00) RA00 - последнее задание вперед
	{ 1007	,1	,1	, &internal1_m100_RA10},	//(internal1_m100_RA10) RA10 - последнее задание назад
	{ 1008	,1	,1	, &internal1_m100_RA30},	//(internal1_m100_RA30)  RA30 - разрешение движения
	{ 1009	,1	,1	, &internal1_m100_RA50},	//(internal1_m100_RA50) Ra50 - последнее задание скорости
	{ 1010	,1	,1	, &internal1_m100_fls},	//(internal1_m100_fls)  fls - флаг одношагового режима
	{ 1011	,1	,1	, &internal1_m100_flp},	//(internal1_m100_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1012	,1	,1	, &internal1_m100_MyFirstEnterFlag},	//(internal1_m100_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1013	,8	,1	, &internal1_m234_X00},	//(internal1_m234_X00) X0 - текущая координата ОРР
	{ 1014	,8	,1	, &internal1_m234_Sh00},	//(internal1_m234_Sh00) Sh0 - текущая координата штока ОРР
	{ 1015	,8	,1	, &internal1_m234_RV00},	//(internal1_m234_RV00) V0 - текущая скорость ОРР
	{ 1016	,8	,1	, &internal1_m234_ShV00},	//(internal1_m234_ShV00) V0 - текущая скорость штока ОРР
	{ 1017	,1	,1	, &internal1_m234_Ppv0},	//(internal1_m234_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1018	,1	,1	, &internal1_m234_Pav0},	//(internal1_m234_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1019	,1	,1	, &internal1_m234_Zav0},	//(internal1_m234_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1020	,1	,1	, &internal1_m234_RA00},	//(internal1_m234_RA00) RA00 - последнее задание вперед
	{ 1021	,1	,1	, &internal1_m234_RA10},	//(internal1_m234_RA10) RA10 - последнее задание назад
	{ 1022	,1	,1	, &internal1_m234_RA30},	//(internal1_m234_RA30)  RA30 - разрешение движения
	{ 1023	,1	,1	, &internal1_m234_RA50},	//(internal1_m234_RA50) Ra50 - последнее задание скорости
	{ 1024	,1	,1	, &internal1_m234_fls},	//(internal1_m234_fls)  fls - флаг одношагового режима
	{ 1025	,1	,1	, &internal1_m234_flp},	//(internal1_m234_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1026	,1	,1	, &internal1_m234_MyFirstEnterFlag},	//(internal1_m234_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1027	,8	,1	, &internal1_m66_X00},	//(internal1_m66_X00) X0 - текущая координата ОРР
	{ 1028	,8	,1	, &internal1_m66_Sh00},	//(internal1_m66_Sh00) Sh0 - текущая координата штока ОРР
	{ 1029	,8	,1	, &internal1_m66_RV00},	//(internal1_m66_RV00) V0 - текущая скорость ОРР
	{ 1030	,8	,1	, &internal1_m66_ShV00},	//(internal1_m66_ShV00) V0 - текущая скорость штока ОРР
	{ 1031	,1	,1	, &internal1_m66_Ppv0},	//(internal1_m66_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1032	,1	,1	, &internal1_m66_Pav0},	//(internal1_m66_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1033	,1	,1	, &internal1_m66_Zav0},	//(internal1_m66_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1034	,1	,1	, &internal1_m66_RA00},	//(internal1_m66_RA00) RA00 - последнее задание вперед
	{ 1035	,1	,1	, &internal1_m66_RA10},	//(internal1_m66_RA10) RA10 - последнее задание назад
	{ 1036	,1	,1	, &internal1_m66_RA30},	//(internal1_m66_RA30)  RA30 - разрешение движения
	{ 1037	,1	,1	, &internal1_m66_RA50},	//(internal1_m66_RA50) Ra50 - последнее задание скорости
	{ 1038	,1	,1	, &internal1_m66_fls},	//(internal1_m66_fls)  fls - флаг одношагового режима
	{ 1039	,1	,1	, &internal1_m66_flp},	//(internal1_m66_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1040	,1	,1	, &internal1_m66_MyFirstEnterFlag},	//(internal1_m66_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1041	,8	,1	, &internal1_m14_C1},	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 1042	,8	,1	, &internal1_m14_C2},	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 1043	,8	,1	, &internal1_m14_C3},	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 1044	,8	,1	, &internal1_m14_C4},	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 1045	,8	,1	, &internal1_m14_C5},	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 1046	,8	,1	, &internal1_m14_C6},	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 1047	,8	,1	, &internal1_m14_N20},	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 1048	,8	,1	, &internal1_m14_N00},	//(internal1_m14_N00) N00 - Текущая концентрация нейтронов
	{ 1049	,8	,1	, &internal1_m14_R00},	//(internal1_m14_R00) R00 - Текущая реактивность
	{ 1050	,8	,1	, &internal1_m14_T00},	//(internal1_m14_T00) T00 - Текущая температура
	{ 1051	,1	,1	, &internal1_m14_ImpINI0},	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 1052	,1	,1	, &internal1_m14_MyFirstEnterFlag},	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="scm.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{284,"fEM_R0UL01RIM\0"}, 
{285,"fEM_R0UN02RIM\0"}, 
{286,"fEM_A1UR01RIM\0"}, 
{287,"fEM_A1UR00RIM\0"}, 
{288,"fEM_A3UR00RIM\0"}, 
{289,"fEM_A3UR01RIM\0"}, 
{290,"fEM_R0UT01RIM\0"}, 
{291,"fEM_R0UT02RIM\0"}, 
{292,"fEM_R0UT04RIM\0"}, 
{293,"fEM_R0UT03RIM\0"}, 
{294,"fEM_R0UT05RIM\0"}, 
{295,"fEM_R0UT06RIM\0"}, 
{296,"fEM_A1UC02RDU\0"}, 
{297,"fEM_A1UC04RIM\0"}, 
{298,"fEM_A1UC05RIM\0"}, 
{299,"fEM_A1UC06RIM\0"}, 
{300,"fEM_A2UC06RIM\0"}, 
{301,"fEM_A2UC05RIM\0"}, 
{302,"fEM_A2UC04RIM\0"}, 
{303,"fEM_A2UC02RDU\0"}, 
{304,"fEM_A3UC06RIM\0"}, 
{305,"fEM_A3UC05RIM\0"}, 
{306,"fEM_A3UC04RIM\0"}, 
{307,"fEM_A3UC02RDU\0"}, 
{308,"fEM_R4UV80RDU\0"}, 
{309,"fEM_R4UC10RIM\0"}, 
{310,"fEM_R4UC20RIM\0"}, 
{311,"fEM_B8UC21RIM\0"}, 
{312,"fEM_B8UC20RIM\0"}, 
{313,"fEM_B8UC11RIM\0"}, 
{314,"fEM_B8UC10RIM\0"}, 
{315,"fEM_B8UV80RDU\0"}, 
{316,"fEM_A8UV80RDU\0"}, 
{317,"fEM_A8UC10RIM\0"}, 
{318,"fEM_A8UC11RIM\0"}, 
{319,"fEM_A8UC20RIM\0"}, 
{320,"fEM_A8UC21RIM\0"}, 
{321,"fEM_A6UC10RIM\0"}, 
{322,"fEM_R1UC10RIM\0"}, 
{323,"fEM_A5UC10RIM\0"}, 
{324,"fEM_A0UN01RIM\0"}, 
{325,"fEM_R4UC22RIM\0"}, 
{326,"fEM_A1UG01RDU\0"}, 
{327,"fEM_A2UG01RDU\0"}, 
{328,"fEM_A3UG01RDU\0"}, 
{329,"fEM_R7UC10RIM\0"}, 
{330,"fEM_R7UC19RIM\0"}, 
{331,"fEM_R7UI02RIM\0"}, 
{332,"fEM_R7UL01RIM\0"}, 
{333,"fEM_A2UR00RIM\0"}, 
{334,"fEM_A2UR01RIM\0"}, 
{335,"fEM_A0UN02RIM\0"}, 
{336,"fEM_R0UR30RIM\0"}, 
{337,"fEM_R0UR01RIM\0"}, 
{338,"fEM_R0UT02RDU\0"}, 
{339,"fEM_R0UT01RDU\0"}, 
{340,"fEM_A1UC03RDU\0"}, 
{341,"fEM_A2UP03RDU\0"}, 
{342,"fEM_A2UP04RDU\0"}, 
{343,"fEM_A2UC03RDU\0"}, 
{344,"fEM_A3UP03RDU\0"}, 
{345,"fEM_A3UP04RDU\0"}, 
{346,"fEM_A3UC03RDU\0"}, 
{347,"fEM_R7UI74RIM\0"}, 
{348,"fEM_A8UC03RDU\0"}, 
{349,"fEM_R0UV87RDU\0"}, 
{350,"fEM_R0UV81RDU\0"}, 
{351,"fEM_R0UV82RDU\0"}, 
{352,"fEM_R0UV83RDU\0"}, 
{353,"fEM_R0UV84RDU\0"}, 
{354,"fEM_R0UV85RDU\0"}, 
{355,"fEM_R0UV86RDU\0"}, 
{356,"fEM_A8UC08RDU\0"}, 
{357,"fEM_B8UC08RDU\0"}, 
{358,"fEM_R4UC08RDU\0"}, 
{359,"fEM_R0UH01RSS\0"}, 
{360,"fEM_A0UX00RSS\0"}, 
{361,"fEM_R7UX01RSS\0"}, 
{362,"fEM_R7UX02RSS\0"}, 
{363,"fEM_R7UX04RSS\0"}, 
{364,"fEM_R7UX05RSS\0"}, 
{365,"fEM_R7UX06RSS\0"}, 
{366,"fEM_R7UX07RSS\0"}, 
{367,"fEM_R7UX08RSS\0"}, 
{368,"fEM_R7UX09RSS\0"}, 
{369,"fEM_R7UY01RSS\0"}, 
{370,"fEM_R7UY02RSS\0"}, 
{371,"fEM_R7UY04RSS\0"}, 
{372,"fEM_R7UY05RSS\0"}, 
{373,"fEM_R7UY06RSS\0"}, 
{374,"fEM_R7UY07RSS\0"}, 
{375,"fEM_R7UY08RSS\0"}, 
{376,"fEM_R7UY09RSS\0"}, 
{377,"fEM_R7UX10RSS\0"}, 
{378,"fEM_R7UX11RSS\0"}, 
{379,"fEM_R7UX12RSS\0"}, 
{380,"fEM_R7UY10RSS\0"}, 
{381,"fEM_R7UY11RSS\0"}, 
{382,"fEM_R7UY12RSS\0"}, 
{383,"fEM_A0UX01RSS\0"}, 
{384,"fEM_A0UX02RSS\0"}, 
{385,"fEM_A0UX03RSS\0"}, 
{386,"fEM_A0UX04RSS\0"}, 
{387,"fEM_A0UX05RSS\0"}, 
{388,"fEM_A0UX06RSS\0"}, 
{389,"fEM_A0UX07RSS\0"}, 
{390,"fEM_A0UX08RSS\0"}, 
{391,"fEM_A0UX09RSS\0"}, 
{392,"fEM_A0UX10RSS\0"}, 
{393,"fEM_A0UX11RSS\0"}, 
{394,"fEM_A0UX12RSS\0"}, 
{395,"fEM_B0UX01RSS\0"}, 
{396,"fEM_B0UX02RSS\0"}, 
{397,"fEM_B0UX03RSS\0"}, 
{398,"fEM_B0UX04RSS\0"}, 
{399,"fEM_B0UX05RSS\0"}, 
{400,"fEM_B0UX06RSS\0"}, 
{401,"fEM_B0UX07RSS\0"}, 
{402,"fEM_B0UX08RSS\0"}, 
{403,"fEM_B0UX09RSS\0"}, 
{404,"fEM_B0UX10RSS\0"}, 
{405,"fEM_B0UX11RSS\0"}, 
{406,"fEM_B0UX12RSS\0"}, 
{407,"fEM_R0UH02RSS\0"}, 
{408,"fEM_R0UH03RSS\0"}, 
{409,"fEM_R4US80RDU\0"}, 
{410,"fEM_R7UI71RIM\0"}, 
{411,"fEM_R7UI72RIM\0"}, 
{412,"fEM_R7UI73RIM\0"}, 
{413,"fEM_A1UP01RIM\0"}, 
{414,"fEM_A2UP01RIM\0"}, 
{415,"fEM_A0UP02RIM\0"}, 
{416,"fEM_A3UP01RIM\0"}, 
{417,"fEM_A1UP82RIM\0"}, 
{418,"fEM_A3UP02RDU\0"}, 
{419,"fEM_A1UV02RIM\0"}, 
{420,"fEM_A3UV02RIM\0"}, 
{421,"fEM_A2UV02RIM\0"}, 
{422,"fEM_B8US80RDU\0"}, 
{423,"fEM_A8US80RDU\0"}, 
{424,"fEM_A6US80RDU\0"}, 
{425,"fEM_A1US07RDU\0"}, 
{426,"fEM_A2US07RDU\0"}, 
{427,"fEM_A3US07RDU\0"}, 
{428,"fEM_R7UI75RIM\0"}, 
{429,"fEM_R0UH21RSS\0"}, 
{430,"fEM_R0UH22RSS\0"}, 
{431,"fEM_R0UH23RSS\0"}, 
{432,"fEM_R0UH05RSS\0"}, 
{433,"fEM_A4UL10RIM\0"}, 
{434,"fEM_A9UL10RIM\0"}, 
{435,"fEM_R3UL10RIM\0"}, 
{436,"fEM_R5UL10RIM\0"}, 
{437,"fEM_R6UL10RIM\0"}, 
{438,"lEM_C1AD31LRP\0"}, 
{439,"lEM_R0IE01LRP\0"}, 
{440,"lEM_R0IE02LRP\0"}, 
{441,"fEM_A2UP02RIM\0"}, 
{442,"fEM_A2UP03RIM\0"}, 
{443,"fEM_A0UP01RIM\0"}, 
{444,"fEM_A3UP02RIM\0"}, 
{445,"fEM_A4UP01RIM\0"}, 
{446,"fEM_A4UP02RIM\0"}, 
{447,"fEM_R7UI76RIM\0"}, 
{448,"fEM_R7UI77RIM\0"}, 
{449,"iEM_TERBB1\0"}, 
{450,"fEM_A1MC02RC1\0"}, 
{451,"fEM_A1MV02RC1\0"}, 
{452,"iEM_TERBB2\0"}, 
{453,"fEM_B1MC02RC1\0"}, 
{454,"fEM_B1MV02RC1\0"}, 
{455,"iEM_TERRB2\0"}, 
{456,"fEM_B2MC02RC1\0"}, 
{457,"fEM_B2MV02RC1\0"}, 
{458,"iEM_TERRB1\0"}, 
{459,"fEM_A2MC02RC1\0"}, 
{460,"fEM_A2MV02RC1\0"}, 
{461,"iEM_TERIS2\0"}, 
{462,"fEM_B3MC02RC1\0"}, 
{463,"fEM_B3MV02RC1\0"}, 
{464,"iEM_TERIS1\0"}, 
{465,"fEM_A3MC02RC1\0"}, 
{466,"fEM_A3MV02RC1\0"}, 
{467,"iEM_TERA1IE04LDU\0"}, 
{468,"iEM_TERA1IE03LDU\0"}, 
{469,"fEM_A1MC01RC1\0"}, 
{470,"iEM_TERB1IE03LDU\0"}, 
{471,"iEM_TERB1IE04LDU\0"}, 
{472,"fEM_B1MC01RC1\0"}, 
{473,"fEM_B1MV01RC1\0"}, 
{474,"fEM_B2MC01RC1\0"}, 
{475,"fEM_B2MV01RC1\0"}, 
{476,"fEM_A3MC01RC1\0"}, 
{477,"fEM_A3MV01RC1\0"}, 
{478,"fEM_B3MC01RC1\0"}, 
{479,"fEM_B3MV01RC1\0"}, 
{480,"iEM_TERA2SS21LIM\0"}, 
{481,"iEM_TERA2SS12LIM\0"}, 
{482,"iEM_TERR6SS21LIM\0"}, 
{483,"iEM_TERA2VP82LIM\0"}, 
{484,"iEM_TERA2SS11LIM\0"}, 
{485,"iEM_TERB3SS21LIM\0"}, 
{486,"iEM_TERA0MT01RIM\0"}, 
{487,"iEM_TERB0MT01RIM\0"}, 
{488,"iEM_TERA2SP01RIM\0"}, 
{489,"iEM_TERB2SP01RIM\0"}, 
{490,"iEM_TERB3SP02RIM\0"}, 
{491,"iEM_TERA3SC01RIM\0"}, 
{492,"iEM_TERA3VP81LIM\0"}, 
{493,"iEM_TERA2SC01RIM\0"}, 
{494,"iEM_TERA2SS33LIM\0"}, 
{495,"iEM_TERA3SS21LIM\0"}, 
{496,"iEM_TERA3SS33LIM\0"}, 
{497,"iEM_TERA3SS31LIM\0"}, 
{498,"iEM_TERB3SS31LIM\0"}, 
{499,"iEM_TERB3SS33LIM\0"}, 
{500,"iEM_TERB3SC01RIM\0"}, 
{501,"iEM_TERA3SS11LIM\0"}, 
{502,"iEM_TERB3SS11LIM\0"}, 
{503,"iEM_TERR6IS64LIM\0"}, 
{504,"iEM_TERB3SS22LIM\0"}, 
{505,"iEM_TERA3SS22LIM\0"}, 
{506,"iEM_TERA3SP02RIM\0"}, 
{507,"iEM_TERR6IS62LIM\0"}, 
{508,"iEM_TERR6IS66LIM\0"}, 
{509,"iEM_TERR6IS67LIM\0"}, 
{510,"iEM_TERA0VP81LIM\0"}, 
{511,"iEM_TERB0VP81LIM\0"}, 
{512,"iEM_TERR0VP81LIM\0"}, 
{513,"iEM_TERR6IS68LIM\0"}, 
{514,"iEM_TERR7SI74RIM\0"}, 
{515,"iEM_TERA5SS21LIM\0"}, 
{516,"iEM_TERB5SS11LIM\0"}, 
{517,"iEM_TERA5SS11LIM\0"}, 
{518,"iEM_TERA9SS11LIM\0"}, 
{519,"iEM_TERB2SS11LIM\0"}, 
{520,"iEM_TERB2SS12LIM\0"}, 
{521,"iEM_TERB2SS21LIM\0"}, 
{522,"iEM_TERR3SS11LIM\0"}, 
{523,"iEM_TERB2SC01RIM\0"}, 
{524,"iEM_TERR3SS21LIM\0"}, 
{525,"iEM_TERR5SS11LIM\0"}, 
{526,"iEM_TERA4SS11LIM\0"}, 
{527,"iEM_TERR1SS11LIM\0"}, 
{528,"iEM_TERR1SS21LIM\0"}, 
{529,"iEM_TERR2SS11LIM\0"}, 
{530,"iEM_TERR2SS21LIM\0"}, 
{531,"iEM_TERA4VP82LIM\0"}, 
{532,"iEM_TERB4SS21LIM\0"}, 
{533,"iEM_TERR5SS21LIM\0"}, 
{534,"iEM_TERB6SS21LIM\0"}, 
{535,"iEM_TERB4SS11LIM\0"}, 
{536,"iEM_TERA4SS21LIM\0"}, 
{537,"iEM_TERA6MS11LIM\0"}, 
{538,"iEM_TERA6SS21LIM\0"}, 
{539,"iEM_TERB6SS11LIM\0"}, 
{540,"iEM_TERR4SS11LIM\0"}, 
{541,"iEM_TERR4MS21LIM\0"}, 
{542,"iEM_TERR4SS12LIM\0"}, 
{543,"iEM_TERR4SS22LIM\0"}, 
{544,"iEM_TERR8SS11LIM\0"}, 
{545,"iEM_TERB8SC01RIM\0"}, 
{546,"iEM_TERA8SC01RIM\0"}, 
{547,"iEM_TERB8SS12LIM\0"}, 
{548,"iEM_TERA8SS12LIM\0"}, 
{549,"iEM_TERB8SS22LIM\0"}, 
{550,"iEM_TERA8SS22LIM\0"}, 
{551,"iEM_TERA9SS21LIM\0"}, 
{552,"iEM_TERB9SS21LIM\0"}, 
{553,"iEM_TERB9SS11LIM\0"}, 
{554,"iEM_TERB5SS21LIM\0"}, 
{555,"iEM_TERA1SS21LIM\0"}, 
{556,"iEM_TERA1SS11LIM\0"}, 
{557,"iEM_TERA1SC01RIM\0"}, 
{558,"iEM_TERA1SS12LIM\0"}, 
{559,"iEM_TERB1SS21LIM\0"}, 
{560,"iEM_TERB1SS11LIM\0"}, 
{561,"iEM_TERB1MC01RIM\0"}, 
{562,"iEM_TERB1SS12LIM\0"}, 
{563,"iEM_TERTLG\0"}, 
{564,"fEM_R4MC01RC1\0"}, 
{565,"fEM_R4MV01RC1\0"}, 
{566,"iEM_TERMAZ2\0"}, 
{567,"fEM_B8MV01RC1\0"}, 
{568,"iEM_TERDS2\0"}, 
{569,"fEM_A8MC01RC1\0"}, 
{570,"fEM_A8MV01RC1\0"}, 
{571,"iEM_TERBZ1\0"}, 
{572,"fEM_A6MC01RC1\0"}, 
{573,"fEM_A6MV01RC1\0"}, 
{574,"iEM_TERBZ2\0"}, 
{575,"fEM_B6MC01RC1\0"}, 
{576,"fEM_B6MV01RC1\0"}, 
{577,"lEM_R3AD10LC1\0"}, 
{578,"lEM_R3AD20LC1\0"}, 
{579,"lEM_R6AD10LC1\0"}, 
{580,"lEM_R5AD10LC1\0"}, 
{581,"lEM_R5AD20LC1\0"}, 
{582,"iEM_TERMDZ2\0"}, 
{583,"fEM_R2MC01RC1\0"}, 
{584,"fEM_R2MV01RC1\0"}, 
{585,"iEM_TERMDZ1\0"}, 
{586,"fEM_R1MC01RC1\0"}, 
{587,"fEM_R1MV01RC1\0"}, 
{588,"iEM_TERNL1\0"}, 
{589,"fEM_A5MC01RC1\0"}, 
{590,"fEM_A5MV01RC1\0"}, 
{591,"iEM_TERNL2\0"}, 
{592,"fEM_B5MC01RC1\0"}, 
{593,"fEM_B5MV01RC1\0"}, 
{594,"lEM_R8AD10LC1\0"}, 
{595,"fEM_A1UC08RIM\0"}, 
{596,"fEM_A2UC08RIM\0"}, 
{597,"fEM_A3UC08RIM\0"}, 
{598,"iEM_TERB2SS33LIM\0"}, 
{599,"iEM_TERA1VP81LIM\0"}, 
{600,"iEM_TERB1VP81LIM\0"}, 
{601,"fEM_A0UT03RSP\0"}, 
{602,"fEM_A0UR01RSP\0"}, 
{603,"fEM_A0UR02RSP\0"}, 
{604,"fEM_B0UT03RSP\0"}, 
{605,"fEM_A1MC01RSP\0"}, 
{606,"fEM_A1MC02RSP\0"}, 
{607,"fEM_B1MC01RSP\0"}, 
{608,"fEM_B1MC02RSP\0"}, 
{609,"fEM_A2MC01RC1\0"}, 
{610,"fEM_A2MV01RC1\0"}, 
{611,"fEM_A2MC01RSP\0"}, 
{612,"fEM_A2MC02RSP\0"}, 
{613,"fEM_B2MC01RSP\0"}, 
{614,"fEM_B2MC02RSP\0"}, 
{615,"fEM_A3MC01RSP\0"}, 
{616,"fEM_A3MC02RSP\0"}, 
{617,"fEM_B3MC01RSP\0"}, 
{618,"fEM_B3MC02RSP\0"}, 
{619,"fEM_B8MC01RSP\0"}, 
{620,"fEM_A8MC01RSP\0"}, 
{621,"fEM_A6MC01RSP\0"}, 
{622,"fEM_B6MC01RSP\0"}, 
{623,"fEM_R3UC01RSP\0"}, 
{624,"fEM_R5UC01RSP\0"}, 
{625,"fEM_R6UC01RSP\0"}, 
{626,"fEM_R2MC01RSP\0"}, 
{627,"fEM_R1MC01RSP\0"}, 
{628,"fEM_A5MC01RSP\0"}, 
{629,"fEM_B5MC01RSP\0"}, 
{630,"fEM_A9MC01RSP\0"}, 
{631,"fEM_B9MC01RSP\0"}, 
{632,"fEM_A4MC01RSP\0"}, 
{633,"fEM_B4MC01RSP\0"}, 
{634,"fEM_R4MC01RSP\0"}, 
{635,"fEM_A1MV01RC1\0"}, 
{636,"iEM_TERB7MS31LIM\0"}, 
{637,"iEM_TERA7MS31LIM\0"}, 
{638,"fEM_R7UY00RSS\0"}, 
{639,"iEM_TERA6VS12LIM\0"}, 
{640,"iEM_TERA6VS22LIM\0"}, 
{641,"iEM_TERB6VS12LIM\0"}, 
{642,"iEM_TERB6VS22LIM\0"}, 
{643,"iEM_TERA5VS22LIM\0"}, 
{644,"iEM_TERA5VS12LIM\0"}, 
{645,"iEM_TERB5VS12LIM\0"}, 
{646,"iEM_TERB5VS22LIM\0"}, 
{647,"iEM_TERR1VS12LIM\0"}, 
{648,"iEM_TERR1VS22LIM\0"}, 
{649,"iEM_TERR2VS12LIM\0"}, 
{650,"iEM_TERR2VS22LIM\0"}, 
{651,"iEM_TERR4VS12LDU\0"}, 
{652,"iEM_TERR4VS22LDU\0"}, 
{653,"fEM_A0UX13RSS\0"}, 
{654,"fEM_A0UX14RSS\0"}, 
{655,"fEM_A0UX15RSS\0"}, 
{656,"fEM_R7UX13RSS\0"}, 
{657,"fEM_R7UX14RSS\0"}, 
{658,"fEM_R7UX15RSS\0"}, 
{659,"fEM_R7UY13RSS\0"}, 
{660,"fEM_R7UY14RSS\0"}, 
{661,"fEM_R7UY15RSS\0"}, 
{662,"fEM_R7UX16RSS\0"}, 
{663,"fEM_B8MC01RC1\0"}, 
{664,"fEM_A0UN07RIM\0"}, 
{665,"fEM_R0UL02RIM\0"}, 
{666,"fEM_R0UL04RDU\0"}, 
{667,"fEM_R0UL02RDU\0"}, 
{668,"fEM_R0UL03RDU\0"}, 
{0,NULL}
};
#pragma pack(push,1)
static ModbusRegister coil_SCM[]={  // 
	{&R0AD14LDU,1,0},	//( - , SCM) Имитация срабатывания верхней АС II УР
	{&R0VZ71LZ1,1,1},	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
	{&R0VZ71LZ2,1,2},	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
	{&C2MD31LP1,1,3},	//( - , SCM) Кнопка «СБРОС РБ»
	{&C1MD31LP2,1,4},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{&C1MD31LP1,1,5},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{&R0MW13LP2,1,6},	//( - , SCM) Переключатель «СЕТЬ»
	{&lEM_C1AD31LRP,1,7},	//( - , SCM) Общий сброс от РПУ
	{&lEM_R0IE01LRP,1,8},	//( - , SCM) Отключение питание детекторов
	{&lEM_R0IE02LRP,1,9},	//( - , SCM) Отключить питание ПР, ПУ
	{&lEM_R3AD10LC1,1,10},	//( - , SCM) Гомогенные двери-1 открыть от ИС
	{&lEM_R3AD20LC1,1,11},	//( - , SCM) Гомогенные двери-1 закрыть от ИС
	{&lEM_R6AD10LC1,1,12},	//( - , SCM) Выкатить кран-балку от ИС
	{&lEM_R5AD10LC1,1,13},	//( - , SCM) Открыть ворота отстойной зоны от ИС
	{&lEM_R5AD20LC1,1,14},	//( - , SCM) Закрыть ворота отстойной зоны от ИС
	{&lEM_R8AD10LC1,1,15},	//( - , SCM) Установить аварийный НИ от ИС
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SCM[]={  // 
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
static ModbusRegister ir_SCM[]={  // 
	{&A0VN01RIM,8,0},	//( - , SCM) Период разгона  AЗ1
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SCM[]={  // 
	{&R0MW11IP1,3,0},	//( - , SCM) Переключатель ВЫСТРЕЛ
	{&R0DEUMLSS,3,1},	//( - , SCM) Сигнал управления моделью
	{&fEM_R0UL01RIM,8,2},	//( - , SCM) Среднее время генерации нейтронов
	{&fEM_R0UN02RIM,8,4},	//( - , SCM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{&fEM_A1UR01RIM,8,6},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{&fEM_A1UR00RIM,8,8},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{&fEM_A3UR00RIM,8,10},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{&fEM_A3UR01RIM,8,12},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{&fEM_R0UT01RIM,8,14},	//( - , SCM) Температурный коэффициент (долл)
	{&fEM_R0UT02RIM,8,16},	//( - , SCM) Масса топлива в АЗ
	{&fEM_R0UT04RIM,8,18},	//( - , SCM) Удельная теплоёмкость топлива
	{&fEM_R0UT03RIM,8,20},	//( - , SCM) Нормальная температура АЗ град
	{&fEM_R0UT05RIM,8,22},	//( - , SCM) Энергия деления ядра
	{&fEM_R0UT06RIM,8,24},	//( - , SCM) Конвекционное сопротивление при обдуве
	{&fEM_A1UC02RDU,8,26},	//( - , SCM) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{&fEM_A1UC04RIM,8,28},	//( - , SCM) Координата промежуточного путевого выключателя ББ мм
	{&fEM_A1UC05RIM,8,30},	//( - , SCM) Координата переднего аварийного выключателя ББ мм
	{&fEM_A1UC06RIM,8,32},	//( - , SCM) Координата заднего аварийного выключателя ББ мм
	{&fEM_A2UC06RIM,8,34},	//( - , SCM) Координата заднего аварийного выключателя РБ мм
	{&fEM_A2UC05RIM,8,36},	//( - , SCM) Координата переднего аварийного выключателя РБ мм
	{&fEM_A2UC04RIM,8,38},	//( - , SCM) Координата промежуточного путевого выключателя РБ мм
	{&fEM_A2UC02RDU,8,40},	//( - , SCM) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{&fEM_A3UC06RIM,8,42},	//( - , SCM) Координата заднего аварийного выключателя ИС мм
	{&fEM_A3UC05RIM,8,44},	//( - , SCM) Координата переднего аварийного выключателя ИС мм
	{&fEM_A3UC04RIM,8,46},	//( - , SCM) Координата промежуточного путевого выключателя ИС мм
	{&fEM_A3UC02RDU,8,48},	//( - , SCM) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{&fEM_R4UV80RDU,8,50},	//( - , SCM) Номинальная скорость тележки (см/с)
	{&fEM_R4UC10RIM,8,52},	//( - , SCM) Координата верхних механических упоров тележки мм
	{&fEM_R4UC20RIM,8,54},	//( - , SCM) Координата нижних механических упоров тележки мм
	{&fEM_B8UC21RIM,8,56},	//( - , SCM) Координата верхнего путевого выключателя АЗ2 мм
	{&fEM_B8UC20RIM,8,58},	//( - , SCM) Координата верхних механических упоров АЗ2 мм
	{&fEM_B8UC11RIM,8,60},	//( - , SCM) Координата нижнего путевого выключателя АЗ2 мм
	{&fEM_B8UC10RIM,8,62},	//( - , SCM) Координата нижних механических упоров АЗ2 мм
	{&fEM_B8UV80RDU,8,64},	//( - , SCM) Номинальная скорость АЗ2 (мм/с)
	{&fEM_A8UV80RDU,8,66},	//( - , SCM) Номинальная скорость ДС2 (мм/с)
	{&fEM_A8UC10RIM,8,68},	//( - , SCM) Координата нижних механических упоров ДС2 мм
	{&fEM_A8UC11RIM,8,70},	//( - , SCM) Координата нижнего путевого выключателя ДС2 мм
	{&fEM_A8UC20RIM,8,72},	//( - , SCM) Координата верхних механических упоров ДС2 мм
	{&fEM_A8UC21RIM,8,74},	//( - , SCM) Координата верхнего путевого выключателя ДС2 мм
	{&fEM_A6UC10RIM,8,76},	//( - , SCM) Время полного хода БЗ (сек)
	{&fEM_R1UC10RIM,8,78},	//( - , SCM) Время полного хода МДЗ сек
	{&fEM_A5UC10RIM,8,80},	//( - , SCM) Время полного хода НЛ сек
	{&fEM_A0UN01RIM,8,82},	//( - , SCM) Мощность источника нейтронов ИНИ
	{&fEM_R4UC22RIM,8,84},	//( - , SCM) Смещение координаты АЗ от координаты тележки
	{&fEM_A1UG01RDU,8,86},	//( - , SCM) Расстояние включения масляного демпфера ББ(мм)
	{&fEM_A2UG01RDU,8,88},	//( - , SCM) Расстояние включения масляного демпфера РБ
	{&fEM_A3UG01RDU,8,90},	//( - , SCM) Расстояние включения масляного демпфера ИС
	{&fEM_R7UC10RIM,8,92},	//( - , SCM) X-координата КНК53М R7IN13 см
	{&fEM_R7UC19RIM,8,94},	//( - , SCM) Y-координата СНМ-11 (11) см
	{&fEM_R7UI02RIM,8,96},	//( - , SCM) Коэффициент усиления уровня радиации
	{&fEM_R7UL01RIM,8,98},	//( - , SCM) Постоянная времени изменения уровня радиации в зале
	{&fEM_A2UR00RIM,8,100},	//( - , SCM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{&fEM_A2UR01RIM,8,102},	//( - , SCM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{&fEM_A0UN02RIM,8,104},	//( - , SCM) Мощность источника нейтронов с АНИ
	{&fEM_R0UR30RIM,8,106},	//( - , SCM) Реактивность вносимая образцами (долл)
	{&fEM_R0UR01RIM,8,108},	//( - , SCM) Стартовая отрицательная реактивность
	{&fEM_R0UT02RDU,8,110},	//( - , SCM) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RDU,8,112},	//( - , SCM) Нижний предел шкалы датчика температуры
	{&fEM_A1UC03RDU,8,114},	//( - , SCM) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{&fEM_A2UP03RDU,8,116},	//( - , SCM) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UP04RDU,8,118},	//( - , SCM) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UC03RDU,8,120},	//( - , SCM) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{&fEM_A3UP03RDU,8,122},	//( - , SCM) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UP04RDU,8,124},	//( - , SCM) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UC03RDU,8,126},	//( - , SCM) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{&fEM_R7UI74RIM,8,128},	//( - , SCM) Верхняя граница измерения уровня радиации в зале
	{&fEM_A8UC03RDU,8,130},	//( - , SCM) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{&fEM_R0UV87RDU,8,132},	//( - , SCM) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV81RDU,8,134},	//( - , SCM) 1-я частота двигателя (шагов/секунду)
	{&fEM_R0UV82RDU,8,136},	//( - , SCM) 3-я частота двигателя (шагов/секунду)
	{&fEM_R0UV83RDU,8,138},	//( - , SCM) 4-я частота двигателя (шагов/секунду)
	{&fEM_R0UV84RDU,8,140},	//( - , SCM) 5-я частота двигателя (шагов/секунду)
	{&fEM_R0UV85RDU,8,142},	//( - , SCM) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV86RDU,8,144},	//( - , SCM) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_A8UC08RDU,8,146},	//( - , SCM) Зона срабатывания КВ ДС2(мм)
	{&fEM_B8UC08RDU,8,148},	//( - , SCM) Зона срабатывания КВ АЗ2(мм)
	{&fEM_R4UC08RDU,8,150},	//( - , SCM) Зона срабатывания КВ тележки РУ(мм)
	{&fEM_R0UH01RSS,8,152},	//( - , SCM) Коэфф. преобразования частота->нейтр/с  СНМ11
	{&fEM_A0UX00RSS,8,154},	//( - , SCM) Эффективный радиус АЗ
	{&fEM_R7UX01RSS,8,156},	//( - , SCM) X-координата камеры R7IN11
	{&fEM_R7UX02RSS,8,158},	//( - , SCM) X-координата камеры R7IN12 (см)
	{&fEM_R7UX04RSS,8,160},	//( - , SCM) X-координата камеры R7IN21 (см)
	{&fEM_R7UX05RSS,8,162},	//( - , SCM) X-координата камеры R7IN22 (см)
	{&fEM_R7UX06RSS,8,164},	//( - , SCM) X-координата камеры R7IN23 (см)
	{&fEM_R7UX07RSS,8,166},	//( - , SCM) X-координата камеры R7IN31 (см)
	{&fEM_R7UX08RSS,8,168},	//( - , SCM) X-координата камеры R7IN32 (см)
	{&fEM_R7UX09RSS,8,170},	//( - , SCM) X-координата камеры R7IN33 (см)
	{&fEM_R7UY01RSS,8,172},	//( - , SCM) Y-координата камеры R7IN11
	{&fEM_R7UY02RSS,8,174},	//( - , SCM) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY04RSS,8,176},	//( - , SCM) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY05RSS,8,178},	//( - , SCM) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY06RSS,8,180},	//( - , SCM) Y-координата камеры R7IN23 (см)
	{&fEM_R7UY07RSS,8,182},	//( - , SCM) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY08RSS,8,184},	//( - , SCM) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY09RSS,8,186},	//( - , SCM) Y-координата камеры R7IN33 (см)
	{&fEM_R7UX10RSS,8,188},	//( - , SCM) X-координата камеры R7IN41
	{&fEM_R7UX11RSS,8,190},	//( - , SCM) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,192},	//( - , SCM) X-координата камеры R7IN43
	{&fEM_R7UY10RSS,8,194},	//( - , SCM) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,196},	//( - , SCM) Y-координата камеры R7IN42
	{&fEM_R7UY12RSS,8,198},	//( - , SCM) Y-координата камеры R7IN43
	{&fEM_A0UX01RSS,8,200},	//( - , SCM) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX02RSS,8,202},	//( - , SCM) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX03RSS,8,204},	//( - , SCM) Первый коэффициент калибровки камеры 3
	{&fEM_A0UX04RSS,8,206},	//( - , SCM) Первый коэффициент калибровки камеры4
	{&fEM_A0UX05RSS,8,208},	//( - , SCM) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX06RSS,8,210},	//( - , SCM) Первый коэффициент калибровки камеры 6
	{&fEM_A0UX07RSS,8,212},	//( - , SCM) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX08RSS,8,214},	//( - , SCM) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX09RSS,8,216},	//( - , SCM) Первый коэффициент калибровки камеры 9
	{&fEM_A0UX10RSS,8,218},	//( - , SCM) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX11RSS,8,220},	//( - , SCM) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX12RSS,8,222},	//( - , SCM) Первый коэффициент калибровки камеры 12
	{&fEM_B0UX01RSS,8,224},	//( - , SCM) Второй коэффициент калибровки камеры 1
	{&fEM_B0UX02RSS,8,226},	//( - , SCM) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX03RSS,8,228},	//( - , SCM) Второй коэффициент калибровки камеры 3
	{&fEM_B0UX04RSS,8,230},	//( - , SCM) Второй коэффициент калибровки камеры 4
	{&fEM_B0UX05RSS,8,232},	//( - , SCM) Второй коэффициент калибровки камеры 5
	{&fEM_B0UX06RSS,8,234},	//( - , SCM) Второй коэффициент калибровки камеры 6
	{&fEM_B0UX07RSS,8,236},	//( - , SCM) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX08RSS,8,238},	//( - , SCM) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX09RSS,8,240},	//( - , SCM) Второй коэффициент калибровки камеры 9
	{&fEM_B0UX10RSS,8,242},	//( - , SCM) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX11RSS,8,244},	//( - , SCM) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX12RSS,8,246},	//( - , SCM) Второй коэффициент калибровки камеры 12
	{&fEM_R0UH02RSS,8,248},	//( - , SCM) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{&fEM_R0UH03RSS,8,250},	//( - , SCM) Коэфф. преобразования частота->нейтр/с  КНК53М
	{&fEM_R4US80RDU,8,252},	//( - , SCM) Тормозной путь тележки (мм)
	{&fEM_R7UI71RIM,8,254},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{&fEM_R7UI72RIM,8,256},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{&fEM_R7UI73RIM,8,258},	//( - , SCM) Уровень мощности срабатывания АС II УР  ватт
	{&fEM_A1UP01RIM,8,260},	//( - , SCM) Текущее давление на сброс ББ (МПа)
	{&fEM_A2UP01RIM,8,262},	//( - , SCM) Текущее давление на сброс РБ
	{&fEM_A0UP02RIM,8,264},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP01RIM,8,266},	//( - , SCM) Текущее давление на СПУСК ИС
	{&fEM_A1UP82RIM,8,268},	//( - , SCM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{&fEM_A3UP02RDU,8,270},	//( - , SCM) Текущее давление ВЫСТРЕЛ ИС
	{&fEM_A1UV02RIM,8,272},	//( - , SCM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{&fEM_A3UV02RIM,8,274},	//( - , SCM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{&fEM_A2UV02RIM,8,276},	//( - , SCM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{&fEM_B8US80RDU,8,278},	//( - , SCM) Тормозной путь АЗ2 (мм)
	{&fEM_A8US80RDU,8,280},	//( - , SCM) Тормозной путь ДС2 (мм)
	{&fEM_A6US80RDU,8,282},	//( - , SCM) Тормозной путь БЗ (мм)
	{&fEM_A1US07RDU,8,284},	//( - , SCM) Постоянная времени масляного демпфера ББ
	{&fEM_A2US07RDU,8,286},	//( - , SCM) Постоянная времени масляного демпфера РБ
	{&fEM_A3US07RDU,8,288},	//( - , SCM) Постоянная времени масляного демпфера ИС
	{&fEM_R7UI75RIM,8,290},	//( - , SCM) Множитель к уровню радиации
	{&fEM_R0UH21RSS,8,292},	//( - , SCM) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{&fEM_R0UH22RSS,8,294},	//( - , SCM) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{&fEM_R0UH23RSS,8,296},	//( - , SCM) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{&fEM_R0UH05RSS,8,298},	//( - , SCM) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_A4UL10RIM,8,300},	//( - , SCM) Время полного перемещения НИ сек
	{&fEM_A9UL10RIM,8,302},	//( - , SCM) Время полного перемещения НИ ДС1/ДС2 сек
	{&fEM_R3UL10RIM,8,304},	//( - , SCM) Время полного хода гомогенных дверей (сек)
	{&fEM_R5UL10RIM,8,306},	//( - , SCM) Время полного хода ворот отстойной зоны (дес. мс)
	{&fEM_R6UL10RIM,8,308},	//( - , SCM) Время полного хода кран-балки сек
	{&fEM_A2UP02RIM,8,310},	//( - , SCM) Текущее давление на подъём РБ
	{&fEM_A2UP03RIM,8,312},	//( - , SCM) Нижняя граница давления на ПОДЪЁМ РБ
	{&fEM_A0UP01RIM,8,314},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP02RIM,8,316},	//( - , SCM) Нижняя граница  давления на СПУСК ИС
	{&fEM_A4UP01RIM,8,318},	//( - , SCM) Текущее давление на подъём НИ
	{&fEM_A4UP02RIM,8,320},	//( - , SCM) Нижняя граница давления на подъём НИ
	{&fEM_R7UI76RIM,8,322},	//( - , SCM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{&fEM_R7UI77RIM,8,324},	//( - , SCM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{&iEM_TERBB1,3,326},	//( - , SCM) Неисправности  ББ1
	{&fEM_A1MC02RC1,8,327},	//( - , SCM) Заданная координата штока ББ1 от ИС
	{&fEM_A1MV02RC1,8,329},	//( - , SCM) Заданная скорость движения  штока ББ1 от ИС
	{&iEM_TERBB2,3,331},	//( - , SCM) Неисправности  ББ2
	{&fEM_B1MC02RC1,8,332},	//( - , SCM) Заданная координата штока ББ2 от ИС
	{&fEM_B1MV02RC1,8,334},	//( - , SCM) Заданная скорость движения штока ББ2 от ИС
	{&iEM_TERRB2,3,336},	//( - , SCM) Неисправности  РБ2
	{&fEM_B2MC02RC1,8,337},	//( - , SCM) Заданная координата штока РБ2 от ИС
	{&fEM_B2MV02RC1,8,339},	//( - , SCM) Заданная скорость движения штока РБ2 от ИС
	{&iEM_TERRB1,3,341},	//( - , SCM) Неисправности  РБ1
	{&fEM_A2MC02RC1,8,342},	//( - , SCM) Заданная координата штока РБ1 от ИС
	{&fEM_A2MV02RC1,8,344},	//( - , SCM) Заданная скорость движения штока РБ1 от ИС
	{&iEM_TERIS2,3,346},	//( - , SCM) Неисправности  ИС2
	{&fEM_B3MC02RC1,8,347},	//( - , SCM) Заданная координата штока ИС2 от ИС
	{&fEM_B3MV02RC1,8,349},	//( - , SCM) Заданная скорость движения штока ИС2 от ИС
	{&iEM_TERIS1,3,351},	//( - , SCM) Неисправности  ИС1
	{&fEM_A3MC02RC1,8,352},	//( - , SCM) Заданная координата штока ИС1 от ИС
	{&fEM_A3MV02RC1,8,354},	//( - , SCM) Заданная скорость движения штока ИС1 от ИС
	{&iEM_TERA1IE04LDU,3,356},	//( - , SCM) Искажение Движение ББ1 назад (от БУШД)
	{&iEM_TERA1IE03LDU,3,357},	//( - , SCM) Искажение Движение ББ1 вперёд (от БУШД)
	{&fEM_A1MC01RC1,8,358},	//( - , SCM) Заданная координата  ББ1 от ИС
	{&iEM_TERB1IE03LDU,3,360},	//( - , SCM) Искажение Движение ББ2 вперёд (от БУШД)
	{&iEM_TERB1IE04LDU,3,361},	//( - , SCM) Искажение Движение ББ2 назад (от БУШД)
	{&fEM_B1MC01RC1,8,362},	//( - , SCM) Заданная координата ББ2 от ИС
	{&fEM_B1MV01RC1,8,364},	//( - , SCM) Заданная скорость движения ББ2 от ИС
	{&fEM_B2MC01RC1,8,366},	//( - , SCM) Заданная координата РБ2 от ИС
	{&fEM_B2MV01RC1,8,368},	//( - , SCM) Заданная скорость движения  РБ2 от ИС
	{&fEM_A3MC01RC1,8,370},	//( - , SCM) Заданная координата ИС1 от ИС
	{&fEM_A3MV01RC1,8,372},	//( - , SCM) Заданная скорость движения ИС1 от ИС
	{&fEM_B3MC01RC1,8,374},	//( - , SCM) Заданная координата ИС2 от ИС
	{&fEM_B3MV01RC1,8,376},	//( - , SCM) Заданная скорость движения ИС2 от ИС
	{&iEM_TERA2SS21LIM,3,378},	//( - , SCM) Искажение: Приход на НУ РБ1
	{&iEM_TERA2SS12LIM,3,379},	//( - , SCM) Искажение: Магнит РБ1 зацеплен
	{&iEM_TERR6SS21LIM,3,380},	//( - , SCM) Искажение: Кран-балка в нерабочем положении
	{&iEM_TERA2VP82LIM,3,381},	//( - , SCM) Искажение: Текущее давление на подъём РБ  в норме
	{&iEM_TERA2SS11LIM,3,382},	//( - , SCM) Искажение: Приход на ВУ РБ1
	{&iEM_TERB3SS21LIM,3,383},	//( - , SCM) Искажение: Приход на НУ ИС2
	{&iEM_TERA0MT01RIM,3,384},	//( - , SCM) Искажение: Текущая температура AЗ1
	{&iEM_TERB0MT01RIM,3,385},	//( - , SCM) Искажение: Текущая температура AЗ2
	{&iEM_TERA2SP01RIM,3,386},	//( - , SCM) Искажение: Текущее давление СБРОС РБ1
	{&iEM_TERB2SP01RIM,3,387},	//( - , SCM) Искажение: Текущее давление СБРОС РБ2
	{&iEM_TERB3SP02RIM,3,388},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{&iEM_TERA3SC01RIM,3,389},	//( - , SCM) Искажение: Координата штока ИС1
	{&iEM_TERA3VP81LIM,3,390},	//( - , SCM) Искажение: Текущее давление СПУСК ИС  в норме
	{&iEM_TERA2SC01RIM,3,391},	//( - , SCM) Искажение: Координата штока РБ1
	{&iEM_TERA2SS33LIM,3,392},	//( - , SCM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{&iEM_TERA3SS21LIM,3,393},	//( - , SCM) Искажение: Приход на НУ ИС1
	{&iEM_TERA3SS33LIM,3,394},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{&iEM_TERA3SS31LIM,3,395},	//( - , SCM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{&iEM_TERB3SS31LIM,3,396},	//( - , SCM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{&iEM_TERB3SS33LIM,3,397},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{&iEM_TERB3SC01RIM,3,398},	//( - , SCM) Искажение: Координата штока ИС2
	{&iEM_TERA3SS11LIM,3,399},	//( - , SCM) Искажение: Приход на ВУ ИС1
	{&iEM_TERB3SS11LIM,3,400},	//( - , SCM) Искажение: Приход на ВУ ИС2
	{&iEM_TERR6IS64LIM,3,401},	//( - , SCM) Искажение: Исправность ВИП ССДИ-35
	{&iEM_TERB3SS22LIM,3,402},	//( - , SCM) Искажение: Приход на НУП ИС2
	{&iEM_TERA3SS22LIM,3,403},	//( - , SCM) Искажение: Приход на НУП ИС1
	{&iEM_TERA3SP02RIM,3,404},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{&iEM_TERR6IS62LIM,3,405},	//( - , SCM) Искажение Исправность ВИП ССДИ-39
	{&iEM_TERR6IS66LIM,3,406},	//( - , SCM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&iEM_TERR6IS67LIM,3,407},	//( - , SCM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&iEM_TERA0VP81LIM,3,408},	//( - , SCM) Искажение: Давление  АЗ1  в норме
	{&iEM_TERB0VP81LIM,3,409},	//( - , SCM) Искажение: Давление  АЗ2 в норме
	{&iEM_TERR0VP81LIM,3,410},	//( - , SCM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{&iEM_TERR6IS68LIM,3,411},	//( - , SCM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{&iEM_TERR7SI74RIM,3,412},	//( - , SCM) Искажение: Радиация в реакторном зале
	{&iEM_TERA5SS21LIM,3,413},	//( - , SCM) Искажение: Приход на НУ НЛ1
	{&iEM_TERB5SS11LIM,3,414},	//( - , SCM) Искажение: Приход на ВУ НЛ2
	{&iEM_TERA5SS11LIM,3,415},	//( - , SCM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{&iEM_TERA9SS11LIM,3,416},	//( - , SCM) Искажение: Приход на ВУ НИ ДС1
	{&iEM_TERB2SS11LIM,3,417},	//( - , SCM) Искажение: Приход на ВУ РБ2
	{&iEM_TERB2SS12LIM,3,418},	//( - , SCM) Искажение: Магнит РБ2 зацеплен
	{&iEM_TERB2SS21LIM,3,419},	//( - , SCM) Искажение: Приход на НУ РБ2
	{&iEM_TERR3SS11LIM,3,420},	//( - , SCM) Искажение: Приход на ВУ гомогенных дверей-1
	{&iEM_TERB2SC01RIM,3,421},	//( - , SCM) Искажение: Координата штока РБ2
	{&iEM_TERR3SS21LIM,3,422},	//( - , SCM) Искажение: Приход на НУ гомогенных дверей-1
	{&iEM_TERR5SS11LIM,3,423},	//( - , SCM) Искажение: Приход на ВУ ворот отстойной зоны
	{&iEM_TERA4SS11LIM,3,424},	//( - , SCM) Искажение: Приход на ВУ НИ1
	{&iEM_TERR1SS11LIM,3,425},	//( - , SCM) Искажение: Приход на ВУ МДЗ1
	{&iEM_TERR1SS21LIM,3,426},	//( - , SCM) Искажение: Приход на НУ МДЗ1
	{&iEM_TERR2SS11LIM,3,427},	//( - , SCM) Искажение: Приход на ВУ МДЗ2
	{&iEM_TERR2SS21LIM,3,428},	//( - , SCM) Искажение: Приход на НУ МДЗ2
	{&iEM_TERA4VP82LIM,3,429},	//( - , SCM) Искажение Давление ПОДЪЁМ НИ в норме
	{&iEM_TERB4SS21LIM,3,430},	//( - , SCM) Искажение: Приход на НУ НИ2
	{&iEM_TERR5SS21LIM,3,431},	//( - , SCM) Искажение: Приход на НУ ворот отстойной зоны
	{&iEM_TERB6SS21LIM,3,432},	//( - , SCM) Искажение: Приход на НУ БЗ2
	{&iEM_TERB4SS11LIM,3,433},	//( - , SCM) Искажение: Приход на ВУ НИ2
	{&iEM_TERA4SS21LIM,3,434},	//( - , SCM) Искажение: Приход на НУ НИ1
	{&iEM_TERA6MS11LIM,3,435},	//( - , SCM) Искажение: Приход на ВУ БЗ1
	{&iEM_TERA6SS21LIM,3,436},	//( - , SCM) Искажение: Приход на НУ БЗ1
	{&iEM_TERB6SS11LIM,3,437},	//( - , SCM) Искажение: Приход на ВУ БЗ2
	{&iEM_TERR4SS11LIM,3,438},	//( - , SCM) Искажение: Приход на ВУ тележки
	{&iEM_TERR4MS21LIM,3,439},	//( - , SCM) Искажение: Приход на НУ тележки
	{&iEM_TERR4SS12LIM,3,440},	//( - , SCM) Искажение: Приход на механический ВУ тележки
	{&iEM_TERR4SS22LIM,3,441},	//( - , SCM) Искажение: Приход на механический НУ тележки
	{&iEM_TERR8SS11LIM,3,442},	//( - , SCM) Искажение: Аварийный НИ установлен
	{&iEM_TERB8SC01RIM,3,443},	//( - , SCM) Искажение: Координата АЗ2
	{&iEM_TERA8SC01RIM,3,444},	//( - , SCM) Искажение: Координата ДС2
	{&iEM_TERB8SS12LIM,3,445},	//( - , SCM) Искажение: Приход на механический ВУ АЗ2
	{&iEM_TERA8SS12LIM,3,446},	//( - , SCM) Искажение: Приход на механический ВУ ДС2
	{&iEM_TERB8SS22LIM,3,447},	//( - , SCM) Искажение: Приход на механический НУ АЗ2
	{&iEM_TERA8SS22LIM,3,448},	//( - , SCM) Искажение: Приход на механический НУ ДС2
	{&iEM_TERA9SS21LIM,3,449},	//( - , SCM) Искажение: Приход на НУ НИ ДС1
	{&iEM_TERB9SS21LIM,3,450},	//( - , SCM) Искажение: Приход на НУ НИ ДС2
	{&iEM_TERB9SS11LIM,3,451},	//( - , SCM) Искажение: Приход на ВУ НИ ДС2
	{&iEM_TERB5SS21LIM,3,452},	//( - , SCM) Искажение: Приход на НУ НЛ2
	{&iEM_TERA1SS21LIM,3,453},	//( - , SCM) Искажение: Приход на НУ ББ1
	{&iEM_TERA1SS11LIM,3,454},	//( - , SCM) Искажение: Приход на ВУ ББ1
	{&iEM_TERA1SC01RIM,3,455},	//( - , SCM) Искажение: Координата штока ББ1
	{&iEM_TERA1SS12LIM,3,456},	//( - , SCM) Искажение: Магнит ББ1 зацеплен
	{&iEM_TERB1SS21LIM,3,457},	//( - , SCM) Искажение: Приход на НУ ББ2
	{&iEM_TERB1SS11LIM,3,458},	//( - , SCM) Искажение:Приход на ВУ ББ2
	{&iEM_TERB1MC01RIM,3,459},	//( - , SCM) Искажение: Координата штока ББ2
	{&iEM_TERB1SS12LIM,3,460},	//( - , SCM) Искажение: Магнит ББ2 зацеплен
	{&iEM_TERTLG,3,461},	//( - , SCM) Неисправности  тележки от ИС
	{&fEM_R4MC01RC1,8,462},	//( - , SCM) Заданная координата тележки от ИС
	{&fEM_R4MV01RC1,8,464},	//( - , SCM) Заданная скорость тележки от ИС
	{&iEM_TERMAZ2,3,466},	//( - , SCM) Неисправности АЗ2 от ИС
	{&fEM_B8MV01RC1,8,467},	//( - , SCM) Заданная скорость АЗ2 от ИС
	{&iEM_TERDS2,3,469},	//( - , SCM) Неисправности ДС2 от ИС
	{&fEM_A8MC01RC1,8,470},	//( - , SCM) Заданная координата ДС2 от ИС
	{&fEM_A8MV01RC1,8,472},	//( - , SCM) Заданная скорость ДС2 от ИС
	{&iEM_TERBZ1,3,474},	//( - , SCM) Неисправности БЗ1
	{&fEM_A6MC01RC1,8,475},	//( - , SCM) Заданная координата БЗ1 от ИС
	{&fEM_A6MV01RC1,8,477},	//( - , SCM) Заданная скорость БЗ1 от ИС
	{&iEM_TERBZ2,3,479},	//( - , SCM) Неисправности БЗ2
	{&fEM_B6MC01RC1,8,480},	//( - , SCM) Заданная координата БЗ2 от ИС
	{&fEM_B6MV01RC1,8,482},	//( - , SCM) Заданная скорость БЗ2 от ИС
	{&iEM_TERMDZ2,3,484},	//( - , SCM) Неисправности МДЗ2
	{&fEM_R2MC01RC1,8,485},	//( - , SCM) Заданная координата МДЗ2 от ИС
	{&fEM_R2MV01RC1,8,487},	//( - , SCM) Заданная скорость МДЗ2 от ИС
	{&iEM_TERMDZ1,3,489},	//( - , SCM) Неисправности МДЗ1
	{&fEM_R1MC01RC1,8,490},	//( - , SCM) Заданная координата МДЗ1 от ИС
	{&fEM_R1MV01RC1,8,492},	//( - , SCM) Заданная скорость МДЗ1 от ИС
	{&iEM_TERNL1,3,494},	//( - , SCM) Неисправности НЛ1
	{&fEM_A5MC01RC1,8,495},	//( - , SCM) Заданная координата НЛ1 от ИС
	{&fEM_A5MV01RC1,8,497},	//( - , SCM) Заданная скорость НЛ1 от ИС
	{&iEM_TERNL2,3,499},	//( - , SCM) Неисправности НЛ2
	{&fEM_B5MC01RC1,8,500},	//( - , SCM) Заданная координата НЛ2 от ИС
	{&fEM_B5MV01RC1,8,502},	//( - , SCM) Заданная скорость НЛ2 от ИС
	{&fEM_A1UC08RIM,8,504},	//( - , SCM) Зона срабатывания КВ ББ(мм)
	{&fEM_A2UC08RIM,8,506},	//( - , SCM) Зона срабатывания КВ  РБ мм
	{&fEM_A3UC08RIM,8,508},	//( - , SCM) Зона срабатывания КВ ИС(мм)
	{&iEM_TERB2SS33LIM,3,510},	//( - , SCM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{&iEM_TERA1VP81LIM,3,511},	//( - , SCM) Искажение: Текущее давление СБРОС ББ1  в норме
	{&iEM_TERB1VP81LIM,3,512},	//( - , SCM) Искажение: Текущее давление СБРОС ББ2  в норме
	{&fEM_A0UT03RSP,8,513},	//( - , SCM) Стартовая  температура АЗ1 град
	{&fEM_A0UR01RSP,8,515},	//( - , SCM) Стартовая  реактивность АЗ1
	{&fEM_A0UR02RSP,8,517},	//( - , SCM) Стартовый  поток нейтронов АЗ1
	{&fEM_B0UT03RSP,8,519},	//( - , SCM) Стартовая  температура АЗ2 град
	{&fEM_A1MC01RSP,8,521},	//( - , SCM) Стартовая координата  ББ1
	{&fEM_A1MC02RSP,8,523},	//( - , SCM) Стартовая координата штока ББ1
	{&fEM_B1MC01RSP,8,525},	//( - , SCM) Стартовая координата  ББ2
	{&fEM_B1MC02RSP,8,527},	//( - , SCM) Стартовая координата штока ББ2
	{&fEM_A2MC01RC1,8,529},	//( - , SCM) Заданная координата РБ1 от ИС
	{&fEM_A2MV01RC1,8,531},	//( - , SCM) Заданная скорость движения РБ1 от ИС
	{&fEM_A2MC01RSP,8,533},	//( - , SCM) Стартовая координата  РБ1
	{&fEM_A2MC02RSP,8,535},	//( - , SCM) Стартовая координата штока РБ1
	{&fEM_B2MC01RSP,8,537},	//( - , SCM) Стартовая координата  РБ2
	{&fEM_B2MC02RSP,8,539},	//( - , SCM) Стартовая координата штока РБ2
	{&fEM_A3MC01RSP,8,541},	//( - , SCM) Стартовая координата  ИС1
	{&fEM_A3MC02RSP,8,543},	//( - , SCM) Стартовая координата штока ИС1
	{&fEM_B3MC01RSP,8,545},	//( - , SCM) Стартовая координата  ИС2
	{&fEM_B3MC02RSP,8,547},	//( - , SCM) Стартовая координата штока ИС2
	{&fEM_B8MC01RSP,8,549},	//( - , SCM) Стартовая координата АЗ2
	{&fEM_A8MC01RSP,8,551},	//( - , SCM) Стартовая координата ДС2
	{&fEM_A6MC01RSP,8,553},	//( - , SCM) Стартовая координата БЗ1
	{&fEM_B6MC01RSP,8,555},	//( - , SCM) Стартовая координата БЗ2
	{&fEM_R3UC01RSP,8,557},	//( - , SCM) Стартовая координата Гомогенных дверей
	{&fEM_R5UC01RSP,8,559},	//( - , SCM) Стартовая координата Ворот отстойной зоны
	{&fEM_R6UC01RSP,8,561},	//( - , SCM) Стартовая координата Кран-балки
	{&fEM_R2MC01RSP,8,563},	//( - , SCM) Стартовая координата МДЗ2
	{&fEM_R1MC01RSP,8,565},	//( - , SCM) Стартовая координата МДЗ1
	{&fEM_A5MC01RSP,8,567},	//( - , SCM) Стартовая координата НЛ1
	{&fEM_B5MC01RSP,8,569},	//( - , SCM) Стартовая координата НЛ2
	{&fEM_A9MC01RSP,8,571},	//( - , SCM) Стартовая координата НИ ДС1
	{&fEM_B9MC01RSP,8,573},	//( - , SCM) Стартовая координата НИ ДС2
	{&fEM_A4MC01RSP,8,575},	//( - , SCM) Стартовая координата НИ1
	{&fEM_B4MC01RSP,8,577},	//( - , SCM) Стартовая координата НИ2
	{&fEM_R4MC01RSP,8,579},	//( - , SCM) Стартовая координата тележки
	{&fEM_A1MV01RC1,8,581},	//( - , SCM) Заданная скорость движения  ББ1 от ИС
	{&iEM_TERB7MS31LIM,3,583},	//( - , SCM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{&iEM_TERA7MS31LIM,3,584},	//( - , SCM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{&fEM_R7UY00RSS,8,585},	//( - , SCM) Y-координата АЗ1 см
	{&iEM_TERA6VS12LIM,3,587},	//( - , SCM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{&iEM_TERA6VS22LIM,3,588},	//( - , SCM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{&iEM_TERB6VS12LIM,3,589},	//( - , SCM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{&iEM_TERB6VS22LIM,3,590},	//( - , SCM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{&iEM_TERA5VS22LIM,3,591},	//( - , SCM) Искажение: Движение створок НЛ1 к НУ
	{&iEM_TERA5VS12LIM,3,592},	//( - , SCM) Искажение: Движение створок НЛ1 к ВУ
	{&iEM_TERB5VS12LIM,3,593},	//( - , SCM) Искажение: Движение створок НЛ2 к ВУ
	{&iEM_TERB5VS22LIM,3,594},	//( - , SCM) Искажение: Движение створок НЛ2 к НУ
	{&iEM_TERR1VS12LIM,3,595},	//( - , SCM) Искажение: Движение МДЗ1 в сторону ВУ
	{&iEM_TERR1VS22LIM,3,596},	//( - , SCM) Искажение: Движение МДЗ1 в сторону НУ
	{&iEM_TERR2VS12LIM,3,597},	//( - , SCM) Искажение: Движение МДЗ2 в сторону ВУ
	{&iEM_TERR2VS22LIM,3,598},	//( - , SCM) Искажение: Движение МДЗ2 в сторону НУ
	{&iEM_TERR4VS12LDU,3,599},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&iEM_TERR4VS22LDU,3,600},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&fEM_A0UX13RSS,8,601},	//( - , SCM) Первый коэффициент калибровки камеры 13
	{&fEM_A0UX14RSS,8,603},	//( - , SCM) Первый коэффициент калибровки камеры 14
	{&fEM_A0UX15RSS,8,605},	//( - , SCM) Первый коэффициент калибровки камеры 15
	{&fEM_R7UX13RSS,8,607},	//( - , SCM) X-координата камеры R7IN51
	{&fEM_R7UX14RSS,8,609},	//( - , SCM) X-координата камеры R7IN52
	{&fEM_R7UX15RSS,8,611},	//( - , SCM) X-координата камеры R7IN53
	{&fEM_R7UY13RSS,8,613},	//( - , SCM) Y-координата камеры R7IN51
	{&fEM_R7UY14RSS,8,615},	//( - , SCM) Y-координата камеры R7IN52
	{&fEM_R7UY15RSS,8,617},	//( - , SCM) Y-координата камеры R7IN53
	{&fEM_R7UX16RSS,8,619},	//( - , SCM) Величина сигнала СНМ11 в БЗ
	{&fEM_B8MC01RC1,8,621},	//( - , SCM) Заданная координата АЗ2 от ИС
	{&fEM_A0UN07RIM,8,623},	//( - , SCM) Доля запаздывающих нейтронов
	{&fEM_R0UL02RIM,8,625},	//( - , SCM) Время удержания синхроимпульса
	{&fEM_R0UL04RDU,8,627},	//( - , SCM) Время блокировки повторной генерации импульса
	{&fEM_R0UL02RDU,8,629},	//( - , SCM) Время задержки  ИНИ
	{&fEM_R0UL03RDU,8,631},	//( - , SCM) Максимальное время цикла, сек
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz1[]={  // 
	{&R0EE01LZ1,1,0},	//( - , SBz1) Питание  АКНП1  отключить
	{&R0EE02LZ1,1,1},	//( - , SBz1) Питание  АКНП  отключить
	{&R0EE03LZ1,1,2},	//( - , SBz1) Питание  АКНП3  отключить
	{&R0EE04LZ1,1,3},	//( - , SBz1) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SBz2[]={  // 
	{&R0EE01LZ2,1,0},	//( - , SBz2) Питание  АКНП1  отключить
	{&R0EE02LZ2,1,1},	//( - , SBz2) Питание  АКНП  отключить
	{&R0EE03LZ2,1,2},	//( - , SBz2) Питание  АКНП3  отключить
	{&R0EE04LZ2,1,3},	//( - , SBz2) Питание  АКНП4  отключить
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SBz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SBz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SBz2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SDu[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SDu[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SDu[]={  // 
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
static ModbusRegister hr_SDu[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA1[]={  // 
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA1[]={  // 
	{&R0IN01FI1,8,0},	//( - , SA1) Выход СНМ11 Гц от ПТИ
	{&R0IN02FI1,8,2},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI1,8,4},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{&ttlAknp1,8,6},	//( - , SA1) 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA1[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA2[]={  // 
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA2[]={  // 
	{&R0IN01FI2,8,0},	//( - , SA2) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI2,8,2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI2,8,4},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA2[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA3[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA3[]={  // 
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA3[]={  // 
	{&R0IN01FI3,8,0},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI3,8,2},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI3,8,4},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA3[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SA4[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SA4[]={  // 
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA4[]={  // 
	{&R0IN01FI4,8,0},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI4,8,2},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI4,8,4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SA4[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister coil_SRP[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister di_SRP[]={  // 
	{&R0IS01FI0,1,0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SRP[]={  // 
	{&R0IN01RIP,8,0},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{&R0IN02RIP,8,2},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{&R0IN03RIP,8,4},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{&R0IN06RIP,8,6},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{&R0IN07RIP,8,8},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister hr_SRP[]={  // 
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusDevice modbuses[]={
	{0,5002,&coil_SCM[0],&di_SCM[0],&ir_SCM[0],&hr_SCM[0],NULL,NULL,NULL,0},	 //Общий слэйв
	{0,5003,&coil_SBz1[0],&di_SBz1[0],&ir_SBz1[0],&hr_SBz1[0],NULL,NULL,NULL,0},	 //Cлэйв Baz1
	{0,5004,&coil_SBz2[0],&di_SBz2[0],&ir_SBz2[0],&hr_SBz2[0],NULL,NULL,NULL,0},	 //Cлэйв Baz2
	{0,5005,&coil_SDu[0],&di_SDu[0],&ir_SDu[0],&hr_SDu[0],NULL,NULL,NULL,0},	 //Cлэйв DU
	{0,5006,&coil_SA1[0],&di_SA1[0],&ir_SA1[0],&hr_SA1[0],NULL,NULL,NULL,0},	 //Cлэйв AKNP1
	{0,5007,&coil_SA2[0],&di_SA2[0],&ir_SA2[0],&hr_SA2[0],NULL,NULL,NULL,0},	 //Cлэйв AKNP2
	{0,5008,&coil_SA3[0],&di_SA3[0],&ir_SA3[0],&hr_SA3[0],NULL,NULL,NULL,0},	 //Cлэйв AKNP3
	{0,5009,&coil_SA4[0],&di_SA4[0],&ir_SA4[0],&hr_SA4[0],NULL,NULL,NULL,0},	 //Cлэйв AKNP4
	{0,5010,&coil_SRP[0],&di_SRP[0],&ir_SRP[0],&hr_SRP[0],NULL,NULL,NULL,0},	 //Cлэйв RPU

	{0,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0},};
#pragma pop
#include <drivers/ao16.h>
static char buf_AO1601[127];	//AO16
static ao16_inimod ini_AO1601={0xffff,120,0x43,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_AO1601={0,0,&ini_AO1601,buf_AO1601,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_AO1601[]={
	{&B2IP01IZ1,3,9},
	{&B2IP01IZ2,3,21},
	{&B3IP02IDU,3,27},
	{&A0IT03IRP,3,30},
	{&B0IT03IRP,3,33},
	{&A3IP02IDU,3,24},
	{&A2IP01IZ2,3,15},
	{&A0IT01IZ1,3,0},
	{&A0IT02IZ2,3,12},
	{&B0IT01IZ1,3,6},
	{&B0IT02IZ2,3,18},
	{&A2IP01IZ1,3,3},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F01[137];	//do32_5f(0x100)
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
static char buf_DO32_5F02[137];	//do32_5f(0x110)
static do32_pti_inipar ini_DO32_5F02={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F02={0,0,&ini_DO32_5F02,buf_DO32_5F02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F02[]={
	{&R7II72LZ2,1,48},
	{&R7II72LZ1,1,12},
	{&R7II71LZ1,1,14},
	{&R7II73LZ1,1,16},
	{&R7II71LZ2,1,46},
	{&R7II73LZ2,1,50},
	{&A3IS11LDU,1,6},
	{&B3IS11LDU,1,20},
	{&A3IS22LDU,1,2},
	{&B3IS22LDU,1,22},
	{&B0VP81LZZ,1,58},
	{&A0VP81LZZ,1,4},
	{&B1VP81LZZ,1,60},
	{&A1VP81LZZ,1,0},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F08[137];	//do32_5f(0x130)
static do32_pti_inipar ini_DO32_5F08={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F08={0,0,&ini_DO32_5F08,buf_DO32_5F08,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F08[]={
	{&R1IS21LDU,1,44},
	{&R1IS11LDU,1,42},
	{&A4IS11LDU,1,30},
	{&R8IS11LDU,1,26},
	{&A4IS21LDU,1,32},
	{&B1IS11LDU,1,14},
	{&B1IS21LDU,1,16},
	{&B2IS12LDU,1,18},
	{&B2IS11LDU,1,20},
	{&B2IS21LDU,1,22},
	{&B1IS12LDU,1,12},
	{&B9IS21LDU,1,40},
	{&B9IS11LDU,1,38},
	{&A9IS21LDU,1,36},
	{&A9IS11LDU,1,34},
	{&A7AS31LDU,1,60},
	{&B7AS31LDU,1,10},
	{&A1IS12LDU,1,62},
	{&B3IS21LDU,1,24},
	{&R2IS21LDU,1,48},
	{&R2IS11LDU,1,46},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F09[137];	//do32_5f(0x140)
static do32_pti_inipar ini_DO32_5F09={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F09={0,0,&ini_DO32_5F09,buf_DO32_5F09,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F09[]={
	{&A2IS21LDU,1,8},
	{&R8AD22LDU,1,16},
	{&A2IS11LDU,1,6},
	{&B6IS21LDU,1,60},
	{&A2IS12LDU,1,4},
	{&A1IS21LDU,1,2},
	{&A1IS11LDU,1,0},
	{&A3IS21LDU,1,10},
	{&B6IS11LDU,1,58},
	{&A6IS21LDU,1,52},
	{&B4IS11LDU,1,12},
	{&R4IS12LDU,1,44},
	{&R4IS22LDU,1,48},
	{&R4IS21LDU,1,46},
	{&R4IS11LDU,1,42},
	{&B4IS21LDU,1,14},
	{&R0IS02LDU,1,32},
	{&B5IS11LDU,1,62},
	{&A5IS11LDU,1,54},
	{&A5IS21LDU,1,56},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F05[137];	//do32_5f(0x150)
static do32_pti_inipar ini_DO32_5F05={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F05={0,0,&ini_DO32_5F05,buf_DO32_5F05,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F05[]={
	{&A8IS12LDU,1,28},
	{&A8IS22LDU,1,30},
	{&B8IS12LDU,1,10},
	{&B8IS11LDU,1,14},
	{&A6IS11LDU,1,34},
	{&B8IS21LDU,1,8},
	{&B8IS22LDU,1,12},
	{&B5IS21LDU,1,0},
	{&R3IS11LDU,1,2},
	{&R5IS21LDU,1,20},
	{&R3IS21LDU,1,4},
	{&R5IS11LDU,1,18},
	{&R6IS21LDU,1,26},
	{NULL,0,0},
};
#pragma pop
#include <drivers/do32_pti.h>
static char buf_DO32_5F06[137];	//do32_5f(0x160)
static do32_pti_inipar ini_DO32_5F06={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F06={0,0,&ini_DO32_5F06,buf_DO32_5F06,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F06[]={
	{NULL,0,0},
};
#pragma pop
#include <drivers/emul8enc.h>
static char buf_em8enc120[40];	//em8enc(0x120)
static em8encpti_inimod ini_em8enc120={0x340,0x4,};
#pragma pack(push,1)
static table_drv table_em8enc120={0,0,&ini_em8enc120,buf_em8enc120,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_em8enc120[]={
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>
static char buf_VDS32F07[66];	//vds32f2(0x340)
static vds32pti_inimod ini_VDS32F07={0,};
#pragma pack(push,1)
static table_drv table_VDS32F07={0,0,&ini_VDS32F07,buf_VDS32F07,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F07[]={
	{&A2AD33LDU,1,26},
	{&B3AD34LDU,1,50},
	{&A4AD10LDU,1,28},
	{&B4AD10LDU,1,56},
	{&A3AD31LDU,1,30},
	{&B3AD31LDU,1,58},
	{&A3AD33LDU,1,24},
	{&B5AD20LDU,1,48},
	{&B5AD10LDU,1,46},
	{&A5AD20LDU,1,44},
	{&A5AD10LDU,1,42},
	{&R2AD20LDU,1,40},
	{&R2AD10LDU,1,38},
	{&B2AD33LDU,1,54},
	{&B3AD33LDU,1,52},
	{&R1AD20LDU,1,36},
	{&R1AD10LDU,1,34},
	{&A8AD10LDU,1,62},
	{&A7AP31LDU,1,32},
	{&B7AP31LDU,1,60},
	{&A3AD34LDU,1,22},
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>
static char buf_VDS32F10[66];	//vds32f2(0x360)
static vds32pti_inimod ini_VDS32F10={0,};
#pragma pack(push,1)
static table_drv table_VDS32F10={0,0,&ini_VDS32F10,buf_VDS32F10,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F10[]={
	{&B6AD20LDU,1,8},
	{&B6AD10LDU,1,6},
	{&A6AD20LDU,1,4},
	{&A3AD04LDU,1,28},
	{&A6AD10LDU,1,2},
	{&A3AD05LDU,1,30},
	{&B3AD11LDU,1,32},
	{&B3AD21LDU,1,34},
	{&B3AD01LDU,1,36},
	{&B3AD02LDU,1,38},
	{&B3AD03LDU,1,40},
	{&B3AD04LDU,1,42},
	{&B3AD05LDU,1,44},
	{&R4AD10LDU,1,10},
	{&R4AD20LDU,1,12},
	{&B8AD10LDU,1,14},
	{&B8AD20LDU,1,16},
	{&A9AD10LDU,1,46},
	{&B9AD10LDU,1,48},
	{&A3AD11LDU,1,18},
	{&A3AD21LDU,1,20},
	{&A3AD01LDU,1,22},
	{&A3AD02LDU,1,24},
	{&A3AD03LDU,1,26},
	{&A1AD11LDU,1,50},
	{&A1AD21LDU,1,52},
	{&A1AD01LDU,1,54},
	{&A1AD02LDU,1,56},
	{&A1AD03LDU,1,58},
	{&A1AD04LDU,1,60},
	{&A8AD20LDU,1,0},
	{NULL,0,0},
};
#pragma pop
#include <drivers/vds32_pti.h>
static char buf_VDS32F11[66];	//vds32f2(0x310)
static vds32pti_inimod ini_VDS32F11={0,};
#pragma pack(push,1)
static table_drv table_VDS32F11={0,0,&ini_VDS32F11,buf_VDS32F11,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F11[]={
	{&B2AD21LDU,1,32},
	{&B2AD11LDU,1,30},
	{&B2AD01LDU,1,34},
	{&A2AD05LDU,1,28},
	{&A2AD04LDU,1,26},
	{&A2AD03LDU,1,24},
	{&A2AD02LDU,1,22},
	{&B2AD02LDU,1,36},
	{&B2AD03LDU,1,38},
	{&R0AD16LDU,1,62},
	{&B2AD04LDU,1,40},
	{&B2AD05LDU,1,42},
	{&A2AD01LDU,1,20},
	{&A2AD21LDU,1,18},
	{&A2AD11LDU,1,16},
	{&B2AD31LDU,1,58},
	{&B1AD32LDU,1,52},
	{&B1AD31LDU,1,54},
	{&B1AD11LDU,1,2},
	{&A1AD05LDU,1,0},
	{&B2AD32LDU,1,56},
	{&A1AD31LDU,1,46},
	{&A1AD32LDU,1,44},
	{&A2AD31LDU,1,50},
	{&B1AD21LDU,1,4},
	{&A2AD32LDU,1,48},
	{&B1AD01LDU,1,6},
	{&B1AD02LDU,1,8},
	{&R8AD21LDU,1,60},
	{&B1AD03LDU,1,10},
	{&B1AD04LDU,1,12},
	{&B1AD05LDU,1,14},
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static Driver drivers[]={
	{0x04,0x320,20,127,def_buf_AO1601,&table_AO1601}, //AO16
	{0x02,0x100,1,137,def_buf_DO32_5F01,&table_DO32_5F01}, //do32_5f(0x100)
	{0x02,0x110,1,137,def_buf_DO32_5F02,&table_DO32_5F02}, //do32_5f(0x110)
	{0x02,0x130,1,137,def_buf_DO32_5F08,&table_DO32_5F08}, //do32_5f(0x130)
	{0x02,0x140,1,137,def_buf_DO32_5F09,&table_DO32_5F09}, //do32_5f(0x140)
	{0x02,0x150,1,137,def_buf_DO32_5F05,&table_DO32_5F05}, //do32_5f(0x150)
	{0x02,0x160,1,137,def_buf_DO32_5F06,&table_DO32_5F06}, //do32_5f(0x160)
	{0x05,0x120,2,40,def_buf_em8enc120,&table_em8enc120}, //em8enc(0x120)
	{0x03,0x340,1,66,def_buf_VDS32F07,&table_VDS32F07}, //vds32f2(0x340)
	{0x03,0x360,1,66,def_buf_VDS32F10,&table_VDS32F10}, //vds32f2(0x360)
	{0x03,0x310,1,66,def_buf_VDS32F11,&table_VDS32F11}, //vds32f2(0x310)
	{0,0,0,0,NULL,NULL},
};
#pragma pop
void InitSetConst(void){      // Инициализация  переменных для сохранения
	setAsFloat(284,0.015);
	setAsFloat(285,0.0069);
	setAsFloat(286,0.21);
	setAsFloat(287,0);
	setAsFloat(288,0);
	setAsFloat(289,0.0096);
	setAsFloat(290,0.0026);
	setAsFloat(291,106);
	setAsFloat(292,135.227);
	setAsFloat(293,25);
	setAsFloat(294,320.435466);
	setAsFloat(295,0.0055);
	setAsFloat(296,0.000877);
	setAsFloat(297,200);
	setAsFloat(298,100);
	setAsFloat(299,0);
	setAsFloat(300,0);
	setAsFloat(301,100);
	setAsFloat(302,80);
	setAsFloat(303,0.002375);
	setAsFloat(304,0);
	setAsFloat(305,165);
	setAsFloat(306,200);
	setAsFloat(307,0.001675);
	setAsFloat(308,4);
	setAsFloat(309,1530.0);
	setAsFloat(310,137.4);
	setAsFloat(311,0);
	setAsFloat(312,390.0);
	setAsFloat(313,2000.0);
	setAsFloat(314,1500.0);
	setAsFloat(315,10.91);
	setAsFloat(316,10.91);
	setAsFloat(317,1500.0);
	setAsFloat(318,2000);
	setAsFloat(319,390.0);
	setAsFloat(320,0);
	setAsFloat(321,55.0);
	setAsFloat(322,15.0);
	setAsFloat(323,5.0);
	setAsFloat(324,1E12);
	setAsFloat(325,40.0);
	setAsFloat(326,20.0);
	setAsFloat(327,20.0);
	setAsFloat(328,20.0);
	setAsFloat(329,1269.0);
	setAsFloat(330,256.0);
	setAsFloat(331,1.0);
	setAsFloat(332,2.0);
	setAsFloat(333,0);
	setAsFloat(334,0.026);
	setAsFloat(335,0.8);
	setAsFloat(336,0.0);
	setAsFloat(337,27.108);
	setAsFloat(338,600);
	setAsFloat(339,0);
	setAsFloat(340,0.00009765625);
	setAsFloat(341,1.6);
	setAsFloat(342,0);
	setAsFloat(343,0.00009765625);
	setAsFloat(344,2.5);
	setAsFloat(345,0);
	setAsFloat(346,0.00009765625);
	setAsFloat(347,10000.0);
	setAsFloat(348,0.0009765625);
	setAsFloat(349,750);
	setAsFloat(350,100);
	setAsFloat(351,200);
	setAsFloat(352,300);
	setAsFloat(353,400);
	setAsFloat(354,500);
	setAsFloat(355,600);
	setAsFloat(356,0.50);
	setAsFloat(357,0.50);
	setAsFloat(358,0.50);
	setAsFloat(359,20);
	setAsFloat(360,11.0);
	setAsFloat(361,1585.0);
	setAsFloat(362,1796.0);
	setAsFloat(363,1555.0);
	setAsFloat(364,1269.0);
	setAsFloat(365,1269.0);
	setAsFloat(366,1585.0);
	setAsFloat(367,1796.0);
	setAsFloat(368,1269.0);
	setAsFloat(369,248.0);
	setAsFloat(370,284.5);
	setAsFloat(371,248.0);
	setAsFloat(372,271.6);
	setAsFloat(373,287.2);
	setAsFloat(374,594.0);
	setAsFloat(375,559.0);
	setAsFloat(376,588.0);
	setAsFloat(377,1555.0);
	setAsFloat(378,1281.2);
	setAsFloat(379,1269.0);
	setAsFloat(380,594.0);
	setAsFloat(381,597.2);
	setAsFloat(382,556.8);
	setAsFloat(383,1.0);
	setAsFloat(384,1.0);
	setAsFloat(385,1.0);
	setAsFloat(386,1.0);
	setAsFloat(387,1.0);
	setAsFloat(388,1.0);
	setAsFloat(389,1.0);
	setAsFloat(390,1.0);
	setAsFloat(391,1.0);
	setAsFloat(392,1.0);
	setAsFloat(393,1.0);
	setAsFloat(394,1.0);
	setAsFloat(395,0);
	setAsFloat(396,0);
	setAsFloat(397,0);
	setAsFloat(398,0);
	setAsFloat(399,0.0);
	setAsFloat(400,0);
	setAsFloat(401,0.0);
	setAsFloat(402,0);
	setAsFloat(403,0.0);
	setAsFloat(404,0.0);
	setAsFloat(405,0.0);
	setAsFloat(406,0.0);
	setAsFloat(407,37037.04);
	setAsFloat(408,975000.0);
	setAsFloat(409,20);
	setAsFloat(410,18000);
	setAsFloat(411,18000);
	setAsFloat(412,18000);
	setAsFloat(413,0.76);
	setAsFloat(414,0.245);
	setAsFloat(415,2.9);
	setAsFloat(416,0.13);
	setAsFloat(417,0.73);
	setAsFloat(418,0.6);
	setAsFloat(419,9807.0);
	setAsFloat(420,22975.0);
	setAsFloat(421,12750.0);
	setAsFloat(422,20);
	setAsFloat(423,20);
	setAsFloat(424,0);
	setAsFloat(425,5.0);
	setAsFloat(426,5.0);
	setAsFloat(427,5.0);
	setAsFloat(428,100.0);
	setAsFloat(429,4000);
	setAsFloat(430,100000);
	setAsFloat(431,1000000);
	setAsFloat(432,32000.0);
	setAsFloat(433,5.0);
	setAsFloat(434,15.0);
	setAsFloat(435,15.0);
	setAsFloat(436,20.0);
	setAsFloat(437,10.0);
	setAsBool(438,0);
	setAsBool(439,0);
	setAsBool(440,0);
	setAsFloat(441,0.45);
	setAsFloat(442,0.39);
	setAsFloat(443,2.74);
	setAsFloat(444,0.07);
	setAsFloat(445,0.275);
	setAsFloat(446,0.245);
	setAsFloat(447,0.02);
	setAsFloat(448,0.05);
	setAsShort(449,0);
	setAsFloat(450,0);
	setAsFloat(451,0);
	setAsShort(452,0);
	setAsFloat(453,0);
	setAsFloat(454,0);
	setAsShort(455,0);
	setAsFloat(456,0);
	setAsFloat(457,0);
	setAsShort(458,0);
	setAsFloat(459,0);
	setAsFloat(460,0);
	setAsShort(461,0);
	setAsFloat(462,0);
	setAsFloat(463,0);
	setAsShort(464,0);
	setAsFloat(465,0);
	setAsFloat(466,0);
	setAsShort(467,0);
	setAsShort(468,0);
	setAsFloat(469,0);
	setAsShort(470,0);
	setAsShort(471,0);
	setAsFloat(472,0);
	setAsFloat(473,0);
	setAsFloat(474,0);
	setAsFloat(475,0);
	setAsFloat(476,0);
	setAsFloat(477,0);
	setAsFloat(478,0);
	setAsFloat(479,0);
	setAsShort(480,0);
	setAsShort(481,0);
	setAsShort(482,0);
	setAsShort(483,0);
	setAsShort(484,0);
	setAsShort(485,0);
	setAsShort(486,0);
	setAsShort(487,0);
	setAsShort(488,0);
	setAsShort(489,0);
	setAsShort(490,0);
	setAsShort(491,0);
	setAsShort(492,0);
	setAsShort(493,0);
	setAsShort(494,0);
	setAsShort(495,0);
	setAsShort(496,0);
	setAsShort(497,0);
	setAsShort(498,0);
	setAsShort(499,0);
	setAsShort(500,0);
	setAsShort(501,0);
	setAsShort(502,0);
	setAsShort(503,0);
	setAsShort(504,0);
	setAsShort(505,0);
	setAsShort(506,0);
	setAsShort(507,0);
	setAsShort(508,0);
	setAsShort(509,0);
	setAsShort(510,0);
	setAsShort(511,0);
	setAsShort(512,0);
	setAsShort(513,0);
	setAsShort(514,0);
	setAsShort(515,0);
	setAsShort(516,0);
	setAsShort(517,0);
	setAsShort(518,0);
	setAsShort(519,0);
	setAsShort(520,0);
	setAsShort(521,0);
	setAsShort(522,0);
	setAsShort(523,0);
	setAsShort(524,0);
	setAsShort(525,0);
	setAsShort(526,0);
	setAsShort(527,0);
	setAsShort(528,0);
	setAsShort(529,0);
	setAsShort(530,0);
	setAsShort(531,0);
	setAsShort(532,0);
	setAsShort(533,0);
	setAsShort(534,0);
	setAsShort(535,0);
	setAsShort(536,0);
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
	setAsFloat(564,0);
	setAsFloat(565,0);
	setAsShort(566,0);
	setAsFloat(567,0);
	setAsShort(568,0);
	setAsFloat(569,0);
	setAsFloat(570,0);
	setAsShort(571,0);
	setAsFloat(572,0);
	setAsFloat(573,0);
	setAsShort(574,0);
	setAsFloat(575,0);
	setAsFloat(576,0);
	setAsBool(577,0);
	setAsBool(578,1);
	setAsBool(579,0);
	setAsBool(580,1);
	setAsBool(581,0);
	setAsShort(582,0);
	setAsFloat(583,0);
	setAsFloat(584,0);
	setAsShort(585,0);
	setAsFloat(586,0);
	setAsFloat(587,0);
	setAsShort(588,0);
	setAsFloat(589,0);
	setAsFloat(590,0);
	setAsShort(591,0);
	setAsFloat(592,0);
	setAsFloat(593,0);
	setAsBool(594,1);
	setAsFloat(595,0.01);
	setAsFloat(596,0.01);
	setAsFloat(597,0.01);
	setAsShort(598,0);
	setAsShort(599,0);
	setAsShort(600,0);
	setAsFloat(601,25.017338);
	setAsFloat(602,-0.15912805);
	setAsFloat(603,0.000000166);
	setAsFloat(604,25.017338);
	setAsFloat(605,0);
	setAsFloat(606,0);
	setAsFloat(607,0);
	setAsFloat(608,0);
	setAsFloat(609,0);
	setAsFloat(610,0);
	setAsFloat(611,0);
	setAsFloat(612,0);
	setAsFloat(613,0);
	setAsFloat(614,0);
	setAsFloat(615,0.000885839);
	setAsFloat(616,0.000885839);
	setAsFloat(617,0.000885839);
	setAsFloat(618,0.000885839);
	setAsFloat(619,390);
	setAsFloat(620,390);
	setAsFloat(621,55);
	setAsFloat(622,55);
	setAsFloat(623,0);
	setAsFloat(624,4000.0);
	setAsFloat(625,10);
	setAsFloat(626,0);
	setAsFloat(627,0);
	setAsFloat(628,5);
	setAsFloat(629,5);
	setAsFloat(630,0);
	setAsFloat(631,0);
	setAsFloat(632,0);
	setAsFloat(633,0);
	setAsFloat(634,1530.0);
	setAsFloat(635,0);
	setAsShort(636,0);
	setAsShort(637,0);
	setAsFloat(638,506.5);
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
	setAsFloat(653,1.0);
	setAsFloat(654,1.0);
	setAsFloat(655,1.0);
	setAsFloat(656,1570.0);
	setAsFloat(657,1269);
	setAsFloat(658,1281.2);
	setAsFloat(659,248.0);
	setAsFloat(660,572.4);
	setAsFloat(661,246.8);
	setAsFloat(662,1);
	setAsFloat(663,0);
	setAsFloat(664,0.0069);
	setAsFloat(665,0.5);
	setAsFloat(666,600);
	setAsFloat(667,0.014);
	setAsFloat(668,0.019);
	setAsShort(105,2);
}
uspaint8 InternalBuf[1090];

/* Определение констант ПЗУ и ЭСППЗУ*/
ssbool lRM_1_ = {1,0}; /* Флаг наличия магнита на штоке ОРР */ 
ssfloat fRM_0_ = {0,0}; /* Заглушка давления на подъём ББ1 */ 
ssfloat fRM_1_ = {1,0}; /* *Vm - массив скоростей движения (шагов в секунду) */ 
ssbool lRM_0_ = {0,0}; /* Флаг наличия магнита на штоке ОРР */ 
ssfloat fRM_1_0 = {1.0,0}; /* Номинальная скорость БЗ (град/с) */ 
ssfloat fRM_180_0 = {180.0,0}; /* Координата верхнего путевого выключателя БЗ град */ 
ssfloat fRM_0_0 = {0.0,0}; /* Координата нижних упоров БЗ град */ 
ssfloat fRM_n50_ = {-50,0}; /* Координата нижнего путевого выключателя БЗ град */ 
ssfloat fRM_2000_0 = {2000.0,0}; /* Координата верхнего путевого выключателя МДЗ мм */ 
ssfloat fRM_n150_ = {-150,0}; /* Координата нижнего путевого выключателя МДЗ мм */ 
ssfloat fRM_1500_0 = {1500.0,0}; /* Координата верхнего механического выключателя НЛ мм */ 
ssint iRM_7_ = {7,0}; /* N */ 
ssfloat fRM_390_ = {390,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_420_ = {420,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_513_ = {513,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_767_ = {767,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_900_ = {900,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_1200_ = {1200,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_1500_ = {1500,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_3_546 = {3.546,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_2_7 = {2.7,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_2_ = {2,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_88884 = {0.88884,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_6221739 = {0.6221739,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_35555072 = {0.35555072,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_2666666667 = {0.2666666667,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssint iRM_5_ = {5,0}; /* N */ 
ssfloat fRM_600_ = {600,0}; /* Ai, i=1..N -абсциссы опорных точек */ 
ssfloat fRM_0_5 = {0.5,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_2 = {0.2,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_088884 = {0.088884,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_066666667 = {0.066666667,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_02173913 = {0.02173913,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_002453 = {0.002453,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_00184 = {0.00184,0}; /* Bi, i=1..N -ординаты опорных точек */ 
ssfloat fRM_0_10 = {0.10,0}; /* Зона срабатывания КВ БЗ(мм) */ 
ssfloat fRM_0_50 = {0.50,0}; /* Зона срабатывания КВ МДЗ (мм) */ 
ssint iRM_2_ = {2,0}; /* n - N-размерность массива x */ 
ssint iRM_3_ = {3,0}; /* N-число входов */ 
ssint iRM_4_ = {4,0}; /* N-число входов */ 
ssint iRM_0_ = {0,0}; /* Ter - Неисправности механизма */ 
ssfloat fRM_100000_ = {100000,0}; /* KPv - координата пер. выключателя механизма мм */ 
ssfloat fRM_n100_ = {-100,0}; /* KZv - координата зад. выключателя механизма мм */ 
ssfloat fRM_20_ = {20,0}; /* Tp - Тормозной путь мм */ 
sschar bRM_2_ = {2,0}; /* type - тип камеры */ 
sschar bRM_4_ = {4,0}; /* type - тип камеры */ 
sschar bRM_5_ = {5,0}; /* type - тип камеры */ 
sschar bRM_1_ = {1,0}; /* type - тип камеры */ 
ssfloat fRM_3_ = {3,0}; /* m1 - величина отклонения второго сигнала от входного */ 
ssfloat fRM_2_0 = {2.0,0}; /* ampl - амплетуда синусоидального отклонения */ 
ssint iRM_3276_ = {3276,0}; /* min - минимальное возможное значение выходного сигнала */ 
ssint iRM_16383_ = {16383,0}; /* max - максимальное возможное значение выходного сигнала */ 
ssfloat fRM_3276_ = {3276,0}; /* c   - мин. значение кода ФАС */ 
ssfloat fRM_16383_ = {16383,0}; /* d - макс.  значение кода ФАС */ 
ssfloat fRM_200_ = {200,0}; /* maxs1 - макc. значение второго сигнала */ 
ssfloat fRM_0_0015 = {0.0015,0}; /* m1 - величина отклонения второго сигнала от входного */ 
ssfloat fRM_0_001 = {0.001,0}; /* ampl - амплетуда синусоидального отклонения */ 
ssfloat fRM_0_1 = {0.1,0}; /* k - коэффициент усиления */ 
ssint iRM_16_ = {16,0}; /* n - N-размерность массива входных параметров */ 
ssfloat fRM_2000_ = {2000,0}; /* maxs1 - макc. значение второго сигнала */ 
ssfloat fRM_15_ = {15,0}; /* m1 - величина отклонения второго сигнала от входного */ 

uspaint8 SpaEEPROMBuf[1656];

/* Определение переменных */
ssbool var1;
ssbool var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
ssfloat var6;
ssfloat var7;
ssfloat var8;
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
ssfloat var41;
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
sslong var55;
ssfloat var56;
sslong var57;
ssfloat var58;
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
ssint var93;
ssint var94;
ssfloat var95;
ssfloat var96;
sslong var97;
ssfloat var98;
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
ssfloat var110;
ssbool var111;
ssbool var112;
sslong var113;
ssfloat var114;
sslong var115;
ssfloat var116;
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
ssint var128;
ssfloat var129;
ssbool var130;
ssbool var131;
ssint var132;
ssfloat var133;
ssbool var134;
sslong var135;
ssfloat var136;
ssbool var137;
ssbool var138;
sslong var139;
ssfloat var140;
ssbool var141;
ssint var142;
ssint var143;
ssbool var144;
ssbool var145;
ssbool var146;
sslong var147;
ssfloat var148;
ssbool var149;
ssbool var150;
ssbool var151;
ssfloat var152;
ssfloat var153;
ssfloat var154;
ssint var155;
ssint var156;
ssint var157;
ssfloat var158;
ssfloat var159;
ssfloat var160;
ssint var161;
ssint var162;
ssbool var163;
ssbool var164;
ssint var165;
ssfloat var166;
ssfloat var167;
ssfloat var168;
ssbool var169;
ssbool var170;
ssbool var171;
ssbool var172;
ssfloat var173;
ssbool var174;
ssfloat var175;
ssbool var176;
ssbool var177;
ssbool var178;
ssbool var179;
ssbool var180;
ssfloat var181;
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
ssfloat var220;
ssfloat var221;
ssfloat var222;
ssfloat var223;
ssfloat var224;
ssfloat var225;
ssfloat var226;
ssfloat var227;
ssfloat var228;
ssbool var229;
ssbool var230;
ssbool var231;
ssfloat var232;
ssfloat var233;
ssfloat var234;
ssfloat var235;
ssfloat var236;
ssfloat var237;
ssfloat var238;
ssfloat var239;
ssfloat var240;
ssfloat var241;
ssfloat var242;
ssfloat var243;
ssfloat var244;
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
ssfloat var269;
ssbool var270;
ssbool var271;
ssfloat var272;
ssbool var273;
ssbool var274;
ssbool var275;
ssbool var276;
ssbool var277;
ssbool var278;
ssbool var279;
ssbool var280;
ssfloat var281;
ssfloat var282;
ssfloat var283;
ssfloat var284;
ssbool var285;
ssfloat var286;
ssfloat var287;
ssfloat var288;
ssfloat var289;
ssbool var290;
ssbool var291;
ssbool var292;
ssbool var293;
ssbool var294;
ssfloat var295;
ssfloat var296;
ssbool var297;
ssbool var298;
ssbool var299;
ssbool var300;
ssbool var301;
ssfloat var302;
ssfloat var303;
ssbool var304;
ssbool var305;
ssbool var306;
ssbool var307;
ssbool var308;
ssbool var309;
ssfloat var310;
ssfloat var311;
ssbool var312;
ssbool var313;
ssbool var314;
ssbool var315;
ssbool var316;
ssbool var317;
ssfloat var318;
ssfloat var319;
ssbool var320;
ssbool var321;
ssbool var322;
ssbool var323;
ssbool var324;
ssfloat var325;
ssfloat var326;
ssbool var327;
ssbool var328;
ssbool var329;
ssbool var330;
ssbool var331;
ssfloat var332;
ssfloat var333;
ssfloat var334;
ssfloat var335;
ssbool var336;
ssfloat var337;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m354_x_1[16] = {&lEM_R8AD10LC1,&lEM_R8AD10LC1,&var331,&var189,&var183,&var273,&var271,&var265,&var262,&var278,&var321,&var316,&var307,&var297,&var291,&R0MW13LP2};
psbool  array_m905_x_1[2] = {&lEM_R0IE02LRP,&lEM_R0IE01LRP};
psbool  array_m900_x_1[2] = {&var171,&R0MW13LP2};
psbool  array_m925_x_1[2] = {&var176,&R0MW13LP2};
psbool  array_m918_x_1[2] = {&var177,&R0MW13LP2};
psbool  array_m910_x_1[2] = {&var178,&R0MW13LP2};
psbool  array_m616_x_1[2] = {&var35,&var230};
psbool  array_m613_x_1[2] = {&var35,&var231};
psbool  array_m622_x_1[3] = {&lEM_C1AD31LRP,&R0VZ71LZ1,&R0VZ71LZ2};
psbool  array_m902_x_1[2] = {&var201,&R0MW13LP2};
psbool  array_m291_x_1[2] = {&var218,&B3AD31LDU};
psbool  array_m257_x_1[3] = {&B2AD31LDU,&var204,&var218};
psbool  array_m258_x_1[3] = {&B2AD32LDU,&var204,&var218};
psbool  array_m220_x_1[4] = {&B1AD32LDU,&var207,&var206,&var218};
psbool  array_m219_x_1[4] = {&var207,&B1AD31LDU,&var206,&var218};
psbool  array_m124_x_1[2] = {&A3AD31LDU,&var218};
psbool  array_m54_x_1[4] = {&A1AD32LDU,&var212,&var211,&var218};
psbool  array_m53_x_1[4] = {&var212,&A1AD31LDU,&var211,&var218};
psbool  array_m91_x_1[3] = {&A2AD31LDU,&var216,&var218};
psbool  array_m92_x_1[3] = {&A2AD32LDU,&var216,&var218};
psbool  array_m629_x_1[2] = {&var229,&var34};
psfloat  array_m7_a_1[5] = {&fRM_390_,&fRM_600_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m7_b_1[5] = {&fRM_0_5,&fRM_0_2,&fRM_0_088884,&fRM_0_066666667,&fRM_0_02173913};
psfloat  array_m9_a_1[7] = {&fRM_390_,&fRM_420_,&fRM_513_,&fRM_767_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m9_b_1[7] = {&fRM_3_546,&fRM_2_7,&fRM_2_,&fRM_0_88884,&fRM_0_6221739,&fRM_0_35555072,&fRM_0_2666666667};
psfloat  array_m299_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m134_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m269_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m100_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m234_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m66_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};

/* Объявление структур */
_S_kvds  S_kvds_39_1 = {&var298,&var291,&R8AD21LDU,&fEM_R0UL02RDU,&fEM_R0UL04RDU,&fEM_R0UL02RIM,&fEM_R0UL03RDU,&var1,&var2,&internal1_m39_reg,&internal1_m39_tgen,&internal1_m39_tsin,&internal1_m39_tlock,&internal1_m39_fef};
_S_looktakt  S_looktakt_150_1 = {&var3};
_S_to3val  S_to3val_954_1 = {&fEM_R7UX16RSS,&fRM_900_,&fRM_15_,&fRM_0_0015,&fRM_0_,&fRM_2000_,&fRM_2000_,&TerR0IN06FRP,&var4,&var5,&vainSFloat,&bFirstEnterFlag};
_S_vchs  S_vchs_880_1 = {&var282,&var333,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_5_,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var6,&internal1_m880_Chim0};
_S_vchs  S_vchs_870_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&bRM_4_,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var7,&internal1_m870_Chim0};
_S_vchs  S_vchs_862_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&bRM_2_,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var8,&internal1_m862_Chim0};
_S_twobool  S_twobool_817_1 = {&var280,&iEM_TERR4VS22LDU,&var9,&vainSBool,&internal1_m817_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_816_1 = {&var279,&iEM_TERR4VS12LDU,&var10,&vainSBool,&internal1_m816_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_999_1 = {&var256,&iEM_TERR2VS22LIM,&var11,&vainSBool,&internal1_m999_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_998_1 = {&var255,&iEM_TERR2VS12LIM,&var12,&vainSBool,&internal1_m998_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_997_1 = {&var260,&iEM_TERR1VS22LIM,&var13,&vainSBool,&internal1_m997_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_996_1 = {&var259,&iEM_TERR1VS12LIM,&var14,&vainSBool,&internal1_m996_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_675_1 = {&var248,&iEM_TERB5VS22LIM,&var15,&vainSBool,&internal1_m675_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_674_1 = {&var247,&iEM_TERB5VS12LIM,&var16,&vainSBool,&internal1_m674_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_653_1 = {&var252,&iEM_TERA5VS22LIM,&var17,&vainSBool,&internal1_m653_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_652_1 = {&var251,&iEM_TERA5VS12LIM,&var18,&vainSBool,&internal1_m652_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_673_1 = {&var264,&iEM_TERB6VS22LIM,&var19,&vainSBool,&internal1_m673_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_672_1 = {&var263,&iEM_TERB6VS12LIM,&var20,&vainSBool,&internal1_m672_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_651_1 = {&var268,&iEM_TERA6VS22LIM,&var21,&vainSBool,&internal1_m651_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_650_1 = {&var267,&iEM_TERA6VS12LIM,&var22,&vainSBool,&internal1_m650_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_517_1 = {&var40,&iEM_TERA1VP81LIM,&var23,&vainSBool,&internal1_m517_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_533_1 = {&var40,&iEM_TERB1VP81LIM,&var24,&vainSBool,&internal1_m533_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_405_1 = {&var307,&iEM_TERB2SS33LIM,&var25,&vainSBool,&internal1_m405_Out10,&bFirstEnterFlag};
_S_noto  S_noto_480_1 = {&var185,&var26};
_S_noto  S_noto_481_1 = {&var184,&var27};
_S_noto  S_noto_471_1 = {&var186,&var28};
_S_noto  S_noto_473_1 = {&var187,&var29};
_S_rs  S_rs_478_1 = {&var27,&lEM_R5AD10LC1,&var30,&vainSBool,&internal1_m478_q0};
_S_rs  S_rs_479_1 = {&var26,&lEM_R5AD20LC1,&var31,&vainSBool,&internal1_m479_q0};
_S_rs  S_rs_466_1 = {&var28,&lEM_R3AD10LC1,&var32,&vainSBool,&internal1_m466_q0};
_S_rs  S_rs_467_1 = {&var29,&lEM_R3AD20LC1,&var33,&vainSBool,&internal1_m467_q0};
_S_andn  S_andn_354_1 = {array_m354_x_1,&iRM_16_,&vainSBool};
_S_zpfs  S_zpfs_626_1 = {&R0AD14LDU,&fEM_R7UI76RIM,&var34,&internal1_m626_tx,&internal1_m626_y0};
_S_zpfs  S_zpfs_614_1 = {&R0AD16LDU,&fEM_R7UI77RIM,&var35,&internal1_m614_tx,&internal1_m614_y0};
_S_bol  S_bol_940_1 = {&fEM_A4UP01RIM,&fEM_A4UP02RIM,&var36};
_S_bol  S_bol_937_1 = {&fEM_A3UP01RIM,&fEM_A3UP02RIM,&var37};
_S_bol  S_bol_916_1 = {&fEM_A0UP02RIM,&fEM_A0UP01RIM,&var38};
_S_bol  S_bol_938_1 = {&fEM_A2UP02RIM,&fEM_A2UP03RIM,&var39};
_S_bol  S_bol_928_1 = {&fEM_A1UP01RIM,&fEM_A1UP82RIM,&var40};
_S_ampl  S_ampl_368_1 = {&var272,&fRM_0_1,&var41};
_S_or2  S_or2_929_1 = {&R0EE04LZ1,&R0EE04LZ2,&var42};
_S_or2  S_or2_920_1 = {&R0EE03LZ1,&R0EE03LZ2,&var43};
_S_or2  S_or2_913_1 = {&R0EE02LZ1,&R0EE02LZ2,&var44};
_S_or2  S_or2_906_1 = {&R0EE01LZ1,&R0EE01LZ2,&var45};
_S_zpfs  S_zpfs_602_1 = {&var188,&fRM_1_0,&var46,&internal1_m602_tx,&internal1_m602_y0};
_S_zpfs  S_zpfs_600_1 = {&var191,&fRM_0_5,&var47,&internal1_m600_tx,&internal1_m600_y0};
_S_twobool  S_twobool_210_1 = {&B1AD21LDU,&iEM_TERB1IE04LDU,&var48,&vainSBool,&internal1_m210_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_228_1 = {&B1AD11LDU,&iEM_TERB1IE03LDU,&var49,&vainSBool,&internal1_m228_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_47_1 = {&A1AD21LDU,&iEM_TERA1IE04LDU,&var50,&vainSBool,&internal1_m47_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_62_1 = {&A1AD11LDU,&iEM_TERA1IE03LDU,&var51,&vainSBool,&internal1_m62_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_970_1 = {&var324,&iEM_TERB1SS12LIM,&var52,&vainSBool,&internal1_m970_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_967_1 = {&var320,&iEM_TERB1SS11LIM,&var53,&vainSBool,&internal1_m967_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_966_1 = {&var321,&iEM_TERB1SS21LIM,&var54,&vainSBool,&internal1_m966_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_969_1 = {&var56,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var55,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m969_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_964_1 = {&var223,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB1MC01RIM,&var56,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_952_1 = {&var58,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var57,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m952_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_945_1 = {&var224,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA1SC01RIM,&var58,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_953_1 = {&var331,&iEM_TERA1SS12LIM,&var59,&vainSBool,&internal1_m953_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_950_1 = {&var328,&iEM_TERA1SS11LIM,&var60,&vainSBool,&internal1_m950_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_949_1 = {&var329,&iEM_TERA1SS21LIM,&var61,&vainSBool,&internal1_m949_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1037_1 = {&var262,&iEM_TERB6SS21LIM,&var62,&vainSBool,&internal1_m1037_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1018_1 = {&var261,&iEM_TERB6SS11LIM,&var63,&vainSBool,&internal1_m1018_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1017_1 = {&var266,&iEM_TERA6SS21LIM,&var64,&vainSBool,&internal1_m1017_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1016_1 = {&var265,&iEM_TERA6MS11LIM,&var65,&vainSBool,&internal1_m1016_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_838_1 = {&var271,&iEM_TERA8SS12LIM,&var66,&vainSBool,&internal1_m838_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_840_1 = {&var270,&iEM_TERA8SS22LIM,&var67,&vainSBool,&internal1_m840_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_837_1 = {&var274,&iEM_TERB8SS12LIM,&var68,&var69,&internal1_m837_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_839_1 = {&var273,&iEM_TERB8SS22LIM,&var70,&var71,&internal1_m839_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_813_1 = {&var275,&iEM_TERR4SS12LIM,&var72,&vainSBool,&internal1_m813_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_814_1 = {&var276,&iEM_TERR4SS22LIM,&var73,&vainSBool,&internal1_m814_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_812_1 = {&var278,&iEM_TERR4MS21LIM,&var74,&vainSBool,&internal1_m812_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_811_1 = {&var277,&iEM_TERR4SS11LIM,&var75,&vainSBool,&internal1_m811_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1032_1 = {&var36,&iEM_TERA4VP82LIM,&var76,&var77,&internal1_m1032_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_984_1 = {&var254,&iEM_TERR2SS21LIM,&var78,&vainSBool,&internal1_m984_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_983_1 = {&var253,&iEM_TERR2SS11LIM,&var79,&vainSBool,&internal1_m983_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_982_1 = {&var258,&iEM_TERR1SS21LIM,&var80,&vainSBool,&internal1_m982_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_981_1 = {&var257,&iEM_TERR1SS11LIM,&var81,&vainSBool,&internal1_m981_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1033_1 = {&var193,&iEM_TERB4SS21LIM,&var82,&vainSBool,&internal1_m1033_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1014_1 = {&var192,&iEM_TERB4SS11LIM,&var83,&vainSBool,&internal1_m1014_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_815_1 = {&lEM_R8AD10LC1,&iEM_TERR8SS11LIM,&var84,&vainSBool,&internal1_m815_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1015_1 = {&var190,&iEM_TERA4SS21LIM,&var85,&vainSBool,&internal1_m1015_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1013_1 = {&var189,&iEM_TERA4SS11LIM,&var86,&vainSBool,&internal1_m1013_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1034_1 = {&var185,&iEM_TERR5SS21LIM,&var87,&vainSBool,&internal1_m1034_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1012_1 = {&var184,&iEM_TERR5SS11LIM,&var88,&vainSBool,&internal1_m1012_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_995_1 = {&var187,&iEM_TERR3SS21LIM,&var89,&vainSBool,&internal1_m995_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_980_1 = {&var186,&iEM_TERR3SS11LIM,&var90,&vainSBool,&internal1_m980_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_534_1 = {&var39,&iEM_TERA2VP82LIM,&var91,&var92,&internal1_m534_Out10,&bFirstEnterFlag};
_S_toao  S_toao_538_1 = {&var96,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var93,&bFirstEnterFlag};
_S_toao  S_toao_537_1 = {&var95,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var94,&bFirstEnterFlag};
_S_to3val  S_to3val_531_1 = {&var153,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERB2SP01RIM,&var95,&vainSFloat,&var96,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_415_1 = {&var98,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var97,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m415_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_409_1 = {&var222,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB2SC01RIM,&var98,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_406_1 = {&var309,&iEM_TERB2SS12LIM,&var99,&vainSBool,&internal1_m406_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_408_1 = {&var304,&iEM_TERB2SS11LIM,&var100,&vainSBool,&internal1_m408_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_407_1 = {&var305,&iEM_TERB2SS21LIM,&var101,&vainSBool,&internal1_m407_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_853_1 = {&var199,&iEM_TERB9SS21LIM,&var102,&vainSBool,&internal1_m853_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_854_1 = {&var198,&iEM_TERB9SS11LIM,&var103,&vainSBool,&internal1_m854_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_852_1 = {&var196,&iEM_TERA9SS21LIM,&var104,&vainSBool,&internal1_m852_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1036_1 = {&var195,&iEM_TERA9SS11LIM,&var105,&vainSBool,&internal1_m1036_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_688_1 = {&var246,&iEM_TERB5SS21LIM,&var106,&vainSBool,&internal1_m688_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_689_1 = {&var245,&iEM_TERB5SS11LIM,&var107,&vainSBool,&internal1_m689_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_686_1 = {&var250,&iEM_TERA5SS21LIM,&var108,&vainSBool,&internal1_m686_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_687_1 = {&var249,&iEM_TERA5SS11LIM,&var109,&vainSBool,&internal1_m687_Out10,&bFirstEnterFlag};
_S_ampl  S_ampl_639_1 = {&var228,&fEM_R7UI75RIM,&var110};
_S_to3val  S_to3val_640_1 = {&var110,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R7UI74RIM,&fEM_R7UI74RIM,&iEM_TERR7SI74RIM,&vainSFloat,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_550_1 = {&var38,&iEM_TERB0VP81LIM,&var111,&vainSBool,&internal1_m550_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_549_1 = {&var38,&iEM_TERA0VP81LIM,&var112,&vainSBool,&internal1_m549_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_834_1 = {&var114,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var113,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m834_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_826_1 = {&var272,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB8SC01RIM,&var114,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_836_1 = {&var116,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var115,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m836_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_828_1 = {&var269,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA8SC01RIM,&var116,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_685_1 = {&R0MW13LP2,&iEM_TERR6IS68LIM,&var117,&vainSBool,&internal1_m685_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_669_1 = {&R0MW13LP2,&iEM_TERR6IS67LIM,&var118,&vainSBool,&internal1_m669_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_649_1 = {&R0MW13LP2,&iEM_TERR6IS66LIM,&var119,&vainSBool,&internal1_m649_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_668_1 = {&R0MW13LP2,&iEM_TERR6IS64LIM,&var120,&var121,&internal1_m668_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_648_1 = {&R0MW13LP2,&iEM_TERR6IS62LIM,&var122,&var123,&internal1_m648_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_336_1 = {&var290,&iEM_TERB3SS22LIM,&var124,&vainSBool,&internal1_m336_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_335_1 = {&var297,&iEM_TERA3SS22LIM,&var125,&vainSBool,&internal1_m335_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_320_1 = {&var291,&iEM_TERB3SS11LIM,&var126,&vainSBool,&internal1_m320_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_319_1 = {&var298,&iEM_TERA3SS11LIM,&var127,&vainSBool,&internal1_m319_Out10,&bFirstEnterFlag};
_S_toao  S_toao_516_1 = {&var129,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var128,&bFirstEnterFlag};
_S_to3val  S_to3val_505_1 = {&var175,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERA3SP02RIM,&vainSFloat,&var129,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_551_1 = {&var37,&iEM_TERA3VP81LIM,&var130,&var131,&internal1_m551_Out10,&bFirstEnterFlag};
_S_toao  S_toao_514_1 = {&var133,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var132,&bFirstEnterFlag};
_S_to3val  S_to3val_508_1 = {&var173,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERB3SP02RIM,&vainSFloat,&var133,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_349_1 = {&var294,&iEM_TERB3SS33LIM,&var134,&vainSBool,&internal1_m349_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_333_1 = {&var136,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var135,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m333_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_332_1 = {&var289,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB3SC01RIM,&var136,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_348_1 = {&var293,&iEM_TERB3SS31LIM,&var137,&vainSBool,&internal1_m348_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_346_1 = {&var301,&iEM_TERA3SS33LIM,&var138,&vainSBool,&internal1_m346_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_326_1 = {&var140,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var139,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m326_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_322_1 = {&var296,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA3SC01RIM,&var140,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_347_1 = {&var300,&iEM_TERA3SS31LIM,&var141,&vainSBool,&internal1_m347_Out10,&bFirstEnterFlag};
_S_toao  S_toao_536_1 = {&var154,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var142,&bFirstEnterFlag};
_S_toao  S_toao_535_1 = {&var152,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var143,&bFirstEnterFlag};
_S_twobool  S_twobool_318_1 = {&var292,&iEM_TERB3SS21LIM,&var144,&vainSBool,&internal1_m318_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_334_1 = {&var299,&iEM_TERA3SS21LIM,&var145,&vainSBool,&internal1_m334_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_427_1 = {&var315,&iEM_TERA2SS33LIM,&var146,&vainSBool,&internal1_m427_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_428_1 = {&var148,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var147,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m428_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_423_1 = {&var221,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA2SC01RIM,&var148,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_426_1 = {&var317,&iEM_TERA2SS12LIM,&var149,&vainSBool,&internal1_m426_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_425_1 = {&var312,&iEM_TERA2SS11LIM,&var150,&vainSBool,&internal1_m425_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_424_1 = {&var313,&iEM_TERA2SS21LIM,&var151,&vainSBool,&internal1_m424_Out10,&bFirstEnterFlag};
_S_to3val  S_to3val_530_1 = {&fEM_A2UP01RIM,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERA2SP01RIM,&var152,&var153,&var154,&bFirstEnterFlag};
_S_toao  S_toao_166_1 = {&var160,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var155,&bFirstEnterFlag};
_S_toao  S_toao_165_1 = {&var159,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var156,&bFirstEnterFlag};
_S_toao  S_toao_164_1 = {&var158,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var157,&bFirstEnterFlag};
_S_to3val  S_to3val_159_1 = {&var284,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERB0MT01RIM,&var158,&var159,&var160,&bFirstEnterFlag};
_S_toao  S_toao_169_1 = {&var168,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var161,&bFirstEnterFlag};
_S_toao  S_toao_168_1 = {&var167,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var162,&bFirstEnterFlag};
_S_twobool  S_twobool_1035_1 = {&var183,&iEM_TERR6SS21LIM,&var163,&vainSBool,&internal1_m1035_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_152_1 = {&var285,&iEM_TERB7MS31LIM,&var164,&vainSBool,&internal1_m152_Out10,&bFirstEnterFlag};
_S_toao  S_toao_167_1 = {&var166,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var165,&bFirstEnterFlag};
_S_to3val  S_to3val_161_1 = {&var335,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERA0MT01RIM,&var166,&var167,&var168,&bFirstEnterFlag};
_S_twobool  S_twobool_151_1 = {&var336,&iEM_TERA7MS31LIM,&var169,&vainSBool,&internal1_m151_Out10,&bFirstEnterFlag};
_S_orn  S_orn_905_1 = {array_m905_x_1,&iRM_2_,&var170};
_S_andn  S_andn_900_1 = {array_m900_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_904_1 = {&var170,&var171};
_S_noto  S_noto_503_1 = {&B3AD34LDU,&var172};
_S_lk  S_lk_507_1 = {&fEM_A3UP02RDU,&var172,&var173};
_S_noto  S_noto_501_1 = {&A3AD34LDU,&var174};
_S_lk  S_lk_506_1 = {&fEM_A3UP02RDU,&var174,&var175};
_S_andn  S_andn_925_1 = {array_m925_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_930_1 = {&var42,&var176};
_S_andn  S_andn_918_1 = {array_m918_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_921_1 = {&var43,&var177};
_S_andn  S_andn_910_1 = {array_m910_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_914_1 = {&var44,&var178};
_S_orn  S_orn_616_1 = {array_m616_x_1,&iRM_2_,&var179};
_S_orn  S_orn_613_1 = {array_m613_x_1,&iRM_2_,&var180};
_S_react  S_react_203_1 = {&var286,&var181};
_S_noto  S_noto_468_1 = {&lEM_R6AD10LC1,&var182};
_S_asmot  S_asmot_470_1 = {&var182,&lEM_R6AD10LC1,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R6UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R6UC01RSP,&vainSFloat,&var183,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m470_X00,&internal1_m470_V00,&internal1_m470_Pav0,&internal1_m470_Zav0,&internal1_m470_Pv0,&internal1_m470_Zv0,&internal1_m470_RA00,&internal1_m470_RA10,&internal1_m470_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_482_1 = {&var30,&var31,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R5UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R5UC01RSP,&vainSFloat,&var184,&var185,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m482_X00,&internal1_m482_V00,&internal1_m482_Pav0,&internal1_m482_Zav0,&internal1_m482_Pv0,&internal1_m482_Zv0,&internal1_m482_RA00,&internal1_m482_RA10,&internal1_m482_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_472_1 = {&var32,&var33,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R3UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R3UC01RSP,&vainSFloat,&var186,&var187,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m472_X00,&internal1_m472_V00,&internal1_m472_Pav0,&internal1_m472_Zav0,&internal1_m472_Pv0,&internal1_m472_Zv0,&internal1_m472_RA00,&internal1_m472_RA10,&internal1_m472_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_601_1 = {&A4AD10LDU,&var188};
_S_asmot  S_asmot_605_1 = {&var188,&A4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A4MC01RSP,&vainSFloat,&var189,&var190,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m605_X00,&internal1_m605_V00,&internal1_m605_Pav0,&internal1_m605_Zav0,&internal1_m605_Pv0,&internal1_m605_Zv0,&internal1_m605_RA00,&internal1_m605_RA10,&internal1_m605_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_599_1 = {&B4AD10LDU,&var191};
_S_asmot  S_asmot_604_1 = {&var191,&B4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B4MC01RSP,&vainSFloat,&var192,&var193,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m604_X00,&internal1_m604_V00,&internal1_m604_Pav0,&internal1_m604_Zav0,&internal1_m604_Pv0,&internal1_m604_Zv0,&internal1_m604_RA00,&internal1_m604_RA10,&internal1_m604_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_590_1 = {&A9AD10LDU,&var194};
_S_asmot  S_asmot_592_1 = {&var194,&A9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A9MC01RSP,&vainSFloat,&var195,&var196,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m592_X00,&internal1_m592_V00,&internal1_m592_Pav0,&internal1_m592_Zav0,&internal1_m592_Pv0,&internal1_m592_Zv0,&internal1_m592_RA00,&internal1_m592_RA10,&internal1_m592_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_589_1 = {&B9AD10LDU,&var197};
_S_asmot  S_asmot_591_1 = {&var197,&B9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B9MC01RSP,&vainSFloat,&var198,&var199,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m591_X00,&internal1_m591_V00,&internal1_m591_Pav0,&internal1_m591_Zav0,&internal1_m591_Pv0,&internal1_m591_Zv0,&internal1_m591_RA00,&internal1_m591_RA10,&internal1_m591_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orn  S_orn_622_1 = {array_m622_x_1,&iRM_3_,&var200};
_S_andn  S_andn_902_1 = {array_m902_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_907_1 = {&var45,&var201};
_S_andn  S_andn_291_1 = {array_m291_x_1,&iRM_2_,&var202};
_S_andn  S_andn_257_1 = {array_m257_x_1,&iRM_3_,&var203};
_S_noto  S_noto_256_1 = {&C2MD31LP1,&var204};
_S_andn  S_andn_258_1 = {array_m258_x_1,&iRM_3_,&var205};
_S_noto  S_noto_218_1 = {&C1MD31LP2,&var206};
_S_noto  S_noto_217_1 = {&C1MD31LP1,&var207};
_S_andn  S_andn_220_1 = {array_m220_x_1,&iRM_4_,&var208};
_S_andn  S_andn_219_1 = {array_m219_x_1,&iRM_4_,&var209};
_S_andn  S_andn_124_1 = {array_m124_x_1,&iRM_2_,&var210};
_S_noto  S_noto_52_1 = {&C1MD31LP2,&var211};
_S_noto  S_noto_51_1 = {&C1MD31LP1,&var212};
_S_andn  S_andn_54_1 = {array_m54_x_1,&iRM_4_,&var213};
_S_andn  S_andn_53_1 = {array_m53_x_1,&iRM_4_,&var214};
_S_andn  S_andn_91_1 = {array_m91_x_1,&iRM_3_,&var215};
_S_noto  S_noto_90_1 = {&C2MD31LP1,&var216};
_S_andn  S_andn_92_1 = {array_m92_x_1,&iRM_3_,&var217};
_S_noto  S_noto_621_1 = {&var200,&var218};
_S_orn  S_orn_629_1 = {array_m629_x_1,&iRM_2_,&var219};
_S_fsubo  S_fsubo_370_1 = {&fEM_R7UY00RSS,&var41,&var220};
_S_fsubo  S_fsubo_118_1 = {&fEM_A2UC05RIM,&var311,&var221};
_S_fsubo  S_fsubo_284_1 = {&fEM_A2UC05RIM,&var303,&var222};
_S_fsubo  S_fsubo_246_1 = {&fEM_A1UC05RIM,&var319,&var223};
_S_fsubo  S_fsubo_80_1 = {&fEM_A1UC05RIM,&var326,&var224};
_S_fsubo  S_fsubo_8_1 = {&var226,&fEM_R0UR01RIM,&var225};
_S_inf  S_inf_7_1 = {&var272,array_m7_a_1,array_m7_b_1,&iRM_5_,&var226,&vainSInt};
_S_inf  S_inf_9_1 = {&var272,array_m9_a_1,array_m9_b_1,&iRM_7_,&var227,&vainSInt};
_S_mod1  S_mod1_634_1 = {&var287,&fEM_R7UI02RIM,&fEM_R7UL01RIM,&var228,&internal1_m634_y0};
_S_bol  S_bol_628_1 = {&var287,&fEM_R7UI73RIM,&var229};
_S_bol  S_bol_618_1 = {&var287,&fEM_R7UI72RIM,&var230};
_S_bol  S_bol_612_1 = {&var287,&fEM_R7UI71RIM,&var231};
_S_vchs  S_vchs_799_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_5_,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var232,&internal1_m799_Chim0};
_S_vchs  S_vchs_790_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&bRM_4_,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var233,&internal1_m790_Chim0};
_S_vchs  S_vchs_782_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&bRM_1_,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var234,&internal1_m782_Chim0};
_S_vchs  S_vchs_773_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_5_,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var235,&internal1_m773_Chim0};
_S_vchs  S_vchs_764_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&bRM_4_,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var236,&internal1_m764_Chim0};
_S_vchs  S_vchs_756_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&bRM_1_,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var237,&internal1_m756_Chim0};
_S_vchs  S_vchs_747_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_5_,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var238,&internal1_m747_Chim0};
_S_vchs  S_vchs_738_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&bRM_4_,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var239,&internal1_m738_Chim0};
_S_vchs  S_vchs_730_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&bRM_2_,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var240,&internal1_m730_Chim0};
_S_vchs  S_vchs_721_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UC10RIM,&fEM_R7UC19RIM,&bRM_5_,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var241,&internal1_m721_Chim0};
_S_vchs  S_vchs_712_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&bRM_4_,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var242,&internal1_m712_Chim0};
_S_fsumo  S_fsumo_896_1 = {&fEM_R4UC10RIM,&fEM_R4UC22RIM,&var243};
_S_vchs  S_vchs_702_1 = {&var333,&var282,&var243,&fEM_R7UY00RSS,&var220,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&bRM_2_,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var244,&internal1_m702_Chim0};
_S_asmot  S_asmot_579_1 = {&B5AD10LDU,&B5AD20LDU,&fEM_B5MC01RC1,&fEM_B5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL2,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_B5MC01RSP,&vainSFloat,&var245,&var246,&vainSBool,&vainSBool,&vainSFloat,&var247,&var248,&internal1_m579_X00,&internal1_m579_V00,&internal1_m579_Pav0,&internal1_m579_Zav0,&internal1_m579_Pv0,&internal1_m579_Zv0,&internal1_m579_RA00,&internal1_m579_RA10,&internal1_m579_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_565_1 = {&A5AD10LDU,&A5AD20LDU,&fEM_A5MC01RC1,&fEM_A5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL1,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_A5MC01RSP,&vainSFloat,&var249,&var250,&vainSBool,&vainSBool,&vainSFloat,&var251,&var252,&internal1_m565_X00,&internal1_m565_V00,&internal1_m565_Pav0,&internal1_m565_Zav0,&internal1_m565_Pv0,&internal1_m565_Zv0,&internal1_m565_RA00,&internal1_m565_RA10,&internal1_m565_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_456_1 = {&R2AD10LDU,&R2AD20LDU,&fEM_R2MC01RC1,&fEM_R2MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ2,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R2MC01RSP,&vainSFloat,&var253,&var254,&vainSBool,&vainSBool,&vainSFloat,&var255,&var256,&internal1_m456_X00,&internal1_m456_V00,&internal1_m456_Pav0,&internal1_m456_Zav0,&internal1_m456_Pv0,&internal1_m456_Zv0,&internal1_m456_RA00,&internal1_m456_RA10,&internal1_m456_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_442_1 = {&R1AD10LDU,&R1AD20LDU,&fEM_R1MC01RC1,&fEM_R1MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ1,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R1MC01RSP,&vainSFloat,&var257,&var258,&vainSBool,&vainSBool,&vainSFloat,&var259,&var260,&internal1_m442_X00,&internal1_m442_V00,&internal1_m442_Pav0,&internal1_m442_Zav0,&internal1_m442_Pv0,&internal1_m442_Zv0,&internal1_m442_RA00,&internal1_m442_RA10,&internal1_m442_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_493_1 = {&B6AD10LDU,&B6AD20LDU,&fEM_B6MC01RC1,&fEM_B6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ2,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_B6MC01RSP,&vainSFloat,&var261,&var262,&vainSBool,&vainSBool,&vainSFloat,&var263,&var264,&internal1_m493_X00,&internal1_m493_V00,&internal1_m493_Pav0,&internal1_m493_Zav0,&internal1_m493_Pv0,&internal1_m493_Zv0,&internal1_m493_RA00,&internal1_m493_RA10,&internal1_m493_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_394_1 = {&A6AD10LDU,&A6AD20LDU,&fEM_A6MC01RC1,&fEM_A6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ1,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_A6MC01RSP,&vainSFloat,&var265,&var266,&vainSBool,&vainSBool,&vainSFloat,&var267,&var268,&internal1_m394_X00,&internal1_m394_V00,&internal1_m394_Pav0,&internal1_m394_Zav0,&internal1_m394_Pv0,&internal1_m394_Zv0,&internal1_m394_RA00,&internal1_m394_RA10,&internal1_m394_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_379_1 = {&A8AD20LDU,&A8AD10LDU,&fEM_A8MC01RC1,&fEM_A8MV01RC1,&fEM_A8UV80RDU,&fEM_A8US80RDU,&iEM_TERDS2,&fEM_A8UC10RIM,&fEM_A8UC20RIM,&fEM_A8UC11RIM,&fEM_A8UC21RIM,&fEM_A8UC08RDU,&fEM_A8MC01RSP,&var269,&var270,&var271,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m379_X00,&internal1_m379_V00,&internal1_m379_Pav0,&internal1_m379_Zav0,&internal1_m379_Pv0,&internal1_m379_Zv0,&internal1_m379_RA00,&internal1_m379_RA10,&internal1_m379_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_363_1 = {&B8AD20LDU,&B8AD10LDU,&fEM_B8MC01RC1,&fEM_B8MV01RC1,&fEM_B8UV80RDU,&fEM_B8US80RDU,&iEM_TERMAZ2,&fEM_B8UC10RIM,&fEM_B8UC20RIM,&fEM_B8UC11RIM,&fEM_B8UC21RIM,&fEM_B8UC08RDU,&fEM_B8MC01RSP,&var272,&var273,&var274,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m363_X00,&internal1_m363_V00,&internal1_m363_Pav0,&internal1_m363_Zav0,&internal1_m363_Pv0,&internal1_m363_Zv0,&internal1_m363_RA00,&internal1_m363_RA10,&internal1_m363_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_892_1 = {&R4AD10LDU,&R4AD20LDU,&fEM_R4MC01RC1,&fEM_R4MV01RC1,&fEM_R4UV80RDU,&fEM_R4US80RDU,&iEM_TERTLG,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC08RDU,&fEM_R4MC01RSP,&vainSFloat,&var275,&var276,&var277,&var278,&vainSFloat,&var279,&var280,&internal1_m892_X00,&internal1_m892_V00,&internal1_m892_Pav0,&internal1_m892_Zav0,&internal1_m892_Pv0,&internal1_m892_Zv0,&internal1_m892_RA00,&internal1_m892_RA10,&internal1_m892_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_185_1 = {&var318,&var302,&var288,&var332,&fEM_R0UR30RIM,&B7AP31LDU,&var192,&lEM_R8AD10LC1,&var1,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_A0UN07RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var225,&var227,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_B0UT03RSP,&var281,&var282,&var283,&var284,&var285,&var286,&var287,&internal1_m185_C1,&internal1_m185_C2,&internal1_m185_C3,&internal1_m185_C4,&internal1_m185_C5,&internal1_m185_C6,&internal1_m185_N20,&internal1_m185_N00,&internal1_m185_R00,&internal1_m185_T00,&internal1_m185_ImpINI0,&internal1_m185_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_299_1 = {&B3AD11LDU,&B3AD21LDU,&B3AD02LDU,&B3AD01LDU,&B3AD03LDU,&B3AD04LDU,&B3AD05LDU,&var202,&B3AD33LDU,&lRM_1_,&fEM_B3MC01RC1,&fEM_B3MC02RC1,&fEM_B3MV01RC1,&fEM_B3MV02RC1,&lRM_0_,array_m299_Vr_1,&fEM_A3UC02RDU,&var173,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS2,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_B3MC01RSP,&fEM_B3MC02RSP,&var288,&var289,&var290,&var291,&var292,&vainSFloat,&vainSFloat,&var293,&var294,&vainSBool,&vainSBool,&internal1_m299_X00,&internal1_m299_Sh00,&internal1_m299_RV00,&internal1_m299_ShV00,&internal1_m299_Ppv0,&internal1_m299_Pav0,&internal1_m299_Zav0,&internal1_m299_RA00,&internal1_m299_RA10,&internal1_m299_RA30,&internal1_m299_RA50,&internal1_m299_fls,&internal1_m299_flp,&internal1_m299_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_134_1 = {&A3AD11LDU,&A3AD21LDU,&A3AD02LDU,&A3AD01LDU,&A3AD03LDU,&A3AD04LDU,&A3AD05LDU,&var210,&A3AD33LDU,&lRM_1_,&fEM_A3MC01RC1,&fEM_A3MC02RC1,&fEM_A3MV01RC1,&fEM_A3MV02RC1,&lRM_0_,array_m134_Vr_1,&fEM_A3UC02RDU,&var175,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS1,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_A3MC01RSP,&fEM_A3MC02RSP,&var295,&var296,&var297,&var298,&var299,&vainSFloat,&vainSFloat,&var300,&var301,&vainSBool,&vainSBool,&internal1_m134_X00,&internal1_m134_Sh00,&internal1_m134_RV00,&internal1_m134_ShV00,&internal1_m134_Ppv0,&internal1_m134_Pav0,&internal1_m134_Zav0,&internal1_m134_RA00,&internal1_m134_RA10,&internal1_m134_RA30,&internal1_m134_RA50,&internal1_m134_fls,&internal1_m134_flp,&internal1_m134_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_269_1 = {&B2AD11LDU,&B2AD21LDU,&B2AD02LDU,&B2AD01LDU,&B2AD03LDU,&B2AD04LDU,&B2AD05LDU,&var203,&B2AD33LDU,&var205,&fEM_B2MC01RC1,&fEM_B2MC02RC1,&fEM_B2MV01RC1,&fEM_B2MV02RC1,&lRM_1_,array_m269_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB2,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_B2MC01RSP,&fEM_B2MC02RSP,&var302,&var303,&vainSBool,&var304,&var305,&vainSFloat,&vainSFloat,&var306,&var307,&var308,&var309,&internal1_m269_X00,&internal1_m269_Sh00,&internal1_m269_RV00,&internal1_m269_ShV00,&internal1_m269_Ppv0,&internal1_m269_Pav0,&internal1_m269_Zav0,&internal1_m269_RA00,&internal1_m269_RA10,&internal1_m269_RA30,&internal1_m269_RA50,&internal1_m269_fls,&internal1_m269_flp,&internal1_m269_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_100_1 = {&A2AD11LDU,&A2AD21LDU,&A2AD02LDU,&A2AD01LDU,&A2AD03LDU,&A2AD04LDU,&A2AD05LDU,&var215,&A2AD33LDU,&var217,&fEM_A2MC01RC1,&fEM_A2MC02RC1,&fEM_A2MV01RC1,&fEM_A2MV02RC1,&lRM_1_,array_m100_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB1,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_A2MC01RSP,&fEM_A2MC02RSP,&var310,&var311,&vainSBool,&var312,&var313,&vainSFloat,&vainSFloat,&var314,&var315,&var316,&var317,&internal1_m100_X00,&internal1_m100_Sh00,&internal1_m100_RV00,&internal1_m100_ShV00,&internal1_m100_Ppv0,&internal1_m100_Pav0,&internal1_m100_Zav0,&internal1_m100_RA00,&internal1_m100_RA10,&internal1_m100_RA30,&internal1_m100_RA50,&internal1_m100_fls,&internal1_m100_flp,&internal1_m100_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_234_1 = {&B1AD11LDU,&B1AD21LDU,&B1AD02LDU,&B1AD01LDU,&B1AD03LDU,&B1AD04LDU,&B1AD05LDU,&var209,&lRM_1_,&var208,&fEM_B1MC01RC1,&fEM_B1MC02RC1,&fEM_B1MV01RC1,&fEM_B1MV02RC1,&lRM_1_,array_m234_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB2,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_B1MC01RSP,&fEM_B1MC02RSP,&var318,&var319,&vainSBool,&var320,&var321,&vainSFloat,&vainSFloat,&var322,&vainSBool,&var323,&var324,&internal1_m234_X00,&internal1_m234_Sh00,&internal1_m234_RV00,&internal1_m234_ShV00,&internal1_m234_Ppv0,&internal1_m234_Pav0,&internal1_m234_Zav0,&internal1_m234_RA00,&internal1_m234_RA10,&internal1_m234_RA30,&internal1_m234_RA50,&internal1_m234_fls,&internal1_m234_flp,&internal1_m234_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_66_1 = {&A1AD11LDU,&A1AD21LDU,&A1AD02LDU,&A1AD01LDU,&A1AD03LDU,&A1AD04LDU,&A1AD05LDU,&var214,&lRM_1_,&var213,&fEM_A1MC01RC1,&fEM_A1MC02RC1,&fEM_A1MV01RC1,&fEM_A1MV02RC1,&lRM_1_,array_m66_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB1,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_A1MC01RSP,&fEM_A1MC02RSP,&var325,&var326,&var327,&var328,&var329,&vainSFloat,&vainSFloat,&vainSBool,&vainSBool,&var330,&var331,&internal1_m66_X00,&internal1_m66_Sh00,&internal1_m66_RV00,&internal1_m66_ShV00,&internal1_m66_Ppv0,&internal1_m66_Pav0,&internal1_m66_Zav0,&internal1_m66_RA00,&internal1_m66_RA10,&internal1_m66_RA30,&internal1_m66_RA50,&internal1_m66_fls,&internal1_m66_flp,&internal1_m66_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_14_1 = {&var325,&var310,&var295,&var281,&fEM_R0UR30RIM,&A7AP31LDU,&var189,&lEM_R8AD10LC1,&var1,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_A0UN07RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var225,&var227,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_A0UT03RSP,&var332,&var333,&var334,&var335,&var336,&var337,&vainSFloat,&internal1_m14_C1,&internal1_m14_C2,&internal1_m14_C3,&internal1_m14_C4,&internal1_m14_C5,&internal1_m14_C6,&internal1_m14_N20,&internal1_m14_N00,&internal1_m14_R00,&internal1_m14_T00,&internal1_m14_ImpINI0,&internal1_m14_MyFirstEnterFlag,&bFirstEnterFlag};


void ZeroVar()
{
   var1.b=0;
   var2.b=0;
   var3.f=0.0;
   var4.f=0.0;
   var5.f=0.0;
   var6.f=0.0;
   var7.f=0.0;
   var8.f=0.0;
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
   var41.f=0.0;
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
   var55.l=0L;
   var56.f=0.0;
   var57.l=0L;
   var58.f=0.0;
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
   var93.i=0;
   var94.i=0;
   var95.f=0.0;
   var96.f=0.0;
   var97.l=0L;
   var98.f=0.0;
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
   var110.f=0.0;
   var111.b=0;
   var112.b=0;
   var113.l=0L;
   var114.f=0.0;
   var115.l=0L;
   var116.f=0.0;
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
   var128.i=0;
   var129.f=0.0;
   var130.b=0;
   var131.b=0;
   var132.i=0;
   var133.f=0.0;
   var134.b=0;
   var135.l=0L;
   var136.f=0.0;
   var137.b=0;
   var138.b=0;
   var139.l=0L;
   var140.f=0.0;
   var141.b=0;
   var142.i=0;
   var143.i=0;
   var144.b=0;
   var145.b=0;
   var146.b=0;
   var147.l=0L;
   var148.f=0.0;
   var149.b=0;
   var150.b=0;
   var151.b=0;
   var152.f=0.0;
   var153.f=0.0;
   var154.f=0.0;
   var155.i=0;
   var156.i=0;
   var157.i=0;
   var158.f=0.0;
   var159.f=0.0;
   var160.f=0.0;
   var161.i=0;
   var162.i=0;
   var163.b=0;
   var164.b=0;
   var165.i=0;
   var166.f=0.0;
   var167.f=0.0;
   var168.f=0.0;
   var169.b=0;
   var170.b=0;
   var171.b=0;
   var172.b=0;
   var173.f=0.0;
   var174.b=0;
   var175.f=0.0;
   var176.b=0;
   var177.b=0;
   var178.b=0;
   var179.b=0;
   var180.b=0;
   var181.f=0.0;
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
   var220.f=0.0;
   var221.f=0.0;
   var222.f=0.0;
   var223.f=0.0;
   var224.f=0.0;
   var225.f=0.0;
   var226.f=0.0;
   var227.f=0.0;
   var228.f=0.0;
   var229.b=0;
   var230.b=0;
   var231.b=0;
   var232.f=0.0;
   var233.f=0.0;
   var234.f=0.0;
   var235.f=0.0;
   var236.f=0.0;
   var237.f=0.0;
   var238.f=0.0;
   var239.f=0.0;
   var240.f=0.0;
   var241.f=0.0;
   var242.f=0.0;
   var243.f=0.0;
   var244.f=0.0;
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
   var269.f=0.0;
   var270.b=0;
   var271.b=0;
   var272.f=0.0;
   var273.b=0;
   var274.b=0;
   var275.b=0;
   var276.b=0;
   var277.b=0;
   var278.b=0;
   var279.b=0;
   var280.b=0;
   var281.f=0.0;
   var282.f=0.0;
   var283.f=0.0;
   var284.f=0.0;
   var285.b=0;
   var286.f=0.0;
   var287.f=0.0;
   var288.f=0.0;
   var289.f=0.0;
   var290.b=0;
   var291.b=0;
   var292.b=0;
   var293.b=0;
   var294.b=0;
   var295.f=0.0;
   var296.f=0.0;
   var297.b=0;
   var298.b=0;
   var299.b=0;
   var300.b=0;
   var301.b=0;
   var302.f=0.0;
   var303.f=0.0;
   var304.b=0;
   var305.b=0;
   var306.b=0;
   var307.b=0;
   var308.b=0;
   var309.b=0;
   var310.f=0.0;
   var311.f=0.0;
   var312.b=0;
   var313.b=0;
   var314.b=0;
   var315.b=0;
   var316.b=0;
   var317.b=0;
   var318.f=0.0;
   var319.f=0.0;
   var320.b=0;
   var321.b=0;
   var322.b=0;
   var323.b=0;
   var324.b=0;
   var325.f=0.0;
   var326.f=0.0;
   var327.b=0;
   var328.b=0;
   var329.b=0;
   var330.b=0;
   var331.b=0;
   var332.f=0.0;
   var333.f=0.0;
   var334.f=0.0;
   var335.f=0.0;
   var336.b=0;
   var337.f=0.0;
   vainSLong.l=0L;
   vainSFloat.f=0.0;
   vainSInt.i=0;
   vainSBool.b=0;
   vainSChar.c=0;

}
int freebuff = 0;
void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_90_1);
  noto(&S_noto_256_1);
  noto(&S_noto_589_1);
  noto(&S_noto_590_1);
  noto(&S_noto_503_1);
  bol(&S_bol_928_1);
  bol(&S_bol_938_1);
  bol(&S_bol_916_1);
  bol(&S_bol_937_1);
  bol(&S_bol_940_1);
  zpfs(&S_zpfs_614_1);
  zpfs(&S_zpfs_626_1);
  noto(&S_noto_473_1);
  noto(&S_noto_471_1);
  noto(&S_noto_481_1);
  noto(&S_noto_480_1);
  to3val(&S_to3val_954_1);
  looktakt(&S_looktakt_150_1);
  asmot(&S_asmot_892_1);
  asmot(&S_asmot_363_1);
  asmot(&S_asmot_379_1);
  asmot(&S_asmot_394_1);
  asmot(&S_asmot_493_1);
  asmot(&S_asmot_442_1);
  asmot(&S_asmot_456_1);
  asmot(&S_asmot_565_1);
  asmot(&S_asmot_579_1);
  fsumo(&S_fsumo_896_1);
  inf(&S_inf_9_1);
  inf(&S_inf_7_1);
  fsubo(&S_fsubo_8_1);
  noto(&S_noto_51_1);
  noto(&S_noto_52_1);
  noto(&S_noto_217_1);
  noto(&S_noto_218_1);
  orn(&S_orn_622_1);
  asmot(&S_asmot_591_1);
  asmot(&S_asmot_592_1);
  noto(&S_noto_599_1);
  noto(&S_noto_601_1);
  noto(&S_noto_468_1);
  noto(&S_noto_501_1);
  lk(&S_lk_507_1);
  orn(&S_orn_905_1);
  to3val(&S_to3val_530_1);
  toao(&S_toao_535_1);
  toao(&S_toao_536_1);
  to3val(&S_to3val_508_1);
  toao(&S_toao_514_1);
  twobool(&S_twobool_551_1);
  twobool(&S_twobool_648_1);
  twobool(&S_twobool_668_1);
  twobool(&S_twobool_649_1);
  twobool(&S_twobool_669_1);
  twobool(&S_twobool_685_1);
  to3val(&S_to3val_828_1);
  ktoenc(&S_ktoenc_836_1);
  to3val(&S_to3val_826_1);
  ktoenc(&S_ktoenc_834_1);
  twobool(&S_twobool_549_1);
  twobool(&S_twobool_550_1);
  twobool(&S_twobool_687_1);
  twobool(&S_twobool_686_1);
  twobool(&S_twobool_689_1);
  twobool(&S_twobool_688_1);
  twobool(&S_twobool_1036_1);
  twobool(&S_twobool_852_1);
  twobool(&S_twobool_854_1);
  twobool(&S_twobool_853_1);
  to3val(&S_to3val_531_1);
  toao(&S_toao_537_1);
  toao(&S_toao_538_1);
  twobool(&S_twobool_534_1);
  twobool(&S_twobool_980_1);
  twobool(&S_twobool_995_1);
  twobool(&S_twobool_1012_1);
  twobool(&S_twobool_1034_1);
  twobool(&S_twobool_815_1);
  twobool(&S_twobool_981_1);
  twobool(&S_twobool_982_1);
  twobool(&S_twobool_983_1);
  twobool(&S_twobool_984_1);
  twobool(&S_twobool_1032_1);
  twobool(&S_twobool_811_1);
  twobool(&S_twobool_812_1);
  twobool(&S_twobool_814_1);
  twobool(&S_twobool_813_1);
  twobool(&S_twobool_839_1);
  twobool(&S_twobool_837_1);
  twobool(&S_twobool_840_1);
  twobool(&S_twobool_838_1);
  twobool(&S_twobool_1016_1);
  twobool(&S_twobool_1017_1);
  twobool(&S_twobool_1018_1);
  twobool(&S_twobool_1037_1);
  twobool(&S_twobool_62_1);
  twobool(&S_twobool_47_1);
  twobool(&S_twobool_228_1);
  twobool(&S_twobool_210_1);
  zpfs(&S_zpfs_600_1);
  zpfs(&S_zpfs_602_1);
  or2(&S_or2_906_1);
  or2(&S_or2_913_1);
  or2(&S_or2_920_1);
  or2(&S_or2_929_1);
  ampl(&S_ampl_368_1);
  rs(&S_rs_467_1);
  rs(&S_rs_466_1);
  rs(&S_rs_479_1);
  rs(&S_rs_478_1);
  twobool(&S_twobool_533_1);
  twobool(&S_twobool_517_1);
  twobool(&S_twobool_650_1);
  twobool(&S_twobool_651_1);
  twobool(&S_twobool_672_1);
  twobool(&S_twobool_673_1);
  twobool(&S_twobool_652_1);
  twobool(&S_twobool_653_1);
  twobool(&S_twobool_674_1);
  twobool(&S_twobool_675_1);
  twobool(&S_twobool_996_1);
  twobool(&S_twobool_997_1);
  twobool(&S_twobool_998_1);
  twobool(&S_twobool_999_1);
  twobool(&S_twobool_816_1);
  twobool(&S_twobool_817_1);
  fsubo(&S_fsubo_370_1);
  noto(&S_noto_621_1);
  andn(&S_andn_92_1);
  andn(&S_andn_91_1);
  andn(&S_andn_53_1);
  andn(&S_andn_54_1);
  andn(&S_andn_124_1);
  andn(&S_andn_219_1);
  andn(&S_andn_220_1);
  andn(&S_andn_258_1);
  andn(&S_andn_257_1);
  andn(&S_andn_291_1);
  noto(&S_noto_907_1);
  andn(&S_andn_902_1);
  asmot(&S_asmot_604_1);
  asmot(&S_asmot_605_1);
  asmot(&S_asmot_472_1);
  asmot(&S_asmot_482_1);
  asmot(&S_asmot_470_1);
  noto(&S_noto_914_1);
  andn(&S_andn_910_1);
  noto(&S_noto_921_1);
  andn(&S_andn_918_1);
  noto(&S_noto_930_1);
  andn(&S_andn_925_1);
  lk(&S_lk_506_1);
  noto(&S_noto_904_1);
  andn(&S_andn_900_1);
  twobool(&S_twobool_1035_1);
  to3val(&S_to3val_505_1);
  toao(&S_toao_516_1);
  twobool(&S_twobool_1013_1);
  twobool(&S_twobool_1015_1);
  twobool(&S_twobool_1014_1);
  twobool(&S_twobool_1033_1);
  orrsim(&S_orrsim_66_1);
  orrsim(&S_orrsim_234_1);
  orrsim(&S_orrsim_100_1);
  orrsim(&S_orrsim_269_1);
  orrsim(&S_orrsim_134_1);
  orrsim(&S_orrsim_299_1);
  fsubo(&S_fsubo_80_1);
  fsubo(&S_fsubo_246_1);
  fsubo(&S_fsubo_284_1);
  fsubo(&S_fsubo_118_1);
  twobool(&S_twobool_424_1);
  twobool(&S_twobool_425_1);
  twobool(&S_twobool_426_1);
  to3val(&S_to3val_423_1);
  ktoenc(&S_ktoenc_428_1);
  twobool(&S_twobool_427_1);
  twobool(&S_twobool_334_1);
  twobool(&S_twobool_318_1);
  twobool(&S_twobool_347_1);
  to3val(&S_to3val_322_1);
  ktoenc(&S_ktoenc_326_1);
  twobool(&S_twobool_346_1);
  twobool(&S_twobool_348_1);
  to3val(&S_to3val_332_1);
  ktoenc(&S_ktoenc_333_1);
  twobool(&S_twobool_349_1);
  twobool(&S_twobool_319_1);
  twobool(&S_twobool_320_1);
  twobool(&S_twobool_335_1);
  twobool(&S_twobool_336_1);
  twobool(&S_twobool_407_1);
  twobool(&S_twobool_408_1);
  twobool(&S_twobool_406_1);
  to3val(&S_to3val_409_1);
  ktoenc(&S_ktoenc_415_1);
  twobool(&S_twobool_949_1);
  twobool(&S_twobool_950_1);
  twobool(&S_twobool_953_1);
  to3val(&S_to3val_945_1);
  ktoenc(&S_ktoenc_952_1);
  to3val(&S_to3val_964_1);
  ktoenc(&S_ktoenc_969_1);
  twobool(&S_twobool_966_1);
  twobool(&S_twobool_967_1);
  twobool(&S_twobool_970_1);
  andn(&S_andn_354_1);
  twobool(&S_twobool_405_1);
  kvds(&S_kvds_39_1);
  azbars(&S_azbars_185_1);
  bol(&S_bol_612_1);
  bol(&S_bol_618_1);
  bol(&S_bol_628_1);
  mod1(&S_mod1_634_1);
  orn(&S_orn_629_1);
  react(&S_react_203_1);
  orn(&S_orn_613_1);
  orn(&S_orn_616_1);
  twobool(&S_twobool_152_1);
  to3val(&S_to3val_159_1);
  toao(&S_toao_164_1);
  toao(&S_toao_165_1);
  toao(&S_toao_166_1);
  ampl(&S_ampl_639_1);
  azbars(&S_azbars_14_1);
  vchs(&S_vchs_702_1);
  vchs(&S_vchs_712_1);
  vchs(&S_vchs_721_1);
  vchs(&S_vchs_730_1);
  vchs(&S_vchs_738_1);
  vchs(&S_vchs_747_1);
  vchs(&S_vchs_756_1);
  vchs(&S_vchs_764_1);
  vchs(&S_vchs_773_1);
  vchs(&S_vchs_782_1);
  vchs(&S_vchs_790_1);
  vchs(&S_vchs_799_1);
  twobool(&S_twobool_151_1);
  to3val(&S_to3val_161_1);
  toao(&S_toao_167_1);
  toao(&S_toao_168_1);
  toao(&S_toao_169_1);
  to3val(&S_to3val_640_1);
  vchs(&S_vchs_862_1);
  vchs(&S_vchs_870_1);
  vchs(&S_vchs_880_1);
  setData(idR8AD22LDU,&var2);
  setData(idLTAKTS,&var3);
  setData(idkrb2,&var302);
  setData(idkrb1,&var310);
  setData(idR0IS01FI0,&lRM_1_);
  setData(idA0IT03IRP,&var161);
  setData(idB0IT03IRP,&var155);
  setData(idR0IN03FI3,&var235);
  setData(idR0IN02FI3,&var236);
  setData(idR0IN03FI2,&var238);
  setData(idR0IN07RIP,&var5);
  setData(idR0IN06RIP,&var4);
  setData(idR0IN03RIP,&var6);
  setData(idR0IN02RIP,&var7);
  setData(idR0IN01RIP,&var8);
  setData(idR0IN02FI2,&var239);
  setData(idR0IN03FI1,&var241);
  setData(idR0IN02FI1,&var242);
  setData(idR0IN03FI4,&var232);
  setData(idR0IN02FI4,&var233);
  setData(idR0IN01FI3,&var237);
  setData(idR0IN01FI2,&var240);
  setData(idR0IN01FI4,&var234);
  setData(idR0IN01FI1,&var244);
  setData(idR4VS12LDU,&var10);
  setData(idR4VS22LDU,&var9);
  setData(idR1VS12LDU,&var14);
  setData(idR2VS12LDU,&var12);
  setData(idR2VS22LDU,&var11);
  setData(idR1VS22LDU,&var13);
  setData(idB5VS12LDU,&var16);
  setData(idB5VS22LDU,&var15);
  setData(idA5VS12LDU,&var18);
  setData(idA5VS22LDU,&var17);
  setData(idB6VS12LDU,&var20);
  setData(idB6VS22LDU,&var19);
  setData(idA6VS12LDU,&var22);
  setData(idA6VS22LDU,&var21);
  setData(idB8IS21LDU,&var70);
  setData(idB8IS11LDU,&var68);
  setData(idA1VP81LZZ,&var23);
  setData(idB1VP81LZZ,&var24);
  setData(idB2IS33LDU,&var25);
  setData(idA0VN01RIM,&var337);
  setData(idB2IS32LIM,&var306);
  setData(idB2IS11LIM,&var308);
  setData(idA2IS32LIM,&var314);
  setData(idA2IS11LIM,&var316);
  setData(idB1IS32LIM,&var322);
  setData(idB1IS11LIM,&var323);
  setData(idA1IS32LIM,&var327);
  setData(idA1IS11LIM,&var330);
  setData(idR0IS02LDU,&lEM_R0IE02LRP);
  setData(idB4IS10LDU,&var47);
  setData(idA4IS10LDU,&var46);
  setData(idB1IE04LDU,&var48);
  setData(idB1IE03LDU,&var49);
  setData(idA1IE04LDU,&var50);
  setData(idA1IE03LDU,&var51);
  setData(idB1IS12LDU,&var52);
  setData(idB1IS11LDU,&var53);
  setData(idB1IS21LDU,&var54);
  setData(idB1IC01UDU,&var55);
  setData(idA1IC01UDU,&var57);
  setData(idA1IS12LDU,&var59);
  setData(idA1IS11LDU,&var60);
  setData(idA1IS21LDU,&var61);
  setData(idB6IS21LDU,&var62);
  setData(idB6IS11LDU,&var63);
  setData(idA6IS21LDU,&var64);
  setData(idA6IS11LDU,&var65);
  setData(idA8IS12LDU,&var66);
  setData(idA8IS22LDU,&var67);
  setData(idB8IS12LDU,&var69);
  setData(idB8IS22LDU,&var71);
  setData(idR4IS12LDU,&var72);
  setData(idR4IS22LDU,&var73);
  setData(idR4IS21LDU,&var74);
  setData(idR4IS11LDU,&var75);
  setData(idB4VP82LDU,&var77);
  setData(idA4VP82LDU,&var76);
  setData(idR2IS21LDU,&var78);
  setData(idR2IS11LDU,&var79);
  setData(idR1IS21LDU,&var80);
  setData(idR1IS11LDU,&var81);
  setData(idB4IS21LDU,&var82);
  setData(idB4IS11LDU,&var83);
  setData(idR8IS11LDU,&var84);
  setData(idA4IS21LDU,&var85);
  setData(idA4IS11LDU,&var86);
  setData(idR5IS21LDU,&var87);
  setData(idR5IS11LDU,&var88);
  setData(idR3IS21LDU,&var89);
  setData(idR3IS11LDU,&var90);
  setData(idB2VP82LDU,&var91);
  setData(idB2IP01IZ2,&var93);
  setData(idB2IP01IZ1,&var94);
  setData(idB2IC01UDU,&var97);
  setData(idB2IS12LDU,&var99);
  setData(idB2IS11LDU,&var100);
  setData(idB2IS21LDU,&var101);
  setData(idB9IS21LDU,&var102);
  setData(idB9IS11LDU,&var103);
  setData(idA9IS21LDU,&var104);
  setData(idA9IS11LDU,&var105);
  setData(idB5IS21LDU,&var106);
  setData(idB5IS11LDU,&var107);
  setData(idA5IS21LDU,&var108);
  setData(idA5IS11LDU,&var109);
  setData(idB0VP81LZZ,&var111);
  setData(idA0VP81LZZ,&var112);
  setData(idB8IC01UDU,&var113);
  setData(idA8IC01UDU,&var115);
  setData(idR6IS68LZZ,&var117);
  setData(idR6IS67LZZ,&var118);
  setData(idR6IS66LZZ,&var119);
  setData(idR6IS65LDU,&var121);
  setData(idR6IS64LDU,&var120);
  setData(idR6IS63LDU,&var123);
  setData(idR6IS62LDU,&var122);
  setData(idB3IS22LDU,&var124);
  setData(idA3IS22LDU,&var125);
  setData(idB3IS11LDU,&var126);
  setData(idA3IS11LDU,&var127);
  setData(idA3IP02IDU,&var128);
  setData(idB3VP81LDU,&var131);
  setData(idA3VP81LDU,&var130);
  setData(idB3IS33LDU,&var134);
  setData(idB3IC01UDU,&var135);
  setData(idB3IS31LDU,&var137);
  setData(idB3IP02IDU,&var132);
  setData(idA3IS33LDU,&var138);
  setData(idA3IC01UDU,&var139);
  setData(idA3IS31LDU,&var141);
  setData(idA2VP82LDU,&var92);
  setData(idA2IP01IZ2,&var142);
  setData(idA2IP01IZ1,&var143);
  setData(idB3IS21LDU,&var144);
  setData(idA3IS21LDU,&var145);
  setData(idA2IS33LDU,&var146);
  setData(idA2IC01UDU,&var147);
  setData(idA2IS12LDU,&var149);
  setData(idA2IS11LDU,&var150);
  setData(idA2IS21LDU,&var151);
  setData(idB0IT02IZ2,&var156);
  setData(idB0IT01IZ1,&var157);
  setData(idA0IT02IZ2,&var162);
  setData(idA0IT01IZ1,&var165);
  setData(idR6IS21LDU,&var163);
  setData(idB7AS31LDU,&var164);
  setData(idA7AS31LDU,&var169);
  setData(idB3IS35LDU,&var172);
  setData(idA3IS35LDU,&var174);
  setData(idR7II73LZ2,&var219);
  setData(idR7II71LZ2,&var180);
  setData(idR7II72LZ2,&var179);
  setData(idR7II72LZ1,&var179);
  setData(idR7II71LZ1,&var180);
  setData(idR7II73LZ1,&var219);
  setData(idR0SR01RIM,&var181);
  setData(idR0ST01RIM,&var286);
  setData(idR0SR02RIM,&var287);
  setData(idR0CR02RIM,&var225);
  setData(idR0CR01RIM,&var227);
  setData(idB0SN08RIM,&var282);
  setData(idA0SN08RIM,&var333);
  setData(idB0SR01RIM,&var283);
  setData(idA0SR01RIM,&var334);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
}

void MainCycle(void)
{
if ((getAsShort(idR0DEUMLSS) == 2) || (getAsShort(idR0DEUMLSS) == 3)) { 
     freebuff = 0;
       Scheme(); 
 }
 else {
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
                 if (initAllDriversPTI(drivers))
                 return EXIT_FAILURE;
           }
           }
       }


}
#endif
