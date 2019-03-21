#ifndef SCM_H
#define SCM_H
// Подсистема scm:SCM
static char SimulOn=0;
static short CodeSub=1;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=20;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 3287
static char BUFFER[3287];
#define A1IS21LDU	 BUFFER[0]	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define idA1IS21LDU	 1	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define B6IS21LDU	 BUFFER[2]	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define idB6IS21LDU	 2	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define B6IS11LDU	 BUFFER[4]	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define idB6IS11LDU	 3	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define A6IS21LDU	 BUFFER[6]	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define idA6IS21LDU	 4	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define A6IS11LDU	 BUFFER[8]	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define idA6IS11LDU	 5	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define A8IS12LDU	 BUFFER[10]	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define idA8IS12LDU	 6	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define A8IS22LDU	 BUFFER[12]	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define idA8IS22LDU	 7	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define B8IS12LDU	 BUFFER[14]	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 8	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define B8IS22LDU	 BUFFER[16]	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define idB8IS22LDU	 9	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define R4IS12LDU	 BUFFER[18]	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define idR4IS12LDU	 10	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define R4IS22LDU	 BUFFER[20]	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define idR4IS22LDU	 11	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define R4IS21LDU	 BUFFER[22]	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define idR4IS21LDU	 12	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define R4IS11LDU	 BUFFER[24]	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define idR4IS11LDU	 13	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define B4VP82LDU	 BUFFER[26]	//( - , SCM) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 14	//( - , SCM) Давление ПОДЪЁМ НИ2 в норме
#define A4VP82LDU	 BUFFER[28]	//( - , SCM) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 15	//( - , SCM) Давление ПОДЪЁМ НИ1 в норме
#define R2IS21LDU	 BUFFER[30]	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define idR2IS21LDU	 16	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define R2IS11LDU	 BUFFER[32]	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define idR2IS11LDU	 17	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define R0EE03LZ1	 BUFFER[34]	//( - , SBz1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 18	//( - , SBz1) Питание  АКНП3  отключить
#define R0EE02LZ1	 BUFFER[36]	//( - , SBz1) Питание  АКНП  отключить
#define idR0EE02LZ1	 19	//( - , SBz1) Питание  АКНП  отключить
#define R0EE01LZ2	 BUFFER[38]	//( - , SBz2) Питание  АКНП1  отключить
#define idR0EE01LZ2	 20	//( - , SBz2) Питание  АКНП1  отключить
#define R0EE01LZ1	 BUFFER[40]	//( - , SBz1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 21	//( - , SBz1) Питание  АКНП1  отключить
#define B4IS10LDU	 BUFFER[42]	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define idB4IS10LDU	 22	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define A4IS10LDU	 BUFFER[44]	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define idA4IS10LDU	 23	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define B1IE04LDU	 BUFFER[46]	//( - , SCM) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 24	//( - , SCM) Движение ББ2 назад (от БУШД)
#define B1IE03LDU	 BUFFER[48]	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 25	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[50]	//( - , SCM) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 26	//( - , SCM) Движение ББ1 назад (от БУШД)
#define A1IE03LDU	 BUFFER[52]	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 27	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define B1IS12LDU	 BUFFER[54]	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define idB1IS12LDU	 28	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define B1IS11LDU	 BUFFER[56]	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define idB1IS11LDU	 29	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define B1IS21LDU	 BUFFER[58]	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define idB1IS21LDU	 30	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define B1IC01UDU	 BUFFER[60]	//( - , SDu) Координата штока ББ2
#define idB1IC01UDU	 31	//( - , SDu) Координата штока ББ2
#define A1IC01UDU	 BUFFER[65]	//( - , SDu) Координата штока ББ1
#define idA1IC01UDU	 32	//( - , SDu) Координата штока ББ1
#define A1IS12LDU	 BUFFER[70]	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define idA1IS12LDU	 33	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define A1IS11LDU	 BUFFER[72]	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define idA1IS11LDU	 34	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define B9IS21LDU	 BUFFER[74]	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 35	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define B9IS11LDU	 BUFFER[76]	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 36	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define A9IS21LDU	 BUFFER[78]	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 37	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define A9IS11LDU	 BUFFER[80]	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 38	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define B5IS21LDU	 BUFFER[82]	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define idB5IS21LDU	 39	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define B5IS11LDU	 BUFFER[84]	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define idB5IS11LDU	 40	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define A5IS21LDU	 BUFFER[86]	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define idA5IS21LDU	 41	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define A5IS11LDU	 BUFFER[88]	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define idA5IS11LDU	 42	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define B0VP81LZZ	 BUFFER[90]	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 43	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define A0VP81LZZ	 BUFFER[92]	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
#define idA0VP81LZZ	 44	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
#define B8IC01UDU	 BUFFER[94]	//( - , SDu) Координата АЗ2
#define idB8IC01UDU	 45	//( - , SDu) Координата АЗ2
#define A8IC01UDU	 BUFFER[99]	//( - , SDu) Координата ДС2
#define idA8IC01UDU	 46	//( - , SDu) Координата ДС2
#define R6IS68LZZ	 BUFFER[104]	//(do32_pti:100 - K19DO, - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 47	//(do32_pti:100 - K19DO, - ) Исправность ВИП 4,0 (№7) ССДИ-2
#define R6IS67LZZ	 BUFFER[106]	//(do32_pti:100 - K18DO, - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 48	//(do32_pti:100 - K18DO, - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS66LZZ	 BUFFER[108]	//(do32_pti:100 - K17DO, - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 49	//(do32_pti:100 - K17DO, - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS65LDU	 BUFFER[110]	//(do32_pti:160 - K32DO, - ) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 50	//(do32_pti:160 - K32DO, - ) Исправность ВИП ССДИ-35 2канал
#define R6IS64LDU	 BUFFER[112]	//(do32_pti:160 - K31DO, - ) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 51	//(do32_pti:160 - K31DO, - ) Исправность ВИП ССДИ-35 1канал
#define R1IS21LDU	 BUFFER[114]	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define idR1IS21LDU	 52	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define R1IS11LDU	 BUFFER[116]	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define idR1IS11LDU	 53	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define B4IS21LDU	 BUFFER[118]	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define idB4IS21LDU	 54	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define B4IS11LDU	 BUFFER[120]	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define idB4IS11LDU	 55	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define R8IS11LDU	 BUFFER[122]	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define idR8IS11LDU	 56	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define A4IS21LDU	 BUFFER[124]	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define idA4IS21LDU	 57	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define A4IS11LDU	 BUFFER[126]	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define idA4IS11LDU	 58	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define R5IS21LDU	 BUFFER[128]	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 59	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define R5IS11LDU	 BUFFER[130]	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 60	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define R3IS21LDU	 BUFFER[132]	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 61	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define R3IS11LDU	 BUFFER[134]	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 62	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define B2VP82LDU	 BUFFER[136]	//( - , SCM) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 63	//( - , SCM) Давление ПОДЪЁМ РБ2 в норме
#define B2IP01IZ2	 BUFFER[138]	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 64	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define B2IP01IZ1	 BUFFER[141]	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 65	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define B2IC01UDU	 BUFFER[144]	//( - , SDu) Координата штока РБ2
#define idB2IC01UDU	 66	//( - , SDu) Координата штока РБ2
#define B2IS12LDU	 BUFFER[149]	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 67	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define B2IS11LDU	 BUFFER[151]	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define idB2IS11LDU	 68	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define B2IS21LDU	 BUFFER[153]	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define idB2IS21LDU	 69	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define R0IN03FI2	 BUFFER[155]	//( - , SA2) Выход КНК53М Гц от ПТИ
#define idR0IN03FI2	 70	//( - , SA2) Выход КНК53М Гц от ПТИ
#define R0IN07RIP	 BUFFER[160]	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define idR0IN07RIP	 71	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define R0IN06RIP	 BUFFER[165]	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define idR0IN06RIP	 72	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define TerR0IN06FRP	 BUFFER[170]	//( - , - ) Неисправности СНМ-11 -1,2
#define idTerR0IN06FRP	 73	//( - , - ) Неисправности СНМ-11 -1,2
#define R0IN03RIP	 BUFFER[173]	//( - , SRP) Выход КНК53М Гц от ПТИ
#define idR0IN03RIP	 74	//( - , SRP) Выход КНК53М Гц от ПТИ
#define R0IN02RIP	 BUFFER[178]	//( - , SRP) Выход КНК15- Гц от ПТИ
#define idR0IN02RIP	 75	//( - , SRP) Выход КНК15- Гц от ПТИ
#define R0IN01RIP	 BUFFER[183]	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define idR0IN01RIP	 76	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define R0IN02FI2	 BUFFER[188]	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI2	 77	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI1	 BUFFER[193]	//( - , SA1) Выход КНК53М Гц от ПТИ
#define idR0IN03FI1	 78	//( - , SA1) Выход КНК53М Гц от ПТИ
#define R0IN02FI1	 BUFFER[198]	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI1	 79	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI4	 BUFFER[203]	//( - , SA4) Выход КНК53М Гц от ПТИ
#define idR0IN03FI4	 80	//( - , SA4) Выход КНК53М Гц от ПТИ
#define R0IN02FI4	 BUFFER[208]	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI4	 81	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define R0IN01FI3	 BUFFER[213]	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI3	 82	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI2	 BUFFER[218]	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN01FI2	 83	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define R0IN01FI4	 BUFFER[223]	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI4	 84	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI1	 BUFFER[228]	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN01FI1	 85	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define B7AP31LDU	 BUFFER[233]	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define idB7AP31LDU	 86	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define B0SN07RIM	 BUFFER[235]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define idB0SN07RIM	 87	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define B0SN06RIM	 BUFFER[240]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define idB0SN06RIM	 88	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define B0SN05RIM	 BUFFER[245]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define idB0SN05RIM	 89	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define B0SN04RIM	 BUFFER[250]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define idB0SN04RIM	 90	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define B0SN03RIM	 BUFFER[255]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define idB0SN03RIM	 91	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define B0SN02RIM	 BUFFER[260]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define idB0SN02RIM	 92	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define A0SN07RIM	 BUFFER[265]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define idA0SN07RIM	 93	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define A0SN06RIM	 BUFFER[270]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define idA0SN06RIM	 94	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define A0SN05RIM	 BUFFER[275]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define idA0SN05RIM	 95	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define A0SN04RIM	 BUFFER[280]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define idA0SN04RIM	 96	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define A0SN03RIM	 BUFFER[285]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define idA0SN03RIM	 97	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define A0SN02RIM	 BUFFER[290]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define idA0SN02RIM	 98	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define R0IS01FI0	 BUFFER[295]	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define idR0IS01FI0	 99	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define A0IT03IRP	 BUFFER[298]	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define idA0IT03IRP	 100	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define B0IT03IRP	 BUFFER[301]	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define idB0IT03IRP	 101	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define R0IN03FI3	 BUFFER[304]	//( - , SA3) Выход КНК53М Гц от ПТИ
#define idR0IN03FI3	 102	//( - , SA3) Выход КНК53М Гц от ПТИ
#define R0IN02FI3	 BUFFER[309]	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI3	 103	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define B1VP81LZZ	 BUFFER[314]	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 104	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define B2IS33LDU	 BUFFER[316]	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define idB2IS33LDU	 105	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define A0VN01RIM	 BUFFER[318]	//( - , SCM) Период разгона  AЗ1
#define idA0VN01RIM	 106	//( - , SCM) Период разгона  AЗ1
#define B2IS32LIM	 BUFFER[323]	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define idB2IS32LIM	 107	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define B2IS11LIM	 BUFFER[325]	//( - , SCM) Магнит РБ2 обесточен
#define idB2IS11LIM	 108	//( - , SCM) Магнит РБ2 обесточен
#define A2IS32LIM	 BUFFER[327]	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define idA2IS32LIM	 109	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define A2IS11LIM	 BUFFER[329]	//( - , SCM) Магнит РБ1 обесточен
#define idA2IS11LIM	 110	//( - , SCM) Магнит РБ1 обесточен
#define B1IS32LIM	 BUFFER[331]	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define idB1IS32LIM	 111	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define B1IS11LIM	 BUFFER[333]	//( - , SCM) Магнит ББ2 обесточен
#define idB1IS11LIM	 112	//( - , SCM) Магнит ББ2 обесточен
#define A1IS32LIM	 BUFFER[335]	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define idA1IS32LIM	 113	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define A1IS11LIM	 BUFFER[337]	//( - , SCM) Магнит ББ1 обесточен
#define idA1IS11LIM	 114	//( - , SCM) Магнит ББ1 обесточен
#define A3AD34LDU	 BUFFER[339]	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define idA3AD34LDU	 115	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define R0IS02LDU	 BUFFER[341]	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define idR0IS02LDU	 116	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define R0EE04LZ2	 BUFFER[343]	//( - , SBz2) Питание  АКНП4  отключить
#define idR0EE04LZ2	 117	//( - , SBz2) Питание  АКНП4  отключить
#define R0EE03LZ2	 BUFFER[345]	//( - , SBz2) Питание  АКНП3  отключить
#define idR0EE03LZ2	 118	//( - , SBz2) Питание  АКНП3  отключить
#define R0EE02LZ2	 BUFFER[347]	//( - , SBz2) Питание  АКНП  отключить
#define idR0EE02LZ2	 119	//( - , SBz2) Питание  АКНП  отключить
#define R0EE04LZ1	 BUFFER[349]	//( - , SBz1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 120	//( - , SBz1) Питание  АКНП4  отключить
#define A7AP31LDU	 BUFFER[351]	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define idA7AP31LDU	 121	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define R4VS12LDU	 BUFFER[353]	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	 122	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define R4VS22LDU	 BUFFER[355]	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	 123	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define R1VS12LDU	 BUFFER[357]	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 124	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define R2VS12LDU	 BUFFER[359]	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 125	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	 BUFFER[361]	//( - , SCM) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 126	//( - , SCM) Движение МДЗ2 в сторону НУ
#define R1VS22LDU	 BUFFER[363]	//( - , SCM) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 127	//( - , SCM) Движение МДЗ1 в сторону НУ
#define B5VS12LDU	 BUFFER[365]	//( - , SCM) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 128	//( - , SCM) Движение НЛ2 в сторону ВУ
#define B5VS22LDU	 BUFFER[367]	//( - , SCM) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 129	//( - , SCM) Движение НЛ2 в сторону НУ
#define A5VS12LDU	 BUFFER[369]	//( - , SCM) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 130	//( - , SCM) Движение НЛ1 в сторону ВУ
#define A5VS22LDU	 BUFFER[371]	//( - , SCM) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 131	//( - , SCM) Движение НЛ1 в сторону НУ
#define B6VS12LDU	 BUFFER[373]	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define idB6VS12LDU	 132	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define B6VS22LDU	 BUFFER[375]	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define idB6VS22LDU	 133	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[377]	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 134	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define A6VS22LDU	 BUFFER[379]	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 135	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define B8IS21LDU	 BUFFER[381]	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define idB8IS21LDU	 136	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define B8IS11LDU	 BUFFER[383]	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 137	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define A1VP81LZZ	 BUFFER[385]	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 138	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
#define B8AD20LDU	 BUFFER[387]	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 139	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define B8AD10LDU	 BUFFER[389]	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 140	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define R4AD20LDU	 BUFFER[391]	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define idR4AD20LDU	 141	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define R4AD10LDU	 BUFFER[393]	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 142	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define B0SR01RIM	 BUFFER[395]	//( - , SCM) Текущая реактивность AЗ2
#define idB0SR01RIM	 143	//( - , SCM) Текущая реактивность AЗ2
#define B3AD33LDU	 BUFFER[400]	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 144	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B3AD05LDU	 BUFFER[402]	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 145	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define B3AD04LDU	 BUFFER[404]	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 146	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[406]	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 147	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define B3AD02LDU	 BUFFER[408]	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 148	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define B3AD01LDU	 BUFFER[410]	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 149	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define B3AD21LDU	 BUFFER[412]	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 150	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD11LDU	 BUFFER[414]	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 151	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define A3AD33LDU	 BUFFER[416]	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define idA3AD33LDU	 152	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define A3AD05LDU	 BUFFER[418]	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 153	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define A3AD04LDU	 BUFFER[420]	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 154	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[422]	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 155	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define R0CR01RIM	 BUFFER[424]	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define idR0CR01RIM	 156	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define B0SN08RIM	 BUFFER[429]	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define idB0SN08RIM	 157	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define A0SN08RIM	 BUFFER[434]	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define idA0SN08RIM	 158	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define B5AD20LDU	 BUFFER[439]	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 159	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define B5AD10LDU	 BUFFER[441]	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 160	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define A5AD20LDU	 BUFFER[443]	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 161	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define A5AD10LDU	 BUFFER[445]	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 162	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define R2AD20LDU	 BUFFER[447]	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 163	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[449]	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	 164	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define R1AD20LDU	 BUFFER[451]	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 165	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define R1AD10LDU	 BUFFER[453]	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	 166	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define B6AD20LDU	 BUFFER[455]	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 167	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define B6AD10LDU	 BUFFER[457]	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 168	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define A6AD20LDU	 BUFFER[459]	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 169	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define A6AD10LDU	 BUFFER[461]	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 170	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define A8AD20LDU	 BUFFER[463]	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 171	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define A8AD10LDU	 BUFFER[465]	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 172	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define A2AD21LDU	 BUFFER[467]	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 173	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD11LDU	 BUFFER[469]	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 174	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define B1AD05LDU	 BUFFER[471]	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 175	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define B1AD04LDU	 BUFFER[473]	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 176	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[475]	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 177	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define B1AD02LDU	 BUFFER[477]	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define idB1AD02LDU	 178	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define B1AD01LDU	 BUFFER[479]	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 179	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define B1AD21LDU	 BUFFER[481]	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 180	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD11LDU	 BUFFER[483]	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 181	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define A1AD05LDU	 BUFFER[485]	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 182	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define A1AD04LDU	 BUFFER[487]	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 183	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[489]	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 184	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define A1AD02LDU	 BUFFER[491]	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 185	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define A1AD01LDU	 BUFFER[493]	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 186	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define A1AD21LDU	 BUFFER[495]	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 187	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD11LDU	 BUFFER[497]	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 188	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define A0SR01RIM	 BUFFER[499]	//( - , SCM) Текущая реактивность AЗ1
#define idA0SR01RIM	 189	//( - , SCM) Текущая реактивность AЗ1
#define A3AD02LDU	 BUFFER[504]	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 190	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define A3AD01LDU	 BUFFER[506]	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 191	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define A3AD21LDU	 BUFFER[508]	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 192	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD11LDU	 BUFFER[510]	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 193	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define B2AD33LDU	 BUFFER[512]	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define idB2AD33LDU	 194	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define B2AD05LDU	 BUFFER[514]	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 195	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define B2AD04LDU	 BUFFER[516]	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 196	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[518]	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 197	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define B2AD02LDU	 BUFFER[520]	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 198	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define B2AD01LDU	 BUFFER[522]	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 199	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define B2AD21LDU	 BUFFER[524]	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 200	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD11LDU	 BUFFER[526]	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 201	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define A2AD33LDU	 BUFFER[528]	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define idA2AD33LDU	 202	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define A2AD05LDU	 BUFFER[530]	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 203	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define A2AD04LDU	 BUFFER[532]	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 204	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[534]	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 205	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define A2AD02LDU	 BUFFER[536]	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 206	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define A2AD01LDU	 BUFFER[538]	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 207	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define A2IP01IZ2	 BUFFER[540]	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 208	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define A2IP01IZ1	 BUFFER[543]	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 209	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define B3IS21LDU	 BUFFER[546]	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define idB3IS21LDU	 210	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define A3IS21LDU	 BUFFER[548]	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define idA3IS21LDU	 211	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define A2IS33LDU	 BUFFER[550]	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define idA2IS33LDU	 212	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define A2IC01UDU	 BUFFER[552]	//( - , SDu) Координата штока РБ1
#define idA2IC01UDU	 213	//( - , SDu) Координата штока РБ1
#define A2IS12LDU	 BUFFER[557]	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 214	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define A2IS11LDU	 BUFFER[559]	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define idA2IS11LDU	 215	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define A2IS21LDU	 BUFFER[561]	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define idA2IS21LDU	 216	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define B0IT02IZ2	 BUFFER[563]	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define idB0IT02IZ2	 217	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define B0IT01IZ1	 BUFFER[566]	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define idB0IT01IZ1	 218	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define A0IT02IZ2	 BUFFER[569]	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define idA0IT02IZ2	 219	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define A0IT01IZ1	 BUFFER[572]	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define idA0IT01IZ1	 220	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define R6IS21LDU	 BUFFER[575]	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 221	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define B7AS31LDU	 BUFFER[577]	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define idB7AS31LDU	 222	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define A7AS31LDU	 BUFFER[579]	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define idA7AS31LDU	 223	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define B3IS35LDU	 BUFFER[581]	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define idB3IS35LDU	 224	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define R6IS63LDU	 BUFFER[583]	//(do32_pti:160 - K30DO, - ) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 225	//(do32_pti:160 - K30DO, - ) Исправность ВИП ССДИ-39 2канал
#define R6IS62LDU	 BUFFER[585]	//(do32_pti:160 - K29DO, - ) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 226	//(do32_pti:160 - K29DO, - ) Исправность ВИП ССДИ-39 1канал
#define B3IS22LDU	 BUFFER[587]	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define idB3IS22LDU	 227	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define A3IS22LDU	 BUFFER[589]	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
#define idA3IS22LDU	 228	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
#define B3IS11LDU	 BUFFER[591]	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 229	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define A3IS11LDU	 BUFFER[593]	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 230	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
#define A3IP02IDU	 BUFFER[595]	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 231	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3VP81LDU	 BUFFER[598]	//( - , SCM) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 232	//( - , SCM) Давление СПУСК ИС2 в норме
#define A3VP81LDU	 BUFFER[600]	//( - , SCM) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 233	//( - , SCM) Давление СПУСК ИС1 в норме
#define B3IS33LDU	 BUFFER[602]	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idB3IS33LDU	 234	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define B3IC01UDU	 BUFFER[604]	//( - , SDu) Координата штока ИС2
#define idB3IC01UDU	 235	//( - , SDu) Координата штока ИС2
#define B3IS31LDU	 BUFFER[609]	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define idB3IS31LDU	 236	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define B3IP02IDU	 BUFFER[611]	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define idB3IP02IDU	 237	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define A3IS33LDU	 BUFFER[614]	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define idA3IS33LDU	 238	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define A3IC01UDU	 BUFFER[616]	//( - , SDu) Координата штока ИС1
#define idA3IC01UDU	 239	//( - , SDu) Координата штока ИС1
#define A3IS31LDU	 BUFFER[621]	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define idA3IS31LDU	 240	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define A2VP82LDU	 BUFFER[623]	//( - , SCM) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 241	//( - , SCM) Давление ПОДЪЁМ РБ1 в норме
#define B2AD31LDU	 BUFFER[625]	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define idB2AD31LDU	 242	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define B1AD32LDU	 BUFFER[627]	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 243	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define B1AD31LDU	 BUFFER[629]	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define idB1AD31LDU	 244	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define A3AD31LDU	 BUFFER[631]	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define idA3AD31LDU	 245	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define C1MD31LP1	 BUFFER[633]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define idC1MD31LP1	 246	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define C1MD31LP2	 BUFFER[635]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define idC1MD31LP2	 247	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define A1AD31LDU	 BUFFER[637]	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define idA1AD31LDU	 248	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define A1AD32LDU	 BUFFER[639]	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 249	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define A2AD31LDU	 BUFFER[641]	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define idA2AD31LDU	 250	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define C2MD31LP1	 BUFFER[643]	//( - , SCM) Кнопка «СБРОС РБ»
#define idC2MD31LP1	 251	//( - , SCM) Кнопка «СБРОС РБ»
#define A2AD32LDU	 BUFFER[645]	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 252	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define R0VZ71LZ2	 BUFFER[647]	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define idR0VZ71LZ2	 253	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define R0VZ71LZ1	 BUFFER[649]	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define idR0VZ71LZ1	 254	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define R8AD21LDU	 BUFFER[651]	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 255	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
#define R0AD14LDU	 BUFFER[653]	//( - , SCM) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 256	//( - , SCM) Имитация срабатывания верхней АС II УР
#define R0SR02RIM	 BUFFER[655]	//( - , SCM) Текущая мощность РУ (ватт)
#define idR0SR02RIM	 257	//( - , SCM) Текущая мощность РУ (ватт)
#define R0CR02RIM	 BUFFER[660]	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define idR0CR02RIM	 258	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define B3AD34LDU	 BUFFER[665]	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define idB3AD34LDU	 259	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define A3IS35LDU	 BUFFER[667]	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define idA3IS35LDU	 260	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define R7II73LZ2	 BUFFER[669]	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ2	 261	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define R7II71LZ2	 BUFFER[671]	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ2	 262	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II72LZ2	 BUFFER[673]	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ2	 263	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R0AD16LDU	 BUFFER[675]	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 264	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define R7II72LZ1	 BUFFER[677]	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ1	 265	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R7II71LZ1	 BUFFER[679]	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ1	 266	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II73LZ1	 BUFFER[681]	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ1	 267	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
#define R0SR01RIM	 BUFFER[683]	//( - , SCM) Текущая реактивность PУ
#define idR0SR01RIM	 268	//( - , SCM) Текущая реактивность PУ
#define R0ST01RIM	 BUFFER[688]	//( - , SCM) Текущий период разгона РУ
#define idR0ST01RIM	 269	//( - , SCM) Текущий период разгона РУ
#define A4AD10LDU	 BUFFER[693]	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define idA4AD10LDU	 270	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define B4AD10LDU	 BUFFER[695]	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define idB4AD10LDU	 271	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define A9AD10LDU	 BUFFER[697]	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define idA9AD10LDU	 272	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define B9AD10LDU	 BUFFER[699]	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define idB9AD10LDU	 273	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define R0MW13LP2	 BUFFER[701]	//( - , SCM) Переключатель «СЕТЬ»
#define idR0MW13LP2	 274	//( - , SCM) Переключатель «СЕТЬ»
#define B3AD31LDU	 BUFFER[703]	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define idB3AD31LDU	 275	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define B2AD32LDU	 BUFFER[705]	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 276	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define fEM_R0UL01RIM	 BUFFER[707]	//(R0UL01RIM) Среднее время генерации нейтронов
#define idfEM_R0UL01RIM	 277	//(R0UL01RIM) Среднее время генерации нейтронов
#define fEM_R0UN02RIM	 BUFFER[712]	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define idfEM_R0UN02RIM	 278	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define fEM_A1UR01RIM	 BUFFER[717]	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR01RIM	 279	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define fEM_A1UR00RIM	 BUFFER[722]	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR00RIM	 280	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define fEM_A3UR00RIM	 BUFFER[727]	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR00RIM	 281	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define fEM_A3UR01RIM	 BUFFER[732]	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR01RIM	 282	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define fEM_R0UT01RIM	 BUFFER[737]	//(R0UT01RIM) Температурный коэффициент (долл)
#define idfEM_R0UT01RIM	 283	//(R0UT01RIM) Температурный коэффициент (долл)
#define fEM_R0UT02RIM	 BUFFER[742]	//(R0UT02RIM) Масса топлива в АЗ
#define idfEM_R0UT02RIM	 284	//(R0UT02RIM) Масса топлива в АЗ
#define fEM_R0UT04RIM	 BUFFER[747]	//(R0UT04RIM) Удельная теплоёмкость топлива
#define idfEM_R0UT04RIM	 285	//(R0UT04RIM) Удельная теплоёмкость топлива
#define fEM_R0UT03RIM	 BUFFER[752]	//(R0UT03RIM) Нормальная температура АЗ град
#define idfEM_R0UT03RIM	 286	//(R0UT03RIM) Нормальная температура АЗ град
#define fEM_R0UT05RIM	 BUFFER[757]	//(R0UT05RIM) Энергия деления ядра
#define idfEM_R0UT05RIM	 287	//(R0UT05RIM) Энергия деления ядра
#define fEM_R0UT06RIM	 BUFFER[762]	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define idfEM_R0UT06RIM	 288	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define fEM_A1UC02RDU	 BUFFER[767]	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define idfEM_A1UC02RDU	 289	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define fEM_A1UC04RIM	 BUFFER[772]	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define idfEM_A1UC04RIM	 290	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define fEM_A1UC05RIM	 BUFFER[777]	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define idfEM_A1UC05RIM	 291	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define fEM_A1UC06RIM	 BUFFER[782]	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define idfEM_A1UC06RIM	 292	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define fEM_A2UC06RIM	 BUFFER[787]	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define idfEM_A2UC06RIM	 293	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define fEM_A2UC05RIM	 BUFFER[792]	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define idfEM_A2UC05RIM	 294	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define fEM_A2UC04RIM	 BUFFER[797]	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define idfEM_A2UC04RIM	 295	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define fEM_A2UC02RDU	 BUFFER[802]	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define idfEM_A2UC02RDU	 296	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define fEM_A3UC06RIM	 BUFFER[807]	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define idfEM_A3UC06RIM	 297	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define fEM_A3UC05RIM	 BUFFER[812]	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC05RIM	 298	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC04RIM	 BUFFER[817]	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define idfEM_A3UC04RIM	 299	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define fEM_A3UC02RDU	 BUFFER[822]	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define idfEM_A3UC02RDU	 300	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define fEM_R4UV80RDU	 BUFFER[827]	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define idfEM_R4UV80RDU	 301	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define fEM_R4UC10RIM	 BUFFER[832]	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define idfEM_R4UC10RIM	 302	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define fEM_R4UC20RIM	 BUFFER[837]	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define idfEM_R4UC20RIM	 303	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define fEM_B8UC21RIM	 BUFFER[842]	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define idfEM_B8UC21RIM	 304	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define fEM_B8UC20RIM	 BUFFER[847]	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define idfEM_B8UC20RIM	 305	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define fEM_B8UC11RIM	 BUFFER[852]	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define idfEM_B8UC11RIM	 306	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define fEM_B8UC10RIM	 BUFFER[857]	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define idfEM_B8UC10RIM	 307	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define fEM_B8UV80RDU	 BUFFER[862]	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define idfEM_B8UV80RDU	 308	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define fEM_A8UV80RDU	 BUFFER[867]	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define idfEM_A8UV80RDU	 309	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define fEM_A8UC10RIM	 BUFFER[872]	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define idfEM_A8UC10RIM	 310	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define fEM_A8UC11RIM	 BUFFER[877]	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define idfEM_A8UC11RIM	 311	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define fEM_A8UC20RIM	 BUFFER[882]	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define idfEM_A8UC20RIM	 312	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define fEM_A8UC21RIM	 BUFFER[887]	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define idfEM_A8UC21RIM	 313	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define fEM_A6UC10RIM	 BUFFER[892]	//(A6UC10RIM) Время полного хода БЗ (сек)
#define idfEM_A6UC10RIM	 314	//(A6UC10RIM) Время полного хода БЗ (сек)
#define fEM_R1UC10RIM	 BUFFER[897]	//(R1UC10RIM) Время полного хода МДЗ сек
#define idfEM_R1UC10RIM	 315	//(R1UC10RIM) Время полного хода МДЗ сек
#define fEM_A5UC10RIM	 BUFFER[902]	//(A5UC10RIM) Время полного хода НЛ сек
#define idfEM_A5UC10RIM	 316	//(A5UC10RIM) Время полного хода НЛ сек
#define fEM_A0UN01RIM	 BUFFER[907]	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define idfEM_A0UN01RIM	 317	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define fEM_R4UC22RIM	 BUFFER[912]	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define idfEM_R4UC22RIM	 318	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define fEM_A1UG01RDU	 BUFFER[917]	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define idfEM_A1UG01RDU	 319	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define fEM_A2UG01RDU	 BUFFER[922]	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define idfEM_A2UG01RDU	 320	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define fEM_A3UG01RDU	 BUFFER[927]	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define idfEM_A3UG01RDU	 321	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define fEM_R7UC10RIM	 BUFFER[932]	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define idfEM_R7UC10RIM	 322	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define fEM_R7UC19RIM	 BUFFER[937]	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define idfEM_R7UC19RIM	 323	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define fEM_R7UI02RIM	 BUFFER[942]	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define idfEM_R7UI02RIM	 324	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define fEM_R7UL01RIM	 BUFFER[947]	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define idfEM_R7UL01RIM	 325	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define fEM_A2UR00RIM	 BUFFER[952]	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define idfEM_A2UR00RIM	 326	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define fEM_A2UR01RIM	 BUFFER[957]	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define idfEM_A2UR01RIM	 327	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define fEM_A0UN02RIM	 BUFFER[962]	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define idfEM_A0UN02RIM	 328	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define fEM_R0UR30RIM	 BUFFER[967]	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define idfEM_R0UR30RIM	 329	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define fEM_R0UR01RIM	 BUFFER[972]	//(R0UR01RIM) Стартовая отрицательная реактивность
#define idfEM_R0UR01RIM	 330	//(R0UR01RIM) Стартовая отрицательная реактивность
#define fEM_R0UT02RDU	 BUFFER[977]	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RDU	 331	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RDU	 BUFFER[982]	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RDU	 332	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define fEM_A1UC03RDU	 BUFFER[987]	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define idfEM_A1UC03RDU	 333	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define fEM_A2UP03RDU	 BUFFER[992]	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP03RDU	 334	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UP04RDU	 BUFFER[997]	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP04RDU	 335	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UC03RDU	 BUFFER[1002]	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define idfEM_A2UC03RDU	 336	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define fEM_A3UP03RDU	 BUFFER[1007]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 337	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1012]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 338	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UC03RDU	 BUFFER[1017]	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define idfEM_A3UC03RDU	 339	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define fEM_R7UI74RIM	 BUFFER[1022]	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define idfEM_R7UI74RIM	 340	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define fEM_A8UC03RDU	 BUFFER[1027]	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define idfEM_A8UC03RDU	 341	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define fEM_R0UV87RDU	 BUFFER[1032]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 342	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV81RDU	 BUFFER[1037]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 343	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1042]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 344	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1047]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 345	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1052]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 346	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1057]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 347	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1062]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 348	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A8UC08RDU	 BUFFER[1067]	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define idfEM_A8UC08RDU	 349	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define fEM_B8UC08RDU	 BUFFER[1072]	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define idfEM_B8UC08RDU	 350	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define fEM_R4UC08RDU	 BUFFER[1077]	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define idfEM_R4UC08RDU	 351	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define fEM_R0UH01RSS	 BUFFER[1082]	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define idfEM_R0UH01RSS	 352	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define fEM_A0UX00RSS	 BUFFER[1087]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 353	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_R7UX01RSS	 BUFFER[1092]	//(R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	 354	//(R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	 BUFFER[1097]	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	 355	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX04RSS	 BUFFER[1102]	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	 356	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	 BUFFER[1107]	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	 357	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	 BUFFER[1112]	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	 358	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define fEM_R7UX07RSS	 BUFFER[1117]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 359	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[1122]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 360	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[1127]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 361	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY01RSS	 BUFFER[1132]	//(R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	 362	//(R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	 BUFFER[1137]	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	 363	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY04RSS	 BUFFER[1142]	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	 364	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	 BUFFER[1147]	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	 365	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	 BUFFER[1152]	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	 366	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY07RSS	 BUFFER[1157]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 367	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[1162]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 368	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[1167]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 369	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_R7UX10RSS	 BUFFER[1172]	//(R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	 370	//(R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	 BUFFER[1177]	//(R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	 371	//(R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	 BUFFER[1182]	//(R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	 372	//(R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY10RSS	 BUFFER[1187]	//(R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	 373	//(R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	 BUFFER[1192]	//(R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	 374	//(R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	 BUFFER[1197]	//(R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	 375	//(R7UY12RSS) Y-координата камеры R7IN43
#define fEM_A0UX01RSS	 BUFFER[1202]	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	 376	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	 BUFFER[1207]	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	 377	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	 BUFFER[1212]	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	 378	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_A0UX04RSS	 BUFFER[1217]	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	 379	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	 BUFFER[1222]	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	 380	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	 BUFFER[1227]	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	 381	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_A0UX07RSS	 BUFFER[1232]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 382	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[1237]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 383	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[1242]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 384	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_A0UX10RSS	 BUFFER[1247]	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	 385	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	 BUFFER[1252]	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	 386	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	 BUFFER[1257]	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	 387	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX01RSS	 BUFFER[1262]	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	 388	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	 BUFFER[1267]	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	 389	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	 BUFFER[1272]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 390	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[1277]	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define idfEM_B0UX04RSS	 391	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define fEM_B0UX05RSS	 BUFFER[1282]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 392	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	 BUFFER[1287]	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	 393	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_B0UX07RSS	 BUFFER[1292]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 394	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[1297]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 395	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[1302]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 396	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_B0UX10RSS	 BUFFER[1307]	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	 397	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	 BUFFER[1312]	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	 398	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	 BUFFER[1317]	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	 399	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0UH02RSS	 BUFFER[1322]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define idfEM_R0UH02RSS	 400	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define fEM_R0UH03RSS	 BUFFER[1327]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define idfEM_R0UH03RSS	 401	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define fEM_R4US80RDU	 BUFFER[1332]	//(R4US80RDU) Тормозной путь тележки (мм)
#define idfEM_R4US80RDU	 402	//(R4US80RDU) Тормозной путь тележки (мм)
#define fEM_R7UI71RIM	 BUFFER[1337]	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define idfEM_R7UI71RIM	 403	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define fEM_R7UI72RIM	 BUFFER[1342]	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define idfEM_R7UI72RIM	 404	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define fEM_R7UI73RIM	 BUFFER[1347]	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define idfEM_R7UI73RIM	 405	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define fEM_A1UP01RIM	 BUFFER[1352]	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define idfEM_A1UP01RIM	 406	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define fEM_A2UP01RIM	 BUFFER[1357]	//(A2UP01RIM) Текущее давление на сброс РБ
#define idfEM_A2UP01RIM	 407	//(A2UP01RIM) Текущее давление на сброс РБ
#define fEM_A0UP02RIM	 BUFFER[1362]	//(A0UP02RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP02RIM	 408	//(A0UP02RIM) Текущее давление в АЗ1,2
#define fEM_A3UP01RIM	 BUFFER[1367]	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define idfEM_A3UP01RIM	 409	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define fEM_A1UP82RIM	 BUFFER[1372]	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define idfEM_A1UP82RIM	 410	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define fEM_A3UP02RDU	 BUFFER[1377]	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define idfEM_A3UP02RDU	 411	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define fEM_A1UV02RIM	 BUFFER[1382]	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define idfEM_A1UV02RIM	 412	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define fEM_A3UV02RIM	 BUFFER[1387]	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define idfEM_A3UV02RIM	 413	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define fEM_A2UV02RIM	 BUFFER[1392]	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define idfEM_A2UV02RIM	 414	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define fEM_B8US80RDU	 BUFFER[1397]	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define idfEM_B8US80RDU	 415	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define fEM_A8US80RDU	 BUFFER[1402]	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define idfEM_A8US80RDU	 416	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define fEM_A6US80RDU	 BUFFER[1407]	//(A6US80RDU) Тормозной путь БЗ (мм)
#define idfEM_A6US80RDU	 417	//(A6US80RDU) Тормозной путь БЗ (мм)
#define fEM_A1US07RDU	 BUFFER[1412]	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define idfEM_A1US07RDU	 418	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define fEM_A2US07RDU	 BUFFER[1417]	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define idfEM_A2US07RDU	 419	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define fEM_A3US07RDU	 BUFFER[1422]	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define idfEM_A3US07RDU	 420	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define fEM_R7UI75RIM	 BUFFER[1427]	//(R7UI75RIM) Множитель к уровню радиации
#define idfEM_R7UI75RIM	 421	//(R7UI75RIM) Множитель к уровню радиации
#define fEM_R0UH21RSS	 BUFFER[1432]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 422	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[1437]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 423	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[1442]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 424	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UH05RSS	 BUFFER[1447]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 425	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_A4UL10RIM	 BUFFER[1452]	//(A4UL10RIM) Время полного перемещения НИ сек
#define idfEM_A4UL10RIM	 426	//(A4UL10RIM) Время полного перемещения НИ сек
#define fEM_A9UL10RIM	 BUFFER[1457]	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define idfEM_A9UL10RIM	 427	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define fEM_R3UL10RIM	 BUFFER[1462]	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define idfEM_R3UL10RIM	 428	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define fEM_R5UL10RIM	 BUFFER[1467]	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define idfEM_R5UL10RIM	 429	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define fEM_R6UL10RIM	 BUFFER[1472]	//(R6UL10RIM) Время полного хода кран-балки сек
#define idfEM_R6UL10RIM	 430	//(R6UL10RIM) Время полного хода кран-балки сек
#define lEM_C1AD31LRP	 BUFFER[1477]	//(C1AD31LRP) Общий сброс от РПУ
#define idlEM_C1AD31LRP	 431	//(C1AD31LRP) Общий сброс от РПУ
#define lEM_R0IE01LRP	 BUFFER[1479]	//(R0IE01LRP) Отключение питание детекторов
#define idlEM_R0IE01LRP	 432	//(R0IE01LRP) Отключение питание детекторов
#define lEM_R0IE02LRP	 BUFFER[1481]	//(R0IE02LRP) Отключить питание ПР, ПУ
#define idlEM_R0IE02LRP	 433	//(R0IE02LRP) Отключить питание ПР, ПУ
#define fEM_A2UP02RIM	 BUFFER[1483]	//(A2UP02RIM) Текущее давление на подъём РБ
#define idfEM_A2UP02RIM	 434	//(A2UP02RIM) Текущее давление на подъём РБ
#define fEM_A2UP03RIM	 BUFFER[1488]	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define idfEM_A2UP03RIM	 435	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define fEM_A0UP01RIM	 BUFFER[1493]	//(A0UP01RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP01RIM	 436	//(A0UP01RIM) Текущее давление в АЗ1,2
#define fEM_A3UP02RIM	 BUFFER[1498]	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define idfEM_A3UP02RIM	 437	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define fEM_A4UP01RIM	 BUFFER[1503]	//(A4UP01RIM) Текущее давление на подъём НИ
#define idfEM_A4UP01RIM	 438	//(A4UP01RIM) Текущее давление на подъём НИ
#define fEM_A4UP02RIM	 BUFFER[1508]	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define idfEM_A4UP02RIM	 439	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define fEM_R7UI76RIM	 BUFFER[1513]	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define idfEM_R7UI76RIM	 440	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define fEM_R7UI77RIM	 BUFFER[1518]	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define idfEM_R7UI77RIM	 441	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define iEM_TERBB1	 BUFFER[1523]	//(TERBB1) Неисправности  ББ1
#define idiEM_TERBB1	 442	//(TERBB1) Неисправности  ББ1
#define fEM_A1MC02RC1	 BUFFER[1526]	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define idfEM_A1MC02RC1	 443	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define fEM_A1MV02RC1	 BUFFER[1531]	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define idfEM_A1MV02RC1	 444	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define iEM_TERBB2	 BUFFER[1536]	//(TERBB2) Неисправности  ББ2
#define idiEM_TERBB2	 445	//(TERBB2) Неисправности  ББ2
#define fEM_B1MC02RC1	 BUFFER[1539]	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define idfEM_B1MC02RC1	 446	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define fEM_B1MV02RC1	 BUFFER[1544]	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define idfEM_B1MV02RC1	 447	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define iEM_TERRB2	 BUFFER[1549]	//(TERRB2) Неисправности  РБ2
#define idiEM_TERRB2	 448	//(TERRB2) Неисправности  РБ2
#define fEM_B2MC02RC1	 BUFFER[1552]	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define idfEM_B2MC02RC1	 449	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define fEM_B2MV02RC1	 BUFFER[1557]	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define idfEM_B2MV02RC1	 450	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define iEM_TERRB1	 BUFFER[1562]	//(TERRB1) Неисправности  РБ1
#define idiEM_TERRB1	 451	//(TERRB1) Неисправности  РБ1
#define fEM_A2MC02RC1	 BUFFER[1565]	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define idfEM_A2MC02RC1	 452	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define fEM_A2MV02RC1	 BUFFER[1570]	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define idfEM_A2MV02RC1	 453	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define iEM_TERIS2	 BUFFER[1575]	//(TERIS2) Неисправности  ИС2
#define idiEM_TERIS2	 454	//(TERIS2) Неисправности  ИС2
#define fEM_B3MC02RC1	 BUFFER[1578]	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define idfEM_B3MC02RC1	 455	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define fEM_B3MV02RC1	 BUFFER[1583]	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define idfEM_B3MV02RC1	 456	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define iEM_TERIS1	 BUFFER[1588]	//(TERIS1) Неисправности  ИС1
#define idiEM_TERIS1	 457	//(TERIS1) Неисправности  ИС1
#define fEM_A3MC02RC1	 BUFFER[1591]	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define idfEM_A3MC02RC1	 458	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define fEM_A3MV02RC1	 BUFFER[1596]	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define idfEM_A3MV02RC1	 459	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define iEM_TERA1IE04LDU	 BUFFER[1601]	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define idiEM_TERA1IE04LDU	 460	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define iEM_TERA1IE03LDU	 BUFFER[1604]	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define idiEM_TERA1IE03LDU	 461	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define fEM_A1MC01RC1	 BUFFER[1607]	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define idfEM_A1MC01RC1	 462	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define iEM_TERB1IE03LDU	 BUFFER[1612]	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define idiEM_TERB1IE03LDU	 463	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define iEM_TERB1IE04LDU	 BUFFER[1615]	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define idiEM_TERB1IE04LDU	 464	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define fEM_B1MC01RC1	 BUFFER[1618]	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define idfEM_B1MC01RC1	 465	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define fEM_B1MV01RC1	 BUFFER[1623]	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define idfEM_B1MV01RC1	 466	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define fEM_B2MC01RC1	 BUFFER[1628]	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define idfEM_B2MC01RC1	 467	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define fEM_B2MV01RC1	 BUFFER[1633]	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define idfEM_B2MV01RC1	 468	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define fEM_A3MC01RC1	 BUFFER[1638]	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define idfEM_A3MC01RC1	 469	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define fEM_A3MV01RC1	 BUFFER[1643]	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define idfEM_A3MV01RC1	 470	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define fEM_B3MC01RC1	 BUFFER[1648]	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define idfEM_B3MC01RC1	 471	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define fEM_B3MV01RC1	 BUFFER[1653]	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define idfEM_B3MV01RC1	 472	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define iEM_TERA2SS21LIM	 BUFFER[1658]	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define idiEM_TERA2SS21LIM	 473	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define iEM_TERA2SS12LIM	 BUFFER[1661]	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define idiEM_TERA2SS12LIM	 474	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define iEM_TERR6SS21LIM	 BUFFER[1664]	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define idiEM_TERR6SS21LIM	 475	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define iEM_TERA2VP82LIM	 BUFFER[1667]	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define idiEM_TERA2VP82LIM	 476	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define iEM_TERA2SS11LIM	 BUFFER[1670]	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define idiEM_TERA2SS11LIM	 477	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define iEM_TERB3SS21LIM	 BUFFER[1673]	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define idiEM_TERB3SS21LIM	 478	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define iEM_TERA0MT01RIM	 BUFFER[1676]	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define idiEM_TERA0MT01RIM	 479	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define iEM_TERB0MT01RIM	 BUFFER[1679]	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define idiEM_TERB0MT01RIM	 480	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define iEM_TERA2SP01RIM	 BUFFER[1682]	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define idiEM_TERA2SP01RIM	 481	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define iEM_TERB2SP01RIM	 BUFFER[1685]	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define idiEM_TERB2SP01RIM	 482	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define iEM_TERB3SP02RIM	 BUFFER[1688]	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define idiEM_TERB3SP02RIM	 483	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define iEM_TERA3SC01RIM	 BUFFER[1691]	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define idiEM_TERA3SC01RIM	 484	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define iEM_TERA3VP81LIM	 BUFFER[1694]	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define idiEM_TERA3VP81LIM	 485	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define iEM_TERA2SC01RIM	 BUFFER[1697]	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define idiEM_TERA2SC01RIM	 486	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define iEM_TERA2SS33LIM	 BUFFER[1700]	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define idiEM_TERA2SS33LIM	 487	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define iEM_TERA3SS21LIM	 BUFFER[1703]	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define idiEM_TERA3SS21LIM	 488	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define iEM_TERA3SS33LIM	 BUFFER[1706]	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define idiEM_TERA3SS33LIM	 489	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define iEM_TERA3SS31LIM	 BUFFER[1709]	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define idiEM_TERA3SS31LIM	 490	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define iEM_TERB3SS31LIM	 BUFFER[1712]	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define idiEM_TERB3SS31LIM	 491	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define iEM_TERB3SS33LIM	 BUFFER[1715]	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idiEM_TERB3SS33LIM	 492	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define iEM_TERB3SC01RIM	 BUFFER[1718]	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define idiEM_TERB3SC01RIM	 493	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define iEM_TERA3SS11LIM	 BUFFER[1721]	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define idiEM_TERA3SS11LIM	 494	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define iEM_TERB3SS11LIM	 BUFFER[1724]	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define idiEM_TERB3SS11LIM	 495	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define iEM_TERR6IS64LIM	 BUFFER[1727]	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define idiEM_TERR6IS64LIM	 496	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define iEM_TERB3SS22LIM	 BUFFER[1730]	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define idiEM_TERB3SS22LIM	 497	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define iEM_TERA3SS22LIM	 BUFFER[1733]	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define idiEM_TERA3SS22LIM	 498	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define iEM_TERA3SP02RIM	 BUFFER[1736]	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define idiEM_TERA3SP02RIM	 499	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define iEM_TERR6IS62LIM	 BUFFER[1739]	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define idiEM_TERR6IS62LIM	 500	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define iEM_TERR6IS66LIM	 BUFFER[1742]	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idiEM_TERR6IS66LIM	 501	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define iEM_TERR6IS67LIM	 BUFFER[1745]	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idiEM_TERR6IS67LIM	 502	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define iEM_TERA0VP81LIM	 BUFFER[1748]	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define idiEM_TERA0VP81LIM	 503	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define iEM_TERB0VP81LIM	 BUFFER[1751]	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define idiEM_TERB0VP81LIM	 504	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define iEM_TERR0VP81LIM	 BUFFER[1754]	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define idiEM_TERR0VP81LIM	 505	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define iEM_TERR6IS68LIM	 BUFFER[1757]	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define idiEM_TERR6IS68LIM	 506	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define iEM_TERR7SI74RIM	 BUFFER[1760]	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define idiEM_TERR7SI74RIM	 507	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define iEM_TERA5SS21LIM	 BUFFER[1763]	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define idiEM_TERA5SS21LIM	 508	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define iEM_TERB5SS11LIM	 BUFFER[1766]	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define idiEM_TERB5SS11LIM	 509	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define iEM_TERA5SS11LIM	 BUFFER[1769]	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define idiEM_TERA5SS11LIM	 510	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define iEM_TERA9SS11LIM	 BUFFER[1772]	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define idiEM_TERA9SS11LIM	 511	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define iEM_TERB2SS11LIM	 BUFFER[1775]	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define idiEM_TERB2SS11LIM	 512	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define iEM_TERB2SS12LIM	 BUFFER[1778]	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define idiEM_TERB2SS12LIM	 513	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define iEM_TERB2SS21LIM	 BUFFER[1781]	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB2SS21LIM	 514	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERR3SS11LIM	 BUFFER[1784]	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define idiEM_TERR3SS11LIM	 515	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define iEM_TERB2SC01RIM	 BUFFER[1787]	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define idiEM_TERB2SC01RIM	 516	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define iEM_TERR3SS21LIM	 BUFFER[1790]	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define idiEM_TERR3SS21LIM	 517	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define iEM_TERR5SS11LIM	 BUFFER[1793]	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define idiEM_TERR5SS11LIM	 518	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define iEM_TERA4SS11LIM	 BUFFER[1796]	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define idiEM_TERA4SS11LIM	 519	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define iEM_TERR1SS11LIM	 BUFFER[1799]	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define idiEM_TERR1SS11LIM	 520	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define iEM_TERR1SS21LIM	 BUFFER[1802]	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define idiEM_TERR1SS21LIM	 521	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define iEM_TERR2SS11LIM	 BUFFER[1805]	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define idiEM_TERR2SS11LIM	 522	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define iEM_TERR2SS21LIM	 BUFFER[1808]	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define idiEM_TERR2SS21LIM	 523	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define iEM_TERA4VP82LIM	 BUFFER[1811]	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define idiEM_TERA4VP82LIM	 524	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define iEM_TERB4SS21LIM	 BUFFER[1814]	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define idiEM_TERB4SS21LIM	 525	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define iEM_TERR5SS21LIM	 BUFFER[1817]	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define idiEM_TERR5SS21LIM	 526	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define iEM_TERB6SS21LIM	 BUFFER[1820]	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define idiEM_TERB6SS21LIM	 527	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define iEM_TERB4SS11LIM	 BUFFER[1823]	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define idiEM_TERB4SS11LIM	 528	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define iEM_TERA4SS21LIM	 BUFFER[1826]	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define idiEM_TERA4SS21LIM	 529	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define iEM_TERA6MS11LIM	 BUFFER[1829]	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define idiEM_TERA6MS11LIM	 530	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define iEM_TERA6SS21LIM	 BUFFER[1832]	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define idiEM_TERA6SS21LIM	 531	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define iEM_TERB6SS11LIM	 BUFFER[1835]	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define idiEM_TERB6SS11LIM	 532	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define iEM_TERR4SS11LIM	 BUFFER[1838]	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define idiEM_TERR4SS11LIM	 533	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define iEM_TERR4MS21LIM	 BUFFER[1841]	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define idiEM_TERR4MS21LIM	 534	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define iEM_TERR4SS12LIM	 BUFFER[1844]	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define idiEM_TERR4SS12LIM	 535	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define iEM_TERR4SS22LIM	 BUFFER[1847]	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define idiEM_TERR4SS22LIM	 536	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define iEM_TERR8SS11LIM	 BUFFER[1850]	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define idiEM_TERR8SS11LIM	 537	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define iEM_TERB8SC01RIM	 BUFFER[1853]	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define idiEM_TERB8SC01RIM	 538	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define iEM_TERA8SC01RIM	 BUFFER[1856]	//(TERA8SC01RIM) Искажение: Координата ДС2
#define idiEM_TERA8SC01RIM	 539	//(TERA8SC01RIM) Искажение: Координата ДС2
#define iEM_TERB8SS12LIM	 BUFFER[1859]	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define idiEM_TERB8SS12LIM	 540	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define iEM_TERA8SS12LIM	 BUFFER[1862]	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define idiEM_TERA8SS12LIM	 541	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define iEM_TERB8SS22LIM	 BUFFER[1865]	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define idiEM_TERB8SS22LIM	 542	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define iEM_TERA8SS22LIM	 BUFFER[1868]	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define idiEM_TERA8SS22LIM	 543	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define iEM_TERA9SS21LIM	 BUFFER[1871]	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define idiEM_TERA9SS21LIM	 544	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define iEM_TERB9SS21LIM	 BUFFER[1874]	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define idiEM_TERB9SS21LIM	 545	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define iEM_TERB9SS11LIM	 BUFFER[1877]	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define idiEM_TERB9SS11LIM	 546	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define iEM_TERB5SS21LIM	 BUFFER[1880]	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define idiEM_TERB5SS21LIM	 547	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define iEM_TERA1SS21LIM	 BUFFER[1883]	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define idiEM_TERA1SS21LIM	 548	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define iEM_TERA1SS11LIM	 BUFFER[1886]	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define idiEM_TERA1SS11LIM	 549	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define iEM_TERA1SC01RIM	 BUFFER[1889]	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define idiEM_TERA1SC01RIM	 550	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define iEM_TERA1SS12LIM	 BUFFER[1892]	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define idiEM_TERA1SS12LIM	 551	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define iEM_TERB1SS21LIM	 BUFFER[1895]	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define idiEM_TERB1SS21LIM	 552	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define iEM_TERB1SS11LIM	 BUFFER[1898]	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define idiEM_TERB1SS11LIM	 553	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define iEM_TERB1MC01RIM	 BUFFER[1901]	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define idiEM_TERB1MC01RIM	 554	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define iEM_TERB1SS12LIM	 BUFFER[1904]	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define idiEM_TERB1SS12LIM	 555	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define iEM_TERTLG	 BUFFER[1907]	//(TERTLG) Неисправности  тележки от ИС
#define idiEM_TERTLG	 556	//(TERTLG) Неисправности  тележки от ИС
#define fEM_R4MC01RC1	 BUFFER[1910]	//(R4MC01RC1) Заданная координата тележки от ИС
#define idfEM_R4MC01RC1	 557	//(R4MC01RC1) Заданная координата тележки от ИС
#define fEM_R4MV01RC1	 BUFFER[1915]	//(R4MV01RC1) Заданная скорость тележки от ИС
#define idfEM_R4MV01RC1	 558	//(R4MV01RC1) Заданная скорость тележки от ИС
#define iEM_TERMAZ2	 BUFFER[1920]	//(TERMAZ2) Неисправности АЗ2 от ИС
#define idiEM_TERMAZ2	 559	//(TERMAZ2) Неисправности АЗ2 от ИС
#define fEM_B8MC01RC1	 BUFFER[1923]	//(B8MC01RC1) аданная координата АЗ2 от ИС
#define idfEM_B8MC01RC1	 560	//(B8MC01RC1) аданная координата АЗ2 от ИС
#define fEM_B8MV01RC1	 BUFFER[1928]	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define idfEM_B8MV01RC1	 561	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define iEM_TERDS2	 BUFFER[1933]	//(TERDS2) Неисправности ДС2 от ИС
#define idiEM_TERDS2	 562	//(TERDS2) Неисправности ДС2 от ИС
#define fEM_A8MC01RC1	 BUFFER[1936]	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define idfEM_A8MC01RC1	 563	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define fEM_A8MV01RC1	 BUFFER[1941]	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define idfEM_A8MV01RC1	 564	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define iEM_TERBZ1	 BUFFER[1946]	//(TERBZ1) Неисправности БЗ1
#define idiEM_TERBZ1	 565	//(TERBZ1) Неисправности БЗ1
#define fEM_A6MC01RC1	 BUFFER[1949]	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define idfEM_A6MC01RC1	 566	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define fEM_A6MV01RC1	 BUFFER[1954]	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define idfEM_A6MV01RC1	 567	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define iEM_TERBZ2	 BUFFER[1959]	//(TERBZ2) Неисправности БЗ2
#define idiEM_TERBZ2	 568	//(TERBZ2) Неисправности БЗ2
#define fEM_B6MC01RC1	 BUFFER[1962]	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define idfEM_B6MC01RC1	 569	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define fEM_B6MV01RC1	 BUFFER[1967]	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define idfEM_B6MV01RC1	 570	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define lEM_R3AD10LC1	 BUFFER[1972]	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define idlEM_R3AD10LC1	 571	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define lEM_R3AD20LC1	 BUFFER[1974]	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define idlEM_R3AD20LC1	 572	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define lEM_R6AD10LC1	 BUFFER[1976]	//(R6AD10LC1) Выкатить кран-балку от ИС
#define idlEM_R6AD10LC1	 573	//(R6AD10LC1) Выкатить кран-балку от ИС
#define lEM_R5AD10LC1	 BUFFER[1978]	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define idlEM_R5AD10LC1	 574	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define lEM_R5AD20LC1	 BUFFER[1980]	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define idlEM_R5AD20LC1	 575	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define iEM_TERMDZ2	 BUFFER[1982]	//(TERMDZ2) Неисправности МДЗ2
#define idiEM_TERMDZ2	 576	//(TERMDZ2) Неисправности МДЗ2
#define fEM_R2MC01RC1	 BUFFER[1985]	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define idfEM_R2MC01RC1	 577	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define fEM_R2MV01RC1	 BUFFER[1990]	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define idfEM_R2MV01RC1	 578	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define iEM_TERMDZ1	 BUFFER[1995]	//(TERMDZ1) Неисправности МДЗ1
#define idiEM_TERMDZ1	 579	//(TERMDZ1) Неисправности МДЗ1
#define fEM_R1MC01RC1	 BUFFER[1998]	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define idfEM_R1MC01RC1	 580	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define fEM_R1MV01RC1	 BUFFER[2003]	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define idfEM_R1MV01RC1	 581	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define iEM_TERNL1	 BUFFER[2008]	//(TERNL1) Неисправности НЛ1
#define idiEM_TERNL1	 582	//(TERNL1) Неисправности НЛ1
#define fEM_A5MC01RC1	 BUFFER[2011]	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define idfEM_A5MC01RC1	 583	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define fEM_A5MV01RC1	 BUFFER[2016]	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define idfEM_A5MV01RC1	 584	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define iEM_TERNL2	 BUFFER[2021]	//(TERNL2) Неисправности НЛ2
#define idiEM_TERNL2	 585	//(TERNL2) Неисправности НЛ2
#define fEM_B5MC01RC1	 BUFFER[2024]	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define idfEM_B5MC01RC1	 586	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define fEM_B5MV01RC1	 BUFFER[2029]	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define idfEM_B5MV01RC1	 587	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define lEM_R8AD10LC1	 BUFFER[2034]	//(R8AD10LC1) Установить аварийный НИ от ИС
#define idlEM_R8AD10LC1	 588	//(R8AD10LC1) Установить аварийный НИ от ИС
#define fEM_A1UC08RIM	 BUFFER[2036]	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define idfEM_A1UC08RIM	 589	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define fEM_A2UC08RIM	 BUFFER[2041]	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define idfEM_A2UC08RIM	 590	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define fEM_A3UC08RIM	 BUFFER[2046]	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define idfEM_A3UC08RIM	 591	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define iEM_TERB2SS33LIM	 BUFFER[2051]	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define idiEM_TERB2SS33LIM	 592	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define iEM_TERA1VP81LIM	 BUFFER[2054]	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define idiEM_TERA1VP81LIM	 593	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define iEM_TERB1VP81LIM	 BUFFER[2057]	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define idiEM_TERB1VP81LIM	 594	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define fEM_A0UT03RSP	 BUFFER[2060]	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define idfEM_A0UT03RSP	 595	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define fEM_A0UR01RSP	 BUFFER[2065]	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define idfEM_A0UR01RSP	 596	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define fEM_A0UR02RSP	 BUFFER[2070]	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define idfEM_A0UR02RSP	 597	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define fEM_B0UT03RSP	 BUFFER[2075]	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define idfEM_B0UT03RSP	 598	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define fEM_A1MC01RSP	 BUFFER[2080]	//(A1MC01RSP) Стартовая координата  ББ1
#define idfEM_A1MC01RSP	 599	//(A1MC01RSP) Стартовая координата  ББ1
#define fEM_A1MC02RSP	 BUFFER[2085]	//(A1MC02RSP) Стартовая координата штока ББ1
#define idfEM_A1MC02RSP	 600	//(A1MC02RSP) Стартовая координата штока ББ1
#define fEM_A1MV01RSP	 BUFFER[2090]	//(A1MV01RSP) Стартовая скорость движения  ББ1
#define idfEM_A1MV01RSP	 601	//(A1MV01RSP) Стартовая скорость движения  ББ1
#define fEM_A1MV02RSP	 BUFFER[2095]	//(A1MV02RSP) Стартовая скорость движения  ББ1
#define idfEM_A1MV02RSP	 602	//(A1MV02RSP) Стартовая скорость движения  ББ1
#define fEM_B1MC01RSP	 BUFFER[2100]	//(B1MC01RSP) Стартовая координата  ББ2
#define idfEM_B1MC01RSP	 603	//(B1MC01RSP) Стартовая координата  ББ2
#define fEM_B1MV01RSP	 BUFFER[2105]	//(B1MV01RSP) Стартовая скорость движения  ББ2
#define idfEM_B1MV01RSP	 604	//(B1MV01RSP) Стартовая скорость движения  ББ2
#define fEM_B1MC02RSP	 BUFFER[2110]	//(B1MC02RSP) Стартовая координата штока ББ2
#define idfEM_B1MC02RSP	 605	//(B1MC02RSP) Стартовая координата штока ББ2
#define fEM_B1MV02RSP	 BUFFER[2115]	//(B1MV02RSP) Стартовая скорость движения  ББ2
#define idfEM_B1MV02RSP	 606	//(B1MV02RSP) Стартовая скорость движения  ББ2
#define fEM_A2MC01RC1	 BUFFER[2120]	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define idfEM_A2MC01RC1	 607	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define fEM_A2MV01RC1	 BUFFER[2125]	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define idfEM_A2MV01RC1	 608	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define fEM_A2MC01RSP	 BUFFER[2130]	//(A2MC01RSP) Стартовая координата  РБ1
#define idfEM_A2MC01RSP	 609	//(A2MC01RSP) Стартовая координата  РБ1
#define fEM_A2MV01RSP	 BUFFER[2135]	//(A2MV01RSP) Стартовая скорость движения  РБ1
#define idfEM_A2MV01RSP	 610	//(A2MV01RSP) Стартовая скорость движения  РБ1
#define fEM_A2MC02RSP	 BUFFER[2140]	//(A2MC02RSP) Стартовая координата штока РБ1
#define idfEM_A2MC02RSP	 611	//(A2MC02RSP) Стартовая координата штока РБ1
#define fEM_A2MV02RSP	 BUFFER[2145]	//(A2MV02RSP) Стартовая скорость движения  РБ1
#define idfEM_A2MV02RSP	 612	//(A2MV02RSP) Стартовая скорость движения  РБ1
#define fEM_B2MC01RSP	 BUFFER[2150]	//(B2MC01RSP) Стартовая координата  РБ2
#define idfEM_B2MC01RSP	 613	//(B2MC01RSP) Стартовая координата  РБ2
#define fEM_B2MV01RSP	 BUFFER[2155]	//(B2MV01RSP) Стартовая скорость движения  РБ2
#define idfEM_B2MV01RSP	 614	//(B2MV01RSP) Стартовая скорость движения  РБ2
#define fEM_B2MC02RSP	 BUFFER[2160]	//(B2MC02RSP) Стартовая координата штока РБ2
#define idfEM_B2MC02RSP	 615	//(B2MC02RSP) Стартовая координата штока РБ2
#define fEM_B2MV02RSP	 BUFFER[2165]	//(B2MV02RSP) Стартовая скорость движения  РБ2
#define idfEM_B2MV02RSP	 616	//(B2MV02RSP) Стартовая скорость движения  РБ2
#define fEM_A3MC01RSP	 BUFFER[2170]	//(A3MC01RSP) Стартовая координата  ИС1
#define idfEM_A3MC01RSP	 617	//(A3MC01RSP) Стартовая координата  ИС1
#define fEM_A3MV01RSP	 BUFFER[2175]	//(A3MV01RSP) Стартовая скорость движения  ИС1
#define idfEM_A3MV01RSP	 618	//(A3MV01RSP) Стартовая скорость движения  ИС1
#define fEM_A3MC02RSP	 BUFFER[2180]	//(A3MC02RSP) Стартовая координата штока ИС1
#define idfEM_A3MC02RSP	 619	//(A3MC02RSP) Стартовая координата штока ИС1
#define fEM_A3MV02RSP	 BUFFER[2185]	//(A3MV02RSP) Стартовая скорость движения  ИС1
#define idfEM_A3MV02RSP	 620	//(A3MV02RSP) Стартовая скорость движения  ИС1
#define fEM_B3MC01RSP	 BUFFER[2190]	//(B3MC01RSP) Стартовая координата  ИС2
#define idfEM_B3MC01RSP	 621	//(B3MC01RSP) Стартовая координата  ИС2
#define fEM_B3MV01RSP	 BUFFER[2195]	//(B3MV01RSP) Стартовая скорость движения  ИС2
#define idfEM_B3MV01RSP	 622	//(B3MV01RSP) Стартовая скорость движения  ИС2
#define fEM_B3MC02RSP	 BUFFER[2200]	//(B3MC02RSP) Стартовая координата штока ИС2
#define idfEM_B3MC02RSP	 623	//(B3MC02RSP) Стартовая координата штока ИС2
#define fEM_B3MV02RSP	 BUFFER[2205]	//(B3MV02RSP) Стартовая скорость движения  ИС2
#define idfEM_B3MV02RSP	 624	//(B3MV02RSP) Стартовая скорость движения  ИС2
#define fEM_B8MC01RSP	 BUFFER[2210]	//(B8MC01RSP) Стартовая координата АЗ2
#define idfEM_B8MC01RSP	 625	//(B8MC01RSP) Стартовая координата АЗ2
#define fEM_B8MV01RSP	 BUFFER[2215]	//(B8MV01RSP) Стартовая скорость АЗ2
#define idfEM_B8MV01RSP	 626	//(B8MV01RSP) Стартовая скорость АЗ2
#define fEM_A8MC01RSP	 BUFFER[2220]	//(A8MC01RSP) Стартовая координата ДС2
#define idfEM_A8MC01RSP	 627	//(A8MC01RSP) Стартовая координата ДС2
#define fEM_A8MV01RSP	 BUFFER[2225]	//(A8MV01RSP) Стартовая скорость ДС2
#define idfEM_A8MV01RSP	 628	//(A8MV01RSP) Стартовая скорость ДС2
#define fEM_A6MC01RSP	 BUFFER[2230]	//(A6MC01RSP) Стартовая координата БЗ1
#define idfEM_A6MC01RSP	 629	//(A6MC01RSP) Стартовая координата БЗ1
#define fEM_A6MV01RSP	 BUFFER[2235]	//(A6MV01RSP) Стартовая скорость БЗ1
#define idfEM_A6MV01RSP	 630	//(A6MV01RSP) Стартовая скорость БЗ1
#define fEM_B6MC01RSP	 BUFFER[2240]	//(B6MC01RSP) Стартовая координата БЗ2
#define idfEM_B6MC01RSP	 631	//(B6MC01RSP) Стартовая координата БЗ2
#define fEM_B6MV01RSP	 BUFFER[2245]	//(B6MV01RSP) Стартовая скорость БЗ2
#define idfEM_B6MV01RSP	 632	//(B6MV01RSP) Стартовая скорость БЗ2
#define fEM_R3UC01RSP	 BUFFER[2250]	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define idfEM_R3UC01RSP	 633	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define fEM_R3UV01RSP	 BUFFER[2255]	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
#define idfEM_R3UV01RSP	 634	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
#define fEM_R5UC01RSP	 BUFFER[2260]	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define idfEM_R5UC01RSP	 635	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define fEM_R5UV01RSP	 BUFFER[2265]	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
#define idfEM_R5UV01RSP	 636	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
#define fEM_R6UC01RSP	 BUFFER[2270]	//(R6UC01RSP) Стартовая координата Кран-балки
#define idfEM_R6UC01RSP	 637	//(R6UC01RSP) Стартовая координата Кран-балки
#define fEM_R6UV01RSP	 BUFFER[2275]	//(R6UV01RSP) Стартовая скорость Кран-балки
#define idfEM_R6UV01RSP	 638	//(R6UV01RSP) Стартовая скорость Кран-балки
#define fEM_R2MC01RSP	 BUFFER[2280]	//(R2MC01RSP) Стартовая координата МДЗ2
#define idfEM_R2MC01RSP	 639	//(R2MC01RSP) Стартовая координата МДЗ2
#define fEM_R2MV01RSP	 BUFFER[2285]	//(R2MV01RSP) Стартовая скорость МДЗ2
#define idfEM_R2MV01RSP	 640	//(R2MV01RSP) Стартовая скорость МДЗ2
#define fEM_R1MC01RSP	 BUFFER[2290]	//(R1MC01RSP) Стартовая координата МДЗ1
#define idfEM_R1MC01RSP	 641	//(R1MC01RSP) Стартовая координата МДЗ1
#define fEM_R1MV01RSP	 BUFFER[2295]	//(R1MV01RSP) Стартовая скорость МДЗ1
#define idfEM_R1MV01RSP	 642	//(R1MV01RSP) Стартовая скорость МДЗ1
#define fEM_A5MC01RSP	 BUFFER[2300]	//(A5MC01RSP) Стартовая координата НЛ1
#define idfEM_A5MC01RSP	 643	//(A5MC01RSP) Стартовая координата НЛ1
#define fEM_A5MV01RSP	 BUFFER[2305]	//(A5MV01RSP) Стартовая скорость НЛ1
#define idfEM_A5MV01RSP	 644	//(A5MV01RSP) Стартовая скорость НЛ1
#define fEM_B5MC01RSP	 BUFFER[2310]	//(B5MC01RSP) Стартовая координата НЛ2
#define idfEM_B5MC01RSP	 645	//(B5MC01RSP) Стартовая координата НЛ2
#define fEM_B5MV01RSP	 BUFFER[2315]	//(B5MV01RSP) Стартовая скорость НЛ2
#define idfEM_B5MV01RSP	 646	//(B5MV01RSP) Стартовая скорость НЛ2
#define fEM_A9MC01RSP	 BUFFER[2320]	//(A9MC01RSP) Стартовая координата НИ ДС1
#define idfEM_A9MC01RSP	 647	//(A9MC01RSP) Стартовая координата НИ ДС1
#define fEM_A9MV01RSP	 BUFFER[2325]	//(A9MV01RSP) Стартовая скорость НИ ДС1
#define idfEM_A9MV01RSP	 648	//(A9MV01RSP) Стартовая скорость НИ ДС1
#define fEM_B9MC01RSP	 BUFFER[2330]	//(B9MC01RSP) Стартовая координата НИ ДС2
#define idfEM_B9MC01RSP	 649	//(B9MC01RSP) Стартовая координата НИ ДС2
#define fEM_B9MV01RSP	 BUFFER[2335]	//(B9MV01RSP) Стартовая скорость НИ ДС2
#define idfEM_B9MV01RSP	 650	//(B9MV01RSP) Стартовая скорость НИ ДС2
#define fEM_A4MC01RSP	 BUFFER[2340]	//(A4MC01RSP) Стартовая координата НИ1
#define idfEM_A4MC01RSP	 651	//(A4MC01RSP) Стартовая координата НИ1
#define fEM_A4MV01RSP	 BUFFER[2345]	//(A4MV01RSP) Стартовая скорость НИ1
#define idfEM_A4MV01RSP	 652	//(A4MV01RSP) Стартовая скорость НИ1
#define fEM_B4MC01RSP	 BUFFER[2350]	//(B4MC01RSP) Стартовая координата НИ2
#define idfEM_B4MC01RSP	 653	//(B4MC01RSP) Стартовая координата НИ2
#define fEM_B4MV01RSP	 BUFFER[2355]	//(B4MV01RSP) Стартовая скорость НИ2
#define idfEM_B4MV01RSP	 654	//(B4MV01RSP) Стартовая скорость НИ2
#define fEM_R4MC01RSP	 BUFFER[2360]	//(R4MC01RSP) Стартовая координата тележки
#define idfEM_R4MC01RSP	 655	//(R4MC01RSP) Стартовая координата тележки
#define fEM_R4MV01RSP	 BUFFER[2365]	//(R4MV01RSP) Стартовая скорость тележки
#define idfEM_R4MV01RSP	 656	//(R4MV01RSP) Стартовая скорость тележки
#define fEM_A1MV01RC1	 BUFFER[2370]	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define idfEM_A1MV01RC1	 657	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define iEM_TERB7MS31LIM	 BUFFER[2375]	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define idiEM_TERB7MS31LIM	 658	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define iEM_TERA7MS31LIM	 BUFFER[2378]	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define idiEM_TERA7MS31LIM	 659	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define fEM_R7UY00RSS	 BUFFER[2381]	//(R7UY00RSS) Y-координата АЗ1 см
#define idfEM_R7UY00RSS	 660	//(R7UY00RSS) Y-координата АЗ1 см
#define iEM_TERA6VS12LIM	 BUFFER[2386]	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define idiEM_TERA6VS12LIM	 661	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define iEM_TERA6VS22LIM	 BUFFER[2389]	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define idiEM_TERA6VS22LIM	 662	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define iEM_TERB6VS12LIM	 BUFFER[2392]	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define idiEM_TERB6VS12LIM	 663	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define iEM_TERB6VS22LIM	 BUFFER[2395]	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define idiEM_TERB6VS22LIM	 664	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define iEM_TERA5VS22LIM	 BUFFER[2398]	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define idiEM_TERA5VS22LIM	 665	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define iEM_TERA5VS12LIM	 BUFFER[2401]	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define idiEM_TERA5VS12LIM	 666	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define iEM_TERB5VS12LIM	 BUFFER[2404]	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define idiEM_TERB5VS12LIM	 667	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define iEM_TERB5VS22LIM	 BUFFER[2407]	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define idiEM_TERB5VS22LIM	 668	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define iEM_TERR1VS12LIM	 BUFFER[2410]	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define idiEM_TERR1VS12LIM	 669	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define iEM_TERR1VS22LIM	 BUFFER[2413]	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define idiEM_TERR1VS22LIM	 670	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define iEM_TERR2VS12LIM	 BUFFER[2416]	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define idiEM_TERR2VS12LIM	 671	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define iEM_TERR2VS22LIM	 BUFFER[2419]	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define idiEM_TERR2VS22LIM	 672	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define iEM_TERR4VS12LDU	 BUFFER[2422]	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS12LDU	 673	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR4VS22LDU	 BUFFER[2425]	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS22LDU	 674	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define fEM_R4UC23RIM	 BUFFER[2428]	//(R4UC23RIM) Y-координата АЗ1
#define idfEM_R4UC23RIM	 675	//(R4UC23RIM) Y-координата АЗ1
#define fEM_A0UX13RSS	 BUFFER[2433]	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	 676	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	 BUFFER[2438]	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	 677	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	 BUFFER[2443]	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	 678	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_R7UX13RSS	 BUFFER[2448]	//(R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	 679	//(R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	 BUFFER[2453]	//(R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	 680	//(R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	 BUFFER[2458]	//(R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	 681	//(R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY13RSS	 BUFFER[2463]	//(R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	 682	//(R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	 BUFFER[2468]	//(R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	 683	//(R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	 BUFFER[2473]	//(R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	 684	//(R7UY15RSS) Y-координата камеры R7IN53
#define fEM_R7UX16RSS	 BUFFER[2478]	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define idfEM_R7UX16RSS	 685	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define bFirstEnterFlag	 BUFFER[2483]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 686	//(bFirstEnterFlag) 
#define internal1_m894_Chim0	 BUFFER[2485]	//(internal1_m894_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m894_Chim0	 687	//(internal1_m894_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m884_Chim0	 BUFFER[2490]	//(internal1_m884_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m884_Chim0	 688	//(internal1_m884_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m876_Chim0	 BUFFER[2495]	//(internal1_m876_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m876_Chim0	 689	//(internal1_m876_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m831_Out10	 BUFFER[2500]	//(internal1_m831_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m831_Out10	 690	//(internal1_m831_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m830_Out10	 BUFFER[2502]	//(internal1_m830_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m830_Out10	 691	//(internal1_m830_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1014_Out10	 BUFFER[2504]	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1014_Out10	 692	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1013_Out10	 BUFFER[2506]	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1013_Out10	 693	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1012_Out10	 BUFFER[2508]	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1012_Out10	 694	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1011_Out10	 BUFFER[2510]	//(internal1_m1011_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1011_Out10	 695	//(internal1_m1011_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m693_Out10	 BUFFER[2512]	//(internal1_m693_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m693_Out10	 696	//(internal1_m693_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m692_Out10	 BUFFER[2514]	//(internal1_m692_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m692_Out10	 697	//(internal1_m692_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m671_Out10	 BUFFER[2516]	//(internal1_m671_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m671_Out10	 698	//(internal1_m671_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m670_Out10	 BUFFER[2518]	//(internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m670_Out10	 699	//(internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m691_Out10	 BUFFER[2520]	//(internal1_m691_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m691_Out10	 700	//(internal1_m691_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m690_Out10	 BUFFER[2522]	//(internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m690_Out10	 701	//(internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m669_Out10	 BUFFER[2524]	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m669_Out10	 702	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m668_Out10	 BUFFER[2526]	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m668_Out10	 703	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m529_Out10	 BUFFER[2528]	//(internal1_m529_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m529_Out10	 704	//(internal1_m529_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m545_Out10	 BUFFER[2530]	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m545_Out10	 705	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m411_Out10	 BUFFER[2532]	//(internal1_m411_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m411_Out10	 706	//(internal1_m411_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m488_q0	 BUFFER[2534]	//(internal1_m488_q0) q0 - внутренний параметр
#define idinternal1_m488_q0	 707	//(internal1_m488_q0) q0 - внутренний параметр
#define internal1_m489_q0	 BUFFER[2536]	//(internal1_m489_q0) q0 - внутренний параметр
#define idinternal1_m489_q0	 708	//(internal1_m489_q0) q0 - внутренний параметр
#define internal1_m474_q0	 BUFFER[2538]	//(internal1_m474_q0) q0 - внутренний параметр
#define idinternal1_m474_q0	 709	//(internal1_m474_q0) q0 - внутренний параметр
#define internal1_m475_q0	 BUFFER[2540]	//(internal1_m475_q0) q0 - внутренний параметр
#define idinternal1_m475_q0	 710	//(internal1_m475_q0) q0 - внутренний параметр
#define internal1_m644_tx	 BUFFER[2542]	//(internal1_m644_tx) tx - время накопленное сек
#define idinternal1_m644_tx	 711	//(internal1_m644_tx) tx - время накопленное сек
#define internal1_m644_y0	 BUFFER[2547]	//(internal1_m644_y0) y0
#define idinternal1_m644_y0	 712	//(internal1_m644_y0) y0
#define internal1_m632_tx	 BUFFER[2548]	//(internal1_m632_tx) tx - время накопленное сек
#define idinternal1_m632_tx	 713	//(internal1_m632_tx) tx - время накопленное сек
#define internal1_m632_y0	 BUFFER[2553]	//(internal1_m632_y0) y0
#define idinternal1_m632_y0	 714	//(internal1_m632_y0) y0
#define internal1_m618_tx	 BUFFER[2554]	//(internal1_m618_tx) tx - время накопленное сек
#define idinternal1_m618_tx	 715	//(internal1_m618_tx) tx - время накопленное сек
#define internal1_m618_y0	 BUFFER[2559]	//(internal1_m618_y0) y0
#define idinternal1_m618_y0	 716	//(internal1_m618_y0) y0
#define internal1_m616_tx	 BUFFER[2560]	//(internal1_m616_tx) tx - время накопленное сек
#define idinternal1_m616_tx	 717	//(internal1_m616_tx) tx - время накопленное сек
#define internal1_m616_y0	 BUFFER[2565]	//(internal1_m616_y0) y0
#define idinternal1_m616_y0	 718	//(internal1_m616_y0) y0
#define internal1_m208_Out10	 BUFFER[2566]	//(internal1_m208_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m208_Out10	 719	//(internal1_m208_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m225_Out10	 BUFFER[2568]	//(internal1_m225_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m225_Out10	 720	//(internal1_m225_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m41_Out10	 BUFFER[2570]	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m41_Out10	 721	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m56_Out10	 BUFFER[2572]	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m56_Out10	 722	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m985_Out10	 BUFFER[2574]	//(internal1_m985_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m985_Out10	 723	//(internal1_m985_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m982_Out10	 BUFFER[2576]	//(internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m982_Out10	 724	//(internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m981_Out10	 BUFFER[2578]	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m981_Out10	 725	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m984_Xtek0	 BUFFER[2580]	//(internal1_m984_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m984_Xtek0	 726	//(internal1_m984_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m967_Xtek0	 BUFFER[2585]	//(internal1_m967_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m967_Xtek0	 727	//(internal1_m967_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m968_Out10	 BUFFER[2590]	//(internal1_m968_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m968_Out10	 728	//(internal1_m968_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m965_Out10	 BUFFER[2592]	//(internal1_m965_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m965_Out10	 729	//(internal1_m965_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m964_Out10	 BUFFER[2594]	//(internal1_m964_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m964_Out10	 730	//(internal1_m964_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1052_Out10	 BUFFER[2596]	//(internal1_m1052_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1052_Out10	 731	//(internal1_m1052_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1033_Out10	 BUFFER[2598]	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1033_Out10	 732	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1032_Out10	 BUFFER[2600]	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1032_Out10	 733	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1031_Out10	 BUFFER[2602]	//(internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1031_Out10	 734	//(internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m852_Out10	 BUFFER[2604]	//(internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m852_Out10	 735	//(internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m854_Out10	 BUFFER[2606]	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m854_Out10	 736	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m851_Out10	 BUFFER[2608]	//(internal1_m851_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m851_Out10	 737	//(internal1_m851_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m853_Out10	 BUFFER[2610]	//(internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m853_Out10	 738	//(internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m827_Out10	 BUFFER[2612]	//(internal1_m827_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m827_Out10	 739	//(internal1_m827_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m828_Out10	 BUFFER[2614]	//(internal1_m828_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m828_Out10	 740	//(internal1_m828_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m826_Out10	 BUFFER[2616]	//(internal1_m826_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m826_Out10	 741	//(internal1_m826_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m825_Out10	 BUFFER[2618]	//(internal1_m825_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m825_Out10	 742	//(internal1_m825_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1047_Out10	 BUFFER[2620]	//(internal1_m1047_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1047_Out10	 743	//(internal1_m1047_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m999_Out10	 BUFFER[2622]	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m999_Out10	 744	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m998_Out10	 BUFFER[2624]	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m998_Out10	 745	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m997_Out10	 BUFFER[2626]	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m997_Out10	 746	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m996_Out10	 BUFFER[2628]	//(internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m996_Out10	 747	//(internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1048_Out10	 BUFFER[2630]	//(internal1_m1048_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1048_Out10	 748	//(internal1_m1048_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1029_Out10	 BUFFER[2632]	//(internal1_m1029_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1029_Out10	 749	//(internal1_m1029_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m829_Out10	 BUFFER[2634]	//(internal1_m829_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m829_Out10	 750	//(internal1_m829_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1030_Out10	 BUFFER[2636]	//(internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1030_Out10	 751	//(internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1028_Out10	 BUFFER[2638]	//(internal1_m1028_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1028_Out10	 752	//(internal1_m1028_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1049_Out10	 BUFFER[2640]	//(internal1_m1049_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1049_Out10	 753	//(internal1_m1049_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1027_Out10	 BUFFER[2642]	//(internal1_m1027_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1027_Out10	 754	//(internal1_m1027_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1010_Out10	 BUFFER[2644]	//(internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1010_Out10	 755	//(internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m995_Out10	 BUFFER[2646]	//(internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m995_Out10	 756	//(internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m546_Out10	 BUFFER[2648]	//(internal1_m546_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m546_Out10	 757	//(internal1_m546_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m421_Xtek0	 BUFFER[2650]	//(internal1_m421_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m421_Xtek0	 758	//(internal1_m421_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m412_Out10	 BUFFER[2655]	//(internal1_m412_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m412_Out10	 759	//(internal1_m412_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m414_Out10	 BUFFER[2657]	//(internal1_m414_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m414_Out10	 760	//(internal1_m414_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m413_Out10	 BUFFER[2659]	//(internal1_m413_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m413_Out10	 761	//(internal1_m413_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m867_Out10	 BUFFER[2661]	//(internal1_m867_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m867_Out10	 762	//(internal1_m867_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m868_Out10	 BUFFER[2663]	//(internal1_m868_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m868_Out10	 763	//(internal1_m868_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m866_Out10	 BUFFER[2665]	//(internal1_m866_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m866_Out10	 764	//(internal1_m866_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1051_Out10	 BUFFER[2667]	//(internal1_m1051_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1051_Out10	 765	//(internal1_m1051_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m706_Out10	 BUFFER[2669]	//(internal1_m706_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m706_Out10	 766	//(internal1_m706_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m707_Out10	 BUFFER[2671]	//(internal1_m707_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m707_Out10	 767	//(internal1_m707_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m704_Out10	 BUFFER[2673]	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m704_Out10	 768	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m705_Out10	 BUFFER[2675]	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m705_Out10	 769	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m562_Out10	 BUFFER[2677]	//(internal1_m562_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m562_Out10	 770	//(internal1_m562_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m561_Out10	 BUFFER[2679]	//(internal1_m561_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m561_Out10	 771	//(internal1_m561_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m848_Xtek0	 BUFFER[2681]	//(internal1_m848_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m848_Xtek0	 772	//(internal1_m848_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m850_Xtek0	 BUFFER[2686]	//(internal1_m850_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m850_Xtek0	 773	//(internal1_m850_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m703_Out10	 BUFFER[2691]	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m703_Out10	 774	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m687_Out10	 BUFFER[2693]	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m687_Out10	 775	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m667_Out10	 BUFFER[2695]	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m667_Out10	 776	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m686_Out10	 BUFFER[2697]	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m686_Out10	 777	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m666_Out10	 BUFFER[2699]	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m666_Out10	 778	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m339_Out10	 BUFFER[2701]	//(internal1_m339_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m339_Out10	 779	//(internal1_m339_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m338_Out10	 BUFFER[2703]	//(internal1_m338_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m338_Out10	 780	//(internal1_m338_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m323_Out10	 BUFFER[2705]	//(internal1_m323_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m323_Out10	 781	//(internal1_m323_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m322_Out10	 BUFFER[2707]	//(internal1_m322_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m322_Out10	 782	//(internal1_m322_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m563_Out10	 BUFFER[2709]	//(internal1_m563_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m563_Out10	 783	//(internal1_m563_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m352_Out10	 BUFFER[2711]	//(internal1_m352_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m352_Out10	 784	//(internal1_m352_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m336_Xtek0	 BUFFER[2713]	//(internal1_m336_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m336_Xtek0	 785	//(internal1_m336_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m351_Out10	 BUFFER[2718]	//(internal1_m351_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m351_Out10	 786	//(internal1_m351_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m349_Out10	 BUFFER[2720]	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m349_Out10	 787	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m329_Xtek0	 BUFFER[2722]	//(internal1_m329_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m329_Xtek0	 788	//(internal1_m329_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m350_Out10	 BUFFER[2727]	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m350_Out10	 789	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m321_Out10	 BUFFER[2729]	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m321_Out10	 790	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m337_Out10	 BUFFER[2731]	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m337_Out10	 791	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m433_Out10	 BUFFER[2733]	//(internal1_m433_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m433_Out10	 792	//(internal1_m433_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m434_Xtek0	 BUFFER[2735]	//(internal1_m434_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m434_Xtek0	 793	//(internal1_m434_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m432_Out10	 BUFFER[2740]	//(internal1_m432_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m432_Out10	 794	//(internal1_m432_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m431_Out10	 BUFFER[2742]	//(internal1_m431_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m431_Out10	 795	//(internal1_m431_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m430_Out10	 BUFFER[2744]	//(internal1_m430_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m430_Out10	 796	//(internal1_m430_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1050_Out10	 BUFFER[2746]	//(internal1_m1050_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1050_Out10	 797	//(internal1_m1050_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m150_Out10	 BUFFER[2748]	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m150_Out10	 798	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m149_Out10	 BUFFER[2750]	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m149_Out10	 799	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m197_tx	 BUFFER[2752]	//(internal1_m197_tx) tx - внутренний параметр
#define idinternal1_m197_tx	 800	//(internal1_m197_tx) tx - внутренний параметр
#define internal1_m30_tx	 BUFFER[2755]	//(internal1_m30_tx) tx - внутренний параметр
#define idinternal1_m30_tx	 801	//(internal1_m30_tx) tx - внутренний параметр
#define internal1_m478_Pav0	 BUFFER[2758]	//(internal1_m478_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m478_Pav0	 802	//(internal1_m478_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m478_Zav0	 BUFFER[2760]	//(internal1_m478_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m478_Zav0	 803	//(internal1_m478_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m478_Pv0	 BUFFER[2762]	//(internal1_m478_Pv0)  - Пер. выключатель механизма
#define idinternal1_m478_Pv0	 804	//(internal1_m478_Pv0)  - Пер. выключатель механизма
#define internal1_m478_Zv0	 BUFFER[2764]	//(internal1_m478_Zv0)  - Зад. выключатель механизма
#define idinternal1_m478_Zv0	 805	//(internal1_m478_Zv0)  - Зад. выключатель механизма
#define internal1_m478_RA00	 BUFFER[2766]	//(internal1_m478_RA00)  - последнее задание вперед
#define idinternal1_m478_RA00	 806	//(internal1_m478_RA00)  - последнее задание вперед
#define internal1_m478_RA10	 BUFFER[2768]	//(internal1_m478_RA10)  - последнее задание назад
#define idinternal1_m478_RA10	 807	//(internal1_m478_RA10)  - последнее задание назад
#define internal1_m478_MyFirstEnterFlag	 BUFFER[2770]	//(internal1_m478_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m478_MyFirstEnterFlag	 808	//(internal1_m478_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m492_Pav0	 BUFFER[2772]	//(internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m492_Pav0	 809	//(internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m492_Zav0	 BUFFER[2774]	//(internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m492_Zav0	 810	//(internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m492_Pv0	 BUFFER[2776]	//(internal1_m492_Pv0)  - Пер. выключатель механизма
#define idinternal1_m492_Pv0	 811	//(internal1_m492_Pv0)  - Пер. выключатель механизма
#define internal1_m492_Zv0	 BUFFER[2778]	//(internal1_m492_Zv0)  - Зад. выключатель механизма
#define idinternal1_m492_Zv0	 812	//(internal1_m492_Zv0)  - Зад. выключатель механизма
#define internal1_m492_RA00	 BUFFER[2780]	//(internal1_m492_RA00)  - последнее задание вперед
#define idinternal1_m492_RA00	 813	//(internal1_m492_RA00)  - последнее задание вперед
#define internal1_m492_RA10	 BUFFER[2782]	//(internal1_m492_RA10)  - последнее задание назад
#define idinternal1_m492_RA10	 814	//(internal1_m492_RA10)  - последнее задание назад
#define internal1_m492_MyFirstEnterFlag	 BUFFER[2784]	//(internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m492_MyFirstEnterFlag	 815	//(internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m480_Pav0	 BUFFER[2786]	//(internal1_m480_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m480_Pav0	 816	//(internal1_m480_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m480_Zav0	 BUFFER[2788]	//(internal1_m480_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m480_Zav0	 817	//(internal1_m480_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m480_Pv0	 BUFFER[2790]	//(internal1_m480_Pv0)  - Пер. выключатель механизма
#define idinternal1_m480_Pv0	 818	//(internal1_m480_Pv0)  - Пер. выключатель механизма
#define internal1_m480_Zv0	 BUFFER[2792]	//(internal1_m480_Zv0)  - Зад. выключатель механизма
#define idinternal1_m480_Zv0	 819	//(internal1_m480_Zv0)  - Зад. выключатель механизма
#define internal1_m480_RA00	 BUFFER[2794]	//(internal1_m480_RA00)  - последнее задание вперед
#define idinternal1_m480_RA00	 820	//(internal1_m480_RA00)  - последнее задание вперед
#define internal1_m480_RA10	 BUFFER[2796]	//(internal1_m480_RA10)  - последнее задание назад
#define idinternal1_m480_RA10	 821	//(internal1_m480_RA10)  - последнее задание назад
#define internal1_m480_MyFirstEnterFlag	 BUFFER[2798]	//(internal1_m480_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m480_MyFirstEnterFlag	 822	//(internal1_m480_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m623_Pav0	 BUFFER[2800]	//(internal1_m623_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m623_Pav0	 823	//(internal1_m623_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m623_Zav0	 BUFFER[2802]	//(internal1_m623_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m623_Zav0	 824	//(internal1_m623_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m623_Pv0	 BUFFER[2804]	//(internal1_m623_Pv0)  - Пер. выключатель механизма
#define idinternal1_m623_Pv0	 825	//(internal1_m623_Pv0)  - Пер. выключатель механизма
#define internal1_m623_Zv0	 BUFFER[2806]	//(internal1_m623_Zv0)  - Зад. выключатель механизма
#define idinternal1_m623_Zv0	 826	//(internal1_m623_Zv0)  - Зад. выключатель механизма
#define internal1_m623_RA00	 BUFFER[2808]	//(internal1_m623_RA00)  - последнее задание вперед
#define idinternal1_m623_RA00	 827	//(internal1_m623_RA00)  - последнее задание вперед
#define internal1_m623_RA10	 BUFFER[2810]	//(internal1_m623_RA10)  - последнее задание назад
#define idinternal1_m623_RA10	 828	//(internal1_m623_RA10)  - последнее задание назад
#define internal1_m623_MyFirstEnterFlag	 BUFFER[2812]	//(internal1_m623_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m623_MyFirstEnterFlag	 829	//(internal1_m623_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m620_Pav0	 BUFFER[2814]	//(internal1_m620_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m620_Pav0	 830	//(internal1_m620_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m620_Zav0	 BUFFER[2816]	//(internal1_m620_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m620_Zav0	 831	//(internal1_m620_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m620_Pv0	 BUFFER[2818]	//(internal1_m620_Pv0)  - Пер. выключатель механизма
#define idinternal1_m620_Pv0	 832	//(internal1_m620_Pv0)  - Пер. выключатель механизма
#define internal1_m620_Zv0	 BUFFER[2820]	//(internal1_m620_Zv0)  - Зад. выключатель механизма
#define idinternal1_m620_Zv0	 833	//(internal1_m620_Zv0)  - Зад. выключатель механизма
#define internal1_m620_RA00	 BUFFER[2822]	//(internal1_m620_RA00)  - последнее задание вперед
#define idinternal1_m620_RA00	 834	//(internal1_m620_RA00)  - последнее задание вперед
#define internal1_m620_RA10	 BUFFER[2824]	//(internal1_m620_RA10)  - последнее задание назад
#define idinternal1_m620_RA10	 835	//(internal1_m620_RA10)  - последнее задание назад
#define internal1_m620_MyFirstEnterFlag	 BUFFER[2826]	//(internal1_m620_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m620_MyFirstEnterFlag	 836	//(internal1_m620_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m606_Pav0	 BUFFER[2828]	//(internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m606_Pav0	 837	//(internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m606_Zav0	 BUFFER[2830]	//(internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m606_Zav0	 838	//(internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m606_Pv0	 BUFFER[2832]	//(internal1_m606_Pv0)  - Пер. выключатель механизма
#define idinternal1_m606_Pv0	 839	//(internal1_m606_Pv0)  - Пер. выключатель механизма
#define internal1_m606_Zv0	 BUFFER[2834]	//(internal1_m606_Zv0)  - Зад. выключатель механизма
#define idinternal1_m606_Zv0	 840	//(internal1_m606_Zv0)  - Зад. выключатель механизма
#define internal1_m606_RA00	 BUFFER[2836]	//(internal1_m606_RA00)  - последнее задание вперед
#define idinternal1_m606_RA00	 841	//(internal1_m606_RA00)  - последнее задание вперед
#define internal1_m606_RA10	 BUFFER[2838]	//(internal1_m606_RA10)  - последнее задание назад
#define idinternal1_m606_RA10	 842	//(internal1_m606_RA10)  - последнее задание назад
#define internal1_m606_MyFirstEnterFlag	 BUFFER[2840]	//(internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m606_MyFirstEnterFlag	 843	//(internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m605_Pav0	 BUFFER[2842]	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m605_Pav0	 844	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m605_Zav0	 BUFFER[2844]	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m605_Zav0	 845	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m605_Pv0	 BUFFER[2846]	//(internal1_m605_Pv0)  - Пер. выключатель механизма
#define idinternal1_m605_Pv0	 846	//(internal1_m605_Pv0)  - Пер. выключатель механизма
#define internal1_m605_Zv0	 BUFFER[2848]	//(internal1_m605_Zv0)  - Зад. выключатель механизма
#define idinternal1_m605_Zv0	 847	//(internal1_m605_Zv0)  - Зад. выключатель механизма
#define internal1_m605_RA00	 BUFFER[2850]	//(internal1_m605_RA00)  - последнее задание вперед
#define idinternal1_m605_RA00	 848	//(internal1_m605_RA00)  - последнее задание вперед
#define internal1_m605_RA10	 BUFFER[2852]	//(internal1_m605_RA10)  - последнее задание назад
#define idinternal1_m605_RA10	 849	//(internal1_m605_RA10)  - последнее задание назад
#define internal1_m605_MyFirstEnterFlag	 BUFFER[2854]	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m605_MyFirstEnterFlag	 850	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m652_y0	 BUFFER[2856]	//(internal1_m652_y0) y0 - внутренний параметр
#define idinternal1_m652_y0	 851	//(internal1_m652_y0) y0 - внутренний параметр
#define internal1_m813_Chim0	 BUFFER[2861]	//(internal1_m813_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m813_Chim0	 852	//(internal1_m813_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m804_Chim0	 BUFFER[2866]	//(internal1_m804_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m804_Chim0	 853	//(internal1_m804_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m796_Chim0	 BUFFER[2871]	//(internal1_m796_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m796_Chim0	 854	//(internal1_m796_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m787_Chim0	 BUFFER[2876]	//(internal1_m787_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m787_Chim0	 855	//(internal1_m787_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m778_Chim0	 BUFFER[2881]	//(internal1_m778_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m778_Chim0	 856	//(internal1_m778_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m770_Chim0	 BUFFER[2886]	//(internal1_m770_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m770_Chim0	 857	//(internal1_m770_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m761_Chim0	 BUFFER[2891]	//(internal1_m761_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m761_Chim0	 858	//(internal1_m761_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m752_Chim0	 BUFFER[2896]	//(internal1_m752_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m752_Chim0	 859	//(internal1_m752_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m744_Chim0	 BUFFER[2901]	//(internal1_m744_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m744_Chim0	 860	//(internal1_m744_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m735_Chim0	 BUFFER[2906]	//(internal1_m735_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m735_Chim0	 861	//(internal1_m735_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m726_Chim0	 BUFFER[2911]	//(internal1_m726_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m726_Chim0	 862	//(internal1_m726_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m718_Chim0	 BUFFER[2916]	//(internal1_m718_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m718_Chim0	 863	//(internal1_m718_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m592_Pav0	 BUFFER[2921]	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m592_Pav0	 864	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m592_Zav0	 BUFFER[2923]	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m592_Zav0	 865	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m592_Pv0	 BUFFER[2925]	//(internal1_m592_Pv0)  - Пер. выключатель механизма
#define idinternal1_m592_Pv0	 866	//(internal1_m592_Pv0)  - Пер. выключатель механизма
#define internal1_m592_Zv0	 BUFFER[2927]	//(internal1_m592_Zv0)  - Зад. выключатель механизма
#define idinternal1_m592_Zv0	 867	//(internal1_m592_Zv0)  - Зад. выключатель механизма
#define internal1_m592_RA00	 BUFFER[2929]	//(internal1_m592_RA00)  - последнее задание вперед
#define idinternal1_m592_RA00	 868	//(internal1_m592_RA00)  - последнее задание вперед
#define internal1_m592_RA10	 BUFFER[2931]	//(internal1_m592_RA10)  - последнее задание назад
#define idinternal1_m592_RA10	 869	//(internal1_m592_RA10)  - последнее задание назад
#define internal1_m592_MyFirstEnterFlag	 BUFFER[2933]	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m592_MyFirstEnterFlag	 870	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m577_Pav0	 BUFFER[2935]	//(internal1_m577_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m577_Pav0	 871	//(internal1_m577_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m577_Zav0	 BUFFER[2937]	//(internal1_m577_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m577_Zav0	 872	//(internal1_m577_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m577_Pv0	 BUFFER[2939]	//(internal1_m577_Pv0)  - Пер. выключатель механизма
#define idinternal1_m577_Pv0	 873	//(internal1_m577_Pv0)  - Пер. выключатель механизма
#define internal1_m577_Zv0	 BUFFER[2941]	//(internal1_m577_Zv0)  - Зад. выключатель механизма
#define idinternal1_m577_Zv0	 874	//(internal1_m577_Zv0)  - Зад. выключатель механизма
#define internal1_m577_RA00	 BUFFER[2943]	//(internal1_m577_RA00)  - последнее задание вперед
#define idinternal1_m577_RA00	 875	//(internal1_m577_RA00)  - последнее задание вперед
#define internal1_m577_RA10	 BUFFER[2945]	//(internal1_m577_RA10)  - последнее задание назад
#define idinternal1_m577_RA10	 876	//(internal1_m577_RA10)  - последнее задание назад
#define internal1_m577_MyFirstEnterFlag	 BUFFER[2947]	//(internal1_m577_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m577_MyFirstEnterFlag	 877	//(internal1_m577_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m463_Pav0	 BUFFER[2949]	//(internal1_m463_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m463_Pav0	 878	//(internal1_m463_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m463_Zav0	 BUFFER[2951]	//(internal1_m463_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m463_Zav0	 879	//(internal1_m463_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m463_Pv0	 BUFFER[2953]	//(internal1_m463_Pv0)  - Пер. выключатель механизма
#define idinternal1_m463_Pv0	 880	//(internal1_m463_Pv0)  - Пер. выключатель механизма
#define internal1_m463_Zv0	 BUFFER[2955]	//(internal1_m463_Zv0)  - Зад. выключатель механизма
#define idinternal1_m463_Zv0	 881	//(internal1_m463_Zv0)  - Зад. выключатель механизма
#define internal1_m463_RA00	 BUFFER[2957]	//(internal1_m463_RA00)  - последнее задание вперед
#define idinternal1_m463_RA00	 882	//(internal1_m463_RA00)  - последнее задание вперед
#define internal1_m463_RA10	 BUFFER[2959]	//(internal1_m463_RA10)  - последнее задание назад
#define idinternal1_m463_RA10	 883	//(internal1_m463_RA10)  - последнее задание назад
#define internal1_m463_MyFirstEnterFlag	 BUFFER[2961]	//(internal1_m463_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m463_MyFirstEnterFlag	 884	//(internal1_m463_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m448_Pav0	 BUFFER[2963]	//(internal1_m448_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m448_Pav0	 885	//(internal1_m448_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m448_Zav0	 BUFFER[2965]	//(internal1_m448_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m448_Zav0	 886	//(internal1_m448_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m448_Pv0	 BUFFER[2967]	//(internal1_m448_Pv0)  - Пер. выключатель механизма
#define idinternal1_m448_Pv0	 887	//(internal1_m448_Pv0)  - Пер. выключатель механизма
#define internal1_m448_Zv0	 BUFFER[2969]	//(internal1_m448_Zv0)  - Зад. выключатель механизма
#define idinternal1_m448_Zv0	 888	//(internal1_m448_Zv0)  - Зад. выключатель механизма
#define internal1_m448_RA00	 BUFFER[2971]	//(internal1_m448_RA00)  - последнее задание вперед
#define idinternal1_m448_RA00	 889	//(internal1_m448_RA00)  - последнее задание вперед
#define internal1_m448_RA10	 BUFFER[2973]	//(internal1_m448_RA10)  - последнее задание назад
#define idinternal1_m448_RA10	 890	//(internal1_m448_RA10)  - последнее задание назад
#define internal1_m448_MyFirstEnterFlag	 BUFFER[2975]	//(internal1_m448_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m448_MyFirstEnterFlag	 891	//(internal1_m448_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m504_Pav0	 BUFFER[2977]	//(internal1_m504_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m504_Pav0	 892	//(internal1_m504_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m504_Zav0	 BUFFER[2979]	//(internal1_m504_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m504_Zav0	 893	//(internal1_m504_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m504_Pv0	 BUFFER[2981]	//(internal1_m504_Pv0)  - Пер. выключатель механизма
#define idinternal1_m504_Pv0	 894	//(internal1_m504_Pv0)  - Пер. выключатель механизма
#define internal1_m504_Zv0	 BUFFER[2983]	//(internal1_m504_Zv0)  - Зад. выключатель механизма
#define idinternal1_m504_Zv0	 895	//(internal1_m504_Zv0)  - Зад. выключатель механизма
#define internal1_m504_RA00	 BUFFER[2985]	//(internal1_m504_RA00)  - последнее задание вперед
#define idinternal1_m504_RA00	 896	//(internal1_m504_RA00)  - последнее задание вперед
#define internal1_m504_RA10	 BUFFER[2987]	//(internal1_m504_RA10)  - последнее задание назад
#define idinternal1_m504_RA10	 897	//(internal1_m504_RA10)  - последнее задание назад
#define internal1_m504_MyFirstEnterFlag	 BUFFER[2989]	//(internal1_m504_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m504_MyFirstEnterFlag	 898	//(internal1_m504_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m399_Pav0	 BUFFER[2991]	//(internal1_m399_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m399_Pav0	 899	//(internal1_m399_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m399_Zav0	 BUFFER[2993]	//(internal1_m399_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m399_Zav0	 900	//(internal1_m399_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m399_Pv0	 BUFFER[2995]	//(internal1_m399_Pv0)  - Пер. выключатель механизма
#define idinternal1_m399_Pv0	 901	//(internal1_m399_Pv0)  - Пер. выключатель механизма
#define internal1_m399_Zv0	 BUFFER[2997]	//(internal1_m399_Zv0)  - Зад. выключатель механизма
#define idinternal1_m399_Zv0	 902	//(internal1_m399_Zv0)  - Зад. выключатель механизма
#define internal1_m399_RA00	 BUFFER[2999]	//(internal1_m399_RA00)  - последнее задание вперед
#define idinternal1_m399_RA00	 903	//(internal1_m399_RA00)  - последнее задание вперед
#define internal1_m399_RA10	 BUFFER[3001]	//(internal1_m399_RA10)  - последнее задание назад
#define idinternal1_m399_RA10	 904	//(internal1_m399_RA10)  - последнее задание назад
#define internal1_m399_MyFirstEnterFlag	 BUFFER[3003]	//(internal1_m399_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m399_MyFirstEnterFlag	 905	//(internal1_m399_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m383_Pav0	 BUFFER[3005]	//(internal1_m383_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m383_Pav0	 906	//(internal1_m383_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m383_Zav0	 BUFFER[3007]	//(internal1_m383_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m383_Zav0	 907	//(internal1_m383_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m383_Pv0	 BUFFER[3009]	//(internal1_m383_Pv0)  - Пер. выключатель механизма
#define idinternal1_m383_Pv0	 908	//(internal1_m383_Pv0)  - Пер. выключатель механизма
#define internal1_m383_Zv0	 BUFFER[3011]	//(internal1_m383_Zv0)  - Зад. выключатель механизма
#define idinternal1_m383_Zv0	 909	//(internal1_m383_Zv0)  - Зад. выключатель механизма
#define internal1_m383_RA00	 BUFFER[3013]	//(internal1_m383_RA00)  - последнее задание вперед
#define idinternal1_m383_RA00	 910	//(internal1_m383_RA00)  - последнее задание вперед
#define internal1_m383_RA10	 BUFFER[3015]	//(internal1_m383_RA10)  - последнее задание назад
#define idinternal1_m383_RA10	 911	//(internal1_m383_RA10)  - последнее задание назад
#define internal1_m383_MyFirstEnterFlag	 BUFFER[3017]	//(internal1_m383_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m383_MyFirstEnterFlag	 912	//(internal1_m383_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m366_Pav0	 BUFFER[3019]	//(internal1_m366_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m366_Pav0	 913	//(internal1_m366_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m366_Zav0	 BUFFER[3021]	//(internal1_m366_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m366_Zav0	 914	//(internal1_m366_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m366_Pv0	 BUFFER[3023]	//(internal1_m366_Pv0)  - Пер. выключатель механизма
#define idinternal1_m366_Pv0	 915	//(internal1_m366_Pv0)  - Пер. выключатель механизма
#define internal1_m366_Zv0	 BUFFER[3025]	//(internal1_m366_Zv0)  - Зад. выключатель механизма
#define idinternal1_m366_Zv0	 916	//(internal1_m366_Zv0)  - Зад. выключатель механизма
#define internal1_m366_RA00	 BUFFER[3027]	//(internal1_m366_RA00)  - последнее задание вперед
#define idinternal1_m366_RA00	 917	//(internal1_m366_RA00)  - последнее задание вперед
#define internal1_m366_RA10	 BUFFER[3029]	//(internal1_m366_RA10)  - последнее задание назад
#define idinternal1_m366_RA10	 918	//(internal1_m366_RA10)  - последнее задание назад
#define internal1_m366_MyFirstEnterFlag	 BUFFER[3031]	//(internal1_m366_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m366_MyFirstEnterFlag	 919	//(internal1_m366_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m906_Pav0	 BUFFER[3033]	//(internal1_m906_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m906_Pav0	 920	//(internal1_m906_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m906_Zav0	 BUFFER[3035]	//(internal1_m906_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m906_Zav0	 921	//(internal1_m906_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m906_Pv0	 BUFFER[3037]	//(internal1_m906_Pv0)  - Пер. выключатель механизма
#define idinternal1_m906_Pv0	 922	//(internal1_m906_Pv0)  - Пер. выключатель механизма
#define internal1_m906_Zv0	 BUFFER[3039]	//(internal1_m906_Zv0)  - Зад. выключатель механизма
#define idinternal1_m906_Zv0	 923	//(internal1_m906_Zv0)  - Зад. выключатель механизма
#define internal1_m906_RA00	 BUFFER[3041]	//(internal1_m906_RA00)  - последнее задание вперед
#define idinternal1_m906_RA00	 924	//(internal1_m906_RA00)  - последнее задание вперед
#define internal1_m906_RA10	 BUFFER[3043]	//(internal1_m906_RA10)  - последнее задание назад
#define idinternal1_m906_RA10	 925	//(internal1_m906_RA10)  - последнее задание назад
#define internal1_m906_MyFirstEnterFlag	 BUFFER[3045]	//(internal1_m906_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m906_MyFirstEnterFlag	 926	//(internal1_m906_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m182_C1	 BUFFER[3047]	//(internal1_m182_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m182_C1	 927	//(internal1_m182_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m182_C2	 BUFFER[3052]	//(internal1_m182_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m182_C2	 928	//(internal1_m182_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m182_C3	 BUFFER[3057]	//(internal1_m182_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m182_C3	 929	//(internal1_m182_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m182_C4	 BUFFER[3062]	//(internal1_m182_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m182_C4	 930	//(internal1_m182_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m182_C5	 BUFFER[3067]	//(internal1_m182_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m182_C5	 931	//(internal1_m182_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m182_C6	 BUFFER[3072]	//(internal1_m182_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m182_C6	 932	//(internal1_m182_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m182_N20	 BUFFER[3077]	//(internal1_m182_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m182_N20	 933	//(internal1_m182_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m182_C0	 BUFFER[3082]	//(internal1_m182_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m182_C0	 934	//(internal1_m182_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m182_ImpINI0	 BUFFER[3112]	//(internal1_m182_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m182_ImpINI0	 935	//(internal1_m182_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m182_MyFirstEnterFlag	 BUFFER[3114]	//(internal1_m182_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m182_MyFirstEnterFlag	 936	//(internal1_m182_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m300_Ppv0	 BUFFER[3116]	//(internal1_m300_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m300_Ppv0	 937	//(internal1_m300_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m300_Pav0	 BUFFER[3118]	//(internal1_m300_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m300_Pav0	 938	//(internal1_m300_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m300_Zav0	 BUFFER[3120]	//(internal1_m300_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m300_Zav0	 939	//(internal1_m300_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m300_RA00	 BUFFER[3122]	//(internal1_m300_RA00) RA00 - последнее задание вперед
#define idinternal1_m300_RA00	 940	//(internal1_m300_RA00) RA00 - последнее задание вперед
#define internal1_m300_RA10	 BUFFER[3124]	//(internal1_m300_RA10) RA10 - последнее задание назад
#define idinternal1_m300_RA10	 941	//(internal1_m300_RA10) RA10 - последнее задание назад
#define internal1_m300_RA50	 BUFFER[3126]	//(internal1_m300_RA50) Ra50 - последнее задание скорости
#define idinternal1_m300_RA50	 942	//(internal1_m300_RA50) Ra50 - последнее задание скорости
#define internal1_m300_fls	 BUFFER[3127]	//(internal1_m300_fls)  fls - флаг одношагового режима
#define idinternal1_m300_fls	 943	//(internal1_m300_fls)  fls - флаг одношагового режима
#define internal1_m300_flp	 BUFFER[3129]	//(internal1_m300_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m300_flp	 944	//(internal1_m300_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m300_MyFirstEnterFlag	 BUFFER[3131]	//(internal1_m300_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m300_MyFirstEnterFlag	 945	//(internal1_m300_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m133_Ppv0	 BUFFER[3133]	//(internal1_m133_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m133_Ppv0	 946	//(internal1_m133_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m133_Pav0	 BUFFER[3135]	//(internal1_m133_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m133_Pav0	 947	//(internal1_m133_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m133_Zav0	 BUFFER[3137]	//(internal1_m133_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m133_Zav0	 948	//(internal1_m133_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m133_RA00	 BUFFER[3139]	//(internal1_m133_RA00) RA00 - последнее задание вперед
#define idinternal1_m133_RA00	 949	//(internal1_m133_RA00) RA00 - последнее задание вперед
#define internal1_m133_RA10	 BUFFER[3141]	//(internal1_m133_RA10) RA10 - последнее задание назад
#define idinternal1_m133_RA10	 950	//(internal1_m133_RA10) RA10 - последнее задание назад
#define internal1_m133_RA50	 BUFFER[3143]	//(internal1_m133_RA50) Ra50 - последнее задание скорости
#define idinternal1_m133_RA50	 951	//(internal1_m133_RA50) Ra50 - последнее задание скорости
#define internal1_m133_fls	 BUFFER[3144]	//(internal1_m133_fls)  fls - флаг одношагового режима
#define idinternal1_m133_fls	 952	//(internal1_m133_fls)  fls - флаг одношагового режима
#define internal1_m133_flp	 BUFFER[3146]	//(internal1_m133_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m133_flp	 953	//(internal1_m133_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m133_MyFirstEnterFlag	 BUFFER[3148]	//(internal1_m133_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m133_MyFirstEnterFlag	 954	//(internal1_m133_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m266_Ppv0	 BUFFER[3150]	//(internal1_m266_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m266_Ppv0	 955	//(internal1_m266_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m266_Pav0	 BUFFER[3152]	//(internal1_m266_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m266_Pav0	 956	//(internal1_m266_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m266_Zav0	 BUFFER[3154]	//(internal1_m266_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m266_Zav0	 957	//(internal1_m266_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m266_RA00	 BUFFER[3156]	//(internal1_m266_RA00) RA00 - последнее задание вперед
#define idinternal1_m266_RA00	 958	//(internal1_m266_RA00) RA00 - последнее задание вперед
#define internal1_m266_RA10	 BUFFER[3158]	//(internal1_m266_RA10) RA10 - последнее задание назад
#define idinternal1_m266_RA10	 959	//(internal1_m266_RA10) RA10 - последнее задание назад
#define internal1_m266_RA50	 BUFFER[3160]	//(internal1_m266_RA50) Ra50 - последнее задание скорости
#define idinternal1_m266_RA50	 960	//(internal1_m266_RA50) Ra50 - последнее задание скорости
#define internal1_m266_fls	 BUFFER[3161]	//(internal1_m266_fls)  fls - флаг одношагового режима
#define idinternal1_m266_fls	 961	//(internal1_m266_fls)  fls - флаг одношагового режима
#define internal1_m266_flp	 BUFFER[3163]	//(internal1_m266_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m266_flp	 962	//(internal1_m266_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m266_MyFirstEnterFlag	 BUFFER[3165]	//(internal1_m266_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m266_MyFirstEnterFlag	 963	//(internal1_m266_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m96_Ppv0	 BUFFER[3167]	//(internal1_m96_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m96_Ppv0	 964	//(internal1_m96_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m96_Pav0	 BUFFER[3169]	//(internal1_m96_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m96_Pav0	 965	//(internal1_m96_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m96_Zav0	 BUFFER[3171]	//(internal1_m96_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m96_Zav0	 966	//(internal1_m96_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m96_RA00	 BUFFER[3173]	//(internal1_m96_RA00) RA00 - последнее задание вперед
#define idinternal1_m96_RA00	 967	//(internal1_m96_RA00) RA00 - последнее задание вперед
#define internal1_m96_RA10	 BUFFER[3175]	//(internal1_m96_RA10) RA10 - последнее задание назад
#define idinternal1_m96_RA10	 968	//(internal1_m96_RA10) RA10 - последнее задание назад
#define internal1_m96_RA50	 BUFFER[3177]	//(internal1_m96_RA50) Ra50 - последнее задание скорости
#define idinternal1_m96_RA50	 969	//(internal1_m96_RA50) Ra50 - последнее задание скорости
#define internal1_m96_fls	 BUFFER[3178]	//(internal1_m96_fls)  fls - флаг одношагового режима
#define idinternal1_m96_fls	 970	//(internal1_m96_fls)  fls - флаг одношагового режима
#define internal1_m96_flp	 BUFFER[3180]	//(internal1_m96_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m96_flp	 971	//(internal1_m96_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m96_MyFirstEnterFlag	 BUFFER[3182]	//(internal1_m96_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m96_MyFirstEnterFlag	 972	//(internal1_m96_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m229_Ppv0	 BUFFER[3184]	//(internal1_m229_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m229_Ppv0	 973	//(internal1_m229_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m229_Pav0	 BUFFER[3186]	//(internal1_m229_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m229_Pav0	 974	//(internal1_m229_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m229_Zav0	 BUFFER[3188]	//(internal1_m229_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m229_Zav0	 975	//(internal1_m229_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m229_RA00	 BUFFER[3190]	//(internal1_m229_RA00) RA00 - последнее задание вперед
#define idinternal1_m229_RA00	 976	//(internal1_m229_RA00) RA00 - последнее задание вперед
#define internal1_m229_RA10	 BUFFER[3192]	//(internal1_m229_RA10) RA10 - последнее задание назад
#define idinternal1_m229_RA10	 977	//(internal1_m229_RA10) RA10 - последнее задание назад
#define internal1_m229_RA50	 BUFFER[3194]	//(internal1_m229_RA50) Ra50 - последнее задание скорости
#define idinternal1_m229_RA50	 978	//(internal1_m229_RA50) Ra50 - последнее задание скорости
#define internal1_m229_fls	 BUFFER[3195]	//(internal1_m229_fls)  fls - флаг одношагового режима
#define idinternal1_m229_fls	 979	//(internal1_m229_fls)  fls - флаг одношагового режима
#define internal1_m229_flp	 BUFFER[3197]	//(internal1_m229_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m229_flp	 980	//(internal1_m229_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m229_MyFirstEnterFlag	 BUFFER[3199]	//(internal1_m229_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m229_MyFirstEnterFlag	 981	//(internal1_m229_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m60_Ppv0	 BUFFER[3201]	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m60_Ppv0	 982	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m60_Pav0	 BUFFER[3203]	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m60_Pav0	 983	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m60_Zav0	 BUFFER[3205]	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m60_Zav0	 984	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m60_RA00	 BUFFER[3207]	//(internal1_m60_RA00) RA00 - последнее задание вперед
#define idinternal1_m60_RA00	 985	//(internal1_m60_RA00) RA00 - последнее задание вперед
#define internal1_m60_RA10	 BUFFER[3209]	//(internal1_m60_RA10) RA10 - последнее задание назад
#define idinternal1_m60_RA10	 986	//(internal1_m60_RA10) RA10 - последнее задание назад
#define internal1_m60_RA50	 BUFFER[3211]	//(internal1_m60_RA50) Ra50 - последнее задание скорости
#define idinternal1_m60_RA50	 987	//(internal1_m60_RA50) Ra50 - последнее задание скорости
#define internal1_m60_fls	 BUFFER[3212]	//(internal1_m60_fls)  fls - флаг одношагового режима
#define idinternal1_m60_fls	 988	//(internal1_m60_fls)  fls - флаг одношагового режима
#define internal1_m60_flp	 BUFFER[3214]	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m60_flp	 989	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m60_MyFirstEnterFlag	 BUFFER[3216]	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m60_MyFirstEnterFlag	 990	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m14_C1	 BUFFER[3218]	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m14_C1	 991	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m14_C2	 BUFFER[3223]	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m14_C2	 992	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m14_C3	 BUFFER[3228]	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m14_C3	 993	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m14_C4	 BUFFER[3233]	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m14_C4	 994	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m14_C5	 BUFFER[3238]	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m14_C5	 995	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m14_C6	 BUFFER[3243]	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m14_C6	 996	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m14_N20	 BUFFER[3248]	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m14_N20	 997	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m14_C0	 BUFFER[3253]	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m14_C0	 998	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m14_ImpINI0	 BUFFER[3283]	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m14_ImpINI0	 999	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m14_MyFirstEnterFlag	 BUFFER[3285]	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m14_MyFirstEnterFlag	 1000	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &A1IS21LDU},	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
	{ 2	,1	,1	, &B6IS21LDU},	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
	{ 3	,1	,1	, &B6IS11LDU},	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
	{ 4	,1	,1	, &A6IS21LDU},	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
	{ 5	,1	,1	, &A6IS11LDU},	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
	{ 6	,1	,1	, &A8IS12LDU},	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
	{ 7	,1	,1	, &A8IS22LDU},	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
	{ 8	,1	,1	, &B8IS12LDU},	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
	{ 9	,1	,1	, &B8IS22LDU},	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
	{ 10	,1	,1	, &R4IS12LDU},	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
	{ 11	,1	,1	, &R4IS22LDU},	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
	{ 12	,1	,1	, &R4IS21LDU},	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
	{ 13	,1	,1	, &R4IS11LDU},	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
	{ 14	,1	,1	, &B4VP82LDU},	//( - , SCM) Давление ПОДЪЁМ НИ2 в норме
	{ 15	,1	,1	, &A4VP82LDU},	//( - , SCM) Давление ПОДЪЁМ НИ1 в норме
	{ 16	,1	,1	, &R2IS21LDU},	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
	{ 17	,1	,1	, &R2IS11LDU},	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
	{ 18	,1	,1	, &R0EE03LZ1},	//( - , SBz1) Питание  АКНП3  отключить
	{ 19	,1	,1	, &R0EE02LZ1},	//( - , SBz1) Питание  АКНП  отключить
	{ 20	,1	,1	, &R0EE01LZ2},	//( - , SBz2) Питание  АКНП1  отключить
	{ 21	,1	,1	, &R0EE01LZ1},	//( - , SBz1) Питание  АКНП1  отключить
	{ 22	,1	,1	, &B4IS10LDU},	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
	{ 23	,1	,1	, &A4IS10LDU},	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
	{ 24	,1	,1	, &B1IE04LDU},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{ 25	,1	,1	, &B1IE03LDU},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{ 26	,1	,1	, &A1IE04LDU},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{ 27	,1	,1	, &A1IE03LDU},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{ 28	,1	,1	, &B1IS12LDU},	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
	{ 29	,1	,1	, &B1IS11LDU},	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
	{ 30	,1	,1	, &B1IS21LDU},	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
	{ 31	,5	,1	, &B1IC01UDU},	//( - , SDu) Координата штока ББ2
	{ 32	,5	,1	, &A1IC01UDU},	//( - , SDu) Координата штока ББ1
	{ 33	,1	,1	, &A1IS12LDU},	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
	{ 34	,1	,1	, &A1IS11LDU},	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
	{ 35	,1	,1	, &B9IS21LDU},	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
	{ 36	,1	,1	, &B9IS11LDU},	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
	{ 37	,1	,1	, &A9IS21LDU},	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
	{ 38	,1	,1	, &A9IS11LDU},	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
	{ 39	,1	,1	, &B5IS21LDU},	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
	{ 40	,1	,1	, &B5IS11LDU},	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
	{ 41	,1	,1	, &A5IS21LDU},	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
	{ 42	,1	,1	, &A5IS11LDU},	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
	{ 43	,1	,1	, &B0VP81LZZ},	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
	{ 44	,1	,1	, &A0VP81LZZ},	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
	{ 45	,5	,1	, &B8IC01UDU},	//( - , SDu) Координата АЗ2
	{ 46	,5	,1	, &A8IC01UDU},	//( - , SDu) Координата ДС2
	{ 47	,1	,1	, &R6IS68LZZ},	//(do32_pti:100 - K19DO, - ) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 48	,1	,1	, &R6IS67LZZ},	//(do32_pti:100 - K18DO, - ) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 49	,1	,1	, &R6IS66LZZ},	//(do32_pti:100 - K17DO, - ) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 50	,1	,1	, &R6IS65LDU},	//(do32_pti:160 - K32DO, - ) Исправность ВИП ССДИ-35 2канал
	{ 51	,1	,1	, &R6IS64LDU},	//(do32_pti:160 - K31DO, - ) Исправность ВИП ССДИ-35 1канал
	{ 52	,1	,1	, &R1IS21LDU},	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
	{ 53	,1	,1	, &R1IS11LDU},	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
	{ 54	,1	,1	, &B4IS21LDU},	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
	{ 55	,1	,1	, &B4IS11LDU},	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
	{ 56	,1	,1	, &R8IS11LDU},	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
	{ 57	,1	,1	, &A4IS21LDU},	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
	{ 58	,1	,1	, &A4IS11LDU},	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
	{ 59	,1	,1	, &R5IS21LDU},	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
	{ 60	,1	,1	, &R5IS11LDU},	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
	{ 61	,1	,1	, &R3IS21LDU},	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
	{ 62	,1	,1	, &R3IS11LDU},	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
	{ 63	,1	,1	, &B2VP82LDU},	//( - , SCM) Давление ПОДЪЁМ РБ2 в норме
	{ 64	,3	,1	, &B2IP01IZ2},	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
	{ 65	,3	,1	, &B2IP01IZ1},	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
	{ 66	,5	,1	, &B2IC01UDU},	//( - , SDu) Координата штока РБ2
	{ 67	,1	,1	, &B2IS12LDU},	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
	{ 68	,1	,1	, &B2IS11LDU},	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
	{ 69	,1	,1	, &B2IS21LDU},	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
	{ 70	,8	,1	, &R0IN03FI2},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{ 71	,8	,1	, &R0IN07RIP},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{ 72	,8	,1	, &R0IN06RIP},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{ 73	,3	,1	, &TerR0IN06FRP},	//( - , - ) Неисправности СНМ-11 -1,2
	{ 74	,8	,1	, &R0IN03RIP},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{ 75	,8	,1	, &R0IN02RIP},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{ 76	,8	,1	, &R0IN01RIP},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{ 77	,8	,1	, &R0IN02FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{ 78	,8	,1	, &R0IN03FI1},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{ 79	,8	,1	, &R0IN02FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{ 80	,8	,1	, &R0IN03FI4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{ 81	,8	,1	, &R0IN02FI4},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{ 82	,8	,1	, &R0IN01FI3},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{ 83	,8	,1	, &R0IN01FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{ 84	,8	,1	, &R0IN01FI4},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{ 85	,8	,1	, &R0IN01FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{ 86	,1	,1	, &B7AP31LDU},	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
	{ 87	,8	,1	, &B0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
	{ 88	,8	,1	, &B0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
	{ 89	,8	,1	, &B0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
	{ 90	,8	,1	, &B0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
	{ 91	,8	,1	, &B0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
	{ 92	,8	,1	, &B0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
	{ 93	,8	,1	, &A0SN07RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
	{ 94	,8	,1	, &A0SN06RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
	{ 95	,8	,1	, &A0SN05RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
	{ 96	,8	,1	, &A0SN04RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
	{ 97	,8	,1	, &A0SN03RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
	{ 98	,8	,1	, &A0SN02RIM},	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
	{ 99	,3	,1	, &R0IS01FI0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{ 100	,3	,1	, &A0IT03IRP},	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
	{ 101	,3	,1	, &B0IT03IRP},	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
	{ 102	,8	,1	, &R0IN03FI3},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{ 103	,8	,1	, &R0IN02FI3},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{ 104	,1	,1	, &B1VP81LZZ},	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
	{ 105	,1	,1	, &B2IS33LDU},	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
	{ 106	,8	,1	, &A0VN01RIM},	//( - , SCM) Период разгона  AЗ1
	{ 107	,1	,1	, &B2IS32LIM},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{ 108	,1	,1	, &B2IS11LIM},	//( - , SCM) Магнит РБ2 обесточен
	{ 109	,1	,1	, &A2IS32LIM},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{ 110	,1	,1	, &A2IS11LIM},	//( - , SCM) Магнит РБ1 обесточен
	{ 111	,1	,1	, &B1IS32LIM},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	{ 112	,1	,1	, &B1IS11LIM},	//( - , SCM) Магнит ББ2 обесточен
	{ 113	,1	,1	, &A1IS32LIM},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{ 114	,1	,1	, &A1IS11LIM},	//( - , SCM) Магнит ББ1 обесточен
	{ 115	,1	,1	, &A3AD34LDU},	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
	{ 116	,1	,1	, &R0IS02LDU},	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
	{ 117	,1	,1	, &R0EE04LZ2},	//( - , SBz2) Питание  АКНП4  отключить
	{ 118	,1	,1	, &R0EE03LZ2},	//( - , SBz2) Питание  АКНП3  отключить
	{ 119	,1	,1	, &R0EE02LZ2},	//( - , SBz2) Питание  АКНП  отключить
	{ 120	,1	,1	, &R0EE04LZ1},	//( - , SBz1) Питание  АКНП4  отключить
	{ 121	,1	,1	, &A7AP31LDU},	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
	{ 122	,1	,1	, &R4VS12LDU},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{ 123	,1	,1	, &R4VS22LDU},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{ 124	,1	,1	, &R1VS12LDU},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{ 125	,1	,1	, &R2VS12LDU},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{ 126	,1	,1	, &R2VS22LDU},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{ 127	,1	,1	, &R1VS22LDU},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{ 128	,1	,1	, &B5VS12LDU},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{ 129	,1	,1	, &B5VS22LDU},	//( - , SCM) Движение НЛ2 в сторону НУ
	{ 130	,1	,1	, &A5VS12LDU},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{ 131	,1	,1	, &A5VS22LDU},	//( - , SCM) Движение НЛ1 в сторону НУ
	{ 132	,1	,1	, &B6VS12LDU},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{ 133	,1	,1	, &B6VS22LDU},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{ 134	,1	,1	, &A6VS12LDU},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{ 135	,1	,1	, &A6VS22LDU},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{ 136	,1	,1	, &B8IS21LDU},	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
	{ 137	,1	,1	, &B8IS11LDU},	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
	{ 138	,1	,1	, &A1VP81LZZ},	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
	{ 139	,1	,1	, &B8AD20LDU},	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
	{ 140	,1	,1	, &B8AD10LDU},	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
	{ 141	,1	,1	, &R4AD20LDU},	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
	{ 142	,1	,1	, &R4AD10LDU},	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
	{ 143	,8	,1	, &B0SR01RIM},	//( - , SCM) Текущая реактивность AЗ2
	{ 144	,1	,1	, &B3AD33LDU},	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
	{ 145	,1	,1	, &B3AD05LDU},	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
	{ 146	,1	,1	, &B3AD04LDU},	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
	{ 147	,1	,1	, &B3AD03LDU},	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
	{ 148	,1	,1	, &B3AD02LDU},	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
	{ 149	,1	,1	, &B3AD01LDU},	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
	{ 150	,1	,1	, &B3AD21LDU},	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
	{ 151	,1	,1	, &B3AD11LDU},	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
	{ 152	,1	,1	, &A3AD33LDU},	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
	{ 153	,1	,1	, &A3AD05LDU},	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
	{ 154	,1	,1	, &A3AD04LDU},	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
	{ 155	,1	,1	, &A3AD03LDU},	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
	{ 156	,8	,1	, &R0CR01RIM},	//( - , SCM) Коэффициент 12 связи АЗ1,2
	{ 157	,8	,1	, &B0SN08RIM},	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
	{ 158	,8	,1	, &A0SN08RIM},	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
	{ 159	,1	,1	, &B5AD20LDU},	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
	{ 160	,1	,1	, &B5AD10LDU},	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
	{ 161	,1	,1	, &A5AD20LDU},	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
	{ 162	,1	,1	, &A5AD10LDU},	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
	{ 163	,1	,1	, &R2AD20LDU},	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
	{ 164	,1	,1	, &R2AD10LDU},	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
	{ 165	,1	,1	, &R1AD20LDU},	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
	{ 166	,1	,1	, &R1AD10LDU},	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
	{ 167	,1	,1	, &B6AD20LDU},	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
	{ 168	,1	,1	, &B6AD10LDU},	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
	{ 169	,1	,1	, &A6AD20LDU},	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
	{ 170	,1	,1	, &A6AD10LDU},	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
	{ 171	,1	,1	, &A8AD20LDU},	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
	{ 172	,1	,1	, &A8AD10LDU},	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
	{ 173	,1	,1	, &A2AD21LDU},	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
	{ 174	,1	,1	, &A2AD11LDU},	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
	{ 175	,1	,1	, &B1AD05LDU},	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
	{ 176	,1	,1	, &B1AD04LDU},	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
	{ 177	,1	,1	, &B1AD03LDU},	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
	{ 178	,1	,1	, &B1AD02LDU},	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
	{ 179	,1	,1	, &B1AD01LDU},	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
	{ 180	,1	,1	, &B1AD21LDU},	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
	{ 181	,1	,1	, &B1AD11LDU},	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
	{ 182	,1	,1	, &A1AD05LDU},	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
	{ 183	,1	,1	, &A1AD04LDU},	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
	{ 184	,1	,1	, &A1AD03LDU},	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
	{ 185	,1	,1	, &A1AD02LDU},	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
	{ 186	,1	,1	, &A1AD01LDU},	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
	{ 187	,1	,1	, &A1AD21LDU},	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
	{ 188	,1	,1	, &A1AD11LDU},	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
	{ 189	,8	,1	, &A0SR01RIM},	//( - , SCM) Текущая реактивность AЗ1
	{ 190	,1	,1	, &A3AD02LDU},	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
	{ 191	,1	,1	, &A3AD01LDU},	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
	{ 192	,1	,1	, &A3AD21LDU},	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
	{ 193	,1	,1	, &A3AD11LDU},	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
	{ 194	,1	,1	, &B2AD33LDU},	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
	{ 195	,1	,1	, &B2AD05LDU},	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
	{ 196	,1	,1	, &B2AD04LDU},	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
	{ 197	,1	,1	, &B2AD03LDU},	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
	{ 198	,1	,1	, &B2AD02LDU},	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
	{ 199	,1	,1	, &B2AD01LDU},	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
	{ 200	,1	,1	, &B2AD21LDU},	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
	{ 201	,1	,1	, &B2AD11LDU},	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
	{ 202	,1	,1	, &A2AD33LDU},	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
	{ 203	,1	,1	, &A2AD05LDU},	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
	{ 204	,1	,1	, &A2AD04LDU},	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
	{ 205	,1	,1	, &A2AD03LDU},	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
	{ 206	,1	,1	, &A2AD02LDU},	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
	{ 207	,1	,1	, &A2AD01LDU},	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
	{ 208	,3	,1	, &A2IP01IZ2},	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
	{ 209	,3	,1	, &A2IP01IZ1},	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
	{ 210	,1	,1	, &B3IS21LDU},	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
	{ 211	,1	,1	, &A3IS21LDU},	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
	{ 212	,1	,1	, &A2IS33LDU},	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
	{ 213	,5	,1	, &A2IC01UDU},	//( - , SDu) Координата штока РБ1
	{ 214	,1	,1	, &A2IS12LDU},	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
	{ 215	,1	,1	, &A2IS11LDU},	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
	{ 216	,1	,1	, &A2IS21LDU},	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
	{ 217	,3	,1	, &B0IT02IZ2},	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
	{ 218	,3	,1	, &B0IT01IZ1},	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
	{ 219	,3	,1	, &A0IT02IZ2},	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
	{ 220	,3	,1	, &A0IT01IZ1},	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
	{ 221	,1	,1	, &R6IS21LDU},	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
	{ 222	,1	,1	, &B7AS31LDU},	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
	{ 223	,1	,1	, &A7AS31LDU},	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
	{ 224	,1	,1	, &B3IS35LDU},	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
	{ 225	,1	,1	, &R6IS63LDU},	//(do32_pti:160 - K30DO, - ) Исправность ВИП ССДИ-39 2канал
	{ 226	,1	,1	, &R6IS62LDU},	//(do32_pti:160 - K29DO, - ) Исправность ВИП ССДИ-39 1канал
	{ 227	,1	,1	, &B3IS22LDU},	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
	{ 228	,1	,1	, &A3IS22LDU},	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
	{ 229	,1	,1	, &B3IS11LDU},	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
	{ 230	,1	,1	, &A3IS11LDU},	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
	{ 231	,3	,1	, &A3IP02IDU},	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 232	,1	,1	, &B3VP81LDU},	//( - , SCM) Давление СПУСК ИС2 в норме
	{ 233	,1	,1	, &A3VP81LDU},	//( - , SCM) Давление СПУСК ИС1 в норме
	{ 234	,1	,1	, &B3IS33LDU},	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 235	,5	,1	, &B3IC01UDU},	//( - , SDu) Координата штока ИС2
	{ 236	,1	,1	, &B3IS31LDU},	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
	{ 237	,3	,1	, &B3IP02IDU},	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
	{ 238	,1	,1	, &A3IS33LDU},	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
	{ 239	,5	,1	, &A3IC01UDU},	//( - , SDu) Координата штока ИС1
	{ 240	,1	,1	, &A3IS31LDU},	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
	{ 241	,1	,1	, &A2VP82LDU},	//( - , SCM) Давление ПОДЪЁМ РБ1 в норме
	{ 242	,1	,1	, &B2AD31LDU},	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
	{ 243	,1	,1	, &B1AD32LDU},	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
	{ 244	,1	,1	, &B1AD31LDU},	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
	{ 245	,1	,1	, &A3AD31LDU},	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
	{ 246	,1	,1	, &C1MD31LP1},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{ 247	,1	,1	, &C1MD31LP2},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{ 248	,1	,1	, &A1AD31LDU},	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
	{ 249	,1	,1	, &A1AD32LDU},	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
	{ 250	,1	,1	, &A2AD31LDU},	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
	{ 251	,1	,1	, &C2MD31LP1},	//( - , SCM) Кнопка «СБРОС РБ»
	{ 252	,1	,1	, &A2AD32LDU},	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
	{ 253	,1	,1	, &R0VZ71LZ2},	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
	{ 254	,1	,1	, &R0VZ71LZ1},	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
	{ 255	,1	,1	, &R8AD21LDU},	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
	{ 256	,1	,1	, &R0AD14LDU},	//( - , SCM) Имитация срабатывания верхней АС II УР
	{ 257	,8	,1	, &R0SR02RIM},	//( - , SCM) Текущая мощность РУ (ватт)
	{ 258	,8	,1	, &R0CR02RIM},	//( - , SCM) Коэффициент 11 связи АЗ1,2
	{ 259	,1	,1	, &B3AD34LDU},	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
	{ 260	,1	,1	, &A3IS35LDU},	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
	{ 261	,1	,1	, &R7II73LZ2},	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
	{ 262	,1	,1	, &R7II71LZ2},	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
	{ 263	,1	,1	, &R7II72LZ2},	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
	{ 264	,1	,1	, &R0AD16LDU},	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
	{ 265	,1	,1	, &R7II72LZ1},	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
	{ 266	,1	,1	, &R7II71LZ1},	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
	{ 267	,1	,1	, &R7II73LZ1},	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
	{ 268	,8	,1	, &R0SR01RIM},	//( - , SCM) Текущая реактивность PУ
	{ 269	,8	,1	, &R0ST01RIM},	//( - , SCM) Текущий период разгона РУ
	{ 270	,1	,1	, &A4AD10LDU},	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
	{ 271	,1	,1	, &B4AD10LDU},	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
	{ 272	,1	,1	, &A9AD10LDU},	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
	{ 273	,1	,1	, &B9AD10LDU},	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
	{ 274	,1	,1	, &R0MW13LP2},	//( - , SCM) Переключатель «СЕТЬ»
	{ 275	,1	,1	, &B3AD31LDU},	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
	{ 276	,1	,1	, &B2AD32LDU},	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
	{ 277	,8	,1	, &fEM_R0UL01RIM},	//(R0UL01RIM) Среднее время генерации нейтронов
	{ 278	,8	,1	, &fEM_R0UN02RIM},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{ 279	,8	,1	, &fEM_A1UR01RIM},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{ 280	,8	,1	, &fEM_A1UR00RIM},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{ 281	,8	,1	, &fEM_A3UR00RIM},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{ 282	,8	,1	, &fEM_A3UR01RIM},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{ 283	,8	,1	, &fEM_R0UT01RIM},	//(R0UT01RIM) Температурный коэффициент (долл)
	{ 284	,8	,1	, &fEM_R0UT02RIM},	//(R0UT02RIM) Масса топлива в АЗ
	{ 285	,8	,1	, &fEM_R0UT04RIM},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{ 286	,8	,1	, &fEM_R0UT03RIM},	//(R0UT03RIM) Нормальная температура АЗ град
	{ 287	,8	,1	, &fEM_R0UT05RIM},	//(R0UT05RIM) Энергия деления ядра
	{ 288	,8	,1	, &fEM_R0UT06RIM},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{ 289	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{ 290	,8	,1	, &fEM_A1UC04RIM},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{ 291	,8	,1	, &fEM_A1UC05RIM},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{ 292	,8	,1	, &fEM_A1UC06RIM},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{ 293	,8	,1	, &fEM_A2UC06RIM},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{ 294	,8	,1	, &fEM_A2UC05RIM},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{ 295	,8	,1	, &fEM_A2UC04RIM},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{ 296	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{ 297	,8	,1	, &fEM_A3UC06RIM},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{ 298	,8	,1	, &fEM_A3UC05RIM},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{ 299	,8	,1	, &fEM_A3UC04RIM},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{ 300	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{ 301	,8	,1	, &fEM_R4UV80RDU},	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
	{ 302	,8	,1	, &fEM_R4UC10RIM},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{ 303	,8	,1	, &fEM_R4UC20RIM},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{ 304	,8	,1	, &fEM_B8UC21RIM},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{ 305	,8	,1	, &fEM_B8UC20RIM},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{ 306	,8	,1	, &fEM_B8UC11RIM},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{ 307	,8	,1	, &fEM_B8UC10RIM},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{ 308	,8	,1	, &fEM_B8UV80RDU},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{ 309	,8	,1	, &fEM_A8UV80RDU},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{ 310	,8	,1	, &fEM_A8UC10RIM},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{ 311	,8	,1	, &fEM_A8UC11RIM},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{ 312	,8	,1	, &fEM_A8UC20RIM},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{ 313	,8	,1	, &fEM_A8UC21RIM},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{ 314	,8	,1	, &fEM_A6UC10RIM},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{ 315	,8	,1	, &fEM_R1UC10RIM},	//(R1UC10RIM) Время полного хода МДЗ сек
	{ 316	,8	,1	, &fEM_A5UC10RIM},	//(A5UC10RIM) Время полного хода НЛ сек
	{ 317	,8	,1	, &fEM_A0UN01RIM},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{ 318	,8	,1	, &fEM_R4UC22RIM},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{ 319	,8	,1	, &fEM_A1UG01RDU},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{ 320	,8	,1	, &fEM_A2UG01RDU},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{ 321	,8	,1	, &fEM_A3UG01RDU},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{ 322	,8	,1	, &fEM_R7UC10RIM},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{ 323	,8	,1	, &fEM_R7UC19RIM},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{ 324	,8	,1	, &fEM_R7UI02RIM},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{ 325	,8	,1	, &fEM_R7UL01RIM},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{ 326	,8	,1	, &fEM_A2UR00RIM},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{ 327	,8	,1	, &fEM_A2UR01RIM},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{ 328	,8	,1	, &fEM_A0UN02RIM},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{ 329	,8	,1	, &fEM_R0UR30RIM},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{ 330	,8	,1	, &fEM_R0UR01RIM},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{ 331	,8	,1	, &fEM_R0UT02RDU},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{ 332	,8	,1	, &fEM_R0UT01RDU},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{ 333	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{ 334	,8	,1	, &fEM_A2UP03RDU},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{ 335	,8	,1	, &fEM_A2UP04RDU},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{ 336	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{ 337	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 338	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 339	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{ 340	,8	,1	, &fEM_R7UI74RIM},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{ 341	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{ 342	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 343	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 344	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 345	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 346	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 347	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 348	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 349	,8	,1	, &fEM_A8UC08RDU},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{ 350	,8	,1	, &fEM_B8UC08RDU},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{ 351	,8	,1	, &fEM_R4UC08RDU},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{ 352	,8	,1	, &fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
	{ 353	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 354	,8	,1	, &fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{ 355	,8	,1	, &fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{ 356	,8	,1	, &fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{ 357	,8	,1	, &fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{ 358	,8	,1	, &fEM_R7UX06RSS},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{ 359	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 360	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 361	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 362	,8	,1	, &fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{ 363	,8	,1	, &fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{ 364	,8	,1	, &fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{ 365	,8	,1	, &fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{ 366	,8	,1	, &fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{ 367	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 368	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 369	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 370	,8	,1	, &fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{ 371	,8	,1	, &fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{ 372	,8	,1	, &fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{ 373	,8	,1	, &fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{ 374	,8	,1	, &fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{ 375	,8	,1	, &fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{ 376	,8	,1	, &fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{ 377	,8	,1	, &fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{ 378	,8	,1	, &fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{ 379	,8	,1	, &fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{ 380	,8	,1	, &fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{ 381	,8	,1	, &fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{ 382	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 383	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 384	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 385	,8	,1	, &fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{ 386	,8	,1	, &fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{ 387	,8	,1	, &fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{ 388	,8	,1	, &fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{ 389	,8	,1	, &fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{ 390	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 391	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{ 392	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 393	,8	,1	, &fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{ 394	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 395	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 396	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 397	,8	,1	, &fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{ 398	,8	,1	, &fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{ 399	,8	,1	, &fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{ 400	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{ 401	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{ 402	,8	,1	, &fEM_R4US80RDU},	//(R4US80RDU) Тормозной путь тележки (мм)
	{ 403	,8	,1	, &fEM_R7UI71RIM},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{ 404	,8	,1	, &fEM_R7UI72RIM},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{ 405	,8	,1	, &fEM_R7UI73RIM},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{ 406	,8	,1	, &fEM_A1UP01RIM},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{ 407	,8	,1	, &fEM_A2UP01RIM},	//(A2UP01RIM) Текущее давление на сброс РБ
	{ 408	,8	,1	, &fEM_A0UP02RIM},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{ 409	,8	,1	, &fEM_A3UP01RIM},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{ 410	,8	,1	, &fEM_A1UP82RIM},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{ 411	,8	,1	, &fEM_A3UP02RDU},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{ 412	,8	,1	, &fEM_A1UV02RIM},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{ 413	,8	,1	, &fEM_A3UV02RIM},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{ 414	,8	,1	, &fEM_A2UV02RIM},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{ 415	,8	,1	, &fEM_B8US80RDU},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{ 416	,8	,1	, &fEM_A8US80RDU},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{ 417	,8	,1	, &fEM_A6US80RDU},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{ 418	,8	,1	, &fEM_A1US07RDU},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{ 419	,8	,1	, &fEM_A2US07RDU},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{ 420	,8	,1	, &fEM_A3US07RDU},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{ 421	,8	,1	, &fEM_R7UI75RIM},	//(R7UI75RIM) Множитель к уровню радиации
	{ 422	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 423	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 424	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 425	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 426	,8	,1	, &fEM_A4UL10RIM},	//(A4UL10RIM) Время полного перемещения НИ сек
	{ 427	,8	,1	, &fEM_A9UL10RIM},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{ 428	,8	,1	, &fEM_R3UL10RIM},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{ 429	,8	,1	, &fEM_R5UL10RIM},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{ 430	,8	,1	, &fEM_R6UL10RIM},	//(R6UL10RIM) Время полного хода кран-балки сек
	{ 431	,1	,1	, &lEM_C1AD31LRP},	//(C1AD31LRP) Общий сброс от РПУ
	{ 432	,1	,1	, &lEM_R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов
	{ 433	,1	,1	, &lEM_R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{ 434	,8	,1	, &fEM_A2UP02RIM},	//(A2UP02RIM) Текущее давление на подъём РБ
	{ 435	,8	,1	, &fEM_A2UP03RIM},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{ 436	,8	,1	, &fEM_A0UP01RIM},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{ 437	,8	,1	, &fEM_A3UP02RIM},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{ 438	,8	,1	, &fEM_A4UP01RIM},	//(A4UP01RIM) Текущее давление на подъём НИ
	{ 439	,8	,1	, &fEM_A4UP02RIM},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{ 440	,8	,1	, &fEM_R7UI76RIM},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{ 441	,8	,1	, &fEM_R7UI77RIM},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{ 442	,3	,1	, &iEM_TERBB1},	//(TERBB1) Неисправности  ББ1
	{ 443	,8	,1	, &fEM_A1MC02RC1},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{ 444	,8	,1	, &fEM_A1MV02RC1},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{ 445	,3	,1	, &iEM_TERBB2},	//(TERBB2) Неисправности  ББ2
	{ 446	,8	,1	, &fEM_B1MC02RC1},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{ 447	,8	,1	, &fEM_B1MV02RC1},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{ 448	,3	,1	, &iEM_TERRB2},	//(TERRB2) Неисправности  РБ2
	{ 449	,8	,1	, &fEM_B2MC02RC1},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{ 450	,8	,1	, &fEM_B2MV02RC1},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{ 451	,3	,1	, &iEM_TERRB1},	//(TERRB1) Неисправности  РБ1
	{ 452	,8	,1	, &fEM_A2MC02RC1},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{ 453	,8	,1	, &fEM_A2MV02RC1},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{ 454	,3	,1	, &iEM_TERIS2},	//(TERIS2) Неисправности  ИС2
	{ 455	,8	,1	, &fEM_B3MC02RC1},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{ 456	,8	,1	, &fEM_B3MV02RC1},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{ 457	,3	,1	, &iEM_TERIS1},	//(TERIS1) Неисправности  ИС1
	{ 458	,8	,1	, &fEM_A3MC02RC1},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{ 459	,8	,1	, &fEM_A3MV02RC1},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{ 460	,3	,1	, &iEM_TERA1IE04LDU},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{ 461	,3	,1	, &iEM_TERA1IE03LDU},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{ 462	,8	,1	, &fEM_A1MC01RC1},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{ 463	,3	,1	, &iEM_TERB1IE03LDU},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{ 464	,3	,1	, &iEM_TERB1IE04LDU},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{ 465	,8	,1	, &fEM_B1MC01RC1},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{ 466	,8	,1	, &fEM_B1MV01RC1},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{ 467	,8	,1	, &fEM_B2MC01RC1},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{ 468	,8	,1	, &fEM_B2MV01RC1},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{ 469	,8	,1	, &fEM_A3MC01RC1},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{ 470	,8	,1	, &fEM_A3MV01RC1},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{ 471	,8	,1	, &fEM_B3MC01RC1},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{ 472	,8	,1	, &fEM_B3MV01RC1},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{ 473	,3	,1	, &iEM_TERA2SS21LIM},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{ 474	,3	,1	, &iEM_TERA2SS12LIM},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{ 475	,3	,1	, &iEM_TERR6SS21LIM},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{ 476	,3	,1	, &iEM_TERA2VP82LIM},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{ 477	,3	,1	, &iEM_TERA2SS11LIM},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{ 478	,3	,1	, &iEM_TERB3SS21LIM},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{ 479	,3	,1	, &iEM_TERA0MT01RIM},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{ 480	,3	,1	, &iEM_TERB0MT01RIM},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{ 481	,3	,1	, &iEM_TERA2SP01RIM},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{ 482	,3	,1	, &iEM_TERB2SP01RIM},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{ 483	,3	,1	, &iEM_TERB3SP02RIM},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{ 484	,3	,1	, &iEM_TERA3SC01RIM},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{ 485	,3	,1	, &iEM_TERA3VP81LIM},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{ 486	,3	,1	, &iEM_TERA2SC01RIM},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{ 487	,3	,1	, &iEM_TERA2SS33LIM},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{ 488	,3	,1	, &iEM_TERA3SS21LIM},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{ 489	,3	,1	, &iEM_TERA3SS33LIM},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{ 490	,3	,1	, &iEM_TERA3SS31LIM},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{ 491	,3	,1	, &iEM_TERB3SS31LIM},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{ 492	,3	,1	, &iEM_TERB3SS33LIM},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 493	,3	,1	, &iEM_TERB3SC01RIM},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{ 494	,3	,1	, &iEM_TERA3SS11LIM},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{ 495	,3	,1	, &iEM_TERB3SS11LIM},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{ 496	,3	,1	, &iEM_TERR6IS64LIM},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{ 497	,3	,1	, &iEM_TERB3SS22LIM},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{ 498	,3	,1	, &iEM_TERA3SS22LIM},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{ 499	,3	,1	, &iEM_TERA3SP02RIM},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{ 500	,3	,1	, &iEM_TERR6IS62LIM},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{ 501	,3	,1	, &iEM_TERR6IS66LIM},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 502	,3	,1	, &iEM_TERR6IS67LIM},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 503	,3	,1	, &iEM_TERA0VP81LIM},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{ 504	,3	,1	, &iEM_TERB0VP81LIM},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{ 505	,3	,1	, &iEM_TERR0VP81LIM},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{ 506	,3	,1	, &iEM_TERR6IS68LIM},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{ 507	,3	,1	, &iEM_TERR7SI74RIM},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{ 508	,3	,1	, &iEM_TERA5SS21LIM},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{ 509	,3	,1	, &iEM_TERB5SS11LIM},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{ 510	,3	,1	, &iEM_TERA5SS11LIM},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{ 511	,3	,1	, &iEM_TERA9SS11LIM},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{ 512	,3	,1	, &iEM_TERB2SS11LIM},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{ 513	,3	,1	, &iEM_TERB2SS12LIM},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{ 514	,3	,1	, &iEM_TERB2SS21LIM},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{ 515	,3	,1	, &iEM_TERR3SS11LIM},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{ 516	,3	,1	, &iEM_TERB2SC01RIM},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{ 517	,3	,1	, &iEM_TERR3SS21LIM},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{ 518	,3	,1	, &iEM_TERR5SS11LIM},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{ 519	,3	,1	, &iEM_TERA4SS11LIM},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{ 520	,3	,1	, &iEM_TERR1SS11LIM},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{ 521	,3	,1	, &iEM_TERR1SS21LIM},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{ 522	,3	,1	, &iEM_TERR2SS11LIM},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{ 523	,3	,1	, &iEM_TERR2SS21LIM},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{ 524	,3	,1	, &iEM_TERA4VP82LIM},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{ 525	,3	,1	, &iEM_TERB4SS21LIM},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{ 526	,3	,1	, &iEM_TERR5SS21LIM},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{ 527	,3	,1	, &iEM_TERB6SS21LIM},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{ 528	,3	,1	, &iEM_TERB4SS11LIM},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{ 529	,3	,1	, &iEM_TERA4SS21LIM},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{ 530	,3	,1	, &iEM_TERA6MS11LIM},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{ 531	,3	,1	, &iEM_TERA6SS21LIM},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{ 532	,3	,1	, &iEM_TERB6SS11LIM},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{ 533	,3	,1	, &iEM_TERR4SS11LIM},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{ 534	,3	,1	, &iEM_TERR4MS21LIM},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{ 535	,3	,1	, &iEM_TERR4SS12LIM},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{ 536	,3	,1	, &iEM_TERR4SS22LIM},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{ 537	,3	,1	, &iEM_TERR8SS11LIM},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{ 538	,3	,1	, &iEM_TERB8SC01RIM},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{ 539	,3	,1	, &iEM_TERA8SC01RIM},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{ 540	,3	,1	, &iEM_TERB8SS12LIM},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{ 541	,3	,1	, &iEM_TERA8SS12LIM},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{ 542	,3	,1	, &iEM_TERB8SS22LIM},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{ 543	,3	,1	, &iEM_TERA8SS22LIM},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{ 544	,3	,1	, &iEM_TERA9SS21LIM},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{ 545	,3	,1	, &iEM_TERB9SS21LIM},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{ 546	,3	,1	, &iEM_TERB9SS11LIM},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{ 547	,3	,1	, &iEM_TERB5SS21LIM},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{ 548	,3	,1	, &iEM_TERA1SS21LIM},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{ 549	,3	,1	, &iEM_TERA1SS11LIM},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{ 550	,3	,1	, &iEM_TERA1SC01RIM},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{ 551	,3	,1	, &iEM_TERA1SS12LIM},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{ 552	,3	,1	, &iEM_TERB1SS21LIM},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{ 553	,3	,1	, &iEM_TERB1SS11LIM},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{ 554	,3	,1	, &iEM_TERB1MC01RIM},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{ 555	,3	,1	, &iEM_TERB1SS12LIM},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{ 556	,3	,1	, &iEM_TERTLG},	//(TERTLG) Неисправности  тележки от ИС
	{ 557	,8	,1	, &fEM_R4MC01RC1},	//(R4MC01RC1) Заданная координата тележки от ИС
	{ 558	,8	,1	, &fEM_R4MV01RC1},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{ 559	,3	,1	, &iEM_TERMAZ2},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{ 560	,8	,1	, &fEM_B8MC01RC1},	//(B8MC01RC1) аданная координата АЗ2 от ИС
	{ 561	,8	,1	, &fEM_B8MV01RC1},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{ 562	,3	,1	, &iEM_TERDS2},	//(TERDS2) Неисправности ДС2 от ИС
	{ 563	,8	,1	, &fEM_A8MC01RC1},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{ 564	,8	,1	, &fEM_A8MV01RC1},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{ 565	,3	,1	, &iEM_TERBZ1},	//(TERBZ1) Неисправности БЗ1
	{ 566	,8	,1	, &fEM_A6MC01RC1},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{ 567	,8	,1	, &fEM_A6MV01RC1},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{ 568	,3	,1	, &iEM_TERBZ2},	//(TERBZ2) Неисправности БЗ2
	{ 569	,8	,1	, &fEM_B6MC01RC1},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{ 570	,8	,1	, &fEM_B6MV01RC1},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{ 571	,1	,1	, &lEM_R3AD10LC1},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{ 572	,1	,1	, &lEM_R3AD20LC1},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{ 573	,1	,1	, &lEM_R6AD10LC1},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{ 574	,1	,1	, &lEM_R5AD10LC1},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{ 575	,1	,1	, &lEM_R5AD20LC1},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{ 576	,3	,1	, &iEM_TERMDZ2},	//(TERMDZ2) Неисправности МДЗ2
	{ 577	,8	,1	, &fEM_R2MC01RC1},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{ 578	,8	,1	, &fEM_R2MV01RC1},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{ 579	,3	,1	, &iEM_TERMDZ1},	//(TERMDZ1) Неисправности МДЗ1
	{ 580	,8	,1	, &fEM_R1MC01RC1},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{ 581	,8	,1	, &fEM_R1MV01RC1},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{ 582	,3	,1	, &iEM_TERNL1},	//(TERNL1) Неисправности НЛ1
	{ 583	,8	,1	, &fEM_A5MC01RC1},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{ 584	,8	,1	, &fEM_A5MV01RC1},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{ 585	,3	,1	, &iEM_TERNL2},	//(TERNL2) Неисправности НЛ2
	{ 586	,8	,1	, &fEM_B5MC01RC1},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{ 587	,8	,1	, &fEM_B5MV01RC1},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{ 588	,1	,1	, &lEM_R8AD10LC1},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{ 589	,8	,1	, &fEM_A1UC08RIM},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{ 590	,8	,1	, &fEM_A2UC08RIM},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{ 591	,8	,1	, &fEM_A3UC08RIM},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{ 592	,3	,1	, &iEM_TERB2SS33LIM},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{ 593	,3	,1	, &iEM_TERA1VP81LIM},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{ 594	,3	,1	, &iEM_TERB1VP81LIM},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{ 595	,8	,1	, &fEM_A0UT03RSP},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{ 596	,8	,1	, &fEM_A0UR01RSP},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{ 597	,8	,1	, &fEM_A0UR02RSP},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{ 598	,8	,1	, &fEM_B0UT03RSP},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{ 599	,8	,1	, &fEM_A1MC01RSP},	//(A1MC01RSP) Стартовая координата  ББ1
	{ 600	,8	,1	, &fEM_A1MC02RSP},	//(A1MC02RSP) Стартовая координата штока ББ1
	{ 601	,8	,1	, &fEM_A1MV01RSP},	//(A1MV01RSP) Стартовая скорость движения  ББ1
	{ 602	,8	,1	, &fEM_A1MV02RSP},	//(A1MV02RSP) Стартовая скорость движения  ББ1
	{ 603	,8	,1	, &fEM_B1MC01RSP},	//(B1MC01RSP) Стартовая координата  ББ2
	{ 604	,8	,1	, &fEM_B1MV01RSP},	//(B1MV01RSP) Стартовая скорость движения  ББ2
	{ 605	,8	,1	, &fEM_B1MC02RSP},	//(B1MC02RSP) Стартовая координата штока ББ2
	{ 606	,8	,1	, &fEM_B1MV02RSP},	//(B1MV02RSP) Стартовая скорость движения  ББ2
	{ 607	,8	,1	, &fEM_A2MC01RC1},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{ 608	,8	,1	, &fEM_A2MV01RC1},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{ 609	,8	,1	, &fEM_A2MC01RSP},	//(A2MC01RSP) Стартовая координата  РБ1
	{ 610	,8	,1	, &fEM_A2MV01RSP},	//(A2MV01RSP) Стартовая скорость движения  РБ1
	{ 611	,8	,1	, &fEM_A2MC02RSP},	//(A2MC02RSP) Стартовая координата штока РБ1
	{ 612	,8	,1	, &fEM_A2MV02RSP},	//(A2MV02RSP) Стартовая скорость движения  РБ1
	{ 613	,8	,1	, &fEM_B2MC01RSP},	//(B2MC01RSP) Стартовая координата  РБ2
	{ 614	,8	,1	, &fEM_B2MV01RSP},	//(B2MV01RSP) Стартовая скорость движения  РБ2
	{ 615	,8	,1	, &fEM_B2MC02RSP},	//(B2MC02RSP) Стартовая координата штока РБ2
	{ 616	,8	,1	, &fEM_B2MV02RSP},	//(B2MV02RSP) Стартовая скорость движения  РБ2
	{ 617	,8	,1	, &fEM_A3MC01RSP},	//(A3MC01RSP) Стартовая координата  ИС1
	{ 618	,8	,1	, &fEM_A3MV01RSP},	//(A3MV01RSP) Стартовая скорость движения  ИС1
	{ 619	,8	,1	, &fEM_A3MC02RSP},	//(A3MC02RSP) Стартовая координата штока ИС1
	{ 620	,8	,1	, &fEM_A3MV02RSP},	//(A3MV02RSP) Стартовая скорость движения  ИС1
	{ 621	,8	,1	, &fEM_B3MC01RSP},	//(B3MC01RSP) Стартовая координата  ИС2
	{ 622	,8	,1	, &fEM_B3MV01RSP},	//(B3MV01RSP) Стартовая скорость движения  ИС2
	{ 623	,8	,1	, &fEM_B3MC02RSP},	//(B3MC02RSP) Стартовая координата штока ИС2
	{ 624	,8	,1	, &fEM_B3MV02RSP},	//(B3MV02RSP) Стартовая скорость движения  ИС2
	{ 625	,8	,1	, &fEM_B8MC01RSP},	//(B8MC01RSP) Стартовая координата АЗ2
	{ 626	,8	,1	, &fEM_B8MV01RSP},	//(B8MV01RSP) Стартовая скорость АЗ2
	{ 627	,8	,1	, &fEM_A8MC01RSP},	//(A8MC01RSP) Стартовая координата ДС2
	{ 628	,8	,1	, &fEM_A8MV01RSP},	//(A8MV01RSP) Стартовая скорость ДС2
	{ 629	,8	,1	, &fEM_A6MC01RSP},	//(A6MC01RSP) Стартовая координата БЗ1
	{ 630	,8	,1	, &fEM_A6MV01RSP},	//(A6MV01RSP) Стартовая скорость БЗ1
	{ 631	,8	,1	, &fEM_B6MC01RSP},	//(B6MC01RSP) Стартовая координата БЗ2
	{ 632	,8	,1	, &fEM_B6MV01RSP},	//(B6MV01RSP) Стартовая скорость БЗ2
	{ 633	,8	,1	, &fEM_R3UC01RSP},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{ 634	,8	,1	, &fEM_R3UV01RSP},	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
	{ 635	,8	,1	, &fEM_R5UC01RSP},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{ 636	,8	,1	, &fEM_R5UV01RSP},	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
	{ 637	,8	,1	, &fEM_R6UC01RSP},	//(R6UC01RSP) Стартовая координата Кран-балки
	{ 638	,8	,1	, &fEM_R6UV01RSP},	//(R6UV01RSP) Стартовая скорость Кран-балки
	{ 639	,8	,1	, &fEM_R2MC01RSP},	//(R2MC01RSP) Стартовая координата МДЗ2
	{ 640	,8	,1	, &fEM_R2MV01RSP},	//(R2MV01RSP) Стартовая скорость МДЗ2
	{ 641	,8	,1	, &fEM_R1MC01RSP},	//(R1MC01RSP) Стартовая координата МДЗ1
	{ 642	,8	,1	, &fEM_R1MV01RSP},	//(R1MV01RSP) Стартовая скорость МДЗ1
	{ 643	,8	,1	, &fEM_A5MC01RSP},	//(A5MC01RSP) Стартовая координата НЛ1
	{ 644	,8	,1	, &fEM_A5MV01RSP},	//(A5MV01RSP) Стартовая скорость НЛ1
	{ 645	,8	,1	, &fEM_B5MC01RSP},	//(B5MC01RSP) Стартовая координата НЛ2
	{ 646	,8	,1	, &fEM_B5MV01RSP},	//(B5MV01RSP) Стартовая скорость НЛ2
	{ 647	,8	,1	, &fEM_A9MC01RSP},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{ 648	,8	,1	, &fEM_A9MV01RSP},	//(A9MV01RSP) Стартовая скорость НИ ДС1
	{ 649	,8	,1	, &fEM_B9MC01RSP},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{ 650	,8	,1	, &fEM_B9MV01RSP},	//(B9MV01RSP) Стартовая скорость НИ ДС2
	{ 651	,8	,1	, &fEM_A4MC01RSP},	//(A4MC01RSP) Стартовая координата НИ1
	{ 652	,8	,1	, &fEM_A4MV01RSP},	//(A4MV01RSP) Стартовая скорость НИ1
	{ 653	,8	,1	, &fEM_B4MC01RSP},	//(B4MC01RSP) Стартовая координата НИ2
	{ 654	,8	,1	, &fEM_B4MV01RSP},	//(B4MV01RSP) Стартовая скорость НИ2
	{ 655	,8	,1	, &fEM_R4MC01RSP},	//(R4MC01RSP) Стартовая координата тележки
	{ 656	,8	,1	, &fEM_R4MV01RSP},	//(R4MV01RSP) Стартовая скорость тележки
	{ 657	,8	,1	, &fEM_A1MV01RC1},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{ 658	,3	,1	, &iEM_TERB7MS31LIM},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{ 659	,3	,1	, &iEM_TERA7MS31LIM},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{ 660	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 см
	{ 661	,3	,1	, &iEM_TERA6VS12LIM},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{ 662	,3	,1	, &iEM_TERA6VS22LIM},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{ 663	,3	,1	, &iEM_TERB6VS12LIM},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{ 664	,3	,1	, &iEM_TERB6VS22LIM},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{ 665	,3	,1	, &iEM_TERA5VS22LIM},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{ 666	,3	,1	, &iEM_TERA5VS12LIM},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{ 667	,3	,1	, &iEM_TERB5VS12LIM},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{ 668	,3	,1	, &iEM_TERB5VS22LIM},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{ 669	,3	,1	, &iEM_TERR1VS12LIM},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{ 670	,3	,1	, &iEM_TERR1VS22LIM},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{ 671	,3	,1	, &iEM_TERR2VS12LIM},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{ 672	,3	,1	, &iEM_TERR2VS22LIM},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{ 673	,3	,1	, &iEM_TERR4VS12LDU},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 674	,3	,1	, &iEM_TERR4VS22LDU},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 675	,8	,1	, &fEM_R4UC23RIM},	//(R4UC23RIM) Y-координата АЗ1
	{ 676	,8	,1	, &fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{ 677	,8	,1	, &fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{ 678	,8	,1	, &fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{ 679	,8	,1	, &fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{ 680	,8	,1	, &fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{ 681	,8	,1	, &fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{ 682	,8	,1	, &fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{ 683	,8	,1	, &fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{ 684	,8	,1	, &fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{ 685	,8	,1	, &fEM_R7UX16RSS},	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
	{ 686	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 687	,8	,1	, &internal1_m894_Chim0},	//(internal1_m894_Chim0) измеренная частота импульсов камеры Гц
	{ 688	,8	,1	, &internal1_m884_Chim0},	//(internal1_m884_Chim0) измеренная частота импульсов камеры Гц
	{ 689	,8	,1	, &internal1_m876_Chim0},	//(internal1_m876_Chim0) измеренная частота импульсов камеры Гц
	{ 690	,1	,1	, &internal1_m831_Out10},	//(internal1_m831_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 691	,1	,1	, &internal1_m830_Out10},	//(internal1_m830_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 692	,1	,1	, &internal1_m1014_Out10},	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 693	,1	,1	, &internal1_m1013_Out10},	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 694	,1	,1	, &internal1_m1012_Out10},	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 695	,1	,1	, &internal1_m1011_Out10},	//(internal1_m1011_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 696	,1	,1	, &internal1_m693_Out10},	//(internal1_m693_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 697	,1	,1	, &internal1_m692_Out10},	//(internal1_m692_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 698	,1	,1	, &internal1_m671_Out10},	//(internal1_m671_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 699	,1	,1	, &internal1_m670_Out10},	//(internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 700	,1	,1	, &internal1_m691_Out10},	//(internal1_m691_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 701	,1	,1	, &internal1_m690_Out10},	//(internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 702	,1	,1	, &internal1_m669_Out10},	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 703	,1	,1	, &internal1_m668_Out10},	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 704	,1	,1	, &internal1_m529_Out10},	//(internal1_m529_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 705	,1	,1	, &internal1_m545_Out10},	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 706	,1	,1	, &internal1_m411_Out10},	//(internal1_m411_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 707	,1	,1	, &internal1_m488_q0},	//(internal1_m488_q0) q0 - внутренний параметр
	{ 708	,1	,1	, &internal1_m489_q0},	//(internal1_m489_q0) q0 - внутренний параметр
	{ 709	,1	,1	, &internal1_m474_q0},	//(internal1_m474_q0) q0 - внутренний параметр
	{ 710	,1	,1	, &internal1_m475_q0},	//(internal1_m475_q0) q0 - внутренний параметр
	{ 711	,8	,1	, &internal1_m644_tx},	//(internal1_m644_tx) tx - время накопленное сек
	{ 712	,18	,1	, &internal1_m644_y0},	//(internal1_m644_y0) y0
	{ 713	,8	,1	, &internal1_m632_tx},	//(internal1_m632_tx) tx - время накопленное сек
	{ 714	,18	,1	, &internal1_m632_y0},	//(internal1_m632_y0) y0
	{ 715	,8	,1	, &internal1_m618_tx},	//(internal1_m618_tx) tx - время накопленное сек
	{ 716	,18	,1	, &internal1_m618_y0},	//(internal1_m618_y0) y0
	{ 717	,8	,1	, &internal1_m616_tx},	//(internal1_m616_tx) tx - время накопленное сек
	{ 718	,18	,1	, &internal1_m616_y0},	//(internal1_m616_y0) y0
	{ 719	,1	,1	, &internal1_m208_Out10},	//(internal1_m208_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 720	,1	,1	, &internal1_m225_Out10},	//(internal1_m225_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 721	,1	,1	, &internal1_m41_Out10},	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 722	,1	,1	, &internal1_m56_Out10},	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 723	,1	,1	, &internal1_m985_Out10},	//(internal1_m985_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 724	,1	,1	, &internal1_m982_Out10},	//(internal1_m982_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 725	,1	,1	, &internal1_m981_Out10},	//(internal1_m981_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 726	,8	,1	, &internal1_m984_Xtek0},	//(internal1_m984_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 727	,8	,1	, &internal1_m967_Xtek0},	//(internal1_m967_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 728	,1	,1	, &internal1_m968_Out10},	//(internal1_m968_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 729	,1	,1	, &internal1_m965_Out10},	//(internal1_m965_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 730	,1	,1	, &internal1_m964_Out10},	//(internal1_m964_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 731	,1	,1	, &internal1_m1052_Out10},	//(internal1_m1052_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 732	,1	,1	, &internal1_m1033_Out10},	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 733	,1	,1	, &internal1_m1032_Out10},	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 734	,1	,1	, &internal1_m1031_Out10},	//(internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 735	,1	,1	, &internal1_m852_Out10},	//(internal1_m852_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 736	,1	,1	, &internal1_m854_Out10},	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 737	,1	,1	, &internal1_m851_Out10},	//(internal1_m851_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 738	,1	,1	, &internal1_m853_Out10},	//(internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 739	,1	,1	, &internal1_m827_Out10},	//(internal1_m827_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 740	,1	,1	, &internal1_m828_Out10},	//(internal1_m828_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 741	,1	,1	, &internal1_m826_Out10},	//(internal1_m826_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 742	,1	,1	, &internal1_m825_Out10},	//(internal1_m825_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 743	,1	,1	, &internal1_m1047_Out10},	//(internal1_m1047_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 744	,1	,1	, &internal1_m999_Out10},	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 745	,1	,1	, &internal1_m998_Out10},	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 746	,1	,1	, &internal1_m997_Out10},	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 747	,1	,1	, &internal1_m996_Out10},	//(internal1_m996_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 748	,1	,1	, &internal1_m1048_Out10},	//(internal1_m1048_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 749	,1	,1	, &internal1_m1029_Out10},	//(internal1_m1029_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 750	,1	,1	, &internal1_m829_Out10},	//(internal1_m829_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 751	,1	,1	, &internal1_m1030_Out10},	//(internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 752	,1	,1	, &internal1_m1028_Out10},	//(internal1_m1028_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 753	,1	,1	, &internal1_m1049_Out10},	//(internal1_m1049_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 754	,1	,1	, &internal1_m1027_Out10},	//(internal1_m1027_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 755	,1	,1	, &internal1_m1010_Out10},	//(internal1_m1010_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 756	,1	,1	, &internal1_m995_Out10},	//(internal1_m995_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 757	,1	,1	, &internal1_m546_Out10},	//(internal1_m546_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 758	,8	,1	, &internal1_m421_Xtek0},	//(internal1_m421_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 759	,1	,1	, &internal1_m412_Out10},	//(internal1_m412_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 760	,1	,1	, &internal1_m414_Out10},	//(internal1_m414_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 761	,1	,1	, &internal1_m413_Out10},	//(internal1_m413_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 762	,1	,1	, &internal1_m867_Out10},	//(internal1_m867_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 763	,1	,1	, &internal1_m868_Out10},	//(internal1_m868_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 764	,1	,1	, &internal1_m866_Out10},	//(internal1_m866_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 765	,1	,1	, &internal1_m1051_Out10},	//(internal1_m1051_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 766	,1	,1	, &internal1_m706_Out10},	//(internal1_m706_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 767	,1	,1	, &internal1_m707_Out10},	//(internal1_m707_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 768	,1	,1	, &internal1_m704_Out10},	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 769	,1	,1	, &internal1_m705_Out10},	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 770	,1	,1	, &internal1_m562_Out10},	//(internal1_m562_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 771	,1	,1	, &internal1_m561_Out10},	//(internal1_m561_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 772	,8	,1	, &internal1_m848_Xtek0},	//(internal1_m848_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 773	,8	,1	, &internal1_m850_Xtek0},	//(internal1_m850_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 774	,1	,1	, &internal1_m703_Out10},	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 775	,1	,1	, &internal1_m687_Out10},	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 776	,1	,1	, &internal1_m667_Out10},	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 777	,1	,1	, &internal1_m686_Out10},	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 778	,1	,1	, &internal1_m666_Out10},	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 779	,1	,1	, &internal1_m339_Out10},	//(internal1_m339_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 780	,1	,1	, &internal1_m338_Out10},	//(internal1_m338_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 781	,1	,1	, &internal1_m323_Out10},	//(internal1_m323_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 782	,1	,1	, &internal1_m322_Out10},	//(internal1_m322_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 783	,1	,1	, &internal1_m563_Out10},	//(internal1_m563_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 784	,1	,1	, &internal1_m352_Out10},	//(internal1_m352_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 785	,8	,1	, &internal1_m336_Xtek0},	//(internal1_m336_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 786	,1	,1	, &internal1_m351_Out10},	//(internal1_m351_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 787	,1	,1	, &internal1_m349_Out10},	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 788	,8	,1	, &internal1_m329_Xtek0},	//(internal1_m329_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 789	,1	,1	, &internal1_m350_Out10},	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 790	,1	,1	, &internal1_m321_Out10},	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 791	,1	,1	, &internal1_m337_Out10},	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 792	,1	,1	, &internal1_m433_Out10},	//(internal1_m433_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 793	,8	,1	, &internal1_m434_Xtek0},	//(internal1_m434_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 794	,1	,1	, &internal1_m432_Out10},	//(internal1_m432_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 795	,1	,1	, &internal1_m431_Out10},	//(internal1_m431_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 796	,1	,1	, &internal1_m430_Out10},	//(internal1_m430_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 797	,1	,1	, &internal1_m1050_Out10},	//(internal1_m1050_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 798	,1	,1	, &internal1_m150_Out10},	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 799	,1	,1	, &internal1_m149_Out10},	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 800	,3	,1	, &internal1_m197_tx},	//(internal1_m197_tx) tx - внутренний параметр
	{ 801	,3	,1	, &internal1_m30_tx},	//(internal1_m30_tx) tx - внутренний параметр
	{ 802	,1	,1	, &internal1_m478_Pav0},	//(internal1_m478_Pav0)  - Пер.аварийный выключатель механизма
	{ 803	,1	,1	, &internal1_m478_Zav0},	//(internal1_m478_Zav0)  - Зад.аварийный выключатель механизма
	{ 804	,1	,1	, &internal1_m478_Pv0},	//(internal1_m478_Pv0)  - Пер. выключатель механизма
	{ 805	,1	,1	, &internal1_m478_Zv0},	//(internal1_m478_Zv0)  - Зад. выключатель механизма
	{ 806	,1	,1	, &internal1_m478_RA00},	//(internal1_m478_RA00)  - последнее задание вперед
	{ 807	,1	,1	, &internal1_m478_RA10},	//(internal1_m478_RA10)  - последнее задание назад
	{ 808	,1	,1	, &internal1_m478_MyFirstEnterFlag},	//(internal1_m478_MyFirstEnterFlag) MyFirstEnterFlag
	{ 809	,1	,1	, &internal1_m492_Pav0},	//(internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
	{ 810	,1	,1	, &internal1_m492_Zav0},	//(internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
	{ 811	,1	,1	, &internal1_m492_Pv0},	//(internal1_m492_Pv0)  - Пер. выключатель механизма
	{ 812	,1	,1	, &internal1_m492_Zv0},	//(internal1_m492_Zv0)  - Зад. выключатель механизма
	{ 813	,1	,1	, &internal1_m492_RA00},	//(internal1_m492_RA00)  - последнее задание вперед
	{ 814	,1	,1	, &internal1_m492_RA10},	//(internal1_m492_RA10)  - последнее задание назад
	{ 815	,1	,1	, &internal1_m492_MyFirstEnterFlag},	//(internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
	{ 816	,1	,1	, &internal1_m480_Pav0},	//(internal1_m480_Pav0)  - Пер.аварийный выключатель механизма
	{ 817	,1	,1	, &internal1_m480_Zav0},	//(internal1_m480_Zav0)  - Зад.аварийный выключатель механизма
	{ 818	,1	,1	, &internal1_m480_Pv0},	//(internal1_m480_Pv0)  - Пер. выключатель механизма
	{ 819	,1	,1	, &internal1_m480_Zv0},	//(internal1_m480_Zv0)  - Зад. выключатель механизма
	{ 820	,1	,1	, &internal1_m480_RA00},	//(internal1_m480_RA00)  - последнее задание вперед
	{ 821	,1	,1	, &internal1_m480_RA10},	//(internal1_m480_RA10)  - последнее задание назад
	{ 822	,1	,1	, &internal1_m480_MyFirstEnterFlag},	//(internal1_m480_MyFirstEnterFlag) MyFirstEnterFlag
	{ 823	,1	,1	, &internal1_m623_Pav0},	//(internal1_m623_Pav0)  - Пер.аварийный выключатель механизма
	{ 824	,1	,1	, &internal1_m623_Zav0},	//(internal1_m623_Zav0)  - Зад.аварийный выключатель механизма
	{ 825	,1	,1	, &internal1_m623_Pv0},	//(internal1_m623_Pv0)  - Пер. выключатель механизма
	{ 826	,1	,1	, &internal1_m623_Zv0},	//(internal1_m623_Zv0)  - Зад. выключатель механизма
	{ 827	,1	,1	, &internal1_m623_RA00},	//(internal1_m623_RA00)  - последнее задание вперед
	{ 828	,1	,1	, &internal1_m623_RA10},	//(internal1_m623_RA10)  - последнее задание назад
	{ 829	,1	,1	, &internal1_m623_MyFirstEnterFlag},	//(internal1_m623_MyFirstEnterFlag) MyFirstEnterFlag
	{ 830	,1	,1	, &internal1_m620_Pav0},	//(internal1_m620_Pav0)  - Пер.аварийный выключатель механизма
	{ 831	,1	,1	, &internal1_m620_Zav0},	//(internal1_m620_Zav0)  - Зад.аварийный выключатель механизма
	{ 832	,1	,1	, &internal1_m620_Pv0},	//(internal1_m620_Pv0)  - Пер. выключатель механизма
	{ 833	,1	,1	, &internal1_m620_Zv0},	//(internal1_m620_Zv0)  - Зад. выключатель механизма
	{ 834	,1	,1	, &internal1_m620_RA00},	//(internal1_m620_RA00)  - последнее задание вперед
	{ 835	,1	,1	, &internal1_m620_RA10},	//(internal1_m620_RA10)  - последнее задание назад
	{ 836	,1	,1	, &internal1_m620_MyFirstEnterFlag},	//(internal1_m620_MyFirstEnterFlag) MyFirstEnterFlag
	{ 837	,1	,1	, &internal1_m606_Pav0},	//(internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
	{ 838	,1	,1	, &internal1_m606_Zav0},	//(internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
	{ 839	,1	,1	, &internal1_m606_Pv0},	//(internal1_m606_Pv0)  - Пер. выключатель механизма
	{ 840	,1	,1	, &internal1_m606_Zv0},	//(internal1_m606_Zv0)  - Зад. выключатель механизма
	{ 841	,1	,1	, &internal1_m606_RA00},	//(internal1_m606_RA00)  - последнее задание вперед
	{ 842	,1	,1	, &internal1_m606_RA10},	//(internal1_m606_RA10)  - последнее задание назад
	{ 843	,1	,1	, &internal1_m606_MyFirstEnterFlag},	//(internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
	{ 844	,1	,1	, &internal1_m605_Pav0},	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
	{ 845	,1	,1	, &internal1_m605_Zav0},	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
	{ 846	,1	,1	, &internal1_m605_Pv0},	//(internal1_m605_Pv0)  - Пер. выключатель механизма
	{ 847	,1	,1	, &internal1_m605_Zv0},	//(internal1_m605_Zv0)  - Зад. выключатель механизма
	{ 848	,1	,1	, &internal1_m605_RA00},	//(internal1_m605_RA00)  - последнее задание вперед
	{ 849	,1	,1	, &internal1_m605_RA10},	//(internal1_m605_RA10)  - последнее задание назад
	{ 850	,1	,1	, &internal1_m605_MyFirstEnterFlag},	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
	{ 851	,8	,1	, &internal1_m652_y0},	//(internal1_m652_y0) y0 - внутренний параметр
	{ 852	,8	,1	, &internal1_m813_Chim0},	//(internal1_m813_Chim0) измеренная частота импульсов камеры Гц
	{ 853	,8	,1	, &internal1_m804_Chim0},	//(internal1_m804_Chim0) измеренная частота импульсов камеры Гц
	{ 854	,8	,1	, &internal1_m796_Chim0},	//(internal1_m796_Chim0) измеренная частота импульсов камеры Гц
	{ 855	,8	,1	, &internal1_m787_Chim0},	//(internal1_m787_Chim0) измеренная частота импульсов камеры Гц
	{ 856	,8	,1	, &internal1_m778_Chim0},	//(internal1_m778_Chim0) измеренная частота импульсов камеры Гц
	{ 857	,8	,1	, &internal1_m770_Chim0},	//(internal1_m770_Chim0) измеренная частота импульсов камеры Гц
	{ 858	,8	,1	, &internal1_m761_Chim0},	//(internal1_m761_Chim0) измеренная частота импульсов камеры Гц
	{ 859	,8	,1	, &internal1_m752_Chim0},	//(internal1_m752_Chim0) измеренная частота импульсов камеры Гц
	{ 860	,8	,1	, &internal1_m744_Chim0},	//(internal1_m744_Chim0) измеренная частота импульсов камеры Гц
	{ 861	,8	,1	, &internal1_m735_Chim0},	//(internal1_m735_Chim0) измеренная частота импульсов камеры Гц
	{ 862	,8	,1	, &internal1_m726_Chim0},	//(internal1_m726_Chim0) измеренная частота импульсов камеры Гц
	{ 863	,8	,1	, &internal1_m718_Chim0},	//(internal1_m718_Chim0) измеренная частота импульсов камеры Гц
	{ 864	,1	,1	, &internal1_m592_Pav0},	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
	{ 865	,1	,1	, &internal1_m592_Zav0},	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
	{ 866	,1	,1	, &internal1_m592_Pv0},	//(internal1_m592_Pv0)  - Пер. выключатель механизма
	{ 867	,1	,1	, &internal1_m592_Zv0},	//(internal1_m592_Zv0)  - Зад. выключатель механизма
	{ 868	,1	,1	, &internal1_m592_RA00},	//(internal1_m592_RA00)  - последнее задание вперед
	{ 869	,1	,1	, &internal1_m592_RA10},	//(internal1_m592_RA10)  - последнее задание назад
	{ 870	,1	,1	, &internal1_m592_MyFirstEnterFlag},	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
	{ 871	,1	,1	, &internal1_m577_Pav0},	//(internal1_m577_Pav0)  - Пер.аварийный выключатель механизма
	{ 872	,1	,1	, &internal1_m577_Zav0},	//(internal1_m577_Zav0)  - Зад.аварийный выключатель механизма
	{ 873	,1	,1	, &internal1_m577_Pv0},	//(internal1_m577_Pv0)  - Пер. выключатель механизма
	{ 874	,1	,1	, &internal1_m577_Zv0},	//(internal1_m577_Zv0)  - Зад. выключатель механизма
	{ 875	,1	,1	, &internal1_m577_RA00},	//(internal1_m577_RA00)  - последнее задание вперед
	{ 876	,1	,1	, &internal1_m577_RA10},	//(internal1_m577_RA10)  - последнее задание назад
	{ 877	,1	,1	, &internal1_m577_MyFirstEnterFlag},	//(internal1_m577_MyFirstEnterFlag) MyFirstEnterFlag
	{ 878	,1	,1	, &internal1_m463_Pav0},	//(internal1_m463_Pav0)  - Пер.аварийный выключатель механизма
	{ 879	,1	,1	, &internal1_m463_Zav0},	//(internal1_m463_Zav0)  - Зад.аварийный выключатель механизма
	{ 880	,1	,1	, &internal1_m463_Pv0},	//(internal1_m463_Pv0)  - Пер. выключатель механизма
	{ 881	,1	,1	, &internal1_m463_Zv0},	//(internal1_m463_Zv0)  - Зад. выключатель механизма
	{ 882	,1	,1	, &internal1_m463_RA00},	//(internal1_m463_RA00)  - последнее задание вперед
	{ 883	,1	,1	, &internal1_m463_RA10},	//(internal1_m463_RA10)  - последнее задание назад
	{ 884	,1	,1	, &internal1_m463_MyFirstEnterFlag},	//(internal1_m463_MyFirstEnterFlag) MyFirstEnterFlag
	{ 885	,1	,1	, &internal1_m448_Pav0},	//(internal1_m448_Pav0)  - Пер.аварийный выключатель механизма
	{ 886	,1	,1	, &internal1_m448_Zav0},	//(internal1_m448_Zav0)  - Зад.аварийный выключатель механизма
	{ 887	,1	,1	, &internal1_m448_Pv0},	//(internal1_m448_Pv0)  - Пер. выключатель механизма
	{ 888	,1	,1	, &internal1_m448_Zv0},	//(internal1_m448_Zv0)  - Зад. выключатель механизма
	{ 889	,1	,1	, &internal1_m448_RA00},	//(internal1_m448_RA00)  - последнее задание вперед
	{ 890	,1	,1	, &internal1_m448_RA10},	//(internal1_m448_RA10)  - последнее задание назад
	{ 891	,1	,1	, &internal1_m448_MyFirstEnterFlag},	//(internal1_m448_MyFirstEnterFlag) MyFirstEnterFlag
	{ 892	,1	,1	, &internal1_m504_Pav0},	//(internal1_m504_Pav0)  - Пер.аварийный выключатель механизма
	{ 893	,1	,1	, &internal1_m504_Zav0},	//(internal1_m504_Zav0)  - Зад.аварийный выключатель механизма
	{ 894	,1	,1	, &internal1_m504_Pv0},	//(internal1_m504_Pv0)  - Пер. выключатель механизма
	{ 895	,1	,1	, &internal1_m504_Zv0},	//(internal1_m504_Zv0)  - Зад. выключатель механизма
	{ 896	,1	,1	, &internal1_m504_RA00},	//(internal1_m504_RA00)  - последнее задание вперед
	{ 897	,1	,1	, &internal1_m504_RA10},	//(internal1_m504_RA10)  - последнее задание назад
	{ 898	,1	,1	, &internal1_m504_MyFirstEnterFlag},	//(internal1_m504_MyFirstEnterFlag) MyFirstEnterFlag
	{ 899	,1	,1	, &internal1_m399_Pav0},	//(internal1_m399_Pav0)  - Пер.аварийный выключатель механизма
	{ 900	,1	,1	, &internal1_m399_Zav0},	//(internal1_m399_Zav0)  - Зад.аварийный выключатель механизма
	{ 901	,1	,1	, &internal1_m399_Pv0},	//(internal1_m399_Pv0)  - Пер. выключатель механизма
	{ 902	,1	,1	, &internal1_m399_Zv0},	//(internal1_m399_Zv0)  - Зад. выключатель механизма
	{ 903	,1	,1	, &internal1_m399_RA00},	//(internal1_m399_RA00)  - последнее задание вперед
	{ 904	,1	,1	, &internal1_m399_RA10},	//(internal1_m399_RA10)  - последнее задание назад
	{ 905	,1	,1	, &internal1_m399_MyFirstEnterFlag},	//(internal1_m399_MyFirstEnterFlag) MyFirstEnterFlag
	{ 906	,1	,1	, &internal1_m383_Pav0},	//(internal1_m383_Pav0)  - Пер.аварийный выключатель механизма
	{ 907	,1	,1	, &internal1_m383_Zav0},	//(internal1_m383_Zav0)  - Зад.аварийный выключатель механизма
	{ 908	,1	,1	, &internal1_m383_Pv0},	//(internal1_m383_Pv0)  - Пер. выключатель механизма
	{ 909	,1	,1	, &internal1_m383_Zv0},	//(internal1_m383_Zv0)  - Зад. выключатель механизма
	{ 910	,1	,1	, &internal1_m383_RA00},	//(internal1_m383_RA00)  - последнее задание вперед
	{ 911	,1	,1	, &internal1_m383_RA10},	//(internal1_m383_RA10)  - последнее задание назад
	{ 912	,1	,1	, &internal1_m383_MyFirstEnterFlag},	//(internal1_m383_MyFirstEnterFlag) MyFirstEnterFlag
	{ 913	,1	,1	, &internal1_m366_Pav0},	//(internal1_m366_Pav0)  - Пер.аварийный выключатель механизма
	{ 914	,1	,1	, &internal1_m366_Zav0},	//(internal1_m366_Zav0)  - Зад.аварийный выключатель механизма
	{ 915	,1	,1	, &internal1_m366_Pv0},	//(internal1_m366_Pv0)  - Пер. выключатель механизма
	{ 916	,1	,1	, &internal1_m366_Zv0},	//(internal1_m366_Zv0)  - Зад. выключатель механизма
	{ 917	,1	,1	, &internal1_m366_RA00},	//(internal1_m366_RA00)  - последнее задание вперед
	{ 918	,1	,1	, &internal1_m366_RA10},	//(internal1_m366_RA10)  - последнее задание назад
	{ 919	,1	,1	, &internal1_m366_MyFirstEnterFlag},	//(internal1_m366_MyFirstEnterFlag) MyFirstEnterFlag
	{ 920	,1	,1	, &internal1_m906_Pav0},	//(internal1_m906_Pav0)  - Пер.аварийный выключатель механизма
	{ 921	,1	,1	, &internal1_m906_Zav0},	//(internal1_m906_Zav0)  - Зад.аварийный выключатель механизма
	{ 922	,1	,1	, &internal1_m906_Pv0},	//(internal1_m906_Pv0)  - Пер. выключатель механизма
	{ 923	,1	,1	, &internal1_m906_Zv0},	//(internal1_m906_Zv0)  - Зад. выключатель механизма
	{ 924	,1	,1	, &internal1_m906_RA00},	//(internal1_m906_RA00)  - последнее задание вперед
	{ 925	,1	,1	, &internal1_m906_RA10},	//(internal1_m906_RA10)  - последнее задание назад
	{ 926	,1	,1	, &internal1_m906_MyFirstEnterFlag},	//(internal1_m906_MyFirstEnterFlag) MyFirstEnterFlag
	{ 927	,8	,1	, &internal1_m182_C1},	//(internal1_m182_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 928	,8	,1	, &internal1_m182_C2},	//(internal1_m182_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 929	,8	,1	, &internal1_m182_C3},	//(internal1_m182_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 930	,8	,1	, &internal1_m182_C4},	//(internal1_m182_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 931	,8	,1	, &internal1_m182_C5},	//(internal1_m182_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 932	,8	,1	, &internal1_m182_C6},	//(internal1_m182_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 933	,8	,1	, &internal1_m182_N20},	//(internal1_m182_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 934	,8	,6	, &internal1_m182_C0},	//(internal1_m182_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 935	,1	,1	, &internal1_m182_ImpINI0},	//(internal1_m182_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 936	,1	,1	, &internal1_m182_MyFirstEnterFlag},	//(internal1_m182_MyFirstEnterFlag) MyFirstEnterFlag
	{ 937	,1	,1	, &internal1_m300_Ppv0},	//(internal1_m300_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 938	,1	,1	, &internal1_m300_Pav0},	//(internal1_m300_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 939	,1	,1	, &internal1_m300_Zav0},	//(internal1_m300_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 940	,1	,1	, &internal1_m300_RA00},	//(internal1_m300_RA00) RA00 - последнее задание вперед
	{ 941	,1	,1	, &internal1_m300_RA10},	//(internal1_m300_RA10) RA10 - последнее задание назад
	{ 942	,18	,1	, &internal1_m300_RA50},	//(internal1_m300_RA50) Ra50 - последнее задание скорости
	{ 943	,1	,1	, &internal1_m300_fls},	//(internal1_m300_fls)  fls - флаг одношагового режима
	{ 944	,1	,1	, &internal1_m300_flp},	//(internal1_m300_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 945	,1	,1	, &internal1_m300_MyFirstEnterFlag},	//(internal1_m300_MyFirstEnterFlag) MyFirstEnterFlag
	{ 946	,1	,1	, &internal1_m133_Ppv0},	//(internal1_m133_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 947	,1	,1	, &internal1_m133_Pav0},	//(internal1_m133_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 948	,1	,1	, &internal1_m133_Zav0},	//(internal1_m133_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 949	,1	,1	, &internal1_m133_RA00},	//(internal1_m133_RA00) RA00 - последнее задание вперед
	{ 950	,1	,1	, &internal1_m133_RA10},	//(internal1_m133_RA10) RA10 - последнее задание назад
	{ 951	,18	,1	, &internal1_m133_RA50},	//(internal1_m133_RA50) Ra50 - последнее задание скорости
	{ 952	,1	,1	, &internal1_m133_fls},	//(internal1_m133_fls)  fls - флаг одношагового режима
	{ 953	,1	,1	, &internal1_m133_flp},	//(internal1_m133_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 954	,1	,1	, &internal1_m133_MyFirstEnterFlag},	//(internal1_m133_MyFirstEnterFlag) MyFirstEnterFlag
	{ 955	,1	,1	, &internal1_m266_Ppv0},	//(internal1_m266_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 956	,1	,1	, &internal1_m266_Pav0},	//(internal1_m266_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 957	,1	,1	, &internal1_m266_Zav0},	//(internal1_m266_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 958	,1	,1	, &internal1_m266_RA00},	//(internal1_m266_RA00) RA00 - последнее задание вперед
	{ 959	,1	,1	, &internal1_m266_RA10},	//(internal1_m266_RA10) RA10 - последнее задание назад
	{ 960	,18	,1	, &internal1_m266_RA50},	//(internal1_m266_RA50) Ra50 - последнее задание скорости
	{ 961	,1	,1	, &internal1_m266_fls},	//(internal1_m266_fls)  fls - флаг одношагового режима
	{ 962	,1	,1	, &internal1_m266_flp},	//(internal1_m266_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 963	,1	,1	, &internal1_m266_MyFirstEnterFlag},	//(internal1_m266_MyFirstEnterFlag) MyFirstEnterFlag
	{ 964	,1	,1	, &internal1_m96_Ppv0},	//(internal1_m96_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 965	,1	,1	, &internal1_m96_Pav0},	//(internal1_m96_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 966	,1	,1	, &internal1_m96_Zav0},	//(internal1_m96_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 967	,1	,1	, &internal1_m96_RA00},	//(internal1_m96_RA00) RA00 - последнее задание вперед
	{ 968	,1	,1	, &internal1_m96_RA10},	//(internal1_m96_RA10) RA10 - последнее задание назад
	{ 969	,18	,1	, &internal1_m96_RA50},	//(internal1_m96_RA50) Ra50 - последнее задание скорости
	{ 970	,1	,1	, &internal1_m96_fls},	//(internal1_m96_fls)  fls - флаг одношагового режима
	{ 971	,1	,1	, &internal1_m96_flp},	//(internal1_m96_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 972	,1	,1	, &internal1_m96_MyFirstEnterFlag},	//(internal1_m96_MyFirstEnterFlag) MyFirstEnterFlag
	{ 973	,1	,1	, &internal1_m229_Ppv0},	//(internal1_m229_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 974	,1	,1	, &internal1_m229_Pav0},	//(internal1_m229_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 975	,1	,1	, &internal1_m229_Zav0},	//(internal1_m229_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 976	,1	,1	, &internal1_m229_RA00},	//(internal1_m229_RA00) RA00 - последнее задание вперед
	{ 977	,1	,1	, &internal1_m229_RA10},	//(internal1_m229_RA10) RA10 - последнее задание назад
	{ 978	,18	,1	, &internal1_m229_RA50},	//(internal1_m229_RA50) Ra50 - последнее задание скорости
	{ 979	,1	,1	, &internal1_m229_fls},	//(internal1_m229_fls)  fls - флаг одношагового режима
	{ 980	,1	,1	, &internal1_m229_flp},	//(internal1_m229_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 981	,1	,1	, &internal1_m229_MyFirstEnterFlag},	//(internal1_m229_MyFirstEnterFlag) MyFirstEnterFlag
	{ 982	,1	,1	, &internal1_m60_Ppv0},	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 983	,1	,1	, &internal1_m60_Pav0},	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 984	,1	,1	, &internal1_m60_Zav0},	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 985	,1	,1	, &internal1_m60_RA00},	//(internal1_m60_RA00) RA00 - последнее задание вперед
	{ 986	,1	,1	, &internal1_m60_RA10},	//(internal1_m60_RA10) RA10 - последнее задание назад
	{ 987	,18	,1	, &internal1_m60_RA50},	//(internal1_m60_RA50) Ra50 - последнее задание скорости
	{ 988	,1	,1	, &internal1_m60_fls},	//(internal1_m60_fls)  fls - флаг одношагового режима
	{ 989	,1	,1	, &internal1_m60_flp},	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 990	,1	,1	, &internal1_m60_MyFirstEnterFlag},	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
	{ 991	,8	,1	, &internal1_m14_C1},	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 992	,8	,1	, &internal1_m14_C2},	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 993	,8	,1	, &internal1_m14_C3},	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 994	,8	,1	, &internal1_m14_C4},	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 995	,8	,1	, &internal1_m14_C5},	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 996	,8	,1	, &internal1_m14_C6},	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 997	,8	,1	, &internal1_m14_N20},	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 998	,8	,6	, &internal1_m14_C0},	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 999	,1	,1	, &internal1_m14_ImpINI0},	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 1000	,1	,1	, &internal1_m14_MyFirstEnterFlag},	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="scm.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{277,"fEM_R0UL01RIM\0"}, 
{278,"fEM_R0UN02RIM\0"}, 
{279,"fEM_A1UR01RIM\0"}, 
{280,"fEM_A1UR00RIM\0"}, 
{281,"fEM_A3UR00RIM\0"}, 
{282,"fEM_A3UR01RIM\0"}, 
{283,"fEM_R0UT01RIM\0"}, 
{284,"fEM_R0UT02RIM\0"}, 
{285,"fEM_R0UT04RIM\0"}, 
{286,"fEM_R0UT03RIM\0"}, 
{287,"fEM_R0UT05RIM\0"}, 
{288,"fEM_R0UT06RIM\0"}, 
{289,"fEM_A1UC02RDU\0"}, 
{290,"fEM_A1UC04RIM\0"}, 
{291,"fEM_A1UC05RIM\0"}, 
{292,"fEM_A1UC06RIM\0"}, 
{293,"fEM_A2UC06RIM\0"}, 
{294,"fEM_A2UC05RIM\0"}, 
{295,"fEM_A2UC04RIM\0"}, 
{296,"fEM_A2UC02RDU\0"}, 
{297,"fEM_A3UC06RIM\0"}, 
{298,"fEM_A3UC05RIM\0"}, 
{299,"fEM_A3UC04RIM\0"}, 
{300,"fEM_A3UC02RDU\0"}, 
{301,"fEM_R4UV80RDU\0"}, 
{302,"fEM_R4UC10RIM\0"}, 
{303,"fEM_R4UC20RIM\0"}, 
{304,"fEM_B8UC21RIM\0"}, 
{305,"fEM_B8UC20RIM\0"}, 
{306,"fEM_B8UC11RIM\0"}, 
{307,"fEM_B8UC10RIM\0"}, 
{308,"fEM_B8UV80RDU\0"}, 
{309,"fEM_A8UV80RDU\0"}, 
{310,"fEM_A8UC10RIM\0"}, 
{311,"fEM_A8UC11RIM\0"}, 
{312,"fEM_A8UC20RIM\0"}, 
{313,"fEM_A8UC21RIM\0"}, 
{314,"fEM_A6UC10RIM\0"}, 
{315,"fEM_R1UC10RIM\0"}, 
{316,"fEM_A5UC10RIM\0"}, 
{317,"fEM_A0UN01RIM\0"}, 
{318,"fEM_R4UC22RIM\0"}, 
{319,"fEM_A1UG01RDU\0"}, 
{320,"fEM_A2UG01RDU\0"}, 
{321,"fEM_A3UG01RDU\0"}, 
{322,"fEM_R7UC10RIM\0"}, 
{323,"fEM_R7UC19RIM\0"}, 
{324,"fEM_R7UI02RIM\0"}, 
{325,"fEM_R7UL01RIM\0"}, 
{326,"fEM_A2UR00RIM\0"}, 
{327,"fEM_A2UR01RIM\0"}, 
{328,"fEM_A0UN02RIM\0"}, 
{329,"fEM_R0UR30RIM\0"}, 
{330,"fEM_R0UR01RIM\0"}, 
{331,"fEM_R0UT02RDU\0"}, 
{332,"fEM_R0UT01RDU\0"}, 
{333,"fEM_A1UC03RDU\0"}, 
{334,"fEM_A2UP03RDU\0"}, 
{335,"fEM_A2UP04RDU\0"}, 
{336,"fEM_A2UC03RDU\0"}, 
{337,"fEM_A3UP03RDU\0"}, 
{338,"fEM_A3UP04RDU\0"}, 
{339,"fEM_A3UC03RDU\0"}, 
{340,"fEM_R7UI74RIM\0"}, 
{341,"fEM_A8UC03RDU\0"}, 
{342,"fEM_R0UV87RDU\0"}, 
{343,"fEM_R0UV81RDU\0"}, 
{344,"fEM_R0UV82RDU\0"}, 
{345,"fEM_R0UV83RDU\0"}, 
{346,"fEM_R0UV84RDU\0"}, 
{347,"fEM_R0UV85RDU\0"}, 
{348,"fEM_R0UV86RDU\0"}, 
{349,"fEM_A8UC08RDU\0"}, 
{350,"fEM_B8UC08RDU\0"}, 
{351,"fEM_R4UC08RDU\0"}, 
{352,"fEM_R0UH01RSS\0"}, 
{353,"fEM_A0UX00RSS\0"}, 
{354,"fEM_R7UX01RSS\0"}, 
{355,"fEM_R7UX02RSS\0"}, 
{356,"fEM_R7UX04RSS\0"}, 
{357,"fEM_R7UX05RSS\0"}, 
{358,"fEM_R7UX06RSS\0"}, 
{359,"fEM_R7UX07RSS\0"}, 
{360,"fEM_R7UX08RSS\0"}, 
{361,"fEM_R7UX09RSS\0"}, 
{362,"fEM_R7UY01RSS\0"}, 
{363,"fEM_R7UY02RSS\0"}, 
{364,"fEM_R7UY04RSS\0"}, 
{365,"fEM_R7UY05RSS\0"}, 
{366,"fEM_R7UY06RSS\0"}, 
{367,"fEM_R7UY07RSS\0"}, 
{368,"fEM_R7UY08RSS\0"}, 
{369,"fEM_R7UY09RSS\0"}, 
{370,"fEM_R7UX10RSS\0"}, 
{371,"fEM_R7UX11RSS\0"}, 
{372,"fEM_R7UX12RSS\0"}, 
{373,"fEM_R7UY10RSS\0"}, 
{374,"fEM_R7UY11RSS\0"}, 
{375,"fEM_R7UY12RSS\0"}, 
{376,"fEM_A0UX01RSS\0"}, 
{377,"fEM_A0UX02RSS\0"}, 
{378,"fEM_A0UX03RSS\0"}, 
{379,"fEM_A0UX04RSS\0"}, 
{380,"fEM_A0UX05RSS\0"}, 
{381,"fEM_A0UX06RSS\0"}, 
{382,"fEM_A0UX07RSS\0"}, 
{383,"fEM_A0UX08RSS\0"}, 
{384,"fEM_A0UX09RSS\0"}, 
{385,"fEM_A0UX10RSS\0"}, 
{386,"fEM_A0UX11RSS\0"}, 
{387,"fEM_A0UX12RSS\0"}, 
{388,"fEM_B0UX01RSS\0"}, 
{389,"fEM_B0UX02RSS\0"}, 
{390,"fEM_B0UX03RSS\0"}, 
{391,"fEM_B0UX04RSS\0"}, 
{392,"fEM_B0UX05RSS\0"}, 
{393,"fEM_B0UX06RSS\0"}, 
{394,"fEM_B0UX07RSS\0"}, 
{395,"fEM_B0UX08RSS\0"}, 
{396,"fEM_B0UX09RSS\0"}, 
{397,"fEM_B0UX10RSS\0"}, 
{398,"fEM_B0UX11RSS\0"}, 
{399,"fEM_B0UX12RSS\0"}, 
{400,"fEM_R0UH02RSS\0"}, 
{401,"fEM_R0UH03RSS\0"}, 
{402,"fEM_R4US80RDU\0"}, 
{403,"fEM_R7UI71RIM\0"}, 
{404,"fEM_R7UI72RIM\0"}, 
{405,"fEM_R7UI73RIM\0"}, 
{406,"fEM_A1UP01RIM\0"}, 
{407,"fEM_A2UP01RIM\0"}, 
{408,"fEM_A0UP02RIM\0"}, 
{409,"fEM_A3UP01RIM\0"}, 
{410,"fEM_A1UP82RIM\0"}, 
{411,"fEM_A3UP02RDU\0"}, 
{412,"fEM_A1UV02RIM\0"}, 
{413,"fEM_A3UV02RIM\0"}, 
{414,"fEM_A2UV02RIM\0"}, 
{415,"fEM_B8US80RDU\0"}, 
{416,"fEM_A8US80RDU\0"}, 
{417,"fEM_A6US80RDU\0"}, 
{418,"fEM_A1US07RDU\0"}, 
{419,"fEM_A2US07RDU\0"}, 
{420,"fEM_A3US07RDU\0"}, 
{421,"fEM_R7UI75RIM\0"}, 
{422,"fEM_R0UH21RSS\0"}, 
{423,"fEM_R0UH22RSS\0"}, 
{424,"fEM_R0UH23RSS\0"}, 
{425,"fEM_R0UH05RSS\0"}, 
{426,"fEM_A4UL10RIM\0"}, 
{427,"fEM_A9UL10RIM\0"}, 
{428,"fEM_R3UL10RIM\0"}, 
{429,"fEM_R5UL10RIM\0"}, 
{430,"fEM_R6UL10RIM\0"}, 
{431,"lEM_C1AD31LRP\0"}, 
{432,"lEM_R0IE01LRP\0"}, 
{433,"lEM_R0IE02LRP\0"}, 
{434,"fEM_A2UP02RIM\0"}, 
{435,"fEM_A2UP03RIM\0"}, 
{436,"fEM_A0UP01RIM\0"}, 
{437,"fEM_A3UP02RIM\0"}, 
{438,"fEM_A4UP01RIM\0"}, 
{439,"fEM_A4UP02RIM\0"}, 
{440,"fEM_R7UI76RIM\0"}, 
{441,"fEM_R7UI77RIM\0"}, 
{442,"iEM_TERBB1\0"}, 
{443,"fEM_A1MC02RC1\0"}, 
{444,"fEM_A1MV02RC1\0"}, 
{445,"iEM_TERBB2\0"}, 
{446,"fEM_B1MC02RC1\0"}, 
{447,"fEM_B1MV02RC1\0"}, 
{448,"iEM_TERRB2\0"}, 
{449,"fEM_B2MC02RC1\0"}, 
{450,"fEM_B2MV02RC1\0"}, 
{451,"iEM_TERRB1\0"}, 
{452,"fEM_A2MC02RC1\0"}, 
{453,"fEM_A2MV02RC1\0"}, 
{454,"iEM_TERIS2\0"}, 
{455,"fEM_B3MC02RC1\0"}, 
{456,"fEM_B3MV02RC1\0"}, 
{457,"iEM_TERIS1\0"}, 
{458,"fEM_A3MC02RC1\0"}, 
{459,"fEM_A3MV02RC1\0"}, 
{460,"iEM_TERA1IE04LDU\0"}, 
{461,"iEM_TERA1IE03LDU\0"}, 
{462,"fEM_A1MC01RC1\0"}, 
{463,"iEM_TERB1IE03LDU\0"}, 
{464,"iEM_TERB1IE04LDU\0"}, 
{465,"fEM_B1MC01RC1\0"}, 
{466,"fEM_B1MV01RC1\0"}, 
{467,"fEM_B2MC01RC1\0"}, 
{468,"fEM_B2MV01RC1\0"}, 
{469,"fEM_A3MC01RC1\0"}, 
{470,"fEM_A3MV01RC1\0"}, 
{471,"fEM_B3MC01RC1\0"}, 
{472,"fEM_B3MV01RC1\0"}, 
{473,"iEM_TERA2SS21LIM\0"}, 
{474,"iEM_TERA2SS12LIM\0"}, 
{475,"iEM_TERR6SS21LIM\0"}, 
{476,"iEM_TERA2VP82LIM\0"}, 
{477,"iEM_TERA2SS11LIM\0"}, 
{478,"iEM_TERB3SS21LIM\0"}, 
{479,"iEM_TERA0MT01RIM\0"}, 
{480,"iEM_TERB0MT01RIM\0"}, 
{481,"iEM_TERA2SP01RIM\0"}, 
{482,"iEM_TERB2SP01RIM\0"}, 
{483,"iEM_TERB3SP02RIM\0"}, 
{484,"iEM_TERA3SC01RIM\0"}, 
{485,"iEM_TERA3VP81LIM\0"}, 
{486,"iEM_TERA2SC01RIM\0"}, 
{487,"iEM_TERA2SS33LIM\0"}, 
{488,"iEM_TERA3SS21LIM\0"}, 
{489,"iEM_TERA3SS33LIM\0"}, 
{490,"iEM_TERA3SS31LIM\0"}, 
{491,"iEM_TERB3SS31LIM\0"}, 
{492,"iEM_TERB3SS33LIM\0"}, 
{493,"iEM_TERB3SC01RIM\0"}, 
{494,"iEM_TERA3SS11LIM\0"}, 
{495,"iEM_TERB3SS11LIM\0"}, 
{496,"iEM_TERR6IS64LIM\0"}, 
{497,"iEM_TERB3SS22LIM\0"}, 
{498,"iEM_TERA3SS22LIM\0"}, 
{499,"iEM_TERA3SP02RIM\0"}, 
{500,"iEM_TERR6IS62LIM\0"}, 
{501,"iEM_TERR6IS66LIM\0"}, 
{502,"iEM_TERR6IS67LIM\0"}, 
{503,"iEM_TERA0VP81LIM\0"}, 
{504,"iEM_TERB0VP81LIM\0"}, 
{505,"iEM_TERR0VP81LIM\0"}, 
{506,"iEM_TERR6IS68LIM\0"}, 
{507,"iEM_TERR7SI74RIM\0"}, 
{508,"iEM_TERA5SS21LIM\0"}, 
{509,"iEM_TERB5SS11LIM\0"}, 
{510,"iEM_TERA5SS11LIM\0"}, 
{511,"iEM_TERA9SS11LIM\0"}, 
{512,"iEM_TERB2SS11LIM\0"}, 
{513,"iEM_TERB2SS12LIM\0"}, 
{514,"iEM_TERB2SS21LIM\0"}, 
{515,"iEM_TERR3SS11LIM\0"}, 
{516,"iEM_TERB2SC01RIM\0"}, 
{517,"iEM_TERR3SS21LIM\0"}, 
{518,"iEM_TERR5SS11LIM\0"}, 
{519,"iEM_TERA4SS11LIM\0"}, 
{520,"iEM_TERR1SS11LIM\0"}, 
{521,"iEM_TERR1SS21LIM\0"}, 
{522,"iEM_TERR2SS11LIM\0"}, 
{523,"iEM_TERR2SS21LIM\0"}, 
{524,"iEM_TERA4VP82LIM\0"}, 
{525,"iEM_TERB4SS21LIM\0"}, 
{526,"iEM_TERR5SS21LIM\0"}, 
{527,"iEM_TERB6SS21LIM\0"}, 
{528,"iEM_TERB4SS11LIM\0"}, 
{529,"iEM_TERA4SS21LIM\0"}, 
{530,"iEM_TERA6MS11LIM\0"}, 
{531,"iEM_TERA6SS21LIM\0"}, 
{532,"iEM_TERB6SS11LIM\0"}, 
{533,"iEM_TERR4SS11LIM\0"}, 
{534,"iEM_TERR4MS21LIM\0"}, 
{535,"iEM_TERR4SS12LIM\0"}, 
{536,"iEM_TERR4SS22LIM\0"}, 
{537,"iEM_TERR8SS11LIM\0"}, 
{538,"iEM_TERB8SC01RIM\0"}, 
{539,"iEM_TERA8SC01RIM\0"}, 
{540,"iEM_TERB8SS12LIM\0"}, 
{541,"iEM_TERA8SS12LIM\0"}, 
{542,"iEM_TERB8SS22LIM\0"}, 
{543,"iEM_TERA8SS22LIM\0"}, 
{544,"iEM_TERA9SS21LIM\0"}, 
{545,"iEM_TERB9SS21LIM\0"}, 
{546,"iEM_TERB9SS11LIM\0"}, 
{547,"iEM_TERB5SS21LIM\0"}, 
{548,"iEM_TERA1SS21LIM\0"}, 
{549,"iEM_TERA1SS11LIM\0"}, 
{550,"iEM_TERA1SC01RIM\0"}, 
{551,"iEM_TERA1SS12LIM\0"}, 
{552,"iEM_TERB1SS21LIM\0"}, 
{553,"iEM_TERB1SS11LIM\0"}, 
{554,"iEM_TERB1MC01RIM\0"}, 
{555,"iEM_TERB1SS12LIM\0"}, 
{556,"iEM_TERTLG\0"}, 
{557,"fEM_R4MC01RC1\0"}, 
{558,"fEM_R4MV01RC1\0"}, 
{559,"iEM_TERMAZ2\0"}, 
{560,"fEM_B8MC01RC1\0"}, 
{561,"fEM_B8MV01RC1\0"}, 
{562,"iEM_TERDS2\0"}, 
{563,"fEM_A8MC01RC1\0"}, 
{564,"fEM_A8MV01RC1\0"}, 
{565,"iEM_TERBZ1\0"}, 
{566,"fEM_A6MC01RC1\0"}, 
{567,"fEM_A6MV01RC1\0"}, 
{568,"iEM_TERBZ2\0"}, 
{569,"fEM_B6MC01RC1\0"}, 
{570,"fEM_B6MV01RC1\0"}, 
{571,"lEM_R3AD10LC1\0"}, 
{572,"lEM_R3AD20LC1\0"}, 
{573,"lEM_R6AD10LC1\0"}, 
{574,"lEM_R5AD10LC1\0"}, 
{575,"lEM_R5AD20LC1\0"}, 
{576,"iEM_TERMDZ2\0"}, 
{577,"fEM_R2MC01RC1\0"}, 
{578,"fEM_R2MV01RC1\0"}, 
{579,"iEM_TERMDZ1\0"}, 
{580,"fEM_R1MC01RC1\0"}, 
{581,"fEM_R1MV01RC1\0"}, 
{582,"iEM_TERNL1\0"}, 
{583,"fEM_A5MC01RC1\0"}, 
{584,"fEM_A5MV01RC1\0"}, 
{585,"iEM_TERNL2\0"}, 
{586,"fEM_B5MC01RC1\0"}, 
{587,"fEM_B5MV01RC1\0"}, 
{588,"lEM_R8AD10LC1\0"}, 
{589,"fEM_A1UC08RIM\0"}, 
{590,"fEM_A2UC08RIM\0"}, 
{591,"fEM_A3UC08RIM\0"}, 
{592,"iEM_TERB2SS33LIM\0"}, 
{593,"iEM_TERA1VP81LIM\0"}, 
{594,"iEM_TERB1VP81LIM\0"}, 
{595,"fEM_A0UT03RSP\0"}, 
{596,"fEM_A0UR01RSP\0"}, 
{597,"fEM_A0UR02RSP\0"}, 
{598,"fEM_B0UT03RSP\0"}, 
{599,"fEM_A1MC01RSP\0"}, 
{600,"fEM_A1MC02RSP\0"}, 
{601,"fEM_A1MV01RSP\0"}, 
{602,"fEM_A1MV02RSP\0"}, 
{603,"fEM_B1MC01RSP\0"}, 
{604,"fEM_B1MV01RSP\0"}, 
{605,"fEM_B1MC02RSP\0"}, 
{606,"fEM_B1MV02RSP\0"}, 
{607,"fEM_A2MC01RC1\0"}, 
{608,"fEM_A2MV01RC1\0"}, 
{609,"fEM_A2MC01RSP\0"}, 
{610,"fEM_A2MV01RSP\0"}, 
{611,"fEM_A2MC02RSP\0"}, 
{612,"fEM_A2MV02RSP\0"}, 
{613,"fEM_B2MC01RSP\0"}, 
{614,"fEM_B2MV01RSP\0"}, 
{615,"fEM_B2MC02RSP\0"}, 
{616,"fEM_B2MV02RSP\0"}, 
{617,"fEM_A3MC01RSP\0"}, 
{618,"fEM_A3MV01RSP\0"}, 
{619,"fEM_A3MC02RSP\0"}, 
{620,"fEM_A3MV02RSP\0"}, 
{621,"fEM_B3MC01RSP\0"}, 
{622,"fEM_B3MV01RSP\0"}, 
{623,"fEM_B3MC02RSP\0"}, 
{624,"fEM_B3MV02RSP\0"}, 
{625,"fEM_B8MC01RSP\0"}, 
{626,"fEM_B8MV01RSP\0"}, 
{627,"fEM_A8MC01RSP\0"}, 
{628,"fEM_A8MV01RSP\0"}, 
{629,"fEM_A6MC01RSP\0"}, 
{630,"fEM_A6MV01RSP\0"}, 
{631,"fEM_B6MC01RSP\0"}, 
{632,"fEM_B6MV01RSP\0"}, 
{633,"fEM_R3UC01RSP\0"}, 
{634,"fEM_R3UV01RSP\0"}, 
{635,"fEM_R5UC01RSP\0"}, 
{636,"fEM_R5UV01RSP\0"}, 
{637,"fEM_R6UC01RSP\0"}, 
{638,"fEM_R6UV01RSP\0"}, 
{639,"fEM_R2MC01RSP\0"}, 
{640,"fEM_R2MV01RSP\0"}, 
{641,"fEM_R1MC01RSP\0"}, 
{642,"fEM_R1MV01RSP\0"}, 
{643,"fEM_A5MC01RSP\0"}, 
{644,"fEM_A5MV01RSP\0"}, 
{645,"fEM_B5MC01RSP\0"}, 
{646,"fEM_B5MV01RSP\0"}, 
{647,"fEM_A9MC01RSP\0"}, 
{648,"fEM_A9MV01RSP\0"}, 
{649,"fEM_B9MC01RSP\0"}, 
{650,"fEM_B9MV01RSP\0"}, 
{651,"fEM_A4MC01RSP\0"}, 
{652,"fEM_A4MV01RSP\0"}, 
{653,"fEM_B4MC01RSP\0"}, 
{654,"fEM_B4MV01RSP\0"}, 
{655,"fEM_R4MC01RSP\0"}, 
{656,"fEM_R4MV01RSP\0"}, 
{657,"fEM_A1MV01RC1\0"}, 
{658,"iEM_TERB7MS31LIM\0"}, 
{659,"iEM_TERA7MS31LIM\0"}, 
{660,"fEM_R7UY00RSS\0"}, 
{661,"iEM_TERA6VS12LIM\0"}, 
{662,"iEM_TERA6VS22LIM\0"}, 
{663,"iEM_TERB6VS12LIM\0"}, 
{664,"iEM_TERB6VS22LIM\0"}, 
{665,"iEM_TERA5VS22LIM\0"}, 
{666,"iEM_TERA5VS12LIM\0"}, 
{667,"iEM_TERB5VS12LIM\0"}, 
{668,"iEM_TERB5VS22LIM\0"}, 
{669,"iEM_TERR1VS12LIM\0"}, 
{670,"iEM_TERR1VS22LIM\0"}, 
{671,"iEM_TERR2VS12LIM\0"}, 
{672,"iEM_TERR2VS22LIM\0"}, 
{673,"iEM_TERR4VS12LDU\0"}, 
{674,"iEM_TERR4VS22LDU\0"}, 
{675,"fEM_R4UC23RIM\0"}, 
{676,"fEM_A0UX13RSS\0"}, 
{677,"fEM_A0UX14RSS\0"}, 
{678,"fEM_A0UX15RSS\0"}, 
{679,"fEM_R7UX13RSS\0"}, 
{680,"fEM_R7UX14RSS\0"}, 
{681,"fEM_R7UX15RSS\0"}, 
{682,"fEM_R7UY13RSS\0"}, 
{683,"fEM_R7UY14RSS\0"}, 
{684,"fEM_R7UY15RSS\0"}, 
{685,"fEM_R7UX16RSS\0"}, 
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
	{&A2IS11LIM,1,0},	//( - , SCM) Магнит РБ1 обесточен
	{&A2IS32LIM,1,1},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{&B2IS11LIM,1,2},	//( - , SCM) Магнит РБ2 обесточен
	{&B2IS32LIM,1,3},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{&A6VS22LDU,1,4},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{&A6VS12LDU,1,5},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{&B6VS22LDU,1,6},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{&B6VS12LDU,1,7},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{&A5VS22LDU,1,8},	//( - , SCM) Движение НЛ1 в сторону НУ
	{&A5VS12LDU,1,9},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{&B5VS22LDU,1,10},	//( - , SCM) Движение НЛ2 в сторону НУ
	{&B5VS12LDU,1,11},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{&R1VS22LDU,1,12},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{&R2VS22LDU,1,13},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{&R2VS12LDU,1,14},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{&R1VS12LDU,1,15},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{&R4VS22LDU,1,16},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{&R4VS12LDU,1,17},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{&A2VP82LDU,1,18},	//( - , SCM) Давление ПОДЪЁМ РБ1 в норме
	{&A3VP81LDU,1,19},	//( - , SCM) Давление СПУСК ИС1 в норме
	{&B3VP81LDU,1,20},	//( - , SCM) Давление СПУСК ИС2 в норме
	{&B2VP82LDU,1,21},	//( - , SCM) Давление ПОДЪЁМ РБ2 в норме
	{&B4IS21LDU,1,22},	//( - K08DO, SCM) Приход на НУ НИ2
	{&A4VP82LDU,1,23},	//( - , SCM) Давление ПОДЪЁМ НИ1 в норме
	{&B4VP82LDU,1,24},	//( - , SCM) Давление ПОДЪЁМ НИ2 в норме
	{&A1IE03LDU,1,25},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{&A1IE04LDU,1,26},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{&B1IE03LDU,1,27},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{&B1IE04LDU,1,28},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{&A1IS11LIM,1,29},	//( - , SCM) Магнит ББ1 обесточен
	{&A1IS32LIM,1,30},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{&B1IS11LIM,1,31},	//( - , SCM) Магнит ББ2 обесточен
	{&B1IS32LIM,1,32},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
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
	{&fEM_R0UL01RIM,8,0},	//( - , SCM) Среднее время генерации нейтронов
	{&fEM_R0UN02RIM,8,2},	//( - , SCM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{&fEM_A1UR01RIM,8,4},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{&fEM_A1UR00RIM,8,6},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{&fEM_A3UR00RIM,8,8},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{&fEM_A3UR01RIM,8,10},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{&fEM_R0UT01RIM,8,12},	//( - , SCM) Температурный коэффициент (долл)
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
	{&fEM_R4UV80RDU,8,48},	//( - , SCM) Номинальная скорость тележки (мм/с)
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
	{&fEM_R7UX01RSS,8,150},	//( - , SCM) X-координата камеры R7IN11
	{&fEM_R7UX02RSS,8,152},	//( - , SCM) X-координата камеры R7IN12 (см)
	{&fEM_R7UX04RSS,8,154},	//( - , SCM) X-координата камеры R7IN21 (см)
	{&fEM_R7UX05RSS,8,156},	//( - , SCM) X-координата камеры R7IN22 (см)
	{&fEM_R7UX06RSS,8,158},	//( - , SCM) X-координата камеры R7IN23 (см)
	{&fEM_R7UX07RSS,8,160},	//( - , SCM) X-координата камеры R7IN31 (см)
	{&fEM_R7UX08RSS,8,162},	//( - , SCM) X-координата камеры R7IN32 (см)
	{&fEM_R7UX09RSS,8,164},	//( - , SCM) X-координата камеры R7IN33 (см)
	{&fEM_R7UY01RSS,8,166},	//( - , SCM) Y-координата камеры R7IN11
	{&fEM_R7UY02RSS,8,168},	//( - , SCM) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY04RSS,8,170},	//( - , SCM) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY05RSS,8,172},	//( - , SCM) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY06RSS,8,174},	//( - , SCM) Y-координата камеры R7IN23 (см)
	{&fEM_R7UY07RSS,8,176},	//( - , SCM) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY08RSS,8,178},	//( - , SCM) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY09RSS,8,180},	//( - , SCM) Y-координата камеры R7IN33 (см)
	{&fEM_R7UX10RSS,8,182},	//( - , SCM) X-координата камеры R7IN41
	{&fEM_R7UX11RSS,8,184},	//( - , SCM) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,186},	//( - , SCM) X-координата камеры R7IN43
	{&fEM_R7UY10RSS,8,188},	//( - , SCM) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,190},	//( - , SCM) Y-координата камеры R7IN42
	{&fEM_R7UY12RSS,8,192},	//( - , SCM) Y-координата камеры R7IN43
	{&fEM_A0UX01RSS,8,194},	//( - , SCM) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX02RSS,8,196},	//( - , SCM) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX03RSS,8,198},	//( - , SCM) Первый коэффициент калибровки камеры 3
	{&fEM_A0UX04RSS,8,200},	//( - , SCM) Первый коэффициент калибровки камеры4
	{&fEM_A0UX05RSS,8,202},	//( - , SCM) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX06RSS,8,204},	//( - , SCM) Первый коэффициент калибровки камеры 6
	{&fEM_A0UX07RSS,8,206},	//( - , SCM) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX08RSS,8,208},	//( - , SCM) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX09RSS,8,210},	//( - , SCM) Первый коэффициент калибровки камеры 9
	{&fEM_A0UX10RSS,8,212},	//( - , SCM) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX11RSS,8,214},	//( - , SCM) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX12RSS,8,216},	//( - , SCM) Первый коэффициент калибровки камеры 12
	{&fEM_B0UX01RSS,8,218},	//( - , SCM) Второй коэффициент калибровки камеры 1
	{&fEM_B0UX02RSS,8,220},	//( - , SCM) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX06RSS,8,222},	//( - , SCM) Второй коэффициент калибровки камеры 6
	{&fEM_B0UX07RSS,8,224},	//( - , SCM) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX08RSS,8,226},	//( - , SCM) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX09RSS,8,228},	//( - , SCM) Второй коэффициент калибровки камеры 9
	{&fEM_B0UX10RSS,8,230},	//( - , SCM) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX11RSS,8,232},	//( - , SCM) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX12RSS,8,234},	//( - , SCM) Второй коэффициент калибровки камеры 12
	{&fEM_R4US80RDU,8,236},	//( - , SCM) Тормозной путь тележки (мм)
	{&fEM_R7UI71RIM,8,238},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{&fEM_R7UI72RIM,8,240},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{&fEM_R7UI73RIM,8,242},	//( - , SCM) Уровень мощности срабатывания АС II УР  ватт
	{&fEM_A1UP01RIM,8,244},	//( - , SCM) Текущее давление на сброс ББ (МПа)
	{&fEM_A2UP01RIM,8,246},	//( - , SCM) Текущее давление на сброс РБ
	{&fEM_A0UP02RIM,8,248},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP01RIM,8,250},	//( - , SCM) Текущее давление на СПУСК ИС
	{&fEM_A1UP82RIM,8,252},	//( - , SCM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{&fEM_A3UP02RDU,8,254},	//( - , SCM) Текущее давление ВЫСТРЕЛ ИС
	{&fEM_A1UV02RIM,8,256},	//( - , SCM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{&fEM_A3UV02RIM,8,258},	//( - , SCM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{&fEM_A2UV02RIM,8,260},	//( - , SCM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{&fEM_B8US80RDU,8,262},	//( - , SCM) Тормозной путь АЗ2 (мм)
	{&fEM_A8US80RDU,8,264},	//( - , SCM) Тормозной путь ДС2 (мм)
	{&fEM_A6US80RDU,8,266},	//( - , SCM) Тормозной путь БЗ (мм)
	{&fEM_A1US07RDU,8,268},	//( - , SCM) Постоянная времени масляного демпфера ББ
	{&fEM_A2US07RDU,8,270},	//( - , SCM) Постоянная времени масляного демпфера РБ
	{&fEM_A3US07RDU,8,272},	//( - , SCM) Постоянная времени масляного демпфера ИС
	{&fEM_R7UI75RIM,8,274},	//( - , SCM) Множитель к уровню радиации
	{&fEM_R0UH05RSS,8,276},	//( - , SCM) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_A4UL10RIM,8,278},	//( - , SCM) Время полного перемещения НИ сек
	{&fEM_A9UL10RIM,8,280},	//( - , SCM) Время полного перемещения НИ ДС1/ДС2 сек
	{&fEM_R3UL10RIM,8,282},	//( - , SCM) Время полного хода гомогенных дверей (сек)
	{&fEM_R5UL10RIM,8,284},	//( - , SCM) Время полного хода ворот отстойной зоны (дес. мс)
	{&fEM_R6UL10RIM,8,286},	//( - , SCM) Время полного хода кран-балки сек
	{&fEM_A2UP02RIM,8,288},	//( - , SCM) Текущее давление на подъём РБ
	{&fEM_A2UP03RIM,8,290},	//( - , SCM) Нижняя граница давления на ПОДЪЁМ РБ
	{&fEM_A0UP01RIM,8,292},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP02RIM,8,294},	//( - , SCM) Нижняя граница  давления на СПУСК ИС
	{&fEM_A4UP01RIM,8,296},	//( - , SCM) Текущее давление на подъём НИ
	{&fEM_A4UP02RIM,8,298},	//( - , SCM) Нижняя граница давления на подъём НИ
	{&fEM_R7UI76RIM,8,300},	//( - , SCM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{&fEM_R7UI77RIM,8,302},	//( - , SCM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{&iEM_TERBB1,3,304},	//( - , SCM) Неисправности  ББ1
	{&fEM_A1MC02RC1,8,305},	//( - , SCM) Заданная координата штока ББ1 от ИС
	{&fEM_A1MV02RC1,8,307},	//( - , SCM) Заданная скорость движения  штока ББ1 от ИС
	{&iEM_TERBB2,3,309},	//( - , SCM) Неисправности  ББ2
	{&fEM_B1MC02RC1,8,310},	//( - , SCM) Заданная координата штока ББ2 от ИС
	{&fEM_B1MV02RC1,8,312},	//( - , SCM) Заданная скорость движения штока ББ2 от ИС
	{&iEM_TERRB2,3,314},	//( - , SCM) Неисправности  РБ2
	{&fEM_B2MC02RC1,8,315},	//( - , SCM) Заданная координата штока РБ2 от ИС
	{&fEM_B2MV02RC1,8,317},	//( - , SCM) Заданная скорость движения штока РБ2 от ИС
	{&iEM_TERRB1,3,319},	//( - , SCM) Неисправности  РБ1
	{&fEM_A2MC02RC1,8,320},	//( - , SCM) Заданная координата штока РБ1 от ИС
	{&fEM_A2MV02RC1,8,322},	//( - , SCM) Заданная скорость движения штока РБ1 от ИС
	{&iEM_TERIS2,3,324},	//( - , SCM) Неисправности  ИС2
	{&fEM_B3MC02RC1,8,325},	//( - , SCM) Заданная координата штока ИС2 от ИС
	{&fEM_B3MV02RC1,8,327},	//( - , SCM) Заданная скорость движения штока ИС2 от ИС
	{&iEM_TERIS1,3,329},	//( - , SCM) Неисправности  ИС1
	{&fEM_A3MC02RC1,8,330},	//( - , SCM) Заданная координата штока ИС1 от ИС
	{&fEM_A3MV02RC1,8,332},	//( - , SCM) Заданная скорость движения штока ИС1 от ИС
	{&iEM_TERA1IE04LDU,3,334},	//( - , SCM) Искажение Движение ББ1 назад (от БУШД)
	{&iEM_TERA1IE03LDU,3,335},	//( - , SCM) Искажение Движение ББ1 вперёд (от БУШД)
	{&fEM_A1MC01RC1,8,336},	//( - , SCM) Заданная координата  ББ1 от ИС
	{&iEM_TERB1IE03LDU,3,338},	//( - , SCM) Искажение Движение ББ2 вперёд (от БУШД)
	{&iEM_TERB1IE04LDU,3,339},	//( - , SCM) Искажение Движение ББ2 назад (от БУШД)
	{&fEM_B1MC01RC1,8,340},	//( - , SCM) Заданная координата ББ2 от ИС
	{&fEM_B1MV01RC1,8,342},	//( - , SCM) Заданная скорость движения ББ2 от ИС
	{&fEM_B2MC01RC1,8,344},	//( - , SCM) Заданная координата РБ2 от ИС
	{&fEM_B2MV01RC1,8,346},	//( - , SCM) Заданная скорость движения  РБ2 от ИС
	{&fEM_A3MC01RC1,8,348},	//( - , SCM) Заданная координата ИС1 от ИС
	{&fEM_A3MV01RC1,8,350},	//( - , SCM) Заданная скорость движения ИС1 от ИС
	{&fEM_B3MC01RC1,8,352},	//( - , SCM) Заданная координата ИС2 от ИС
	{&fEM_B3MV01RC1,8,354},	//( - , SCM) Заданная скорость движения ИС2 от ИС
	{&iEM_TERA2SS21LIM,3,356},	//( - , SCM) Искажение: Приход на НУ РБ1
	{&iEM_TERA2SS12LIM,3,357},	//( - , SCM) Искажение: Магнит РБ1 зацеплен
	{&iEM_TERR6SS21LIM,3,358},	//( - , SCM) Искажение: Кран-балка в нерабочем положении
	{&iEM_TERA2VP82LIM,3,359},	//( - , SCM) Искажение: Текущее давление на подъём РБ  в норме
	{&iEM_TERA2SS11LIM,3,360},	//( - , SCM) Искажение: Приход на ВУ РБ1
	{&iEM_TERB3SS21LIM,3,361},	//( - , SCM) Искажение: Приход на НУ ИС2
	{&iEM_TERA0MT01RIM,3,362},	//( - , SCM) Искажение: Текущая температура AЗ1
	{&iEM_TERB0MT01RIM,3,363},	//( - , SCM) Искажение: Текущая температура AЗ2
	{&iEM_TERA2SP01RIM,3,364},	//( - , SCM) Искажение: Текущее давление СБРОС РБ1
	{&iEM_TERB2SP01RIM,3,365},	//( - , SCM) Искажение: Текущее давление СБРОС РБ2
	{&iEM_TERB3SP02RIM,3,366},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{&iEM_TERA3SC01RIM,3,367},	//( - , SCM) Искажение: Координата штока ИС1
	{&iEM_TERA3VP81LIM,3,368},	//( - , SCM) Искажение: Текущее давление СПУСК ИС  в норме
	{&iEM_TERA2SC01RIM,3,369},	//( - , SCM) Искажение: Координата штока РБ1
	{&iEM_TERA2SS33LIM,3,370},	//( - , SCM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{&iEM_TERA3SS21LIM,3,371},	//( - , SCM) Искажение: Приход на НУ ИС1
	{&iEM_TERA3SS33LIM,3,372},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{&iEM_TERA3SS31LIM,3,373},	//( - , SCM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{&iEM_TERB3SS31LIM,3,374},	//( - , SCM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{&iEM_TERB3SS33LIM,3,375},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{&iEM_TERB3SC01RIM,3,376},	//( - , SCM) Искажение: Координата штока ИС2
	{&iEM_TERA3SS11LIM,3,377},	//( - , SCM) Искажение: Приход на ВУ ИС1
	{&iEM_TERB3SS11LIM,3,378},	//( - , SCM) Искажение: Приход на ВУ ИС2
	{&iEM_TERR6IS64LIM,3,379},	//( - , SCM) Искажение: Исправность ВИП ССДИ-35
	{&iEM_TERB3SS22LIM,3,380},	//( - , SCM) Искажение: Приход на НУП ИС2
	{&iEM_TERA3SS22LIM,3,381},	//( - , SCM) Искажение: Приход на НУП ИС1
	{&iEM_TERA3SP02RIM,3,382},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{&iEM_TERR6IS62LIM,3,383},	//( - , SCM) Искажение Исправность ВИП ССДИ-39
	{&iEM_TERR6IS66LIM,3,384},	//( - , SCM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&iEM_TERR6IS67LIM,3,385},	//( - , SCM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&iEM_TERA0VP81LIM,3,386},	//( - , SCM) Искажение: Давление  АЗ1  в норме
	{&iEM_TERB0VP81LIM,3,387},	//( - , SCM) Искажение: Давление  АЗ2 в норме
	{&iEM_TERR0VP81LIM,3,388},	//( - , SCM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{&iEM_TERR6IS68LIM,3,389},	//( - , SCM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{&iEM_TERR7SI74RIM,3,390},	//( - , SCM) Искажение: Радиация в реакторном зале
	{&iEM_TERA5SS21LIM,3,391},	//( - , SCM) Искажение: Приход на НУ НЛ1
	{&iEM_TERB5SS11LIM,3,392},	//( - , SCM) Искажение: Приход на ВУ НЛ2
	{&iEM_TERA5SS11LIM,3,393},	//( - , SCM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{&iEM_TERA9SS11LIM,3,394},	//( - , SCM) Искажение: Приход на ВУ НИ ДС1
	{&iEM_TERB2SS11LIM,3,395},	//( - , SCM) Искажение: Приход на ВУ РБ2
	{&iEM_TERB2SS12LIM,3,396},	//( - , SCM) Искажение: Магнит РБ2 зацеплен
	{&iEM_TERB2SS21LIM,3,397},	//( - , SCM) Искажение: Приход на НУ РБ2
	{&iEM_TERR3SS11LIM,3,398},	//( - , SCM) Искажение: Приход на ВУ гомогенных дверей-1
	{&iEM_TERB2SC01RIM,3,399},	//( - , SCM) Искажение: Координата штока РБ2
	{&iEM_TERR3SS21LIM,3,400},	//( - , SCM) Искажение: Приход на НУ гомогенных дверей-1
	{&iEM_TERR5SS11LIM,3,401},	//( - , SCM) Искажение: Приход на ВУ ворот отстойной зоны
	{&iEM_TERA4SS11LIM,3,402},	//( - , SCM) Искажение: Приход на ВУ НИ1
	{&iEM_TERR1SS11LIM,3,403},	//( - , SCM) Искажение: Приход на ВУ МДЗ1
	{&iEM_TERR1SS21LIM,3,404},	//( - , SCM) Искажение: Приход на НУ МДЗ1
	{&iEM_TERR2SS11LIM,3,405},	//( - , SCM) Искажение: Приход на ВУ МДЗ2
	{&iEM_TERR2SS21LIM,3,406},	//( - , SCM) Искажение: Приход на НУ МДЗ2
	{&iEM_TERA4VP82LIM,3,407},	//( - , SCM) Искажение Давление ПОДЪЁМ НИ в норме
	{&iEM_TERB4SS21LIM,3,408},	//( - , SCM) Искажение: Приход на НУ НИ2
	{&iEM_TERR5SS21LIM,3,409},	//( - , SCM) Искажение: Приход на НУ ворот отстойной зоны
	{&iEM_TERB6SS21LIM,3,410},	//( - , SCM) Искажение: Приход на НУ БЗ2
	{&iEM_TERB4SS11LIM,3,411},	//( - , SCM) Искажение: Приход на ВУ НИ2
	{&iEM_TERA4SS21LIM,3,412},	//( - , SCM) Искажение: Приход на НУ НИ1
	{&iEM_TERA6MS11LIM,3,413},	//( - , SCM) Искажение: Приход на ВУ БЗ1
	{&iEM_TERA6SS21LIM,3,414},	//( - , SCM) Искажение: Приход на НУ БЗ1
	{&iEM_TERB6SS11LIM,3,415},	//( - , SCM) Искажение: Приход на ВУ БЗ2
	{&iEM_TERR4SS11LIM,3,416},	//( - , SCM) Искажение: Приход на ВУ тележки
	{&iEM_TERR4MS21LIM,3,417},	//( - , SCM) Искажение: Приход на НУ тележки
	{&iEM_TERR4SS12LIM,3,418},	//( - , SCM) Искажение: Приход на механический ВУ тележки
	{&iEM_TERR4SS22LIM,3,419},	//( - , SCM) Искажение: Приход на механический НУ тележки
	{&iEM_TERR8SS11LIM,3,420},	//( - , SCM) Искажение: Аварийный НИ установлен
	{&iEM_TERB8SC01RIM,3,421},	//( - , SCM) Искажение: Координата АЗ2
	{&iEM_TERA8SC01RIM,3,422},	//( - , SCM) Искажение: Координата ДС2
	{&iEM_TERB8SS12LIM,3,423},	//( - , SCM) Искажение: Приход на механический ВУ АЗ2
	{&iEM_TERA8SS12LIM,3,424},	//( - , SCM) Искажение: Приход на механический ВУ ДС2
	{&iEM_TERB8SS22LIM,3,425},	//( - , SCM) Искажение: Приход на механический НУ АЗ2
	{&iEM_TERA8SS22LIM,3,426},	//( - , SCM) Искажение: Приход на механический НУ ДС2
	{&iEM_TERA9SS21LIM,3,427},	//( - , SCM) Искажение: Приход на НУ НИ ДС1
	{&iEM_TERB9SS21LIM,3,428},	//( - , SCM) Искажение: Приход на НУ НИ ДС2
	{&iEM_TERB9SS11LIM,3,429},	//( - , SCM) Искажение: Приход на ВУ НИ ДС2
	{&iEM_TERB5SS21LIM,3,430},	//( - , SCM) Искажение: Приход на НУ НЛ2
	{&iEM_TERA1SS21LIM,3,431},	//( - , SCM) Искажение: Приход на НУ ББ1
	{&iEM_TERA1SS11LIM,3,432},	//( - , SCM) Искажение: Приход на ВУ ББ1
	{&iEM_TERA1SC01RIM,3,433},	//( - , SCM) Искажение: Координата штока ББ1
	{&iEM_TERA1SS12LIM,3,434},	//( - , SCM) Искажение: Магнит ББ1 зацеплен
	{&iEM_TERB1SS21LIM,3,435},	//( - , SCM) Искажение: Приход на НУ ББ2
	{&iEM_TERB1SS11LIM,3,436},	//( - , SCM) Искажение:Приход на ВУ ББ2
	{&iEM_TERB1MC01RIM,3,437},	//( - , SCM) Искажение: Координата штока ББ2
	{&iEM_TERB1SS12LIM,3,438},	//( - , SCM) Искажение: Магнит ББ2 зацеплен
	{&iEM_TERTLG,3,439},	//( - , SCM) Неисправности  тележки от ИС
	{&fEM_R4MC01RC1,8,440},	//( - , SCM) Заданная координата тележки от ИС
	{&fEM_R4MV01RC1,8,442},	//( - , SCM) Заданная скорость тележки от ИС
	{&iEM_TERMAZ2,3,444},	//( - , SCM) Неисправности АЗ2 от ИС
	{&fEM_B8MC01RC1,8,445},	//( - , SCM) аданная координата АЗ2 от ИС
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
	{&fEM_A1MV01RSP,8,505},	//( - , SCM) Стартовая скорость движения  ББ1
	{&fEM_A1MV02RSP,8,507},	//( - , SCM) Стартовая скорость движения  ББ1
	{&fEM_B1MC01RSP,8,509},	//( - , SCM) Стартовая координата  ББ2
	{&fEM_B1MV01RSP,8,511},	//( - , SCM) Стартовая скорость движения  ББ2
	{&fEM_B1MC02RSP,8,513},	//( - , SCM) Стартовая координата штока ББ2
	{&fEM_B1MV02RSP,8,515},	//( - , SCM) Стартовая скорость движения  ББ2
	{&fEM_A2MC01RC1,8,517},	//( - , SCM) Заданная координата РБ1 от ИС
	{&fEM_A2MV01RC1,8,519},	//( - , SCM) Заданная скорость движения РБ1 от ИС
	{&fEM_A2MC01RSP,8,521},	//( - , SCM) Стартовая координата  РБ1
	{&fEM_A2MV01RSP,8,523},	//( - , SCM) Стартовая скорость движения  РБ1
	{&fEM_A2MC02RSP,8,525},	//( - , SCM) Стартовая координата штока РБ1
	{&fEM_A2MV02RSP,8,527},	//( - , SCM) Стартовая скорость движения  РБ1
	{&fEM_B2MC01RSP,8,529},	//( - , SCM) Стартовая координата  РБ2
	{&fEM_B2MV01RSP,8,531},	//( - , SCM) Стартовая скорость движения  РБ2
	{&fEM_B2MC02RSP,8,533},	//( - , SCM) Стартовая координата штока РБ2
	{&fEM_B2MV02RSP,8,535},	//( - , SCM) Стартовая скорость движения  РБ2
	{&fEM_A3MC01RSP,8,537},	//( - , SCM) Стартовая координата  ИС1
	{&fEM_A3MV01RSP,8,539},	//( - , SCM) Стартовая скорость движения  ИС1
	{&fEM_A3MC02RSP,8,541},	//( - , SCM) Стартовая координата штока ИС1
	{&fEM_A3MV02RSP,8,543},	//( - , SCM) Стартовая скорость движения  ИС1
	{&fEM_B3MC01RSP,8,545},	//( - , SCM) Стартовая координата  ИС2
	{&fEM_B3MV01RSP,8,547},	//( - , SCM) Стартовая скорость движения  ИС2
	{&fEM_B3MC02RSP,8,549},	//( - , SCM) Стартовая координата штока ИС2
	{&fEM_B3MV02RSP,8,551},	//( - , SCM) Стартовая скорость движения  ИС2
	{&fEM_B8MC01RSP,8,553},	//( - , SCM) Стартовая координата АЗ2
	{&fEM_B8MV01RSP,8,555},	//( - , SCM) Стартовая скорость АЗ2
	{&fEM_A8MC01RSP,8,557},	//( - , SCM) Стартовая координата ДС2
	{&fEM_A8MV01RSP,8,559},	//( - , SCM) Стартовая скорость ДС2
	{&fEM_A6MC01RSP,8,561},	//( - , SCM) Стартовая координата БЗ1
	{&fEM_A6MV01RSP,8,563},	//( - , SCM) Стартовая скорость БЗ1
	{&fEM_B6MC01RSP,8,565},	//( - , SCM) Стартовая координата БЗ2
	{&fEM_B6MV01RSP,8,567},	//( - , SCM) Стартовая скорость БЗ2
	{&fEM_R3UC01RSP,8,569},	//( - , SCM) Стартовая координата Гомогенных дверей
	{&fEM_R3UV01RSP,8,571},	//( - , SCM) Стартовая скорость Гомогенных дверей
	{&fEM_R5UC01RSP,8,573},	//( - , SCM) Стартовая координата Ворот отстойной зоны
	{&fEM_R5UV01RSP,8,575},	//( - , SCM) Стартовая скорость Ворот отстойной зоны
	{&fEM_R6UC01RSP,8,577},	//( - , SCM) Стартовая координата Кран-балки
	{&fEM_R6UV01RSP,8,579},	//( - , SCM) Стартовая скорость Кран-балки
	{&fEM_R2MC01RSP,8,581},	//( - , SCM) Стартовая координата МДЗ2
	{&fEM_R2MV01RSP,8,583},	//( - , SCM) Стартовая скорость МДЗ2
	{&fEM_R1MC01RSP,8,585},	//( - , SCM) Стартовая координата МДЗ1
	{&fEM_R1MV01RSP,8,587},	//( - , SCM) Стартовая скорость МДЗ1
	{&fEM_A5MC01RSP,8,589},	//( - , SCM) Стартовая координата НЛ1
	{&fEM_A5MV01RSP,8,591},	//( - , SCM) Стартовая скорость НЛ1
	{&fEM_B5MC01RSP,8,593},	//( - , SCM) Стартовая координата НЛ2
	{&fEM_B5MV01RSP,8,595},	//( - , SCM) Стартовая скорость НЛ2
	{&fEM_A9MC01RSP,8,597},	//( - , SCM) Стартовая координата НИ ДС1
	{&fEM_A9MV01RSP,8,599},	//( - , SCM) Стартовая скорость НИ ДС1
	{&fEM_B9MC01RSP,8,601},	//( - , SCM) Стартовая координата НИ ДС2
	{&fEM_B9MV01RSP,8,603},	//( - , SCM) Стартовая скорость НИ ДС2
	{&fEM_A4MC01RSP,8,605},	//( - , SCM) Стартовая координата НИ1
	{&fEM_A4MV01RSP,8,607},	//( - , SCM) Стартовая скорость НИ1
	{&fEM_B4MC01RSP,8,609},	//( - , SCM) Стартовая координата НИ2
	{&fEM_B4MV01RSP,8,611},	//( - , SCM) Стартовая скорость НИ2
	{&fEM_R4MC01RSP,8,613},	//( - , SCM) Стартовая координата тележки
	{&fEM_R4MV01RSP,8,615},	//( - , SCM) Стартовая скорость тележки
	{&fEM_A1MV01RC1,8,617},	//( - , SCM) Заданная скорость движения  ББ1 от ИС
	{&iEM_TERB7MS31LIM,3,619},	//( - , SCM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{&iEM_TERA7MS31LIM,3,620},	//( - , SCM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{&fEM_R7UY00RSS,8,621},	//( - , SCM) Y-координата АЗ1 см
	{&iEM_TERA6VS12LIM,3,623},	//( - , SCM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{&iEM_TERA6VS22LIM,3,624},	//( - , SCM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{&iEM_TERB6VS12LIM,3,625},	//( - , SCM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{&iEM_TERB6VS22LIM,3,626},	//( - , SCM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{&iEM_TERA5VS22LIM,3,627},	//( - , SCM) Искажение: Движение створок НЛ1 к НУ
	{&iEM_TERA5VS12LIM,3,628},	//( - , SCM) Искажение: Движение створок НЛ1 к ВУ
	{&iEM_TERB5VS12LIM,3,629},	//( - , SCM) Искажение: Движение створок НЛ2 к ВУ
	{&iEM_TERB5VS22LIM,3,630},	//( - , SCM) Искажение: Движение створок НЛ2 к НУ
	{&iEM_TERR1VS12LIM,3,631},	//( - , SCM) Искажение: Движение МДЗ1 в сторону ВУ
	{&iEM_TERR1VS22LIM,3,632},	//( - , SCM) Искажение: Движение МДЗ1 в сторону НУ
	{&iEM_TERR2VS12LIM,3,633},	//( - , SCM) Искажение: Движение МДЗ2 в сторону ВУ
	{&iEM_TERR2VS22LIM,3,634},	//( - , SCM) Искажение: Движение МДЗ2 в сторону НУ
	{&iEM_TERR4VS12LDU,3,635},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&iEM_TERR4VS22LDU,3,636},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
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
	{&B8IC01UDU,5,8},	//( - , SDu) Координата АЗ2
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA1[]={  // 
	{&R0IN01FI1,8,0},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{&R0IN02FI1,8,2},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI1,8,4},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{&R0IS01FI0,3,6},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA2[]={  // 
	{&R0IN01FI2,8,0},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{&R0IN02FI2,8,2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI2,8,4},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{&R0IS01FI0,3,6},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA3[]={  // 
	{&R0IN01FI3,8,0},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI3,8,2},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI3,8,4},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{&R0IS01FI0,3,6},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
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
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SA4[]={  // 
	{&R0IN01FI4,8,0},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{&R0IN02FI4,8,2},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{&R0IN03FI4,8,4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{&R0IS01FI0,3,6},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
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
	{&R0IS01FI0,3,10},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
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
#include "drivers/ao16.h"
static char buf_AO1601[127];	//AO16
static ao16_inimod ini_AO1601={0xffff,120,0x43,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#pragma pack(push,1)
static table_drv table_AO1601={0,0,&ini_AO1601,buf_AO1601,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_AO1601[]={
	{&B0IT02IZ2,3,18},
	{&B0IT01IZ1,3,6},
	{&A0IT02IZ2,3,12},
	{&A3IP02IDU,3,24},
	{&B2IP01IZ1,3,9},
	{&B2IP01IZ2,3,21},
	{&B3IP02IDU,3,27},
	{&A2IP01IZ2,3,15},
	{&A2IP01IZ1,3,3},
	{&A0IT01IZ1,3,0},
	{&A0IT03IRP,3,30},
	{&B0IT03IRP,3,33},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F01[137];	//do32_5f(0x100)
static do32_pti_inipar ini_DO32_5F01={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F01={0,0,&ini_DO32_5F01,buf_DO32_5F01,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F01[]={
	{&R7II71LZ1,1,46},
	{&R7II72LZ1,1,48},
	{&A3IS22LDU,1,10},
	{&R7II73LZ1,1,50},
	{&A1VP81LZZ,1,54},
	{&A3IS11LDU,1,8},
	{&A0VP81LZZ,1,52},
	{&R6IS66LZZ,1,32},
	{&R6IS67LZZ,1,34},
	{&R6IS68LZZ,1,36},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F02[137];	//do32_5f(0x110)
static do32_pti_inipar ini_DO32_5F02={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F02={0,0,&ini_DO32_5F02,buf_DO32_5F02,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F02[]={
	{&B3IS22LDU,1,22},
	{&B3IS11LDU,1,20},
	{&R7II72LZ2,1,48},
	{&R7II71LZ2,1,46},
	{&R7II73LZ2,1,50},
	{&B0VP81LZZ,1,58},
	{&B1VP81LZZ,1,60},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F08[137];	//do32_5f(0x130)
static do32_pti_inipar ini_DO32_5F08={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F08={0,0,&ini_DO32_5F08,buf_DO32_5F08,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F08[]={
	{&B2IS12LDU,1,18},
	{&B2IS11LDU,1,20},
	{&A4IS11LDU,1,30},
	{&A4IS21LDU,1,32},
	{&R8IS11LDU,1,26},
	{&B1IS12LDU,1,12},
	{&B3IS21LDU,1,24},
	{&R1IS11LDU,1,42},
	{&R1IS21LDU,1,44},
	{&B2IS21LDU,1,22},
	{&B1IS11LDU,1,14},
	{&B1IS21LDU,1,16},
	{&R2IS21LDU,1,48},
	{&R2IS11LDU,1,46},
	{&A7AS31LDU,1,60},
	{&A1IS12LDU,1,62},
	{&A9IS11LDU,1,34},
	{&A9IS21LDU,1,36},
	{&B9IS11LDU,1,38},
	{&B9IS21LDU,1,40},
	{&B7AS31LDU,1,10},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F09[137];	//do32_5f(0x140)
static do32_pti_inipar ini_DO32_5F09={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F09={0,0,&ini_DO32_5F09,buf_DO32_5F09,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F09[]={
	{&A2IS12LDU,1,4},
	{&A2IS11LDU,1,6},
	{&A3IS21LDU,1,10},
	{&A2IS21LDU,1,8},
	{&R0IS02LDU,1,32},
	{&B4IS11LDU,1,12},
	{&B4IS21LDU,1,14},
	{&A5IS11LDU,1,54},
	{&A5IS21LDU,1,56},
	{&B5IS11LDU,1,62},
	{&A1IS11LDU,1,0},
	{&R4IS11LDU,1,42},
	{&R4IS21LDU,1,46},
	{&R4IS22LDU,1,48},
	{&R4IS12LDU,1,44},
	{&A6IS21LDU,1,52},
	{&B6IS11LDU,1,58},
	{&B6IS21LDU,1,60},
	{&A1IS21LDU,1,2},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F05[137];	//do32_5f(0x150)
static do32_pti_inipar ini_DO32_5F05={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F05={0,0,&ini_DO32_5F05,buf_DO32_5F05,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F05[]={
	{&B8IS22LDU,1,12},
	{&B8IS12LDU,1,10},
	{&A8IS22LDU,1,30},
	{&A8IS12LDU,1,28},
	{&A6IS11LDU,1,34},
	{&R3IS21LDU,1,4},
	{&R5IS11LDU,1,18},
	{&R5IS21LDU,1,20},
	{&B8IS11LDU,1,14},
	{&B8IS21LDU,1,8},
	{&R6IS21LDU,1,26},
	{&R3IS11LDU,1,2},
	{&B5IS21LDU,1,0},
	{NULL,0,0},
};
#pragma pop
#include "drivers/do32_pti.h"
static char buf_DO32_5F06[137];	//do32_5f(0x160)
static do32_pti_inipar ini_DO32_5F06={0,};
#pragma pack(push,1)
static table_drv table_DO32_5F06={0,0,&ini_DO32_5F06,buf_DO32_5F06,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_DO32_5F06[]={
	{&R6IS64LDU,1,60},
	{&R6IS65LDU,1,62},
	{&R6IS63LDU,1,58},
	{&R6IS62LDU,1,56},
	{NULL,0,0},
};
#pragma pop
#include "drivers/emul8enc.h"
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
#include "drivers/vds32_pti.h"
static char buf_VDS32F07[66];	//vds32f2(0x340)
static vds32pti_inimod ini_VDS32F07={0,};
#pragma pack(push,1)
static table_drv table_VDS32F07={0,0,&ini_VDS32F07,buf_VDS32F07,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F07[]={
	{&A2AD33LDU,1,26},
	{&B7AP31LDU,1,60},
	{&A3AD34LDU,1,22},
	{&A7AP31LDU,1,32},
	{&A3AD31LDU,1,30},
	{&A8AD10LDU,1,62},
	{&B3AD34LDU,1,50},
	{&R1AD10LDU,1,34},
	{&R1AD20LDU,1,36},
	{&R2AD10LDU,1,38},
	{&R2AD20LDU,1,40},
	{&A5AD10LDU,1,42},
	{&A5AD20LDU,1,44},
	{&B5AD10LDU,1,46},
	{&B5AD20LDU,1,48},
	{&A3AD33LDU,1,24},
	{&A4AD10LDU,1,28},
	{&B4AD10LDU,1,56},
	{&B3AD33LDU,1,52},
	{&B2AD33LDU,1,54},
	{&B3AD31LDU,1,58},
	{NULL,0,0},
};
#pragma pop
#include "drivers/vds32_pti.h"
static char buf_VDS32F10[66];	//vds32f2(0x360)
static vds32pti_inimod ini_VDS32F10={0,};
#pragma pack(push,1)
static table_drv table_VDS32F10={0,0,&ini_VDS32F10,buf_VDS32F10,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F10[]={
	{&A9AD10LDU,1,46},
	{&B9AD10LDU,1,48},
	{&A6AD10LDU,1,2},
	{&A6AD20LDU,1,4},
	{&B6AD10LDU,1,6},
	{&B6AD20LDU,1,8},
	{&A3AD03LDU,1,26},
	{&A3AD04LDU,1,28},
	{&A3AD05LDU,1,30},
	{&A8AD20LDU,1,0},
	{&A1AD04LDU,1,60},
	{&A1AD03LDU,1,58},
	{&A1AD02LDU,1,56},
	{&A1AD01LDU,1,54},
	{&A1AD21LDU,1,52},
	{&A1AD11LDU,1,50},
	{&A3AD02LDU,1,24},
	{&A3AD01LDU,1,22},
	{&A3AD21LDU,1,20},
	{&A3AD11LDU,1,18},
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
	{NULL,0,0},
};
#pragma pop
#include "drivers/vds32_pti.h"
static char buf_VDS32F11[66];	//vds32f2(0x310)
static vds32pti_inimod ini_VDS32F11={0,};
#pragma pack(push,1)
static table_drv table_VDS32F11={0,0,&ini_VDS32F11,buf_VDS32F11,0,0};
#pragma pop
#pragma pack(push,1)
static DriverRegister def_buf_VDS32F11[]={
	{&A2AD21LDU,1,18},
	{&A2AD11LDU,1,16},
	{&A2AD32LDU,1,48},
	{&R8AD21LDU,1,60},
	{&R0AD16LDU,1,62},
	{&B2AD32LDU,1,56},
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
	{&A1AD05LDU,1,0},
	{&B1AD11LDU,1,2},
	{&B1AD21LDU,1,4},
	{&B1AD01LDU,1,6},
	{&B2AD31LDU,1,58},
	{&B1AD32LDU,1,52},
	{&B1AD31LDU,1,54},
	{&B1AD02LDU,1,8},
	{&B1AD03LDU,1,10},
	{&B1AD04LDU,1,12},
	{&A1AD31LDU,1,46},
	{&A1AD32LDU,1,44},
	{&A2AD31LDU,1,50},
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
	setAsFloat(277,0.015);
	setAsFloat(278,0.0069);
	setAsFloat(279,0.21);
	setAsFloat(280,0);
	setAsFloat(281,0);
	setAsFloat(282,0.0096);
	setAsFloat(283,0.0026);
	setAsFloat(284,106);
	setAsFloat(285,135.227);
	setAsFloat(286,25);
	setAsFloat(287,320.435466);
	setAsFloat(288,0.0055);
	setAsFloat(289,0.000877);
	setAsFloat(290,200);
	setAsFloat(291,100);
	setAsFloat(292,0);
	setAsFloat(293,0);
	setAsFloat(294,100);
	setAsFloat(295,80);
	setAsFloat(296,0.002375);
	setAsFloat(297,0);
	setAsFloat(298,165);
	setAsFloat(299,200);
	setAsFloat(300,0.001675);
	setAsFloat(301,40);
	setAsFloat(302,15630.0);
	setAsFloat(303,1374);
	setAsFloat(304,0);
	setAsFloat(305,390.0);
	setAsFloat(306,2000.0);
	setAsFloat(307,1500.0);
	setAsFloat(308,10.91);
	setAsFloat(309,10.91);
	setAsFloat(310,1500.0);
	setAsFloat(311,2000);
	setAsFloat(312,390.0);
	setAsFloat(313,0);
	setAsFloat(314,55.0);
	setAsFloat(315,15.0);
	setAsFloat(316,5.0);
	setAsFloat(317,1E12);
	setAsFloat(318,43.6);
	setAsFloat(319,20.0);
	setAsFloat(320,20.0);
	setAsFloat(321,20.0);
	setAsFloat(322,1269.0);
	setAsFloat(323,256.0);
	setAsFloat(324,1.0);
	setAsFloat(325,2.0);
	setAsFloat(326,0);
	setAsFloat(327,0.026);
	setAsFloat(328,0.08);
	setAsFloat(329,0.0);
	setAsFloat(330,27.108);
	setAsFloat(331,600);
	setAsFloat(332,0);
	setAsFloat(333,0.00009765625);
	setAsFloat(334,1.6);
	setAsFloat(335,0);
	setAsFloat(336,0.00009765625);
	setAsFloat(337,1.6);
	setAsFloat(338,0);
	setAsFloat(339,0.00009765625);
	setAsFloat(340,10000.0);
	setAsFloat(341,0.0009765625);
	setAsFloat(342,750);
	setAsFloat(343,100);
	setAsFloat(344,200);
	setAsFloat(345,300);
	setAsFloat(346,400);
	setAsFloat(347,500);
	setAsFloat(348,600);
	setAsFloat(349,0.50);
	setAsFloat(350,0.50);
	setAsFloat(351,0.50);
	setAsFloat(352,2);
	setAsFloat(353,11.0);
	setAsFloat(354,1585.0);
	setAsFloat(355,1796.0);
	setAsFloat(356,1555.0);
	setAsFloat(357,1269.0);
	setAsFloat(358,1269.0);
	setAsFloat(359,1585.0);
	setAsFloat(360,1796.0);
	setAsFloat(361,1269.0);
	setAsFloat(362,248.0);
	setAsFloat(363,284.5);
	setAsFloat(364,248.0);
	setAsFloat(365,271.6);
	setAsFloat(366,287.2);
	setAsFloat(367,594.0);
	setAsFloat(368,559.0);
	setAsFloat(369,588.0);
	setAsFloat(370,1555.0);
	setAsFloat(371,1281.2);
	setAsFloat(372,1269.0);
	setAsFloat(373,594.0);
	setAsFloat(374,597.2);
	setAsFloat(375,556.8);
	setAsFloat(376,1.0);
	setAsFloat(377,1.0);
	setAsFloat(378,1.0);
	setAsFloat(379,1.0);
	setAsFloat(380,1.0);
	setAsFloat(381,1.0);
	setAsFloat(382,1.0);
	setAsFloat(383,1.0);
	setAsFloat(384,1.0);
	setAsFloat(385,1.0);
	setAsFloat(386,1.0);
	setAsFloat(387,1.0);
	setAsFloat(388,0);
	setAsFloat(389,0);
	setAsFloat(390,0);
	setAsFloat(391,0);
	setAsFloat(392,0.0);
	setAsFloat(393,0);
	setAsFloat(394,0.0);
	setAsFloat(395,0);
	setAsFloat(396,0.0);
	setAsFloat(397,0.0);
	setAsFloat(398,0.0);
	setAsFloat(399,0.0);
	setAsFloat(400,3703.704);
	setAsFloat(401,62500.0);
	setAsFloat(402,20);
	setAsFloat(403,18000);
	setAsFloat(404,18000);
	setAsFloat(405,18000);
	setAsFloat(406,0.76);
	setAsFloat(407,0.245);
	setAsFloat(408,2.9);
	setAsFloat(409,0.13);
	setAsFloat(410,0.73);
	setAsFloat(411,0.41);
	setAsFloat(412,9807.0);
	setAsFloat(413,22975.0);
	setAsFloat(414,12750.0);
	setAsFloat(415,20);
	setAsFloat(416,20);
	setAsFloat(417,0);
	setAsFloat(418,5.0);
	setAsFloat(419,5.0);
	setAsFloat(420,5.0);
	setAsFloat(421,100.0);
	setAsFloat(422,4000);
	setAsFloat(423,100000);
	setAsFloat(424,1000000);
	setAsFloat(425,32000.0);
	setAsFloat(426,5.0);
	setAsFloat(427,15.0);
	setAsFloat(428,15.0);
	setAsFloat(429,20.0);
	setAsFloat(430,10.0);
	setAsBool(431,0);
	setAsBool(432,0);
	setAsBool(433,0);
	setAsFloat(434,0.45);
	setAsFloat(435,0.39);
	setAsFloat(436,2.74);
	setAsFloat(437,0.07);
	setAsFloat(438,0.275);
	setAsFloat(439,0.245);
	setAsFloat(440,0.045);
	setAsFloat(441,0.05);
	setAsShort(442,0);
	setAsFloat(443,0);
	setAsFloat(444,0);
	setAsShort(445,0);
	setAsFloat(446,0);
	setAsFloat(447,0);
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
	setAsShort(461,0);
	setAsFloat(462,0);
	setAsShort(463,0);
	setAsShort(464,0);
	setAsFloat(465,0);
	setAsFloat(466,0);
	setAsFloat(467,0);
	setAsFloat(468,0);
	setAsFloat(469,0);
	setAsFloat(470,0);
	setAsFloat(471,0);
	setAsFloat(472,0);
	setAsShort(473,0);
	setAsShort(474,0);
	setAsShort(475,0);
	setAsShort(476,0);
	setAsShort(477,0);
	setAsShort(478,0);
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
	setAsFloat(557,0);
	setAsFloat(558,0);
	setAsShort(559,0);
	setAsFloat(560,0);
	setAsFloat(561,0);
	setAsShort(562,0);
	setAsFloat(563,0);
	setAsFloat(564,0);
	setAsShort(565,0);
	setAsFloat(566,0);
	setAsFloat(567,0);
	setAsShort(568,0);
	setAsFloat(569,0);
	setAsFloat(570,0);
	setAsBool(571,0);
	setAsBool(572,1);
	setAsBool(573,0);
	setAsBool(574,1);
	setAsBool(575,0);
	setAsShort(576,0);
	setAsFloat(577,0);
	setAsFloat(578,0);
	setAsShort(579,0);
	setAsFloat(580,0);
	setAsFloat(581,0);
	setAsShort(582,0);
	setAsFloat(583,0);
	setAsFloat(584,0);
	setAsShort(585,0);
	setAsFloat(586,0);
	setAsFloat(587,0);
	setAsBool(588,1);
	setAsFloat(589,0.01);
	setAsFloat(590,0.01);
	setAsFloat(591,0.01);
	setAsShort(592,0);
	setAsShort(593,0);
	setAsShort(594,0);
	setAsFloat(595,25.017338);
	setAsFloat(596,-0.15912805);
	setAsFloat(597,0.000000166);
	setAsFloat(598,25.017338);
	setAsFloat(599,0);
	setAsFloat(600,0.000167646);
	setAsFloat(601,0);
	setAsFloat(602,0);
	setAsFloat(603,0);
	setAsFloat(604,0);
	setAsFloat(605,0.000167646);
	setAsFloat(606,0);
	setAsFloat(607,0);
	setAsFloat(608,0);
	setAsFloat(609,0);
	setAsFloat(610,0);
	setAsFloat(611,0);
	setAsFloat(612,0);
	setAsFloat(613,0);
	setAsFloat(614,0);
	setAsFloat(615,0);
	setAsFloat(616,0);
	setAsFloat(617,0.000885839);
	setAsFloat(618,0);
	setAsFloat(619,0.000885839);
	setAsFloat(620,0);
	setAsFloat(621,0.000885839);
	setAsFloat(622,0);
	setAsFloat(623,0.000885839);
	setAsFloat(624,0);
	setAsFloat(625,390);
	setAsFloat(626,0);
	setAsFloat(627,390);
	setAsFloat(628,0);
	setAsFloat(629,55);
	setAsFloat(630,0);
	setAsFloat(631,55);
	setAsFloat(632,0);
	setAsFloat(633,0);
	setAsFloat(634,0);
	setAsFloat(635,4000.0);
	setAsFloat(636,0);
	setAsFloat(637,10);
	setAsFloat(638,0);
	setAsFloat(639,0);
	setAsFloat(640,0);
	setAsFloat(641,0);
	setAsFloat(642,0);
	setAsFloat(643,5);
	setAsFloat(644,0);
	setAsFloat(645,5);
	setAsFloat(646,0);
	setAsFloat(647,0);
	setAsFloat(648,0);
	setAsFloat(649,0);
	setAsFloat(650,0);
	setAsFloat(651,0);
	setAsFloat(652,0);
	setAsFloat(653,0);
	setAsFloat(654,0);
	setAsFloat(655,15650);
	setAsFloat(656,0);
	setAsFloat(657,0);
	setAsShort(658,0);
	setAsShort(659,0);
	setAsFloat(660,506.6);
	setAsShort(661,0);
	setAsShort(662,0);
	setAsShort(663,0);
	setAsShort(664,0);
	setAsShort(665,0);
	setAsShort(666,0);
	setAsShort(667,0);
	setAsShort(668,0);
	setAsShort(669,0);
	setAsShort(670,0);
	setAsShort(671,0);
	setAsShort(672,0);
	setAsShort(673,0);
	setAsShort(674,0);
	setAsFloat(675,5065.0);
	setAsFloat(676,1.0);
	setAsFloat(677,1.0);
	setAsFloat(678,1.0);
	setAsFloat(679,1570.0);
	setAsFloat(680,1269);
	setAsFloat(681,1281.2);
	setAsFloat(682,248.0);
	setAsFloat(683,572.4);
	setAsFloat(684,246.8);
	setAsFloat(685,1);
}
uspaint8 InternalBuf[814];

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
ssint iRM_500_ = {500,0}; /* tz - ширина импульса, 10-ки мс */ 
ssfloat fRM_3_ = {3,0}; /* m1 - величина отклонения второго сигнала от входного */ 
ssfloat fRM_2_0 = {2.0,0}; /* ampl - амплетуда синусоидального отклонения */ 
ssint iRM_719_ = {719,0}; /* min - минимальное возможное значение выходного сигнала */ 
ssint iRM_4195_ = {4195,0}; /* max - максимальное возможное значение выходного сигнала */ 
ssfloat fRM_3276_ = {3276,0}; /* c   - мин. значение кода ФАС */ 
ssfloat fRM_16383_ = {16383,0}; /* d - макс.  значение кода ФАС */ 
ssfloat fRM_200_ = {200,0}; /* maxs1 - макc. значение второго сигнала */ 
ssfloat fRM_0_0015 = {0.0015,0}; /* m1 - величина отклонения второго сигнала от входного */ 
ssfloat fRM_0_001 = {0.001,0}; /* ampl - амплетуда синусоидального отклонения */ 
ssfloat fRM_0_1 = {0.1,0}; /* k - коэффициент усиления */ 
ssint iRM_16_ = {16,0}; /* n - N-размерность массива входных параметров */ 
ssfloat fRM_2000_ = {2000,0}; /* maxs1 - макc. значение второго сигнала */ 
ssfloat fRM_15_ = {15,0}; /* m1 - величина отклонения второго сигнала от входного */ 

uspaint8 SpaEEPROMBuf[1776];

/* Определение переменных */
ssfloat var1;
ssfloat var2;
ssfloat var3;
ssfloat var4;
ssfloat var5;
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
ssbool var45;
ssbool var46;
ssbool var47;
ssbool var48;
ssbool var49;
ssbool var50;
sslong var51;
ssfloat var52;
sslong var53;
ssfloat var54;
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
ssint var89;
ssint var90;
ssfloat var91;
ssfloat var92;
sslong var93;
ssfloat var94;
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
ssfloat var106;
ssbool var107;
ssbool var108;
sslong var109;
ssfloat var110;
sslong var111;
ssfloat var112;
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
ssint var124;
ssfloat var125;
ssbool var126;
ssbool var127;
ssint var128;
ssfloat var129;
ssbool var130;
sslong var131;
ssfloat var132;
ssbool var133;
ssbool var134;
sslong var135;
ssfloat var136;
ssbool var137;
ssint var138;
ssint var139;
ssbool var140;
ssbool var141;
ssbool var142;
sslong var143;
ssfloat var144;
ssbool var145;
ssbool var146;
ssbool var147;
ssfloat var148;
ssfloat var149;
ssfloat var150;
ssint var151;
ssint var152;
ssint var153;
ssfloat var154;
ssfloat var155;
ssfloat var156;
ssint var157;
ssint var158;
ssbool var159;
ssbool var160;
ssint var161;
ssfloat var162;
ssfloat var163;
ssfloat var164;
ssbool var165;
ssbool var166;
ssbool var167;
ssbool var168;
ssfloat var169;
ssbool var170;
ssfloat var171;
ssbool var172;
ssbool var173;
ssbool var174;
ssbool var175;
ssbool var176;
ssbool var177;
ssbool var178;
ssfloat var179;
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
ssfloat var218;
ssfloat var219;
ssfloat var220;
ssfloat var221;
ssfloat var222;
ssfloat var223;
ssfloat var224;
ssfloat var225;
ssfloat var226;
ssbool var227;
ssbool var228;
ssbool var229;
ssfloat var230;
ssfloat var231;
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
ssfloat var267;
ssbool var268;
ssbool var269;
ssfloat var270;
ssbool var271;
ssbool var272;
ssbool var273;
ssbool var274;
ssbool var275;
ssbool var276;
ssbool var277;
ssbool var278;
ssfloat var279;
ssfloat var280;
ssfloat var281;
ssfloat var282;
ssbool var283;
ssfloat var284;
ssfloat var285;
ssfloat var286;
ssfloat var287;
ssbool var288;
ssbool var289;
ssbool var290;
ssbool var291;
ssbool var292;
ssfloat var293;
ssfloat var294;
ssbool var295;
ssbool var296;
ssbool var297;
ssbool var298;
ssbool var299;
ssfloat var300;
ssfloat var301;
ssbool var302;
ssbool var303;
ssbool var304;
ssbool var305;
ssbool var306;
ssbool var307;
ssfloat var308;
ssfloat var309;
ssbool var310;
ssbool var311;
ssbool var312;
ssbool var313;
ssbool var314;
ssbool var315;
ssfloat var316;
ssfloat var317;
ssbool var318;
ssbool var319;
ssbool var320;
ssbool var321;
ssbool var322;
ssfloat var323;
ssfloat var324;
ssbool var325;
ssbool var326;
ssbool var327;
ssbool var328;
ssbool var329;
ssfloat var330;
ssfloat var331;
ssfloat var332;
ssfloat var333;
ssbool var334;
ssfloat var335;
sslong vainSLong;
ssfloat vainSFloat;
ssint vainSInt;
ssbool vainSBool;
sschar vainSChar;
char vainSText[] = "";

/* Объявление массивов */
psbool  array_m357_x_1[16] = {&lEM_R8AD10LC1,&lEM_R8AD10LC1,&var329,&var187,&var181,&var271,&var269,&var263,&var260,&var276,&var319,&var314,&var305,&var295,&var289,&R0MW13LP2};
psbool  array_m920_x_1[2] = {&lEM_R0IE02LRP,&lEM_R0IE01LRP};
psbool  array_m915_x_1[2] = {&var167,&R0MW13LP2};
psbool  array_m940_x_1[2] = {&var174,&R0MW13LP2};
psbool  array_m933_x_1[2] = {&var175,&R0MW13LP2};
psbool  array_m925_x_1[2] = {&var176,&R0MW13LP2};
psbool  array_m634_x_1[2] = {&var32,&var228};
psbool  array_m631_x_1[2] = {&var32,&var229};
psbool  array_m640_x_1[3] = {&lEM_C1AD31LRP,&R0VZ71LZ1,&R0VZ71LZ2};
psbool  array_m917_x_1[2] = {&var199,&R0MW13LP2};
psbool  array_m292_x_1[2] = {&var216,&B3AD31LDU};
psbool  array_m257_x_1[3] = {&B2AD31LDU,&var202,&var216};
psbool  array_m258_x_1[3] = {&B2AD32LDU,&var202,&var216};
psbool  array_m218_x_1[4] = {&B1AD32LDU,&var205,&var204,&var216};
psbool  array_m217_x_1[4] = {&var205,&B1AD31LDU,&var204,&var216};
psbool  array_m121_x_1[2] = {&A3AD31LDU,&var216};
psbool  array_m48_x_1[4] = {&A1AD32LDU,&var210,&var209,&var216};
psbool  array_m47_x_1[4] = {&var210,&A1AD31LDU,&var209,&var216};
psbool  array_m87_x_1[3] = {&A2AD31LDU,&var214,&var216};
psbool  array_m88_x_1[3] = {&A2AD32LDU,&var214,&var216};
psbool  array_m647_x_1[2] = {&var227,&var31};
psfloat  array_m7_a_1[5] = {&fRM_390_,&fRM_600_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m7_b_1[5] = {&fRM_0_5,&fRM_0_2,&fRM_0_088884,&fRM_0_066666667,&fRM_0_02173913};
psfloat  array_m9_a_1[7] = {&fRM_390_,&fRM_420_,&fRM_513_,&fRM_767_,&fRM_900_,&fRM_1200_,&fRM_1500_};
psfloat  array_m9_b_1[7] = {&fRM_3_546,&fRM_2_7,&fRM_2_,&fRM_0_88884,&fRM_0_6221739,&fRM_0_35555072,&fRM_0_2666666667};
psfloat  array_m182_C0_1[6];
psfloat  array_m300_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m133_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m266_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m96_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m229_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m60_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m14_C0_1[6];

/* Объявление структур */
_S_to3val  S_to3val_969_1 = {&fEM_R7UX16RSS,&fRM_900_,&fRM_15_,&fRM_0_0015,&fRM_0_,&fRM_2000_,&fRM_2000_,&TerR0IN06FRP,&var1,&var2,&vainSFloat,&bFirstEnterFlag};
_S_vchs  S_vchs_894_1 = {&var280,&var331,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_5_,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var3,&internal1_m894_Chim0};
_S_vchs  S_vchs_884_1 = {&var331,&var280,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&bRM_4_,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var4,&internal1_m884_Chim0};
_S_vchs  S_vchs_876_1 = {&var331,&var280,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&bRM_2_,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var5,&internal1_m876_Chim0};
_S_twobool  S_twobool_831_1 = {&var278,&iEM_TERR4VS22LDU,&var6,&vainSBool,&internal1_m831_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_830_1 = {&var277,&iEM_TERR4VS12LDU,&var7,&vainSBool,&internal1_m830_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1014_1 = {&var254,&iEM_TERR2VS22LIM,&var8,&vainSBool,&internal1_m1014_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1013_1 = {&var253,&iEM_TERR2VS12LIM,&var9,&vainSBool,&internal1_m1013_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1012_1 = {&var258,&iEM_TERR1VS22LIM,&var10,&vainSBool,&internal1_m1012_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1011_1 = {&var257,&iEM_TERR1VS12LIM,&var11,&vainSBool,&internal1_m1011_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_693_1 = {&var246,&iEM_TERB5VS22LIM,&var12,&vainSBool,&internal1_m693_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_692_1 = {&var245,&iEM_TERB5VS12LIM,&var13,&vainSBool,&internal1_m692_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_671_1 = {&var250,&iEM_TERA5VS22LIM,&var14,&vainSBool,&internal1_m671_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_670_1 = {&var249,&iEM_TERA5VS12LIM,&var15,&vainSBool,&internal1_m670_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_691_1 = {&var262,&iEM_TERB6VS22LIM,&var16,&vainSBool,&internal1_m691_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_690_1 = {&var261,&iEM_TERB6VS12LIM,&var17,&vainSBool,&internal1_m690_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_669_1 = {&var266,&iEM_TERA6VS22LIM,&var18,&vainSBool,&internal1_m669_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_668_1 = {&var265,&iEM_TERA6VS12LIM,&var19,&vainSBool,&internal1_m668_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_529_1 = {&var37,&iEM_TERA1VP81LIM,&var20,&vainSBool,&internal1_m529_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_545_1 = {&var37,&iEM_TERB1VP81LIM,&var21,&vainSBool,&internal1_m545_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_411_1 = {&var305,&iEM_TERB2SS33LIM,&var22,&vainSBool,&internal1_m411_Out10,&bFirstEnterFlag};
_S_noto  S_noto_490_1 = {&var183,&var23};
_S_noto  S_noto_491_1 = {&var182,&var24};
_S_noto  S_noto_479_1 = {&var184,&var25};
_S_noto  S_noto_481_1 = {&var185,&var26};
_S_rs  S_rs_488_1 = {&var24,&lEM_R5AD10LC1,&var27,&vainSBool,&internal1_m488_q0};
_S_rs  S_rs_489_1 = {&var23,&lEM_R5AD20LC1,&var28,&vainSBool,&internal1_m489_q0};
_S_rs  S_rs_474_1 = {&var25,&lEM_R3AD10LC1,&var29,&vainSBool,&internal1_m474_q0};
_S_rs  S_rs_475_1 = {&var26,&lEM_R3AD20LC1,&var30,&vainSBool,&internal1_m475_q0};
_S_andn  S_andn_357_1 = {array_m357_x_1,&iRM_16_,&vainSBool};
_S_zpfs  S_zpfs_644_1 = {&R0AD14LDU,&fEM_R7UI76RIM,&var31,&internal1_m644_tx,&internal1_m644_y0};
_S_zpfs  S_zpfs_632_1 = {&R0AD16LDU,&fEM_R7UI77RIM,&var32,&internal1_m632_tx,&internal1_m632_y0};
_S_bol  S_bol_955_1 = {&fEM_A4UP01RIM,&fEM_A4UP02RIM,&var33};
_S_bol  S_bol_952_1 = {&fEM_A3UP01RIM,&fEM_A3UP02RIM,&var34};
_S_bol  S_bol_931_1 = {&fEM_A0UP02RIM,&fEM_A0UP01RIM,&var35};
_S_bol  S_bol_953_1 = {&fEM_A2UP02RIM,&fEM_A2UP03RIM,&var36};
_S_bol  S_bol_943_1 = {&fEM_A1UP01RIM,&fEM_A1UP82RIM,&var37};
_S_ampl  S_ampl_374_1 = {&var218,&fRM_0_1,&vainSFloat};
_S_or2  S_or2_944_1 = {&R0EE04LZ1,&R0EE04LZ2,&var38};
_S_or2  S_or2_935_1 = {&R0EE03LZ1,&R0EE03LZ2,&var39};
_S_or2  S_or2_928_1 = {&R0EE02LZ1,&R0EE02LZ2,&var40};
_S_or2  S_or2_921_1 = {&R0EE01LZ1,&R0EE01LZ2,&var41};
_S_zpfs  S_zpfs_618_1 = {&var186,&fRM_1_0,&var42,&internal1_m618_tx,&internal1_m618_y0};
_S_zpfs  S_zpfs_616_1 = {&var189,&fRM_0_5,&var43,&internal1_m616_tx,&internal1_m616_y0};
_S_twobool  S_twobool_208_1 = {&B1AD21LDU,&iEM_TERB1IE04LDU,&var44,&vainSBool,&internal1_m208_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_225_1 = {&B1AD11LDU,&iEM_TERB1IE03LDU,&var45,&vainSBool,&internal1_m225_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_41_1 = {&A1AD21LDU,&iEM_TERA1IE04LDU,&var46,&vainSBool,&internal1_m41_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_56_1 = {&A1AD11LDU,&iEM_TERA1IE03LDU,&var47,&vainSBool,&internal1_m56_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_985_1 = {&var322,&iEM_TERB1SS12LIM,&var48,&vainSBool,&internal1_m985_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_982_1 = {&var318,&iEM_TERB1SS11LIM,&var49,&vainSBool,&internal1_m982_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_981_1 = {&var319,&iEM_TERB1SS21LIM,&var50,&vainSBool,&internal1_m981_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_984_1 = {&var52,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var51,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m984_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_979_1 = {&var221,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB1MC01RIM,&var52,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_967_1 = {&var54,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var53,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m967_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_960_1 = {&var222,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA1SC01RIM,&var54,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_968_1 = {&var329,&iEM_TERA1SS12LIM,&var55,&vainSBool,&internal1_m968_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_965_1 = {&var326,&iEM_TERA1SS11LIM,&var56,&vainSBool,&internal1_m965_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_964_1 = {&var327,&iEM_TERA1SS21LIM,&var57,&vainSBool,&internal1_m964_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1052_1 = {&var260,&iEM_TERB6SS21LIM,&var58,&vainSBool,&internal1_m1052_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1033_1 = {&var259,&iEM_TERB6SS11LIM,&var59,&vainSBool,&internal1_m1033_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1032_1 = {&var264,&iEM_TERA6SS21LIM,&var60,&vainSBool,&internal1_m1032_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1031_1 = {&var263,&iEM_TERA6MS11LIM,&var61,&vainSBool,&internal1_m1031_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_852_1 = {&var269,&iEM_TERA8SS12LIM,&var62,&vainSBool,&internal1_m852_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_854_1 = {&var268,&iEM_TERA8SS22LIM,&var63,&vainSBool,&internal1_m854_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_851_1 = {&var272,&iEM_TERB8SS12LIM,&var64,&var65,&internal1_m851_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_853_1 = {&var271,&iEM_TERB8SS22LIM,&var66,&var67,&internal1_m853_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_827_1 = {&var273,&iEM_TERR4SS12LIM,&var68,&vainSBool,&internal1_m827_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_828_1 = {&var274,&iEM_TERR4SS22LIM,&var69,&vainSBool,&internal1_m828_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_826_1 = {&var276,&iEM_TERR4MS21LIM,&var70,&vainSBool,&internal1_m826_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_825_1 = {&var275,&iEM_TERR4SS11LIM,&var71,&vainSBool,&internal1_m825_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1047_1 = {&var33,&iEM_TERA4VP82LIM,&var72,&var73,&internal1_m1047_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_999_1 = {&var252,&iEM_TERR2SS21LIM,&var74,&vainSBool,&internal1_m999_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_998_1 = {&var251,&iEM_TERR2SS11LIM,&var75,&vainSBool,&internal1_m998_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_997_1 = {&var256,&iEM_TERR1SS21LIM,&var76,&vainSBool,&internal1_m997_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_996_1 = {&var255,&iEM_TERR1SS11LIM,&var77,&vainSBool,&internal1_m996_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1048_1 = {&var191,&iEM_TERB4SS21LIM,&var78,&vainSBool,&internal1_m1048_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1029_1 = {&var190,&iEM_TERB4SS11LIM,&var79,&vainSBool,&internal1_m1029_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_829_1 = {&lEM_R8AD10LC1,&iEM_TERR8SS11LIM,&var80,&vainSBool,&internal1_m829_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1030_1 = {&var188,&iEM_TERA4SS21LIM,&var81,&vainSBool,&internal1_m1030_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1028_1 = {&var187,&iEM_TERA4SS11LIM,&var82,&vainSBool,&internal1_m1028_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1049_1 = {&var183,&iEM_TERR5SS21LIM,&var83,&vainSBool,&internal1_m1049_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1027_1 = {&var182,&iEM_TERR5SS11LIM,&var84,&vainSBool,&internal1_m1027_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1010_1 = {&var185,&iEM_TERR3SS21LIM,&var85,&vainSBool,&internal1_m1010_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_995_1 = {&var184,&iEM_TERR3SS11LIM,&var86,&vainSBool,&internal1_m995_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_546_1 = {&var36,&iEM_TERA2VP82LIM,&var87,&var88,&internal1_m546_Out10,&bFirstEnterFlag};
_S_toao  S_toao_550_1 = {&var92,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var89,&bFirstEnterFlag};
_S_toao  S_toao_549_1 = {&var91,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var90,&bFirstEnterFlag};
_S_to3val  S_to3val_543_1 = {&var149,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERB2SP01RIM,&var91,&vainSFloat,&var92,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_421_1 = {&var94,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var93,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m421_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_415_1 = {&var220,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB2SC01RIM,&var94,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_412_1 = {&var307,&iEM_TERB2SS12LIM,&var95,&vainSBool,&internal1_m412_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_414_1 = {&var302,&iEM_TERB2SS11LIM,&var96,&vainSBool,&internal1_m414_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_413_1 = {&var303,&iEM_TERB2SS21LIM,&var97,&vainSBool,&internal1_m413_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_867_1 = {&var197,&iEM_TERB9SS21LIM,&var98,&vainSBool,&internal1_m867_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_868_1 = {&var196,&iEM_TERB9SS11LIM,&var99,&vainSBool,&internal1_m868_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_866_1 = {&var194,&iEM_TERA9SS21LIM,&var100,&vainSBool,&internal1_m866_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1051_1 = {&var193,&iEM_TERA9SS11LIM,&var101,&vainSBool,&internal1_m1051_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_706_1 = {&var244,&iEM_TERB5SS21LIM,&var102,&vainSBool,&internal1_m706_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_707_1 = {&var243,&iEM_TERB5SS11LIM,&var103,&vainSBool,&internal1_m707_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_704_1 = {&var248,&iEM_TERA5SS21LIM,&var104,&vainSBool,&internal1_m704_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_705_1 = {&var247,&iEM_TERA5SS11LIM,&var105,&vainSBool,&internal1_m705_Out10,&bFirstEnterFlag};
_S_ampl  S_ampl_657_1 = {&var226,&fEM_R7UI75RIM,&var106};
_S_to3val  S_to3val_658_1 = {&var106,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R7UI74RIM,&fEM_R7UI74RIM,&iEM_TERR7SI74RIM,&vainSFloat,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_562_1 = {&var35,&iEM_TERB0VP81LIM,&var107,&vainSBool,&internal1_m562_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_561_1 = {&var35,&iEM_TERA0VP81LIM,&var108,&vainSBool,&internal1_m561_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_848_1 = {&var110,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var109,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m848_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_840_1 = {&var270,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB8SC01RIM,&var110,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_850_1 = {&var112,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var111,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m850_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_842_1 = {&var267,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA8SC01RIM,&var112,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_703_1 = {&R0MW13LP2,&iEM_TERR6IS68LIM,&var113,&vainSBool,&internal1_m703_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_687_1 = {&R0MW13LP2,&iEM_TERR6IS67LIM,&var114,&vainSBool,&internal1_m687_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_667_1 = {&R0MW13LP2,&iEM_TERR6IS66LIM,&var115,&vainSBool,&internal1_m667_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_686_1 = {&R0MW13LP2,&iEM_TERR6IS64LIM,&var116,&var117,&internal1_m686_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_666_1 = {&R0MW13LP2,&iEM_TERR6IS62LIM,&var118,&var119,&internal1_m666_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_339_1 = {&var288,&iEM_TERB3SS22LIM,&var120,&vainSBool,&internal1_m339_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_338_1 = {&var295,&iEM_TERA3SS22LIM,&var121,&vainSBool,&internal1_m338_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_323_1 = {&var289,&iEM_TERB3SS11LIM,&var122,&vainSBool,&internal1_m323_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_322_1 = {&var296,&iEM_TERA3SS11LIM,&var123,&vainSBool,&internal1_m322_Out10,&bFirstEnterFlag};
_S_toao  S_toao_523_1 = {&var125,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var124,&bFirstEnterFlag};
_S_to3val  S_to3val_517_1 = {&var171,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERA3SP02RIM,&vainSFloat,&var125,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_563_1 = {&var34,&iEM_TERA3VP81LIM,&var126,&var127,&internal1_m563_Out10,&bFirstEnterFlag};
_S_toao  S_toao_527_1 = {&var129,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var128,&bFirstEnterFlag};
_S_to3val  S_to3val_520_1 = {&var169,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERB3SP02RIM,&vainSFloat,&var129,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_352_1 = {&var292,&iEM_TERB3SS33LIM,&var130,&vainSBool,&internal1_m352_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_336_1 = {&var132,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var131,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m336_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_335_1 = {&var287,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB3SC01RIM,&var132,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_351_1 = {&var291,&iEM_TERB3SS31LIM,&var133,&vainSBool,&internal1_m351_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_349_1 = {&var299,&iEM_TERA3SS33LIM,&var134,&vainSBool,&internal1_m349_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_329_1 = {&var136,&fEM_A3UC03RDU,&fRM_0_,&iRM_0_,&var135,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m329_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_325_1 = {&var294,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA3SC01RIM,&var136,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_350_1 = {&var298,&iEM_TERA3SS31LIM,&var137,&vainSBool,&internal1_m350_Out10,&bFirstEnterFlag};
_S_toao  S_toao_548_1 = {&var150,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var138,&bFirstEnterFlag};
_S_toao  S_toao_547_1 = {&var148,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var139,&bFirstEnterFlag};
_S_twobool  S_twobool_321_1 = {&var290,&iEM_TERB3SS21LIM,&var140,&vainSBool,&internal1_m321_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_337_1 = {&var297,&iEM_TERA3SS21LIM,&var141,&vainSBool,&internal1_m337_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_433_1 = {&var313,&iEM_TERA2SS33LIM,&var142,&vainSBool,&internal1_m433_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_434_1 = {&var144,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var143,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m434_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_429_1 = {&var219,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA2SC01RIM,&var144,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_432_1 = {&var315,&iEM_TERA2SS12LIM,&var145,&vainSBool,&internal1_m432_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_431_1 = {&var310,&iEM_TERA2SS11LIM,&var146,&vainSBool,&internal1_m431_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_430_1 = {&var311,&iEM_TERA2SS21LIM,&var147,&vainSBool,&internal1_m430_Out10,&bFirstEnterFlag};
_S_to3val  S_to3val_542_1 = {&fEM_A2UP01RIM,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERA2SP01RIM,&var148,&var149,&var150,&bFirstEnterFlag};
_S_toao  S_toao_163_1 = {&var156,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var151,&bFirstEnterFlag};
_S_toao  S_toao_162_1 = {&var155,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var152,&bFirstEnterFlag};
_S_toao  S_toao_161_1 = {&var154,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var153,&bFirstEnterFlag};
_S_to3val  S_to3val_156_1 = {&var282,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERB0MT01RIM,&var154,&var155,&var156,&bFirstEnterFlag};
_S_toao  S_toao_166_1 = {&var164,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var157,&bFirstEnterFlag};
_S_toao  S_toao_165_1 = {&var163,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var158,&bFirstEnterFlag};
_S_twobool  S_twobool_1050_1 = {&var181,&iEM_TERR6SS21LIM,&var159,&vainSBool,&internal1_m1050_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_150_1 = {&var283,&iEM_TERB7MS31LIM,&var160,&vainSBool,&internal1_m150_Out10,&bFirstEnterFlag};
_S_toao  S_toao_164_1 = {&var162,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var161,&bFirstEnterFlag};
_S_to3val  S_to3val_158_1 = {&var333,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERA0MT01RIM,&var162,&var163,&var164,&bFirstEnterFlag};
_S_twobool  S_twobool_149_1 = {&var334,&iEM_TERA7MS31LIM,&var165,&vainSBool,&internal1_m149_Out10,&bFirstEnterFlag};
_S_orn  S_orn_920_1 = {array_m920_x_1,&iRM_2_,&var166};
_S_andn  S_andn_915_1 = {array_m915_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_919_1 = {&var166,&var167};
_S_noto  S_noto_515_1 = {&B3AD34LDU,&var168};
_S_lk  S_lk_519_1 = {&fEM_A3UP02RDU,&var168,&var169};
_S_noto  S_noto_513_1 = {&A3AD34LDU,&var170};
_S_lk  S_lk_518_1 = {&fEM_A3UP02RDU,&var170,&var171};
_S_ovb1  S_ovb1_197_1 = {&R8AD21LDU,&iRM_500_,&var172,&internal1_m197_tx};
_S_ovb1  S_ovb1_30_1 = {&R8AD21LDU,&iRM_500_,&var173,&internal1_m30_tx};
_S_andn  S_andn_940_1 = {array_m940_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_945_1 = {&var38,&var174};
_S_andn  S_andn_933_1 = {array_m933_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_936_1 = {&var39,&var175};
_S_andn  S_andn_925_1 = {array_m925_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_929_1 = {&var40,&var176};
_S_orn  S_orn_634_1 = {array_m634_x_1,&iRM_2_,&var177};
_S_orn  S_orn_631_1 = {array_m631_x_1,&iRM_2_,&var178};
_S_react  S_react_200_1 = {&var284,&var179};
_S_noto  S_noto_476_1 = {&lEM_R6AD10LC1,&var180};
_S_asmot  S_asmot_478_1 = {&var180,&lEM_R6AD10LC1,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R6UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R6UC01RSP,&fEM_R6UV01RSP,&vainSFloat,&var181,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m478_Pav0,&internal1_m478_Zav0,&internal1_m478_Pv0,&internal1_m478_Zv0,&internal1_m478_RA00,&internal1_m478_RA10,&internal1_m478_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_492_1 = {&var27,&var28,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R5UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R5UC01RSP,&fEM_R5UV01RSP,&vainSFloat,&var182,&var183,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m492_Pav0,&internal1_m492_Zav0,&internal1_m492_Pv0,&internal1_m492_Zv0,&internal1_m492_RA00,&internal1_m492_RA10,&internal1_m492_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_480_1 = {&var29,&var30,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R3UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R3UC01RSP,&fEM_R3UV01RSP,&vainSFloat,&var184,&var185,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m480_Pav0,&internal1_m480_Zav0,&internal1_m480_Pv0,&internal1_m480_Zv0,&internal1_m480_RA00,&internal1_m480_RA10,&internal1_m480_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_617_1 = {&A4AD10LDU,&var186};
_S_asmot  S_asmot_623_1 = {&var186,&A4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A4MC01RSP,&fEM_A4MV01RSP,&vainSFloat,&var187,&var188,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m623_Pav0,&internal1_m623_Zav0,&internal1_m623_Pv0,&internal1_m623_Zv0,&internal1_m623_RA00,&internal1_m623_RA10,&internal1_m623_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_615_1 = {&B4AD10LDU,&var189};
_S_asmot  S_asmot_620_1 = {&var189,&B4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B4MC01RSP,&fEM_B4MV01RSP,&vainSFloat,&var190,&var191,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m620_Pav0,&internal1_m620_Zav0,&internal1_m620_Pv0,&internal1_m620_Zv0,&internal1_m620_RA00,&internal1_m620_RA10,&internal1_m620_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_604_1 = {&A9AD10LDU,&var192};
_S_asmot  S_asmot_606_1 = {&var192,&A9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A9MC01RSP,&fEM_A9MV01RSP,&vainSFloat,&var193,&var194,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m606_Pav0,&internal1_m606_Zav0,&internal1_m606_Pv0,&internal1_m606_Zv0,&internal1_m606_RA00,&internal1_m606_RA10,&internal1_m606_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_603_1 = {&B9AD10LDU,&var195};
_S_asmot  S_asmot_605_1 = {&var195,&B9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B9MC01RSP,&fEM_B9MV01RSP,&vainSFloat,&var196,&var197,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m605_Pav0,&internal1_m605_Zav0,&internal1_m605_Pv0,&internal1_m605_Zv0,&internal1_m605_RA00,&internal1_m605_RA10,&internal1_m605_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orn  S_orn_640_1 = {array_m640_x_1,&iRM_3_,&var198};
_S_andn  S_andn_917_1 = {array_m917_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_922_1 = {&var41,&var199};
_S_andn  S_andn_292_1 = {array_m292_x_1,&iRM_2_,&var200};
_S_andn  S_andn_257_1 = {array_m257_x_1,&iRM_3_,&var201};
_S_noto  S_noto_256_1 = {&C2MD31LP1,&var202};
_S_andn  S_andn_258_1 = {array_m258_x_1,&iRM_3_,&var203};
_S_noto  S_noto_216_1 = {&C1MD31LP2,&var204};
_S_noto  S_noto_215_1 = {&C1MD31LP1,&var205};
_S_andn  S_andn_218_1 = {array_m218_x_1,&iRM_4_,&var206};
_S_andn  S_andn_217_1 = {array_m217_x_1,&iRM_4_,&var207};
_S_andn  S_andn_121_1 = {array_m121_x_1,&iRM_2_,&var208};
_S_noto  S_noto_46_1 = {&C1MD31LP2,&var209};
_S_noto  S_noto_45_1 = {&C1MD31LP1,&var210};
_S_andn  S_andn_48_1 = {array_m48_x_1,&iRM_4_,&var211};
_S_andn  S_andn_47_1 = {array_m47_x_1,&iRM_4_,&var212};
_S_andn  S_andn_87_1 = {array_m87_x_1,&iRM_3_,&var213};
_S_noto  S_noto_86_1 = {&C2MD31LP1,&var214};
_S_andn  S_andn_88_1 = {array_m88_x_1,&iRM_3_,&var215};
_S_noto  S_noto_639_1 = {&var198,&var216};
_S_orn  S_orn_647_1 = {array_m647_x_1,&iRM_2_,&var217};
_S_fsubo  S_fsubo_373_1 = {&fEM_R7UY00RSS,&var270,&var218};
_S_fsubo  S_fsubo_115_1 = {&fEM_A2UC05RIM,&var309,&var219};
_S_fsubo  S_fsubo_285_1 = {&fEM_A2UC05RIM,&var301,&var220};
_S_fsubo  S_fsubo_244_1 = {&fEM_A1UC05RIM,&var317,&var221};
_S_fsubo  S_fsubo_74_1 = {&fEM_A1UC05RIM,&var324,&var222};
_S_fsubo  S_fsubo_8_1 = {&var224,&fEM_R0UR01RIM,&var223};
_S_inf  S_inf_7_1 = {&var270,array_m7_a_1,array_m7_b_1,&iRM_5_,&var224,&vainSInt};
_S_inf  S_inf_9_1 = {&var270,array_m9_a_1,array_m9_b_1,&iRM_7_,&var225,&vainSInt};
_S_mod1  S_mod1_652_1 = {&var285,&fEM_R7UI02RIM,&fEM_R7UL01RIM,&var226,&internal1_m652_y0};
_S_bol  S_bol_646_1 = {&var285,&fEM_R7UI73RIM,&var227};
_S_bol  S_bol_636_1 = {&var285,&fEM_R7UI72RIM,&var228};
_S_bol  S_bol_630_1 = {&var285,&fEM_R7UI71RIM,&var229};
_S_vchs  S_vchs_813_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_5_,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var230,&internal1_m813_Chim0};
_S_vchs  S_vchs_804_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&bRM_4_,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var231,&internal1_m804_Chim0};
_S_vchs  S_vchs_796_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&bRM_1_,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var232,&internal1_m796_Chim0};
_S_vchs  S_vchs_787_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_5_,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var233,&internal1_m787_Chim0};
_S_vchs  S_vchs_778_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&bRM_4_,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var234,&internal1_m778_Chim0};
_S_vchs  S_vchs_770_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&bRM_1_,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var235,&internal1_m770_Chim0};
_S_vchs  S_vchs_761_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_5_,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var236,&internal1_m761_Chim0};
_S_vchs  S_vchs_752_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&bRM_4_,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var237,&internal1_m752_Chim0};
_S_vchs  S_vchs_744_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&bRM_2_,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var238,&internal1_m744_Chim0};
_S_vchs  S_vchs_735_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UC10RIM,&fEM_R7UC19RIM,&bRM_5_,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var239,&internal1_m735_Chim0};
_S_vchs  S_vchs_726_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&bRM_4_,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var240,&internal1_m726_Chim0};
_S_fsumo  S_fsumo_911_1 = {&fEM_R4UC10RIM,&fEM_R4UC22RIM,&var241};
_S_vchs  S_vchs_718_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&bRM_2_,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var242,&internal1_m718_Chim0};
_S_asmot  S_asmot_592_1 = {&B5AD10LDU,&B5AD20LDU,&fEM_B5MC01RC1,&fEM_B5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL2,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_B5MC01RSP,&fEM_B5MV01RSP,&vainSFloat,&var243,&var244,&vainSBool,&vainSBool,&vainSFloat,&var245,&var246,&internal1_m592_Pav0,&internal1_m592_Zav0,&internal1_m592_Pv0,&internal1_m592_Zv0,&internal1_m592_RA00,&internal1_m592_RA10,&internal1_m592_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_577_1 = {&A5AD10LDU,&A5AD20LDU,&fEM_A5MC01RC1,&fEM_A5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL1,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_A5MC01RSP,&fEM_A5MV01RSP,&vainSFloat,&var247,&var248,&vainSBool,&vainSBool,&vainSFloat,&var249,&var250,&internal1_m577_Pav0,&internal1_m577_Zav0,&internal1_m577_Pv0,&internal1_m577_Zv0,&internal1_m577_RA00,&internal1_m577_RA10,&internal1_m577_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_463_1 = {&R2AD10LDU,&R2AD20LDU,&fEM_R2MC01RC1,&fEM_R2MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ2,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R2MC01RSP,&fEM_R2MV01RSP,&vainSFloat,&var251,&var252,&vainSBool,&vainSBool,&vainSFloat,&var253,&var254,&internal1_m463_Pav0,&internal1_m463_Zav0,&internal1_m463_Pv0,&internal1_m463_Zv0,&internal1_m463_RA00,&internal1_m463_RA10,&internal1_m463_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_448_1 = {&R1AD10LDU,&R1AD20LDU,&fEM_R1MC01RC1,&fEM_R1MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ1,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R1MC01RSP,&fEM_R1MV01RSP,&vainSFloat,&var255,&var256,&vainSBool,&vainSBool,&vainSFloat,&var257,&var258,&internal1_m448_Pav0,&internal1_m448_Zav0,&internal1_m448_Pv0,&internal1_m448_Zv0,&internal1_m448_RA00,&internal1_m448_RA10,&internal1_m448_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_504_1 = {&B6AD10LDU,&B6AD20LDU,&fEM_B6MC01RC1,&fEM_B6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ2,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_B6MC01RSP,&fEM_B6MV01RSP,&vainSFloat,&var259,&var260,&vainSBool,&vainSBool,&vainSFloat,&var261,&var262,&internal1_m504_Pav0,&internal1_m504_Zav0,&internal1_m504_Pv0,&internal1_m504_Zv0,&internal1_m504_RA00,&internal1_m504_RA10,&internal1_m504_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_399_1 = {&A6AD10LDU,&A6AD20LDU,&fEM_A6MC01RC1,&fEM_A6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ1,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_A6MC01RSP,&fEM_A6MV01RSP,&vainSFloat,&var263,&var264,&vainSBool,&vainSBool,&vainSFloat,&var265,&var266,&internal1_m399_Pav0,&internal1_m399_Zav0,&internal1_m399_Pv0,&internal1_m399_Zv0,&internal1_m399_RA00,&internal1_m399_RA10,&internal1_m399_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_383_1 = {&A8AD20LDU,&A8AD10LDU,&fEM_A8MC01RC1,&fEM_A8MV01RC1,&fEM_A8UV80RDU,&fEM_A8US80RDU,&iEM_TERDS2,&fEM_A8UC10RIM,&fEM_A8UC20RIM,&fEM_A8UC11RIM,&fEM_A8UC21RIM,&fEM_A8UC08RDU,&fEM_A8MC01RSP,&fEM_A8MV01RSP,&var267,&var268,&var269,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m383_Pav0,&internal1_m383_Zav0,&internal1_m383_Pv0,&internal1_m383_Zv0,&internal1_m383_RA00,&internal1_m383_RA10,&internal1_m383_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_366_1 = {&B8AD20LDU,&B8AD10LDU,&fEM_B8MC01RC1,&fEM_B8MV01RC1,&fEM_B8UV80RDU,&fEM_B8US80RDU,&iEM_TERMAZ2,&fEM_B8UC10RIM,&fEM_B8UC20RIM,&fEM_B8UC11RIM,&fEM_B8UC21RIM,&fEM_B8UC08RDU,&fEM_B8MC01RSP,&fEM_B8MV01RSP,&var270,&var271,&var272,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m366_Pav0,&internal1_m366_Zav0,&internal1_m366_Pv0,&internal1_m366_Zv0,&internal1_m366_RA00,&internal1_m366_RA10,&internal1_m366_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_906_1 = {&R4AD10LDU,&R4AD20LDU,&fEM_R4MC01RC1,&fEM_R4MV01RC1,&fEM_R4UV80RDU,&fEM_R4US80RDU,&iEM_TERTLG,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC08RDU,&fEM_R4MC01RSP,&fEM_R4MV01RSP,&vainSFloat,&var273,&var274,&var275,&var276,&vainSFloat,&var277,&var278,&internal1_m906_Pav0,&internal1_m906_Zav0,&internal1_m906_Pv0,&internal1_m906_Zv0,&internal1_m906_RA00,&internal1_m906_RA10,&internal1_m906_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_182_1 = {&var316,&var300,&var286,&var330,&fEM_R0UR30RIM,&B7AP31LDU,&var190,&lEM_R8AD10LC1,&var172,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var223,&var225,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_B0UT03RSP,&var279,&var280,&var281,&var282,&var283,&var284,&var285,&internal1_m182_C1,&internal1_m182_C2,&internal1_m182_C3,&internal1_m182_C4,&internal1_m182_C5,&internal1_m182_C6,&internal1_m182_N20,array_m182_C0_1,&internal1_m182_ImpINI0,&internal1_m182_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_300_1 = {&B3AD11LDU,&B3AD21LDU,&B3AD02LDU,&B3AD01LDU,&B3AD03LDU,&B3AD04LDU,&B3AD05LDU,&var200,&B3AD33LDU,&lRM_1_,&fEM_B3MC01RC1,&fEM_B3MC02RC1,&fEM_B3MV01RC1,&fEM_B3MV02RC1,&lRM_0_,array_m300_Vr_1,&fEM_A3UC02RDU,&var169,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS2,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_B3MC01RSP,&fEM_B3MC02RSP,&fEM_B3MV01RSP,&fEM_B3MV02RSP,&var286,&var287,&var288,&var289,&var290,&vainSFloat,&vainSFloat,&var291,&var292,&vainSBool,&vainSBool,&internal1_m300_Ppv0,&internal1_m300_Pav0,&internal1_m300_Zav0,&internal1_m300_RA00,&internal1_m300_RA10,&internal1_m300_RA50,&internal1_m300_fls,&internal1_m300_flp,&internal1_m300_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_133_1 = {&A3AD11LDU,&A3AD21LDU,&A3AD02LDU,&A3AD01LDU,&A3AD03LDU,&A3AD04LDU,&A3AD05LDU,&var208,&A3AD33LDU,&lRM_1_,&fEM_A3MC01RC1,&fEM_A3MC02RC1,&fEM_A3MV01RC1,&fEM_A3MV02RC1,&lRM_0_,array_m133_Vr_1,&fEM_A3UC02RDU,&var171,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS1,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_A3MC01RSP,&fEM_A3MC02RSP,&fEM_A3MV01RSP,&fEM_A3MV02RSP,&var293,&var294,&var295,&var296,&var297,&vainSFloat,&vainSFloat,&var298,&var299,&vainSBool,&vainSBool,&internal1_m133_Ppv0,&internal1_m133_Pav0,&internal1_m133_Zav0,&internal1_m133_RA00,&internal1_m133_RA10,&internal1_m133_RA50,&internal1_m133_fls,&internal1_m133_flp,&internal1_m133_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_266_1 = {&B2AD11LDU,&B2AD21LDU,&B2AD02LDU,&B2AD01LDU,&B2AD03LDU,&B2AD04LDU,&B2AD05LDU,&var201,&B2AD33LDU,&var203,&fEM_B2MC01RC1,&fEM_B2MC02RC1,&fEM_B2MV01RC1,&fEM_B2MV02RC1,&lRM_1_,array_m266_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB2,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_B2MC01RSP,&fEM_B2MC02RSP,&fEM_B2MV01RSP,&fEM_B2MV02RSP,&var300,&var301,&vainSBool,&var302,&var303,&vainSFloat,&vainSFloat,&var304,&var305,&var306,&var307,&internal1_m266_Ppv0,&internal1_m266_Pav0,&internal1_m266_Zav0,&internal1_m266_RA00,&internal1_m266_RA10,&internal1_m266_RA50,&internal1_m266_fls,&internal1_m266_flp,&internal1_m266_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_96_1 = {&A2AD11LDU,&A2AD21LDU,&A2AD02LDU,&A2AD01LDU,&A2AD03LDU,&A2AD04LDU,&A2AD05LDU,&var213,&A2AD33LDU,&var215,&fEM_A2MC01RC1,&fEM_A2MC02RC1,&fEM_A2MV01RC1,&fEM_A2MV02RC1,&lRM_1_,array_m96_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB1,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_A2MC01RSP,&fEM_A2MC02RSP,&fEM_A2MV01RSP,&fEM_A2MV02RSP,&var308,&var309,&vainSBool,&var310,&var311,&vainSFloat,&vainSFloat,&var312,&var313,&var314,&var315,&internal1_m96_Ppv0,&internal1_m96_Pav0,&internal1_m96_Zav0,&internal1_m96_RA00,&internal1_m96_RA10,&internal1_m96_RA50,&internal1_m96_fls,&internal1_m96_flp,&internal1_m96_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_229_1 = {&B1AD11LDU,&B1AD21LDU,&B1AD02LDU,&B1AD01LDU,&B1AD03LDU,&B1AD04LDU,&B1AD05LDU,&var207,&lRM_1_,&var206,&fEM_B1MC01RC1,&fEM_B1MC02RC1,&fEM_B1MV01RC1,&fEM_B1MV02RC1,&lRM_1_,array_m229_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB2,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_B1MC01RSP,&fEM_B1MC02RSP,&fEM_B1MV01RSP,&fEM_B1MV02RSP,&var316,&var317,&vainSBool,&var318,&var319,&vainSFloat,&vainSFloat,&var320,&vainSBool,&var321,&var322,&internal1_m229_Ppv0,&internal1_m229_Pav0,&internal1_m229_Zav0,&internal1_m229_RA00,&internal1_m229_RA10,&internal1_m229_RA50,&internal1_m229_fls,&internal1_m229_flp,&internal1_m229_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_60_1 = {&A1AD11LDU,&A1AD21LDU,&A1AD02LDU,&A1AD01LDU,&A1AD03LDU,&A1AD04LDU,&A1AD05LDU,&var212,&lRM_1_,&var211,&fEM_A1MC01RC1,&fEM_A1MC02RC1,&fEM_A1MV01RC1,&fEM_A1MV02RC1,&lRM_1_,array_m60_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB1,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_A1MC01RSP,&fEM_A1MC02RSP,&fEM_A1MV01RSP,&fEM_A1MV02RSP,&var323,&var324,&var325,&var326,&var327,&vainSFloat,&vainSFloat,&vainSBool,&vainSBool,&var328,&var329,&internal1_m60_Ppv0,&internal1_m60_Pav0,&internal1_m60_Zav0,&internal1_m60_RA00,&internal1_m60_RA10,&internal1_m60_RA50,&internal1_m60_fls,&internal1_m60_flp,&internal1_m60_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_14_1 = {&var323,&var308,&var293,&var279,&fEM_R0UR30RIM,&A7AP31LDU,&var187,&lEM_R8AD10LC1,&var173,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var223,&var225,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_A0UT03RSP,&var330,&var331,&var332,&var333,&var334,&var335,&vainSFloat,&internal1_m14_C1,&internal1_m14_C2,&internal1_m14_C3,&internal1_m14_C4,&internal1_m14_C5,&internal1_m14_C6,&internal1_m14_N20,array_m14_C0_1,&internal1_m14_ImpINI0,&internal1_m14_MyFirstEnterFlag,&bFirstEnterFlag};


void Scheme()
{
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_86_1);
  noto(&S_noto_256_1);
  noto(&S_noto_603_1);
  noto(&S_noto_604_1);
  ovb1(&S_ovb1_30_1);
  ovb1(&S_ovb1_197_1);
  noto(&S_noto_515_1);
  bol(&S_bol_943_1);
  bol(&S_bol_953_1);
  bol(&S_bol_931_1);
  bol(&S_bol_952_1);
  bol(&S_bol_955_1);
  zpfs(&S_zpfs_632_1);
  zpfs(&S_zpfs_644_1);
  noto(&S_noto_481_1);
  noto(&S_noto_479_1);
  noto(&S_noto_491_1);
  noto(&S_noto_490_1);
  to3val(&S_to3val_969_1);
  asmot(&S_asmot_906_1);
  asmot(&S_asmot_366_1);
  asmot(&S_asmot_383_1);
  asmot(&S_asmot_399_1);
  asmot(&S_asmot_504_1);
  asmot(&S_asmot_448_1);
  asmot(&S_asmot_463_1);
  asmot(&S_asmot_577_1);
  asmot(&S_asmot_592_1);
  fsumo(&S_fsumo_911_1);
  inf(&S_inf_9_1);
  inf(&S_inf_7_1);
  fsubo(&S_fsubo_8_1);
  fsubo(&S_fsubo_373_1);
  noto(&S_noto_45_1);
  noto(&S_noto_46_1);
  noto(&S_noto_215_1);
  noto(&S_noto_216_1);
  orn(&S_orn_640_1);
  asmot(&S_asmot_605_1);
  asmot(&S_asmot_606_1);
  noto(&S_noto_615_1);
  noto(&S_noto_617_1);
  noto(&S_noto_476_1);
  noto(&S_noto_513_1);
  lk(&S_lk_519_1);
  orn(&S_orn_920_1);
  to3val(&S_to3val_542_1);
  toao(&S_toao_547_1);
  toao(&S_toao_548_1);
  to3val(&S_to3val_520_1);
  toao(&S_toao_527_1);
  twobool(&S_twobool_563_1);
  twobool(&S_twobool_666_1);
  twobool(&S_twobool_686_1);
  twobool(&S_twobool_667_1);
  twobool(&S_twobool_687_1);
  twobool(&S_twobool_703_1);
  to3val(&S_to3val_842_1);
  ktoenc(&S_ktoenc_850_1);
  to3val(&S_to3val_840_1);
  ktoenc(&S_ktoenc_848_1);
  twobool(&S_twobool_561_1);
  twobool(&S_twobool_562_1);
  twobool(&S_twobool_705_1);
  twobool(&S_twobool_704_1);
  twobool(&S_twobool_707_1);
  twobool(&S_twobool_706_1);
  twobool(&S_twobool_1051_1);
  twobool(&S_twobool_866_1);
  twobool(&S_twobool_868_1);
  twobool(&S_twobool_867_1);
  to3val(&S_to3val_543_1);
  toao(&S_toao_549_1);
  toao(&S_toao_550_1);
  twobool(&S_twobool_546_1);
  twobool(&S_twobool_995_1);
  twobool(&S_twobool_1010_1);
  twobool(&S_twobool_1027_1);
  twobool(&S_twobool_1049_1);
  twobool(&S_twobool_829_1);
  twobool(&S_twobool_996_1);
  twobool(&S_twobool_997_1);
  twobool(&S_twobool_998_1);
  twobool(&S_twobool_999_1);
  twobool(&S_twobool_1047_1);
  twobool(&S_twobool_825_1);
  twobool(&S_twobool_826_1);
  twobool(&S_twobool_828_1);
  twobool(&S_twobool_827_1);
  twobool(&S_twobool_853_1);
  twobool(&S_twobool_851_1);
  twobool(&S_twobool_854_1);
  twobool(&S_twobool_852_1);
  twobool(&S_twobool_1031_1);
  twobool(&S_twobool_1032_1);
  twobool(&S_twobool_1033_1);
  twobool(&S_twobool_1052_1);
  twobool(&S_twobool_56_1);
  twobool(&S_twobool_41_1);
  twobool(&S_twobool_225_1);
  twobool(&S_twobool_208_1);
  zpfs(&S_zpfs_616_1);
  zpfs(&S_zpfs_618_1);
  or2(&S_or2_921_1);
  or2(&S_or2_928_1);
  or2(&S_or2_935_1);
  or2(&S_or2_944_1);
  ampl(&S_ampl_374_1);
  rs(&S_rs_475_1);
  rs(&S_rs_474_1);
  rs(&S_rs_489_1);
  rs(&S_rs_488_1);
  twobool(&S_twobool_545_1);
  twobool(&S_twobool_529_1);
  twobool(&S_twobool_668_1);
  twobool(&S_twobool_669_1);
  twobool(&S_twobool_690_1);
  twobool(&S_twobool_691_1);
  twobool(&S_twobool_670_1);
  twobool(&S_twobool_671_1);
  twobool(&S_twobool_692_1);
  twobool(&S_twobool_693_1);
  twobool(&S_twobool_1011_1);
  twobool(&S_twobool_1012_1);
  twobool(&S_twobool_1013_1);
  twobool(&S_twobool_1014_1);
  twobool(&S_twobool_830_1);
  twobool(&S_twobool_831_1);
  noto(&S_noto_639_1);
  andn(&S_andn_88_1);
  andn(&S_andn_87_1);
  andn(&S_andn_47_1);
  andn(&S_andn_48_1);
  andn(&S_andn_121_1);
  andn(&S_andn_217_1);
  andn(&S_andn_218_1);
  andn(&S_andn_258_1);
  andn(&S_andn_257_1);
  andn(&S_andn_292_1);
  noto(&S_noto_922_1);
  andn(&S_andn_917_1);
  asmot(&S_asmot_620_1);
  asmot(&S_asmot_623_1);
  asmot(&S_asmot_480_1);
  asmot(&S_asmot_492_1);
  asmot(&S_asmot_478_1);
  noto(&S_noto_929_1);
  andn(&S_andn_925_1);
  noto(&S_noto_936_1);
  andn(&S_andn_933_1);
  noto(&S_noto_945_1);
  andn(&S_andn_940_1);
  lk(&S_lk_518_1);
  noto(&S_noto_919_1);
  andn(&S_andn_915_1);
  twobool(&S_twobool_1050_1);
  to3val(&S_to3val_517_1);
  toao(&S_toao_523_1);
  twobool(&S_twobool_1028_1);
  twobool(&S_twobool_1030_1);
  twobool(&S_twobool_1029_1);
  twobool(&S_twobool_1048_1);
  orrsim(&S_orrsim_60_1);
  orrsim(&S_orrsim_229_1);
  orrsim(&S_orrsim_96_1);
  orrsim(&S_orrsim_266_1);
  orrsim(&S_orrsim_133_1);
  orrsim(&S_orrsim_300_1);
  azbars(&S_azbars_182_1);
  bol(&S_bol_630_1);
  bol(&S_bol_636_1);
  bol(&S_bol_646_1);
  mod1(&S_mod1_652_1);
  fsubo(&S_fsubo_74_1);
  fsubo(&S_fsubo_244_1);
  fsubo(&S_fsubo_285_1);
  fsubo(&S_fsubo_115_1);
  orn(&S_orn_647_1);
  react(&S_react_200_1);
  orn(&S_orn_631_1);
  orn(&S_orn_634_1);
  twobool(&S_twobool_150_1);
  to3val(&S_to3val_156_1);
  toao(&S_toao_161_1);
  toao(&S_toao_162_1);
  toao(&S_toao_163_1);
  twobool(&S_twobool_430_1);
  twobool(&S_twobool_431_1);
  twobool(&S_twobool_432_1);
  to3val(&S_to3val_429_1);
  ktoenc(&S_ktoenc_434_1);
  twobool(&S_twobool_433_1);
  twobool(&S_twobool_337_1);
  twobool(&S_twobool_321_1);
  twobool(&S_twobool_350_1);
  to3val(&S_to3val_325_1);
  ktoenc(&S_ktoenc_329_1);
  twobool(&S_twobool_349_1);
  twobool(&S_twobool_351_1);
  to3val(&S_to3val_335_1);
  ktoenc(&S_ktoenc_336_1);
  twobool(&S_twobool_352_1);
  twobool(&S_twobool_322_1);
  twobool(&S_twobool_323_1);
  twobool(&S_twobool_338_1);
  twobool(&S_twobool_339_1);
  ampl(&S_ampl_657_1);
  twobool(&S_twobool_413_1);
  twobool(&S_twobool_414_1);
  twobool(&S_twobool_412_1);
  to3val(&S_to3val_415_1);
  ktoenc(&S_ktoenc_421_1);
  twobool(&S_twobool_964_1);
  twobool(&S_twobool_965_1);
  twobool(&S_twobool_968_1);
  to3val(&S_to3val_960_1);
  ktoenc(&S_ktoenc_967_1);
  to3val(&S_to3val_979_1);
  ktoenc(&S_ktoenc_984_1);
  twobool(&S_twobool_981_1);
  twobool(&S_twobool_982_1);
  twobool(&S_twobool_985_1);
  andn(&S_andn_357_1);
  twobool(&S_twobool_411_1);
  azbars(&S_azbars_14_1);
  vchs(&S_vchs_718_1);
  vchs(&S_vchs_726_1);
  vchs(&S_vchs_735_1);
  vchs(&S_vchs_744_1);
  vchs(&S_vchs_752_1);
  vchs(&S_vchs_761_1);
  vchs(&S_vchs_770_1);
  vchs(&S_vchs_778_1);
  vchs(&S_vchs_787_1);
  vchs(&S_vchs_796_1);
  vchs(&S_vchs_804_1);
  vchs(&S_vchs_813_1);
  twobool(&S_twobool_149_1);
  to3val(&S_to3val_158_1);
  toao(&S_toao_164_1);
  toao(&S_toao_165_1);
  toao(&S_toao_166_1);
  to3val(&S_to3val_658_1);
  vchs(&S_vchs_876_1);
  vchs(&S_vchs_884_1);
  vchs(&S_vchs_894_1);
  setData(idA0IT03IRP,&var157);
  setData(idB0IT03IRP,&var151);
  setData(idR0IN03FI3,&var233);
  setData(idR0IN02FI3,&var234);
  setData(idR0IN03FI2,&var236);
  setData(idR0IN07RIP,&var2);
  setData(idR0IN06RIP,&var1);
  setData(idR0IN03RIP,&var3);
  setData(idR0IN02RIP,&var4);
  setData(idR0IN01RIP,&var5);
  setData(idR0IN02FI2,&var237);
  setData(idR0IN03FI1,&var239);
  setData(idR0IN02FI1,&var240);
  setData(idR0IN03FI4,&var230);
  setData(idR0IN02FI4,&var231);
  setData(idR0IN01FI3,&var235);
  setData(idR0IN01FI2,&var238);
  setData(idR0IN01FI4,&var232);
  setData(idR0IN01FI1,&var242);
  setData(idR4VS12LDU,&var7);
  setData(idR4VS22LDU,&var6);
  setData(idR1VS12LDU,&var11);
  setData(idR2VS12LDU,&var9);
  setData(idR2VS22LDU,&var8);
  setData(idR1VS22LDU,&var10);
  setData(idB5VS12LDU,&var13);
  setData(idB5VS22LDU,&var12);
  setData(idA5VS12LDU,&var15);
  setData(idA5VS22LDU,&var14);
  setData(idB6VS12LDU,&var17);
  setData(idB6VS22LDU,&var16);
  setData(idA6VS12LDU,&var19);
  setData(idA6VS22LDU,&var18);
  setData(idB8IS21LDU,&var66);
  setData(idB8IS11LDU,&var64);
  setData(idA1VP81LZZ,&var20);
  setData(idB1VP81LZZ,&var21);
  setData(idB2IS33LDU,&var22);
  setData(idA0VN01RIM,&var335);
  setData(idB2IS32LIM,&var304);
  setData(idB2IS11LIM,&var306);
  setData(idA2IS32LIM,&var312);
  setData(idA2IS11LIM,&var314);
  setData(idB1IS32LIM,&var320);
  setData(idB1IS11LIM,&var321);
  setData(idA1IS32LIM,&var325);
  setData(idA1IS11LIM,&var328);
  setData(idR0IS02LDU,&lEM_R0IE02LRP);
  setData(idB4IS10LDU,&var43);
  setData(idA4IS10LDU,&var42);
  setData(idB1IE04LDU,&var44);
  setData(idB1IE03LDU,&var45);
  setData(idA1IE04LDU,&var46);
  setData(idA1IE03LDU,&var47);
  setData(idB1IS12LDU,&var48);
  setData(idB1IS11LDU,&var49);
  setData(idB1IS21LDU,&var50);
  setData(idB1IC01UDU,&var51);
  setData(idA1IC01UDU,&var53);
  setData(idA1IS12LDU,&var55);
  setData(idA1IS11LDU,&var56);
  setData(idA1IS21LDU,&var57);
  setData(idB6IS21LDU,&var58);
  setData(idB6IS11LDU,&var59);
  setData(idA6IS21LDU,&var60);
  setData(idA6IS11LDU,&var61);
  setData(idA8IS12LDU,&var62);
  setData(idA8IS22LDU,&var63);
  setData(idB8IS12LDU,&var65);
  setData(idB8IS22LDU,&var67);
  setData(idR4IS12LDU,&var68);
  setData(idR4IS22LDU,&var69);
  setData(idR4IS21LDU,&var70);
  setData(idR4IS11LDU,&var71);
  setData(idB4VP82LDU,&var73);
  setData(idA4VP82LDU,&var72);
  setData(idR2IS21LDU,&var74);
  setData(idR2IS11LDU,&var75);
  setData(idR1IS21LDU,&var76);
  setData(idR1IS11LDU,&var77);
  setData(idB4IS21LDU,&var78);
  setData(idB4IS11LDU,&var79);
  setData(idR8IS11LDU,&var80);
  setData(idA4IS21LDU,&var81);
  setData(idA4IS11LDU,&var82);
  setData(idR5IS21LDU,&var83);
  setData(idR5IS11LDU,&var84);
  setData(idR3IS21LDU,&var85);
  setData(idR3IS11LDU,&var86);
  setData(idB2VP82LDU,&var87);
  setData(idB2IP01IZ2,&var89);
  setData(idB2IP01IZ1,&var90);
  setData(idB2IC01UDU,&var93);
  setData(idB2IS12LDU,&var95);
  setData(idB2IS11LDU,&var96);
  setData(idB2IS21LDU,&var97);
  setData(idB9IS21LDU,&var98);
  setData(idB9IS11LDU,&var99);
  setData(idA9IS21LDU,&var100);
  setData(idA9IS11LDU,&var101);
  setData(idB5IS21LDU,&var102);
  setData(idB5IS11LDU,&var103);
  setData(idA5IS21LDU,&var104);
  setData(idA5IS11LDU,&var105);
  setData(idB0VP81LZZ,&var107);
  setData(idA0VP81LZZ,&var108);
  setData(idB8IC01UDU,&var109);
  setData(idA8IC01UDU,&var111);
  setData(idR6IS68LZZ,&var113);
  setData(idR6IS67LZZ,&var114);
  setData(idR6IS66LZZ,&var115);
  setData(idR6IS65LDU,&var117);
  setData(idR6IS64LDU,&var116);
  setData(idR6IS63LDU,&var119);
  setData(idR6IS62LDU,&var118);
  setData(idB3IS22LDU,&var120);
  setData(idA3IS22LDU,&var121);
  setData(idB3IS11LDU,&var122);
  setData(idA3IS11LDU,&var123);
  setData(idA3IP02IDU,&var124);
  setData(idB3VP81LDU,&var127);
  setData(idA3VP81LDU,&var126);
  setData(idB3IS33LDU,&var130);
  setData(idB3IC01UDU,&var131);
  setData(idB3IS31LDU,&var133);
  setData(idB3IP02IDU,&var128);
  setData(idA3IS33LDU,&var134);
  setData(idA3IC01UDU,&var135);
  setData(idA3IS31LDU,&var137);
  setData(idA2VP82LDU,&var88);
  setData(idA2IP01IZ2,&var138);
  setData(idA2IP01IZ1,&var139);
  setData(idB3IS21LDU,&var140);
  setData(idA3IS21LDU,&var141);
  setData(idA2IS33LDU,&var142);
  setData(idA2IC01UDU,&var143);
  setData(idA2IS12LDU,&var145);
  setData(idA2IS11LDU,&var146);
  setData(idA2IS21LDU,&var147);
  setData(idB0IT02IZ2,&var152);
  setData(idB0IT01IZ1,&var153);
  setData(idA0IT02IZ2,&var158);
  setData(idA0IT01IZ1,&var161);
  setData(idR6IS21LDU,&var159);
  setData(idB7AS31LDU,&var160);
  setData(idA7AS31LDU,&var165);
  setData(idB3IS35LDU,&var168);
  setData(idA3IS35LDU,&var170);
  setData(idR7II73LZ2,&var217);
  setData(idR7II71LZ2,&var178);
  setData(idR7II72LZ2,&var177);
  setData(idR7II72LZ1,&var177);
  setData(idR7II71LZ1,&var178);
  setData(idR7II73LZ1,&var217);
  setData(idR0SR01RIM,&var179);
  setData(idR0ST01RIM,&var284);
  setData(idR0SR02RIM,&var285);
  setData(idR0CR02RIM,&var223);
  setData(idR0CR01RIM,&var225);
  setData(idB0SN08RIM,&var280);
  setData(idA0SN08RIM,&var331);
  setData(idB0SR01RIM,&var281);
  setData(idA0SR01RIM,&var332);

  setAsBool(idbFirstEnterFlag,1);
}

void InitInternalParametr(void)
{
  int i;
  for( i=0;i<6;i++ )
    array_m182_C0_1[i] = &(&internal1_m182_C0)[i*5];
  for( i=0;i<6;i++ )
    array_m14_C0_1[i] = &(&internal1_m14_C0)[i*5];
}

#endif
