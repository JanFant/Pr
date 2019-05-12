#ifndef SCM_H
#define SCM_H
// Подсистема scm:SCM
static char SimulOn=0;
static short CodeSub=1;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt, taktScheme=0, taktSS=0;
#define SIZE_BUFFER 3437
static char BUFFER[3437];

#define A1IC01UDU	 BUFFER[0]	//( - , SDu) Координата штока ББ1
#define idA1IC01UDU	 1	//( - , SDu) Координата штока ББ1
#define A1IS12LDU	 BUFFER[5]	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define idA1IS12LDU	 2	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define A1IS11LDU	 BUFFER[7]	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define idA1IS11LDU	 3	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define A1IS21LDU	 BUFFER[9]	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define idA1IS21LDU	 4	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define B6IS21LDU	 BUFFER[11]	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define idB6IS21LDU	 5	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define B6IS11LDU	 BUFFER[13]	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define idB6IS11LDU	 6	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define A6IS21LDU	 BUFFER[15]	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define idA6IS21LDU	 7	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define A6IS11LDU	 BUFFER[17]	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define idA6IS11LDU	 8	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define A8IS12LDU	 BUFFER[19]	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define idA8IS12LDU	 9	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define A8IS22LDU	 BUFFER[21]	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define idA8IS22LDU	 10	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define B8IS12LDU	 BUFFER[23]	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 11	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define B8IS22LDU	 BUFFER[25]	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define idB8IS22LDU	 12	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define R4IS12LDU	 BUFFER[27]	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define idR4IS12LDU	 13	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define R4IS22LDU	 BUFFER[29]	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define idR4IS22LDU	 14	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define R4IS21LDU	 BUFFER[31]	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define idR4IS21LDU	 15	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define R4IS11LDU	 BUFFER[33]	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define idR4IS11LDU	 16	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define B4VP82LDU	 BUFFER[35]	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 17	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
#define R0EE04LZ2	 BUFFER[37]	//( - , SBz2) Питание  АКНП4  отключить
#define idR0EE04LZ2	 18	//( - , SBz2) Питание  АКНП4  отключить
#define R0EE03LZ2	 BUFFER[39]	//( - , SBz2) Питание  АКНП3  отключить
#define idR0EE03LZ2	 19	//( - , SBz2) Питание  АКНП3  отключить
#define R0EE02LZ2	 BUFFER[41]	//( - , SBz2) Питание  АКНП  отключить
#define idR0EE02LZ2	 20	//( - , SBz2) Питание  АКНП  отключить
#define R0EE04LZ1	 BUFFER[43]	//( - , SBz1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 21	//( - , SBz1) Питание  АКНП4  отключить
#define R0EE03LZ1	 BUFFER[45]	//( - , SBz1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 22	//( - , SBz1) Питание  АКНП3  отключить
#define R0EE02LZ1	 BUFFER[47]	//( - , SBz1) Питание  АКНП  отключить
#define idR0EE02LZ1	 23	//( - , SBz1) Питание  АКНП  отключить
#define R0EE01LZ2	 BUFFER[49]	//( - , SBz2) Питание  АКНП1  отключить
#define idR0EE01LZ2	 24	//( - , SBz2) Питание  АКНП1  отключить
#define R0EE01LZ1	 BUFFER[51]	//( - , SBz1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 25	//( - , SBz1) Питание  АКНП1  отключить
#define B4IS10LDU	 BUFFER[53]	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define idB4IS10LDU	 26	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define A4IS10LDU	 BUFFER[55]	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define idA4IS10LDU	 27	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define B1IE04LDU	 BUFFER[57]	//( - , SCM) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 28	//( - , SCM) Движение ББ2 назад (от БУШД)
#define B1IE03LDU	 BUFFER[59]	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 29	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[61]	//( - , SCM) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 30	//( - , SCM) Движение ББ1 назад (от БУШД)
#define A1IE03LDU	 BUFFER[63]	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 31	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define B1IS12LDU	 BUFFER[65]	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define idB1IS12LDU	 32	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define B1IS11LDU	 BUFFER[67]	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define idB1IS11LDU	 33	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define B1IS21LDU	 BUFFER[69]	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define idB1IS21LDU	 34	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define B1IC01UDU	 BUFFER[71]	//( - , SDu) Координата штока ББ2
#define idB1IC01UDU	 35	//( - , SDu) Координата штока ББ2
#define B2IS12LDU	 BUFFER[76]	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 36	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define B2IS11LDU	 BUFFER[78]	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define idB2IS11LDU	 37	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define B2IS21LDU	 BUFFER[80]	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define idB2IS21LDU	 38	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define B9IS21LDU	 BUFFER[82]	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 39	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define B9IS11LDU	 BUFFER[84]	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 40	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define A9IS21LDU	 BUFFER[86]	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 41	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define A9IS11LDU	 BUFFER[88]	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 42	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define B5IS21LDU	 BUFFER[90]	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define idB5IS21LDU	 43	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define B5IS11LDU	 BUFFER[92]	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define idB5IS11LDU	 44	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define A5IS21LDU	 BUFFER[94]	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define idA5IS21LDU	 45	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define A5IS11LDU	 BUFFER[96]	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define idA5IS11LDU	 46	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define B0VP81LZZ	 BUFFER[98]	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 47	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define A0VP81LZZ	 BUFFER[100]	//(do32_pti:110 - K03DO, - ) Давление АЗ1 в норме
#define idA0VP81LZZ	 48	//(do32_pti:110 - K03DO, - ) Давление АЗ1 в норме
#define B8IC01UDU	 BUFFER[102]	//( - , SDu) Координата АЗ2, мм
#define idB8IC01UDU	 49	//( - , SDu) Координата АЗ2, мм
#define A8IC01UDU	 BUFFER[107]	//( - , SDu) Координата ДС2
#define idA8IC01UDU	 50	//( - , SDu) Координата ДС2
#define R6IS68LZZ	 BUFFER[112]	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 51	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R6IS67LZZ	 BUFFER[114]	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 52	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define A4VP82LDU	 BUFFER[116]	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 53	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
#define R2IS21LDU	 BUFFER[118]	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define idR2IS21LDU	 54	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define R2IS11LDU	 BUFFER[120]	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define idR2IS11LDU	 55	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define R1IS21LDU	 BUFFER[122]	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define idR1IS21LDU	 56	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define R1IS11LDU	 BUFFER[124]	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define idR1IS11LDU	 57	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define B4IS21LDU	 BUFFER[126]	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define idB4IS21LDU	 58	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define B4IS11LDU	 BUFFER[128]	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define idB4IS11LDU	 59	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define R8IS11LDU	 BUFFER[130]	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define idR8IS11LDU	 60	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define A4IS21LDU	 BUFFER[132]	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define idA4IS21LDU	 61	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define A4IS11LDU	 BUFFER[134]	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define idA4IS11LDU	 62	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define R5IS21LDU	 BUFFER[136]	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 63	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define R5IS11LDU	 BUFFER[138]	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 64	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define R3IS21LDU	 BUFFER[140]	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 65	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define R3IS11LDU	 BUFFER[142]	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 66	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define B2VP82LDU	 BUFFER[144]	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 67	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
#define B2IP01IZ2	 BUFFER[146]	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 68	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define B2IP01IZ1	 BUFFER[149]	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 69	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define B2IC01UDU	 BUFFER[152]	//( - , SDu) Координата штока РБ2
#define idB2IC01UDU	 70	//( - , SDu) Координата штока РБ2
#define R0IS01FI0	 BUFFER[157]	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define idR0IS01FI0	 71	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define A0IT03IRP	 BUFFER[159]	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define idA0IT03IRP	 72	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define B0IT03IRP	 BUFFER[162]	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define idB0IT03IRP	 73	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define R0IN03FI3	 BUFFER[165]	//( - , SA3) Выход КНК53М Гц от ПТИ
#define idR0IN03FI3	 74	//( - , SA3) Выход КНК53М Гц от ПТИ
#define R0IN02FI3	 BUFFER[170]	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI3	 75	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI2	 BUFFER[175]	//( - , SA2) Выход КНК53М Гц от ПТИ
#define idR0IN03FI2	 76	//( - , SA2) Выход КНК53М Гц от ПТИ
#define R0IN07RIP	 BUFFER[180]	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define idR0IN07RIP	 77	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define R0IN06RIP	 BUFFER[185]	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define idR0IN06RIP	 78	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define TerR0IN06FRP	 BUFFER[190]	//( - , - ) Неисправности СНМ-11 -1,2
#define idTerR0IN06FRP	 79	//( - , - ) Неисправности СНМ-11 -1,2
#define R0IN03RIP	 BUFFER[193]	//( - , SRP) Выход КНК53М Гц от ПТИ
#define idR0IN03RIP	 80	//( - , SRP) Выход КНК53М Гц от ПТИ
#define R0IN02RIP	 BUFFER[198]	//( - , SRP) Выход КНК15- Гц от ПТИ
#define idR0IN02RIP	 81	//( - , SRP) Выход КНК15- Гц от ПТИ
#define R0IN01RIP	 BUFFER[203]	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define idR0IN01RIP	 82	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define R0IN02FI2	 BUFFER[208]	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI2	 83	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI1	 BUFFER[213]	//( - , SA1) Выход КНК53М Гц от ПТИ
#define idR0IN03FI1	 84	//( - , SA1) Выход КНК53М Гц от ПТИ
#define R0IN02FI1	 BUFFER[218]	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI1	 85	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI4	 BUFFER[223]	//( - , SA4) Выход КНК53М Гц от ПТИ
#define idR0IN03FI4	 86	//( - , SA4) Выход КНК53М Гц от ПТИ
#define R0IN02FI4	 BUFFER[228]	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI4	 87	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define ifelse	 BUFFER[233]	//( - , - ) 
#define idifelse	 88	//( - , - ) 
#define B0SN07RIM	 BUFFER[235]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define idB0SN07RIM	 89	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define B0SN06RIM	 BUFFER[240]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define idB0SN06RIM	 90	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define B0SN05RIM	 BUFFER[245]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define idB0SN05RIM	 91	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define B0SN04RIM	 BUFFER[250]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define idB0SN04RIM	 92	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define B0SN03RIM	 BUFFER[255]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define idB0SN03RIM	 93	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define B0SN02RIM	 BUFFER[260]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define idB0SN02RIM	 94	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define A0SN07RIM	 BUFFER[265]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define idA0SN07RIM	 95	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define A0SN06RIM	 BUFFER[270]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define idA0SN06RIM	 96	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define A0SN05RIM	 BUFFER[275]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define idA0SN05RIM	 97	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define A0SN04RIM	 BUFFER[280]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define idA0SN04RIM	 98	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define A0SN03RIM	 BUFFER[285]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define idA0SN03RIM	 99	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define A0SN02RIM	 BUFFER[290]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define idA0SN02RIM	 100	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define LTAKTS	 BUFFER[295]	//( - , - ) takt scm
#define idLTAKTS	 101	//( - , - ) takt scm
#define krb2	 BUFFER[300]	//( - , - ) 
#define idkrb2	 102	//( - , - ) 
#define krb1	 BUFFER[305]	//( - , - ) 
#define idkrb1	 103	//( - , - ) 
#define R0DEUMLSS	 BUFFER[310]	//( - , SCM) Сигнал управления моделью
#define idR0DEUMLSS	 104	//( - , SCM) Сигнал управления моделью
#define R0MW11IP1	 BUFFER[313]	//( - , SCM) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 105	//( - , SCM) Переключатель ВЫСТРЕЛ
#define A6VS12LDU	 BUFFER[316]	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 106	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define A6VS22LDU	 BUFFER[318]	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 107	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define B8IS21LDU	 BUFFER[320]	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define idB8IS21LDU	 108	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define B8IS11LDU	 BUFFER[322]	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 109	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define A1VP81LZZ	 BUFFER[324]	//(do32_pti:110 - K01DO, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 110	//(do32_pti:110 - K01DO, - ) Давление СБРОС ББ1 в норме
#define B1VP81LZZ	 BUFFER[326]	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 111	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define B2IS33LDU	 BUFFER[328]	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define idB2IS33LDU	 112	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define A0VN01RIM	 BUFFER[330]	//( - , SCM) Период разгона  AЗ1
#define idA0VN01RIM	 113	//( - , SCM) Период разгона  AЗ1
#define B2IS32LIM	 BUFFER[335]	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define idB2IS32LIM	 114	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define B2IS11LIM	 BUFFER[337]	//( - , SCM) Магнит РБ2 обесточен
#define idB2IS11LIM	 115	//( - , SCM) Магнит РБ2 обесточен
#define A2IS32LIM	 BUFFER[339]	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define idA2IS32LIM	 116	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define A2IS11LIM	 BUFFER[341]	//( - , SCM) Магнит РБ1 обесточен
#define idA2IS11LIM	 117	//( - , SCM) Магнит РБ1 обесточен
#define B1IS32LIM	 BUFFER[343]	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define idB1IS32LIM	 118	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define B1IS11LIM	 BUFFER[345]	//( - , SCM) Магнит ББ2 обесточен
#define idB1IS11LIM	 119	//( - , SCM) Магнит ББ2 обесточен
#define A1IS32LIM	 BUFFER[347]	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define idA1IS32LIM	 120	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define A1IS11LIM	 BUFFER[349]	//( - , SCM) Магнит ББ1 обесточен
#define idA1IS11LIM	 121	//( - , SCM) Магнит ББ1 обесточен
#define A3AD34LDU	 BUFFER[351]	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define idA3AD34LDU	 122	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define R0IS02LDU	 BUFFER[353]	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define idR0IS02LDU	 123	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define R0IN01FI3	 BUFFER[355]	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI3	 124	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI2	 BUFFER[360]	//( - , SA2) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI2	 125	//( - , SA2) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI4	 BUFFER[365]	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI4	 126	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI1	 BUFFER[370]	//( - , SA1) Выход СНМ11 Гц от ПТИ
#define idR0IN01FI1	 127	//( - , SA1) Выход СНМ11 Гц от ПТИ
#define B7AP31LDU	 BUFFER[375]	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define idB7AP31LDU	 128	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define A7AP31LDU	 BUFFER[377]	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define idA7AP31LDU	 129	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define R4VS12LDU	 BUFFER[379]	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	 130	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define R4VS22LDU	 BUFFER[381]	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	 131	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define R1VS12LDU	 BUFFER[383]	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 132	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define R2VS12LDU	 BUFFER[385]	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 133	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	 BUFFER[387]	//( - , SCM) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 134	//( - , SCM) Движение МДЗ2 в сторону НУ
#define R1VS22LDU	 BUFFER[389]	//( - , SCM) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 135	//( - , SCM) Движение МДЗ1 в сторону НУ
#define B5VS12LDU	 BUFFER[391]	//( - , SCM) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 136	//( - , SCM) Движение НЛ2 в сторону ВУ
#define B5VS22LDU	 BUFFER[393]	//( - , SCM) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 137	//( - , SCM) Движение НЛ2 в сторону НУ
#define A5VS12LDU	 BUFFER[395]	//( - , SCM) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 138	//( - , SCM) Движение НЛ1 в сторону ВУ
#define A5VS22LDU	 BUFFER[397]	//( - , SCM) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 139	//( - , SCM) Движение НЛ1 в сторону НУ
#define B6VS12LDU	 BUFFER[399]	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define idB6VS12LDU	 140	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define B6VS22LDU	 BUFFER[401]	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define idB6VS22LDU	 141	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define B8AD20LDU	 BUFFER[403]	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 142	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define B8AD10LDU	 BUFFER[405]	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 143	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define R4AD20LDU	 BUFFER[407]	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define idR4AD20LDU	 144	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define R4AD10LDU	 BUFFER[409]	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 145	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define B0SR01RIM	 BUFFER[411]	//( - , SCM) Текущая реактивность AЗ2
#define idB0SR01RIM	 146	//( - , SCM) Текущая реактивность AЗ2
#define B3AD33LDU	 BUFFER[416]	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 147	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B3AD05LDU	 BUFFER[418]	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 148	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define B3AD04LDU	 BUFFER[420]	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 149	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[422]	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 150	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define B3AD02LDU	 BUFFER[424]	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 151	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define B3AD01LDU	 BUFFER[426]	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 152	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define B3AD21LDU	 BUFFER[428]	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 153	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD11LDU	 BUFFER[430]	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 154	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define A3AD33LDU	 BUFFER[432]	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define idA3AD33LDU	 155	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define A3AD05LDU	 BUFFER[434]	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 156	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define A3AD04LDU	 BUFFER[436]	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 157	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[438]	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 158	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define R0CR02RIM	 BUFFER[440]	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define idR0CR02RIM	 159	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define R0CR01RIM	 BUFFER[445]	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define idR0CR01RIM	 160	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define B0SN08RIM	 BUFFER[450]	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define idB0SN08RIM	 161	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define A0SN08RIM	 BUFFER[455]	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define idA0SN08RIM	 162	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define B5AD20LDU	 BUFFER[460]	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 163	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define B5AD10LDU	 BUFFER[462]	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 164	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define A5AD20LDU	 BUFFER[464]	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 165	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define A5AD10LDU	 BUFFER[466]	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 166	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define R2AD20LDU	 BUFFER[468]	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 167	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[470]	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	 168	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define R1AD20LDU	 BUFFER[472]	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 169	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define R1AD10LDU	 BUFFER[474]	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	 170	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define B6AD20LDU	 BUFFER[476]	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 171	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define B6AD10LDU	 BUFFER[478]	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 172	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define A6AD20LDU	 BUFFER[480]	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 173	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define A6AD10LDU	 BUFFER[482]	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 174	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define A8AD20LDU	 BUFFER[484]	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 175	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define A8AD10LDU	 BUFFER[486]	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 176	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define A2AD21LDU	 BUFFER[488]	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 177	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD11LDU	 BUFFER[490]	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 178	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define B1AD05LDU	 BUFFER[492]	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 179	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define B1AD04LDU	 BUFFER[494]	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 180	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[496]	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 181	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define B1AD02LDU	 BUFFER[498]	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define idB1AD02LDU	 182	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define B1AD01LDU	 BUFFER[500]	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 183	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define B1AD21LDU	 BUFFER[502]	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 184	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD11LDU	 BUFFER[504]	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 185	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define A1AD05LDU	 BUFFER[506]	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 186	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define A1AD04LDU	 BUFFER[508]	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 187	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[510]	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 188	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define A1AD02LDU	 BUFFER[512]	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 189	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define A1AD01LDU	 BUFFER[514]	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 190	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define A1AD21LDU	 BUFFER[516]	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 191	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD11LDU	 BUFFER[518]	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 192	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define A0SR01RIM	 BUFFER[520]	//( - , SCM) Текущая реактивность AЗ1
#define idA0SR01RIM	 193	//( - , SCM) Текущая реактивность AЗ1
#define A3AD02LDU	 BUFFER[525]	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 194	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define A3AD01LDU	 BUFFER[527]	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 195	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define A3AD21LDU	 BUFFER[529]	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 196	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD11LDU	 BUFFER[531]	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 197	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define B2AD33LDU	 BUFFER[533]	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define idB2AD33LDU	 198	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define B2AD05LDU	 BUFFER[535]	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 199	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define B2AD04LDU	 BUFFER[537]	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 200	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[539]	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 201	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define B2AD02LDU	 BUFFER[541]	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 202	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define B2AD01LDU	 BUFFER[543]	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 203	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define B2AD21LDU	 BUFFER[545]	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 204	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD11LDU	 BUFFER[547]	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 205	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define A2AD33LDU	 BUFFER[549]	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define idA2AD33LDU	 206	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define A2AD05LDU	 BUFFER[551]	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 207	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define A2AD04LDU	 BUFFER[553]	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 208	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[555]	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 209	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define A2AD02LDU	 BUFFER[557]	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 210	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define A2AD01LDU	 BUFFER[559]	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 211	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define A3IS31LDU	 BUFFER[561]	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define idA3IS31LDU	 212	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define A2VP82LDU	 BUFFER[563]	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 213	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
#define A2IP01IZ2	 BUFFER[565]	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 214	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define A2IP01IZ1	 BUFFER[568]	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 215	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define B3IS21LDU	 BUFFER[571]	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define idB3IS21LDU	 216	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define A3IS21LDU	 BUFFER[573]	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define idA3IS21LDU	 217	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define A2IS33LDU	 BUFFER[575]	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define idA2IS33LDU	 218	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define A2IC01UDU	 BUFFER[577]	//( - , SDu) Координата штока РБ1
#define idA2IC01UDU	 219	//( - , SDu) Координата штока РБ1
#define A2IS12LDU	 BUFFER[582]	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 220	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define A2IS11LDU	 BUFFER[584]	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define idA2IS11LDU	 221	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define A2IS21LDU	 BUFFER[586]	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define idA2IS21LDU	 222	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define B0IT02IZ2	 BUFFER[588]	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define idB0IT02IZ2	 223	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define B0IT01IZ1	 BUFFER[591]	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define idB0IT01IZ1	 224	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define A0IT02IZ2	 BUFFER[594]	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define idA0IT02IZ2	 225	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define A0IT01IZ1	 BUFFER[597]	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define idA0IT01IZ1	 226	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define R6IS21LDU	 BUFFER[600]	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 227	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define B7AS31LDU	 BUFFER[602]	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define idB7AS31LDU	 228	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define R6IS66LZZ	 BUFFER[604]	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 229	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS65LDU	 BUFFER[606]	//( - , - ) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 230	//( - , - ) Исправность ВИП ССДИ-35 2канал
#define R6IS64LDU	 BUFFER[608]	//( - , - ) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 231	//( - , - ) Исправность ВИП ССДИ-35 1канал
#define R6IS63LDU	 BUFFER[610]	//( - , - ) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 232	//( - , - ) Исправность ВИП ССДИ-39 2канал
#define R6IS62LDU	 BUFFER[612]	//( - , - ) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 233	//( - , - ) Исправность ВИП ССДИ-39 1канал
#define B3IS22LDU	 BUFFER[614]	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define idB3IS22LDU	 234	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define A3IS22LDU	 BUFFER[616]	//(do32_pti:110 - K02DO, - ) Приход на НУП ИС1
#define idA3IS22LDU	 235	//(do32_pti:110 - K02DO, - ) Приход на НУП ИС1
#define B3IS11LDU	 BUFFER[618]	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 236	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define A3IS11LDU	 BUFFER[620]	//(do32_pti:110 - K04DO, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 237	//(do32_pti:110 - K04DO, - ) Приход на ВУ ИС1
#define A3IP02IDU	 BUFFER[622]	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 238	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3VP81LDU	 BUFFER[625]	//( - , - ) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 239	//( - , - ) Давление СПУСК ИС2 в норме
#define A3VP81LDU	 BUFFER[627]	//( - , - ) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 240	//( - , - ) Давление СПУСК ИС1 в норме
#define B3IS33LDU	 BUFFER[629]	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idB3IS33LDU	 241	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define B3IC01UDU	 BUFFER[631]	//( - , SDu) Координата штока ИС2
#define idB3IC01UDU	 242	//( - , SDu) Координата штока ИС2
#define B3IS31LDU	 BUFFER[636]	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define idB3IS31LDU	 243	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define B3IP02IDU	 BUFFER[638]	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define idB3IP02IDU	 244	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define A3IS33LDU	 BUFFER[641]	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define idA3IS33LDU	 245	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define A3IC01UDU	 BUFFER[643]	//( - , SDu) Координата штока ИС1
#define idA3IC01UDU	 246	//( - , SDu) Координата штока ИС1
#define B3AD31LDU	 BUFFER[648]	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define idB3AD31LDU	 247	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define B2AD32LDU	 BUFFER[650]	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 248	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define B2AD31LDU	 BUFFER[652]	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define idB2AD31LDU	 249	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define B1AD32LDU	 BUFFER[654]	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 250	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define B1AD31LDU	 BUFFER[656]	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define idB1AD31LDU	 251	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define A3AD31LDU	 BUFFER[658]	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define idA3AD31LDU	 252	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define C1MD31LP1	 BUFFER[660]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define idC1MD31LP1	 253	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define C1MD31LP2	 BUFFER[662]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define idC1MD31LP2	 254	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define A1AD31LDU	 BUFFER[664]	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define idA1AD31LDU	 255	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define A1AD32LDU	 BUFFER[666]	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 256	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define A2AD31LDU	 BUFFER[668]	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define idA2AD31LDU	 257	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define C2MD31LP1	 BUFFER[670]	//( - , SCM) Кнопка «СБРОС РБ»
#define idC2MD31LP1	 258	//( - , SCM) Кнопка «СБРОС РБ»
#define A2AD32LDU	 BUFFER[672]	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 259	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define R0VZ71LZ2	 BUFFER[674]	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define idR0VZ71LZ2	 260	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define R0VZ71LZ1	 BUFFER[676]	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define idR0VZ71LZ1	 261	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define R8AD21LDU	 BUFFER[678]	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 262	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
#define R0AD14LDU	 BUFFER[680]	//( - , SCM) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 263	//( - , SCM) Имитация срабатывания верхней АС II УР
#define R0SR02RIM	 BUFFER[682]	//( - , SCM) Текущая мощность РУ (ватт)
#define idR0SR02RIM	 264	//( - , SCM) Текущая мощность РУ (ватт)
#define A7AS31LDU	 BUFFER[687]	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define idA7AS31LDU	 265	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define B3IS35LDU	 BUFFER[689]	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define idB3IS35LDU	 266	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define B3AD34LDU	 BUFFER[691]	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define idB3AD34LDU	 267	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define A3IS35LDU	 BUFFER[693]	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define idA3IS35LDU	 268	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define R7II73LZ2	 BUFFER[695]	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ2	 269	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define R7II71LZ2	 BUFFER[697]	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ2	 270	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II72LZ2	 BUFFER[699]	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ2	 271	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R0AD16LDU	 BUFFER[701]	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 272	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define R7II72LZ1	 BUFFER[703]	//(do32_pti:110 - K07DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ1	 273	//(do32_pti:110 - K07DO, - ) Сработала АС IУР (датчик 2)
#define R7II71LZ1	 BUFFER[705]	//(do32_pti:110 - K08DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ1	 274	//(do32_pti:110 - K08DO, - ) Сработала АС IУР (датчик 1)
#define R7II73LZ1	 BUFFER[707]	//(do32_pti:110 - K09DO, - ) Сработала АС IIУР
#define idR7II73LZ1	 275	//(do32_pti:110 - K09DO, - ) Сработала АС IIУР
#define R0SR01RIM	 BUFFER[709]	//( - , SCM) Текущая реактивность PУ
#define idR0SR01RIM	 276	//( - , SCM) Текущая реактивность PУ
#define R0ST01RIM	 BUFFER[714]	//( - , SCM) Текущий период разгона РУ
#define idR0ST01RIM	 277	//( - , SCM) Текущий период разгона РУ
#define A4AD10LDU	 BUFFER[719]	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define idA4AD10LDU	 278	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define B4AD10LDU	 BUFFER[721]	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define idB4AD10LDU	 279	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define A9AD10LDU	 BUFFER[723]	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define idA9AD10LDU	 280	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define B9AD10LDU	 BUFFER[725]	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define idB9AD10LDU	 281	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define R0MW13LP2	 BUFFER[727]	//( - , SCM) Переключатель «СЕТЬ»
#define idR0MW13LP2	 282	//( - , SCM) Переключатель «СЕТЬ»
#define fEM_R0UL01RIM	 BUFFER[729]	//(R0UL01RIM) Среднее время генерации нейтронов
#define idfEM_R0UL01RIM	 283	//(R0UL01RIM) Среднее время генерации нейтронов
#define fEM_R0UN02RIM	 BUFFER[734]	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define idfEM_R0UN02RIM	 284	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define fEM_A1UR01RIM	 BUFFER[739]	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR01RIM	 285	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define fEM_A1UR00RIM	 BUFFER[744]	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR00RIM	 286	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define fEM_A3UR00RIM	 BUFFER[749]	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR00RIM	 287	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define fEM_A3UR01RIM	 BUFFER[754]	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR01RIM	 288	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define fEM_R0UT01RIM	 BUFFER[759]	//(R0UT01RIM) Температурный коэффициент (долл)
#define idfEM_R0UT01RIM	 289	//(R0UT01RIM) Температурный коэффициент (долл)
#define fEM_R0UT02RIM	 BUFFER[764]	//(R0UT02RIM) Масса топлива в АЗ
#define idfEM_R0UT02RIM	 290	//(R0UT02RIM) Масса топлива в АЗ
#define fEM_R0UT04RIM	 BUFFER[769]	//(R0UT04RIM) Удельная теплоёмкость топлива
#define idfEM_R0UT04RIM	 291	//(R0UT04RIM) Удельная теплоёмкость топлива
#define fEM_R0UT03RIM	 BUFFER[774]	//(R0UT03RIM) Нормальная температура АЗ град
#define idfEM_R0UT03RIM	 292	//(R0UT03RIM) Нормальная температура АЗ град
#define fEM_R0UT05RIM	 BUFFER[779]	//(R0UT05RIM) Энергия деления ядра
#define idfEM_R0UT05RIM	 293	//(R0UT05RIM) Энергия деления ядра
#define fEM_R0UT06RIM	 BUFFER[784]	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define idfEM_R0UT06RIM	 294	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define fEM_A1UC02RDU	 BUFFER[789]	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define idfEM_A1UC02RDU	 295	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define fEM_A1UC04RIM	 BUFFER[794]	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define idfEM_A1UC04RIM	 296	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define fEM_A1UC05RIM	 BUFFER[799]	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define idfEM_A1UC05RIM	 297	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define fEM_A1UC06RIM	 BUFFER[804]	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define idfEM_A1UC06RIM	 298	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define fEM_A2UC06RIM	 BUFFER[809]	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define idfEM_A2UC06RIM	 299	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define fEM_A2UC05RIM	 BUFFER[814]	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define idfEM_A2UC05RIM	 300	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define fEM_A2UC04RIM	 BUFFER[819]	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define idfEM_A2UC04RIM	 301	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define fEM_A2UC02RDU	 BUFFER[824]	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define idfEM_A2UC02RDU	 302	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define fEM_A3UC06RIM	 BUFFER[829]	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define idfEM_A3UC06RIM	 303	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define fEM_A3UC05RIM	 BUFFER[834]	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC05RIM	 304	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC04RIM	 BUFFER[839]	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define idfEM_A3UC04RIM	 305	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define fEM_A3UC02RDU	 BUFFER[844]	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define idfEM_A3UC02RDU	 306	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define fEM_R4UV80RDU	 BUFFER[849]	//(R4UV80RDU) Номинальная скорость тележки (см/с)
#define idfEM_R4UV80RDU	 307	//(R4UV80RDU) Номинальная скорость тележки (см/с)
#define fEM_R4UC10RIM	 BUFFER[854]	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define idfEM_R4UC10RIM	 308	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define fEM_R4UC20RIM	 BUFFER[859]	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define idfEM_R4UC20RIM	 309	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define fEM_B8UC21RIM	 BUFFER[864]	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define idfEM_B8UC21RIM	 310	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define fEM_B8UC20RIM	 BUFFER[869]	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define idfEM_B8UC20RIM	 311	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define fEM_B8UC11RIM	 BUFFER[874]	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define idfEM_B8UC11RIM	 312	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define fEM_B8UC10RIM	 BUFFER[879]	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define idfEM_B8UC10RIM	 313	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define fEM_B8UV80RDU	 BUFFER[884]	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define idfEM_B8UV80RDU	 314	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define fEM_A8UV80RDU	 BUFFER[889]	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define idfEM_A8UV80RDU	 315	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define fEM_A8UC10RIM	 BUFFER[894]	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define idfEM_A8UC10RIM	 316	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define fEM_A8UC11RIM	 BUFFER[899]	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define idfEM_A8UC11RIM	 317	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define fEM_A8UC20RIM	 BUFFER[904]	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define idfEM_A8UC20RIM	 318	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define fEM_A8UC21RIM	 BUFFER[909]	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define idfEM_A8UC21RIM	 319	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define fEM_A6UC10RIM	 BUFFER[914]	//(A6UC10RIM) Время полного хода БЗ (сек)
#define idfEM_A6UC10RIM	 320	//(A6UC10RIM) Время полного хода БЗ (сек)
#define fEM_R1UC10RIM	 BUFFER[919]	//(R1UC10RIM) Время полного хода МДЗ сек
#define idfEM_R1UC10RIM	 321	//(R1UC10RIM) Время полного хода МДЗ сек
#define fEM_A5UC10RIM	 BUFFER[924]	//(A5UC10RIM) Время полного хода НЛ сек
#define idfEM_A5UC10RIM	 322	//(A5UC10RIM) Время полного хода НЛ сек
#define fEM_A0UN01RIM	 BUFFER[929]	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define idfEM_A0UN01RIM	 323	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define fEM_R4UC22RIM	 BUFFER[934]	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define idfEM_R4UC22RIM	 324	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define fEM_A1UG01RDU	 BUFFER[939]	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define idfEM_A1UG01RDU	 325	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define fEM_A2UG01RDU	 BUFFER[944]	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define idfEM_A2UG01RDU	 326	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define fEM_A3UG01RDU	 BUFFER[949]	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define idfEM_A3UG01RDU	 327	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define fEM_R7UC10RIM	 BUFFER[954]	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define idfEM_R7UC10RIM	 328	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define fEM_R7UC19RIM	 BUFFER[959]	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define idfEM_R7UC19RIM	 329	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define fEM_R7UI02RIM	 BUFFER[964]	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define idfEM_R7UI02RIM	 330	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define fEM_R7UL01RIM	 BUFFER[969]	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define idfEM_R7UL01RIM	 331	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define fEM_A2UR00RIM	 BUFFER[974]	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define idfEM_A2UR00RIM	 332	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define fEM_A2UR01RIM	 BUFFER[979]	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define idfEM_A2UR01RIM	 333	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define fEM_A0UN02RIM	 BUFFER[984]	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define idfEM_A0UN02RIM	 334	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define fEM_R0UR30RIM	 BUFFER[989]	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define idfEM_R0UR30RIM	 335	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define fEM_R0UR01RIM	 BUFFER[994]	//(R0UR01RIM) Стартовая отрицательная реактивность
#define idfEM_R0UR01RIM	 336	//(R0UR01RIM) Стартовая отрицательная реактивность
#define fEM_R0UT02RDU	 BUFFER[999]	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RDU	 337	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RDU	 BUFFER[1004]	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RDU	 338	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define fEM_A1UC03RDU	 BUFFER[1009]	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define idfEM_A1UC03RDU	 339	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define fEM_A2UP03RDU	 BUFFER[1014]	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP03RDU	 340	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UP04RDU	 BUFFER[1019]	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP04RDU	 341	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UC03RDU	 BUFFER[1024]	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define idfEM_A2UC03RDU	 342	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define fEM_A3UP03RDU	 BUFFER[1029]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 343	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1034]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 344	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UC03RDU	 BUFFER[1039]	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define idfEM_A3UC03RDU	 345	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define fEM_R7UI74RIM	 BUFFER[1044]	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define idfEM_R7UI74RIM	 346	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define fEM_A8UC03RDU	 BUFFER[1049]	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define idfEM_A8UC03RDU	 347	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define fEM_R0UV87RDU	 BUFFER[1054]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 348	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV81RDU	 BUFFER[1059]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 349	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1064]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 350	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1069]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 351	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1074]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 352	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1079]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 353	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1084]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 354	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A8UC08RDU	 BUFFER[1089]	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define idfEM_A8UC08RDU	 355	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define fEM_B8UC08RDU	 BUFFER[1094]	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define idfEM_B8UC08RDU	 356	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define fEM_R4UC08RDU	 BUFFER[1099]	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define idfEM_R4UC08RDU	 357	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define fEM_R0UH01RSS	 BUFFER[1104]	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define idfEM_R0UH01RSS	 358	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define fEM_A0UX00RSS	 BUFFER[1109]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 359	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_R7UX01RSS	 BUFFER[1114]	//(R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	 360	//(R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	 BUFFER[1119]	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	 361	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX04RSS	 BUFFER[1124]	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	 362	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	 BUFFER[1129]	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	 363	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	 BUFFER[1134]	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	 364	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define fEM_R7UX07RSS	 BUFFER[1139]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 365	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[1144]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 366	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[1149]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 367	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY01RSS	 BUFFER[1154]	//(R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	 368	//(R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	 BUFFER[1159]	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	 369	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY04RSS	 BUFFER[1164]	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	 370	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	 BUFFER[1169]	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	 371	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	 BUFFER[1174]	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	 372	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY07RSS	 BUFFER[1179]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 373	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[1184]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 374	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[1189]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 375	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_R7UX10RSS	 BUFFER[1194]	//(R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	 376	//(R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	 BUFFER[1199]	//(R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	 377	//(R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	 BUFFER[1204]	//(R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	 378	//(R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY10RSS	 BUFFER[1209]	//(R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	 379	//(R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	 BUFFER[1214]	//(R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	 380	//(R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	 BUFFER[1219]	//(R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	 381	//(R7UY12RSS) Y-координата камеры R7IN43
#define fEM_A0UX01RSS	 BUFFER[1224]	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	 382	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	 BUFFER[1229]	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	 383	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	 BUFFER[1234]	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	 384	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_A0UX04RSS	 BUFFER[1239]	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	 385	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	 BUFFER[1244]	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	 386	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	 BUFFER[1249]	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	 387	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_A0UX07RSS	 BUFFER[1254]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 388	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[1259]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 389	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[1264]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 390	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_A0UX10RSS	 BUFFER[1269]	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	 391	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	 BUFFER[1274]	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	 392	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	 BUFFER[1279]	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	 393	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX01RSS	 BUFFER[1284]	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	 394	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	 BUFFER[1289]	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	 395	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	 BUFFER[1294]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 396	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[1299]	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define idfEM_B0UX04RSS	 397	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define fEM_B0UX05RSS	 BUFFER[1304]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 398	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	 BUFFER[1309]	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	 399	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_B0UX07RSS	 BUFFER[1314]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 400	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[1319]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 401	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[1324]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 402	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_B0UX10RSS	 BUFFER[1329]	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	 403	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	 BUFFER[1334]	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	 404	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	 BUFFER[1339]	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	 405	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0UH02RSS	 BUFFER[1344]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define idfEM_R0UH02RSS	 406	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define fEM_R0UH03RSS	 BUFFER[1349]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define idfEM_R0UH03RSS	 407	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define fEM_R4US80RDU	 BUFFER[1354]	//(R4US80RDU) Тормозной путь тележки (мм)
#define idfEM_R4US80RDU	 408	//(R4US80RDU) Тормозной путь тележки (мм)
#define fEM_R7UI71RIM	 BUFFER[1359]	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define idfEM_R7UI71RIM	 409	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define fEM_R7UI72RIM	 BUFFER[1364]	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define idfEM_R7UI72RIM	 410	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define fEM_R7UI73RIM	 BUFFER[1369]	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define idfEM_R7UI73RIM	 411	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define fEM_A1UP01RIM	 BUFFER[1374]	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define idfEM_A1UP01RIM	 412	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define fEM_A2UP01RIM	 BUFFER[1379]	//(A2UP01RIM) Текущее давление на сброс РБ
#define idfEM_A2UP01RIM	 413	//(A2UP01RIM) Текущее давление на сброс РБ
#define fEM_A0UP02RIM	 BUFFER[1384]	//(A0UP02RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP02RIM	 414	//(A0UP02RIM) Текущее давление в АЗ1,2
#define fEM_A3UP01RIM	 BUFFER[1389]	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define idfEM_A3UP01RIM	 415	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define fEM_A1UP82RIM	 BUFFER[1394]	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define idfEM_A1UP82RIM	 416	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define fEM_A3UP02RDU	 BUFFER[1399]	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define idfEM_A3UP02RDU	 417	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define fEM_A1UV02RIM	 BUFFER[1404]	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define idfEM_A1UV02RIM	 418	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define fEM_A3UV02RIM	 BUFFER[1409]	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define idfEM_A3UV02RIM	 419	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define fEM_A2UV02RIM	 BUFFER[1414]	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define idfEM_A2UV02RIM	 420	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define fEM_B8US80RDU	 BUFFER[1419]	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define idfEM_B8US80RDU	 421	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define fEM_A8US80RDU	 BUFFER[1424]	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define idfEM_A8US80RDU	 422	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define fEM_A6US80RDU	 BUFFER[1429]	//(A6US80RDU) Тормозной путь БЗ (мм)
#define idfEM_A6US80RDU	 423	//(A6US80RDU) Тормозной путь БЗ (мм)
#define fEM_A1US07RDU	 BUFFER[1434]	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define idfEM_A1US07RDU	 424	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define fEM_A2US07RDU	 BUFFER[1439]	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define idfEM_A2US07RDU	 425	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define fEM_A3US07RDU	 BUFFER[1444]	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define idfEM_A3US07RDU	 426	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define fEM_R7UI75RIM	 BUFFER[1449]	//(R7UI75RIM) Множитель к уровню радиации
#define idfEM_R7UI75RIM	 427	//(R7UI75RIM) Множитель к уровню радиации
#define fEM_R0UH21RSS	 BUFFER[1454]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 428	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[1459]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 429	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[1464]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 430	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UH05RSS	 BUFFER[1469]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 431	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_A4UL10RIM	 BUFFER[1474]	//(A4UL10RIM) Время полного перемещения НИ сек
#define idfEM_A4UL10RIM	 432	//(A4UL10RIM) Время полного перемещения НИ сек
#define fEM_A9UL10RIM	 BUFFER[1479]	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define idfEM_A9UL10RIM	 433	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define fEM_R3UL10RIM	 BUFFER[1484]	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define idfEM_R3UL10RIM	 434	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define fEM_R5UL10RIM	 BUFFER[1489]	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define idfEM_R5UL10RIM	 435	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define fEM_R6UL10RIM	 BUFFER[1494]	//(R6UL10RIM) Время полного хода кран-балки сек
#define idfEM_R6UL10RIM	 436	//(R6UL10RIM) Время полного хода кран-балки сек
#define lEM_C1AD31LRP	 BUFFER[1499]	//(C1AD31LRP) Общий сброс от РПУ
#define idlEM_C1AD31LRP	 437	//(C1AD31LRP) Общий сброс от РПУ
#define lEM_R0IE01LRP	 BUFFER[1501]	//(R0IE01LRP) Отключение питание детекторов
#define idlEM_R0IE01LRP	 438	//(R0IE01LRP) Отключение питание детекторов
#define lEM_R0IE02LRP	 BUFFER[1503]	//(R0IE02LRP) Отключить питание ПР, ПУ
#define idlEM_R0IE02LRP	 439	//(R0IE02LRP) Отключить питание ПР, ПУ
#define fEM_A2UP02RIM	 BUFFER[1505]	//(A2UP02RIM) Текущее давление на подъём РБ
#define idfEM_A2UP02RIM	 440	//(A2UP02RIM) Текущее давление на подъём РБ
#define fEM_A2UP03RIM	 BUFFER[1510]	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define idfEM_A2UP03RIM	 441	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define fEM_A0UP01RIM	 BUFFER[1515]	//(A0UP01RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP01RIM	 442	//(A0UP01RIM) Текущее давление в АЗ1,2
#define fEM_A3UP02RIM	 BUFFER[1520]	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define idfEM_A3UP02RIM	 443	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define fEM_A4UP01RIM	 BUFFER[1525]	//(A4UP01RIM) Текущее давление на подъём НИ
#define idfEM_A4UP01RIM	 444	//(A4UP01RIM) Текущее давление на подъём НИ
#define fEM_A4UP02RIM	 BUFFER[1530]	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define idfEM_A4UP02RIM	 445	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define fEM_R7UI76RIM	 BUFFER[1535]	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define idfEM_R7UI76RIM	 446	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define fEM_R7UI77RIM	 BUFFER[1540]	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define idfEM_R7UI77RIM	 447	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define iEM_TERBB1	 BUFFER[1545]	//(TERBB1) Неисправности  ББ1
#define idiEM_TERBB1	 448	//(TERBB1) Неисправности  ББ1
#define fEM_A1MC02RC1	 BUFFER[1548]	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define idfEM_A1MC02RC1	 449	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define fEM_A1MV02RC1	 BUFFER[1553]	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define idfEM_A1MV02RC1	 450	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define iEM_TERBB2	 BUFFER[1558]	//(TERBB2) Неисправности  ББ2
#define idiEM_TERBB2	 451	//(TERBB2) Неисправности  ББ2
#define fEM_B1MC02RC1	 BUFFER[1561]	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define idfEM_B1MC02RC1	 452	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define fEM_B1MV02RC1	 BUFFER[1566]	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define idfEM_B1MV02RC1	 453	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define iEM_TERRB2	 BUFFER[1571]	//(TERRB2) Неисправности  РБ2
#define idiEM_TERRB2	 454	//(TERRB2) Неисправности  РБ2
#define fEM_B2MC02RC1	 BUFFER[1574]	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define idfEM_B2MC02RC1	 455	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define fEM_B2MV02RC1	 BUFFER[1579]	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define idfEM_B2MV02RC1	 456	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define iEM_TERRB1	 BUFFER[1584]	//(TERRB1) Неисправности  РБ1
#define idiEM_TERRB1	 457	//(TERRB1) Неисправности  РБ1
#define fEM_A2MC02RC1	 BUFFER[1587]	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define idfEM_A2MC02RC1	 458	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define fEM_A2MV02RC1	 BUFFER[1592]	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define idfEM_A2MV02RC1	 459	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define iEM_TERIS2	 BUFFER[1597]	//(TERIS2) Неисправности  ИС2
#define idiEM_TERIS2	 460	//(TERIS2) Неисправности  ИС2
#define fEM_B3MC02RC1	 BUFFER[1600]	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define idfEM_B3MC02RC1	 461	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define fEM_B3MV02RC1	 BUFFER[1605]	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define idfEM_B3MV02RC1	 462	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define iEM_TERIS1	 BUFFER[1610]	//(TERIS1) Неисправности  ИС1
#define idiEM_TERIS1	 463	//(TERIS1) Неисправности  ИС1
#define fEM_A3MC02RC1	 BUFFER[1613]	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define idfEM_A3MC02RC1	 464	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define fEM_A3MV02RC1	 BUFFER[1618]	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define idfEM_A3MV02RC1	 465	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define iEM_TERA1IE04LDU	 BUFFER[1623]	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define idiEM_TERA1IE04LDU	 466	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define iEM_TERA1IE03LDU	 BUFFER[1626]	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define idiEM_TERA1IE03LDU	 467	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define fEM_A1MC01RC1	 BUFFER[1629]	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define idfEM_A1MC01RC1	 468	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define iEM_TERB1IE03LDU	 BUFFER[1634]	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define idiEM_TERB1IE03LDU	 469	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define iEM_TERB1IE04LDU	 BUFFER[1637]	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define idiEM_TERB1IE04LDU	 470	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define fEM_B1MC01RC1	 BUFFER[1640]	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define idfEM_B1MC01RC1	 471	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define fEM_B1MV01RC1	 BUFFER[1645]	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define idfEM_B1MV01RC1	 472	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define fEM_B2MC01RC1	 BUFFER[1650]	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define idfEM_B2MC01RC1	 473	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define fEM_B2MV01RC1	 BUFFER[1655]	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define idfEM_B2MV01RC1	 474	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define fEM_A3MC01RC1	 BUFFER[1660]	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define idfEM_A3MC01RC1	 475	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define fEM_A3MV01RC1	 BUFFER[1665]	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define idfEM_A3MV01RC1	 476	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define fEM_B3MC01RC1	 BUFFER[1670]	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define idfEM_B3MC01RC1	 477	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define fEM_B3MV01RC1	 BUFFER[1675]	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define idfEM_B3MV01RC1	 478	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define iEM_TERA2SS21LIM	 BUFFER[1680]	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define idiEM_TERA2SS21LIM	 479	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define iEM_TERA2SS12LIM	 BUFFER[1683]	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define idiEM_TERA2SS12LIM	 480	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define iEM_TERR6SS21LIM	 BUFFER[1686]	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define idiEM_TERR6SS21LIM	 481	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define iEM_TERA2VP82LIM	 BUFFER[1689]	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define idiEM_TERA2VP82LIM	 482	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define iEM_TERA2SS11LIM	 BUFFER[1692]	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define idiEM_TERA2SS11LIM	 483	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define iEM_TERB3SS21LIM	 BUFFER[1695]	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define idiEM_TERB3SS21LIM	 484	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define iEM_TERA0MT01RIM	 BUFFER[1698]	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define idiEM_TERA0MT01RIM	 485	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define iEM_TERB0MT01RIM	 BUFFER[1701]	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define idiEM_TERB0MT01RIM	 486	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define iEM_TERA2SP01RIM	 BUFFER[1704]	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define idiEM_TERA2SP01RIM	 487	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define iEM_TERB2SP01RIM	 BUFFER[1707]	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define idiEM_TERB2SP01RIM	 488	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define iEM_TERB3SP02RIM	 BUFFER[1710]	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define idiEM_TERB3SP02RIM	 489	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define iEM_TERA3SC01RIM	 BUFFER[1713]	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define idiEM_TERA3SC01RIM	 490	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define iEM_TERA3VP81LIM	 BUFFER[1716]	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define idiEM_TERA3VP81LIM	 491	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define iEM_TERA2SC01RIM	 BUFFER[1719]	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define idiEM_TERA2SC01RIM	 492	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define iEM_TERA2SS33LIM	 BUFFER[1722]	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define idiEM_TERA2SS33LIM	 493	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define iEM_TERA3SS21LIM	 BUFFER[1725]	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define idiEM_TERA3SS21LIM	 494	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define iEM_TERA3SS33LIM	 BUFFER[1728]	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define idiEM_TERA3SS33LIM	 495	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define iEM_TERA3SS31LIM	 BUFFER[1731]	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define idiEM_TERA3SS31LIM	 496	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define iEM_TERB3SS31LIM	 BUFFER[1734]	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define idiEM_TERB3SS31LIM	 497	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define iEM_TERB3SS33LIM	 BUFFER[1737]	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idiEM_TERB3SS33LIM	 498	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define iEM_TERB3SC01RIM	 BUFFER[1740]	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define idiEM_TERB3SC01RIM	 499	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define iEM_TERA3SS11LIM	 BUFFER[1743]	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define idiEM_TERA3SS11LIM	 500	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define iEM_TERB3SS11LIM	 BUFFER[1746]	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define idiEM_TERB3SS11LIM	 501	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define iEM_TERR6IS64LIM	 BUFFER[1749]	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define idiEM_TERR6IS64LIM	 502	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define iEM_TERB3SS22LIM	 BUFFER[1752]	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define idiEM_TERB3SS22LIM	 503	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define iEM_TERA3SS22LIM	 BUFFER[1755]	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define idiEM_TERA3SS22LIM	 504	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define iEM_TERA3SP02RIM	 BUFFER[1758]	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define idiEM_TERA3SP02RIM	 505	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define iEM_TERR6IS62LIM	 BUFFER[1761]	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define idiEM_TERR6IS62LIM	 506	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define iEM_TERR6IS66LIM	 BUFFER[1764]	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idiEM_TERR6IS66LIM	 507	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define iEM_TERR6IS67LIM	 BUFFER[1767]	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idiEM_TERR6IS67LIM	 508	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define iEM_TERA0VP81LIM	 BUFFER[1770]	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define idiEM_TERA0VP81LIM	 509	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define iEM_TERB0VP81LIM	 BUFFER[1773]	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define idiEM_TERB0VP81LIM	 510	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define iEM_TERR0VP81LIM	 BUFFER[1776]	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define idiEM_TERR0VP81LIM	 511	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define iEM_TERR6IS68LIM	 BUFFER[1779]	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define idiEM_TERR6IS68LIM	 512	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define iEM_TERR7SI74RIM	 BUFFER[1782]	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define idiEM_TERR7SI74RIM	 513	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define iEM_TERA5SS21LIM	 BUFFER[1785]	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define idiEM_TERA5SS21LIM	 514	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define iEM_TERB5SS11LIM	 BUFFER[1788]	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define idiEM_TERB5SS11LIM	 515	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define iEM_TERA5SS11LIM	 BUFFER[1791]	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define idiEM_TERA5SS11LIM	 516	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define iEM_TERA9SS11LIM	 BUFFER[1794]	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define idiEM_TERA9SS11LIM	 517	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define iEM_TERB2SS11LIM	 BUFFER[1797]	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define idiEM_TERB2SS11LIM	 518	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define iEM_TERB2SS12LIM	 BUFFER[1800]	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define idiEM_TERB2SS12LIM	 519	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define iEM_TERB2SS21LIM	 BUFFER[1803]	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB2SS21LIM	 520	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERR3SS11LIM	 BUFFER[1806]	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define idiEM_TERR3SS11LIM	 521	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define iEM_TERB2SC01RIM	 BUFFER[1809]	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define idiEM_TERB2SC01RIM	 522	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define iEM_TERR3SS21LIM	 BUFFER[1812]	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define idiEM_TERR3SS21LIM	 523	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define iEM_TERR5SS11LIM	 BUFFER[1815]	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define idiEM_TERR5SS11LIM	 524	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define iEM_TERA4SS11LIM	 BUFFER[1818]	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define idiEM_TERA4SS11LIM	 525	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define iEM_TERR1SS11LIM	 BUFFER[1821]	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define idiEM_TERR1SS11LIM	 526	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define iEM_TERR1SS21LIM	 BUFFER[1824]	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define idiEM_TERR1SS21LIM	 527	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define iEM_TERR2SS11LIM	 BUFFER[1827]	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define idiEM_TERR2SS11LIM	 528	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define iEM_TERR2SS21LIM	 BUFFER[1830]	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define idiEM_TERR2SS21LIM	 529	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define iEM_TERA4VP82LIM	 BUFFER[1833]	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define idiEM_TERA4VP82LIM	 530	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define iEM_TERB4SS21LIM	 BUFFER[1836]	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define idiEM_TERB4SS21LIM	 531	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define iEM_TERR5SS21LIM	 BUFFER[1839]	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define idiEM_TERR5SS21LIM	 532	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define iEM_TERB6SS21LIM	 BUFFER[1842]	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define idiEM_TERB6SS21LIM	 533	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define iEM_TERB4SS11LIM	 BUFFER[1845]	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define idiEM_TERB4SS11LIM	 534	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define iEM_TERA4SS21LIM	 BUFFER[1848]	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define idiEM_TERA4SS21LIM	 535	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define iEM_TERA6MS11LIM	 BUFFER[1851]	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define idiEM_TERA6MS11LIM	 536	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define iEM_TERA6SS21LIM	 BUFFER[1854]	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define idiEM_TERA6SS21LIM	 537	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define iEM_TERB6SS11LIM	 BUFFER[1857]	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define idiEM_TERB6SS11LIM	 538	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define iEM_TERR4SS11LIM	 BUFFER[1860]	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define idiEM_TERR4SS11LIM	 539	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define iEM_TERR4MS21LIM	 BUFFER[1863]	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define idiEM_TERR4MS21LIM	 540	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define iEM_TERR4SS12LIM	 BUFFER[1866]	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define idiEM_TERR4SS12LIM	 541	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define iEM_TERR4SS22LIM	 BUFFER[1869]	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define idiEM_TERR4SS22LIM	 542	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define iEM_TERR8SS11LIM	 BUFFER[1872]	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define idiEM_TERR8SS11LIM	 543	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define iEM_TERB8SC01RIM	 BUFFER[1875]	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define idiEM_TERB8SC01RIM	 544	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define iEM_TERA8SC01RIM	 BUFFER[1878]	//(TERA8SC01RIM) Искажение: Координата ДС2
#define idiEM_TERA8SC01RIM	 545	//(TERA8SC01RIM) Искажение: Координата ДС2
#define iEM_TERB8SS12LIM	 BUFFER[1881]	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define idiEM_TERB8SS12LIM	 546	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define iEM_TERA8SS12LIM	 BUFFER[1884]	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define idiEM_TERA8SS12LIM	 547	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define iEM_TERB8SS22LIM	 BUFFER[1887]	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define idiEM_TERB8SS22LIM	 548	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define iEM_TERA8SS22LIM	 BUFFER[1890]	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define idiEM_TERA8SS22LIM	 549	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define iEM_TERA9SS21LIM	 BUFFER[1893]	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define idiEM_TERA9SS21LIM	 550	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define iEM_TERB9SS21LIM	 BUFFER[1896]	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define idiEM_TERB9SS21LIM	 551	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define iEM_TERB9SS11LIM	 BUFFER[1899]	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define idiEM_TERB9SS11LIM	 552	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define iEM_TERB5SS21LIM	 BUFFER[1902]	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define idiEM_TERB5SS21LIM	 553	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define iEM_TERA1SS21LIM	 BUFFER[1905]	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define idiEM_TERA1SS21LIM	 554	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define iEM_TERA1SS11LIM	 BUFFER[1908]	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define idiEM_TERA1SS11LIM	 555	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define iEM_TERA1SC01RIM	 BUFFER[1911]	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define idiEM_TERA1SC01RIM	 556	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define iEM_TERA1SS12LIM	 BUFFER[1914]	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define idiEM_TERA1SS12LIM	 557	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define iEM_TERB1SS21LIM	 BUFFER[1917]	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define idiEM_TERB1SS21LIM	 558	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define iEM_TERB1SS11LIM	 BUFFER[1920]	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define idiEM_TERB1SS11LIM	 559	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define iEM_TERB1MC01RIM	 BUFFER[1923]	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define idiEM_TERB1MC01RIM	 560	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define iEM_TERB1SS12LIM	 BUFFER[1926]	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define idiEM_TERB1SS12LIM	 561	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define iEM_TERTLG	 BUFFER[1929]	//(TERTLG) Неисправности  тележки от ИС
#define idiEM_TERTLG	 562	//(TERTLG) Неисправности  тележки от ИС
#define fEM_R4MC01RC1	 BUFFER[1932]	//(R4MC01RC1) Заданная координата тележки от ИС
#define idfEM_R4MC01RC1	 563	//(R4MC01RC1) Заданная координата тележки от ИС
#define fEM_R4MV01RC1	 BUFFER[1937]	//(R4MV01RC1) Заданная скорость тележки от ИС
#define idfEM_R4MV01RC1	 564	//(R4MV01RC1) Заданная скорость тележки от ИС
#define iEM_TERMAZ2	 BUFFER[1942]	//(TERMAZ2) Неисправности АЗ2 от ИС
#define idiEM_TERMAZ2	 565	//(TERMAZ2) Неисправности АЗ2 от ИС
#define fEM_B8MV01RC1	 BUFFER[1945]	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define idfEM_B8MV01RC1	 566	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define iEM_TERDS2	 BUFFER[1950]	//(TERDS2) Неисправности ДС2 от ИС
#define idiEM_TERDS2	 567	//(TERDS2) Неисправности ДС2 от ИС
#define fEM_A8MC01RC1	 BUFFER[1953]	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define idfEM_A8MC01RC1	 568	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define fEM_A8MV01RC1	 BUFFER[1958]	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define idfEM_A8MV01RC1	 569	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define iEM_TERBZ1	 BUFFER[1963]	//(TERBZ1) Неисправности БЗ1
#define idiEM_TERBZ1	 570	//(TERBZ1) Неисправности БЗ1
#define fEM_A6MC01RC1	 BUFFER[1966]	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define idfEM_A6MC01RC1	 571	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define fEM_A6MV01RC1	 BUFFER[1971]	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define idfEM_A6MV01RC1	 572	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define iEM_TERBZ2	 BUFFER[1976]	//(TERBZ2) Неисправности БЗ2
#define idiEM_TERBZ2	 573	//(TERBZ2) Неисправности БЗ2
#define fEM_B6MC01RC1	 BUFFER[1979]	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define idfEM_B6MC01RC1	 574	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define fEM_B6MV01RC1	 BUFFER[1984]	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define idfEM_B6MV01RC1	 575	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define lEM_R3AD10LC1	 BUFFER[1989]	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define idlEM_R3AD10LC1	 576	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define lEM_R3AD20LC1	 BUFFER[1991]	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define idlEM_R3AD20LC1	 577	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define lEM_R6AD10LC1	 BUFFER[1993]	//(R6AD10LC1) Выкатить кран-балку от ИС
#define idlEM_R6AD10LC1	 578	//(R6AD10LC1) Выкатить кран-балку от ИС
#define lEM_R5AD10LC1	 BUFFER[1995]	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define idlEM_R5AD10LC1	 579	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define lEM_R5AD20LC1	 BUFFER[1997]	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define idlEM_R5AD20LC1	 580	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define iEM_TERMDZ2	 BUFFER[1999]	//(TERMDZ2) Неисправности МДЗ2
#define idiEM_TERMDZ2	 581	//(TERMDZ2) Неисправности МДЗ2
#define fEM_R2MC01RC1	 BUFFER[2002]	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define idfEM_R2MC01RC1	 582	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define fEM_R2MV01RC1	 BUFFER[2007]	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define idfEM_R2MV01RC1	 583	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define iEM_TERMDZ1	 BUFFER[2012]	//(TERMDZ1) Неисправности МДЗ1
#define idiEM_TERMDZ1	 584	//(TERMDZ1) Неисправности МДЗ1
#define fEM_R1MC01RC1	 BUFFER[2015]	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define idfEM_R1MC01RC1	 585	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define fEM_R1MV01RC1	 BUFFER[2020]	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define idfEM_R1MV01RC1	 586	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define iEM_TERNL1	 BUFFER[2025]	//(TERNL1) Неисправности НЛ1
#define idiEM_TERNL1	 587	//(TERNL1) Неисправности НЛ1
#define fEM_A5MC01RC1	 BUFFER[2028]	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define idfEM_A5MC01RC1	 588	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define fEM_A5MV01RC1	 BUFFER[2033]	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define idfEM_A5MV01RC1	 589	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define iEM_TERNL2	 BUFFER[2038]	//(TERNL2) Неисправности НЛ2
#define idiEM_TERNL2	 590	//(TERNL2) Неисправности НЛ2
#define fEM_B5MC01RC1	 BUFFER[2041]	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define idfEM_B5MC01RC1	 591	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define fEM_B5MV01RC1	 BUFFER[2046]	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define idfEM_B5MV01RC1	 592	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define lEM_R8AD10LC1	 BUFFER[2051]	//(R8AD10LC1) Установить аварийный НИ от ИС
#define idlEM_R8AD10LC1	 593	//(R8AD10LC1) Установить аварийный НИ от ИС
#define fEM_A1UC08RIM	 BUFFER[2053]	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define idfEM_A1UC08RIM	 594	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define fEM_A2UC08RIM	 BUFFER[2058]	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define idfEM_A2UC08RIM	 595	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define fEM_A3UC08RIM	 BUFFER[2063]	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define idfEM_A3UC08RIM	 596	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define iEM_TERB2SS33LIM	 BUFFER[2068]	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define idiEM_TERB2SS33LIM	 597	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define iEM_TERA1VP81LIM	 BUFFER[2071]	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define idiEM_TERA1VP81LIM	 598	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define iEM_TERB1VP81LIM	 BUFFER[2074]	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define idiEM_TERB1VP81LIM	 599	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define fEM_A0UT03RSP	 BUFFER[2077]	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define idfEM_A0UT03RSP	 600	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define fEM_A0UR01RSP	 BUFFER[2082]	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define idfEM_A0UR01RSP	 601	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define fEM_A0UR02RSP	 BUFFER[2087]	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define idfEM_A0UR02RSP	 602	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define fEM_B0UT03RSP	 BUFFER[2092]	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define idfEM_B0UT03RSP	 603	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define fEM_A1MC01RSP	 BUFFER[2097]	//(A1MC01RSP) Стартовая координата  ББ1
#define idfEM_A1MC01RSP	 604	//(A1MC01RSP) Стартовая координата  ББ1
#define fEM_A1MC02RSP	 BUFFER[2102]	//(A1MC02RSP) Стартовая координата штока ББ1
#define idfEM_A1MC02RSP	 605	//(A1MC02RSP) Стартовая координата штока ББ1
#define fEM_B1MC01RSP	 BUFFER[2107]	//(B1MC01RSP) Стартовая координата  ББ2
#define idfEM_B1MC01RSP	 606	//(B1MC01RSP) Стартовая координата  ББ2
#define fEM_B1MC02RSP	 BUFFER[2112]	//(B1MC02RSP) Стартовая координата штока ББ2
#define idfEM_B1MC02RSP	 607	//(B1MC02RSP) Стартовая координата штока ББ2
#define fEM_A2MC01RC1	 BUFFER[2117]	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define idfEM_A2MC01RC1	 608	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define fEM_A2MV01RC1	 BUFFER[2122]	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define idfEM_A2MV01RC1	 609	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define fEM_A2MC01RSP	 BUFFER[2127]	//(A2MC01RSP) Стартовая координата  РБ1
#define idfEM_A2MC01RSP	 610	//(A2MC01RSP) Стартовая координата  РБ1
#define fEM_A2MC02RSP	 BUFFER[2132]	//(A2MC02RSP) Стартовая координата штока РБ1
#define idfEM_A2MC02RSP	 611	//(A2MC02RSP) Стартовая координата штока РБ1
#define fEM_B2MC01RSP	 BUFFER[2137]	//(B2MC01RSP) Стартовая координата  РБ2
#define idfEM_B2MC01RSP	 612	//(B2MC01RSP) Стартовая координата  РБ2
#define fEM_B2MC02RSP	 BUFFER[2142]	//(B2MC02RSP) Стартовая координата штока РБ2
#define idfEM_B2MC02RSP	 613	//(B2MC02RSP) Стартовая координата штока РБ2
#define fEM_A3MC01RSP	 BUFFER[2147]	//(A3MC01RSP) Стартовая координата  ИС1
#define idfEM_A3MC01RSP	 614	//(A3MC01RSP) Стартовая координата  ИС1
#define fEM_A3MC02RSP	 BUFFER[2152]	//(A3MC02RSP) Стартовая координата штока ИС1
#define idfEM_A3MC02RSP	 615	//(A3MC02RSP) Стартовая координата штока ИС1
#define fEM_B3MC01RSP	 BUFFER[2157]	//(B3MC01RSP) Стартовая координата  ИС2
#define idfEM_B3MC01RSP	 616	//(B3MC01RSP) Стартовая координата  ИС2
#define fEM_B3MC02RSP	 BUFFER[2162]	//(B3MC02RSP) Стартовая координата штока ИС2
#define idfEM_B3MC02RSP	 617	//(B3MC02RSP) Стартовая координата штока ИС2
#define fEM_B8MC01RSP	 BUFFER[2167]	//(B8MC01RSP) Стартовая координата АЗ2
#define idfEM_B8MC01RSP	 618	//(B8MC01RSP) Стартовая координата АЗ2
#define fEM_A8MC01RSP	 BUFFER[2172]	//(A8MC01RSP) Стартовая координата ДС2
#define idfEM_A8MC01RSP	 619	//(A8MC01RSP) Стартовая координата ДС2
#define fEM_A6MC01RSP	 BUFFER[2177]	//(A6MC01RSP) Стартовая координата БЗ1
#define idfEM_A6MC01RSP	 620	//(A6MC01RSP) Стартовая координата БЗ1
#define fEM_B6MC01RSP	 BUFFER[2182]	//(B6MC01RSP) Стартовая координата БЗ2
#define idfEM_B6MC01RSP	 621	//(B6MC01RSP) Стартовая координата БЗ2
#define fEM_R3UC01RSP	 BUFFER[2187]	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define idfEM_R3UC01RSP	 622	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define fEM_R5UC01RSP	 BUFFER[2192]	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define idfEM_R5UC01RSP	 623	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define fEM_R6UC01RSP	 BUFFER[2197]	//(R6UC01RSP) Стартовая координата Кран-балки
#define idfEM_R6UC01RSP	 624	//(R6UC01RSP) Стартовая координата Кран-балки
#define fEM_R2MC01RSP	 BUFFER[2202]	//(R2MC01RSP) Стартовая координата МДЗ2
#define idfEM_R2MC01RSP	 625	//(R2MC01RSP) Стартовая координата МДЗ2
#define fEM_R1MC01RSP	 BUFFER[2207]	//(R1MC01RSP) Стартовая координата МДЗ1
#define idfEM_R1MC01RSP	 626	//(R1MC01RSP) Стартовая координата МДЗ1
#define fEM_A5MC01RSP	 BUFFER[2212]	//(A5MC01RSP) Стартовая координата НЛ1
#define idfEM_A5MC01RSP	 627	//(A5MC01RSP) Стартовая координата НЛ1
#define fEM_B5MC01RSP	 BUFFER[2217]	//(B5MC01RSP) Стартовая координата НЛ2
#define idfEM_B5MC01RSP	 628	//(B5MC01RSP) Стартовая координата НЛ2
#define fEM_A9MC01RSP	 BUFFER[2222]	//(A9MC01RSP) Стартовая координата НИ ДС1
#define idfEM_A9MC01RSP	 629	//(A9MC01RSP) Стартовая координата НИ ДС1
#define fEM_B9MC01RSP	 BUFFER[2227]	//(B9MC01RSP) Стартовая координата НИ ДС2
#define idfEM_B9MC01RSP	 630	//(B9MC01RSP) Стартовая координата НИ ДС2
#define fEM_A4MC01RSP	 BUFFER[2232]	//(A4MC01RSP) Стартовая координата НИ1
#define idfEM_A4MC01RSP	 631	//(A4MC01RSP) Стартовая координата НИ1
#define fEM_B4MC01RSP	 BUFFER[2237]	//(B4MC01RSP) Стартовая координата НИ2
#define idfEM_B4MC01RSP	 632	//(B4MC01RSP) Стартовая координата НИ2
#define fEM_R4MC01RSP	 BUFFER[2242]	//(R4MC01RSP) Стартовая координата тележки
#define idfEM_R4MC01RSP	 633	//(R4MC01RSP) Стартовая координата тележки
#define fEM_A1MV01RC1	 BUFFER[2247]	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define idfEM_A1MV01RC1	 634	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define iEM_TERB7MS31LIM	 BUFFER[2252]	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define idiEM_TERB7MS31LIM	 635	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define iEM_TERA7MS31LIM	 BUFFER[2255]	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define idiEM_TERA7MS31LIM	 636	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define fEM_R7UY00RSS	 BUFFER[2258]	//(R7UY00RSS) Y-координата АЗ1 см
#define idfEM_R7UY00RSS	 637	//(R7UY00RSS) Y-координата АЗ1 см
#define iEM_TERA6VS12LIM	 BUFFER[2263]	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define idiEM_TERA6VS12LIM	 638	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define iEM_TERA6VS22LIM	 BUFFER[2266]	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define idiEM_TERA6VS22LIM	 639	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define iEM_TERB6VS12LIM	 BUFFER[2269]	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define idiEM_TERB6VS12LIM	 640	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define iEM_TERB6VS22LIM	 BUFFER[2272]	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define idiEM_TERB6VS22LIM	 641	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define iEM_TERA5VS22LIM	 BUFFER[2275]	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define idiEM_TERA5VS22LIM	 642	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define iEM_TERA5VS12LIM	 BUFFER[2278]	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define idiEM_TERA5VS12LIM	 643	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define iEM_TERB5VS12LIM	 BUFFER[2281]	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define idiEM_TERB5VS12LIM	 644	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define iEM_TERB5VS22LIM	 BUFFER[2284]	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define idiEM_TERB5VS22LIM	 645	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define iEM_TERR1VS12LIM	 BUFFER[2287]	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define idiEM_TERR1VS12LIM	 646	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define iEM_TERR1VS22LIM	 BUFFER[2290]	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define idiEM_TERR1VS22LIM	 647	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define iEM_TERR2VS12LIM	 BUFFER[2293]	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define idiEM_TERR2VS12LIM	 648	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define iEM_TERR2VS22LIM	 BUFFER[2296]	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define idiEM_TERR2VS22LIM	 649	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define iEM_TERR4VS12LDU	 BUFFER[2299]	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS12LDU	 650	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR4VS22LDU	 BUFFER[2302]	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS22LDU	 651	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define fEM_A0UX13RSS	 BUFFER[2305]	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	 652	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	 BUFFER[2310]	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	 653	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	 BUFFER[2315]	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	 654	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_R7UX13RSS	 BUFFER[2320]	//(R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	 655	//(R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	 BUFFER[2325]	//(R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	 656	//(R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	 BUFFER[2330]	//(R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	 657	//(R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY13RSS	 BUFFER[2335]	//(R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	 658	//(R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	 BUFFER[2340]	//(R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	 659	//(R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	 BUFFER[2345]	//(R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	 660	//(R7UY15RSS) Y-координата камеры R7IN53
#define fEM_R7UX16RSS	 BUFFER[2350]	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define idfEM_R7UX16RSS	 661	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define fEM_B8MC01RC1	 BUFFER[2355]	//(B8MC01RC1) Заданная координата АЗ2 от ИС
#define idfEM_B8MC01RC1	 662	//(B8MC01RC1) Заданная координата АЗ2 от ИС
#define bFirstEnterFlag	 BUFFER[2360]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 663	//(bFirstEnterFlag) 
#define internal1_m708_xy	 BUFFER[2362]	//(internal1_m708_xy) xy - предыдущее
#define idinternal1_m708_xy	 664	//(internal1_m708_xy) xy - предыдущее
#define internal1_m876_Chim0	 BUFFER[2367]	//(internal1_m876_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m876_Chim0	 665	//(internal1_m876_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m866_Chim0	 BUFFER[2372]	//(internal1_m866_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m866_Chim0	 666	//(internal1_m866_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m858_Chim0	 BUFFER[2377]	//(internal1_m858_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m858_Chim0	 667	//(internal1_m858_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m813_Out10	 BUFFER[2382]	//(internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m813_Out10	 668	//(internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m812_Out10	 BUFFER[2384]	//(internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m812_Out10	 669	//(internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m995_Out10	 BUFFER[2386]	//(internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m995_Out10	 670	//(internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m994_Out10	 BUFFER[2388]	//(internal1_m994_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m994_Out10	 671	//(internal1_m994_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m993_Out10	 BUFFER[2390]	//(internal1_m993_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m993_Out10	 672	//(internal1_m993_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m992_Out10	 BUFFER[2392]	//(internal1_m992_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m992_Out10	 673	//(internal1_m992_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m670_Out10	 BUFFER[2394]	//(internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m670_Out10	 674	//(internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m669_Out10	 BUFFER[2396]	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m669_Out10	 675	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m648_Out10	 BUFFER[2398]	//(internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m648_Out10	 676	//(internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m647_Out10	 BUFFER[2400]	//(internal1_m647_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m647_Out10	 677	//(internal1_m647_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m668_Out10	 BUFFER[2402]	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m668_Out10	 678	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m667_Out10	 BUFFER[2404]	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m667_Out10	 679	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m646_Out10	 BUFFER[2406]	//(internal1_m646_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m646_Out10	 680	//(internal1_m646_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m645_Out10	 BUFFER[2408]	//(internal1_m645_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m645_Out10	 681	//(internal1_m645_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m512_Out10	 BUFFER[2410]	//(internal1_m512_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m512_Out10	 682	//(internal1_m512_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m528_Out10	 BUFFER[2412]	//(internal1_m528_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m528_Out10	 683	//(internal1_m528_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m400_Out10	 BUFFER[2414]	//(internal1_m400_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m400_Out10	 684	//(internal1_m400_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m473_q0	 BUFFER[2416]	//(internal1_m473_q0) q0 - внутренний параметр
#define idinternal1_m473_q0	 685	//(internal1_m473_q0) q0 - внутренний параметр
#define internal1_m474_q0	 BUFFER[2418]	//(internal1_m474_q0) q0 - внутренний параметр
#define idinternal1_m474_q0	 686	//(internal1_m474_q0) q0 - внутренний параметр
#define internal1_m461_q0	 BUFFER[2420]	//(internal1_m461_q0) q0 - внутренний параметр
#define idinternal1_m461_q0	 687	//(internal1_m461_q0) q0 - внутренний параметр
#define internal1_m462_q0	 BUFFER[2422]	//(internal1_m462_q0) q0 - внутренний параметр
#define idinternal1_m462_q0	 688	//(internal1_m462_q0) q0 - внутренний параметр
#define internal1_m621_tx	 BUFFER[2424]	//(internal1_m621_tx) tx - время накопленное сек
#define idinternal1_m621_tx	 689	//(internal1_m621_tx) tx - время накопленное сек
#define internal1_m621_y0	 BUFFER[2429]	//(internal1_m621_y0) y0
#define idinternal1_m621_y0	 690	//(internal1_m621_y0) y0
#define internal1_m609_tx	 BUFFER[2430]	//(internal1_m609_tx) tx - время накопленное сек
#define idinternal1_m609_tx	 691	//(internal1_m609_tx) tx - время накопленное сек
#define internal1_m609_y0	 BUFFER[2435]	//(internal1_m609_y0) y0
#define idinternal1_m609_y0	 692	//(internal1_m609_y0) y0
#define internal1_m597_tx	 BUFFER[2436]	//(internal1_m597_tx) tx - время накопленное сек
#define idinternal1_m597_tx	 693	//(internal1_m597_tx) tx - время накопленное сек
#define internal1_m597_y0	 BUFFER[2441]	//(internal1_m597_y0) y0
#define idinternal1_m597_y0	 694	//(internal1_m597_y0) y0
#define internal1_m595_tx	 BUFFER[2442]	//(internal1_m595_tx) tx - время накопленное сек
#define idinternal1_m595_tx	 695	//(internal1_m595_tx) tx - время накопленное сек
#define internal1_m595_y0	 BUFFER[2447]	//(internal1_m595_y0) y0
#define idinternal1_m595_y0	 696	//(internal1_m595_y0) y0
#define internal1_m205_Out10	 BUFFER[2448]	//(internal1_m205_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m205_Out10	 697	//(internal1_m205_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m222_Out10	 BUFFER[2450]	//(internal1_m222_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m222_Out10	 698	//(internal1_m222_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m41_Out10	 BUFFER[2452]	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m41_Out10	 699	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m56_Out10	 BUFFER[2454]	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m56_Out10	 700	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m966_Out10	 BUFFER[2456]	//(internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m966_Out10	 701	//(internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m963_Out10	 BUFFER[2458]	//(internal1_m963_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m963_Out10	 702	//(internal1_m963_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m962_Out10	 BUFFER[2460]	//(internal1_m962_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m962_Out10	 703	//(internal1_m962_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m965_Xtek0	 BUFFER[2462]	//(internal1_m965_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m965_Xtek0	 704	//(internal1_m965_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m948_Xtek0	 BUFFER[2467]	//(internal1_m948_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m948_Xtek0	 705	//(internal1_m948_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m949_Out10	 BUFFER[2472]	//(internal1_m949_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m949_Out10	 706	//(internal1_m949_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m946_Out10	 BUFFER[2474]	//(internal1_m946_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m946_Out10	 707	//(internal1_m946_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m945_Out10	 BUFFER[2476]	//(internal1_m945_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m945_Out10	 708	//(internal1_m945_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1033_Out10	 BUFFER[2478]	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1033_Out10	 709	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1014_Out10	 BUFFER[2480]	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1014_Out10	 710	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1013_Out10	 BUFFER[2482]	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1013_Out10	 711	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1012_Out10	 BUFFER[2484]	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1012_Out10	 712	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m834_Out10	 BUFFER[2486]	//(internal1_m834_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m834_Out10	 713	//(internal1_m834_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m836_Out10	 BUFFER[2488]	//(internal1_m836_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m836_Out10	 714	//(internal1_m836_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m833_Out10	 BUFFER[2490]	//(internal1_m833_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m833_Out10	 715	//(internal1_m833_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m835_Out10	 BUFFER[2492]	//(internal1_m835_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m835_Out10	 716	//(internal1_m835_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m809_Out10	 BUFFER[2494]	//(internal1_m809_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m809_Out10	 717	//(internal1_m809_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m810_Out10	 BUFFER[2496]	//(internal1_m810_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m810_Out10	 718	//(internal1_m810_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m808_Out10	 BUFFER[2498]	//(internal1_m808_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m808_Out10	 719	//(internal1_m808_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m807_Out10	 BUFFER[2500]	//(internal1_m807_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m807_Out10	 720	//(internal1_m807_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1028_Out10	 BUFFER[2502]	//(internal1_m1028_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1028_Out10	 721	//(internal1_m1028_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m980_Out10	 BUFFER[2504]	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m980_Out10	 722	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m979_Out10	 BUFFER[2506]	//(internal1_m979_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m979_Out10	 723	//(internal1_m979_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m978_Out10	 BUFFER[2508]	//(internal1_m978_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m978_Out10	 724	//(internal1_m978_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m977_Out10	 BUFFER[2510]	//(internal1_m977_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m977_Out10	 725	//(internal1_m977_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1029_Out10	 BUFFER[2512]	//(internal1_m1029_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1029_Out10	 726	//(internal1_m1029_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1010_Out10	 BUFFER[2514]	//(internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1010_Out10	 727	//(internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m811_Out10	 BUFFER[2516]	//(internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m811_Out10	 728	//(internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1011_Out10	 BUFFER[2518]	//(internal1_m1011_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1011_Out10	 729	//(internal1_m1011_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1009_Out10	 BUFFER[2520]	//(internal1_m1009_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1009_Out10	 730	//(internal1_m1009_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1030_Out10	 BUFFER[2522]	//(internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1030_Out10	 731	//(internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1008_Out10	 BUFFER[2524]	//(internal1_m1008_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1008_Out10	 732	//(internal1_m1008_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m991_Out10	 BUFFER[2526]	//(internal1_m991_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m991_Out10	 733	//(internal1_m991_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m976_Out10	 BUFFER[2528]	//(internal1_m976_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m976_Out10	 734	//(internal1_m976_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m529_Out10	 BUFFER[2530]	//(internal1_m529_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m529_Out10	 735	//(internal1_m529_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m410_Xtek0	 BUFFER[2532]	//(internal1_m410_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m410_Xtek0	 736	//(internal1_m410_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m401_Out10	 BUFFER[2537]	//(internal1_m401_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m401_Out10	 737	//(internal1_m401_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m403_Out10	 BUFFER[2539]	//(internal1_m403_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m403_Out10	 738	//(internal1_m403_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m402_Out10	 BUFFER[2541]	//(internal1_m402_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m402_Out10	 739	//(internal1_m402_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m849_Out10	 BUFFER[2543]	//(internal1_m849_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m849_Out10	 740	//(internal1_m849_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m850_Out10	 BUFFER[2545]	//(internal1_m850_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m850_Out10	 741	//(internal1_m850_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m848_Out10	 BUFFER[2547]	//(internal1_m848_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m848_Out10	 742	//(internal1_m848_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1032_Out10	 BUFFER[2549]	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1032_Out10	 743	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m683_Out10	 BUFFER[2551]	//(internal1_m683_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m683_Out10	 744	//(internal1_m683_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m684_Out10	 BUFFER[2553]	//(internal1_m684_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m684_Out10	 745	//(internal1_m684_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m681_Out10	 BUFFER[2555]	//(internal1_m681_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m681_Out10	 746	//(internal1_m681_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m682_Out10	 BUFFER[2557]	//(internal1_m682_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m682_Out10	 747	//(internal1_m682_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m545_Out10	 BUFFER[2559]	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m545_Out10	 748	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m544_Out10	 BUFFER[2561]	//(internal1_m544_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m544_Out10	 749	//(internal1_m544_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m830_Xtek0	 BUFFER[2563]	//(internal1_m830_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m830_Xtek0	 750	//(internal1_m830_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m832_Xtek0	 BUFFER[2568]	//(internal1_m832_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m832_Xtek0	 751	//(internal1_m832_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m680_Out10	 BUFFER[2573]	//(internal1_m680_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m680_Out10	 752	//(internal1_m680_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m664_Out10	 BUFFER[2575]	//(internal1_m664_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m664_Out10	 753	//(internal1_m664_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m644_Out10	 BUFFER[2577]	//(internal1_m644_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m644_Out10	 754	//(internal1_m644_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m663_Out10	 BUFFER[2579]	//(internal1_m663_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m663_Out10	 755	//(internal1_m663_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m643_Out10	 BUFFER[2581]	//(internal1_m643_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m643_Out10	 756	//(internal1_m643_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m331_Out10	 BUFFER[2583]	//(internal1_m331_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m331_Out10	 757	//(internal1_m331_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m330_Out10	 BUFFER[2585]	//(internal1_m330_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m330_Out10	 758	//(internal1_m330_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m315_Out10	 BUFFER[2587]	//(internal1_m315_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m315_Out10	 759	//(internal1_m315_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m314_Out10	 BUFFER[2589]	//(internal1_m314_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m314_Out10	 760	//(internal1_m314_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m546_Out10	 BUFFER[2591]	//(internal1_m546_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m546_Out10	 761	//(internal1_m546_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m344_Out10	 BUFFER[2593]	//(internal1_m344_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m344_Out10	 762	//(internal1_m344_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m328_Xtek0	 BUFFER[2595]	//(internal1_m328_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m328_Xtek0	 763	//(internal1_m328_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m343_Out10	 BUFFER[2600]	//(internal1_m343_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m343_Out10	 764	//(internal1_m343_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m341_Out10	 BUFFER[2602]	//(internal1_m341_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m341_Out10	 765	//(internal1_m341_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m318_Xtek0	 BUFFER[2604]	//(internal1_m318_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m318_Xtek0	 766	//(internal1_m318_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m342_Out10	 BUFFER[2609]	//(internal1_m342_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m342_Out10	 767	//(internal1_m342_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m313_Out10	 BUFFER[2611]	//(internal1_m313_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m313_Out10	 768	//(internal1_m313_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m329_Out10	 BUFFER[2613]	//(internal1_m329_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m329_Out10	 769	//(internal1_m329_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m422_Out10	 BUFFER[2615]	//(internal1_m422_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m422_Out10	 770	//(internal1_m422_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m423_Xtek0	 BUFFER[2617]	//(internal1_m423_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m423_Xtek0	 771	//(internal1_m423_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m421_Out10	 BUFFER[2622]	//(internal1_m421_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m421_Out10	 772	//(internal1_m421_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m420_Out10	 BUFFER[2624]	//(internal1_m420_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m420_Out10	 773	//(internal1_m420_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m419_Out10	 BUFFER[2626]	//(internal1_m419_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m419_Out10	 774	//(internal1_m419_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1031_Out10	 BUFFER[2628]	//(internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1031_Out10	 775	//(internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m146_Out10	 BUFFER[2630]	//(internal1_m146_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m146_Out10	 776	//(internal1_m146_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m145_Out10	 BUFFER[2632]	//(internal1_m145_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m145_Out10	 777	//(internal1_m145_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m194_tx	 BUFFER[2634]	//(internal1_m194_tx) tx - внутренний параметр
#define idinternal1_m194_tx	 778	//(internal1_m194_tx) tx - внутренний параметр
#define internal1_m25_tx	 BUFFER[2637]	//(internal1_m25_tx) tx - внутренний параметр
#define idinternal1_m25_tx	 779	//(internal1_m25_tx) tx - внутренний параметр
#define internal1_m465_X00	 BUFFER[2640]	//(internal1_m465_X00)  X00 - текущая координата механизма
#define idinternal1_m465_X00	 780	//(internal1_m465_X00)  X00 - текущая координата механизма
#define internal1_m465_V00	 BUFFER[2645]	//(internal1_m465_V00)  V00 - текущая скорость механизма
#define idinternal1_m465_V00	 781	//(internal1_m465_V00)  V00 - текущая скорость механизма
#define internal1_m465_Pav0	 BUFFER[2650]	//(internal1_m465_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m465_Pav0	 782	//(internal1_m465_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m465_Zav0	 BUFFER[2652]	//(internal1_m465_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m465_Zav0	 783	//(internal1_m465_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m465_Pv0	 BUFFER[2654]	//(internal1_m465_Pv0)  - Пер. выключатель механизма
#define idinternal1_m465_Pv0	 784	//(internal1_m465_Pv0)  - Пер. выключатель механизма
#define internal1_m465_Zv0	 BUFFER[2656]	//(internal1_m465_Zv0)  - Зад. выключатель механизма
#define idinternal1_m465_Zv0	 785	//(internal1_m465_Zv0)  - Зад. выключатель механизма
#define internal1_m465_RA00	 BUFFER[2658]	//(internal1_m465_RA00)  - последнее задание вперед
#define idinternal1_m465_RA00	 786	//(internal1_m465_RA00)  - последнее задание вперед
#define internal1_m465_RA10	 BUFFER[2660]	//(internal1_m465_RA10)  - последнее задание назад
#define idinternal1_m465_RA10	 787	//(internal1_m465_RA10)  - последнее задание назад
#define internal1_m465_MyFirstEnterFlag	 BUFFER[2662]	//(internal1_m465_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m465_MyFirstEnterFlag	 788	//(internal1_m465_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m477_X00	 BUFFER[2664]	//(internal1_m477_X00)  X00 - текущая координата механизма
#define idinternal1_m477_X00	 789	//(internal1_m477_X00)  X00 - текущая координата механизма
#define internal1_m477_V00	 BUFFER[2669]	//(internal1_m477_V00)  V00 - текущая скорость механизма
#define idinternal1_m477_V00	 790	//(internal1_m477_V00)  V00 - текущая скорость механизма
#define internal1_m477_Pav0	 BUFFER[2674]	//(internal1_m477_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m477_Pav0	 791	//(internal1_m477_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m477_Zav0	 BUFFER[2676]	//(internal1_m477_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m477_Zav0	 792	//(internal1_m477_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m477_Pv0	 BUFFER[2678]	//(internal1_m477_Pv0)  - Пер. выключатель механизма
#define idinternal1_m477_Pv0	 793	//(internal1_m477_Pv0)  - Пер. выключатель механизма
#define internal1_m477_Zv0	 BUFFER[2680]	//(internal1_m477_Zv0)  - Зад. выключатель механизма
#define idinternal1_m477_Zv0	 794	//(internal1_m477_Zv0)  - Зад. выключатель механизма
#define internal1_m477_RA00	 BUFFER[2682]	//(internal1_m477_RA00)  - последнее задание вперед
#define idinternal1_m477_RA00	 795	//(internal1_m477_RA00)  - последнее задание вперед
#define internal1_m477_RA10	 BUFFER[2684]	//(internal1_m477_RA10)  - последнее задание назад
#define idinternal1_m477_RA10	 796	//(internal1_m477_RA10)  - последнее задание назад
#define internal1_m477_MyFirstEnterFlag	 BUFFER[2686]	//(internal1_m477_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m477_MyFirstEnterFlag	 797	//(internal1_m477_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m467_X00	 BUFFER[2688]	//(internal1_m467_X00)  X00 - текущая координата механизма
#define idinternal1_m467_X00	 798	//(internal1_m467_X00)  X00 - текущая координата механизма
#define internal1_m467_V00	 BUFFER[2693]	//(internal1_m467_V00)  V00 - текущая скорость механизма
#define idinternal1_m467_V00	 799	//(internal1_m467_V00)  V00 - текущая скорость механизма
#define internal1_m467_Pav0	 BUFFER[2698]	//(internal1_m467_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m467_Pav0	 800	//(internal1_m467_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m467_Zav0	 BUFFER[2700]	//(internal1_m467_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m467_Zav0	 801	//(internal1_m467_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m467_Pv0	 BUFFER[2702]	//(internal1_m467_Pv0)  - Пер. выключатель механизма
#define idinternal1_m467_Pv0	 802	//(internal1_m467_Pv0)  - Пер. выключатель механизма
#define internal1_m467_Zv0	 BUFFER[2704]	//(internal1_m467_Zv0)  - Зад. выключатель механизма
#define idinternal1_m467_Zv0	 803	//(internal1_m467_Zv0)  - Зад. выключатель механизма
#define internal1_m467_RA00	 BUFFER[2706]	//(internal1_m467_RA00)  - последнее задание вперед
#define idinternal1_m467_RA00	 804	//(internal1_m467_RA00)  - последнее задание вперед
#define internal1_m467_RA10	 BUFFER[2708]	//(internal1_m467_RA10)  - последнее задание назад
#define idinternal1_m467_RA10	 805	//(internal1_m467_RA10)  - последнее задание назад
#define internal1_m467_MyFirstEnterFlag	 BUFFER[2710]	//(internal1_m467_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m467_MyFirstEnterFlag	 806	//(internal1_m467_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m600_X00	 BUFFER[2712]	//(internal1_m600_X00)  X00 - текущая координата механизма
#define idinternal1_m600_X00	 807	//(internal1_m600_X00)  X00 - текущая координата механизма
#define internal1_m600_V00	 BUFFER[2717]	//(internal1_m600_V00)  V00 - текущая скорость механизма
#define idinternal1_m600_V00	 808	//(internal1_m600_V00)  V00 - текущая скорость механизма
#define internal1_m600_Pav0	 BUFFER[2722]	//(internal1_m600_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m600_Pav0	 809	//(internal1_m600_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m600_Zav0	 BUFFER[2724]	//(internal1_m600_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m600_Zav0	 810	//(internal1_m600_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m600_Pv0	 BUFFER[2726]	//(internal1_m600_Pv0)  - Пер. выключатель механизма
#define idinternal1_m600_Pv0	 811	//(internal1_m600_Pv0)  - Пер. выключатель механизма
#define internal1_m600_Zv0	 BUFFER[2728]	//(internal1_m600_Zv0)  - Зад. выключатель механизма
#define idinternal1_m600_Zv0	 812	//(internal1_m600_Zv0)  - Зад. выключатель механизма
#define internal1_m600_RA00	 BUFFER[2730]	//(internal1_m600_RA00)  - последнее задание вперед
#define idinternal1_m600_RA00	 813	//(internal1_m600_RA00)  - последнее задание вперед
#define internal1_m600_RA10	 BUFFER[2732]	//(internal1_m600_RA10)  - последнее задание назад
#define idinternal1_m600_RA10	 814	//(internal1_m600_RA10)  - последнее задание назад
#define internal1_m600_MyFirstEnterFlag	 BUFFER[2734]	//(internal1_m600_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m600_MyFirstEnterFlag	 815	//(internal1_m600_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m599_X00	 BUFFER[2736]	//(internal1_m599_X00)  X00 - текущая координата механизма
#define idinternal1_m599_X00	 816	//(internal1_m599_X00)  X00 - текущая координата механизма
#define internal1_m599_V00	 BUFFER[2741]	//(internal1_m599_V00)  V00 - текущая скорость механизма
#define idinternal1_m599_V00	 817	//(internal1_m599_V00)  V00 - текущая скорость механизма
#define internal1_m599_Pav0	 BUFFER[2746]	//(internal1_m599_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m599_Pav0	 818	//(internal1_m599_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m599_Zav0	 BUFFER[2748]	//(internal1_m599_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m599_Zav0	 819	//(internal1_m599_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m599_Pv0	 BUFFER[2750]	//(internal1_m599_Pv0)  - Пер. выключатель механизма
#define idinternal1_m599_Pv0	 820	//(internal1_m599_Pv0)  - Пер. выключатель механизма
#define internal1_m599_Zv0	 BUFFER[2752]	//(internal1_m599_Zv0)  - Зад. выключатель механизма
#define idinternal1_m599_Zv0	 821	//(internal1_m599_Zv0)  - Зад. выключатель механизма
#define internal1_m599_RA00	 BUFFER[2754]	//(internal1_m599_RA00)  - последнее задание вперед
#define idinternal1_m599_RA00	 822	//(internal1_m599_RA00)  - последнее задание вперед
#define internal1_m599_RA10	 BUFFER[2756]	//(internal1_m599_RA10)  - последнее задание назад
#define idinternal1_m599_RA10	 823	//(internal1_m599_RA10)  - последнее задание назад
#define internal1_m599_MyFirstEnterFlag	 BUFFER[2758]	//(internal1_m599_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m599_MyFirstEnterFlag	 824	//(internal1_m599_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m587_X00	 BUFFER[2760]	//(internal1_m587_X00)  X00 - текущая координата механизма
#define idinternal1_m587_X00	 825	//(internal1_m587_X00)  X00 - текущая координата механизма
#define internal1_m587_V00	 BUFFER[2765]	//(internal1_m587_V00)  V00 - текущая скорость механизма
#define idinternal1_m587_V00	 826	//(internal1_m587_V00)  V00 - текущая скорость механизма
#define internal1_m587_Pav0	 BUFFER[2770]	//(internal1_m587_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m587_Pav0	 827	//(internal1_m587_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m587_Zav0	 BUFFER[2772]	//(internal1_m587_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m587_Zav0	 828	//(internal1_m587_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m587_Pv0	 BUFFER[2774]	//(internal1_m587_Pv0)  - Пер. выключатель механизма
#define idinternal1_m587_Pv0	 829	//(internal1_m587_Pv0)  - Пер. выключатель механизма
#define internal1_m587_Zv0	 BUFFER[2776]	//(internal1_m587_Zv0)  - Зад. выключатель механизма
#define idinternal1_m587_Zv0	 830	//(internal1_m587_Zv0)  - Зад. выключатель механизма
#define internal1_m587_RA00	 BUFFER[2778]	//(internal1_m587_RA00)  - последнее задание вперед
#define idinternal1_m587_RA00	 831	//(internal1_m587_RA00)  - последнее задание вперед
#define internal1_m587_RA10	 BUFFER[2780]	//(internal1_m587_RA10)  - последнее задание назад
#define idinternal1_m587_RA10	 832	//(internal1_m587_RA10)  - последнее задание назад
#define internal1_m587_MyFirstEnterFlag	 BUFFER[2782]	//(internal1_m587_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m587_MyFirstEnterFlag	 833	//(internal1_m587_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m586_X00	 BUFFER[2784]	//(internal1_m586_X00)  X00 - текущая координата механизма
#define idinternal1_m586_X00	 834	//(internal1_m586_X00)  X00 - текущая координата механизма
#define internal1_m586_V00	 BUFFER[2789]	//(internal1_m586_V00)  V00 - текущая скорость механизма
#define idinternal1_m586_V00	 835	//(internal1_m586_V00)  V00 - текущая скорость механизма
#define internal1_m586_Pav0	 BUFFER[2794]	//(internal1_m586_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m586_Pav0	 836	//(internal1_m586_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m586_Zav0	 BUFFER[2796]	//(internal1_m586_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m586_Zav0	 837	//(internal1_m586_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m586_Pv0	 BUFFER[2798]	//(internal1_m586_Pv0)  - Пер. выключатель механизма
#define idinternal1_m586_Pv0	 838	//(internal1_m586_Pv0)  - Пер. выключатель механизма
#define internal1_m586_Zv0	 BUFFER[2800]	//(internal1_m586_Zv0)  - Зад. выключатель механизма
#define idinternal1_m586_Zv0	 839	//(internal1_m586_Zv0)  - Зад. выключатель механизма
#define internal1_m586_RA00	 BUFFER[2802]	//(internal1_m586_RA00)  - последнее задание вперед
#define idinternal1_m586_RA00	 840	//(internal1_m586_RA00)  - последнее задание вперед
#define internal1_m586_RA10	 BUFFER[2804]	//(internal1_m586_RA10)  - последнее задание назад
#define idinternal1_m586_RA10	 841	//(internal1_m586_RA10)  - последнее задание назад
#define internal1_m586_MyFirstEnterFlag	 BUFFER[2806]	//(internal1_m586_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m586_MyFirstEnterFlag	 842	//(internal1_m586_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m629_y0	 BUFFER[2808]	//(internal1_m629_y0) y0 - внутренний параметр
#define idinternal1_m629_y0	 843	//(internal1_m629_y0) y0 - внутренний параметр
#define internal1_m795_Chim0	 BUFFER[2813]	//(internal1_m795_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m795_Chim0	 844	//(internal1_m795_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m786_Chim0	 BUFFER[2818]	//(internal1_m786_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m786_Chim0	 845	//(internal1_m786_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m778_Chim0	 BUFFER[2823]	//(internal1_m778_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m778_Chim0	 846	//(internal1_m778_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m769_Chim0	 BUFFER[2828]	//(internal1_m769_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m769_Chim0	 847	//(internal1_m769_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m760_Chim0	 BUFFER[2833]	//(internal1_m760_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m760_Chim0	 848	//(internal1_m760_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m752_Chim0	 BUFFER[2838]	//(internal1_m752_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m752_Chim0	 849	//(internal1_m752_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m743_Chim0	 BUFFER[2843]	//(internal1_m743_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m743_Chim0	 850	//(internal1_m743_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m734_Chim0	 BUFFER[2848]	//(internal1_m734_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m734_Chim0	 851	//(internal1_m734_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m726_Chim0	 BUFFER[2853]	//(internal1_m726_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m726_Chim0	 852	//(internal1_m726_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m716_Chim0	 BUFFER[2858]	//(internal1_m716_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m716_Chim0	 853	//(internal1_m716_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m706_Chim0	 BUFFER[2863]	//(internal1_m706_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m706_Chim0	 854	//(internal1_m706_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m696_Chim0	 BUFFER[2868]	//(internal1_m696_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m696_Chim0	 855	//(internal1_m696_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m574_X00	 BUFFER[2873]	//(internal1_m574_X00)  X00 - текущая координата механизма
#define idinternal1_m574_X00	 856	//(internal1_m574_X00)  X00 - текущая координата механизма
#define internal1_m574_V00	 BUFFER[2878]	//(internal1_m574_V00)  V00 - текущая скорость механизма
#define idinternal1_m574_V00	 857	//(internal1_m574_V00)  V00 - текущая скорость механизма
#define internal1_m574_Pav0	 BUFFER[2883]	//(internal1_m574_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m574_Pav0	 858	//(internal1_m574_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m574_Zav0	 BUFFER[2885]	//(internal1_m574_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m574_Zav0	 859	//(internal1_m574_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m574_Pv0	 BUFFER[2887]	//(internal1_m574_Pv0)  - Пер. выключатель механизма
#define idinternal1_m574_Pv0	 860	//(internal1_m574_Pv0)  - Пер. выключатель механизма
#define internal1_m574_Zv0	 BUFFER[2889]	//(internal1_m574_Zv0)  - Зад. выключатель механизма
#define idinternal1_m574_Zv0	 861	//(internal1_m574_Zv0)  - Зад. выключатель механизма
#define internal1_m574_RA00	 BUFFER[2891]	//(internal1_m574_RA00)  - последнее задание вперед
#define idinternal1_m574_RA00	 862	//(internal1_m574_RA00)  - последнее задание вперед
#define internal1_m574_RA10	 BUFFER[2893]	//(internal1_m574_RA10)  - последнее задание назад
#define idinternal1_m574_RA10	 863	//(internal1_m574_RA10)  - последнее задание назад
#define internal1_m574_MyFirstEnterFlag	 BUFFER[2895]	//(internal1_m574_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m574_MyFirstEnterFlag	 864	//(internal1_m574_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m560_X00	 BUFFER[2897]	//(internal1_m560_X00)  X00 - текущая координата механизма
#define idinternal1_m560_X00	 865	//(internal1_m560_X00)  X00 - текущая координата механизма
#define internal1_m560_V00	 BUFFER[2902]	//(internal1_m560_V00)  V00 - текущая скорость механизма
#define idinternal1_m560_V00	 866	//(internal1_m560_V00)  V00 - текущая скорость механизма
#define internal1_m560_Pav0	 BUFFER[2907]	//(internal1_m560_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m560_Pav0	 867	//(internal1_m560_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m560_Zav0	 BUFFER[2909]	//(internal1_m560_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m560_Zav0	 868	//(internal1_m560_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m560_Pv0	 BUFFER[2911]	//(internal1_m560_Pv0)  - Пер. выключатель механизма
#define idinternal1_m560_Pv0	 869	//(internal1_m560_Pv0)  - Пер. выключатель механизма
#define internal1_m560_Zv0	 BUFFER[2913]	//(internal1_m560_Zv0)  - Зад. выключатель механизма
#define idinternal1_m560_Zv0	 870	//(internal1_m560_Zv0)  - Зад. выключатель механизма
#define internal1_m560_RA00	 BUFFER[2915]	//(internal1_m560_RA00)  - последнее задание вперед
#define idinternal1_m560_RA00	 871	//(internal1_m560_RA00)  - последнее задание вперед
#define internal1_m560_RA10	 BUFFER[2917]	//(internal1_m560_RA10)  - последнее задание назад
#define idinternal1_m560_RA10	 872	//(internal1_m560_RA10)  - последнее задание назад
#define internal1_m560_MyFirstEnterFlag	 BUFFER[2919]	//(internal1_m560_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m560_MyFirstEnterFlag	 873	//(internal1_m560_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m451_X00	 BUFFER[2921]	//(internal1_m451_X00)  X00 - текущая координата механизма
#define idinternal1_m451_X00	 874	//(internal1_m451_X00)  X00 - текущая координата механизма
#define internal1_m451_V00	 BUFFER[2926]	//(internal1_m451_V00)  V00 - текущая скорость механизма
#define idinternal1_m451_V00	 875	//(internal1_m451_V00)  V00 - текущая скорость механизма
#define internal1_m451_Pav0	 BUFFER[2931]	//(internal1_m451_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m451_Pav0	 876	//(internal1_m451_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m451_Zav0	 BUFFER[2933]	//(internal1_m451_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m451_Zav0	 877	//(internal1_m451_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m451_Pv0	 BUFFER[2935]	//(internal1_m451_Pv0)  - Пер. выключатель механизма
#define idinternal1_m451_Pv0	 878	//(internal1_m451_Pv0)  - Пер. выключатель механизма
#define internal1_m451_Zv0	 BUFFER[2937]	//(internal1_m451_Zv0)  - Зад. выключатель механизма
#define idinternal1_m451_Zv0	 879	//(internal1_m451_Zv0)  - Зад. выключатель механизма
#define internal1_m451_RA00	 BUFFER[2939]	//(internal1_m451_RA00)  - последнее задание вперед
#define idinternal1_m451_RA00	 880	//(internal1_m451_RA00)  - последнее задание вперед
#define internal1_m451_RA10	 BUFFER[2941]	//(internal1_m451_RA10)  - последнее задание назад
#define idinternal1_m451_RA10	 881	//(internal1_m451_RA10)  - последнее задание назад
#define internal1_m451_MyFirstEnterFlag	 BUFFER[2943]	//(internal1_m451_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m451_MyFirstEnterFlag	 882	//(internal1_m451_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m437_X00	 BUFFER[2945]	//(internal1_m437_X00)  X00 - текущая координата механизма
#define idinternal1_m437_X00	 883	//(internal1_m437_X00)  X00 - текущая координата механизма
#define internal1_m437_V00	 BUFFER[2950]	//(internal1_m437_V00)  V00 - текущая скорость механизма
#define idinternal1_m437_V00	 884	//(internal1_m437_V00)  V00 - текущая скорость механизма
#define internal1_m437_Pav0	 BUFFER[2955]	//(internal1_m437_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m437_Pav0	 885	//(internal1_m437_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m437_Zav0	 BUFFER[2957]	//(internal1_m437_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m437_Zav0	 886	//(internal1_m437_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m437_Pv0	 BUFFER[2959]	//(internal1_m437_Pv0)  - Пер. выключатель механизма
#define idinternal1_m437_Pv0	 887	//(internal1_m437_Pv0)  - Пер. выключатель механизма
#define internal1_m437_Zv0	 BUFFER[2961]	//(internal1_m437_Zv0)  - Зад. выключатель механизма
#define idinternal1_m437_Zv0	 888	//(internal1_m437_Zv0)  - Зад. выключатель механизма
#define internal1_m437_RA00	 BUFFER[2963]	//(internal1_m437_RA00)  - последнее задание вперед
#define idinternal1_m437_RA00	 889	//(internal1_m437_RA00)  - последнее задание вперед
#define internal1_m437_RA10	 BUFFER[2965]	//(internal1_m437_RA10)  - последнее задание назад
#define idinternal1_m437_RA10	 890	//(internal1_m437_RA10)  - последнее задание назад
#define internal1_m437_MyFirstEnterFlag	 BUFFER[2967]	//(internal1_m437_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m437_MyFirstEnterFlag	 891	//(internal1_m437_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m488_X00	 BUFFER[2969]	//(internal1_m488_X00)  X00 - текущая координата механизма
#define idinternal1_m488_X00	 892	//(internal1_m488_X00)  X00 - текущая координата механизма
#define internal1_m488_V00	 BUFFER[2974]	//(internal1_m488_V00)  V00 - текущая скорость механизма
#define idinternal1_m488_V00	 893	//(internal1_m488_V00)  V00 - текущая скорость механизма
#define internal1_m488_Pav0	 BUFFER[2979]	//(internal1_m488_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m488_Pav0	 894	//(internal1_m488_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m488_Zav0	 BUFFER[2981]	//(internal1_m488_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m488_Zav0	 895	//(internal1_m488_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m488_Pv0	 BUFFER[2983]	//(internal1_m488_Pv0)  - Пер. выключатель механизма
#define idinternal1_m488_Pv0	 896	//(internal1_m488_Pv0)  - Пер. выключатель механизма
#define internal1_m488_Zv0	 BUFFER[2985]	//(internal1_m488_Zv0)  - Зад. выключатель механизма
#define idinternal1_m488_Zv0	 897	//(internal1_m488_Zv0)  - Зад. выключатель механизма
#define internal1_m488_RA00	 BUFFER[2987]	//(internal1_m488_RA00)  - последнее задание вперед
#define idinternal1_m488_RA00	 898	//(internal1_m488_RA00)  - последнее задание вперед
#define internal1_m488_RA10	 BUFFER[2989]	//(internal1_m488_RA10)  - последнее задание назад
#define idinternal1_m488_RA10	 899	//(internal1_m488_RA10)  - последнее задание назад
#define internal1_m488_MyFirstEnterFlag	 BUFFER[2991]	//(internal1_m488_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m488_MyFirstEnterFlag	 900	//(internal1_m488_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m389_X00	 BUFFER[2993]	//(internal1_m389_X00)  X00 - текущая координата механизма
#define idinternal1_m389_X00	 901	//(internal1_m389_X00)  X00 - текущая координата механизма
#define internal1_m389_V00	 BUFFER[2998]	//(internal1_m389_V00)  V00 - текущая скорость механизма
#define idinternal1_m389_V00	 902	//(internal1_m389_V00)  V00 - текущая скорость механизма
#define internal1_m389_Pav0	 BUFFER[3003]	//(internal1_m389_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m389_Pav0	 903	//(internal1_m389_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m389_Zav0	 BUFFER[3005]	//(internal1_m389_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m389_Zav0	 904	//(internal1_m389_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m389_Pv0	 BUFFER[3007]	//(internal1_m389_Pv0)  - Пер. выключатель механизма
#define idinternal1_m389_Pv0	 905	//(internal1_m389_Pv0)  - Пер. выключатель механизма
#define internal1_m389_Zv0	 BUFFER[3009]	//(internal1_m389_Zv0)  - Зад. выключатель механизма
#define idinternal1_m389_Zv0	 906	//(internal1_m389_Zv0)  - Зад. выключатель механизма
#define internal1_m389_RA00	 BUFFER[3011]	//(internal1_m389_RA00)  - последнее задание вперед
#define idinternal1_m389_RA00	 907	//(internal1_m389_RA00)  - последнее задание вперед
#define internal1_m389_RA10	 BUFFER[3013]	//(internal1_m389_RA10)  - последнее задание назад
#define idinternal1_m389_RA10	 908	//(internal1_m389_RA10)  - последнее задание назад
#define internal1_m389_MyFirstEnterFlag	 BUFFER[3015]	//(internal1_m389_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m389_MyFirstEnterFlag	 909	//(internal1_m389_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m374_X00	 BUFFER[3017]	//(internal1_m374_X00)  X00 - текущая координата механизма
#define idinternal1_m374_X00	 910	//(internal1_m374_X00)  X00 - текущая координата механизма
#define internal1_m374_V00	 BUFFER[3022]	//(internal1_m374_V00)  V00 - текущая скорость механизма
#define idinternal1_m374_V00	 911	//(internal1_m374_V00)  V00 - текущая скорость механизма
#define internal1_m374_Pav0	 BUFFER[3027]	//(internal1_m374_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m374_Pav0	 912	//(internal1_m374_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m374_Zav0	 BUFFER[3029]	//(internal1_m374_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m374_Zav0	 913	//(internal1_m374_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m374_Pv0	 BUFFER[3031]	//(internal1_m374_Pv0)  - Пер. выключатель механизма
#define idinternal1_m374_Pv0	 914	//(internal1_m374_Pv0)  - Пер. выключатель механизма
#define internal1_m374_Zv0	 BUFFER[3033]	//(internal1_m374_Zv0)  - Зад. выключатель механизма
#define idinternal1_m374_Zv0	 915	//(internal1_m374_Zv0)  - Зад. выключатель механизма
#define internal1_m374_RA00	 BUFFER[3035]	//(internal1_m374_RA00)  - последнее задание вперед
#define idinternal1_m374_RA00	 916	//(internal1_m374_RA00)  - последнее задание вперед
#define internal1_m374_RA10	 BUFFER[3037]	//(internal1_m374_RA10)  - последнее задание назад
#define idinternal1_m374_RA10	 917	//(internal1_m374_RA10)  - последнее задание назад
#define internal1_m374_MyFirstEnterFlag	 BUFFER[3039]	//(internal1_m374_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m374_MyFirstEnterFlag	 918	//(internal1_m374_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m358_X00	 BUFFER[3041]	//(internal1_m358_X00)  X00 - текущая координата механизма
#define idinternal1_m358_X00	 919	//(internal1_m358_X00)  X00 - текущая координата механизма
#define internal1_m358_V00	 BUFFER[3046]	//(internal1_m358_V00)  V00 - текущая скорость механизма
#define idinternal1_m358_V00	 920	//(internal1_m358_V00)  V00 - текущая скорость механизма
#define internal1_m358_Pav0	 BUFFER[3051]	//(internal1_m358_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m358_Pav0	 921	//(internal1_m358_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m358_Zav0	 BUFFER[3053]	//(internal1_m358_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m358_Zav0	 922	//(internal1_m358_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m358_Pv0	 BUFFER[3055]	//(internal1_m358_Pv0)  - Пер. выключатель механизма
#define idinternal1_m358_Pv0	 923	//(internal1_m358_Pv0)  - Пер. выключатель механизма
#define internal1_m358_Zv0	 BUFFER[3057]	//(internal1_m358_Zv0)  - Зад. выключатель механизма
#define idinternal1_m358_Zv0	 924	//(internal1_m358_Zv0)  - Зад. выключатель механизма
#define internal1_m358_RA00	 BUFFER[3059]	//(internal1_m358_RA00)  - последнее задание вперед
#define idinternal1_m358_RA00	 925	//(internal1_m358_RA00)  - последнее задание вперед
#define internal1_m358_RA10	 BUFFER[3061]	//(internal1_m358_RA10)  - последнее задание назад
#define idinternal1_m358_RA10	 926	//(internal1_m358_RA10)  - последнее задание назад
#define internal1_m358_MyFirstEnterFlag	 BUFFER[3063]	//(internal1_m358_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m358_MyFirstEnterFlag	 927	//(internal1_m358_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m888_X00	 BUFFER[3065]	//(internal1_m888_X00)  X00 - текущая координата механизма
#define idinternal1_m888_X00	 928	//(internal1_m888_X00)  X00 - текущая координата механизма
#define internal1_m888_V00	 BUFFER[3070]	//(internal1_m888_V00)  V00 - текущая скорость механизма
#define idinternal1_m888_V00	 929	//(internal1_m888_V00)  V00 - текущая скорость механизма
#define internal1_m888_Pav0	 BUFFER[3075]	//(internal1_m888_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m888_Pav0	 930	//(internal1_m888_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m888_Zav0	 BUFFER[3077]	//(internal1_m888_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m888_Zav0	 931	//(internal1_m888_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m888_Pv0	 BUFFER[3079]	//(internal1_m888_Pv0)  - Пер. выключатель механизма
#define idinternal1_m888_Pv0	 932	//(internal1_m888_Pv0)  - Пер. выключатель механизма
#define internal1_m888_Zv0	 BUFFER[3081]	//(internal1_m888_Zv0)  - Зад. выключатель механизма
#define idinternal1_m888_Zv0	 933	//(internal1_m888_Zv0)  - Зад. выключатель механизма
#define internal1_m888_RA00	 BUFFER[3083]	//(internal1_m888_RA00)  - последнее задание вперед
#define idinternal1_m888_RA00	 934	//(internal1_m888_RA00)  - последнее задание вперед
#define internal1_m888_RA10	 BUFFER[3085]	//(internal1_m888_RA10)  - последнее задание назад
#define idinternal1_m888_RA10	 935	//(internal1_m888_RA10)  - последнее задание назад
#define internal1_m888_MyFirstEnterFlag	 BUFFER[3087]	//(internal1_m888_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m888_MyFirstEnterFlag	 936	//(internal1_m888_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m179_C1	 BUFFER[3089]	//(internal1_m179_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m179_C1	 937	//(internal1_m179_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m179_C2	 BUFFER[3094]	//(internal1_m179_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m179_C2	 938	//(internal1_m179_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m179_C3	 BUFFER[3099]	//(internal1_m179_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m179_C3	 939	//(internal1_m179_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m179_C4	 BUFFER[3104]	//(internal1_m179_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m179_C4	 940	//(internal1_m179_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m179_C5	 BUFFER[3109]	//(internal1_m179_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m179_C5	 941	//(internal1_m179_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m179_C6	 BUFFER[3114]	//(internal1_m179_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m179_C6	 942	//(internal1_m179_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m179_N20	 BUFFER[3119]	//(internal1_m179_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m179_N20	 943	//(internal1_m179_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m179_N00	 BUFFER[3124]	//(internal1_m179_N00) N00 - Текущая концентрация нейтронов
#define idinternal1_m179_N00	 944	//(internal1_m179_N00) N00 - Текущая концентрация нейтронов
#define internal1_m179_R00	 BUFFER[3129]	//(internal1_m179_R00) R00 - Текущая реактивность
#define idinternal1_m179_R00	 945	//(internal1_m179_R00) R00 - Текущая реактивность
#define internal1_m179_T00	 BUFFER[3134]	//(internal1_m179_T00) T00 - Текущая температура
#define idinternal1_m179_T00	 946	//(internal1_m179_T00) T00 - Текущая температура
#define internal1_m179_ImpINI0	 BUFFER[3139]	//(internal1_m179_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m179_ImpINI0	 947	//(internal1_m179_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m179_MyFirstEnterFlag	 BUFFER[3141]	//(internal1_m179_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m179_MyFirstEnterFlag	 948	//(internal1_m179_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m295_X00	 BUFFER[3143]	//(internal1_m295_X00) X0 - текущая координата ОРР
#define idinternal1_m295_X00	 949	//(internal1_m295_X00) X0 - текущая координата ОРР
#define internal1_m295_Sh00	 BUFFER[3148]	//(internal1_m295_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m295_Sh00	 950	//(internal1_m295_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m295_RV00	 BUFFER[3153]	//(internal1_m295_RV00) V0 - текущая скорость ОРР
#define idinternal1_m295_RV00	 951	//(internal1_m295_RV00) V0 - текущая скорость ОРР
#define internal1_m295_ShV00	 BUFFER[3158]	//(internal1_m295_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m295_ShV00	 952	//(internal1_m295_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m295_Ppv0	 BUFFER[3163]	//(internal1_m295_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m295_Ppv0	 953	//(internal1_m295_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m295_Pav0	 BUFFER[3165]	//(internal1_m295_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m295_Pav0	 954	//(internal1_m295_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m295_Zav0	 BUFFER[3167]	//(internal1_m295_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m295_Zav0	 955	//(internal1_m295_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m295_RA00	 BUFFER[3169]	//(internal1_m295_RA00) RA00 - последнее задание вперед
#define idinternal1_m295_RA00	 956	//(internal1_m295_RA00) RA00 - последнее задание вперед
#define internal1_m295_RA10	 BUFFER[3171]	//(internal1_m295_RA10) RA10 - последнее задание назад
#define idinternal1_m295_RA10	 957	//(internal1_m295_RA10) RA10 - последнее задание назад
#define internal1_m295_RA30	 BUFFER[3173]	//(internal1_m295_RA30)  RA30 - разрешение движения
#define idinternal1_m295_RA30	 958	//(internal1_m295_RA30)  RA30 - разрешение движения
#define internal1_m295_RA50	 BUFFER[3175]	//(internal1_m295_RA50) Ra50 - последнее задание скорости
#define idinternal1_m295_RA50	 959	//(internal1_m295_RA50) Ra50 - последнее задание скорости
#define internal1_m295_fls	 BUFFER[3177]	//(internal1_m295_fls)  fls - флаг одношагового режима
#define idinternal1_m295_fls	 960	//(internal1_m295_fls)  fls - флаг одношагового режима
#define internal1_m295_flp	 BUFFER[3179]	//(internal1_m295_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m295_flp	 961	//(internal1_m295_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m295_MyFirstEnterFlag	 BUFFER[3181]	//(internal1_m295_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m295_MyFirstEnterFlag	 962	//(internal1_m295_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m127_X00	 BUFFER[3183]	//(internal1_m127_X00) X0 - текущая координата ОРР
#define idinternal1_m127_X00	 963	//(internal1_m127_X00) X0 - текущая координата ОРР
#define internal1_m127_Sh00	 BUFFER[3188]	//(internal1_m127_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m127_Sh00	 964	//(internal1_m127_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m127_RV00	 BUFFER[3193]	//(internal1_m127_RV00) V0 - текущая скорость ОРР
#define idinternal1_m127_RV00	 965	//(internal1_m127_RV00) V0 - текущая скорость ОРР
#define internal1_m127_ShV00	 BUFFER[3198]	//(internal1_m127_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m127_ShV00	 966	//(internal1_m127_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m127_Ppv0	 BUFFER[3203]	//(internal1_m127_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m127_Ppv0	 967	//(internal1_m127_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m127_Pav0	 BUFFER[3205]	//(internal1_m127_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m127_Pav0	 968	//(internal1_m127_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m127_Zav0	 BUFFER[3207]	//(internal1_m127_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m127_Zav0	 969	//(internal1_m127_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m127_RA00	 BUFFER[3209]	//(internal1_m127_RA00) RA00 - последнее задание вперед
#define idinternal1_m127_RA00	 970	//(internal1_m127_RA00) RA00 - последнее задание вперед
#define internal1_m127_RA10	 BUFFER[3211]	//(internal1_m127_RA10) RA10 - последнее задание назад
#define idinternal1_m127_RA10	 971	//(internal1_m127_RA10) RA10 - последнее задание назад
#define internal1_m127_RA30	 BUFFER[3213]	//(internal1_m127_RA30)  RA30 - разрешение движения
#define idinternal1_m127_RA30	 972	//(internal1_m127_RA30)  RA30 - разрешение движения
#define internal1_m127_RA50	 BUFFER[3215]	//(internal1_m127_RA50) Ra50 - последнее задание скорости
#define idinternal1_m127_RA50	 973	//(internal1_m127_RA50) Ra50 - последнее задание скорости
#define internal1_m127_fls	 BUFFER[3217]	//(internal1_m127_fls)  fls - флаг одношагового режима
#define idinternal1_m127_fls	 974	//(internal1_m127_fls)  fls - флаг одношагового режима
#define internal1_m127_flp	 BUFFER[3219]	//(internal1_m127_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m127_flp	 975	//(internal1_m127_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m127_MyFirstEnterFlag	 BUFFER[3221]	//(internal1_m127_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m127_MyFirstEnterFlag	 976	//(internal1_m127_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m261_X00	 BUFFER[3223]	//(internal1_m261_X00) X0 - текущая координата ОРР
#define idinternal1_m261_X00	 977	//(internal1_m261_X00) X0 - текущая координата ОРР
#define internal1_m261_Sh00	 BUFFER[3228]	//(internal1_m261_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m261_Sh00	 978	//(internal1_m261_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m261_RV00	 BUFFER[3233]	//(internal1_m261_RV00) V0 - текущая скорость ОРР
#define idinternal1_m261_RV00	 979	//(internal1_m261_RV00) V0 - текущая скорость ОРР
#define internal1_m261_ShV00	 BUFFER[3238]	//(internal1_m261_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m261_ShV00	 980	//(internal1_m261_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m261_Ppv0	 BUFFER[3243]	//(internal1_m261_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m261_Ppv0	 981	//(internal1_m261_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m261_Pav0	 BUFFER[3245]	//(internal1_m261_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m261_Pav0	 982	//(internal1_m261_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m261_Zav0	 BUFFER[3247]	//(internal1_m261_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m261_Zav0	 983	//(internal1_m261_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m261_RA00	 BUFFER[3249]	//(internal1_m261_RA00) RA00 - последнее задание вперед
#define idinternal1_m261_RA00	 984	//(internal1_m261_RA00) RA00 - последнее задание вперед
#define internal1_m261_RA10	 BUFFER[3251]	//(internal1_m261_RA10) RA10 - последнее задание назад
#define idinternal1_m261_RA10	 985	//(internal1_m261_RA10) RA10 - последнее задание назад
#define internal1_m261_RA30	 BUFFER[3253]	//(internal1_m261_RA30)  RA30 - разрешение движения
#define idinternal1_m261_RA30	 986	//(internal1_m261_RA30)  RA30 - разрешение движения
#define internal1_m261_RA50	 BUFFER[3255]	//(internal1_m261_RA50) Ra50 - последнее задание скорости
#define idinternal1_m261_RA50	 987	//(internal1_m261_RA50) Ra50 - последнее задание скорости
#define internal1_m261_fls	 BUFFER[3257]	//(internal1_m261_fls)  fls - флаг одношагового режима
#define idinternal1_m261_fls	 988	//(internal1_m261_fls)  fls - флаг одношагового режима
#define internal1_m261_flp	 BUFFER[3259]	//(internal1_m261_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m261_flp	 989	//(internal1_m261_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m261_MyFirstEnterFlag	 BUFFER[3261]	//(internal1_m261_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m261_MyFirstEnterFlag	 990	//(internal1_m261_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m94_X00	 BUFFER[3263]	//(internal1_m94_X00) X0 - текущая координата ОРР
#define idinternal1_m94_X00	 991	//(internal1_m94_X00) X0 - текущая координата ОРР
#define internal1_m94_Sh00	 BUFFER[3268]	//(internal1_m94_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m94_Sh00	 992	//(internal1_m94_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m94_RV00	 BUFFER[3273]	//(internal1_m94_RV00) V0 - текущая скорость ОРР
#define idinternal1_m94_RV00	 993	//(internal1_m94_RV00) V0 - текущая скорость ОРР
#define internal1_m94_ShV00	 BUFFER[3278]	//(internal1_m94_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m94_ShV00	 994	//(internal1_m94_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m94_Ppv0	 BUFFER[3283]	//(internal1_m94_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m94_Ppv0	 995	//(internal1_m94_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m94_Pav0	 BUFFER[3285]	//(internal1_m94_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m94_Pav0	 996	//(internal1_m94_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m94_Zav0	 BUFFER[3287]	//(internal1_m94_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m94_Zav0	 997	//(internal1_m94_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m94_RA00	 BUFFER[3289]	//(internal1_m94_RA00) RA00 - последнее задание вперед
#define idinternal1_m94_RA00	 998	//(internal1_m94_RA00) RA00 - последнее задание вперед
#define internal1_m94_RA10	 BUFFER[3291]	//(internal1_m94_RA10) RA10 - последнее задание назад
#define idinternal1_m94_RA10	 999	//(internal1_m94_RA10) RA10 - последнее задание назад
#define internal1_m94_RA30	 BUFFER[3293]	//(internal1_m94_RA30)  RA30 - разрешение движения
#define idinternal1_m94_RA30	 1000	//(internal1_m94_RA30)  RA30 - разрешение движения
#define internal1_m94_RA50	 BUFFER[3295]	//(internal1_m94_RA50) Ra50 - последнее задание скорости
#define idinternal1_m94_RA50	 1001	//(internal1_m94_RA50) Ra50 - последнее задание скорости
#define internal1_m94_fls	 BUFFER[3297]	//(internal1_m94_fls)  fls - флаг одношагового режима
#define idinternal1_m94_fls	 1002	//(internal1_m94_fls)  fls - флаг одношагового режима
#define internal1_m94_flp	 BUFFER[3299]	//(internal1_m94_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m94_flp	 1003	//(internal1_m94_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m94_MyFirstEnterFlag	 BUFFER[3301]	//(internal1_m94_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m94_MyFirstEnterFlag	 1004	//(internal1_m94_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m229_X00	 BUFFER[3303]	//(internal1_m229_X00) X0 - текущая координата ОРР
#define idinternal1_m229_X00	 1005	//(internal1_m229_X00) X0 - текущая координата ОРР
#define internal1_m229_Sh00	 BUFFER[3308]	//(internal1_m229_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m229_Sh00	 1006	//(internal1_m229_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m229_RV00	 BUFFER[3313]	//(internal1_m229_RV00) V0 - текущая скорость ОРР
#define idinternal1_m229_RV00	 1007	//(internal1_m229_RV00) V0 - текущая скорость ОРР
#define internal1_m229_ShV00	 BUFFER[3318]	//(internal1_m229_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m229_ShV00	 1008	//(internal1_m229_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m229_Ppv0	 BUFFER[3323]	//(internal1_m229_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m229_Ppv0	 1009	//(internal1_m229_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m229_Pav0	 BUFFER[3325]	//(internal1_m229_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m229_Pav0	 1010	//(internal1_m229_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m229_Zav0	 BUFFER[3327]	//(internal1_m229_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m229_Zav0	 1011	//(internal1_m229_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m229_RA00	 BUFFER[3329]	//(internal1_m229_RA00) RA00 - последнее задание вперед
#define idinternal1_m229_RA00	 1012	//(internal1_m229_RA00) RA00 - последнее задание вперед
#define internal1_m229_RA10	 BUFFER[3331]	//(internal1_m229_RA10) RA10 - последнее задание назад
#define idinternal1_m229_RA10	 1013	//(internal1_m229_RA10) RA10 - последнее задание назад
#define internal1_m229_RA30	 BUFFER[3333]	//(internal1_m229_RA30)  RA30 - разрешение движения
#define idinternal1_m229_RA30	 1014	//(internal1_m229_RA30)  RA30 - разрешение движения
#define internal1_m229_RA50	 BUFFER[3335]	//(internal1_m229_RA50) Ra50 - последнее задание скорости
#define idinternal1_m229_RA50	 1015	//(internal1_m229_RA50) Ra50 - последнее задание скорости
#define internal1_m229_fls	 BUFFER[3337]	//(internal1_m229_fls)  fls - флаг одношагового режима
#define idinternal1_m229_fls	 1016	//(internal1_m229_fls)  fls - флаг одношагового режима
#define internal1_m229_flp	 BUFFER[3339]	//(internal1_m229_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m229_flp	 1017	//(internal1_m229_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m229_MyFirstEnterFlag	 BUFFER[3341]	//(internal1_m229_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m229_MyFirstEnterFlag	 1018	//(internal1_m229_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m61_X00	 BUFFER[3343]	//(internal1_m61_X00) X0 - текущая координата ОРР
#define idinternal1_m61_X00	 1019	//(internal1_m61_X00) X0 - текущая координата ОРР
#define internal1_m61_Sh00	 BUFFER[3348]	//(internal1_m61_Sh00) Sh0 - текущая координата штока ОРР
#define idinternal1_m61_Sh00	 1020	//(internal1_m61_Sh00) Sh0 - текущая координата штока ОРР
#define internal1_m61_RV00	 BUFFER[3353]	//(internal1_m61_RV00) V0 - текущая скорость ОРР
#define idinternal1_m61_RV00	 1021	//(internal1_m61_RV00) V0 - текущая скорость ОРР
#define internal1_m61_ShV00	 BUFFER[3358]	//(internal1_m61_ShV00) V0 - текущая скорость штока ОРР
#define idinternal1_m61_ShV00	 1022	//(internal1_m61_ShV00) V0 - текущая скорость штока ОРР
#define internal1_m61_Ppv0	 BUFFER[3363]	//(internal1_m61_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m61_Ppv0	 1023	//(internal1_m61_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m61_Pav0	 BUFFER[3365]	//(internal1_m61_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m61_Pav0	 1024	//(internal1_m61_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m61_Zav0	 BUFFER[3367]	//(internal1_m61_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m61_Zav0	 1025	//(internal1_m61_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m61_RA00	 BUFFER[3369]	//(internal1_m61_RA00) RA00 - последнее задание вперед
#define idinternal1_m61_RA00	 1026	//(internal1_m61_RA00) RA00 - последнее задание вперед
#define internal1_m61_RA10	 BUFFER[3371]	//(internal1_m61_RA10) RA10 - последнее задание назад
#define idinternal1_m61_RA10	 1027	//(internal1_m61_RA10) RA10 - последнее задание назад
#define internal1_m61_RA30	 BUFFER[3373]	//(internal1_m61_RA30)  RA30 - разрешение движения
#define idinternal1_m61_RA30	 1028	//(internal1_m61_RA30)  RA30 - разрешение движения
#define internal1_m61_RA50	 BUFFER[3375]	//(internal1_m61_RA50) Ra50 - последнее задание скорости
#define idinternal1_m61_RA50	 1029	//(internal1_m61_RA50) Ra50 - последнее задание скорости
#define internal1_m61_fls	 BUFFER[3377]	//(internal1_m61_fls)  fls - флаг одношагового режима
#define idinternal1_m61_fls	 1030	//(internal1_m61_fls)  fls - флаг одношагового режима
#define internal1_m61_flp	 BUFFER[3379]	//(internal1_m61_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m61_flp	 1031	//(internal1_m61_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m61_MyFirstEnterFlag	 BUFFER[3381]	//(internal1_m61_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m61_MyFirstEnterFlag	 1032	//(internal1_m61_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m14_C1	 BUFFER[3383]	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m14_C1	 1033	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m14_C2	 BUFFER[3388]	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m14_C2	 1034	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m14_C3	 BUFFER[3393]	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m14_C3	 1035	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m14_C4	 BUFFER[3398]	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m14_C4	 1036	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m14_C5	 BUFFER[3403]	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m14_C5	 1037	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m14_C6	 BUFFER[3408]	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m14_C6	 1038	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m14_N20	 BUFFER[3413]	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m14_N20	 1039	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m14_N00	 BUFFER[3418]	//(internal1_m14_N00) N00 - Текущая концентрация нейтронов
#define idinternal1_m14_N00	 1040	//(internal1_m14_N00) N00 - Текущая концентрация нейтронов
#define internal1_m14_R00	 BUFFER[3423]	//(internal1_m14_R00) R00 - Текущая реактивность
#define idinternal1_m14_R00	 1041	//(internal1_m14_R00) R00 - Текущая реактивность
#define internal1_m14_T00	 BUFFER[3428]	//(internal1_m14_T00) T00 - Текущая температура
#define idinternal1_m14_T00	 1042	//(internal1_m14_T00) T00 - Текущая температура
#define internal1_m14_ImpINI0	 BUFFER[3433]	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m14_ImpINI0	 1043	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m14_MyFirstEnterFlag	 BUFFER[3435]	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m14_MyFirstEnterFlag	 1044	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,5	,1	, &A1IC01UDU},	//( - , SDu) Координата штока ББ1
	{ 2	,1	,1	, &A1IS12LDU},	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
	{ 3	,1	,1	, &A1IS11LDU},	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
	{ 4	,1	,1	, &A1IS21LDU},	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
	{ 5	,1	,1	, &B6IS21LDU},	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
	{ 6	,1	,1	, &B6IS11LDU},	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
	{ 7	,1	,1	, &A6IS21LDU},	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
	{ 8	,1	,1	, &A6IS11LDU},	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
	{ 9	,1	,1	, &A8IS12LDU},	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
	{ 10	,1	,1	, &A8IS22LDU},	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
	{ 11	,1	,1	, &B8IS12LDU},	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
	{ 12	,1	,1	, &B8IS22LDU},	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
	{ 13	,1	,1	, &R4IS12LDU},	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
	{ 14	,1	,1	, &R4IS22LDU},	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
	{ 15	,1	,1	, &R4IS21LDU},	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
	{ 16	,1	,1	, &R4IS11LDU},	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
	{ 17	,1	,1	, &B4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ2 в норме
	{ 18	,1	,1	, &R0EE04LZ2},	//( - , SBz2) Питание  АКНП4  отключить
	{ 19	,1	,1	, &R0EE03LZ2},	//( - , SBz2) Питание  АКНП3  отключить
	{ 20	,1	,1	, &R0EE02LZ2},	//( - , SBz2) Питание  АКНП  отключить
	{ 21	,1	,1	, &R0EE04LZ1},	//( - , SBz1) Питание  АКНП4  отключить
	{ 22	,1	,1	, &R0EE03LZ1},	//( - , SBz1) Питание  АКНП3  отключить
	{ 23	,1	,1	, &R0EE02LZ1},	//( - , SBz1) Питание  АКНП  отключить
	{ 24	,1	,1	, &R0EE01LZ2},	//( - , SBz2) Питание  АКНП1  отключить
	{ 25	,1	,1	, &R0EE01LZ1},	//( - , SBz1) Питание  АКНП1  отключить
	{ 26	,1	,1	, &B4IS10LDU},	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
	{ 27	,1	,1	, &A4IS10LDU},	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
	{ 28	,1	,1	, &B1IE04LDU},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{ 29	,1	,1	, &B1IE03LDU},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{ 30	,1	,1	, &A1IE04LDU},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{ 31	,1	,1	, &A1IE03LDU},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{ 32	,1	,1	, &B1IS12LDU},	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
	{ 33	,1	,1	, &B1IS11LDU},	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
	{ 34	,1	,1	, &B1IS21LDU},	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
	{ 35	,5	,1	, &B1IC01UDU},	//( - , SDu) Координата штока ББ2
	{ 36	,1	,1	, &B2IS12LDU},	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
	{ 37	,1	,1	, &B2IS11LDU},	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
	{ 38	,1	,1	, &B2IS21LDU},	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
	{ 39	,1	,1	, &B9IS21LDU},	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
	{ 40	,1	,1	, &B9IS11LDU},	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
	{ 41	,1	,1	, &A9IS21LDU},	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
	{ 42	,1	,1	, &A9IS11LDU},	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
	{ 43	,1	,1	, &B5IS21LDU},	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
	{ 44	,1	,1	, &B5IS11LDU},	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
	{ 45	,1	,1	, &A5IS21LDU},	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
	{ 46	,1	,1	, &A5IS11LDU},	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
	{ 47	,1	,1	, &B0VP81LZZ},	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
	{ 48	,1	,1	, &A0VP81LZZ},	//(do32_pti:110 - K03DO, - ) Давление АЗ1 в норме
	{ 49	,5	,1	, &B8IC01UDU},	//( - , SDu) Координата АЗ2, мм
	{ 50	,5	,1	, &A8IC01UDU},	//( - , SDu) Координата ДС2
	{ 51	,1	,1	, &R6IS68LZZ},	//( - , - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 52	,1	,1	, &R6IS67LZZ},	//( - , - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 53	,1	,1	, &A4VP82LDU},	//( - , - ) Давление ПОДЪЁМ НИ1 в норме
	{ 54	,1	,1	, &R2IS21LDU},	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
	{ 55	,1	,1	, &R2IS11LDU},	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
	{ 56	,1	,1	, &R1IS21LDU},	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
	{ 57	,1	,1	, &R1IS11LDU},	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
	{ 58	,1	,1	, &B4IS21LDU},	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
	{ 59	,1	,1	, &B4IS11LDU},	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
	{ 60	,1	,1	, &R8IS11LDU},	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
	{ 61	,1	,1	, &A4IS21LDU},	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
	{ 62	,1	,1	, &A4IS11LDU},	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
	{ 63	,1	,1	, &R5IS21LDU},	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
	{ 64	,1	,1	, &R5IS11LDU},	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
	{ 65	,1	,1	, &R3IS21LDU},	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
	{ 66	,1	,1	, &R3IS11LDU},	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
	{ 67	,1	,1	, &B2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ2 в норме
	{ 68	,3	,1	, &B2IP01IZ2},	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
	{ 69	,3	,1	, &B2IP01IZ1},	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
	{ 70	,5	,1	, &B2IC01UDU},	//( - , SDu) Координата штока РБ2
	{ 71	,1	,1	, &R0IS01FI0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{ 72	,3	,1	, &A0IT03IRP},	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
	{ 73	,3	,1	, &B0IT03IRP},	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
	{ 74	,8	,1	, &R0IN03FI3},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{ 75	,8	,1	, &R0IN02FI3},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{ 76	,8	,1	, &R0IN03FI2},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{ 77	,8	,1	, &R0IN07RIP},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{ 78	,8	,1	, &R0IN06RIP},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{ 79	,3	,1	, &TerR0IN06FRP},	//( - , - ) Неисправности СНМ-11 -1,2
	{ 80	,8	,1	, &R0IN03RIP},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{ 81	,8	,1	, &R0IN02RIP},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{ 82	,8	,1	, &R0IN01RIP},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{ 83	,8	,1	, &R0IN02FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{ 84	,8	,1	, &R0IN03FI1},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{ 85	,8	,1	, &R0IN02FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{ 86	,8	,1	, &R0IN03FI4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{ 87	,8	,1	, &R0IN02FI4},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{ 88	,1	,1	, &ifelse},	//( - , - ) 
	{ 89	,8	,1	, &B0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{ 90	,8	,1	, &B0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{ 91	,8	,1	, &B0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{ 92	,8	,1	, &B0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{ 93	,8	,1	, &B0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{ 94	,8	,1	, &B0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{ 95	,8	,1	, &A0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{ 96	,8	,1	, &A0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{ 97	,8	,1	, &A0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{ 98	,8	,1	, &A0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{ 99	,8	,1	, &A0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{ 100	,8	,1	, &A0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{ 101	,8	,1	, &LTAKTS},	//( - , - ) takt scm
	{ 102	,8	,1	, &krb2},	//( - , - ) 
	{ 103	,8	,1	, &krb1},	//( - , - ) 
	{ 104	,3	,1	, &R0DEUMLSS},	//( - , SCM) Сигнал управления моделью
	{ 105	,3	,1	, &R0MW11IP1},	//( - , SCM) Переключатель ВЫСТРЕЛ
	{ 106	,1	,1	, &A6VS12LDU},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{ 107	,1	,1	, &A6VS22LDU},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{ 108	,1	,1	, &B8IS21LDU},	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
	{ 109	,1	,1	, &B8IS11LDU},	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
	{ 110	,1	,1	, &A1VP81LZZ},	//(do32_pti:110 - K01DO, - ) Давление СБРОС ББ1 в норме
	{ 111	,1	,1	, &B1VP81LZZ},	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
	{ 112	,1	,1	, &B2IS33LDU},	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
	{ 113	,8	,1	, &A0VN01RIM},	//( - , SCM) Период разгона  AЗ1
	{ 114	,1	,1	, &B2IS32LIM},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{ 115	,1	,1	, &B2IS11LIM},	//( - , SCM) Магнит РБ2 обесточен
	{ 116	,1	,1	, &A2IS32LIM},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{ 117	,1	,1	, &A2IS11LIM},	//( - , SCM) Магнит РБ1 обесточен
	{ 118	,1	,1	, &B1IS32LIM},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	{ 119	,1	,1	, &B1IS11LIM},	//( - , SCM) Магнит ББ2 обесточен
	{ 120	,1	,1	, &A1IS32LIM},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{ 121	,1	,1	, &A1IS11LIM},	//( - , SCM) Магнит ББ1 обесточен
	{ 122	,1	,1	, &A3AD34LDU},	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
	{ 123	,1	,1	, &R0IS02LDU},	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
	{ 124	,8	,1	, &R0IN01FI3},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{ 125	,8	,1	, &R0IN01FI2},	//( - , SA2) Выход СНМ-11 Гц от ПТИ
	{ 126	,8	,1	, &R0IN01FI4},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{ 127	,8	,1	, &R0IN01FI1},	//( - , SA1) Выход СНМ11 Гц от ПТИ
	{ 128	,1	,1	, &B7AP31LDU},	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
	{ 129	,1	,1	, &A7AP31LDU},	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
	{ 130	,1	,1	, &R4VS12LDU},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{ 131	,1	,1	, &R4VS22LDU},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{ 132	,1	,1	, &R1VS12LDU},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{ 133	,1	,1	, &R2VS12LDU},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{ 134	,1	,1	, &R2VS22LDU},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{ 135	,1	,1	, &R1VS22LDU},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{ 136	,1	,1	, &B5VS12LDU},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{ 137	,1	,1	, &B5VS22LDU},	//( - , SCM) Движение НЛ2 в сторону НУ
	{ 138	,1	,1	, &A5VS12LDU},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{ 139	,1	,1	, &A5VS22LDU},	//( - , SCM) Движение НЛ1 в сторону НУ
	{ 140	,1	,1	, &B6VS12LDU},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{ 141	,1	,1	, &B6VS22LDU},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{ 142	,1	,1	, &B8AD20LDU},	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
	{ 143	,1	,1	, &B8AD10LDU},	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
	{ 144	,1	,1	, &R4AD20LDU},	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
	{ 145	,1	,1	, &R4AD10LDU},	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
	{ 146	,8	,1	, &B0SR01RIM},	//( - , SCM) Текущая реактивность AЗ2
	{ 147	,1	,1	, &B3AD33LDU},	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 148	,1	,1	, &B3AD05LDU},	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
	{ 149	,1	,1	, &B3AD04LDU},	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
	{ 150	,1	,1	, &B3AD03LDU},	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
	{ 151	,1	,1	, &B3AD02LDU},	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
	{ 152	,1	,1	, &B3AD01LDU},	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
	{ 153	,1	,1	, &B3AD21LDU},	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 154	,1	,1	, &B3AD11LDU},	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 155	,1	,1	, &A3AD33LDU},	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
	{ 156	,1	,1	, &A3AD05LDU},	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
	{ 157	,1	,1	, &A3AD04LDU},	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
	{ 158	,1	,1	, &A3AD03LDU},	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
	{ 159	,8	,1	, &R0CR02RIM},	//( - , SCM) Коэффициент 11 связи АЗ1,2
	{ 160	,8	,1	, &R0CR01RIM},	//( - , SCM) Коэффициент 12 связи АЗ1,2
	{ 161	,8	,1	, &B0SN08RIM},	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
	{ 162	,8	,1	, &A0SN08RIM},	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
	{ 163	,1	,1	, &B5AD20LDU},	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
	{ 164	,1	,1	, &B5AD10LDU},	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
	{ 165	,1	,1	, &A5AD20LDU},	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
	{ 166	,1	,1	, &A5AD10LDU},	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
	{ 167	,1	,1	, &R2AD20LDU},	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
	{ 168	,1	,1	, &R2AD10LDU},	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
	{ 169	,1	,1	, &R1AD20LDU},	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
	{ 170	,1	,1	, &R1AD10LDU},	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
	{ 171	,1	,1	, &B6AD20LDU},	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
	{ 172	,1	,1	, &B6AD10LDU},	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
	{ 173	,1	,1	, &A6AD20LDU},	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
	{ 174	,1	,1	, &A6AD10LDU},	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
	{ 175	,1	,1	, &A8AD20LDU},	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
	{ 176	,1	,1	, &A8AD10LDU},	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
	{ 177	,1	,1	, &A2AD21LDU},	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
	{ 178	,1	,1	, &A2AD11LDU},	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
	{ 179	,1	,1	, &B1AD05LDU},	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
	{ 180	,1	,1	, &B1AD04LDU},	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
	{ 181	,1	,1	, &B1AD03LDU},	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
	{ 182	,1	,1	, &B1AD02LDU},	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
	{ 183	,1	,1	, &B1AD01LDU},	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
	{ 184	,1	,1	, &B1AD21LDU},	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 185	,1	,1	, &B1AD11LDU},	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 186	,1	,1	, &A1AD05LDU},	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
	{ 187	,1	,1	, &A1AD04LDU},	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
	{ 188	,1	,1	, &A1AD03LDU},	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
	{ 189	,1	,1	, &A1AD02LDU},	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
	{ 190	,1	,1	, &A1AD01LDU},	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
	{ 191	,1	,1	, &A1AD21LDU},	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 192	,1	,1	, &A1AD11LDU},	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 193	,8	,1	, &A0SR01RIM},	//( - , SCM) Текущая реактивность AЗ1
	{ 194	,1	,1	, &A3AD02LDU},	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
	{ 195	,1	,1	, &A3AD01LDU},	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
	{ 196	,1	,1	, &A3AD21LDU},	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 197	,1	,1	, &A3AD11LDU},	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 198	,1	,1	, &B2AD33LDU},	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
	{ 199	,1	,1	, &B2AD05LDU},	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
	{ 200	,1	,1	, &B2AD04LDU},	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
	{ 201	,1	,1	, &B2AD03LDU},	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
	{ 202	,1	,1	, &B2AD02LDU},	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
	{ 203	,1	,1	, &B2AD01LDU},	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
	{ 204	,1	,1	, &B2AD21LDU},	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 205	,1	,1	, &B2AD11LDU},	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 206	,1	,1	, &A2AD33LDU},	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
	{ 207	,1	,1	, &A2AD05LDU},	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
	{ 208	,1	,1	, &A2AD04LDU},	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
	{ 209	,1	,1	, &A2AD03LDU},	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
	{ 210	,1	,1	, &A2AD02LDU},	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
	{ 211	,1	,1	, &A2AD01LDU},	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
	{ 212	,1	,1	, &A3IS31LDU},	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
	{ 213	,1	,1	, &A2VP82LDU},	//( - , - ) Давление ПОДЪЁМ РБ1 в норме
	{ 214	,3	,1	, &A2IP01IZ2},	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
	{ 215	,3	,1	, &A2IP01IZ1},	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
	{ 216	,1	,1	, &B3IS21LDU},	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
	{ 217	,1	,1	, &A3IS21LDU},	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
	{ 218	,1	,1	, &A2IS33LDU},	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
	{ 219	,5	,1	, &A2IC01UDU},	//( - , SDu) Координата штока РБ1
	{ 220	,1	,1	, &A2IS12LDU},	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
	{ 221	,1	,1	, &A2IS11LDU},	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
	{ 222	,1	,1	, &A2IS21LDU},	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
	{ 223	,3	,1	, &B0IT02IZ2},	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
	{ 224	,3	,1	, &B0IT01IZ1},	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
	{ 225	,3	,1	, &A0IT02IZ2},	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
	{ 226	,3	,1	, &A0IT01IZ1},	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
	{ 227	,1	,1	, &R6IS21LDU},	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
	{ 228	,1	,1	, &B7AS31LDU},	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
	{ 229	,1	,1	, &R6IS66LZZ},	//( - , - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 230	,1	,1	, &R6IS65LDU},	//( - , - ) Исправность ВИП ССДИ-35 2канал
	{ 231	,1	,1	, &R6IS64LDU},	//( - , - ) Исправность ВИП ССДИ-35 1канал
	{ 232	,1	,1	, &R6IS63LDU},	//( - , - ) Исправность ВИП ССДИ-39 2канал
	{ 233	,1	,1	, &R6IS62LDU},	//( - , - ) Исправность ВИП ССДИ-39 1канал
	{ 234	,1	,1	, &B3IS22LDU},	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
	{ 235	,1	,1	, &A3IS22LDU},	//(do32_pti:110 - K02DO, - ) Приход на НУП ИС1
	{ 236	,1	,1	, &B3IS11LDU},	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
	{ 237	,1	,1	, &A3IS11LDU},	//(do32_pti:110 - K04DO, - ) Приход на ВУ ИС1
	{ 238	,3	,1	, &A3IP02IDU},	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 239	,1	,1	, &B3VP81LDU},	//( - , - ) Давление СПУСК ИС2 в норме
	{ 240	,1	,1	, &A3VP81LDU},	//( - , - ) Давление СПУСК ИС1 в норме
	{ 241	,1	,1	, &B3IS33LDU},	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 242	,5	,1	, &B3IC01UDU},	//( - , SDu) Координата штока ИС2
	{ 243	,1	,1	, &B3IS31LDU},	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
	{ 244	,3	,1	, &B3IP02IDU},	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
	{ 245	,1	,1	, &A3IS33LDU},	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
	{ 246	,5	,1	, &A3IC01UDU},	//( - , SDu) Координата штока ИС1
	{ 247	,1	,1	, &B3AD31LDU},	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
	{ 248	,1	,1	, &B2AD32LDU},	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
	{ 249	,1	,1	, &B2AD31LDU},	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
	{ 250	,1	,1	, &B1AD32LDU},	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
	{ 251	,1	,1	, &B1AD31LDU},	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
	{ 252	,1	,1	, &A3AD31LDU},	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
	{ 253	,1	,1	, &C1MD31LP1},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{ 254	,1	,1	, &C1MD31LP2},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{ 255	,1	,1	, &A1AD31LDU},	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
	{ 256	,1	,1	, &A1AD32LDU},	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
	{ 257	,1	,1	, &A2AD31LDU},	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
	{ 258	,1	,1	, &C2MD31LP1},	//( - , SCM) Кнопка «СБРОС РБ»
	{ 259	,1	,1	, &A2AD32LDU},	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
	{ 260	,1	,1	, &R0VZ71LZ2},	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
	{ 261	,1	,1	, &R0VZ71LZ1},	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
	{ 262	,1	,1	, &R8AD21LDU},	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
	{ 263	,1	,1	, &R0AD14LDU},	//( - , SCM) Имитация срабатывания верхней АС II УР
	{ 264	,8	,1	, &R0SR02RIM},	//( - , SCM) Текущая мощность РУ (ватт)
	{ 265	,1	,1	, &A7AS31LDU},	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
	{ 266	,1	,1	, &B3IS35LDU},	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
	{ 267	,1	,1	, &B3AD34LDU},	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
	{ 268	,1	,1	, &A3IS35LDU},	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
	{ 269	,1	,1	, &R7II73LZ2},	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
	{ 270	,1	,1	, &R7II71LZ2},	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
	{ 271	,1	,1	, &R7II72LZ2},	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
	{ 272	,1	,1	, &R0AD16LDU},	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
	{ 273	,1	,1	, &R7II72LZ1},	//(do32_pti:110 - K07DO, - ) Сработала АС IУР (датчик 2)
	{ 274	,1	,1	, &R7II71LZ1},	//(do32_pti:110 - K08DO, - ) Сработала АС IУР (датчик 1)
	{ 275	,1	,1	, &R7II73LZ1},	//(do32_pti:110 - K09DO, - ) Сработала АС IIУР
	{ 276	,8	,1	, &R0SR01RIM},	//( - , SCM) Текущая реактивность PУ
	{ 277	,8	,1	, &R0ST01RIM},	//( - , SCM) Текущий период разгона РУ
	{ 278	,1	,1	, &A4AD10LDU},	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
	{ 279	,1	,1	, &B4AD10LDU},	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
	{ 280	,1	,1	, &A9AD10LDU},	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
	{ 281	,1	,1	, &B9AD10LDU},	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
	{ 282	,1	,1	, &R0MW13LP2},	//( - , SCM) Переключатель «СЕТЬ»
	{ 283	,8	,1	, &fEM_R0UL01RIM},	//(R0UL01RIM) Среднее время генерации нейтронов
	{ 284	,8	,1	, &fEM_R0UN02RIM},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{ 285	,8	,1	, &fEM_A1UR01RIM},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{ 286	,8	,1	, &fEM_A1UR00RIM},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{ 287	,8	,1	, &fEM_A3UR00RIM},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{ 288	,8	,1	, &fEM_A3UR01RIM},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{ 289	,8	,1	, &fEM_R0UT01RIM},	//(R0UT01RIM) Температурный коэффициент (долл)
	{ 290	,8	,1	, &fEM_R0UT02RIM},	//(R0UT02RIM) Масса топлива в АЗ
	{ 291	,8	,1	, &fEM_R0UT04RIM},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{ 292	,8	,1	, &fEM_R0UT03RIM},	//(R0UT03RIM) Нормальная температура АЗ град
	{ 293	,8	,1	, &fEM_R0UT05RIM},	//(R0UT05RIM) Энергия деления ядра
	{ 294	,8	,1	, &fEM_R0UT06RIM},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{ 295	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{ 296	,8	,1	, &fEM_A1UC04RIM},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{ 297	,8	,1	, &fEM_A1UC05RIM},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{ 298	,8	,1	, &fEM_A1UC06RIM},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{ 299	,8	,1	, &fEM_A2UC06RIM},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{ 300	,8	,1	, &fEM_A2UC05RIM},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{ 301	,8	,1	, &fEM_A2UC04RIM},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{ 302	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{ 303	,8	,1	, &fEM_A3UC06RIM},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{ 304	,8	,1	, &fEM_A3UC05RIM},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{ 305	,8	,1	, &fEM_A3UC04RIM},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{ 306	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{ 307	,8	,1	, &fEM_R4UV80RDU},	//(R4UV80RDU) Номинальная скорость тележки (см/с)
	{ 308	,8	,1	, &fEM_R4UC10RIM},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{ 309	,8	,1	, &fEM_R4UC20RIM},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{ 310	,8	,1	, &fEM_B8UC21RIM},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{ 311	,8	,1	, &fEM_B8UC20RIM},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{ 312	,8	,1	, &fEM_B8UC11RIM},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{ 313	,8	,1	, &fEM_B8UC10RIM},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{ 314	,8	,1	, &fEM_B8UV80RDU},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{ 315	,8	,1	, &fEM_A8UV80RDU},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{ 316	,8	,1	, &fEM_A8UC10RIM},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{ 317	,8	,1	, &fEM_A8UC11RIM},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{ 318	,8	,1	, &fEM_A8UC20RIM},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{ 319	,8	,1	, &fEM_A8UC21RIM},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{ 320	,8	,1	, &fEM_A6UC10RIM},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{ 321	,8	,1	, &fEM_R1UC10RIM},	//(R1UC10RIM) Время полного хода МДЗ сек
	{ 322	,8	,1	, &fEM_A5UC10RIM},	//(A5UC10RIM) Время полного хода НЛ сек
	{ 323	,8	,1	, &fEM_A0UN01RIM},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{ 324	,8	,1	, &fEM_R4UC22RIM},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{ 325	,8	,1	, &fEM_A1UG01RDU},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{ 326	,8	,1	, &fEM_A2UG01RDU},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{ 327	,8	,1	, &fEM_A3UG01RDU},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{ 328	,8	,1	, &fEM_R7UC10RIM},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{ 329	,8	,1	, &fEM_R7UC19RIM},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{ 330	,8	,1	, &fEM_R7UI02RIM},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{ 331	,8	,1	, &fEM_R7UL01RIM},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{ 332	,8	,1	, &fEM_A2UR00RIM},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{ 333	,8	,1	, &fEM_A2UR01RIM},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{ 334	,8	,1	, &fEM_A0UN02RIM},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{ 335	,8	,1	, &fEM_R0UR30RIM},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{ 336	,8	,1	, &fEM_R0UR01RIM},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{ 337	,8	,1	, &fEM_R0UT02RDU},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{ 338	,8	,1	, &fEM_R0UT01RDU},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{ 339	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{ 340	,8	,1	, &fEM_A2UP03RDU},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{ 341	,8	,1	, &fEM_A2UP04RDU},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{ 342	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{ 343	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 344	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 345	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{ 346	,8	,1	, &fEM_R7UI74RIM},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{ 347	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{ 348	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 349	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 350	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 351	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 352	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 353	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 354	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 355	,8	,1	, &fEM_A8UC08RDU},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{ 356	,8	,1	, &fEM_B8UC08RDU},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{ 357	,8	,1	, &fEM_R4UC08RDU},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{ 358	,8	,1	, &fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
	{ 359	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 360	,8	,1	, &fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{ 361	,8	,1	, &fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{ 362	,8	,1	, &fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{ 363	,8	,1	, &fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{ 364	,8	,1	, &fEM_R7UX06RSS},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{ 365	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 366	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 367	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 368	,8	,1	, &fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{ 369	,8	,1	, &fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{ 370	,8	,1	, &fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{ 371	,8	,1	, &fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{ 372	,8	,1	, &fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{ 373	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 374	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 375	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 376	,8	,1	, &fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{ 377	,8	,1	, &fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{ 378	,8	,1	, &fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{ 379	,8	,1	, &fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{ 380	,8	,1	, &fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{ 381	,8	,1	, &fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{ 382	,8	,1	, &fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{ 383	,8	,1	, &fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{ 384	,8	,1	, &fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{ 385	,8	,1	, &fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{ 386	,8	,1	, &fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{ 387	,8	,1	, &fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{ 388	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 389	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 390	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 391	,8	,1	, &fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{ 392	,8	,1	, &fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{ 393	,8	,1	, &fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{ 394	,8	,1	, &fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{ 395	,8	,1	, &fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{ 396	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 397	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{ 398	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 399	,8	,1	, &fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{ 400	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 401	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 402	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 403	,8	,1	, &fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{ 404	,8	,1	, &fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{ 405	,8	,1	, &fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{ 406	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{ 407	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{ 408	,8	,1	, &fEM_R4US80RDU},	//(R4US80RDU) Тормозной путь тележки (мм)
	{ 409	,8	,1	, &fEM_R7UI71RIM},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{ 410	,8	,1	, &fEM_R7UI72RIM},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{ 411	,8	,1	, &fEM_R7UI73RIM},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{ 412	,8	,1	, &fEM_A1UP01RIM},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{ 413	,8	,1	, &fEM_A2UP01RIM},	//(A2UP01RIM) Текущее давление на сброс РБ
	{ 414	,8	,1	, &fEM_A0UP02RIM},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{ 415	,8	,1	, &fEM_A3UP01RIM},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{ 416	,8	,1	, &fEM_A1UP82RIM},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{ 417	,8	,1	, &fEM_A3UP02RDU},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{ 418	,8	,1	, &fEM_A1UV02RIM},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{ 419	,8	,1	, &fEM_A3UV02RIM},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{ 420	,8	,1	, &fEM_A2UV02RIM},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{ 421	,8	,1	, &fEM_B8US80RDU},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{ 422	,8	,1	, &fEM_A8US80RDU},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{ 423	,8	,1	, &fEM_A6US80RDU},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{ 424	,8	,1	, &fEM_A1US07RDU},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{ 425	,8	,1	, &fEM_A2US07RDU},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{ 426	,8	,1	, &fEM_A3US07RDU},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{ 427	,8	,1	, &fEM_R7UI75RIM},	//(R7UI75RIM) Множитель к уровню радиации
	{ 428	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 429	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 430	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 431	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 432	,8	,1	, &fEM_A4UL10RIM},	//(A4UL10RIM) Время полного перемещения НИ сек
	{ 433	,8	,1	, &fEM_A9UL10RIM},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{ 434	,8	,1	, &fEM_R3UL10RIM},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{ 435	,8	,1	, &fEM_R5UL10RIM},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{ 436	,8	,1	, &fEM_R6UL10RIM},	//(R6UL10RIM) Время полного хода кран-балки сек
	{ 437	,1	,1	, &lEM_C1AD31LRP},	//(C1AD31LRP) Общий сброс от РПУ
	{ 438	,1	,1	, &lEM_R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов
	{ 439	,1	,1	, &lEM_R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{ 440	,8	,1	, &fEM_A2UP02RIM},	//(A2UP02RIM) Текущее давление на подъём РБ
	{ 441	,8	,1	, &fEM_A2UP03RIM},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{ 442	,8	,1	, &fEM_A0UP01RIM},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{ 443	,8	,1	, &fEM_A3UP02RIM},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{ 444	,8	,1	, &fEM_A4UP01RIM},	//(A4UP01RIM) Текущее давление на подъём НИ
	{ 445	,8	,1	, &fEM_A4UP02RIM},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{ 446	,8	,1	, &fEM_R7UI76RIM},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{ 447	,8	,1	, &fEM_R7UI77RIM},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{ 448	,3	,1	, &iEM_TERBB1},	//(TERBB1) Неисправности  ББ1
	{ 449	,8	,1	, &fEM_A1MC02RC1},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{ 450	,8	,1	, &fEM_A1MV02RC1},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{ 451	,3	,1	, &iEM_TERBB2},	//(TERBB2) Неисправности  ББ2
	{ 452	,8	,1	, &fEM_B1MC02RC1},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{ 453	,8	,1	, &fEM_B1MV02RC1},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{ 454	,3	,1	, &iEM_TERRB2},	//(TERRB2) Неисправности  РБ2
	{ 455	,8	,1	, &fEM_B2MC02RC1},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{ 456	,8	,1	, &fEM_B2MV02RC1},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{ 457	,3	,1	, &iEM_TERRB1},	//(TERRB1) Неисправности  РБ1
	{ 458	,8	,1	, &fEM_A2MC02RC1},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{ 459	,8	,1	, &fEM_A2MV02RC1},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{ 460	,3	,1	, &iEM_TERIS2},	//(TERIS2) Неисправности  ИС2
	{ 461	,8	,1	, &fEM_B3MC02RC1},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{ 462	,8	,1	, &fEM_B3MV02RC1},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{ 463	,3	,1	, &iEM_TERIS1},	//(TERIS1) Неисправности  ИС1
	{ 464	,8	,1	, &fEM_A3MC02RC1},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{ 465	,8	,1	, &fEM_A3MV02RC1},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{ 466	,3	,1	, &iEM_TERA1IE04LDU},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{ 467	,3	,1	, &iEM_TERA1IE03LDU},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{ 468	,8	,1	, &fEM_A1MC01RC1},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{ 469	,3	,1	, &iEM_TERB1IE03LDU},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{ 470	,3	,1	, &iEM_TERB1IE04LDU},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{ 471	,8	,1	, &fEM_B1MC01RC1},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{ 472	,8	,1	, &fEM_B1MV01RC1},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{ 473	,8	,1	, &fEM_B2MC01RC1},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{ 474	,8	,1	, &fEM_B2MV01RC1},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{ 475	,8	,1	, &fEM_A3MC01RC1},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{ 476	,8	,1	, &fEM_A3MV01RC1},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{ 477	,8	,1	, &fEM_B3MC01RC1},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{ 478	,8	,1	, &fEM_B3MV01RC1},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{ 479	,3	,1	, &iEM_TERA2SS21LIM},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{ 480	,3	,1	, &iEM_TERA2SS12LIM},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{ 481	,3	,1	, &iEM_TERR6SS21LIM},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{ 482	,3	,1	, &iEM_TERA2VP82LIM},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{ 483	,3	,1	, &iEM_TERA2SS11LIM},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{ 484	,3	,1	, &iEM_TERB3SS21LIM},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{ 485	,3	,1	, &iEM_TERA0MT01RIM},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{ 486	,3	,1	, &iEM_TERB0MT01RIM},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{ 487	,3	,1	, &iEM_TERA2SP01RIM},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{ 488	,3	,1	, &iEM_TERB2SP01RIM},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{ 489	,3	,1	, &iEM_TERB3SP02RIM},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{ 490	,3	,1	, &iEM_TERA3SC01RIM},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{ 491	,3	,1	, &iEM_TERA3VP81LIM},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{ 492	,3	,1	, &iEM_TERA2SC01RIM},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{ 493	,3	,1	, &iEM_TERA2SS33LIM},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{ 494	,3	,1	, &iEM_TERA3SS21LIM},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{ 495	,3	,1	, &iEM_TERA3SS33LIM},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{ 496	,3	,1	, &iEM_TERA3SS31LIM},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{ 497	,3	,1	, &iEM_TERB3SS31LIM},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{ 498	,3	,1	, &iEM_TERB3SS33LIM},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 499	,3	,1	, &iEM_TERB3SC01RIM},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{ 500	,3	,1	, &iEM_TERA3SS11LIM},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{ 501	,3	,1	, &iEM_TERB3SS11LIM},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{ 502	,3	,1	, &iEM_TERR6IS64LIM},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{ 503	,3	,1	, &iEM_TERB3SS22LIM},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{ 504	,3	,1	, &iEM_TERA3SS22LIM},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{ 505	,3	,1	, &iEM_TERA3SP02RIM},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{ 506	,3	,1	, &iEM_TERR6IS62LIM},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{ 507	,3	,1	, &iEM_TERR6IS66LIM},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 508	,3	,1	, &iEM_TERR6IS67LIM},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 509	,3	,1	, &iEM_TERA0VP81LIM},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{ 510	,3	,1	, &iEM_TERB0VP81LIM},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{ 511	,3	,1	, &iEM_TERR0VP81LIM},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{ 512	,3	,1	, &iEM_TERR6IS68LIM},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{ 513	,3	,1	, &iEM_TERR7SI74RIM},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{ 514	,3	,1	, &iEM_TERA5SS21LIM},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{ 515	,3	,1	, &iEM_TERB5SS11LIM},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{ 516	,3	,1	, &iEM_TERA5SS11LIM},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{ 517	,3	,1	, &iEM_TERA9SS11LIM},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{ 518	,3	,1	, &iEM_TERB2SS11LIM},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{ 519	,3	,1	, &iEM_TERB2SS12LIM},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{ 520	,3	,1	, &iEM_TERB2SS21LIM},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{ 521	,3	,1	, &iEM_TERR3SS11LIM},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{ 522	,3	,1	, &iEM_TERB2SC01RIM},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{ 523	,3	,1	, &iEM_TERR3SS21LIM},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{ 524	,3	,1	, &iEM_TERR5SS11LIM},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{ 525	,3	,1	, &iEM_TERA4SS11LIM},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{ 526	,3	,1	, &iEM_TERR1SS11LIM},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{ 527	,3	,1	, &iEM_TERR1SS21LIM},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{ 528	,3	,1	, &iEM_TERR2SS11LIM},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{ 529	,3	,1	, &iEM_TERR2SS21LIM},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{ 530	,3	,1	, &iEM_TERA4VP82LIM},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{ 531	,3	,1	, &iEM_TERB4SS21LIM},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{ 532	,3	,1	, &iEM_TERR5SS21LIM},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{ 533	,3	,1	, &iEM_TERB6SS21LIM},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{ 534	,3	,1	, &iEM_TERB4SS11LIM},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{ 535	,3	,1	, &iEM_TERA4SS21LIM},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{ 536	,3	,1	, &iEM_TERA6MS11LIM},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{ 537	,3	,1	, &iEM_TERA6SS21LIM},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{ 538	,3	,1	, &iEM_TERB6SS11LIM},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{ 539	,3	,1	, &iEM_TERR4SS11LIM},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{ 540	,3	,1	, &iEM_TERR4MS21LIM},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{ 541	,3	,1	, &iEM_TERR4SS12LIM},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{ 542	,3	,1	, &iEM_TERR4SS22LIM},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{ 543	,3	,1	, &iEM_TERR8SS11LIM},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{ 544	,3	,1	, &iEM_TERB8SC01RIM},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{ 545	,3	,1	, &iEM_TERA8SC01RIM},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{ 546	,3	,1	, &iEM_TERB8SS12LIM},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{ 547	,3	,1	, &iEM_TERA8SS12LIM},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{ 548	,3	,1	, &iEM_TERB8SS22LIM},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{ 549	,3	,1	, &iEM_TERA8SS22LIM},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{ 550	,3	,1	, &iEM_TERA9SS21LIM},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{ 551	,3	,1	, &iEM_TERB9SS21LIM},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{ 552	,3	,1	, &iEM_TERB9SS11LIM},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{ 553	,3	,1	, &iEM_TERB5SS21LIM},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{ 554	,3	,1	, &iEM_TERA1SS21LIM},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{ 555	,3	,1	, &iEM_TERA1SS11LIM},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{ 556	,3	,1	, &iEM_TERA1SC01RIM},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{ 557	,3	,1	, &iEM_TERA1SS12LIM},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{ 558	,3	,1	, &iEM_TERB1SS21LIM},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{ 559	,3	,1	, &iEM_TERB1SS11LIM},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{ 560	,3	,1	, &iEM_TERB1MC01RIM},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{ 561	,3	,1	, &iEM_TERB1SS12LIM},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{ 562	,3	,1	, &iEM_TERTLG},	//(TERTLG) Неисправности  тележки от ИС
	{ 563	,8	,1	, &fEM_R4MC01RC1},	//(R4MC01RC1) Заданная координата тележки от ИС
	{ 564	,8	,1	, &fEM_R4MV01RC1},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{ 565	,3	,1	, &iEM_TERMAZ2},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{ 566	,8	,1	, &fEM_B8MV01RC1},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{ 567	,3	,1	, &iEM_TERDS2},	//(TERDS2) Неисправности ДС2 от ИС
	{ 568	,8	,1	, &fEM_A8MC01RC1},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{ 569	,8	,1	, &fEM_A8MV01RC1},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{ 570	,3	,1	, &iEM_TERBZ1},	//(TERBZ1) Неисправности БЗ1
	{ 571	,8	,1	, &fEM_A6MC01RC1},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{ 572	,8	,1	, &fEM_A6MV01RC1},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{ 573	,3	,1	, &iEM_TERBZ2},	//(TERBZ2) Неисправности БЗ2
	{ 574	,8	,1	, &fEM_B6MC01RC1},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{ 575	,8	,1	, &fEM_B6MV01RC1},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{ 576	,1	,1	, &lEM_R3AD10LC1},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{ 577	,1	,1	, &lEM_R3AD20LC1},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{ 578	,1	,1	, &lEM_R6AD10LC1},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{ 579	,1	,1	, &lEM_R5AD10LC1},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{ 580	,1	,1	, &lEM_R5AD20LC1},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{ 581	,3	,1	, &iEM_TERMDZ2},	//(TERMDZ2) Неисправности МДЗ2
	{ 582	,8	,1	, &fEM_R2MC01RC1},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{ 583	,8	,1	, &fEM_R2MV01RC1},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{ 584	,3	,1	, &iEM_TERMDZ1},	//(TERMDZ1) Неисправности МДЗ1
	{ 585	,8	,1	, &fEM_R1MC01RC1},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{ 586	,8	,1	, &fEM_R1MV01RC1},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{ 587	,3	,1	, &iEM_TERNL1},	//(TERNL1) Неисправности НЛ1
	{ 588	,8	,1	, &fEM_A5MC01RC1},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{ 589	,8	,1	, &fEM_A5MV01RC1},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{ 590	,3	,1	, &iEM_TERNL2},	//(TERNL2) Неисправности НЛ2
	{ 591	,8	,1	, &fEM_B5MC01RC1},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{ 592	,8	,1	, &fEM_B5MV01RC1},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{ 593	,1	,1	, &lEM_R8AD10LC1},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{ 594	,8	,1	, &fEM_A1UC08RIM},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{ 595	,8	,1	, &fEM_A2UC08RIM},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{ 596	,8	,1	, &fEM_A3UC08RIM},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{ 597	,3	,1	, &iEM_TERB2SS33LIM},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{ 598	,3	,1	, &iEM_TERA1VP81LIM},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{ 599	,3	,1	, &iEM_TERB1VP81LIM},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{ 600	,8	,1	, &fEM_A0UT03RSP},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{ 601	,8	,1	, &fEM_A0UR01RSP},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{ 602	,8	,1	, &fEM_A0UR02RSP},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{ 603	,8	,1	, &fEM_B0UT03RSP},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{ 604	,8	,1	, &fEM_A1MC01RSP},	//(A1MC01RSP) Стартовая координата  ББ1
	{ 605	,8	,1	, &fEM_A1MC02RSP},	//(A1MC02RSP) Стартовая координата штока ББ1
	{ 606	,8	,1	, &fEM_B1MC01RSP},	//(B1MC01RSP) Стартовая координата  ББ2
	{ 607	,8	,1	, &fEM_B1MC02RSP},	//(B1MC02RSP) Стартовая координата штока ББ2
	{ 608	,8	,1	, &fEM_A2MC01RC1},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{ 609	,8	,1	, &fEM_A2MV01RC1},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{ 610	,8	,1	, &fEM_A2MC01RSP},	//(A2MC01RSP) Стартовая координата  РБ1
	{ 611	,8	,1	, &fEM_A2MC02RSP},	//(A2MC02RSP) Стартовая координата штока РБ1
	{ 612	,8	,1	, &fEM_B2MC01RSP},	//(B2MC01RSP) Стартовая координата  РБ2
	{ 613	,8	,1	, &fEM_B2MC02RSP},	//(B2MC02RSP) Стартовая координата штока РБ2
	{ 614	,8	,1	, &fEM_A3MC01RSP},	//(A3MC01RSP) Стартовая координата  ИС1
	{ 615	,8	,1	, &fEM_A3MC02RSP},	//(A3MC02RSP) Стартовая координата штока ИС1
	{ 616	,8	,1	, &fEM_B3MC01RSP},	//(B3MC01RSP) Стартовая координата  ИС2
	{ 617	,8	,1	, &fEM_B3MC02RSP},	//(B3MC02RSP) Стартовая координата штока ИС2
	{ 618	,8	,1	, &fEM_B8MC01RSP},	//(B8MC01RSP) Стартовая координата АЗ2
	{ 619	,8	,1	, &fEM_A8MC01RSP},	//(A8MC01RSP) Стартовая координата ДС2
	{ 620	,8	,1	, &fEM_A6MC01RSP},	//(A6MC01RSP) Стартовая координата БЗ1
	{ 621	,8	,1	, &fEM_B6MC01RSP},	//(B6MC01RSP) Стартовая координата БЗ2
	{ 622	,8	,1	, &fEM_R3UC01RSP},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{ 623	,8	,1	, &fEM_R5UC01RSP},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{ 624	,8	,1	, &fEM_R6UC01RSP},	//(R6UC01RSP) Стартовая координата Кран-балки
	{ 625	,8	,1	, &fEM_R2MC01RSP},	//(R2MC01RSP) Стартовая координата МДЗ2
	{ 626	,8	,1	, &fEM_R1MC01RSP},	//(R1MC01RSP) Стартовая координата МДЗ1
	{ 627	,8	,1	, &fEM_A5MC01RSP},	//(A5MC01RSP) Стартовая координата НЛ1
	{ 628	,8	,1	, &fEM_B5MC01RSP},	//(B5MC01RSP) Стартовая координата НЛ2
	{ 629	,8	,1	, &fEM_A9MC01RSP},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{ 630	,8	,1	, &fEM_B9MC01RSP},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{ 631	,8	,1	, &fEM_A4MC01RSP},	//(A4MC01RSP) Стартовая координата НИ1
	{ 632	,8	,1	, &fEM_B4MC01RSP},	//(B4MC01RSP) Стартовая координата НИ2
	{ 633	,8	,1	, &fEM_R4MC01RSP},	//(R4MC01RSP) Стартовая координата тележки
	{ 634	,8	,1	, &fEM_A1MV01RC1},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{ 635	,3	,1	, &iEM_TERB7MS31LIM},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{ 636	,3	,1	, &iEM_TERA7MS31LIM},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{ 637	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 см
	{ 638	,3	,1	, &iEM_TERA6VS12LIM},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{ 639	,3	,1	, &iEM_TERA6VS22LIM},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{ 640	,3	,1	, &iEM_TERB6VS12LIM},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{ 641	,3	,1	, &iEM_TERB6VS22LIM},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{ 642	,3	,1	, &iEM_TERA5VS22LIM},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{ 643	,3	,1	, &iEM_TERA5VS12LIM},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{ 644	,3	,1	, &iEM_TERB5VS12LIM},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{ 645	,3	,1	, &iEM_TERB5VS22LIM},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{ 646	,3	,1	, &iEM_TERR1VS12LIM},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{ 647	,3	,1	, &iEM_TERR1VS22LIM},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{ 648	,3	,1	, &iEM_TERR2VS12LIM},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{ 649	,3	,1	, &iEM_TERR2VS22LIM},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{ 650	,3	,1	, &iEM_TERR4VS12LDU},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 651	,3	,1	, &iEM_TERR4VS22LDU},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 652	,8	,1	, &fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{ 653	,8	,1	, &fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{ 654	,8	,1	, &fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{ 655	,8	,1	, &fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{ 656	,8	,1	, &fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{ 657	,8	,1	, &fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{ 658	,8	,1	, &fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{ 659	,8	,1	, &fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{ 660	,8	,1	, &fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{ 661	,8	,1	, &fEM_R7UX16RSS},	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
	{ 662	,8	,1	, &fEM_B8MC01RC1},	//(B8MC01RC1) Заданная координата АЗ2 от ИС
	{ 663	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 664	,8	,1	, &internal1_m708_xy},	//(internal1_m708_xy) xy - предыдущее
	{ 665	,8	,1	, &internal1_m876_Chim0},	//(internal1_m876_Chim0) измеренная частота импульсов камеры Гц
	{ 666	,8	,1	, &internal1_m866_Chim0},	//(internal1_m866_Chim0) измеренная частота импульсов камеры Гц
	{ 667	,8	,1	, &internal1_m858_Chim0},	//(internal1_m858_Chim0) измеренная частота импульсов камеры Гц
	{ 668	,1	,1	, &internal1_m813_Out10},	//(internal1_m813_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 669	,1	,1	, &internal1_m812_Out10},	//(internal1_m812_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 670	,1	,1	, &internal1_m995_Out10},	//(internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 671	,1	,1	, &internal1_m994_Out10},	//(internal1_m994_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 672	,1	,1	, &internal1_m993_Out10},	//(internal1_m993_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 673	,1	,1	, &internal1_m992_Out10},	//(internal1_m992_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 674	,1	,1	, &internal1_m670_Out10},	//(internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 675	,1	,1	, &internal1_m669_Out10},	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 676	,1	,1	, &internal1_m648_Out10},	//(internal1_m648_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 677	,1	,1	, &internal1_m647_Out10},	//(internal1_m647_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 678	,1	,1	, &internal1_m668_Out10},	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 679	,1	,1	, &internal1_m667_Out10},	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 680	,1	,1	, &internal1_m646_Out10},	//(internal1_m646_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 681	,1	,1	, &internal1_m645_Out10},	//(internal1_m645_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 682	,1	,1	, &internal1_m512_Out10},	//(internal1_m512_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 683	,1	,1	, &internal1_m528_Out10},	//(internal1_m528_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 684	,1	,1	, &internal1_m400_Out10},	//(internal1_m400_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 685	,1	,1	, &internal1_m473_q0},	//(internal1_m473_q0) q0 - внутренний параметр
	{ 686	,1	,1	, &internal1_m474_q0},	//(internal1_m474_q0) q0 - внутренний параметр
	{ 687	,1	,1	, &internal1_m461_q0},	//(internal1_m461_q0) q0 - внутренний параметр
	{ 688	,1	,1	, &internal1_m462_q0},	//(internal1_m462_q0) q0 - внутренний параметр
	{ 689	,8	,1	, &internal1_m621_tx},	//(internal1_m621_tx) tx - время накопленное сек
	{ 690	,18	,1	, &internal1_m621_y0},	//(internal1_m621_y0) y0
	{ 691	,8	,1	, &internal1_m609_tx},	//(internal1_m609_tx) tx - время накопленное сек
	{ 692	,18	,1	, &internal1_m609_y0},	//(internal1_m609_y0) y0
	{ 693	,8	,1	, &internal1_m597_tx},	//(internal1_m597_tx) tx - время накопленное сек
	{ 694	,18	,1	, &internal1_m597_y0},	//(internal1_m597_y0) y0
	{ 695	,8	,1	, &internal1_m595_tx},	//(internal1_m595_tx) tx - время накопленное сек
	{ 696	,18	,1	, &internal1_m595_y0},	//(internal1_m595_y0) y0
	{ 697	,1	,1	, &internal1_m205_Out10},	//(internal1_m205_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 698	,1	,1	, &internal1_m222_Out10},	//(internal1_m222_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 699	,1	,1	, &internal1_m41_Out10},	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 700	,1	,1	, &internal1_m56_Out10},	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 701	,1	,1	, &internal1_m966_Out10},	//(internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 702	,1	,1	, &internal1_m963_Out10},	//(internal1_m963_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 703	,1	,1	, &internal1_m962_Out10},	//(internal1_m962_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 704	,8	,1	, &internal1_m965_Xtek0},	//(internal1_m965_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 705	,8	,1	, &internal1_m948_Xtek0},	//(internal1_m948_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 706	,1	,1	, &internal1_m949_Out10},	//(internal1_m949_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 707	,1	,1	, &internal1_m946_Out10},	//(internal1_m946_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 708	,1	,1	, &internal1_m945_Out10},	//(internal1_m945_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 709	,1	,1	, &internal1_m1033_Out10},	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 710	,1	,1	, &internal1_m1014_Out10},	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 711	,1	,1	, &internal1_m1013_Out10},	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 712	,1	,1	, &internal1_m1012_Out10},	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 713	,1	,1	, &internal1_m834_Out10},	//(internal1_m834_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 714	,1	,1	, &internal1_m836_Out10},	//(internal1_m836_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 715	,1	,1	, &internal1_m833_Out10},	//(internal1_m833_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 716	,1	,1	, &internal1_m835_Out10},	//(internal1_m835_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 717	,1	,1	, &internal1_m809_Out10},	//(internal1_m809_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 718	,1	,1	, &internal1_m810_Out10},	//(internal1_m810_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 719	,1	,1	, &internal1_m808_Out10},	//(internal1_m808_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 720	,1	,1	, &internal1_m807_Out10},	//(internal1_m807_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 721	,1	,1	, &internal1_m1028_Out10},	//(internal1_m1028_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 722	,1	,1	, &internal1_m980_Out10},	//(internal1_m980_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 723	,1	,1	, &internal1_m979_Out10},	//(internal1_m979_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 724	,1	,1	, &internal1_m978_Out10},	//(internal1_m978_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 725	,1	,1	, &internal1_m977_Out10},	//(internal1_m977_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 726	,1	,1	, &internal1_m1029_Out10},	//(internal1_m1029_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 727	,1	,1	, &internal1_m1010_Out10},	//(internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 728	,1	,1	, &internal1_m811_Out10},	//(internal1_m811_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 729	,1	,1	, &internal1_m1011_Out10},	//(internal1_m1011_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 730	,1	,1	, &internal1_m1009_Out10},	//(internal1_m1009_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 731	,1	,1	, &internal1_m1030_Out10},	//(internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 732	,1	,1	, &internal1_m1008_Out10},	//(internal1_m1008_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 733	,1	,1	, &internal1_m991_Out10},	//(internal1_m991_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 734	,1	,1	, &internal1_m976_Out10},	//(internal1_m976_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 735	,1	,1	, &internal1_m529_Out10},	//(internal1_m529_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 736	,8	,1	, &internal1_m410_Xtek0},	//(internal1_m410_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 737	,1	,1	, &internal1_m401_Out10},	//(internal1_m401_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 738	,1	,1	, &internal1_m403_Out10},	//(internal1_m403_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 739	,1	,1	, &internal1_m402_Out10},	//(internal1_m402_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 740	,1	,1	, &internal1_m849_Out10},	//(internal1_m849_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 741	,1	,1	, &internal1_m850_Out10},	//(internal1_m850_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 742	,1	,1	, &internal1_m848_Out10},	//(internal1_m848_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 743	,1	,1	, &internal1_m1032_Out10},	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 744	,1	,1	, &internal1_m683_Out10},	//(internal1_m683_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 745	,1	,1	, &internal1_m684_Out10},	//(internal1_m684_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 746	,1	,1	, &internal1_m681_Out10},	//(internal1_m681_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 747	,1	,1	, &internal1_m682_Out10},	//(internal1_m682_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 748	,1	,1	, &internal1_m545_Out10},	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 749	,1	,1	, &internal1_m544_Out10},	//(internal1_m544_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 750	,8	,1	, &internal1_m830_Xtek0},	//(internal1_m830_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 751	,8	,1	, &internal1_m832_Xtek0},	//(internal1_m832_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 752	,1	,1	, &internal1_m680_Out10},	//(internal1_m680_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 753	,1	,1	, &internal1_m664_Out10},	//(internal1_m664_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 754	,1	,1	, &internal1_m644_Out10},	//(internal1_m644_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 755	,1	,1	, &internal1_m663_Out10},	//(internal1_m663_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 756	,1	,1	, &internal1_m643_Out10},	//(internal1_m643_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 757	,1	,1	, &internal1_m331_Out10},	//(internal1_m331_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 758	,1	,1	, &internal1_m330_Out10},	//(internal1_m330_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 759	,1	,1	, &internal1_m315_Out10},	//(internal1_m315_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 760	,1	,1	, &internal1_m314_Out10},	//(internal1_m314_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 761	,1	,1	, &internal1_m546_Out10},	//(internal1_m546_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 762	,1	,1	, &internal1_m344_Out10},	//(internal1_m344_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 763	,8	,1	, &internal1_m328_Xtek0},	//(internal1_m328_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 764	,1	,1	, &internal1_m343_Out10},	//(internal1_m343_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 765	,1	,1	, &internal1_m341_Out10},	//(internal1_m341_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 766	,8	,1	, &internal1_m318_Xtek0},	//(internal1_m318_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 767	,1	,1	, &internal1_m342_Out10},	//(internal1_m342_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 768	,1	,1	, &internal1_m313_Out10},	//(internal1_m313_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 769	,1	,1	, &internal1_m329_Out10},	//(internal1_m329_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 770	,1	,1	, &internal1_m422_Out10},	//(internal1_m422_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 771	,8	,1	, &internal1_m423_Xtek0},	//(internal1_m423_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 772	,1	,1	, &internal1_m421_Out10},	//(internal1_m421_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 773	,1	,1	, &internal1_m420_Out10},	//(internal1_m420_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 774	,1	,1	, &internal1_m419_Out10},	//(internal1_m419_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 775	,1	,1	, &internal1_m1031_Out10},	//(internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 776	,1	,1	, &internal1_m146_Out10},	//(internal1_m146_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 777	,1	,1	, &internal1_m145_Out10},	//(internal1_m145_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 778	,3	,1	, &internal1_m194_tx},	//(internal1_m194_tx) tx - внутренний параметр
	{ 779	,3	,1	, &internal1_m25_tx},	//(internal1_m25_tx) tx - внутренний параметр
	{ 780	,8	,1	, &internal1_m465_X00},	//(internal1_m465_X00)  X00 - текущая координата механизма
	{ 781	,8	,1	, &internal1_m465_V00},	//(internal1_m465_V00)  V00 - текущая скорость механизма
	{ 782	,1	,1	, &internal1_m465_Pav0},	//(internal1_m465_Pav0)  - Пер.аварийный выключатель механизма
	{ 783	,1	,1	, &internal1_m465_Zav0},	//(internal1_m465_Zav0)  - Зад.аварийный выключатель механизма
	{ 784	,1	,1	, &internal1_m465_Pv0},	//(internal1_m465_Pv0)  - Пер. выключатель механизма
	{ 785	,1	,1	, &internal1_m465_Zv0},	//(internal1_m465_Zv0)  - Зад. выключатель механизма
	{ 786	,1	,1	, &internal1_m465_RA00},	//(internal1_m465_RA00)  - последнее задание вперед
	{ 787	,1	,1	, &internal1_m465_RA10},	//(internal1_m465_RA10)  - последнее задание назад
	{ 788	,1	,1	, &internal1_m465_MyFirstEnterFlag},	//(internal1_m465_MyFirstEnterFlag) MyFirstEnterFlag
	{ 789	,8	,1	, &internal1_m477_X00},	//(internal1_m477_X00)  X00 - текущая координата механизма
	{ 790	,8	,1	, &internal1_m477_V00},	//(internal1_m477_V00)  V00 - текущая скорость механизма
	{ 791	,1	,1	, &internal1_m477_Pav0},	//(internal1_m477_Pav0)  - Пер.аварийный выключатель механизма
	{ 792	,1	,1	, &internal1_m477_Zav0},	//(internal1_m477_Zav0)  - Зад.аварийный выключатель механизма
	{ 793	,1	,1	, &internal1_m477_Pv0},	//(internal1_m477_Pv0)  - Пер. выключатель механизма
	{ 794	,1	,1	, &internal1_m477_Zv0},	//(internal1_m477_Zv0)  - Зад. выключатель механизма
	{ 795	,1	,1	, &internal1_m477_RA00},	//(internal1_m477_RA00)  - последнее задание вперед
	{ 796	,1	,1	, &internal1_m477_RA10},	//(internal1_m477_RA10)  - последнее задание назад
	{ 797	,1	,1	, &internal1_m477_MyFirstEnterFlag},	//(internal1_m477_MyFirstEnterFlag) MyFirstEnterFlag
	{ 798	,8	,1	, &internal1_m467_X00},	//(internal1_m467_X00)  X00 - текущая координата механизма
	{ 799	,8	,1	, &internal1_m467_V00},	//(internal1_m467_V00)  V00 - текущая скорость механизма
	{ 800	,1	,1	, &internal1_m467_Pav0},	//(internal1_m467_Pav0)  - Пер.аварийный выключатель механизма
	{ 801	,1	,1	, &internal1_m467_Zav0},	//(internal1_m467_Zav0)  - Зад.аварийный выключатель механизма
	{ 802	,1	,1	, &internal1_m467_Pv0},	//(internal1_m467_Pv0)  - Пер. выключатель механизма
	{ 803	,1	,1	, &internal1_m467_Zv0},	//(internal1_m467_Zv0)  - Зад. выключатель механизма
	{ 804	,1	,1	, &internal1_m467_RA00},	//(internal1_m467_RA00)  - последнее задание вперед
	{ 805	,1	,1	, &internal1_m467_RA10},	//(internal1_m467_RA10)  - последнее задание назад
	{ 806	,1	,1	, &internal1_m467_MyFirstEnterFlag},	//(internal1_m467_MyFirstEnterFlag) MyFirstEnterFlag
	{ 807	,8	,1	, &internal1_m600_X00},	//(internal1_m600_X00)  X00 - текущая координата механизма
	{ 808	,8	,1	, &internal1_m600_V00},	//(internal1_m600_V00)  V00 - текущая скорость механизма
	{ 809	,1	,1	, &internal1_m600_Pav0},	//(internal1_m600_Pav0)  - Пер.аварийный выключатель механизма
	{ 810	,1	,1	, &internal1_m600_Zav0},	//(internal1_m600_Zav0)  - Зад.аварийный выключатель механизма
	{ 811	,1	,1	, &internal1_m600_Pv0},	//(internal1_m600_Pv0)  - Пер. выключатель механизма
	{ 812	,1	,1	, &internal1_m600_Zv0},	//(internal1_m600_Zv0)  - Зад. выключатель механизма
	{ 813	,1	,1	, &internal1_m600_RA00},	//(internal1_m600_RA00)  - последнее задание вперед
	{ 814	,1	,1	, &internal1_m600_RA10},	//(internal1_m600_RA10)  - последнее задание назад
	{ 815	,1	,1	, &internal1_m600_MyFirstEnterFlag},	//(internal1_m600_MyFirstEnterFlag) MyFirstEnterFlag
	{ 816	,8	,1	, &internal1_m599_X00},	//(internal1_m599_X00)  X00 - текущая координата механизма
	{ 817	,8	,1	, &internal1_m599_V00},	//(internal1_m599_V00)  V00 - текущая скорость механизма
	{ 818	,1	,1	, &internal1_m599_Pav0},	//(internal1_m599_Pav0)  - Пер.аварийный выключатель механизма
	{ 819	,1	,1	, &internal1_m599_Zav0},	//(internal1_m599_Zav0)  - Зад.аварийный выключатель механизма
	{ 820	,1	,1	, &internal1_m599_Pv0},	//(internal1_m599_Pv0)  - Пер. выключатель механизма
	{ 821	,1	,1	, &internal1_m599_Zv0},	//(internal1_m599_Zv0)  - Зад. выключатель механизма
	{ 822	,1	,1	, &internal1_m599_RA00},	//(internal1_m599_RA00)  - последнее задание вперед
	{ 823	,1	,1	, &internal1_m599_RA10},	//(internal1_m599_RA10)  - последнее задание назад
	{ 824	,1	,1	, &internal1_m599_MyFirstEnterFlag},	//(internal1_m599_MyFirstEnterFlag) MyFirstEnterFlag
	{ 825	,8	,1	, &internal1_m587_X00},	//(internal1_m587_X00)  X00 - текущая координата механизма
	{ 826	,8	,1	, &internal1_m587_V00},	//(internal1_m587_V00)  V00 - текущая скорость механизма
	{ 827	,1	,1	, &internal1_m587_Pav0},	//(internal1_m587_Pav0)  - Пер.аварийный выключатель механизма
	{ 828	,1	,1	, &internal1_m587_Zav0},	//(internal1_m587_Zav0)  - Зад.аварийный выключатель механизма
	{ 829	,1	,1	, &internal1_m587_Pv0},	//(internal1_m587_Pv0)  - Пер. выключатель механизма
	{ 830	,1	,1	, &internal1_m587_Zv0},	//(internal1_m587_Zv0)  - Зад. выключатель механизма
	{ 831	,1	,1	, &internal1_m587_RA00},	//(internal1_m587_RA00)  - последнее задание вперед
	{ 832	,1	,1	, &internal1_m587_RA10},	//(internal1_m587_RA10)  - последнее задание назад
	{ 833	,1	,1	, &internal1_m587_MyFirstEnterFlag},	//(internal1_m587_MyFirstEnterFlag) MyFirstEnterFlag
	{ 834	,8	,1	, &internal1_m586_X00},	//(internal1_m586_X00)  X00 - текущая координата механизма
	{ 835	,8	,1	, &internal1_m586_V00},	//(internal1_m586_V00)  V00 - текущая скорость механизма
	{ 836	,1	,1	, &internal1_m586_Pav0},	//(internal1_m586_Pav0)  - Пер.аварийный выключатель механизма
	{ 837	,1	,1	, &internal1_m586_Zav0},	//(internal1_m586_Zav0)  - Зад.аварийный выключатель механизма
	{ 838	,1	,1	, &internal1_m586_Pv0},	//(internal1_m586_Pv0)  - Пер. выключатель механизма
	{ 839	,1	,1	, &internal1_m586_Zv0},	//(internal1_m586_Zv0)  - Зад. выключатель механизма
	{ 840	,1	,1	, &internal1_m586_RA00},	//(internal1_m586_RA00)  - последнее задание вперед
	{ 841	,1	,1	, &internal1_m586_RA10},	//(internal1_m586_RA10)  - последнее задание назад
	{ 842	,1	,1	, &internal1_m586_MyFirstEnterFlag},	//(internal1_m586_MyFirstEnterFlag) MyFirstEnterFlag
	{ 843	,8	,1	, &internal1_m629_y0},	//(internal1_m629_y0) y0 - внутренний параметр
	{ 844	,8	,1	, &internal1_m795_Chim0},	//(internal1_m795_Chim0) измеренная частота импульсов камеры Гц
	{ 845	,8	,1	, &internal1_m786_Chim0},	//(internal1_m786_Chim0) измеренная частота импульсов камеры Гц
	{ 846	,8	,1	, &internal1_m778_Chim0},	//(internal1_m778_Chim0) измеренная частота импульсов камеры Гц
	{ 847	,8	,1	, &internal1_m769_Chim0},	//(internal1_m769_Chim0) измеренная частота импульсов камеры Гц
	{ 848	,8	,1	, &internal1_m760_Chim0},	//(internal1_m760_Chim0) измеренная частота импульсов камеры Гц
	{ 849	,8	,1	, &internal1_m752_Chim0},	//(internal1_m752_Chim0) измеренная частота импульсов камеры Гц
	{ 850	,8	,1	, &internal1_m743_Chim0},	//(internal1_m743_Chim0) измеренная частота импульсов камеры Гц
	{ 851	,8	,1	, &internal1_m734_Chim0},	//(internal1_m734_Chim0) измеренная частота импульсов камеры Гц
	{ 852	,8	,1	, &internal1_m726_Chim0},	//(internal1_m726_Chim0) измеренная частота импульсов камеры Гц
	{ 853	,8	,1	, &internal1_m716_Chim0},	//(internal1_m716_Chim0) измеренная частота импульсов камеры Гц
	{ 854	,8	,1	, &internal1_m706_Chim0},	//(internal1_m706_Chim0) измеренная частота импульсов камеры Гц
	{ 855	,8	,1	, &internal1_m696_Chim0},	//(internal1_m696_Chim0) измеренная частота импульсов камеры Гц
	{ 856	,8	,1	, &internal1_m574_X00},	//(internal1_m574_X00)  X00 - текущая координата механизма
	{ 857	,8	,1	, &internal1_m574_V00},	//(internal1_m574_V00)  V00 - текущая скорость механизма
	{ 858	,1	,1	, &internal1_m574_Pav0},	//(internal1_m574_Pav0)  - Пер.аварийный выключатель механизма
	{ 859	,1	,1	, &internal1_m574_Zav0},	//(internal1_m574_Zav0)  - Зад.аварийный выключатель механизма
	{ 860	,1	,1	, &internal1_m574_Pv0},	//(internal1_m574_Pv0)  - Пер. выключатель механизма
	{ 861	,1	,1	, &internal1_m574_Zv0},	//(internal1_m574_Zv0)  - Зад. выключатель механизма
	{ 862	,1	,1	, &internal1_m574_RA00},	//(internal1_m574_RA00)  - последнее задание вперед
	{ 863	,1	,1	, &internal1_m574_RA10},	//(internal1_m574_RA10)  - последнее задание назад
	{ 864	,1	,1	, &internal1_m574_MyFirstEnterFlag},	//(internal1_m574_MyFirstEnterFlag) MyFirstEnterFlag
	{ 865	,8	,1	, &internal1_m560_X00},	//(internal1_m560_X00)  X00 - текущая координата механизма
	{ 866	,8	,1	, &internal1_m560_V00},	//(internal1_m560_V00)  V00 - текущая скорость механизма
	{ 867	,1	,1	, &internal1_m560_Pav0},	//(internal1_m560_Pav0)  - Пер.аварийный выключатель механизма
	{ 868	,1	,1	, &internal1_m560_Zav0},	//(internal1_m560_Zav0)  - Зад.аварийный выключатель механизма
	{ 869	,1	,1	, &internal1_m560_Pv0},	//(internal1_m560_Pv0)  - Пер. выключатель механизма
	{ 870	,1	,1	, &internal1_m560_Zv0},	//(internal1_m560_Zv0)  - Зад. выключатель механизма
	{ 871	,1	,1	, &internal1_m560_RA00},	//(internal1_m560_RA00)  - последнее задание вперед
	{ 872	,1	,1	, &internal1_m560_RA10},	//(internal1_m560_RA10)  - последнее задание назад
	{ 873	,1	,1	, &internal1_m560_MyFirstEnterFlag},	//(internal1_m560_MyFirstEnterFlag) MyFirstEnterFlag
	{ 874	,8	,1	, &internal1_m451_X00},	//(internal1_m451_X00)  X00 - текущая координата механизма
	{ 875	,8	,1	, &internal1_m451_V00},	//(internal1_m451_V00)  V00 - текущая скорость механизма
	{ 876	,1	,1	, &internal1_m451_Pav0},	//(internal1_m451_Pav0)  - Пер.аварийный выключатель механизма
	{ 877	,1	,1	, &internal1_m451_Zav0},	//(internal1_m451_Zav0)  - Зад.аварийный выключатель механизма
	{ 878	,1	,1	, &internal1_m451_Pv0},	//(internal1_m451_Pv0)  - Пер. выключатель механизма
	{ 879	,1	,1	, &internal1_m451_Zv0},	//(internal1_m451_Zv0)  - Зад. выключатель механизма
	{ 880	,1	,1	, &internal1_m451_RA00},	//(internal1_m451_RA00)  - последнее задание вперед
	{ 881	,1	,1	, &internal1_m451_RA10},	//(internal1_m451_RA10)  - последнее задание назад
	{ 882	,1	,1	, &internal1_m451_MyFirstEnterFlag},	//(internal1_m451_MyFirstEnterFlag) MyFirstEnterFlag
	{ 883	,8	,1	, &internal1_m437_X00},	//(internal1_m437_X00)  X00 - текущая координата механизма
	{ 884	,8	,1	, &internal1_m437_V00},	//(internal1_m437_V00)  V00 - текущая скорость механизма
	{ 885	,1	,1	, &internal1_m437_Pav0},	//(internal1_m437_Pav0)  - Пер.аварийный выключатель механизма
	{ 886	,1	,1	, &internal1_m437_Zav0},	//(internal1_m437_Zav0)  - Зад.аварийный выключатель механизма
	{ 887	,1	,1	, &internal1_m437_Pv0},	//(internal1_m437_Pv0)  - Пер. выключатель механизма
	{ 888	,1	,1	, &internal1_m437_Zv0},	//(internal1_m437_Zv0)  - Зад. выключатель механизма
	{ 889	,1	,1	, &internal1_m437_RA00},	//(internal1_m437_RA00)  - последнее задание вперед
	{ 890	,1	,1	, &internal1_m437_RA10},	//(internal1_m437_RA10)  - последнее задание назад
	{ 891	,1	,1	, &internal1_m437_MyFirstEnterFlag},	//(internal1_m437_MyFirstEnterFlag) MyFirstEnterFlag
	{ 892	,8	,1	, &internal1_m488_X00},	//(internal1_m488_X00)  X00 - текущая координата механизма
	{ 893	,8	,1	, &internal1_m488_V00},	//(internal1_m488_V00)  V00 - текущая скорость механизма
	{ 894	,1	,1	, &internal1_m488_Pav0},	//(internal1_m488_Pav0)  - Пер.аварийный выключатель механизма
	{ 895	,1	,1	, &internal1_m488_Zav0},	//(internal1_m488_Zav0)  - Зад.аварийный выключатель механизма
	{ 896	,1	,1	, &internal1_m488_Pv0},	//(internal1_m488_Pv0)  - Пер. выключатель механизма
	{ 897	,1	,1	, &internal1_m488_Zv0},	//(internal1_m488_Zv0)  - Зад. выключатель механизма
	{ 898	,1	,1	, &internal1_m488_RA00},	//(internal1_m488_RA00)  - последнее задание вперед
	{ 899	,1	,1	, &internal1_m488_RA10},	//(internal1_m488_RA10)  - последнее задание назад
	{ 900	,1	,1	, &internal1_m488_MyFirstEnterFlag},	//(internal1_m488_MyFirstEnterFlag) MyFirstEnterFlag
	{ 901	,8	,1	, &internal1_m389_X00},	//(internal1_m389_X00)  X00 - текущая координата механизма
	{ 902	,8	,1	, &internal1_m389_V00},	//(internal1_m389_V00)  V00 - текущая скорость механизма
	{ 903	,1	,1	, &internal1_m389_Pav0},	//(internal1_m389_Pav0)  - Пер.аварийный выключатель механизма
	{ 904	,1	,1	, &internal1_m389_Zav0},	//(internal1_m389_Zav0)  - Зад.аварийный выключатель механизма
	{ 905	,1	,1	, &internal1_m389_Pv0},	//(internal1_m389_Pv0)  - Пер. выключатель механизма
	{ 906	,1	,1	, &internal1_m389_Zv0},	//(internal1_m389_Zv0)  - Зад. выключатель механизма
	{ 907	,1	,1	, &internal1_m389_RA00},	//(internal1_m389_RA00)  - последнее задание вперед
	{ 908	,1	,1	, &internal1_m389_RA10},	//(internal1_m389_RA10)  - последнее задание назад
	{ 909	,1	,1	, &internal1_m389_MyFirstEnterFlag},	//(internal1_m389_MyFirstEnterFlag) MyFirstEnterFlag
	{ 910	,8	,1	, &internal1_m374_X00},	//(internal1_m374_X00)  X00 - текущая координата механизма
	{ 911	,8	,1	, &internal1_m374_V00},	//(internal1_m374_V00)  V00 - текущая скорость механизма
	{ 912	,1	,1	, &internal1_m374_Pav0},	//(internal1_m374_Pav0)  - Пер.аварийный выключатель механизма
	{ 913	,1	,1	, &internal1_m374_Zav0},	//(internal1_m374_Zav0)  - Зад.аварийный выключатель механизма
	{ 914	,1	,1	, &internal1_m374_Pv0},	//(internal1_m374_Pv0)  - Пер. выключатель механизма
	{ 915	,1	,1	, &internal1_m374_Zv0},	//(internal1_m374_Zv0)  - Зад. выключатель механизма
	{ 916	,1	,1	, &internal1_m374_RA00},	//(internal1_m374_RA00)  - последнее задание вперед
	{ 917	,1	,1	, &internal1_m374_RA10},	//(internal1_m374_RA10)  - последнее задание назад
	{ 918	,1	,1	, &internal1_m374_MyFirstEnterFlag},	//(internal1_m374_MyFirstEnterFlag) MyFirstEnterFlag
	{ 919	,8	,1	, &internal1_m358_X00},	//(internal1_m358_X00)  X00 - текущая координата механизма
	{ 920	,8	,1	, &internal1_m358_V00},	//(internal1_m358_V00)  V00 - текущая скорость механизма
	{ 921	,1	,1	, &internal1_m358_Pav0},	//(internal1_m358_Pav0)  - Пер.аварийный выключатель механизма
	{ 922	,1	,1	, &internal1_m358_Zav0},	//(internal1_m358_Zav0)  - Зад.аварийный выключатель механизма
	{ 923	,1	,1	, &internal1_m358_Pv0},	//(internal1_m358_Pv0)  - Пер. выключатель механизма
	{ 924	,1	,1	, &internal1_m358_Zv0},	//(internal1_m358_Zv0)  - Зад. выключатель механизма
	{ 925	,1	,1	, &internal1_m358_RA00},	//(internal1_m358_RA00)  - последнее задание вперед
	{ 926	,1	,1	, &internal1_m358_RA10},	//(internal1_m358_RA10)  - последнее задание назад
	{ 927	,1	,1	, &internal1_m358_MyFirstEnterFlag},	//(internal1_m358_MyFirstEnterFlag) MyFirstEnterFlag
	{ 928	,8	,1	, &internal1_m888_X00},	//(internal1_m888_X00)  X00 - текущая координата механизма
	{ 929	,8	,1	, &internal1_m888_V00},	//(internal1_m888_V00)  V00 - текущая скорость механизма
	{ 930	,1	,1	, &internal1_m888_Pav0},	//(internal1_m888_Pav0)  - Пер.аварийный выключатель механизма
	{ 931	,1	,1	, &internal1_m888_Zav0},	//(internal1_m888_Zav0)  - Зад.аварийный выключатель механизма
	{ 932	,1	,1	, &internal1_m888_Pv0},	//(internal1_m888_Pv0)  - Пер. выключатель механизма
	{ 933	,1	,1	, &internal1_m888_Zv0},	//(internal1_m888_Zv0)  - Зад. выключатель механизма
	{ 934	,1	,1	, &internal1_m888_RA00},	//(internal1_m888_RA00)  - последнее задание вперед
	{ 935	,1	,1	, &internal1_m888_RA10},	//(internal1_m888_RA10)  - последнее задание назад
	{ 936	,1	,1	, &internal1_m888_MyFirstEnterFlag},	//(internal1_m888_MyFirstEnterFlag) MyFirstEnterFlag
	{ 937	,8	,1	, &internal1_m179_C1},	//(internal1_m179_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 938	,8	,1	, &internal1_m179_C2},	//(internal1_m179_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 939	,8	,1	, &internal1_m179_C3},	//(internal1_m179_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 940	,8	,1	, &internal1_m179_C4},	//(internal1_m179_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 941	,8	,1	, &internal1_m179_C5},	//(internal1_m179_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 942	,8	,1	, &internal1_m179_C6},	//(internal1_m179_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 943	,8	,1	, &internal1_m179_N20},	//(internal1_m179_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 944	,8	,1	, &internal1_m179_N00},	//(internal1_m179_N00) N00 - Текущая концентрация нейтронов
	{ 945	,8	,1	, &internal1_m179_R00},	//(internal1_m179_R00) R00 - Текущая реактивность
	{ 946	,8	,1	, &internal1_m179_T00},	//(internal1_m179_T00) T00 - Текущая температура
	{ 947	,1	,1	, &internal1_m179_ImpINI0},	//(internal1_m179_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 948	,1	,1	, &internal1_m179_MyFirstEnterFlag},	//(internal1_m179_MyFirstEnterFlag) MyFirstEnterFlag
	{ 949	,8	,1	, &internal1_m295_X00},	//(internal1_m295_X00) X0 - текущая координата ОРР
	{ 950	,8	,1	, &internal1_m295_Sh00},	//(internal1_m295_Sh00) Sh0 - текущая координата штока ОРР
	{ 951	,8	,1	, &internal1_m295_RV00},	//(internal1_m295_RV00) V0 - текущая скорость ОРР
	{ 952	,8	,1	, &internal1_m295_ShV00},	//(internal1_m295_ShV00) V0 - текущая скорость штока ОРР
	{ 953	,1	,1	, &internal1_m295_Ppv0},	//(internal1_m295_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 954	,1	,1	, &internal1_m295_Pav0},	//(internal1_m295_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 955	,1	,1	, &internal1_m295_Zav0},	//(internal1_m295_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 956	,1	,1	, &internal1_m295_RA00},	//(internal1_m295_RA00) RA00 - последнее задание вперед
	{ 957	,1	,1	, &internal1_m295_RA10},	//(internal1_m295_RA10) RA10 - последнее задание назад
	{ 958	,1	,1	, &internal1_m295_RA30},	//(internal1_m295_RA30)  RA30 - разрешение движения
	{ 959	,1	,1	, &internal1_m295_RA50},	//(internal1_m295_RA50) Ra50 - последнее задание скорости
	{ 960	,1	,1	, &internal1_m295_fls},	//(internal1_m295_fls)  fls - флаг одношагового режима
	{ 961	,1	,1	, &internal1_m295_flp},	//(internal1_m295_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 962	,1	,1	, &internal1_m295_MyFirstEnterFlag},	//(internal1_m295_MyFirstEnterFlag) MyFirstEnterFlag
	{ 963	,8	,1	, &internal1_m127_X00},	//(internal1_m127_X00) X0 - текущая координата ОРР
	{ 964	,8	,1	, &internal1_m127_Sh00},	//(internal1_m127_Sh00) Sh0 - текущая координата штока ОРР
	{ 965	,8	,1	, &internal1_m127_RV00},	//(internal1_m127_RV00) V0 - текущая скорость ОРР
	{ 966	,8	,1	, &internal1_m127_ShV00},	//(internal1_m127_ShV00) V0 - текущая скорость штока ОРР
	{ 967	,1	,1	, &internal1_m127_Ppv0},	//(internal1_m127_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 968	,1	,1	, &internal1_m127_Pav0},	//(internal1_m127_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 969	,1	,1	, &internal1_m127_Zav0},	//(internal1_m127_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 970	,1	,1	, &internal1_m127_RA00},	//(internal1_m127_RA00) RA00 - последнее задание вперед
	{ 971	,1	,1	, &internal1_m127_RA10},	//(internal1_m127_RA10) RA10 - последнее задание назад
	{ 972	,1	,1	, &internal1_m127_RA30},	//(internal1_m127_RA30)  RA30 - разрешение движения
	{ 973	,1	,1	, &internal1_m127_RA50},	//(internal1_m127_RA50) Ra50 - последнее задание скорости
	{ 974	,1	,1	, &internal1_m127_fls},	//(internal1_m127_fls)  fls - флаг одношагового режима
	{ 975	,1	,1	, &internal1_m127_flp},	//(internal1_m127_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 976	,1	,1	, &internal1_m127_MyFirstEnterFlag},	//(internal1_m127_MyFirstEnterFlag) MyFirstEnterFlag
	{ 977	,8	,1	, &internal1_m261_X00},	//(internal1_m261_X00) X0 - текущая координата ОРР
	{ 978	,8	,1	, &internal1_m261_Sh00},	//(internal1_m261_Sh00) Sh0 - текущая координата штока ОРР
	{ 979	,8	,1	, &internal1_m261_RV00},	//(internal1_m261_RV00) V0 - текущая скорость ОРР
	{ 980	,8	,1	, &internal1_m261_ShV00},	//(internal1_m261_ShV00) V0 - текущая скорость штока ОРР
	{ 981	,1	,1	, &internal1_m261_Ppv0},	//(internal1_m261_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 982	,1	,1	, &internal1_m261_Pav0},	//(internal1_m261_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 983	,1	,1	, &internal1_m261_Zav0},	//(internal1_m261_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 984	,1	,1	, &internal1_m261_RA00},	//(internal1_m261_RA00) RA00 - последнее задание вперед
	{ 985	,1	,1	, &internal1_m261_RA10},	//(internal1_m261_RA10) RA10 - последнее задание назад
	{ 986	,1	,1	, &internal1_m261_RA30},	//(internal1_m261_RA30)  RA30 - разрешение движения
	{ 987	,1	,1	, &internal1_m261_RA50},	//(internal1_m261_RA50) Ra50 - последнее задание скорости
	{ 988	,1	,1	, &internal1_m261_fls},	//(internal1_m261_fls)  fls - флаг одношагового режима
	{ 989	,1	,1	, &internal1_m261_flp},	//(internal1_m261_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 990	,1	,1	, &internal1_m261_MyFirstEnterFlag},	//(internal1_m261_MyFirstEnterFlag) MyFirstEnterFlag
	{ 991	,8	,1	, &internal1_m94_X00},	//(internal1_m94_X00) X0 - текущая координата ОРР
	{ 992	,8	,1	, &internal1_m94_Sh00},	//(internal1_m94_Sh00) Sh0 - текущая координата штока ОРР
	{ 993	,8	,1	, &internal1_m94_RV00},	//(internal1_m94_RV00) V0 - текущая скорость ОРР
	{ 994	,8	,1	, &internal1_m94_ShV00},	//(internal1_m94_ShV00) V0 - текущая скорость штока ОРР
	{ 995	,1	,1	, &internal1_m94_Ppv0},	//(internal1_m94_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 996	,1	,1	, &internal1_m94_Pav0},	//(internal1_m94_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 997	,1	,1	, &internal1_m94_Zav0},	//(internal1_m94_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 998	,1	,1	, &internal1_m94_RA00},	//(internal1_m94_RA00) RA00 - последнее задание вперед
	{ 999	,1	,1	, &internal1_m94_RA10},	//(internal1_m94_RA10) RA10 - последнее задание назад
	{ 1000	,1	,1	, &internal1_m94_RA30},	//(internal1_m94_RA30)  RA30 - разрешение движения
	{ 1001	,1	,1	, &internal1_m94_RA50},	//(internal1_m94_RA50) Ra50 - последнее задание скорости
	{ 1002	,1	,1	, &internal1_m94_fls},	//(internal1_m94_fls)  fls - флаг одношагового режима
	{ 1003	,1	,1	, &internal1_m94_flp},	//(internal1_m94_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1004	,1	,1	, &internal1_m94_MyFirstEnterFlag},	//(internal1_m94_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1005	,8	,1	, &internal1_m229_X00},	//(internal1_m229_X00) X0 - текущая координата ОРР
	{ 1006	,8	,1	, &internal1_m229_Sh00},	//(internal1_m229_Sh00) Sh0 - текущая координата штока ОРР
	{ 1007	,8	,1	, &internal1_m229_RV00},	//(internal1_m229_RV00) V0 - текущая скорость ОРР
	{ 1008	,8	,1	, &internal1_m229_ShV00},	//(internal1_m229_ShV00) V0 - текущая скорость штока ОРР
	{ 1009	,1	,1	, &internal1_m229_Ppv0},	//(internal1_m229_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1010	,1	,1	, &internal1_m229_Pav0},	//(internal1_m229_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1011	,1	,1	, &internal1_m229_Zav0},	//(internal1_m229_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1012	,1	,1	, &internal1_m229_RA00},	//(internal1_m229_RA00) RA00 - последнее задание вперед
	{ 1013	,1	,1	, &internal1_m229_RA10},	//(internal1_m229_RA10) RA10 - последнее задание назад
	{ 1014	,1	,1	, &internal1_m229_RA30},	//(internal1_m229_RA30)  RA30 - разрешение движения
	{ 1015	,1	,1	, &internal1_m229_RA50},	//(internal1_m229_RA50) Ra50 - последнее задание скорости
	{ 1016	,1	,1	, &internal1_m229_fls},	//(internal1_m229_fls)  fls - флаг одношагового режима
	{ 1017	,1	,1	, &internal1_m229_flp},	//(internal1_m229_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1018	,1	,1	, &internal1_m229_MyFirstEnterFlag},	//(internal1_m229_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1019	,8	,1	, &internal1_m61_X00},	//(internal1_m61_X00) X0 - текущая координата ОРР
	{ 1020	,8	,1	, &internal1_m61_Sh00},	//(internal1_m61_Sh00) Sh0 - текущая координата штока ОРР
	{ 1021	,8	,1	, &internal1_m61_RV00},	//(internal1_m61_RV00) V0 - текущая скорость ОРР
	{ 1022	,8	,1	, &internal1_m61_ShV00},	//(internal1_m61_ShV00) V0 - текущая скорость штока ОРР
	{ 1023	,1	,1	, &internal1_m61_Ppv0},	//(internal1_m61_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 1024	,1	,1	, &internal1_m61_Pav0},	//(internal1_m61_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 1025	,1	,1	, &internal1_m61_Zav0},	//(internal1_m61_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 1026	,1	,1	, &internal1_m61_RA00},	//(internal1_m61_RA00) RA00 - последнее задание вперед
	{ 1027	,1	,1	, &internal1_m61_RA10},	//(internal1_m61_RA10) RA10 - последнее задание назад
	{ 1028	,1	,1	, &internal1_m61_RA30},	//(internal1_m61_RA30)  RA30 - разрешение движения
	{ 1029	,1	,1	, &internal1_m61_RA50},	//(internal1_m61_RA50) Ra50 - последнее задание скорости
	{ 1030	,1	,1	, &internal1_m61_fls},	//(internal1_m61_fls)  fls - флаг одношагового режима
	{ 1031	,1	,1	, &internal1_m61_flp},	//(internal1_m61_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 1032	,1	,1	, &internal1_m61_MyFirstEnterFlag},	//(internal1_m61_MyFirstEnterFlag) MyFirstEnterFlag
	{ 1033	,8	,1	, &internal1_m14_C1},	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 1034	,8	,1	, &internal1_m14_C2},	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 1035	,8	,1	, &internal1_m14_C3},	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 1036	,8	,1	, &internal1_m14_C4},	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 1037	,8	,1	, &internal1_m14_C5},	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 1038	,8	,1	, &internal1_m14_C6},	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 1039	,8	,1	, &internal1_m14_N20},	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 1040	,8	,1	, &internal1_m14_N00},	//(internal1_m14_N00) N00 - Текущая концентрация нейтронов
	{ 1041	,8	,1	, &internal1_m14_R00},	//(internal1_m14_R00) R00 - Текущая реактивность
	{ 1042	,8	,1	, &internal1_m14_T00},	//(internal1_m14_T00) T00 - Текущая температура
	{ 1043	,1	,1	, &internal1_m14_ImpINI0},	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 1044	,1	,1	, &internal1_m14_MyFirstEnterFlag},	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="scm.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{283,"fEM_R0UL01RIM\0"}, 
{284,"fEM_R0UN02RIM\0"}, 
{285,"fEM_A1UR01RIM\0"}, 
{286,"fEM_A1UR00RIM\0"}, 
{287,"fEM_A3UR00RIM\0"}, 
{288,"fEM_A3UR01RIM\0"}, 
{289,"fEM_R0UT01RIM\0"}, 
{290,"fEM_R0UT02RIM\0"}, 
{291,"fEM_R0UT04RIM\0"}, 
{292,"fEM_R0UT03RIM\0"}, 
{293,"fEM_R0UT05RIM\0"}, 
{294,"fEM_R0UT06RIM\0"}, 
{295,"fEM_A1UC02RDU\0"}, 
{296,"fEM_A1UC04RIM\0"}, 
{297,"fEM_A1UC05RIM\0"}, 
{298,"fEM_A1UC06RIM\0"}, 
{299,"fEM_A2UC06RIM\0"}, 
{300,"fEM_A2UC05RIM\0"}, 
{301,"fEM_A2UC04RIM\0"}, 
{302,"fEM_A2UC02RDU\0"}, 
{303,"fEM_A3UC06RIM\0"}, 
{304,"fEM_A3UC05RIM\0"}, 
{305,"fEM_A3UC04RIM\0"}, 
{306,"fEM_A3UC02RDU\0"}, 
{307,"fEM_R4UV80RDU\0"}, 
{308,"fEM_R4UC10RIM\0"}, 
{309,"fEM_R4UC20RIM\0"}, 
{310,"fEM_B8UC21RIM\0"}, 
{311,"fEM_B8UC20RIM\0"}, 
{312,"fEM_B8UC11RIM\0"}, 
{313,"fEM_B8UC10RIM\0"}, 
{314,"fEM_B8UV80RDU\0"}, 
{315,"fEM_A8UV80RDU\0"}, 
{316,"fEM_A8UC10RIM\0"}, 
{317,"fEM_A8UC11RIM\0"}, 
{318,"fEM_A8UC20RIM\0"}, 
{319,"fEM_A8UC21RIM\0"}, 
{320,"fEM_A6UC10RIM\0"}, 
{321,"fEM_R1UC10RIM\0"}, 
{322,"fEM_A5UC10RIM\0"}, 
{323,"fEM_A0UN01RIM\0"}, 
{324,"fEM_R4UC22RIM\0"}, 
{325,"fEM_A1UG01RDU\0"}, 
{326,"fEM_A2UG01RDU\0"}, 
{327,"fEM_A3UG01RDU\0"}, 
{328,"fEM_R7UC10RIM\0"}, 
{329,"fEM_R7UC19RIM\0"}, 
{330,"fEM_R7UI02RIM\0"}, 
{331,"fEM_R7UL01RIM\0"}, 
{332,"fEM_A2UR00RIM\0"}, 
{333,"fEM_A2UR01RIM\0"}, 
{334,"fEM_A0UN02RIM\0"}, 
{335,"fEM_R0UR30RIM\0"}, 
{336,"fEM_R0UR01RIM\0"}, 
{337,"fEM_R0UT02RDU\0"}, 
{338,"fEM_R0UT01RDU\0"}, 
{339,"fEM_A1UC03RDU\0"}, 
{340,"fEM_A2UP03RDU\0"}, 
{341,"fEM_A2UP04RDU\0"}, 
{342,"fEM_A2UC03RDU\0"}, 
{343,"fEM_A3UP03RDU\0"}, 
{344,"fEM_A3UP04RDU\0"}, 
{345,"fEM_A3UC03RDU\0"}, 
{346,"fEM_R7UI74RIM\0"}, 
{347,"fEM_A8UC03RDU\0"}, 
{348,"fEM_R0UV87RDU\0"}, 
{349,"fEM_R0UV81RDU\0"}, 
{350,"fEM_R0UV82RDU\0"}, 
{351,"fEM_R0UV83RDU\0"}, 
{352,"fEM_R0UV84RDU\0"}, 
{353,"fEM_R0UV85RDU\0"}, 
{354,"fEM_R0UV86RDU\0"}, 
{355,"fEM_A8UC08RDU\0"}, 
{356,"fEM_B8UC08RDU\0"}, 
{357,"fEM_R4UC08RDU\0"}, 
{358,"fEM_R0UH01RSS\0"}, 
{359,"fEM_A0UX00RSS\0"}, 
{360,"fEM_R7UX01RSS\0"}, 
{361,"fEM_R7UX02RSS\0"}, 
{362,"fEM_R7UX04RSS\0"}, 
{363,"fEM_R7UX05RSS\0"}, 
{364,"fEM_R7UX06RSS\0"}, 
{365,"fEM_R7UX07RSS\0"}, 
{366,"fEM_R7UX08RSS\0"}, 
{367,"fEM_R7UX09RSS\0"}, 
{368,"fEM_R7UY01RSS\0"}, 
{369,"fEM_R7UY02RSS\0"}, 
{370,"fEM_R7UY04RSS\0"}, 
{371,"fEM_R7UY05RSS\0"}, 
{372,"fEM_R7UY06RSS\0"}, 
{373,"fEM_R7UY07RSS\0"}, 
{374,"fEM_R7UY08RSS\0"}, 
{375,"fEM_R7UY09RSS\0"}, 
{376,"fEM_R7UX10RSS\0"}, 
{377,"fEM_R7UX11RSS\0"}, 
{378,"fEM_R7UX12RSS\0"}, 
{379,"fEM_R7UY10RSS\0"}, 
{380,"fEM_R7UY11RSS\0"}, 
{381,"fEM_R7UY12RSS\0"}, 
{382,"fEM_A0UX01RSS\0"}, 
{383,"fEM_A0UX02RSS\0"}, 
{384,"fEM_A0UX03RSS\0"}, 
{385,"fEM_A0UX04RSS\0"}, 
{386,"fEM_A0UX05RSS\0"}, 
{387,"fEM_A0UX06RSS\0"}, 
{388,"fEM_A0UX07RSS\0"}, 
{389,"fEM_A0UX08RSS\0"}, 
{390,"fEM_A0UX09RSS\0"}, 
{391,"fEM_A0UX10RSS\0"}, 
{392,"fEM_A0UX11RSS\0"}, 
{393,"fEM_A0UX12RSS\0"}, 
{394,"fEM_B0UX01RSS\0"}, 
{395,"fEM_B0UX02RSS\0"}, 
{396,"fEM_B0UX03RSS\0"}, 
{397,"fEM_B0UX04RSS\0"}, 
{398,"fEM_B0UX05RSS\0"}, 
{399,"fEM_B0UX06RSS\0"}, 
{400,"fEM_B0UX07RSS\0"}, 
{401,"fEM_B0UX08RSS\0"}, 
{402,"fEM_B0UX09RSS\0"}, 
{403,"fEM_B0UX10RSS\0"}, 
{404,"fEM_B0UX11RSS\0"}, 
{405,"fEM_B0UX12RSS\0"}, 
{406,"fEM_R0UH02RSS\0"}, 
{407,"fEM_R0UH03RSS\0"}, 
{408,"fEM_R4US80RDU\0"}, 
{409,"fEM_R7UI71RIM\0"}, 
{410,"fEM_R7UI72RIM\0"}, 
{411,"fEM_R7UI73RIM\0"}, 
{412,"fEM_A1UP01RIM\0"}, 
{413,"fEM_A2UP01RIM\0"}, 
{414,"fEM_A0UP02RIM\0"}, 
{415,"fEM_A3UP01RIM\0"}, 
{416,"fEM_A1UP82RIM\0"}, 
{417,"fEM_A3UP02RDU\0"}, 
{418,"fEM_A1UV02RIM\0"}, 
{419,"fEM_A3UV02RIM\0"}, 
{420,"fEM_A2UV02RIM\0"}, 
{421,"fEM_B8US80RDU\0"}, 
{422,"fEM_A8US80RDU\0"}, 
{423,"fEM_A6US80RDU\0"}, 
{424,"fEM_A1US07RDU\0"}, 
{425,"fEM_A2US07RDU\0"}, 
{426,"fEM_A3US07RDU\0"}, 
{427,"fEM_R7UI75RIM\0"}, 
{428,"fEM_R0UH21RSS\0"}, 
{429,"fEM_R0UH22RSS\0"}, 
{430,"fEM_R0UH23RSS\0"}, 
{431,"fEM_R0UH05RSS\0"}, 
{432,"fEM_A4UL10RIM\0"}, 
{433,"fEM_A9UL10RIM\0"}, 
{434,"fEM_R3UL10RIM\0"}, 
{435,"fEM_R5UL10RIM\0"}, 
{436,"fEM_R6UL10RIM\0"}, 
{437,"lEM_C1AD31LRP\0"}, 
{438,"lEM_R0IE01LRP\0"}, 
{439,"lEM_R0IE02LRP\0"}, 
{440,"fEM_A2UP02RIM\0"}, 
{441,"fEM_A2UP03RIM\0"}, 
{442,"fEM_A0UP01RIM\0"}, 
{443,"fEM_A3UP02RIM\0"}, 
{444,"fEM_A4UP01RIM\0"}, 
{445,"fEM_A4UP02RIM\0"}, 
{446,"fEM_R7UI76RIM\0"}, 
{447,"fEM_R7UI77RIM\0"}, 
{448,"iEM_TERBB1\0"}, 
{449,"fEM_A1MC02RC1\0"}, 
{450,"fEM_A1MV02RC1\0"}, 
{451,"iEM_TERBB2\0"}, 
{452,"fEM_B1MC02RC1\0"}, 
{453,"fEM_B1MV02RC1\0"}, 
{454,"iEM_TERRB2\0"}, 
{455,"fEM_B2MC02RC1\0"}, 
{456,"fEM_B2MV02RC1\0"}, 
{457,"iEM_TERRB1\0"}, 
{458,"fEM_A2MC02RC1\0"}, 
{459,"fEM_A2MV02RC1\0"}, 
{460,"iEM_TERIS2\0"}, 
{461,"fEM_B3MC02RC1\0"}, 
{462,"fEM_B3MV02RC1\0"}, 
{463,"iEM_TERIS1\0"}, 
{464,"fEM_A3MC02RC1\0"}, 
{465,"fEM_A3MV02RC1\0"}, 
{466,"iEM_TERA1IE04LDU\0"}, 
{467,"iEM_TERA1IE03LDU\0"}, 
{468,"fEM_A1MC01RC1\0"}, 
{469,"iEM_TERB1IE03LDU\0"}, 
{470,"iEM_TERB1IE04LDU\0"}, 
{471,"fEM_B1MC01RC1\0"}, 
{472,"fEM_B1MV01RC1\0"}, 
{473,"fEM_B2MC01RC1\0"}, 
{474,"fEM_B2MV01RC1\0"}, 
{475,"fEM_A3MC01RC1\0"}, 
{476,"fEM_A3MV01RC1\0"}, 
{477,"fEM_B3MC01RC1\0"}, 
{478,"fEM_B3MV01RC1\0"}, 
{479,"iEM_TERA2SS21LIM\0"}, 
{480,"iEM_TERA2SS12LIM\0"}, 
{481,"iEM_TERR6SS21LIM\0"}, 
{482,"iEM_TERA2VP82LIM\0"}, 
{483,"iEM_TERA2SS11LIM\0"}, 
{484,"iEM_TERB3SS21LIM\0"}, 
{485,"iEM_TERA0MT01RIM\0"}, 
{486,"iEM_TERB0MT01RIM\0"}, 
{487,"iEM_TERA2SP01RIM\0"}, 
{488,"iEM_TERB2SP01RIM\0"}, 
{489,"iEM_TERB3SP02RIM\0"}, 
{490,"iEM_TERA3SC01RIM\0"}, 
{491,"iEM_TERA3VP81LIM\0"}, 
{492,"iEM_TERA2SC01RIM\0"}, 
{493,"iEM_TERA2SS33LIM\0"}, 
{494,"iEM_TERA3SS21LIM\0"}, 
{495,"iEM_TERA3SS33LIM\0"}, 
{496,"iEM_TERA3SS31LIM\0"}, 
{497,"iEM_TERB3SS31LIM\0"}, 
{498,"iEM_TERB3SS33LIM\0"}, 
{499,"iEM_TERB3SC01RIM\0"}, 
{500,"iEM_TERA3SS11LIM\0"}, 
{501,"iEM_TERB3SS11LIM\0"}, 
{502,"iEM_TERR6IS64LIM\0"}, 
{503,"iEM_TERB3SS22LIM\0"}, 
{504,"iEM_TERA3SS22LIM\0"}, 
{505,"iEM_TERA3SP02RIM\0"}, 
{506,"iEM_TERR6IS62LIM\0"}, 
{507,"iEM_TERR6IS66LIM\0"}, 
{508,"iEM_TERR6IS67LIM\0"}, 
{509,"iEM_TERA0VP81LIM\0"}, 
{510,"iEM_TERB0VP81LIM\0"}, 
{511,"iEM_TERR0VP81LIM\0"}, 
{512,"iEM_TERR6IS68LIM\0"}, 
{513,"iEM_TERR7SI74RIM\0"}, 
{514,"iEM_TERA5SS21LIM\0"}, 
{515,"iEM_TERB5SS11LIM\0"}, 
{516,"iEM_TERA5SS11LIM\0"}, 
{517,"iEM_TERA9SS11LIM\0"}, 
{518,"iEM_TERB2SS11LIM\0"}, 
{519,"iEM_TERB2SS12LIM\0"}, 
{520,"iEM_TERB2SS21LIM\0"}, 
{521,"iEM_TERR3SS11LIM\0"}, 
{522,"iEM_TERB2SC01RIM\0"}, 
{523,"iEM_TERR3SS21LIM\0"}, 
{524,"iEM_TERR5SS11LIM\0"}, 
{525,"iEM_TERA4SS11LIM\0"}, 
{526,"iEM_TERR1SS11LIM\0"}, 
{527,"iEM_TERR1SS21LIM\0"}, 
{528,"iEM_TERR2SS11LIM\0"}, 
{529,"iEM_TERR2SS21LIM\0"}, 
{530,"iEM_TERA4VP82LIM\0"}, 
{531,"iEM_TERB4SS21LIM\0"}, 
{532,"iEM_TERR5SS21LIM\0"}, 
{533,"iEM_TERB6SS21LIM\0"}, 
{534,"iEM_TERB4SS11LIM\0"}, 
{535,"iEM_TERA4SS21LIM\0"}, 
{536,"iEM_TERA6MS11LIM\0"}, 
{537,"iEM_TERA6SS21LIM\0"}, 
{538,"iEM_TERB6SS11LIM\0"}, 
{539,"iEM_TERR4SS11LIM\0"}, 
{540,"iEM_TERR4MS21LIM\0"}, 
{541,"iEM_TERR4SS12LIM\0"}, 
{542,"iEM_TERR4SS22LIM\0"}, 
{543,"iEM_TERR8SS11LIM\0"}, 
{544,"iEM_TERB8SC01RIM\0"}, 
{545,"iEM_TERA8SC01RIM\0"}, 
{546,"iEM_TERB8SS12LIM\0"}, 
{547,"iEM_TERA8SS12LIM\0"}, 
{548,"iEM_TERB8SS22LIM\0"}, 
{549,"iEM_TERA8SS22LIM\0"}, 
{550,"iEM_TERA9SS21LIM\0"}, 
{551,"iEM_TERB9SS21LIM\0"}, 
{552,"iEM_TERB9SS11LIM\0"}, 
{553,"iEM_TERB5SS21LIM\0"}, 
{554,"iEM_TERA1SS21LIM\0"}, 
{555,"iEM_TERA1SS11LIM\0"}, 
{556,"iEM_TERA1SC01RIM\0"}, 
{557,"iEM_TERA1SS12LIM\0"}, 
{558,"iEM_TERB1SS21LIM\0"}, 
{559,"iEM_TERB1SS11LIM\0"}, 
{560,"iEM_TERB1MC01RIM\0"}, 
{561,"iEM_TERB1SS12LIM\0"}, 
{562,"iEM_TERTLG\0"}, 
{563,"fEM_R4MC01RC1\0"}, 
{564,"fEM_R4MV01RC1\0"}, 
{565,"iEM_TERMAZ2\0"}, 
{566,"fEM_B8MV01RC1\0"}, 
{567,"iEM_TERDS2\0"}, 
{568,"fEM_A8MC01RC1\0"}, 
{569,"fEM_A8MV01RC1\0"}, 
{570,"iEM_TERBZ1\0"}, 
{571,"fEM_A6MC01RC1\0"}, 
{572,"fEM_A6MV01RC1\0"}, 
{573,"iEM_TERBZ2\0"}, 
{574,"fEM_B6MC01RC1\0"}, 
{575,"fEM_B6MV01RC1\0"}, 
{576,"lEM_R3AD10LC1\0"}, 
{577,"lEM_R3AD20LC1\0"}, 
{578,"lEM_R6AD10LC1\0"}, 
{579,"lEM_R5AD10LC1\0"}, 
{580,"lEM_R5AD20LC1\0"}, 
{581,"iEM_TERMDZ2\0"}, 
{582,"fEM_R2MC01RC1\0"}, 
{583,"fEM_R2MV01RC1\0"}, 
{584,"iEM_TERMDZ1\0"}, 
{585,"fEM_R1MC01RC1\0"}, 
{586,"fEM_R1MV01RC1\0"}, 
{587,"iEM_TERNL1\0"}, 
{588,"fEM_A5MC01RC1\0"}, 
{589,"fEM_A5MV01RC1\0"}, 
{590,"iEM_TERNL2\0"}, 
{591,"fEM_B5MC01RC1\0"}, 
{592,"fEM_B5MV01RC1\0"}, 
{593,"lEM_R8AD10LC1\0"}, 
{594,"fEM_A1UC08RIM\0"}, 
{595,"fEM_A2UC08RIM\0"}, 
{596,"fEM_A3UC08RIM\0"}, 
{597,"iEM_TERB2SS33LIM\0"}, 
{598,"iEM_TERA1VP81LIM\0"}, 
{599,"iEM_TERB1VP81LIM\0"}, 
{600,"fEM_A0UT03RSP\0"}, 
{601,"fEM_A0UR01RSP\0"}, 
{602,"fEM_A0UR02RSP\0"}, 
{603,"fEM_B0UT03RSP\0"}, 
{604,"fEM_A1MC01RSP\0"}, 
{605,"fEM_A1MC02RSP\0"}, 
{606,"fEM_B1MC01RSP\0"}, 
{607,"fEM_B1MC02RSP\0"}, 
{608,"fEM_A2MC01RC1\0"}, 
{609,"fEM_A2MV01RC1\0"}, 
{610,"fEM_A2MC01RSP\0"}, 
{611,"fEM_A2MC02RSP\0"}, 
{612,"fEM_B2MC01RSP\0"}, 
{613,"fEM_B2MC02RSP\0"}, 
{614,"fEM_A3MC01RSP\0"}, 
{615,"fEM_A3MC02RSP\0"}, 
{616,"fEM_B3MC01RSP\0"}, 
{617,"fEM_B3MC02RSP\0"}, 
{618,"fEM_B8MC01RSP\0"}, 
{619,"fEM_A8MC01RSP\0"}, 
{620,"fEM_A6MC01RSP\0"}, 
{621,"fEM_B6MC01RSP\0"}, 
{622,"fEM_R3UC01RSP\0"}, 
{623,"fEM_R5UC01RSP\0"}, 
{624,"fEM_R6UC01RSP\0"}, 
{625,"fEM_R2MC01RSP\0"}, 
{626,"fEM_R1MC01RSP\0"}, 
{627,"fEM_A5MC01RSP\0"}, 
{628,"fEM_B5MC01RSP\0"}, 
{629,"fEM_A9MC01RSP\0"}, 
{630,"fEM_B9MC01RSP\0"}, 
{631,"fEM_A4MC01RSP\0"}, 
{632,"fEM_B4MC01RSP\0"}, 
{633,"fEM_R4MC01RSP\0"}, 
{634,"fEM_A1MV01RC1\0"}, 
{635,"iEM_TERB7MS31LIM\0"}, 
{636,"iEM_TERA7MS31LIM\0"}, 
{637,"fEM_R7UY00RSS\0"}, 
{638,"iEM_TERA6VS12LIM\0"}, 
{639,"iEM_TERA6VS22LIM\0"}, 
{640,"iEM_TERB6VS12LIM\0"}, 
{641,"iEM_TERB6VS22LIM\0"}, 
{642,"iEM_TERA5VS22LIM\0"}, 
{643,"iEM_TERA5VS12LIM\0"}, 
{644,"iEM_TERB5VS12LIM\0"}, 
{645,"iEM_TERB5VS22LIM\0"}, 
{646,"iEM_TERR1VS12LIM\0"}, 
{647,"iEM_TERR1VS22LIM\0"}, 
{648,"iEM_TERR2VS12LIM\0"}, 
{649,"iEM_TERR2VS22LIM\0"}, 
{650,"iEM_TERR4VS12LDU\0"}, 
{651,"iEM_TERR4VS22LDU\0"}, 
{652,"fEM_A0UX13RSS\0"}, 
{653,"fEM_A0UX14RSS\0"}, 
{654,"fEM_A0UX15RSS\0"}, 
{655,"fEM_R7UX13RSS\0"}, 
{656,"fEM_R7UX14RSS\0"}, 
{657,"fEM_R7UX15RSS\0"}, 
{658,"fEM_R7UY13RSS\0"}, 
{659,"fEM_R7UY14RSS\0"}, 
{660,"fEM_R7UY15RSS\0"}, 
{661,"fEM_R7UX16RSS\0"}, 
{662,"fEM_B8MC01RC1\0"}, 
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
	{&fEM_R7UX01RSS,8,152},	//( - , SCM) X-координата камеры R7IN11
	{&fEM_R7UX02RSS,8,154},	//( - , SCM) X-координата камеры R7IN12 (см)
	{&fEM_R7UX04RSS,8,156},	//( - , SCM) X-координата камеры R7IN21 (см)
	{&fEM_R7UX05RSS,8,158},	//( - , SCM) X-координата камеры R7IN22 (см)
	{&fEM_R7UX06RSS,8,160},	//( - , SCM) X-координата камеры R7IN23 (см)
	{&fEM_R7UX07RSS,8,162},	//( - , SCM) X-координата камеры R7IN31 (см)
	{&fEM_R7UX08RSS,8,164},	//( - , SCM) X-координата камеры R7IN32 (см)
	{&fEM_R7UX09RSS,8,166},	//( - , SCM) X-координата камеры R7IN33 (см)
	{&fEM_R7UY01RSS,8,168},	//( - , SCM) Y-координата камеры R7IN11
	{&fEM_R7UY02RSS,8,170},	//( - , SCM) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY04RSS,8,172},	//( - , SCM) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY05RSS,8,174},	//( - , SCM) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY06RSS,8,176},	//( - , SCM) Y-координата камеры R7IN23 (см)
	{&fEM_R7UY07RSS,8,178},	//( - , SCM) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY08RSS,8,180},	//( - , SCM) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY09RSS,8,182},	//( - , SCM) Y-координата камеры R7IN33 (см)
	{&fEM_R7UX10RSS,8,184},	//( - , SCM) X-координата камеры R7IN41
	{&fEM_R7UX11RSS,8,186},	//( - , SCM) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,188},	//( - , SCM) X-координата камеры R7IN43
	{&fEM_R7UY10RSS,8,190},	//( - , SCM) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,192},	//( - , SCM) Y-координата камеры R7IN42
	{&fEM_R7UY12RSS,8,194},	//( - , SCM) Y-координата камеры R7IN43
	{&fEM_A0UX01RSS,8,196},	//( - , SCM) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX02RSS,8,198},	//( - , SCM) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX03RSS,8,200},	//( - , SCM) Первый коэффициент калибровки камеры 3
	{&fEM_A0UX04RSS,8,202},	//( - , SCM) Первый коэффициент калибровки камеры4
	{&fEM_A0UX05RSS,8,204},	//( - , SCM) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX06RSS,8,206},	//( - , SCM) Первый коэффициент калибровки камеры 6
	{&fEM_A0UX07RSS,8,208},	//( - , SCM) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX08RSS,8,210},	//( - , SCM) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX09RSS,8,212},	//( - , SCM) Первый коэффициент калибровки камеры 9
	{&fEM_A0UX10RSS,8,214},	//( - , SCM) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX11RSS,8,216},	//( - , SCM) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX12RSS,8,218},	//( - , SCM) Первый коэффициент калибровки камеры 12
	{&fEM_B0UX01RSS,8,220},	//( - , SCM) Второй коэффициент калибровки камеры 1
	{&fEM_B0UX02RSS,8,222},	//( - , SCM) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX06RSS,8,224},	//( - , SCM) Второй коэффициент калибровки камеры 6
	{&fEM_B0UX07RSS,8,226},	//( - , SCM) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX08RSS,8,228},	//( - , SCM) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX09RSS,8,230},	//( - , SCM) Второй коэффициент калибровки камеры 9
	{&fEM_B0UX10RSS,8,232},	//( - , SCM) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX11RSS,8,234},	//( - , SCM) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX12RSS,8,236},	//( - , SCM) Второй коэффициент калибровки камеры 12
	{&fEM_R4US80RDU,8,238},	//( - , SCM) Тормозной путь тележки (мм)
	{&fEM_R7UI71RIM,8,240},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{&fEM_R7UI72RIM,8,242},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{&fEM_R7UI73RIM,8,244},	//( - , SCM) Уровень мощности срабатывания АС II УР  ватт
	{&fEM_A1UP01RIM,8,246},	//( - , SCM) Текущее давление на сброс ББ (МПа)
	{&fEM_A2UP01RIM,8,248},	//( - , SCM) Текущее давление на сброс РБ
	{&fEM_A0UP02RIM,8,250},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP01RIM,8,252},	//( - , SCM) Текущее давление на СПУСК ИС
	{&fEM_A1UP82RIM,8,254},	//( - , SCM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{&fEM_A3UP02RDU,8,256},	//( - , SCM) Текущее давление ВЫСТРЕЛ ИС
	{&fEM_A1UV02RIM,8,258},	//( - , SCM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{&fEM_A3UV02RIM,8,260},	//( - , SCM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{&fEM_A2UV02RIM,8,262},	//( - , SCM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{&fEM_B8US80RDU,8,264},	//( - , SCM) Тормозной путь АЗ2 (мм)
	{&fEM_A8US80RDU,8,266},	//( - , SCM) Тормозной путь ДС2 (мм)
	{&fEM_A6US80RDU,8,268},	//( - , SCM) Тормозной путь БЗ (мм)
	{&fEM_A1US07RDU,8,270},	//( - , SCM) Постоянная времени масляного демпфера ББ
	{&fEM_A2US07RDU,8,272},	//( - , SCM) Постоянная времени масляного демпфера РБ
	{&fEM_A3US07RDU,8,274},	//( - , SCM) Постоянная времени масляного демпфера ИС
	{&fEM_R7UI75RIM,8,276},	//( - , SCM) Множитель к уровню радиации
	{&fEM_R0UH05RSS,8,278},	//( - , SCM) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_A4UL10RIM,8,280},	//( - , SCM) Время полного перемещения НИ сек
	{&fEM_A9UL10RIM,8,282},	//( - , SCM) Время полного перемещения НИ ДС1/ДС2 сек
	{&fEM_R3UL10RIM,8,284},	//( - , SCM) Время полного хода гомогенных дверей (сек)
	{&fEM_R5UL10RIM,8,286},	//( - , SCM) Время полного хода ворот отстойной зоны (дес. мс)
	{&fEM_R6UL10RIM,8,288},	//( - , SCM) Время полного хода кран-балки сек
	{&fEM_A2UP02RIM,8,290},	//( - , SCM) Текущее давление на подъём РБ
	{&fEM_A2UP03RIM,8,292},	//( - , SCM) Нижняя граница давления на ПОДЪЁМ РБ
	{&fEM_A0UP01RIM,8,294},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP02RIM,8,296},	//( - , SCM) Нижняя граница  давления на СПУСК ИС
	{&fEM_A4UP01RIM,8,298},	//( - , SCM) Текущее давление на подъём НИ
	{&fEM_A4UP02RIM,8,300},	//( - , SCM) Нижняя граница давления на подъём НИ
	{&fEM_R7UI76RIM,8,302},	//( - , SCM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{&fEM_R7UI77RIM,8,304},	//( - , SCM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{&iEM_TERBB1,3,306},	//( - , SCM) Неисправности  ББ1
	{&fEM_A1MC02RC1,8,307},	//( - , SCM) Заданная координата штока ББ1 от ИС
	{&fEM_A1MV02RC1,8,309},	//( - , SCM) Заданная скорость движения  штока ББ1 от ИС
	{&iEM_TERBB2,3,311},	//( - , SCM) Неисправности  ББ2
	{&fEM_B1MC02RC1,8,312},	//( - , SCM) Заданная координата штока ББ2 от ИС
	{&fEM_B1MV02RC1,8,314},	//( - , SCM) Заданная скорость движения штока ББ2 от ИС
	{&iEM_TERRB2,3,316},	//( - , SCM) Неисправности  РБ2
	{&fEM_B2MC02RC1,8,317},	//( - , SCM) Заданная координата штока РБ2 от ИС
	{&fEM_B2MV02RC1,8,319},	//( - , SCM) Заданная скорость движения штока РБ2 от ИС
	{&iEM_TERRB1,3,321},	//( - , SCM) Неисправности  РБ1
	{&fEM_A2MC02RC1,8,322},	//( - , SCM) Заданная координата штока РБ1 от ИС
	{&fEM_A2MV02RC1,8,324},	//( - , SCM) Заданная скорость движения штока РБ1 от ИС
	{&iEM_TERIS2,3,326},	//( - , SCM) Неисправности  ИС2
	{&fEM_B3MC02RC1,8,327},	//( - , SCM) Заданная координата штока ИС2 от ИС
	{&fEM_B3MV02RC1,8,329},	//( - , SCM) Заданная скорость движения штока ИС2 от ИС
	{&iEM_TERIS1,3,331},	//( - , SCM) Неисправности  ИС1
	{&fEM_A3MC02RC1,8,332},	//( - , SCM) Заданная координата штока ИС1 от ИС
	{&fEM_A3MV02RC1,8,334},	//( - , SCM) Заданная скорость движения штока ИС1 от ИС
	{&iEM_TERA1IE04LDU,3,336},	//( - , SCM) Искажение Движение ББ1 назад (от БУШД)
	{&iEM_TERA1IE03LDU,3,337},	//( - , SCM) Искажение Движение ББ1 вперёд (от БУШД)
	{&fEM_A1MC01RC1,8,338},	//( - , SCM) Заданная координата  ББ1 от ИС
	{&iEM_TERB1IE03LDU,3,340},	//( - , SCM) Искажение Движение ББ2 вперёд (от БУШД)
	{&iEM_TERB1IE04LDU,3,341},	//( - , SCM) Искажение Движение ББ2 назад (от БУШД)
	{&fEM_B1MC01RC1,8,342},	//( - , SCM) Заданная координата ББ2 от ИС
	{&fEM_B1MV01RC1,8,344},	//( - , SCM) Заданная скорость движения ББ2 от ИС
	{&fEM_B2MC01RC1,8,346},	//( - , SCM) Заданная координата РБ2 от ИС
	{&fEM_B2MV01RC1,8,348},	//( - , SCM) Заданная скорость движения  РБ2 от ИС
	{&fEM_A3MC01RC1,8,350},	//( - , SCM) Заданная координата ИС1 от ИС
	{&fEM_A3MV01RC1,8,352},	//( - , SCM) Заданная скорость движения ИС1 от ИС
	{&fEM_B3MC01RC1,8,354},	//( - , SCM) Заданная координата ИС2 от ИС
	{&fEM_B3MV01RC1,8,356},	//( - , SCM) Заданная скорость движения ИС2 от ИС
	{&iEM_TERA2SS21LIM,3,358},	//( - , SCM) Искажение: Приход на НУ РБ1
	{&iEM_TERA2SS12LIM,3,359},	//( - , SCM) Искажение: Магнит РБ1 зацеплен
	{&iEM_TERR6SS21LIM,3,360},	//( - , SCM) Искажение: Кран-балка в нерабочем положении
	{&iEM_TERA2VP82LIM,3,361},	//( - , SCM) Искажение: Текущее давление на подъём РБ  в норме
	{&iEM_TERA2SS11LIM,3,362},	//( - , SCM) Искажение: Приход на ВУ РБ1
	{&iEM_TERB3SS21LIM,3,363},	//( - , SCM) Искажение: Приход на НУ ИС2
	{&iEM_TERA0MT01RIM,3,364},	//( - , SCM) Искажение: Текущая температура AЗ1
	{&iEM_TERB0MT01RIM,3,365},	//( - , SCM) Искажение: Текущая температура AЗ2
	{&iEM_TERA2SP01RIM,3,366},	//( - , SCM) Искажение: Текущее давление СБРОС РБ1
	{&iEM_TERB2SP01RIM,3,367},	//( - , SCM) Искажение: Текущее давление СБРОС РБ2
	{&iEM_TERB3SP02RIM,3,368},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{&iEM_TERA3SC01RIM,3,369},	//( - , SCM) Искажение: Координата штока ИС1
	{&iEM_TERA3VP81LIM,3,370},	//( - , SCM) Искажение: Текущее давление СПУСК ИС  в норме
	{&iEM_TERA2SC01RIM,3,371},	//( - , SCM) Искажение: Координата штока РБ1
	{&iEM_TERA2SS33LIM,3,372},	//( - , SCM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{&iEM_TERA3SS21LIM,3,373},	//( - , SCM) Искажение: Приход на НУ ИС1
	{&iEM_TERA3SS33LIM,3,374},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{&iEM_TERA3SS31LIM,3,375},	//( - , SCM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{&iEM_TERB3SS31LIM,3,376},	//( - , SCM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{&iEM_TERB3SS33LIM,3,377},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{&iEM_TERB3SC01RIM,3,378},	//( - , SCM) Искажение: Координата штока ИС2
	{&iEM_TERA3SS11LIM,3,379},	//( - , SCM) Искажение: Приход на ВУ ИС1
	{&iEM_TERB3SS11LIM,3,380},	//( - , SCM) Искажение: Приход на ВУ ИС2
	{&iEM_TERR6IS64LIM,3,381},	//( - , SCM) Искажение: Исправность ВИП ССДИ-35
	{&iEM_TERB3SS22LIM,3,382},	//( - , SCM) Искажение: Приход на НУП ИС2
	{&iEM_TERA3SS22LIM,3,383},	//( - , SCM) Искажение: Приход на НУП ИС1
	{&iEM_TERA3SP02RIM,3,384},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{&iEM_TERR6IS62LIM,3,385},	//( - , SCM) Искажение Исправность ВИП ССДИ-39
	{&iEM_TERR6IS66LIM,3,386},	//( - , SCM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&iEM_TERR6IS67LIM,3,387},	//( - , SCM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&iEM_TERA0VP81LIM,3,388},	//( - , SCM) Искажение: Давление  АЗ1  в норме
	{&iEM_TERB0VP81LIM,3,389},	//( - , SCM) Искажение: Давление  АЗ2 в норме
	{&iEM_TERR0VP81LIM,3,390},	//( - , SCM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{&iEM_TERR6IS68LIM,3,391},	//( - , SCM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{&iEM_TERR7SI74RIM,3,392},	//( - , SCM) Искажение: Радиация в реакторном зале
	{&iEM_TERA5SS21LIM,3,393},	//( - , SCM) Искажение: Приход на НУ НЛ1
	{&iEM_TERB5SS11LIM,3,394},	//( - , SCM) Искажение: Приход на ВУ НЛ2
	{&iEM_TERA5SS11LIM,3,395},	//( - , SCM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{&iEM_TERA9SS11LIM,3,396},	//( - , SCM) Искажение: Приход на ВУ НИ ДС1
	{&iEM_TERB2SS11LIM,3,397},	//( - , SCM) Искажение: Приход на ВУ РБ2
	{&iEM_TERB2SS12LIM,3,398},	//( - , SCM) Искажение: Магнит РБ2 зацеплен
	{&iEM_TERB2SS21LIM,3,399},	//( - , SCM) Искажение: Приход на НУ РБ2
	{&iEM_TERR3SS11LIM,3,400},	//( - , SCM) Искажение: Приход на ВУ гомогенных дверей-1
	{&iEM_TERB2SC01RIM,3,401},	//( - , SCM) Искажение: Координата штока РБ2
	{&iEM_TERR3SS21LIM,3,402},	//( - , SCM) Искажение: Приход на НУ гомогенных дверей-1
	{&iEM_TERR5SS11LIM,3,403},	//( - , SCM) Искажение: Приход на ВУ ворот отстойной зоны
	{&iEM_TERA4SS11LIM,3,404},	//( - , SCM) Искажение: Приход на ВУ НИ1
	{&iEM_TERR1SS11LIM,3,405},	//( - , SCM) Искажение: Приход на ВУ МДЗ1
	{&iEM_TERR1SS21LIM,3,406},	//( - , SCM) Искажение: Приход на НУ МДЗ1
	{&iEM_TERR2SS11LIM,3,407},	//( - , SCM) Искажение: Приход на ВУ МДЗ2
	{&iEM_TERR2SS21LIM,3,408},	//( - , SCM) Искажение: Приход на НУ МДЗ2
	{&iEM_TERA4VP82LIM,3,409},	//( - , SCM) Искажение Давление ПОДЪЁМ НИ в норме
	{&iEM_TERB4SS21LIM,3,410},	//( - , SCM) Искажение: Приход на НУ НИ2
	{&iEM_TERR5SS21LIM,3,411},	//( - , SCM) Искажение: Приход на НУ ворот отстойной зоны
	{&iEM_TERB6SS21LIM,3,412},	//( - , SCM) Искажение: Приход на НУ БЗ2
	{&iEM_TERB4SS11LIM,3,413},	//( - , SCM) Искажение: Приход на ВУ НИ2
	{&iEM_TERA4SS21LIM,3,414},	//( - , SCM) Искажение: Приход на НУ НИ1
	{&iEM_TERA6MS11LIM,3,415},	//( - , SCM) Искажение: Приход на ВУ БЗ1
	{&iEM_TERA6SS21LIM,3,416},	//( - , SCM) Искажение: Приход на НУ БЗ1
	{&iEM_TERB6SS11LIM,3,417},	//( - , SCM) Искажение: Приход на ВУ БЗ2
	{&iEM_TERR4SS11LIM,3,418},	//( - , SCM) Искажение: Приход на ВУ тележки
	{&iEM_TERR4MS21LIM,3,419},	//( - , SCM) Искажение: Приход на НУ тележки
	{&iEM_TERR4SS12LIM,3,420},	//( - , SCM) Искажение: Приход на механический ВУ тележки
	{&iEM_TERR4SS22LIM,3,421},	//( - , SCM) Искажение: Приход на механический НУ тележки
	{&iEM_TERR8SS11LIM,3,422},	//( - , SCM) Искажение: Аварийный НИ установлен
	{&iEM_TERB8SC01RIM,3,423},	//( - , SCM) Искажение: Координата АЗ2
	{&iEM_TERA8SC01RIM,3,424},	//( - , SCM) Искажение: Координата ДС2
	{&iEM_TERB8SS12LIM,3,425},	//( - , SCM) Искажение: Приход на механический ВУ АЗ2
	{&iEM_TERA8SS12LIM,3,426},	//( - , SCM) Искажение: Приход на механический ВУ ДС2
	{&iEM_TERB8SS22LIM,3,427},	//( - , SCM) Искажение: Приход на механический НУ АЗ2
	{&iEM_TERA8SS22LIM,3,428},	//( - , SCM) Искажение: Приход на механический НУ ДС2
	{&iEM_TERA9SS21LIM,3,429},	//( - , SCM) Искажение: Приход на НУ НИ ДС1
	{&iEM_TERB9SS21LIM,3,430},	//( - , SCM) Искажение: Приход на НУ НИ ДС2
	{&iEM_TERB9SS11LIM,3,431},	//( - , SCM) Искажение: Приход на ВУ НИ ДС2
	{&iEM_TERB5SS21LIM,3,432},	//( - , SCM) Искажение: Приход на НУ НЛ2
	{&iEM_TERA1SS21LIM,3,433},	//( - , SCM) Искажение: Приход на НУ ББ1
	{&iEM_TERA1SS11LIM,3,434},	//( - , SCM) Искажение: Приход на ВУ ББ1
	{&iEM_TERA1SC01RIM,3,435},	//( - , SCM) Искажение: Координата штока ББ1
	{&iEM_TERA1SS12LIM,3,436},	//( - , SCM) Искажение: Магнит ББ1 зацеплен
	{&iEM_TERB1SS21LIM,3,437},	//( - , SCM) Искажение: Приход на НУ ББ2
	{&iEM_TERB1SS11LIM,3,438},	//( - , SCM) Искажение:Приход на ВУ ББ2
	{&iEM_TERB1MC01RIM,3,439},	//( - , SCM) Искажение: Координата штока ББ2
	{&iEM_TERB1SS12LIM,3,440},	//( - , SCM) Искажение: Магнит ББ2 зацеплен
	{&iEM_TERTLG,3,441},	//( - , SCM) Неисправности  тележки от ИС
	{&fEM_R4MC01RC1,8,442},	//( - , SCM) Заданная координата тележки от ИС
	{&fEM_R4MV01RC1,8,444},	//( - , SCM) Заданная скорость тележки от ИС
	{&iEM_TERMAZ2,3,446},	//( - , SCM) Неисправности АЗ2 от ИС
	{&fEM_B8MV01RC1,8,447},	//( - , SCM) Заданная скорость АЗ2 от ИС
	{&iEM_TERDS2,3,449},	//( - , SCM) Неисправности ДС2 от ИС
	{&fEM_A8MC01RC1,8,450},	//( - , SCM) Заданная координата ДС2 от ИС
	{&fEM_A8MV01RC1,8,452},	//( - , SCM) Заданная скорость ДС2 от ИС
	{&iEM_TERBZ1,3,454},	//( - , SCM) Неисправности БЗ1
	{&fEM_A6MC01RC1,8,455},	//( - , SCM) Заданная координата БЗ1 от ИС
	{&fEM_A6MV01RC1,8,457},	//( - , SCM) Заданная скорость БЗ1 от ИС
	{&iEM_TERBZ2,3,459},	//( - , SCM) Неисправности БЗ2
	{&fEM_B6MC01RC1,8,460},	//( - , SCM) Заданная координата БЗ2 от ИС
	{&fEM_B6MV01RC1,8,462},	//( - , SCM) Заданная скорость БЗ2 от ИС
	{&iEM_TERMDZ2,3,464},	//( - , SCM) Неисправности МДЗ2
	{&fEM_R2MC01RC1,8,465},	//( - , SCM) Заданная координата МДЗ2 от ИС
	{&fEM_R2MV01RC1,8,467},	//( - , SCM) Заданная скорость МДЗ2 от ИС
	{&iEM_TERMDZ1,3,469},	//( - , SCM) Неисправности МДЗ1
	{&fEM_R1MC01RC1,8,470},	//( - , SCM) Заданная координата МДЗ1 от ИС
	{&fEM_R1MV01RC1,8,472},	//( - , SCM) Заданная скорость МДЗ1 от ИС
	{&iEM_TERNL1,3,474},	//( - , SCM) Неисправности НЛ1
	{&fEM_A5MC01RC1,8,475},	//( - , SCM) Заданная координата НЛ1 от ИС
	{&fEM_A5MV01RC1,8,477},	//( - , SCM) Заданная скорость НЛ1 от ИС
	{&iEM_TERNL2,3,479},	//( - , SCM) Неисправности НЛ2
	{&fEM_B5MC01RC1,8,480},	//( - , SCM) Заданная координата НЛ2 от ИС
	{&fEM_B5MV01RC1,8,482},	//( - , SCM) Заданная скорость НЛ2 от ИС
	{&fEM_A1UC08RIM,8,484},	//( - , SCM) Зона срабатывания КВ ББ(мм)
	{&fEM_A2UC08RIM,8,486},	//( - , SCM) Зона срабатывания КВ  РБ мм
	{&fEM_A3UC08RIM,8,488},	//( - , SCM) Зона срабатывания КВ ИС(мм)
	{&iEM_TERB2SS33LIM,3,490},	//( - , SCM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{&iEM_TERA1VP81LIM,3,491},	//( - , SCM) Искажение: Текущее давление СБРОС ББ1  в норме
	{&iEM_TERB1VP81LIM,3,492},	//( - , SCM) Искажение: Текущее давление СБРОС ББ2  в норме
	{&fEM_A0UT03RSP,8,493},	//( - , SCM) Стартовая  температура АЗ1 град
	{&fEM_A0UR01RSP,8,495},	//( - , SCM) Стартовая  реактивность АЗ1
	{&fEM_A0UR02RSP,8,497},	//( - , SCM) Стартовый  поток нейтронов АЗ1
	{&fEM_B0UT03RSP,8,499},	//( - , SCM) Стартовая  температура АЗ2 град
	{&fEM_A1MC01RSP,8,501},	//( - , SCM) Стартовая координата  ББ1
	{&fEM_A1MC02RSP,8,503},	//( - , SCM) Стартовая координата штока ББ1
	{&fEM_B1MC01RSP,8,505},	//( - , SCM) Стартовая координата  ББ2
	{&fEM_B1MC02RSP,8,507},	//( - , SCM) Стартовая координата штока ББ2
	{&fEM_A2MC01RC1,8,509},	//( - , SCM) Заданная координата РБ1 от ИС
	{&fEM_A2MV01RC1,8,511},	//( - , SCM) Заданная скорость движения РБ1 от ИС
	{&fEM_A2MC01RSP,8,513},	//( - , SCM) Стартовая координата  РБ1
	{&fEM_A2MC02RSP,8,515},	//( - , SCM) Стартовая координата штока РБ1
	{&fEM_B2MC01RSP,8,517},	//( - , SCM) Стартовая координата  РБ2
	{&fEM_B2MC02RSP,8,519},	//( - , SCM) Стартовая координата штока РБ2
	{&fEM_A3MC01RSP,8,521},	//( - , SCM) Стартовая координата  ИС1
	{&fEM_A3MC02RSP,8,523},	//( - , SCM) Стартовая координата штока ИС1
	{&fEM_B3MC01RSP,8,525},	//( - , SCM) Стартовая координата  ИС2
	{&fEM_B3MC02RSP,8,527},	//( - , SCM) Стартовая координата штока ИС2
	{&fEM_B8MC01RSP,8,529},	//( - , SCM) Стартовая координата АЗ2
	{&fEM_A8MC01RSP,8,531},	//( - , SCM) Стартовая координата ДС2
	{&fEM_A6MC01RSP,8,533},	//( - , SCM) Стартовая координата БЗ1
	{&fEM_B6MC01RSP,8,535},	//( - , SCM) Стартовая координата БЗ2
	{&fEM_R3UC01RSP,8,537},	//( - , SCM) Стартовая координата Гомогенных дверей
	{&fEM_R5UC01RSP,8,539},	//( - , SCM) Стартовая координата Ворот отстойной зоны
	{&fEM_R6UC01RSP,8,541},	//( - , SCM) Стартовая координата Кран-балки
	{&fEM_R2MC01RSP,8,543},	//( - , SCM) Стартовая координата МДЗ2
	{&fEM_R1MC01RSP,8,545},	//( - , SCM) Стартовая координата МДЗ1
	{&fEM_A5MC01RSP,8,547},	//( - , SCM) Стартовая координата НЛ1
	{&fEM_B5MC01RSP,8,549},	//( - , SCM) Стартовая координата НЛ2
	{&fEM_A9MC01RSP,8,551},	//( - , SCM) Стартовая координата НИ ДС1
	{&fEM_B9MC01RSP,8,553},	//( - , SCM) Стартовая координата НИ ДС2
	{&fEM_A4MC01RSP,8,555},	//( - , SCM) Стартовая координата НИ1
	{&fEM_B4MC01RSP,8,557},	//( - , SCM) Стартовая координата НИ2
	{&fEM_R4MC01RSP,8,559},	//( - , SCM) Стартовая координата тележки
	{&fEM_A1MV01RC1,8,561},	//( - , SCM) Заданная скорость движения  ББ1 от ИС
	{&iEM_TERB7MS31LIM,3,563},	//( - , SCM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{&iEM_TERA7MS31LIM,3,564},	//( - , SCM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{&fEM_R7UY00RSS,8,565},	//( - , SCM) Y-координата АЗ1 см
	{&iEM_TERA6VS12LIM,3,567},	//( - , SCM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{&iEM_TERA6VS22LIM,3,568},	//( - , SCM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{&iEM_TERB6VS12LIM,3,569},	//( - , SCM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{&iEM_TERB6VS22LIM,3,570},	//( - , SCM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{&iEM_TERA5VS22LIM,3,571},	//( - , SCM) Искажение: Движение створок НЛ1 к НУ
	{&iEM_TERA5VS12LIM,3,572},	//( - , SCM) Искажение: Движение створок НЛ1 к ВУ
	{&iEM_TERB5VS12LIM,3,573},	//( - , SCM) Искажение: Движение створок НЛ2 к ВУ
	{&iEM_TERB5VS22LIM,3,574},	//( - , SCM) Искажение: Движение створок НЛ2 к НУ
	{&iEM_TERR1VS12LIM,3,575},	//( - , SCM) Искажение: Движение МДЗ1 в сторону ВУ
	{&iEM_TERR1VS22LIM,3,576},	//( - , SCM) Искажение: Движение МДЗ1 в сторону НУ
	{&iEM_TERR2VS12LIM,3,577},	//( - , SCM) Искажение: Движение МДЗ2 в сторону ВУ
	{&iEM_TERR2VS22LIM,3,578},	//( - , SCM) Искажение: Движение МДЗ2 в сторону НУ
	{&iEM_TERR4VS12LDU,3,579},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&iEM_TERR4VS22LDU,3,580},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&fEM_B8MC01RC1,8,581},	//( - , SCM) Заданная координата АЗ2 от ИС
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
	{&A0IT03IRP,3,30},
	{&B0IT03IRP,3,33},
	{&A2IP01IZ2,3,15},
	{&A2IP01IZ1,3,3},
	{&B0IT02IZ2,3,18},
	{&B0IT01IZ1,3,6},
	{&A0IT02IZ2,3,12},
	{&A0IT01IZ1,3,0},
	{&B2IP01IZ2,3,21},
	{&A3IP02IDU,3,24},
	{&B3IP02IDU,3,27},
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
	{&A0VP81LZZ,1,4},
	{&B0VP81LZZ,1,58},
	{&A1VP81LZZ,1,0},
	{&B1VP81LZZ,1,60},
	{&R7II73LZ1,1,16},
	{&R7II71LZ1,1,14},
	{&R7II72LZ1,1,12},
	{&B3IS22LDU,1,22},
	{&A3IS22LDU,1,2},
	{&B3IS11LDU,1,20},
	{&A3IS11LDU,1,6},
	{&R7II72LZ2,1,48},
	{&R7II71LZ2,1,46},
	{&R7II73LZ2,1,50},
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
	{&A7AS31LDU,1,60},
	{&B3IS21LDU,1,24},
	{&B7AS31LDU,1,10},
	{&A1IS12LDU,1,62},
	{&B1IS11LDU,1,14},
	{&B1IS21LDU,1,16},
	{&B2IS12LDU,1,18},
	{&B2IS11LDU,1,20},
	{&B2IS21LDU,1,22},
	{&B9IS21LDU,1,40},
	{&B9IS11LDU,1,38},
	{&A9IS21LDU,1,36},
	{&A9IS11LDU,1,34},
	{&B1IS12LDU,1,12},
	{&R2IS21LDU,1,48},
	{&A4IS11LDU,1,30},
	{&R2IS11LDU,1,46},
	{&A4IS21LDU,1,32},
	{&R8IS11LDU,1,26},
	{&R1IS11LDU,1,42},
	{&R1IS21LDU,1,44},
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
	{&A3IS21LDU,1,10},
	{&A2IS12LDU,1,4},
	{&A2IS11LDU,1,6},
	{&A2IS21LDU,1,8},
	{&A1IS11LDU,1,0},
	{&B4IS11LDU,1,12},
	{&B4IS21LDU,1,14},
	{&B5IS11LDU,1,62},
	{&R4IS11LDU,1,42},
	{&R4IS21LDU,1,46},
	{&A1IS21LDU,1,2},
	{&B6IS21LDU,1,60},
	{&B6IS11LDU,1,58},
	{&A6IS21LDU,1,52},
	{&R0IS02LDU,1,32},
	{&A5IS11LDU,1,54},
	{&R4IS12LDU,1,44},
	{&R4IS22LDU,1,48},
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
	{&R3IS21LDU,1,4},
	{&R5IS11LDU,1,18},
	{&A6IS11LDU,1,34},
	{&A8IS12LDU,1,28},
	{&R3IS11LDU,1,2},
	{&R5IS21LDU,1,20},
	{&B8IS21LDU,1,8},
	{&B8IS11LDU,1,14},
	{&A8IS22LDU,1,30},
	{&R6IS21LDU,1,26},
	{&B8IS12LDU,1,10},
	{&B8IS22LDU,1,12},
	{&B5IS21LDU,1,0},
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
	{&A7AP31LDU,1,32},
	{&B7AP31LDU,1,60},
	{&A3AD31LDU,1,30},
	{&A3AD34LDU,1,22},
	{&A4AD10LDU,1,28},
	{&B4AD10LDU,1,56},
	{&B3AD33LDU,1,52},
	{&B3AD31LDU,1,58},
	{&B3AD34LDU,1,50},
	{&A3AD33LDU,1,24},
	{&B2AD33LDU,1,54},
	{&A8AD10LDU,1,62},
	{&R1AD10LDU,1,34},
	{&R1AD20LDU,1,36},
	{&A2AD33LDU,1,26},
	{&R2AD10LDU,1,38},
	{&B5AD20LDU,1,48},
	{&B5AD10LDU,1,46},
	{&R2AD20LDU,1,40},
	{&A5AD20LDU,1,44},
	{&A5AD10LDU,1,42},
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
	{&A3AD11LDU,1,18},
	{&A3AD21LDU,1,20},
	{&A3AD01LDU,1,22},
	{&A3AD02LDU,1,24},
	{&A1AD11LDU,1,50},
	{&A1AD21LDU,1,52},
	{&A1AD01LDU,1,54},
	{&A1AD02LDU,1,56},
	{&A1AD03LDU,1,58},
	{&A1AD04LDU,1,60},
	{&B9AD10LDU,1,48},
	{&A8AD20LDU,1,0},
	{&A6AD10LDU,1,2},
	{&A6AD20LDU,1,4},
	{&B6AD10LDU,1,6},
	{&B6AD20LDU,1,8},
	{&A9AD10LDU,1,46},
	{&B3AD01LDU,1,36},
	{&B8AD20LDU,1,16},
	{&B8AD10LDU,1,14},
	{&R4AD20LDU,1,12},
	{&R4AD10LDU,1,10},
	{&B3AD21LDU,1,34},
	{&B3AD03LDU,1,40},
	{&B3AD05LDU,1,44},
	{&B3AD04LDU,1,42},
	{&A3AD03LDU,1,26},
	{&A3AD04LDU,1,28},
	{&A3AD05LDU,1,30},
	{&B3AD02LDU,1,38},
	{&B3AD11LDU,1,32},
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
	{&B2AD01LDU,1,34},
	{&A2AD21LDU,1,18},
	{&A2AD11LDU,1,16},
	{&B1AD05LDU,1,14},
	{&B2AD21LDU,1,32},
	{&B2AD11LDU,1,30},
	{&R0AD16LDU,1,62},
	{&A2AD05LDU,1,28},
	{&A2AD04LDU,1,26},
	{&A2AD01LDU,1,20},
	{&A2AD02LDU,1,22},
	{&A2AD03LDU,1,24},
	{&B2AD05LDU,1,42},
	{&B2AD04LDU,1,40},
	{&B2AD03LDU,1,38},
	{&B2AD02LDU,1,36},
	{&A1AD05LDU,1,0},
	{&B2AD32LDU,1,56},
	{&B2AD31LDU,1,58},
	{&B1AD32LDU,1,52},
	{&B1AD31LDU,1,54},
	{&B1AD11LDU,1,2},
	{&B1AD21LDU,1,4},
	{&B1AD01LDU,1,6},
	{&A1AD31LDU,1,46},
	{&A1AD32LDU,1,44},
	{&A2AD31LDU,1,50},
	{&B1AD02LDU,1,8},
	{&A2AD32LDU,1,48},
	{&B1AD03LDU,1,10},
	{&B1AD04LDU,1,12},
	{&R8AD21LDU,1,60},
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
	setAsFloat(283,0.015);
	setAsFloat(284,0.0069);
	setAsFloat(285,0.21);
	setAsFloat(286,0);
	setAsFloat(287,0);
	setAsFloat(288,0.0096);
	setAsFloat(289,0.0026);
	setAsFloat(290,106);
	setAsFloat(291,135.227);
	setAsFloat(292,25);
	setAsFloat(293,320.435466);
	setAsFloat(294,0.0055);
	setAsFloat(295,0.000877);
	setAsFloat(296,200);
	setAsFloat(297,100);
	setAsFloat(298,0);
	setAsFloat(299,0);
	setAsFloat(300,100);
	setAsFloat(301,80);
	setAsFloat(302,0.002375);
	setAsFloat(303,0);
	setAsFloat(304,165);
	setAsFloat(305,200);
	setAsFloat(306,0.001675);
	setAsFloat(307,4);
	setAsFloat(308,1530.0);
	setAsFloat(309,137.4);
	setAsFloat(310,0);
	setAsFloat(311,390.0);
	setAsFloat(312,2000.0);
	setAsFloat(313,1500.0);
	setAsFloat(314,10.91);
	setAsFloat(315,10.91);
	setAsFloat(316,1500.0);
	setAsFloat(317,2000);
	setAsFloat(318,390.0);
	setAsFloat(319,0);
	setAsFloat(320,55.0);
	setAsFloat(321,15.0);
	setAsFloat(322,5.0);
	setAsFloat(323,1E12);
	setAsFloat(324,40.0);
	setAsFloat(325,20.0);
	setAsFloat(326,20.0);
	setAsFloat(327,20.0);
	setAsFloat(328,1269.0);
	setAsFloat(329,256.0);
	setAsFloat(330,1.0);
	setAsFloat(331,2.0);
	setAsFloat(332,0);
	setAsFloat(333,0.026);
	setAsFloat(334,0.00002);
	setAsFloat(335,0.0);
	setAsFloat(336,27.108);
	setAsFloat(337,600);
	setAsFloat(338,0);
	setAsFloat(339,0.00009765625);
	setAsFloat(340,1.6);
	setAsFloat(341,0);
	setAsFloat(342,0.00009765625);
	setAsFloat(343,2.5);
	setAsFloat(344,0);
	setAsFloat(345,0.00009765625);
	setAsFloat(346,10000.0);
	setAsFloat(347,0.0009765625);
	setAsFloat(348,750);
	setAsFloat(349,100);
	setAsFloat(350,200);
	setAsFloat(351,300);
	setAsFloat(352,400);
	setAsFloat(353,500);
	setAsFloat(354,600);
	setAsFloat(355,0.50);
	setAsFloat(356,0.50);
	setAsFloat(357,0.50);
	setAsFloat(358,20);
	setAsFloat(359,11.0);
	setAsFloat(360,1585.0);
	setAsFloat(361,1796.0);
	setAsFloat(362,1555.0);
	setAsFloat(363,1269.0);
	setAsFloat(364,1269.0);
	setAsFloat(365,1585.0);
	setAsFloat(366,1796.0);
	setAsFloat(367,1269.0);
	setAsFloat(368,248.0);
	setAsFloat(369,284.5);
	setAsFloat(370,248.0);
	setAsFloat(371,271.6);
	setAsFloat(372,287.2);
	setAsFloat(373,594.0);
	setAsFloat(374,559.0);
	setAsFloat(375,588.0);
	setAsFloat(376,1555.0);
	setAsFloat(377,1281.2);
	setAsFloat(378,1269.0);
	setAsFloat(379,594.0);
	setAsFloat(380,597.2);
	setAsFloat(381,556.8);
	setAsFloat(382,1.0);
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
	setAsFloat(394,0);
	setAsFloat(395,0);
	setAsFloat(396,0);
	setAsFloat(397,0);
	setAsFloat(398,0.0);
	setAsFloat(399,0);
	setAsFloat(400,0.0);
	setAsFloat(401,0);
	setAsFloat(402,0.0);
	setAsFloat(403,0.0);
	setAsFloat(404,0.0);
	setAsFloat(405,0.0);
	setAsFloat(406,37037.04);
	setAsFloat(407,975000.0);
	setAsFloat(408,20);
	setAsFloat(409,18000);
	setAsFloat(410,18000);
	setAsFloat(411,18000);
	setAsFloat(412,0.76);
	setAsFloat(413,0.245);
	setAsFloat(414,2.9);
	setAsFloat(415,0.13);
	setAsFloat(416,0.73);
	setAsFloat(417,0.6);
	setAsFloat(418,9807.0);
	setAsFloat(419,22975.0);
	setAsFloat(420,12750.0);
	setAsFloat(421,20);
	setAsFloat(422,20);
	setAsFloat(423,0);
	setAsFloat(424,5.0);
	setAsFloat(425,5.0);
	setAsFloat(426,5.0);
	setAsFloat(427,100.0);
	setAsFloat(428,4000);
	setAsFloat(429,100000);
	setAsFloat(430,1000000);
	setAsFloat(431,32000.0);
	setAsFloat(432,5.0);
	setAsFloat(433,15.0);
	setAsFloat(434,15.0);
	setAsFloat(435,20.0);
	setAsFloat(436,10.0);
	setAsBool(437,0);
	setAsBool(438,0);
	setAsBool(439,0);
	setAsFloat(440,0.45);
	setAsFloat(441,0.39);
	setAsFloat(442,2.74);
	setAsFloat(443,0.07);
	setAsFloat(444,0.275);
	setAsFloat(445,0.245);
	setAsFloat(446,0.045);
	setAsFloat(447,0.05);
	setAsShort(448,0);
	setAsFloat(449,0);
	setAsFloat(450,0);
	setAsShort(451,0);
	setAsFloat(452,0);
	setAsFloat(453,0);
	setAsShort(454,0);
	setAsFloat(455,0);
	setAsFloat(456,0);
	setAsShort(457,0);
	setAsFloat(458,0);
	setAsFloat(459,0);
	setAsShort(460,0);
	setAsFloat(461,0);
	setAsFloat(462,0);
	setAsShort(463,0);
	setAsFloat(464,0);
	setAsFloat(465,0);
	setAsShort(466,0);
	setAsShort(467,0);
	setAsFloat(468,0);
	setAsShort(469,0);
	setAsShort(470,0);
	setAsFloat(471,0);
	setAsFloat(472,0);
	setAsFloat(473,0);
	setAsFloat(474,0);
	setAsFloat(475,0);
	setAsFloat(476,0);
	setAsFloat(477,0);
	setAsFloat(478,0);
	setAsShort(479,0);
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
	setAsFloat(563,0);
	setAsFloat(564,0);
	setAsShort(565,0);
	setAsFloat(566,0);
	setAsShort(567,0);
	setAsFloat(568,0);
	setAsFloat(569,0);
	setAsShort(570,0);
	setAsFloat(571,0);
	setAsFloat(572,0);
	setAsShort(573,0);
	setAsFloat(574,0);
	setAsFloat(575,0);
	setAsBool(576,0);
	setAsBool(577,1);
	setAsBool(578,0);
	setAsBool(579,1);
	setAsBool(580,0);
	setAsShort(581,0);
	setAsFloat(582,0);
	setAsFloat(583,0);
	setAsShort(584,0);
	setAsFloat(585,0);
	setAsFloat(586,0);
	setAsShort(587,0);
	setAsFloat(588,0);
	setAsFloat(589,0);
	setAsShort(590,0);
	setAsFloat(591,0);
	setAsFloat(592,0);
	setAsBool(593,1);
	setAsFloat(594,0.01);
	setAsFloat(595,0.01);
	setAsFloat(596,0.01);
	setAsShort(597,0);
	setAsShort(598,0);
	setAsShort(599,0);
	setAsFloat(600,25.017338);
	setAsFloat(601,-0.15912805);
	setAsFloat(602,0.000000166);
	setAsFloat(603,25.017338);
	setAsFloat(604,0);
	setAsFloat(605,0);
	setAsFloat(606,0);
	setAsFloat(607,0);
	setAsFloat(608,0);
	setAsFloat(609,0);
	setAsFloat(610,0);
	setAsFloat(611,0);
	setAsFloat(612,0);
	setAsFloat(613,0);
	setAsFloat(614,0.000885839);
	setAsFloat(615,0.000885839);
	setAsFloat(616,0.000885839);
	setAsFloat(617,0.000885839);
	setAsFloat(618,390);
	setAsFloat(619,390);
	setAsFloat(620,55);
	setAsFloat(621,55);
	setAsFloat(622,0);
	setAsFloat(623,4000.0);
	setAsFloat(624,10);
	setAsFloat(625,0);
	setAsFloat(626,0);
	setAsFloat(627,5);
	setAsFloat(628,5);
	setAsFloat(629,0);
	setAsFloat(630,0);
	setAsFloat(631,0);
	setAsFloat(632,0);
	setAsFloat(633,1530.0);
	setAsFloat(634,0);
	setAsShort(635,0);
	setAsShort(636,0);
	setAsFloat(637,506.5);
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
	setAsFloat(652,1.0);
	setAsFloat(653,1.0);
	setAsFloat(654,1.0);
	setAsFloat(655,1570.0);
	setAsFloat(656,1269);
	setAsFloat(657,1281.2);
	setAsFloat(658,248.0);
	setAsFloat(659,572.4);
	setAsFloat(660,246.8);
	setAsFloat(661,1);
	setAsFloat(662,0);
	setAsShort(104,2);
}
uspaint8 InternalBuf[1081];

/* ����������� �������� ��� � ������*/
ssbool lRM_1_ = {1,0}; /* ���� ������� ������� �� ����� ��� */ 
ssfloat fRM_0_ = {0,0}; /* �������� �������� �� ������ ��1 */ 
ssfloat fRM_1_ = {1,0}; /* *Vm - ������ ��������� �������� (����� � �������) */ 
ssbool lRM_0_ = {0,0}; /* ���� ������� ������� �� ����� ��� */ 
ssfloat fRM_1_0 = {1.0,0}; /* ����������� �������� �� (����/�) */ 
ssfloat fRM_180_0 = {180.0,0}; /* ���������� �������� �������� ����������� �� ���� */ 
ssfloat fRM_0_0 = {0.0,0}; /* ���������� ������ ������ �� ���� */ 
ssfloat fRM_n50_ = {-50,0}; /* ���������� ������� �������� ����������� �� ���� */ 
ssfloat fRM_2000_0 = {2000.0,0}; /* ���������� �������� �������� ����������� ��� �� */ 
ssfloat fRM_n150_ = {-150,0}; /* ���������� ������� �������� ����������� ��� �� */ 
ssfloat fRM_1500_0 = {1500.0,0}; /* ���������� �������� ������������� ����������� �� �� */ 
ssint iRM_7_ = {7,0}; /* N */ 
ssfloat fRM_390_ = {390,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_420_ = {420,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_513_ = {513,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_767_ = {767,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_900_ = {900,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_1200_ = {1200,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_1500_ = {1500,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_3_546 = {3.546,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_2_7 = {2.7,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_2_ = {2,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_88884 = {0.88884,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_6221739 = {0.6221739,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_35555072 = {0.35555072,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_2666666667 = {0.2666666667,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssint iRM_5_ = {5,0}; /* N */ 
ssfloat fRM_600_ = {600,0}; /* Ai, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_5 = {0.5,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_2 = {0.2,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_088884 = {0.088884,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_066666667 = {0.066666667,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_02173913 = {0.02173913,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_002453 = {0.002453,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_00184 = {0.00184,0}; /* Bi, i=1..N -�������� ������� ����� */ 
ssfloat fRM_0_10 = {0.10,0}; /* ���� ������������ �� ��(��) */ 
ssfloat fRM_0_50 = {0.50,0}; /* ���� ������������ �� ��� (��) */ 
ssint iRM_2_ = {2,0}; /* n - N-����������� ������� x */ 
ssint iRM_3_ = {3,0}; /* N-����� ������ */ 
ssint iRM_4_ = {4,0}; /* N-����� ������ */ 
ssint iRM_0_ = {0,0}; /* Ter - ������������� ��������� */ 
ssfloat fRM_100000_ = {100000,0}; /* KPv - ���������� ���. ����������� ��������� �� */ 
ssfloat fRM_n100_ = {-100,0}; /* KZv - ���������� ���. ����������� ��������� �� */ 
ssfloat fRM_20_ = {20,0}; /* Tp - ��������� ���� �� */ 
sschar bRM_2_ = {2,0}; /* type - ��� ������ */ 
sschar bRM_4_ = {4,0}; /* type - ��� ������ */ 
sschar bRM_5_ = {5,0}; /* type - ��� ������ */ 
sschar bRM_1_ = {1,0}; /* type - ��� ������ */ 
ssint iRM_500_ = {500,0}; /* tz - ������ ��������, 10-�� �� */ 
ssfloat fRM_3_ = {3,0}; /* m1 - �������� ���������� ������� ������� �� �������� */ 
ssfloat fRM_2_0 = {2.0,0}; /* ampl - ��������� ��������������� ���������� */ 
ssint iRM_3276_ = {3276,0}; /* min - ����������� ��������� �������� ��������� ������� */ 
ssint iRM_16383_ = {16383,0}; /* max - ������������ ��������� �������� ��������� ������� */ 
ssfloat fRM_3276_ = {3276,0}; /* c   - ���. �������� ���� ��� */ 
ssfloat fRM_16383_ = {16383,0}; /* d - ����.  �������� ���� ��� */ 
ssfloat fRM_200_ = {200,0}; /* maxs1 - ���c. �������� ������� ������� */ 
ssfloat fRM_0_0015 = {0.0015,0}; /* m1 - �������� ���������� ������� ������� �� �������� */ 
ssfloat fRM_0_001 = {0.001,0}; /* ampl - ��������� ��������������� ���������� */ 
ssfloat fRM_0_1 = {0.1,0}; /* k - ����������� �������� */ 
ssint iRM_16_ = {16,0}; /* n - N-����������� ������� ������� ���������� */ 
ssfloat fRM_2000_ = {2000,0}; /* maxs1 - ���c. �������� ������� ������� */ 
ssfloat fRM_15_ = {15,0}; /* m1 - �������� ���������� ������� ������� �� �������� */ 

uspaint8 SpaEEPROMBuf[1631];

/* ����������� ���������� */
ssbool var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
ssfloat var6;
ssfloat var7;
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
ssfloat var40;
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
sslong var54;
ssfloat var55;
sslong var56;
ssfloat var57;
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
ssint var92;
ssint var93;
ssfloat var94;
ssfloat var95;
sslong var96;
ssfloat var97;
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
ssfloat var109;
ssbool var110;
ssbool var111;
sslong var112;
ssfloat var113;
sslong var114;
ssfloat var115;
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
ssint var127;
ssfloat var128;
ssbool var129;
ssbool var130;
ssint var131;
ssfloat var132;
ssbool var133;
sslong var134;
ssfloat var135;
ssbool var136;
ssbool var137;
sslong var138;
ssfloat var139;
ssbool var140;
ssint var141;
ssint var142;
ssbool var143;
ssbool var144;
ssbool var145;
sslong var146;
ssfloat var147;
ssbool var148;
ssbool var149;
ssbool var150;
ssfloat var151;
ssfloat var152;
ssfloat var153;
ssint var154;
ssint var155;
ssint var156;
ssfloat var157;
ssfloat var158;
ssfloat var159;
ssint var160;
ssint var161;
ssbool var162;
ssbool var163;
ssint var164;
ssfloat var165;
ssfloat var166;
ssfloat var167;
ssbool var168;
ssbool var169;
ssbool var170;
ssbool var171;
ssfloat var172;
ssbool var173;
ssfloat var174;
ssbool var175;
ssbool var176;
ssbool var177;
ssbool var178;
ssbool var179;
ssbool var180;
ssbool var181;
ssfloat var182;
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
ssfloat var221;
ssfloat var222;
ssfloat var223;
ssfloat var224;
ssfloat var225;
ssfloat var226;
ssfloat var227;
ssfloat var228;
ssfloat var229;
ssbool var230;
ssbool var231;
ssbool var232;
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
ssfloat var245;
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
ssfloat var270;
ssbool var271;
ssbool var272;
ssfloat var273;
ssbool var274;
ssbool var275;
ssbool var276;
ssbool var277;
ssbool var278;
ssbool var279;
ssbool var280;
ssbool var281;
ssfloat var282;
ssfloat var283;
ssfloat var284;
ssfloat var285;
ssbool var286;
ssfloat var287;
ssfloat var288;
ssfloat var289;
ssfloat var290;
ssbool var291;
ssbool var292;
ssbool var293;
ssbool var294;
ssbool var295;
ssfloat var296;
ssfloat var297;
ssbool var298;
ssbool var299;
ssbool var300;
ssbool var301;
ssbool var302;
ssfloat var303;
ssfloat var304;
ssbool var305;
ssbool var306;
ssbool var307;
ssbool var308;
ssbool var309;
ssbool var310;
ssfloat var311;
ssfloat var312;
ssbool var313;
ssbool var314;
ssbool var315;
ssbool var316;
ssbool var317;
ssbool var318;
ssfloat var319;
ssfloat var320;
ssbool var321;
ssbool var322;
ssbool var323;
ssbool var324;
ssbool var325;
ssfloat var326;
ssfloat var327;
ssbool var328;
ssbool var329;
ssbool var330;
ssbool var331;
ssbool var332;
ssfloat var333;
ssfloat var334;
ssfloat var335;
ssfloat var336;
ssbool var337;
ssfloat var338;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* ���������� �������� */
psbool  array_m349_x_1[16] = {&lEM_R8AD10LC1,&lEM_R8AD10LC1,&var332,&var190,&var184,&var274,&var272,&var266,&var263,&var279,&var322,&var317,&var308,&var298,&var292,&R0MW13LP2};
psbool  array_m901_x_1[2] = {&lEM_R0IE02LRP,&lEM_R0IE01LRP};
psbool  array_m896_x_1[2] = {&var170,&R0MW13LP2};
psbool  array_m921_x_1[2] = {&var177,&R0MW13LP2};
psbool  array_m914_x_1[2] = {&var178,&R0MW13LP2};
psbool  array_m906_x_1[2] = {&var179,&R0MW13LP2};
psbool  array_m611_x_1[2] = {&var34,&var231};
psbool  array_m608_x_1[2] = {&var34,&var232};
psbool  array_m617_x_1[3] = {&lEM_C1AD31LRP,&R0VZ71LZ1,&R0VZ71LZ2};
psbool  array_m898_x_1[2] = {&var202,&R0MW13LP2};
psbool  array_m286_x_1[2] = {&var219,&B3AD31LDU};
psbool  array_m252_x_1[3] = {&B2AD31LDU,&var205,&var219};
psbool  array_m253_x_1[3] = {&B2AD32LDU,&var205,&var219};
psbool  array_m215_x_1[4] = {&B1AD32LDU,&var208,&var207,&var219};
psbool  array_m214_x_1[4] = {&var208,&B1AD31LDU,&var207,&var219};
psbool  array_m118_x_1[2] = {&A3AD31LDU,&var219};
psbool  array_m48_x_1[4] = {&A1AD32LDU,&var213,&var212,&var219};
psbool  array_m47_x_1[4] = {&var213,&A1AD31LDU,&var212,&var219};
psbool  array_m85_x_1[3] = {&A2AD31LDU,&var217,&var219};
psbool  array_m86_x_1[3] = {&A2AD32LDU,&var217,&var219};
psbool  array_m624_x_1[2] = {&var230,&var33};
psfloat  array_m7_a_1[5] = {&fRM_390_,&fRM_600_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m7_b_1[5] = {&fRM_0_5,&fRM_0_2,&fRM_0_088884,&fRM_0_066666667,&fRM_0_02173913};
psfloat  array_m9_a_1[7] = {&fRM_390_,&fRM_420_,&fRM_513_,&fRM_767_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m9_b_1[7] = {&fRM_3_546,&fRM_2_7,&fRM_2_,&fRM_0_88884,&fRM_0_6221739,&fRM_0_35555072,&fRM_0_2666666667};
psfloat  array_m295_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m127_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m261_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m94_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m229_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m61_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};

/* ���������� �������� */
_S_ifelse  S_ifelse_708_1 = {&var283,&vainSFloat,&internal1_m708_xy,&var1};
_S_looktakt  S_looktakt_144_1 = {&var2};
_S_to3val  S_to3val_950_1 = {&fEM_R7UX16RSS,&fRM_900_,&fRM_15_,&fRM_0_0015,&fRM_0_,&fRM_2000_,&fRM_2000_,&TerR0IN06FRP,&var3,&var4,&vainSFloat,&bFirstEnterFlag};
_S_vchs  S_vchs_876_1 = {&var283,&var334,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_5_,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var5,&internal1_m876_Chim0};
_S_vchs  S_vchs_866_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&bRM_4_,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var6,&internal1_m866_Chim0};
_S_vchs  S_vchs_858_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&bRM_2_,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var7,&internal1_m858_Chim0};
_S_twobool  S_twobool_813_1 = {&var281,&iEM_TERR4VS22LDU,&var8,&vainSBool,&internal1_m813_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_812_1 = {&var280,&iEM_TERR4VS12LDU,&var9,&vainSBool,&internal1_m812_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_995_1 = {&var257,&iEM_TERR2VS22LIM,&var10,&vainSBool,&internal1_m995_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_994_1 = {&var256,&iEM_TERR2VS12LIM,&var11,&vainSBool,&internal1_m994_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_993_1 = {&var261,&iEM_TERR1VS22LIM,&var12,&vainSBool,&internal1_m993_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_992_1 = {&var260,&iEM_TERR1VS12LIM,&var13,&vainSBool,&internal1_m992_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_670_1 = {&var249,&iEM_TERB5VS22LIM,&var14,&vainSBool,&internal1_m670_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_669_1 = {&var248,&iEM_TERB5VS12LIM,&var15,&vainSBool,&internal1_m669_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_648_1 = {&var253,&iEM_TERA5VS22LIM,&var16,&vainSBool,&internal1_m648_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_647_1 = {&var252,&iEM_TERA5VS12LIM,&var17,&vainSBool,&internal1_m647_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_668_1 = {&var265,&iEM_TERB6VS22LIM,&var18,&vainSBool,&internal1_m668_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_667_1 = {&var264,&iEM_TERB6VS12LIM,&var19,&vainSBool,&internal1_m667_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_646_1 = {&var269,&iEM_TERA6VS22LIM,&var20,&vainSBool,&internal1_m646_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_645_1 = {&var268,&iEM_TERA6VS12LIM,&var21,&vainSBool,&internal1_m645_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_512_1 = {&var39,&iEM_TERA1VP81LIM,&var22,&vainSBool,&internal1_m512_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_528_1 = {&var39,&iEM_TERB1VP81LIM,&var23,&vainSBool,&internal1_m528_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_400_1 = {&var308,&iEM_TERB2SS33LIM,&var24,&vainSBool,&internal1_m400_Out10,&bFirstEnterFlag};
_S_noto  S_noto_475_1 = {&var186,&var25};
_S_noto  S_noto_476_1 = {&var185,&var26};
_S_noto  S_noto_466_1 = {&var187,&var27};
_S_noto  S_noto_468_1 = {&var188,&var28};
_S_rs  S_rs_473_1 = {&var26,&lEM_R5AD10LC1,&var29,&vainSBool,&internal1_m473_q0};
_S_rs  S_rs_474_1 = {&var25,&lEM_R5AD20LC1,&var30,&vainSBool,&internal1_m474_q0};
_S_rs  S_rs_461_1 = {&var27,&lEM_R3AD10LC1,&var31,&vainSBool,&internal1_m461_q0};
_S_rs  S_rs_462_1 = {&var28,&lEM_R3AD20LC1,&var32,&vainSBool,&internal1_m462_q0};
_S_andn  S_andn_349_1 = {array_m349_x_1,&iRM_16_,&vainSBool};
_S_zpfs  S_zpfs_621_1 = {&R0AD14LDU,&fEM_R7UI76RIM,&var33,&internal1_m621_tx,&internal1_m621_y0};
_S_zpfs  S_zpfs_609_1 = {&R0AD16LDU,&fEM_R7UI77RIM,&var34,&internal1_m609_tx,&internal1_m609_y0};
_S_bol  S_bol_936_1 = {&fEM_A4UP01RIM,&fEM_A4UP02RIM,&var35};
_S_bol  S_bol_933_1 = {&fEM_A3UP01RIM,&fEM_A3UP02RIM,&var36};
_S_bol  S_bol_912_1 = {&fEM_A0UP02RIM,&fEM_A0UP01RIM,&var37};
_S_bol  S_bol_934_1 = {&fEM_A2UP02RIM,&fEM_A2UP03RIM,&var38};
_S_bol  S_bol_924_1 = {&fEM_A1UP01RIM,&fEM_A1UP82RIM,&var39};
_S_ampl  S_ampl_363_1 = {&var273,&fRM_0_1,&var40};
_S_or2  S_or2_925_1 = {&R0EE04LZ1,&R0EE04LZ2,&var41};
_S_or2  S_or2_916_1 = {&R0EE03LZ1,&R0EE03LZ2,&var42};
_S_or2  S_or2_909_1 = {&R0EE02LZ1,&R0EE02LZ2,&var43};
_S_or2  S_or2_902_1 = {&R0EE01LZ1,&R0EE01LZ2,&var44};
_S_zpfs  S_zpfs_597_1 = {&var189,&fRM_1_0,&var45,&internal1_m597_tx,&internal1_m597_y0};
_S_zpfs  S_zpfs_595_1 = {&var192,&fRM_0_5,&var46,&internal1_m595_tx,&internal1_m595_y0};
_S_twobool  S_twobool_205_1 = {&B1AD21LDU,&iEM_TERB1IE04LDU,&var47,&vainSBool,&internal1_m205_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_222_1 = {&B1AD11LDU,&iEM_TERB1IE03LDU,&var48,&vainSBool,&internal1_m222_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_41_1 = {&A1AD21LDU,&iEM_TERA1IE04LDU,&var49,&vainSBool,&internal1_m41_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_56_1 = {&A1AD11LDU,&iEM_TERA1IE03LDU,&var50,&vainSBool,&internal1_m56_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_966_1 = {&var325,&iEM_TERB1SS12LIM,&var51,&vainSBool,&internal1_m966_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_963_1 = {&var321,&iEM_TERB1SS11LIM,&var52,&vainSBool,&internal1_m963_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_962_1 = {&var322,&iEM_TERB1SS21LIM,&var53,&vainSBool,&internal1_m962_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_965_1 = {&var55,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var54,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m965_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_960_1 = {&var224,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB1MC01RIM,&var55,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_948_1 = {&var57,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var56,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m948_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_941_1 = {&var225,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA1SC01RIM,&var57,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_949_1 = {&var332,&iEM_TERA1SS12LIM,&var58,&vainSBool,&internal1_m949_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_946_1 = {&var329,&iEM_TERA1SS11LIM,&var59,&vainSBool,&internal1_m946_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_945_1 = {&var330,&iEM_TERA1SS21LIM,&var60,&vainSBool,&internal1_m945_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1033_1 = {&var263,&iEM_TERB6SS21LIM,&var61,&vainSBool,&internal1_m1033_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1014_1 = {&var262,&iEM_TERB6SS11LIM,&var62,&vainSBool,&internal1_m1014_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1013_1 = {&var267,&iEM_TERA6SS21LIM,&var63,&vainSBool,&internal1_m1013_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1012_1 = {&var266,&iEM_TERA6MS11LIM,&var64,&vainSBool,&internal1_m1012_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_834_1 = {&var272,&iEM_TERA8SS12LIM,&var65,&vainSBool,&internal1_m834_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_836_1 = {&var271,&iEM_TERA8SS22LIM,&var66,&vainSBool,&internal1_m836_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_833_1 = {&var275,&iEM_TERB8SS12LIM,&var67,&var68,&internal1_m833_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_835_1 = {&var274,&iEM_TERB8SS22LIM,&var69,&var70,&internal1_m835_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_809_1 = {&var276,&iEM_TERR4SS12LIM,&var71,&vainSBool,&internal1_m809_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_810_1 = {&var277,&iEM_TERR4SS22LIM,&var72,&vainSBool,&internal1_m810_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_808_1 = {&var279,&iEM_TERR4MS21LIM,&var73,&vainSBool,&internal1_m808_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_807_1 = {&var278,&iEM_TERR4SS11LIM,&var74,&vainSBool,&internal1_m807_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1028_1 = {&var35,&iEM_TERA4VP82LIM,&var75,&var76,&internal1_m1028_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_980_1 = {&var255,&iEM_TERR2SS21LIM,&var77,&vainSBool,&internal1_m980_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_979_1 = {&var254,&iEM_TERR2SS11LIM,&var78,&vainSBool,&internal1_m979_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_978_1 = {&var259,&iEM_TERR1SS21LIM,&var79,&vainSBool,&internal1_m978_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_977_1 = {&var258,&iEM_TERR1SS11LIM,&var80,&vainSBool,&internal1_m977_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1029_1 = {&var194,&iEM_TERB4SS21LIM,&var81,&vainSBool,&internal1_m1029_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1010_1 = {&var193,&iEM_TERB4SS11LIM,&var82,&vainSBool,&internal1_m1010_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_811_1 = {&lEM_R8AD10LC1,&iEM_TERR8SS11LIM,&var83,&vainSBool,&internal1_m811_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1011_1 = {&var191,&iEM_TERA4SS21LIM,&var84,&vainSBool,&internal1_m1011_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1009_1 = {&var190,&iEM_TERA4SS11LIM,&var85,&vainSBool,&internal1_m1009_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1030_1 = {&var186,&iEM_TERR5SS21LIM,&var86,&vainSBool,&internal1_m1030_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1008_1 = {&var185,&iEM_TERR5SS11LIM,&var87,&vainSBool,&internal1_m1008_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_991_1 = {&var188,&iEM_TERR3SS21LIM,&var88,&vainSBool,&internal1_m991_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_976_1 = {&var187,&iEM_TERR3SS11LIM,&var89,&vainSBool,&internal1_m976_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_529_1 = {&var38,&iEM_TERA2VP82LIM,&var90,&var91,&internal1_m529_Out10,&bFirstEnterFlag};
_S_toao  S_toao_533_1 = {&var95,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var92,&bFirstEnterFlag};
_S_toao  S_toao_532_1 = {&var94,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var93,&bFirstEnterFlag};
_S_to3val  S_to3val_526_1 = {&var152,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERB2SP01RIM,&var94,&vainSFloat,&var95,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_410_1 = {&var97,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var96,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m410_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_404_1 = {&var223,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB2SC01RIM,&var97,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_401_1 = {&var310,&iEM_TERB2SS12LIM,&var98,&vainSBool,&internal1_m401_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_403_1 = {&var305,&iEM_TERB2SS11LIM,&var99,&vainSBool,&internal1_m403_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_402_1 = {&var306,&iEM_TERB2SS21LIM,&var100,&vainSBool,&internal1_m402_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_849_1 = {&var200,&iEM_TERB9SS21LIM,&var101,&vainSBool,&internal1_m849_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_850_1 = {&var199,&iEM_TERB9SS11LIM,&var102,&vainSBool,&internal1_m850_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_848_1 = {&var197,&iEM_TERA9SS21LIM,&var103,&vainSBool,&internal1_m848_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1032_1 = {&var196,&iEM_TERA9SS11LIM,&var104,&vainSBool,&internal1_m1032_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_683_1 = {&var247,&iEM_TERB5SS21LIM,&var105,&vainSBool,&internal1_m683_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_684_1 = {&var246,&iEM_TERB5SS11LIM,&var106,&vainSBool,&internal1_m684_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_681_1 = {&var251,&iEM_TERA5SS21LIM,&var107,&vainSBool,&internal1_m681_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_682_1 = {&var250,&iEM_TERA5SS11LIM,&var108,&vainSBool,&internal1_m682_Out10,&bFirstEnterFlag};
_S_ampl  S_ampl_634_1 = {&var229,&fEM_R7UI75RIM,&var109};
_S_to3val  S_to3val_635_1 = {&var109,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R7UI74RIM,&fEM_R7UI74RIM,&iEM_TERR7SI74RIM,&vainSFloat,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_545_1 = {&var37,&iEM_TERB0VP81LIM,&var110,&vainSBool,&internal1_m545_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_544_1 = {&var37,&iEM_TERA0VP81LIM,&var111,&vainSBool,&internal1_m544_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_830_1 = {&var113,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var112,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m830_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_822_1 = {&var273,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB8SC01RIM,&var113,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_832_1 = {&var115,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var114,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m832_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_824_1 = {&var270,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA8SC01RIM,&var115,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_680_1 = {&R0MW13LP2,&iEM_TERR6IS68LIM,&var116,&vainSBool,&internal1_m680_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_664_1 = {&R0MW13LP2,&iEM_TERR6IS67LIM,&var117,&vainSBool,&internal1_m664_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_644_1 = {&R0MW13LP2,&iEM_TERR6IS66LIM,&var118,&vainSBool,&internal1_m644_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_663_1 = {&R0MW13LP2,&iEM_TERR6IS64LIM,&var119,&var120,&internal1_m663_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_643_1 = {&R0MW13LP2,&iEM_TERR6IS62LIM,&var121,&var122,&internal1_m643_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_331_1 = {&var291,&iEM_TERB3SS22LIM,&var123,&vainSBool,&internal1_m331_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_330_1 = {&var298,&iEM_TERA3SS22LIM,&var124,&vainSBool,&internal1_m330_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_315_1 = {&var292,&iEM_TERB3SS11LIM,&var125,&vainSBool,&internal1_m315_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_314_1 = {&var299,&iEM_TERA3SS11LIM,&var126,&vainSBool,&internal1_m314_Out10,&bFirstEnterFlag};
_S_toao  S_toao_506_1 = {&var128,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var127,&bFirstEnterFlag};
_S_to3val  S_to3val_500_1 = {&var174,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERA3SP02RIM,&vainSFloat,&var128,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_546_1 = {&var36,&iEM_TERA3VP81LIM,&var129,&var130,&internal1_m546_Out10,&bFirstEnterFlag};
_S_toao  S_toao_510_1 = {&var132,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var131,&bFirstEnterFlag};
_S_to3val  S_to3val_503_1 = {&var172,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERB3SP02RIM,&vainSFloat,&var132,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_344_1 = {&var295,&iEM_TERB3SS33LIM,&var133,&vainSBool,&internal1_m344_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_328_1 = {&var135,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var134,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m328_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_327_1 = {&var290,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB3SC01RIM,&var135,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_343_1 = {&var294,&iEM_TERB3SS31LIM,&var136,&vainSBool,&internal1_m343_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_341_1 = {&var302,&iEM_TERA3SS33LIM,&var137,&vainSBool,&internal1_m341_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_318_1 = {&var139,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var138,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m318_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_317_1 = {&var297,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA3SC01RIM,&var139,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_342_1 = {&var301,&iEM_TERA3SS31LIM,&var140,&vainSBool,&internal1_m342_Out10,&bFirstEnterFlag};
_S_toao  S_toao_531_1 = {&var153,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var141,&bFirstEnterFlag};
_S_toao  S_toao_530_1 = {&var151,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var142,&bFirstEnterFlag};
_S_twobool  S_twobool_313_1 = {&var293,&iEM_TERB3SS21LIM,&var143,&vainSBool,&internal1_m313_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_329_1 = {&var300,&iEM_TERA3SS21LIM,&var144,&vainSBool,&internal1_m329_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_422_1 = {&var316,&iEM_TERA2SS33LIM,&var145,&vainSBool,&internal1_m422_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_423_1 = {&var147,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var146,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m423_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_418_1 = {&var222,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA2SC01RIM,&var147,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_421_1 = {&var318,&iEM_TERA2SS12LIM,&var148,&vainSBool,&internal1_m421_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_420_1 = {&var313,&iEM_TERA2SS11LIM,&var149,&vainSBool,&internal1_m420_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_419_1 = {&var314,&iEM_TERA2SS21LIM,&var150,&vainSBool,&internal1_m419_Out10,&bFirstEnterFlag};
_S_to3val  S_to3val_525_1 = {&fEM_A2UP01RIM,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERA2SP01RIM,&var151,&var152,&var153,&bFirstEnterFlag};
_S_toao  S_toao_160_1 = {&var159,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var154,&bFirstEnterFlag};
_S_toao  S_toao_159_1 = {&var158,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var155,&bFirstEnterFlag};
_S_toao  S_toao_158_1 = {&var157,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var156,&bFirstEnterFlag};
_S_to3val  S_to3val_153_1 = {&var285,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERB0MT01RIM,&var157,&var158,&var159,&bFirstEnterFlag};
_S_toao  S_toao_163_1 = {&var167,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var160,&bFirstEnterFlag};
_S_toao  S_toao_162_1 = {&var166,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var161,&bFirstEnterFlag};
_S_twobool  S_twobool_1031_1 = {&var184,&iEM_TERR6SS21LIM,&var162,&vainSBool,&internal1_m1031_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_146_1 = {&var286,&iEM_TERB7MS31LIM,&var163,&vainSBool,&internal1_m146_Out10,&bFirstEnterFlag};
_S_toao  S_toao_161_1 = {&var165,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_3276_,&iRM_16383_,&fRM_1_,&var164,&bFirstEnterFlag};
_S_to3val  S_to3val_155_1 = {&var336,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERA0MT01RIM,&var165,&var166,&var167,&bFirstEnterFlag};
_S_twobool  S_twobool_145_1 = {&var337,&iEM_TERA7MS31LIM,&var168,&vainSBool,&internal1_m145_Out10,&bFirstEnterFlag};
_S_orn  S_orn_901_1 = {array_m901_x_1,&iRM_2_,&var169};
_S_andn  S_andn_896_1 = {array_m896_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_900_1 = {&var169,&var170};
_S_noto  S_noto_498_1 = {&B3AD34LDU,&var171};
_S_lk  S_lk_502_1 = {&fEM_A3UP02RDU,&var171,&var172};
_S_noto  S_noto_496_1 = {&A3AD34LDU,&var173};
_S_lk  S_lk_501_1 = {&fEM_A3UP02RDU,&var173,&var174};
_S_ovb1  S_ovb1_194_1 = {&R8AD21LDU,&iRM_500_,&var175,&internal1_m194_tx};
_S_ovb1  S_ovb1_25_1 = {&R8AD21LDU,&iRM_500_,&var176,&internal1_m25_tx};
_S_andn  S_andn_921_1 = {array_m921_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_926_1 = {&var41,&var177};
_S_andn  S_andn_914_1 = {array_m914_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_917_1 = {&var42,&var178};
_S_andn  S_andn_906_1 = {array_m906_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_910_1 = {&var43,&var179};
_S_orn  S_orn_611_1 = {array_m611_x_1,&iRM_2_,&var180};
_S_orn  S_orn_608_1 = {array_m608_x_1,&iRM_2_,&var181};
_S_react  S_react_197_1 = {&var287,&var182};
_S_noto  S_noto_463_1 = {&lEM_R6AD10LC1,&var183};
_S_asmot  S_asmot_465_1 = {&var183,&lEM_R6AD10LC1,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R6UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R6UC01RSP,&vainSFloat,&var184,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m465_X00,&internal1_m465_V00,&internal1_m465_Pav0,&internal1_m465_Zav0,&internal1_m465_Pv0,&internal1_m465_Zv0,&internal1_m465_RA00,&internal1_m465_RA10,&internal1_m465_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_477_1 = {&var29,&var30,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R5UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R5UC01RSP,&vainSFloat,&var185,&var186,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m477_X00,&internal1_m477_V00,&internal1_m477_Pav0,&internal1_m477_Zav0,&internal1_m477_Pv0,&internal1_m477_Zv0,&internal1_m477_RA00,&internal1_m477_RA10,&internal1_m477_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_467_1 = {&var31,&var32,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R3UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R3UC01RSP,&vainSFloat,&var187,&var188,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m467_X00,&internal1_m467_V00,&internal1_m467_Pav0,&internal1_m467_Zav0,&internal1_m467_Pv0,&internal1_m467_Zv0,&internal1_m467_RA00,&internal1_m467_RA10,&internal1_m467_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_596_1 = {&A4AD10LDU,&var189};
_S_asmot  S_asmot_600_1 = {&var189,&A4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A4MC01RSP,&vainSFloat,&var190,&var191,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m600_X00,&internal1_m600_V00,&internal1_m600_Pav0,&internal1_m600_Zav0,&internal1_m600_Pv0,&internal1_m600_Zv0,&internal1_m600_RA00,&internal1_m600_RA10,&internal1_m600_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_594_1 = {&B4AD10LDU,&var192};
_S_asmot  S_asmot_599_1 = {&var192,&B4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B4MC01RSP,&vainSFloat,&var193,&var194,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m599_X00,&internal1_m599_V00,&internal1_m599_Pav0,&internal1_m599_Zav0,&internal1_m599_Pv0,&internal1_m599_Zv0,&internal1_m599_RA00,&internal1_m599_RA10,&internal1_m599_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_585_1 = {&A9AD10LDU,&var195};
_S_asmot  S_asmot_587_1 = {&var195,&A9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A9MC01RSP,&vainSFloat,&var196,&var197,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m587_X00,&internal1_m587_V00,&internal1_m587_Pav0,&internal1_m587_Zav0,&internal1_m587_Pv0,&internal1_m587_Zv0,&internal1_m587_RA00,&internal1_m587_RA10,&internal1_m587_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_584_1 = {&B9AD10LDU,&var198};
_S_asmot  S_asmot_586_1 = {&var198,&B9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B9MC01RSP,&vainSFloat,&var199,&var200,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m586_X00,&internal1_m586_V00,&internal1_m586_Pav0,&internal1_m586_Zav0,&internal1_m586_Pv0,&internal1_m586_Zv0,&internal1_m586_RA00,&internal1_m586_RA10,&internal1_m586_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orn  S_orn_617_1 = {array_m617_x_1,&iRM_3_,&var201};
_S_andn  S_andn_898_1 = {array_m898_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_903_1 = {&var44,&var202};
_S_andn  S_andn_286_1 = {array_m286_x_1,&iRM_2_,&var203};
_S_andn  S_andn_252_1 = {array_m252_x_1,&iRM_3_,&var204};
_S_noto  S_noto_251_1 = {&C2MD31LP1,&var205};
_S_andn  S_andn_253_1 = {array_m253_x_1,&iRM_3_,&var206};
_S_noto  S_noto_213_1 = {&C1MD31LP2,&var207};
_S_noto  S_noto_212_1 = {&C1MD31LP1,&var208};
_S_andn  S_andn_215_1 = {array_m215_x_1,&iRM_4_,&var209};
_S_andn  S_andn_214_1 = {array_m214_x_1,&iRM_4_,&var210};
_S_andn  S_andn_118_1 = {array_m118_x_1,&iRM_2_,&var211};
_S_noto  S_noto_46_1 = {&C1MD31LP2,&var212};
_S_noto  S_noto_45_1 = {&C1MD31LP1,&var213};
_S_andn  S_andn_48_1 = {array_m48_x_1,&iRM_4_,&var214};
_S_andn  S_andn_47_1 = {array_m47_x_1,&iRM_4_,&var215};
_S_andn  S_andn_85_1 = {array_m85_x_1,&iRM_3_,&var216};
_S_noto  S_noto_84_1 = {&C2MD31LP1,&var217};
_S_andn  S_andn_86_1 = {array_m86_x_1,&iRM_3_,&var218};
_S_noto  S_noto_616_1 = {&var201,&var219};
_S_orn  S_orn_624_1 = {array_m624_x_1,&iRM_2_,&var220};
_S_fsubo  S_fsubo_365_1 = {&fEM_R7UY00RSS,&var40,&var221};
_S_fsubo  S_fsubo_112_1 = {&fEM_A2UC05RIM,&var312,&var222};
_S_fsubo  S_fsubo_279_1 = {&fEM_A2UC05RIM,&var304,&var223};
_S_fsubo  S_fsubo_241_1 = {&fEM_A1UC05RIM,&var320,&var224};
_S_fsubo  S_fsubo_74_1 = {&fEM_A1UC05RIM,&var327,&var225};
_S_fsubo  S_fsubo_8_1 = {&var227,&fEM_R0UR01RIM,&var226};
_S_inf  S_inf_7_1 = {&var273,array_m7_a_1,array_m7_b_1,&iRM_5_,&var227,&vainSInt};
_S_inf  S_inf_9_1 = {&var273,array_m9_a_1,array_m9_b_1,&iRM_7_,&var228,&vainSInt};
_S_mod1  S_mod1_629_1 = {&var288,&fEM_R7UI02RIM,&fEM_R7UL01RIM,&var229,&internal1_m629_y0};
_S_bol  S_bol_623_1 = {&var288,&fEM_R7UI73RIM,&var230};
_S_bol  S_bol_613_1 = {&var288,&fEM_R7UI72RIM,&var231};
_S_bol  S_bol_607_1 = {&var288,&fEM_R7UI71RIM,&var232};
_S_vchs  S_vchs_795_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_5_,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var233,&internal1_m795_Chim0};
_S_vchs  S_vchs_786_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&bRM_4_,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var234,&internal1_m786_Chim0};
_S_vchs  S_vchs_778_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&bRM_1_,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var235,&internal1_m778_Chim0};
_S_vchs  S_vchs_769_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_5_,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var236,&internal1_m769_Chim0};
_S_vchs  S_vchs_760_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&bRM_4_,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var237,&internal1_m760_Chim0};
_S_vchs  S_vchs_752_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&bRM_1_,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var238,&internal1_m752_Chim0};
_S_vchs  S_vchs_743_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_5_,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var239,&internal1_m743_Chim0};
_S_vchs  S_vchs_734_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&bRM_4_,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var240,&internal1_m734_Chim0};
_S_vchs  S_vchs_726_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&bRM_2_,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var241,&internal1_m726_Chim0};
_S_vchs  S_vchs_716_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UC10RIM,&fEM_R7UC19RIM,&bRM_5_,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var242,&internal1_m716_Chim0};
_S_vchs  S_vchs_706_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&bRM_4_,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var243,&internal1_m706_Chim0};
_S_fsumo  S_fsumo_892_1 = {&fEM_R4UC10RIM,&fEM_R4UC22RIM,&var244};
_S_vchs  S_vchs_696_1 = {&var334,&var283,&var244,&fEM_R7UY00RSS,&var221,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&bRM_2_,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var245,&internal1_m696_Chim0};
_S_asmot  S_asmot_574_1 = {&B5AD10LDU,&B5AD20LDU,&fEM_B5MC01RC1,&fEM_B5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL2,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_B5MC01RSP,&vainSFloat,&var246,&var247,&vainSBool,&vainSBool,&vainSFloat,&var248,&var249,&internal1_m574_X00,&internal1_m574_V00,&internal1_m574_Pav0,&internal1_m574_Zav0,&internal1_m574_Pv0,&internal1_m574_Zv0,&internal1_m574_RA00,&internal1_m574_RA10,&internal1_m574_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_560_1 = {&A5AD10LDU,&A5AD20LDU,&fEM_A5MC01RC1,&fEM_A5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL1,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_A5MC01RSP,&vainSFloat,&var250,&var251,&vainSBool,&vainSBool,&vainSFloat,&var252,&var253,&internal1_m560_X00,&internal1_m560_V00,&internal1_m560_Pav0,&internal1_m560_Zav0,&internal1_m560_Pv0,&internal1_m560_Zv0,&internal1_m560_RA00,&internal1_m560_RA10,&internal1_m560_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_451_1 = {&R2AD10LDU,&R2AD20LDU,&fEM_R2MC01RC1,&fEM_R2MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ2,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R2MC01RSP,&vainSFloat,&var254,&var255,&vainSBool,&vainSBool,&vainSFloat,&var256,&var257,&internal1_m451_X00,&internal1_m451_V00,&internal1_m451_Pav0,&internal1_m451_Zav0,&internal1_m451_Pv0,&internal1_m451_Zv0,&internal1_m451_RA00,&internal1_m451_RA10,&internal1_m451_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_437_1 = {&R1AD10LDU,&R1AD20LDU,&fEM_R1MC01RC1,&fEM_R1MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ1,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R1MC01RSP,&vainSFloat,&var258,&var259,&vainSBool,&vainSBool,&vainSFloat,&var260,&var261,&internal1_m437_X00,&internal1_m437_V00,&internal1_m437_Pav0,&internal1_m437_Zav0,&internal1_m437_Pv0,&internal1_m437_Zv0,&internal1_m437_RA00,&internal1_m437_RA10,&internal1_m437_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_488_1 = {&B6AD10LDU,&B6AD20LDU,&fEM_B6MC01RC1,&fEM_B6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ2,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_B6MC01RSP,&vainSFloat,&var262,&var263,&vainSBool,&vainSBool,&vainSFloat,&var264,&var265,&internal1_m488_X00,&internal1_m488_V00,&internal1_m488_Pav0,&internal1_m488_Zav0,&internal1_m488_Pv0,&internal1_m488_Zv0,&internal1_m488_RA00,&internal1_m488_RA10,&internal1_m488_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_389_1 = {&A6AD10LDU,&A6AD20LDU,&fEM_A6MC01RC1,&fEM_A6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ1,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_A6MC01RSP,&vainSFloat,&var266,&var267,&vainSBool,&vainSBool,&vainSFloat,&var268,&var269,&internal1_m389_X00,&internal1_m389_V00,&internal1_m389_Pav0,&internal1_m389_Zav0,&internal1_m389_Pv0,&internal1_m389_Zv0,&internal1_m389_RA00,&internal1_m389_RA10,&internal1_m389_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_374_1 = {&A8AD20LDU,&A8AD10LDU,&fEM_A8MC01RC1,&fEM_A8MV01RC1,&fEM_A8UV80RDU,&fEM_A8US80RDU,&iEM_TERDS2,&fEM_A8UC10RIM,&fEM_A8UC20RIM,&fEM_A8UC11RIM,&fEM_A8UC21RIM,&fEM_A8UC08RDU,&fEM_A8MC01RSP,&var270,&var271,&var272,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m374_X00,&internal1_m374_V00,&internal1_m374_Pav0,&internal1_m374_Zav0,&internal1_m374_Pv0,&internal1_m374_Zv0,&internal1_m374_RA00,&internal1_m374_RA10,&internal1_m374_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_358_1 = {&B8AD20LDU,&B8AD10LDU,&fEM_B8MC01RC1,&fEM_B8MV01RC1,&fEM_B8UV80RDU,&fEM_B8US80RDU,&iEM_TERMAZ2,&fEM_B8UC10RIM,&fEM_B8UC20RIM,&fEM_B8UC11RIM,&fEM_B8UC21RIM,&fEM_B8UC08RDU,&fEM_B8MC01RSP,&var273,&var274,&var275,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m358_X00,&internal1_m358_V00,&internal1_m358_Pav0,&internal1_m358_Zav0,&internal1_m358_Pv0,&internal1_m358_Zv0,&internal1_m358_RA00,&internal1_m358_RA10,&internal1_m358_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_888_1 = {&R4AD10LDU,&R4AD20LDU,&fEM_R4MC01RC1,&fEM_R4MV01RC1,&fEM_R4UV80RDU,&fEM_R4US80RDU,&iEM_TERTLG,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC08RDU,&fEM_R4MC01RSP,&vainSFloat,&var276,&var277,&var278,&var279,&vainSFloat,&var280,&var281,&internal1_m888_X00,&internal1_m888_V00,&internal1_m888_Pav0,&internal1_m888_Zav0,&internal1_m888_Pv0,&internal1_m888_Zv0,&internal1_m888_RA00,&internal1_m888_RA10,&internal1_m888_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_179_1 = {&var319,&var303,&var289,&var333,&fEM_R0UR30RIM,&B7AP31LDU,&var193,&lEM_R8AD10LC1,&var175,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var226,&var228,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_B0UT03RSP,&var282,&var283,&var284,&var285,&var286,&var287,&var288,&internal1_m179_C1,&internal1_m179_C2,&internal1_m179_C3,&internal1_m179_C4,&internal1_m179_C5,&internal1_m179_C6,&internal1_m179_N20,&internal1_m179_N00,&internal1_m179_R00,&internal1_m179_T00,&internal1_m179_ImpINI0,&internal1_m179_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_295_1 = {&B3AD11LDU,&B3AD21LDU,&B3AD02LDU,&B3AD01LDU,&B3AD03LDU,&B3AD04LDU,&B3AD05LDU,&var203,&B3AD33LDU,&lRM_1_,&fEM_B3MC01RC1,&fEM_B3MC02RC1,&fEM_B3MV01RC1,&fEM_B3MV02RC1,&lRM_0_,array_m295_Vr_1,&fEM_A3UC02RDU,&var172,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS2,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_B3MC01RSP,&fEM_B3MC02RSP,&var289,&var290,&var291,&var292,&var293,&vainSFloat,&vainSFloat,&var294,&var295,&vainSBool,&vainSBool,&internal1_m295_X00,&internal1_m295_Sh00,&internal1_m295_RV00,&internal1_m295_ShV00,&internal1_m295_Ppv0,&internal1_m295_Pav0,&internal1_m295_Zav0,&internal1_m295_RA00,&internal1_m295_RA10,&internal1_m295_RA30,&internal1_m295_RA50,&internal1_m295_fls,&internal1_m295_flp,&internal1_m295_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_127_1 = {&A3AD11LDU,&A3AD21LDU,&A3AD02LDU,&A3AD01LDU,&A3AD03LDU,&A3AD04LDU,&A3AD05LDU,&var211,&A3AD33LDU,&lRM_1_,&fEM_A3MC01RC1,&fEM_A3MC02RC1,&fEM_A3MV01RC1,&fEM_A3MV02RC1,&lRM_0_,array_m127_Vr_1,&fEM_A3UC02RDU,&var174,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS1,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_A3MC01RSP,&fEM_A3MC02RSP,&var296,&var297,&var298,&var299,&var300,&vainSFloat,&vainSFloat,&var301,&var302,&vainSBool,&vainSBool,&internal1_m127_X00,&internal1_m127_Sh00,&internal1_m127_RV00,&internal1_m127_ShV00,&internal1_m127_Ppv0,&internal1_m127_Pav0,&internal1_m127_Zav0,&internal1_m127_RA00,&internal1_m127_RA10,&internal1_m127_RA30,&internal1_m127_RA50,&internal1_m127_fls,&internal1_m127_flp,&internal1_m127_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_261_1 = {&B2AD11LDU,&B2AD21LDU,&B2AD02LDU,&B2AD01LDU,&B2AD03LDU,&B2AD04LDU,&B2AD05LDU,&var204,&B2AD33LDU,&var206,&fEM_B2MC01RC1,&fEM_B2MC02RC1,&fEM_B2MV01RC1,&fEM_B2MV02RC1,&lRM_1_,array_m261_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB2,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_B2MC01RSP,&fEM_B2MC02RSP,&var303,&var304,&vainSBool,&var305,&var306,&vainSFloat,&vainSFloat,&var307,&var308,&var309,&var310,&internal1_m261_X00,&internal1_m261_Sh00,&internal1_m261_RV00,&internal1_m261_ShV00,&internal1_m261_Ppv0,&internal1_m261_Pav0,&internal1_m261_Zav0,&internal1_m261_RA00,&internal1_m261_RA10,&internal1_m261_RA30,&internal1_m261_RA50,&internal1_m261_fls,&internal1_m261_flp,&internal1_m261_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_94_1 = {&A2AD11LDU,&A2AD21LDU,&A2AD02LDU,&A2AD01LDU,&A2AD03LDU,&A2AD04LDU,&A2AD05LDU,&var216,&A2AD33LDU,&var218,&fEM_A2MC01RC1,&fEM_A2MC02RC1,&fEM_A2MV01RC1,&fEM_A2MV02RC1,&lRM_1_,array_m94_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB1,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_A2MC01RSP,&fEM_A2MC02RSP,&var311,&var312,&vainSBool,&var313,&var314,&vainSFloat,&vainSFloat,&var315,&var316,&var317,&var318,&internal1_m94_X00,&internal1_m94_Sh00,&internal1_m94_RV00,&internal1_m94_ShV00,&internal1_m94_Ppv0,&internal1_m94_Pav0,&internal1_m94_Zav0,&internal1_m94_RA00,&internal1_m94_RA10,&internal1_m94_RA30,&internal1_m94_RA50,&internal1_m94_fls,&internal1_m94_flp,&internal1_m94_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_229_1 = {&B1AD11LDU,&B1AD21LDU,&B1AD02LDU,&B1AD01LDU,&B1AD03LDU,&B1AD04LDU,&B1AD05LDU,&var210,&lRM_1_,&var209,&fEM_B1MC01RC1,&fEM_B1MC02RC1,&fEM_B1MV01RC1,&fEM_B1MV02RC1,&lRM_1_,array_m229_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB2,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_B1MC01RSP,&fEM_B1MC02RSP,&var319,&var320,&vainSBool,&var321,&var322,&vainSFloat,&vainSFloat,&var323,&vainSBool,&var324,&var325,&internal1_m229_X00,&internal1_m229_Sh00,&internal1_m229_RV00,&internal1_m229_ShV00,&internal1_m229_Ppv0,&internal1_m229_Pav0,&internal1_m229_Zav0,&internal1_m229_RA00,&internal1_m229_RA10,&internal1_m229_RA30,&internal1_m229_RA50,&internal1_m229_fls,&internal1_m229_flp,&internal1_m229_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_61_1 = {&A1AD11LDU,&A1AD21LDU,&A1AD02LDU,&A1AD01LDU,&A1AD03LDU,&A1AD04LDU,&A1AD05LDU,&var215,&lRM_1_,&var214,&fEM_A1MC01RC1,&fEM_A1MC02RC1,&fEM_A1MV01RC1,&fEM_A1MV02RC1,&lRM_1_,array_m61_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB1,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_A1MC01RSP,&fEM_A1MC02RSP,&var326,&var327,&var328,&var329,&var330,&vainSFloat,&vainSFloat,&vainSBool,&vainSBool,&var331,&var332,&internal1_m61_X00,&internal1_m61_Sh00,&internal1_m61_RV00,&internal1_m61_ShV00,&internal1_m61_Ppv0,&internal1_m61_Pav0,&internal1_m61_Zav0,&internal1_m61_RA00,&internal1_m61_RA10,&internal1_m61_RA30,&internal1_m61_RA50,&internal1_m61_fls,&internal1_m61_flp,&internal1_m61_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_14_1 = {&var326,&var311,&var296,&var282,&fEM_R0UR30RIM,&A7AP31LDU,&var190,&lEM_R8AD10LC1,&var176,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var226,&var228,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_A0UT03RSP,&var333,&var334,&var335,&var336,&var337,&var338,&vainSFloat,&internal1_m14_C1,&internal1_m14_C2,&internal1_m14_C3,&internal1_m14_C4,&internal1_m14_C5,&internal1_m14_C6,&internal1_m14_N20,&internal1_m14_N00,&internal1_m14_R00,&internal1_m14_T00,&internal1_m14_ImpINI0,&internal1_m14_MyFirstEnterFlag,&bFirstEnterFlag};


void ZeroVar()
{
   var1.b=0;
   var2.f=0.0;
   var3.f=0.0;
   var4.f=0.0;
   var5.f=0.0;
   var6.f=0.0;
   var7.f=0.0;
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
   var40.f=0.0;
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
   var54.l=0L;
   var55.f=0.0;
   var56.l=0L;
   var57.f=0.0;
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
   var92.i=0;
   var93.i=0;
   var94.f=0.0;
   var95.f=0.0;
   var96.l=0L;
   var97.f=0.0;
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
   var109.f=0.0;
   var110.b=0;
   var111.b=0;
   var112.l=0L;
   var113.f=0.0;
   var114.l=0L;
   var115.f=0.0;
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
   var127.i=0;
   var128.f=0.0;
   var129.b=0;
   var130.b=0;
   var131.i=0;
   var132.f=0.0;
   var133.b=0;
   var134.l=0L;
   var135.f=0.0;
   var136.b=0;
   var137.b=0;
   var138.l=0L;
   var139.f=0.0;
   var140.b=0;
   var141.i=0;
   var142.i=0;
   var143.b=0;
   var144.b=0;
   var145.b=0;
   var146.l=0L;
   var147.f=0.0;
   var148.b=0;
   var149.b=0;
   var150.b=0;
   var151.f=0.0;
   var152.f=0.0;
   var153.f=0.0;
   var154.i=0;
   var155.i=0;
   var156.i=0;
   var157.f=0.0;
   var158.f=0.0;
   var159.f=0.0;
   var160.i=0;
   var161.i=0;
   var162.b=0;
   var163.b=0;
   var164.i=0;
   var165.f=0.0;
   var166.f=0.0;
   var167.f=0.0;
   var168.b=0;
   var169.b=0;
   var170.b=0;
   var171.b=0;
   var172.f=0.0;
   var173.b=0;
   var174.f=0.0;
   var175.b=0;
   var176.b=0;
   var177.b=0;
   var178.b=0;
   var179.b=0;
   var180.b=0;
   var181.b=0;
   var182.f=0.0;
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
   var221.f=0.0;
   var222.f=0.0;
   var223.f=0.0;
   var224.f=0.0;
   var225.f=0.0;
   var226.f=0.0;
   var227.f=0.0;
   var228.f=0.0;
   var229.f=0.0;
   var230.b=0;
   var231.b=0;
   var232.b=0;
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
   var245.f=0.0;
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
   var270.f=0.0;
   var271.b=0;
   var272.b=0;
   var273.f=0.0;
   var274.b=0;
   var275.b=0;
   var276.b=0;
   var277.b=0;
   var278.b=0;
   var279.b=0;
   var280.b=0;
   var281.b=0;
   var282.f=0.0;
   var283.f=0.0;
   var284.f=0.0;
   var285.f=0.0;
   var286.b=0;
   var287.f=0.0;
   var288.f=0.0;
   var289.f=0.0;
   var290.f=0.0;
   var291.b=0;
   var292.b=0;
   var293.b=0;
   var294.b=0;
   var295.b=0;
   var296.f=0.0;
   var297.f=0.0;
   var298.b=0;
   var299.b=0;
   var300.b=0;
   var301.b=0;
   var302.b=0;
   var303.f=0.0;
   var304.f=0.0;
   var305.b=0;
   var306.b=0;
   var307.b=0;
   var308.b=0;
   var309.b=0;
   var310.b=0;
   var311.f=0.0;
   var312.f=0.0;
   var313.b=0;
   var314.b=0;
   var315.b=0;
   var316.b=0;
   var317.b=0;
   var318.b=0;
   var319.f=0.0;
   var320.f=0.0;
   var321.b=0;
   var322.b=0;
   var323.b=0;
   var324.b=0;
   var325.b=0;
   var326.f=0.0;
   var327.f=0.0;
   var328.b=0;
   var329.b=0;
   var330.b=0;
   var331.b=0;
   var332.b=0;
   var333.f=0.0;
   var334.f=0.0;
   var335.f=0.0;
   var336.f=0.0;
   var337.b=0;
   var338.f=0.0;
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
  noto(&S_noto_84_1);
  noto(&S_noto_251_1);
  noto(&S_noto_584_1);
  noto(&S_noto_585_1);
  ovb1(&S_ovb1_25_1);
  ovb1(&S_ovb1_194_1);
  noto(&S_noto_498_1);
  bol(&S_bol_924_1);
  bol(&S_bol_934_1);
  bol(&S_bol_912_1);
  bol(&S_bol_933_1);
  bol(&S_bol_936_1);
  zpfs(&S_zpfs_609_1);
  zpfs(&S_zpfs_621_1);
  noto(&S_noto_468_1);
  noto(&S_noto_466_1);
  noto(&S_noto_476_1);
  noto(&S_noto_475_1);
  to3val(&S_to3val_950_1);
  looktakt(&S_looktakt_144_1);
  asmot(&S_asmot_888_1);
  asmot(&S_asmot_358_1);
  asmot(&S_asmot_374_1);
  asmot(&S_asmot_389_1);
  asmot(&S_asmot_488_1);
  asmot(&S_asmot_437_1);
  asmot(&S_asmot_451_1);
  asmot(&S_asmot_560_1);
  asmot(&S_asmot_574_1);
  fsumo(&S_fsumo_892_1);
  inf(&S_inf_9_1);
  inf(&S_inf_7_1);
  fsubo(&S_fsubo_8_1);
  noto(&S_noto_45_1);
  noto(&S_noto_46_1);
  noto(&S_noto_212_1);
  noto(&S_noto_213_1);
  orn(&S_orn_617_1);
  asmot(&S_asmot_586_1);
  asmot(&S_asmot_587_1);
  noto(&S_noto_594_1);
  noto(&S_noto_596_1);
  noto(&S_noto_463_1);
  noto(&S_noto_496_1);
  lk(&S_lk_502_1);
  orn(&S_orn_901_1);
  to3val(&S_to3val_525_1);
  toao(&S_toao_530_1);
  toao(&S_toao_531_1);
  to3val(&S_to3val_503_1);
  toao(&S_toao_510_1);
  twobool(&S_twobool_546_1);
  twobool(&S_twobool_643_1);
  twobool(&S_twobool_663_1);
  twobool(&S_twobool_644_1);
  twobool(&S_twobool_664_1);
  twobool(&S_twobool_680_1);
  to3val(&S_to3val_824_1);
  ktoenc(&S_ktoenc_832_1);
  to3val(&S_to3val_822_1);
  ktoenc(&S_ktoenc_830_1);
  twobool(&S_twobool_544_1);
  twobool(&S_twobool_545_1);
  twobool(&S_twobool_682_1);
  twobool(&S_twobool_681_1);
  twobool(&S_twobool_684_1);
  twobool(&S_twobool_683_1);
  twobool(&S_twobool_1032_1);
  twobool(&S_twobool_848_1);
  twobool(&S_twobool_850_1);
  twobool(&S_twobool_849_1);
  to3val(&S_to3val_526_1);
  toao(&S_toao_532_1);
  toao(&S_toao_533_1);
  twobool(&S_twobool_529_1);
  twobool(&S_twobool_976_1);
  twobool(&S_twobool_991_1);
  twobool(&S_twobool_1008_1);
  twobool(&S_twobool_1030_1);
  twobool(&S_twobool_811_1);
  twobool(&S_twobool_977_1);
  twobool(&S_twobool_978_1);
  twobool(&S_twobool_979_1);
  twobool(&S_twobool_980_1);
  twobool(&S_twobool_1028_1);
  twobool(&S_twobool_807_1);
  twobool(&S_twobool_808_1);
  twobool(&S_twobool_810_1);
  twobool(&S_twobool_809_1);
  twobool(&S_twobool_835_1);
  twobool(&S_twobool_833_1);
  twobool(&S_twobool_836_1);
  twobool(&S_twobool_834_1);
  twobool(&S_twobool_1012_1);
  twobool(&S_twobool_1013_1);
  twobool(&S_twobool_1014_1);
  twobool(&S_twobool_1033_1);
  twobool(&S_twobool_56_1);
  twobool(&S_twobool_41_1);
  twobool(&S_twobool_222_1);
  twobool(&S_twobool_205_1);
  zpfs(&S_zpfs_595_1);
  zpfs(&S_zpfs_597_1);
  or2(&S_or2_902_1);
  or2(&S_or2_909_1);
  or2(&S_or2_916_1);
  or2(&S_or2_925_1);
  ampl(&S_ampl_363_1);
  rs(&S_rs_462_1);
  rs(&S_rs_461_1);
  rs(&S_rs_474_1);
  rs(&S_rs_473_1);
  twobool(&S_twobool_528_1);
  twobool(&S_twobool_512_1);
  twobool(&S_twobool_645_1);
  twobool(&S_twobool_646_1);
  twobool(&S_twobool_667_1);
  twobool(&S_twobool_668_1);
  twobool(&S_twobool_647_1);
  twobool(&S_twobool_648_1);
  twobool(&S_twobool_669_1);
  twobool(&S_twobool_670_1);
  twobool(&S_twobool_992_1);
  twobool(&S_twobool_993_1);
  twobool(&S_twobool_994_1);
  twobool(&S_twobool_995_1);
  twobool(&S_twobool_812_1);
  twobool(&S_twobool_813_1);
  fsubo(&S_fsubo_365_1);
  noto(&S_noto_616_1);
  andn(&S_andn_86_1);
  andn(&S_andn_85_1);
  andn(&S_andn_47_1);
  andn(&S_andn_48_1);
  andn(&S_andn_118_1);
  andn(&S_andn_214_1);
  andn(&S_andn_215_1);
  andn(&S_andn_253_1);
  andn(&S_andn_252_1);
  andn(&S_andn_286_1);
  noto(&S_noto_903_1);
  andn(&S_andn_898_1);
  asmot(&S_asmot_599_1);
  asmot(&S_asmot_600_1);
  asmot(&S_asmot_467_1);
  asmot(&S_asmot_477_1);
  asmot(&S_asmot_465_1);
  noto(&S_noto_910_1);
  andn(&S_andn_906_1);
  noto(&S_noto_917_1);
  andn(&S_andn_914_1);
  noto(&S_noto_926_1);
  andn(&S_andn_921_1);
  lk(&S_lk_501_1);
  noto(&S_noto_900_1);
  andn(&S_andn_896_1);
  twobool(&S_twobool_1031_1);
  to3val(&S_to3val_500_1);
  toao(&S_toao_506_1);
  twobool(&S_twobool_1009_1);
  twobool(&S_twobool_1011_1);
  twobool(&S_twobool_1010_1);
  twobool(&S_twobool_1029_1);
  orrsim(&S_orrsim_61_1);
  orrsim(&S_orrsim_229_1);
  orrsim(&S_orrsim_94_1);
  orrsim(&S_orrsim_261_1);
  orrsim(&S_orrsim_127_1);
  orrsim(&S_orrsim_295_1);
  azbars(&S_azbars_179_1);
  bol(&S_bol_607_1);
  bol(&S_bol_613_1);
  bol(&S_bol_623_1);
  mod1(&S_mod1_629_1);
  fsubo(&S_fsubo_74_1);
  fsubo(&S_fsubo_241_1);
  fsubo(&S_fsubo_279_1);
  fsubo(&S_fsubo_112_1);
  orn(&S_orn_624_1);
  react(&S_react_197_1);
  orn(&S_orn_608_1);
  orn(&S_orn_611_1);
  twobool(&S_twobool_146_1);
  to3val(&S_to3val_153_1);
  toao(&S_toao_158_1);
  toao(&S_toao_159_1);
  toao(&S_toao_160_1);
  twobool(&S_twobool_419_1);
  twobool(&S_twobool_420_1);
  twobool(&S_twobool_421_1);
  to3val(&S_to3val_418_1);
  ktoenc(&S_ktoenc_423_1);
  twobool(&S_twobool_422_1);
  twobool(&S_twobool_329_1);
  twobool(&S_twobool_313_1);
  twobool(&S_twobool_342_1);
  to3val(&S_to3val_317_1);
  ktoenc(&S_ktoenc_318_1);
  twobool(&S_twobool_341_1);
  twobool(&S_twobool_343_1);
  to3val(&S_to3val_327_1);
  ktoenc(&S_ktoenc_328_1);
  twobool(&S_twobool_344_1);
  twobool(&S_twobool_314_1);
  twobool(&S_twobool_315_1);
  twobool(&S_twobool_330_1);
  twobool(&S_twobool_331_1);
  ampl(&S_ampl_634_1);
  twobool(&S_twobool_402_1);
  twobool(&S_twobool_403_1);
  twobool(&S_twobool_401_1);
  to3val(&S_to3val_404_1);
  ktoenc(&S_ktoenc_410_1);
  twobool(&S_twobool_945_1);
  twobool(&S_twobool_946_1);
  twobool(&S_twobool_949_1);
  to3val(&S_to3val_941_1);
  ktoenc(&S_ktoenc_948_1);
  to3val(&S_to3val_960_1);
  ktoenc(&S_ktoenc_965_1);
  twobool(&S_twobool_962_1);
  twobool(&S_twobool_963_1);
  twobool(&S_twobool_966_1);
  andn(&S_andn_349_1);
  twobool(&S_twobool_400_1);
  ifelse(&S_ifelse_708_1);
  azbars(&S_azbars_14_1);
  vchs(&S_vchs_696_1);
  vchs(&S_vchs_706_1);
  vchs(&S_vchs_716_1);
  vchs(&S_vchs_726_1);
  vchs(&S_vchs_734_1);
  vchs(&S_vchs_743_1);
  vchs(&S_vchs_752_1);
  vchs(&S_vchs_760_1);
  vchs(&S_vchs_769_1);
  vchs(&S_vchs_778_1);
  vchs(&S_vchs_786_1);
  vchs(&S_vchs_795_1);
  twobool(&S_twobool_145_1);
  to3val(&S_to3val_155_1);
  toao(&S_toao_161_1);
  toao(&S_toao_162_1);
  toao(&S_toao_163_1);
  to3val(&S_to3val_635_1);
  vchs(&S_vchs_858_1);
  vchs(&S_vchs_866_1);
  vchs(&S_vchs_876_1);
  setData(idifelse,&var1);
  setData(idLTAKTS,&var2);
  setData(idkrb2,&var303);
  setData(idkrb1,&var311);
  setData(idR0IS01FI0,&lRM_1_);
  setData(idA0IT03IRP,&var160);
  setData(idB0IT03IRP,&var154);
  setData(idR0IN03FI3,&var236);
  setData(idR0IN02FI3,&var237);
  setData(idR0IN03FI2,&var239);
  setData(idR0IN07RIP,&var4);
  setData(idR0IN06RIP,&var3);
  setData(idR0IN03RIP,&var5);
  setData(idR0IN02RIP,&var6);
  setData(idR0IN01RIP,&var7);
  setData(idR0IN02FI2,&var240);
  setData(idR0IN03FI1,&var242);
  setData(idR0IN02FI1,&var243);
  setData(idR0IN03FI4,&var233);
  setData(idR0IN02FI4,&var234);
  setData(idR0IN01FI3,&var238);
  setData(idR0IN01FI2,&var241);
  setData(idR0IN01FI4,&var235);
  setData(idR0IN01FI1,&var245);
  setData(idR4VS12LDU,&var9);
  setData(idR4VS22LDU,&var8);
  setData(idR1VS12LDU,&var13);
  setData(idR2VS12LDU,&var11);
  setData(idR2VS22LDU,&var10);
  setData(idR1VS22LDU,&var12);
  setData(idB5VS12LDU,&var15);
  setData(idB5VS22LDU,&var14);
  setData(idA5VS12LDU,&var17);
  setData(idA5VS22LDU,&var16);
  setData(idB6VS12LDU,&var19);
  setData(idB6VS22LDU,&var18);
  setData(idA6VS12LDU,&var21);
  setData(idA6VS22LDU,&var20);
  setData(idB8IS21LDU,&var69);
  setData(idB8IS11LDU,&var67);
  setData(idA1VP81LZZ,&var22);
  setData(idB1VP81LZZ,&var23);
  setData(idB2IS33LDU,&var24);
  setData(idA0VN01RIM,&var338);
  setData(idB2IS32LIM,&var307);
  setData(idB2IS11LIM,&var309);
  setData(idA2IS32LIM,&var315);
  setData(idA2IS11LIM,&var317);
  setData(idB1IS32LIM,&var323);
  setData(idB1IS11LIM,&var324);
  setData(idA1IS32LIM,&var328);
  setData(idA1IS11LIM,&var331);
  setData(idR0IS02LDU,&lEM_R0IE02LRP);
  setData(idB4IS10LDU,&var46);
  setData(idA4IS10LDU,&var45);
  setData(idB1IE04LDU,&var47);
  setData(idB1IE03LDU,&var48);
  setData(idA1IE04LDU,&var49);
  setData(idA1IE03LDU,&var50);
  setData(idB1IS12LDU,&var51);
  setData(idB1IS11LDU,&var52);
  setData(idB1IS21LDU,&var53);
  setData(idB1IC01UDU,&var54);
  setData(idA1IC01UDU,&var56);
  setData(idA1IS12LDU,&var58);
  setData(idA1IS11LDU,&var59);
  setData(idA1IS21LDU,&var60);
  setData(idB6IS21LDU,&var61);
  setData(idB6IS11LDU,&var62);
  setData(idA6IS21LDU,&var63);
  setData(idA6IS11LDU,&var64);
  setData(idA8IS12LDU,&var65);
  setData(idA8IS22LDU,&var66);
  setData(idB8IS12LDU,&var68);
  setData(idB8IS22LDU,&var70);
  setData(idR4IS12LDU,&var71);
  setData(idR4IS22LDU,&var72);
  setData(idR4IS21LDU,&var73);
  setData(idR4IS11LDU,&var74);
  setData(idB4VP82LDU,&var76);
  setData(idA4VP82LDU,&var75);
  setData(idR2IS21LDU,&var77);
  setData(idR2IS11LDU,&var78);
  setData(idR1IS21LDU,&var79);
  setData(idR1IS11LDU,&var80);
  setData(idB4IS21LDU,&var81);
  setData(idB4IS11LDU,&var82);
  setData(idR8IS11LDU,&var83);
  setData(idA4IS21LDU,&var84);
  setData(idA4IS11LDU,&var85);
  setData(idR5IS21LDU,&var86);
  setData(idR5IS11LDU,&var87);
  setData(idR3IS21LDU,&var88);
  setData(idR3IS11LDU,&var89);
  setData(idB2VP82LDU,&var90);
  setData(idB2IP01IZ2,&var92);
  setData(idB2IP01IZ1,&var93);
  setData(idB2IC01UDU,&var96);
  setData(idB2IS12LDU,&var98);
  setData(idB2IS11LDU,&var99);
  setData(idB2IS21LDU,&var100);
  setData(idB9IS21LDU,&var101);
  setData(idB9IS11LDU,&var102);
  setData(idA9IS21LDU,&var103);
  setData(idA9IS11LDU,&var104);
  setData(idB5IS21LDU,&var105);
  setData(idB5IS11LDU,&var106);
  setData(idA5IS21LDU,&var107);
  setData(idA5IS11LDU,&var108);
  setData(idB0VP81LZZ,&var110);
  setData(idA0VP81LZZ,&var111);
  setData(idB8IC01UDU,&var112);
  setData(idA8IC01UDU,&var114);
  setData(idR6IS68LZZ,&var116);
  setData(idR6IS67LZZ,&var117);
  setData(idR6IS66LZZ,&var118);
  setData(idR6IS65LDU,&var120);
  setData(idR6IS64LDU,&var119);
  setData(idR6IS63LDU,&var122);
  setData(idR6IS62LDU,&var121);
  setData(idB3IS22LDU,&var123);
  setData(idA3IS22LDU,&var124);
  setData(idB3IS11LDU,&var125);
  setData(idA3IS11LDU,&var126);
  setData(idA3IP02IDU,&var127);
  setData(idB3VP81LDU,&var130);
  setData(idA3VP81LDU,&var129);
  setData(idB3IS33LDU,&var133);
  setData(idB3IC01UDU,&var134);
  setData(idB3IS31LDU,&var136);
  setData(idB3IP02IDU,&var131);
  setData(idA3IS33LDU,&var137);
  setData(idA3IC01UDU,&var138);
  setData(idA3IS31LDU,&var140);
  setData(idA2VP82LDU,&var91);
  setData(idA2IP01IZ2,&var141);
  setData(idA2IP01IZ1,&var142);
  setData(idB3IS21LDU,&var143);
  setData(idA3IS21LDU,&var144);
  setData(idA2IS33LDU,&var145);
  setData(idA2IC01UDU,&var146);
  setData(idA2IS12LDU,&var148);
  setData(idA2IS11LDU,&var149);
  setData(idA2IS21LDU,&var150);
  setData(idB0IT02IZ2,&var155);
  setData(idB0IT01IZ1,&var156);
  setData(idA0IT02IZ2,&var161);
  setData(idA0IT01IZ1,&var164);
  setData(idR6IS21LDU,&var162);
  setData(idB7AS31LDU,&var163);
  setData(idA7AS31LDU,&var168);
  setData(idB3IS35LDU,&var171);
  setData(idA3IS35LDU,&var173);
  setData(idR7II73LZ2,&var220);
  setData(idR7II71LZ2,&var181);
  setData(idR7II72LZ2,&var180);
  setData(idR7II72LZ1,&var180);
  setData(idR7II71LZ1,&var181);
  setData(idR7II73LZ1,&var220);
  setData(idR0SR01RIM,&var182);
  setData(idR0ST01RIM,&var287);
  setData(idR0SR02RIM,&var288);
  setData(idR0CR02RIM,&var226);
  setData(idR0CR01RIM,&var228);
  setData(idB0SN08RIM,&var283);
  setData(idA0SN08RIM,&var334);
  setData(idB0SR01RIM,&var284);
  setData(idA0SR01RIM,&var335);

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
