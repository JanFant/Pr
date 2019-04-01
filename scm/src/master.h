#ifndef SCM_H
#define SCM_H
// Подсистема scm:SCM
static char SimulOn=0;
static short CodeSub=1;
static char SimulIP[]="192.168.10.12\0";
static int SimulPort=5555;
static int StepCycle=35;	 // Время цикла в ms
float takt;
#define SIZE_BUFFER 3290
static char BUFFER[3290];
#define A1IS11LDU	 BUFFER[0]	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define idA1IS11LDU	 1	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
#define A1IS21LDU	 BUFFER[2]	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define idA1IS21LDU	 2	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
#define B6IS21LDU	 BUFFER[4]	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define idB6IS21LDU	 3	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
#define B6IS11LDU	 BUFFER[6]	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define idB6IS11LDU	 4	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
#define A6IS21LDU	 BUFFER[8]	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define idA6IS21LDU	 5	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
#define A6IS11LDU	 BUFFER[10]	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define idA6IS11LDU	 6	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
#define A8IS12LDU	 BUFFER[12]	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define idA8IS12LDU	 7	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
#define A8IS22LDU	 BUFFER[14]	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define idA8IS22LDU	 8	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
#define B8IS12LDU	 BUFFER[16]	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define idB8IS12LDU	 9	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
#define B8IS22LDU	 BUFFER[18]	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define idB8IS22LDU	 10	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
#define R4IS12LDU	 BUFFER[20]	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define idR4IS12LDU	 11	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
#define R4IS22LDU	 BUFFER[22]	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define idR4IS22LDU	 12	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
#define R4IS21LDU	 BUFFER[24]	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define idR4IS21LDU	 13	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
#define R4IS11LDU	 BUFFER[26]	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define idR4IS11LDU	 14	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
#define B4VP82LDU	 BUFFER[28]	//( - , SDu) Давление ПОДЪЁМ НИ2 в норме
#define idB4VP82LDU	 15	//( - , SDu) Давление ПОДЪЁМ НИ2 в норме
#define A4VP82LDU	 BUFFER[30]	//( - , SDu) Давление ПОДЪЁМ НИ1 в норме
#define idA4VP82LDU	 16	//( - , SDu) Давление ПОДЪЁМ НИ1 в норме
#define R2IS21LDU	 BUFFER[32]	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define idR2IS21LDU	 17	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
#define R0EE04LZ1	 BUFFER[34]	//( - , SBz1) Питание  АКНП4  отключить
#define idR0EE04LZ1	 18	//( - , SBz1) Питание  АКНП4  отключить
#define R0EE03LZ1	 BUFFER[36]	//( - , SBz1) Питание  АКНП3  отключить
#define idR0EE03LZ1	 19	//( - , SBz1) Питание  АКНП3  отключить
#define R0EE02LZ1	 BUFFER[38]	//( - , SBz1) Питание  АКНП  отключить
#define idR0EE02LZ1	 20	//( - , SBz1) Питание  АКНП  отключить
#define R0EE01LZ2	 BUFFER[40]	//( - , SBz2) Питание  АКНП1  отключить
#define idR0EE01LZ2	 21	//( - , SBz2) Питание  АКНП1  отключить
#define R0EE01LZ1	 BUFFER[42]	//( - , SBz1) Питание  АКНП1  отключить
#define idR0EE01LZ1	 22	//( - , SBz1) Питание  АКНП1  отключить
#define B4IS10LDU	 BUFFER[44]	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define idB4IS10LDU	 23	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
#define A4IS10LDU	 BUFFER[46]	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define idA4IS10LDU	 24	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
#define B1IE04LDU	 BUFFER[48]	//( - , SCM) Движение ББ2 назад (от БУШД)
#define idB1IE04LDU	 25	//( - , SCM) Движение ББ2 назад (от БУШД)
#define B1IE03LDU	 BUFFER[50]	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define idB1IE03LDU	 26	//( - , SCM) Движение ББ2 вперед (от БУШД)
#define A1IE04LDU	 BUFFER[52]	//( - , SCM) Движение ББ1 назад (от БУШД)
#define idA1IE04LDU	 27	//( - , SCM) Движение ББ1 назад (от БУШД)
#define A1IE03LDU	 BUFFER[54]	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define idA1IE03LDU	 28	//( - , SCM) Движение ББ1 вперед (от БУШД)
#define B1IS12LDU	 BUFFER[56]	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define idB1IS12LDU	 29	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
#define B1IS11LDU	 BUFFER[58]	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define idB1IS11LDU	 30	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
#define B1IS21LDU	 BUFFER[60]	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define idB1IS21LDU	 31	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
#define B1IC01UDU	 BUFFER[62]	//( - , SDu) Координата штока ББ2
#define idB1IC01UDU	 32	//( - , SDu) Координата штока ББ2
#define A1IC01UDU	 BUFFER[67]	//( - , SDu) Координата штока ББ1
#define idA1IC01UDU	 33	//( - , SDu) Координата штока ББ1
#define A1IS12LDU	 BUFFER[72]	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define idA1IS12LDU	 34	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
#define B2IS21LDU	 BUFFER[74]	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define idB2IS21LDU	 35	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
#define B9IS21LDU	 BUFFER[76]	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define idB9IS21LDU	 36	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
#define B9IS11LDU	 BUFFER[78]	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define idB9IS11LDU	 37	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
#define A9IS21LDU	 BUFFER[80]	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define idA9IS21LDU	 38	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
#define A9IS11LDU	 BUFFER[82]	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define idA9IS11LDU	 39	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
#define B5IS21LDU	 BUFFER[84]	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define idB5IS21LDU	 40	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
#define B5IS11LDU	 BUFFER[86]	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define idB5IS11LDU	 41	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
#define A5IS21LDU	 BUFFER[88]	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define idA5IS21LDU	 42	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
#define A5IS11LDU	 BUFFER[90]	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define idA5IS11LDU	 43	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
#define B0VP81LZZ	 BUFFER[92]	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define idB0VP81LZZ	 44	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
#define A0VP81LZZ	 BUFFER[94]	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
#define idA0VP81LZZ	 45	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
#define B8IC01UDU	 BUFFER[96]	//( - , SDu) Координата АЗ2
#define idB8IC01UDU	 46	//( - , SDu) Координата АЗ2
#define A8IC01UDU	 BUFFER[101]	//( - , SDu) Координата ДС2
#define idA8IC01UDU	 47	//( - , SDu) Координата ДС2
#define R6IS68LZZ	 BUFFER[106]	//(do32_pti:100 - K19DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№7) ССДИ-2
#define idR6IS68LZZ	 48	//(do32_pti:100 - K19DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№7) ССДИ-2
#define R6IS67LZZ	 BUFFER[108]	//(do32_pti:100 - K18DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idR6IS67LZZ	 49	//(do32_pti:100 - K18DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№6) ССДИ-1-2
#define R6IS66LZZ	 BUFFER[110]	//(do32_pti:100 - K17DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idR6IS66LZZ	 50	//(do32_pti:100 - K17DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№5) ССДИ-1-1
#define R6IS65LDU	 BUFFER[112]	//(do32_pti:160 - K32DO, - ) Исправность ВИП ССДИ-35 2канал
#define idR6IS65LDU	 51	//(do32_pti:160 - K32DO, - ) Исправность ВИП ССДИ-35 2канал
#define R2IS11LDU	 BUFFER[114]	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define idR2IS11LDU	 52	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
#define R1IS21LDU	 BUFFER[116]	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define idR1IS21LDU	 53	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
#define R1IS11LDU	 BUFFER[118]	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define idR1IS11LDU	 54	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
#define B4IS21LDU	 BUFFER[120]	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define idB4IS21LDU	 55	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
#define B4IS11LDU	 BUFFER[122]	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define idB4IS11LDU	 56	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
#define R8IS11LDU	 BUFFER[124]	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define idR8IS11LDU	 57	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
#define A4IS21LDU	 BUFFER[126]	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define idA4IS21LDU	 58	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
#define A4IS11LDU	 BUFFER[128]	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define idA4IS11LDU	 59	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
#define R5IS21LDU	 BUFFER[130]	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define idR5IS21LDU	 60	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
#define R5IS11LDU	 BUFFER[132]	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define idR5IS11LDU	 61	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
#define R3IS21LDU	 BUFFER[134]	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define idR3IS21LDU	 62	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
#define R3IS11LDU	 BUFFER[136]	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define idR3IS11LDU	 63	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
#define B2VP82LDU	 BUFFER[138]	//( - , SDu) Давление ПОДЪЁМ РБ2 в норме
#define idB2VP82LDU	 64	//( - , SDu) Давление ПОДЪЁМ РБ2 в норме
#define B2IP01IZ2	 BUFFER[140]	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ2	 65	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
#define B2IP01IZ1	 BUFFER[143]	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define idB2IP01IZ1	 66	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
#define B2IC01UDU	 BUFFER[146]	//( - , SDu) Координата штока РБ2
#define idB2IC01UDU	 67	//( - , SDu) Координата штока РБ2
#define B2IS12LDU	 BUFFER[151]	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define idB2IS12LDU	 68	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
#define B2IS11LDU	 BUFFER[153]	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define idB2IS11LDU	 69	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
#define R0IN02FI3	 BUFFER[155]	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI3	 70	//( - , SA3) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI2	 BUFFER[160]	//( - , SA2) Выход КНК53М Гц от ПТИ
#define idR0IN03FI2	 71	//( - , SA2) Выход КНК53М Гц от ПТИ
#define R0IN07RIP	 BUFFER[165]	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define idR0IN07RIP	 72	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
#define R0IN06RIP	 BUFFER[170]	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define idR0IN06RIP	 73	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
#define TerR0IN06FRP	 BUFFER[175]	//( - , - ) Неисправности СНМ-11 -1,2
#define idTerR0IN06FRP	 74	//( - , - ) Неисправности СНМ-11 -1,2
#define R0IN03RIP	 BUFFER[178]	//( - , SRP) Выход КНК53М Гц от ПТИ
#define idR0IN03RIP	 75	//( - , SRP) Выход КНК53М Гц от ПТИ
#define R0IN02RIP	 BUFFER[183]	//( - , SRP) Выход КНК15- Гц от ПТИ
#define idR0IN02RIP	 76	//( - , SRP) Выход КНК15- Гц от ПТИ
#define R0IN01RIP	 BUFFER[188]	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define idR0IN01RIP	 77	//( - , SRP) Выход СНМ-11 Гц от ПТИ
#define R0IN02FI2	 BUFFER[193]	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI2	 78	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI1	 BUFFER[198]	//( - , SA1) Выход КНК53М Гц от ПТИ
#define idR0IN03FI1	 79	//( - , SA1) Выход КНК53М Гц от ПТИ
#define R0IN02FI1	 BUFFER[203]	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI1	 80	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define R0IN03FI4	 BUFFER[208]	//( - , SA4) Выход КНК53М Гц от ПТИ
#define idR0IN03FI4	 81	//( - , SA4) Выход КНК53М Гц от ПТИ
#define R0IN02FI4	 BUFFER[213]	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define idR0IN02FI4	 82	//( - , SA4) Выход КНК15-1 Гц от ПТИ
#define R0IN01FI3	 BUFFER[218]	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI3	 83	//( - , SA3) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI2	 BUFFER[223]	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define idR0IN01FI2	 84	//( - , SA2) Выход КНК15-1 Гц от ПТИ
#define R0IN01FI4	 BUFFER[228]	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define idR0IN01FI4	 85	//( - , SA4) Выход СНМ-11 Гц от ПТИ
#define R0IN01FI1	 BUFFER[233]	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define idR0IN01FI1	 86	//( - , SA1) Выход КНК15-1 Гц от ПТИ
#define B0SN07RIM	 BUFFER[238]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define idB0SN07RIM	 87	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ2
#define B0SN06RIM	 BUFFER[243]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define idB0SN06RIM	 88	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ2
#define B0SN05RIM	 BUFFER[248]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define idB0SN05RIM	 89	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ2
#define B0SN04RIM	 BUFFER[253]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define idB0SN04RIM	 90	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ2
#define B0SN03RIM	 BUFFER[258]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define idB0SN03RIM	 91	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ2
#define B0SN02RIM	 BUFFER[263]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define idB0SN02RIM	 92	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ2
#define A0SN07RIM	 BUFFER[268]	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define idA0SN07RIM	 93	//( - , SCM) Концентрация запаздывающих нейтронов 6-го типа AЗ1
#define A0SN06RIM	 BUFFER[273]	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define idA0SN06RIM	 94	//( - , SCM) Концентрация запаздывающих нейтронов 5-го типа AЗ1
#define A0SN05RIM	 BUFFER[278]	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define idA0SN05RIM	 95	//( - , SCM) Концентрация запаздывающих нейтронов 4-го типа AЗ1
#define A0SN04RIM	 BUFFER[283]	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define idA0SN04RIM	 96	//( - , SCM) Концентрация запаздывающих нейтронов 3-го типа AЗ1
#define A0SN03RIM	 BUFFER[288]	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define idA0SN03RIM	 97	//( - , SCM) Концентрация запаздывающих нейтронов 2-го типа AЗ1
#define A0SN02RIM	 BUFFER[293]	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define idA0SN02RIM	 98	//( - , SCM) Концентрация запаздывающих нейтронов 1-го типа AЗ1
#define R0MW11IP1	 BUFFER[298]	//( - , SCM) Переключатель ВЫСТРЕЛ
#define idR0MW11IP1	 99	//( - , SCM) Переключатель ВЫСТРЕЛ
#define R0IS01FI0	 BUFFER[301]	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define idR0IS01FI0	 100	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
#define A0IT03IRP	 BUFFER[304]	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define idA0IT03IRP	 101	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
#define B0IT03IRP	 BUFFER[307]	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define idB0IT03IRP	 102	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
#define R0IN03FI3	 BUFFER[310]	//( - , SA3) Выход КНК53М Гц от ПТИ
#define idR0IN03FI3	 103	//( - , SA3) Выход КНК53М Гц от ПТИ
#define A1VP81LZZ	 BUFFER[315]	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
#define idA1VP81LZZ	 104	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
#define B1VP81LZZ	 BUFFER[317]	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define idB1VP81LZZ	 105	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
#define B2IS33LDU	 BUFFER[319]	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define idB2IS33LDU	 106	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
#define A0VN01RIM	 BUFFER[321]	//( - , SCM) Период разгона  AЗ1
#define idA0VN01RIM	 107	//( - , SCM) Период разгона  AЗ1
#define B2IS32LIM	 BUFFER[326]	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define idB2IS32LIM	 108	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
#define B2IS11LIM	 BUFFER[328]	//( - , SCM) Магнит РБ2 обесточен
#define idB2IS11LIM	 109	//( - , SCM) Магнит РБ2 обесточен
#define A2IS32LIM	 BUFFER[330]	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define idA2IS32LIM	 110	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
#define A2IS11LIM	 BUFFER[332]	//( - , SCM) Магнит РБ1 обесточен
#define idA2IS11LIM	 111	//( - , SCM) Магнит РБ1 обесточен
#define B1IS32LIM	 BUFFER[334]	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define idB1IS32LIM	 112	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
#define B1IS11LIM	 BUFFER[336]	//( - , SCM) Магнит ББ2 обесточен
#define idB1IS11LIM	 113	//( - , SCM) Магнит ББ2 обесточен
#define A1IS32LIM	 BUFFER[338]	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define idA1IS32LIM	 114	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
#define A1IS11LIM	 BUFFER[340]	//( - , SCM) Магнит ББ1 обесточен
#define idA1IS11LIM	 115	//( - , SCM) Магнит ББ1 обесточен
#define A3AD34LDU	 BUFFER[342]	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define idA3AD34LDU	 116	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
#define R0IS02LDU	 BUFFER[344]	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define idR0IS02LDU	 117	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
#define R0EE04LZ2	 BUFFER[346]	//( - , SBz2) Питание  АКНП4  отключить
#define idR0EE04LZ2	 118	//( - , SBz2) Питание  АКНП4  отключить
#define R0EE03LZ2	 BUFFER[348]	//( - , SBz2) Питание  АКНП3  отключить
#define idR0EE03LZ2	 119	//( - , SBz2) Питание  АКНП3  отключить
#define R0EE02LZ2	 BUFFER[350]	//( - , SBz2) Питание  АКНП  отключить
#define idR0EE02LZ2	 120	//( - , SBz2) Питание  АКНП  отключить
#define B7AP31LDU	 BUFFER[352]	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define idB7AP31LDU	 121	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
#define A7AP31LDU	 BUFFER[354]	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define idA7AP31LDU	 122	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
#define R4VS12LDU	 BUFFER[356]	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define idR4VS12LDU	 123	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
#define R4VS22LDU	 BUFFER[358]	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define idR4VS22LDU	 124	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
#define R1VS12LDU	 BUFFER[360]	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define idR1VS12LDU	 125	//( - , SCM) Движение МДЗ1 в сторону ВУ
#define R2VS12LDU	 BUFFER[362]	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define idR2VS12LDU	 126	//( - , SCM) Движение МДЗ2 в сторону ВУ
#define R2VS22LDU	 BUFFER[364]	//( - , SCM) Движение МДЗ2 в сторону НУ
#define idR2VS22LDU	 127	//( - , SCM) Движение МДЗ2 в сторону НУ
#define R1VS22LDU	 BUFFER[366]	//( - , SCM) Движение МДЗ1 в сторону НУ
#define idR1VS22LDU	 128	//( - , SCM) Движение МДЗ1 в сторону НУ
#define B5VS12LDU	 BUFFER[368]	//( - , SCM) Движение НЛ2 в сторону ВУ
#define idB5VS12LDU	 129	//( - , SCM) Движение НЛ2 в сторону ВУ
#define B5VS22LDU	 BUFFER[370]	//( - , SCM) Движение НЛ2 в сторону НУ
#define idB5VS22LDU	 130	//( - , SCM) Движение НЛ2 в сторону НУ
#define A5VS12LDU	 BUFFER[372]	//( - , SCM) Движение НЛ1 в сторону ВУ
#define idA5VS12LDU	 131	//( - , SCM) Движение НЛ1 в сторону ВУ
#define A5VS22LDU	 BUFFER[374]	//( - , SCM) Движение НЛ1 в сторону НУ
#define idA5VS22LDU	 132	//( - , SCM) Движение НЛ1 в сторону НУ
#define B6VS12LDU	 BUFFER[376]	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define idB6VS12LDU	 133	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
#define B6VS22LDU	 BUFFER[378]	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define idB6VS22LDU	 134	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
#define A6VS12LDU	 BUFFER[380]	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define idA6VS12LDU	 135	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
#define A6VS22LDU	 BUFFER[382]	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define idA6VS22LDU	 136	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
#define B8IS21LDU	 BUFFER[384]	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define idB8IS21LDU	 137	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
#define B8IS11LDU	 BUFFER[386]	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define idB8IS11LDU	 138	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
#define B8AD20LDU	 BUFFER[388]	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define idB8AD20LDU	 139	//(vds32_pti:360 - K09VDSR, - ) Перемещение АЗ2 назад
#define B8AD10LDU	 BUFFER[390]	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define idB8AD10LDU	 140	//(vds32_pti:360 - K08VDSR, - ) Перемещение АЗ2 вперед
#define R4AD20LDU	 BUFFER[392]	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define idR4AD20LDU	 141	//(vds32_pti:360 - K07VDSR, - ) Перемещение тележки назад
#define R4AD10LDU	 BUFFER[394]	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define idR4AD10LDU	 142	//(vds32_pti:360 - K06VDSR, - ) Перемещение тележки вперед
#define B0SR01RIM	 BUFFER[396]	//( - , SCM) Текущая реактивность AЗ2
#define idB0SR01RIM	 143	//( - , SCM) Текущая реактивность AЗ2
#define B3AD33LDU	 BUFFER[401]	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define idB3AD33LDU	 144	//(vds32_pti:340 - K27VDSR, - ) Клапан ВЫСТРЕЛ ИС2 открыть (обесточить)
#define B3AD05LDU	 BUFFER[403]	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define idB3AD05LDU	 145	//(vds32_pti:360 - K23VDSR, - ) паритет команды на ИС2
#define B3AD04LDU	 BUFFER[405]	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define idB3AD04LDU	 146	//(vds32_pti:360 - K22VDSR, - ) 2-й бит скорости ИС2
#define B3AD03LDU	 BUFFER[407]	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define idB3AD03LDU	 147	//(vds32_pti:360 - K21VDSR, - ) 1-й бит скорости ИС2
#define B3AD02LDU	 BUFFER[409]	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define idB3AD02LDU	 148	//(vds32_pti:360 - K20VDSR, - ) 0-й бит скорости ИС2
#define B3AD01LDU	 BUFFER[411]	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define idB3AD01LDU	 149	//(vds32_pti:360 - K19VDSR, - ) Разрешение движения ИС2
#define B3AD21LDU	 BUFFER[413]	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define idB3AD21LDU	 150	//(vds32_pti:360 - K18VDSR, - ) Сигнал на перемещение ИС2 вниз
#define B3AD11LDU	 BUFFER[415]	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define idB3AD11LDU	 151	//(vds32_pti:360 - K17VDSR, - ) Сигнал на перемещение ИС2 вверх
#define A3AD33LDU	 BUFFER[417]	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define idA3AD33LDU	 152	//(vds32_pti:340 - K13VDSR, - ) Клапан ВЫСТРЕЛ  ИС1 открыть (обесточить)
#define A3AD05LDU	 BUFFER[419]	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define idA3AD05LDU	 153	//(vds32_pti:360 - K16VDSR, - ) паритет команды на ИС1
#define A3AD04LDU	 BUFFER[421]	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define idA3AD04LDU	 154	//(vds32_pti:360 - K15VDSR, - ) 2-й бит скорости ИС1
#define A3AD03LDU	 BUFFER[423]	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define idA3AD03LDU	 155	//(vds32_pti:360 - K14VDSR, - ) 1-й бит скорости ИС1
#define R0CR01RIM	 BUFFER[425]	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define idR0CR01RIM	 156	//( - , SCM) Коэффициент 12 связи АЗ1,2
#define B0SN08RIM	 BUFFER[430]	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define idB0SN08RIM	 157	//( - , SCM) Поток нейтронов AЗ2(нейтр/с)
#define A0SN08RIM	 BUFFER[435]	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define idA0SN08RIM	 158	//( - , SCM) Поток нейтронов AЗ1(нейтр/с)
#define B5AD20LDU	 BUFFER[440]	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define idB5AD20LDU	 159	//(vds32_pti:340 - K25VDSR, - ) Опустить НЛ2
#define B5AD10LDU	 BUFFER[442]	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define idB5AD10LDU	 160	//(vds32_pti:340 - K24VDSR, - ) Поднять НЛ2
#define A5AD20LDU	 BUFFER[444]	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define idA5AD20LDU	 161	//(vds32_pti:340 - K23VDSR, - ) Опустить НЛ1
#define A5AD10LDU	 BUFFER[446]	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define idA5AD10LDU	 162	//(vds32_pti:340 - K22VDSR, - ) Поднять НЛ1
#define R2AD20LDU	 BUFFER[448]	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define idR2AD20LDU	 163	//(vds32_pti:340 - K21VDSR, - ) Поднять МДЗ2
#define R2AD10LDU	 BUFFER[450]	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define idR2AD10LDU	 164	//(vds32_pti:340 - K20VDSR, - ) Опустить МДЗ2 в зону облучения
#define R1AD20LDU	 BUFFER[452]	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define idR1AD20LDU	 165	//(vds32_pti:340 - K19VDSR, - ) Поднять МДЗ1
#define R1AD10LDU	 BUFFER[454]	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define idR1AD10LDU	 166	//(vds32_pti:340 - K18VDSR, - ) Опустить МДЗ1 в зону облучения
#define B6AD20LDU	 BUFFER[456]	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define idB6AD20LDU	 167	//(vds32_pti:360 - K05VDSR, - ) Закрыть БЗ2
#define B6AD10LDU	 BUFFER[458]	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define idB6AD10LDU	 168	//(vds32_pti:360 - K04VDSR, - ) Открыть БЗ2
#define A6AD20LDU	 BUFFER[460]	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define idA6AD20LDU	 169	//(vds32_pti:360 - K03VDSR, - ) Закрыть БЗ1
#define A6AD10LDU	 BUFFER[462]	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define idA6AD10LDU	 170	//(vds32_pti:360 - K02VDSR, - ) Открыть БЗ1
#define A8AD20LDU	 BUFFER[464]	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define idA8AD20LDU	 171	//(vds32_pti:360 - K01VDSR, - ) Перемещение ДС2 назад
#define A8AD10LDU	 BUFFER[466]	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define idA8AD10LDU	 172	//(vds32_pti:340 - K32VDSR, - ) Перемещение ДС2 вперед
#define A2AD21LDU	 BUFFER[468]	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define idA2AD21LDU	 173	//(vds32_pti:310 - K10VDSR, - ) Сигнал на перемещение РБ1 вниз
#define A2AD11LDU	 BUFFER[470]	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define idA2AD11LDU	 174	//(vds32_pti:310 - K09VDSR, - ) Сигнал на перемещение РБ1 вверх
#define B1AD05LDU	 BUFFER[472]	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define idB1AD05LDU	 175	//(vds32_pti:310 - K08VDSR, - ) паритет команды на ББ2
#define B1AD04LDU	 BUFFER[474]	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define idB1AD04LDU	 176	//(vds32_pti:310 - K07VDSR, - ) 2-й бит скорости ББ2
#define B1AD03LDU	 BUFFER[476]	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define idB1AD03LDU	 177	//(vds32_pti:310 - K06VDSR, - ) 1-й бит скорости ББ2
#define B1AD02LDU	 BUFFER[478]	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define idB1AD02LDU	 178	//(vds32_pti:310 - K05VDSR, - ) 0-й бит скорости  ББ2
#define B1AD01LDU	 BUFFER[480]	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define idB1AD01LDU	 179	//(vds32_pti:310 - K04VDSR, - ) Разрешение движения ББ2
#define B1AD21LDU	 BUFFER[482]	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define idB1AD21LDU	 180	//(vds32_pti:310 - K03VDSR, - ) Сигнал на перемещение ББ2 вниз
#define B1AD11LDU	 BUFFER[484]	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define idB1AD11LDU	 181	//(vds32_pti:310 - K02VDSR, - ) Сигнал на перемещение ББ2 вверх
#define A1AD05LDU	 BUFFER[486]	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define idA1AD05LDU	 182	//(vds32_pti:310 - K01VDSR, - ) паритет команды на ББ1
#define A1AD04LDU	 BUFFER[488]	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define idA1AD04LDU	 183	//(vds32_pti:360 - K31VDSR, - ) 2-й бит скорости ББ1
#define A1AD03LDU	 BUFFER[490]	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define idA1AD03LDU	 184	//(vds32_pti:360 - K30VDSR, - ) 1-й бит скорости ББ1
#define A1AD02LDU	 BUFFER[492]	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define idA1AD02LDU	 185	//(vds32_pti:360 - K29VDSR, - ) 0-й бит скорости ББ1
#define A1AD01LDU	 BUFFER[494]	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define idA1AD01LDU	 186	//(vds32_pti:360 - K28VDSR, - ) Разрешение движения ББ1
#define A1AD21LDU	 BUFFER[496]	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define idA1AD21LDU	 187	//(vds32_pti:360 - K27VDSR, - ) Сигнал на перемещение ББ1 вниз
#define A1AD11LDU	 BUFFER[498]	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define idA1AD11LDU	 188	//(vds32_pti:360 - K26VDSR, - ) Сигнал на перемещение ББ1 вверх
#define A0SR01RIM	 BUFFER[500]	//( - , SCM) Текущая реактивность AЗ1
#define idA0SR01RIM	 189	//( - , SCM) Текущая реактивность AЗ1
#define A3AD02LDU	 BUFFER[505]	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define idA3AD02LDU	 190	//(vds32_pti:360 - K13VDSR, - ) 0-й бит скорости ИС1
#define A3AD01LDU	 BUFFER[507]	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define idA3AD01LDU	 191	//(vds32_pti:360 - K12VDSR, - ) Разрешение движения ИС1
#define A3AD21LDU	 BUFFER[509]	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define idA3AD21LDU	 192	//(vds32_pti:360 - K11VDSR, - ) Сигнал на перемещение ИС1 вниз
#define A3AD11LDU	 BUFFER[511]	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define idA3AD11LDU	 193	//(vds32_pti:360 - K10VDSR, - ) Сигнал на перемещение ИС1 вверх
#define B2AD33LDU	 BUFFER[513]	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define idB2AD33LDU	 194	//(vds32_pti:340 - K28VDSR, - ) Клапан (Подъем РБ2) закрыть (обесточить)
#define B2AD05LDU	 BUFFER[515]	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define idB2AD05LDU	 195	//(vds32_pti:310 - K22VDSR, - ) паритет команды на РБ2
#define B2AD04LDU	 BUFFER[517]	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define idB2AD04LDU	 196	//(vds32_pti:310 - K21VDSR, - ) 2-й бит скорости РБ2
#define B2AD03LDU	 BUFFER[519]	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define idB2AD03LDU	 197	//(vds32_pti:310 - K20VDSR, - ) 1-й бит скорости РБ2
#define B2AD02LDU	 BUFFER[521]	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define idB2AD02LDU	 198	//(vds32_pti:310 - K19VDSR, - ) 0-й бит скорости РБ2
#define B2AD01LDU	 BUFFER[523]	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define idB2AD01LDU	 199	//(vds32_pti:310 - K18VDSR, - ) Разрешение движения РБ2
#define B2AD21LDU	 BUFFER[525]	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define idB2AD21LDU	 200	//(vds32_pti:310 - K17VDSR, - ) Сигнал на перемещение РБ2 вниз
#define B2AD11LDU	 BUFFER[527]	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define idB2AD11LDU	 201	//(vds32_pti:310 - K16VDSR, - ) Сигнал на перемещение РБ2 вверх
#define A2AD33LDU	 BUFFER[529]	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define idA2AD33LDU	 202	//(vds32_pti:340 - K14VDSR, - ) Клапан (Подъем РБ1) закрыть (обесточить)
#define A2AD05LDU	 BUFFER[531]	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define idA2AD05LDU	 203	//(vds32_pti:310 - K15VDSR, - ) паритет команды на РБ1
#define A2AD04LDU	 BUFFER[533]	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define idA2AD04LDU	 204	//(vds32_pti:310 - K14VDSR, - ) 2-й бит скорости РБ1
#define A2AD03LDU	 BUFFER[535]	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define idA2AD03LDU	 205	//(vds32_pti:310 - K13VDSR, - ) 1-й бит скорости РБ1
#define A2AD02LDU	 BUFFER[537]	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define idA2AD02LDU	 206	//(vds32_pti:310 - K12VDSR, - ) 0-й бит скорости РБ1
#define A2AD01LDU	 BUFFER[539]	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define idA2AD01LDU	 207	//(vds32_pti:310 - K11VDSR, - ) Разрешение движения РБ1
#define A2IP01IZ2	 BUFFER[541]	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ2	 208	//(ao16_pti:320 - K06AO, - ) Текущее давление СБРОС РБ1
#define A2IP01IZ1	 BUFFER[544]	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define idA2IP01IZ1	 209	//(ao16_pti:320 - K02AO, - ) Текущее давление СБРОС РБ1
#define B3IS21LDU	 BUFFER[547]	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define idB3IS21LDU	 210	//(do32_pti:130 - K13DO, - ) Приход на НУ ИС2
#define A3IS21LDU	 BUFFER[549]	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define idA3IS21LDU	 211	//(do32_pti:140 - K06DO, - ) Приход на НУ ИС1
#define A2IS33LDU	 BUFFER[551]	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define idA2IS33LDU	 212	//( - , - ) Клапан (Подъём РБ1)  открыт (обесточен)
#define A2IC01UDU	 BUFFER[553]	//( - , SDu) Координата штока РБ1
#define idA2IC01UDU	 213	//( - , SDu) Координата штока РБ1
#define A2IS12LDU	 BUFFER[558]	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define idA2IS12LDU	 214	//(do32_pti:140 - K03DO, - ) Магнит РБ1 зацеплен
#define A2IS11LDU	 BUFFER[560]	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define idA2IS11LDU	 215	//(do32_pti:140 - K04DO, - ) Приход на ВУ РБ1
#define A2IS21LDU	 BUFFER[562]	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define idA2IS21LDU	 216	//(do32_pti:140 - K05DO, - ) Приход на НУ РБ1
#define B0IT02IZ2	 BUFFER[564]	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define idB0IT02IZ2	 217	//(ao16_pti:320 - K07AO, - ) Температура АЗ2-2
#define B0IT01IZ1	 BUFFER[567]	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define idB0IT01IZ1	 218	//(ao16_pti:320 - K03AO, - ) Температура АЗ2-1
#define A0IT02IZ2	 BUFFER[570]	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define idA0IT02IZ2	 219	//(ao16_pti:320 - K05AO, - ) Температура АЗ1-2
#define A0IT01IZ1	 BUFFER[573]	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define idA0IT01IZ1	 220	//(ao16_pti:320 - K01AO, - ) Температура АЗ1-1
#define R6IS21LDU	 BUFFER[576]	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define idR6IS21LDU	 221	//(do32_pti:150 - K14DO, - ) Кран-балка в нерабочем положении
#define B7AS31LDU	 BUFFER[578]	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define idB7AS31LDU	 222	//(do32_pti:130 - K06DO, - ) Клапан (Обдув АЗ2) открыт (обесточен)
#define A7AS31LDU	 BUFFER[580]	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define idA7AS31LDU	 223	//(do32_pti:130 - K31DO, - ) Клапан (Обдув АЗ1) открыт (обесточен)
#define B3IS35LDU	 BUFFER[582]	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define idB3IS35LDU	 224	//( - , - ) Клапан «ВПИС2» открыт(обесточен)
#define R6IS64LDU	 BUFFER[584]	//(do32_pti:160 - K31DO, - ) Исправность ВИП ССДИ-35 1канал
#define idR6IS64LDU	 225	//(do32_pti:160 - K31DO, - ) Исправность ВИП ССДИ-35 1канал
#define R6IS63LDU	 BUFFER[586]	//(do32_pti:160 - K30DO, - ) Исправность ВИП ССДИ-39 2канал
#define idR6IS63LDU	 226	//(do32_pti:160 - K30DO, - ) Исправность ВИП ССДИ-39 2канал
#define R6IS62LDU	 BUFFER[588]	//(do32_pti:160 - K29DO, - ) Исправность ВИП ССДИ-39 1канал
#define idR6IS62LDU	 227	//(do32_pti:160 - K29DO, - ) Исправность ВИП ССДИ-39 1канал
#define B3IS22LDU	 BUFFER[590]	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define idB3IS22LDU	 228	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
#define A3IS22LDU	 BUFFER[592]	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
#define idA3IS22LDU	 229	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
#define B3IS11LDU	 BUFFER[594]	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define idB3IS11LDU	 230	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
#define A3IS11LDU	 BUFFER[596]	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
#define idA3IS11LDU	 231	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
#define A3IP02IDU	 BUFFER[598]	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define idA3IP02IDU	 232	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
#define B3VP81LDU	 BUFFER[601]	//( - , SDu) Давление СПУСК ИС2 в норме
#define idB3VP81LDU	 233	//( - , SDu) Давление СПУСК ИС2 в норме
#define A3VP81LDU	 BUFFER[603]	//( - , SDu) Давление СПУСК ИС1 в норме
#define idA3VP81LDU	 234	//( - , SDu) Давление СПУСК ИС1 в норме
#define B3IS33LDU	 BUFFER[605]	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idB3IS33LDU	 235	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define B3IC01UDU	 BUFFER[607]	//( - , SDu) Координата штока ИС2
#define idB3IC01UDU	 236	//( - , SDu) Координата штока ИС2
#define B3IS31LDU	 BUFFER[612]	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define idB3IS31LDU	 237	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
#define B3IP02IDU	 BUFFER[614]	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define idB3IP02IDU	 238	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
#define A3IS33LDU	 BUFFER[617]	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define idA3IS33LDU	 239	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
#define A3IC01UDU	 BUFFER[619]	//( - , SDu) Координата штока ИС1
#define idA3IC01UDU	 240	//( - , SDu) Координата штока ИС1
#define A3IS31LDU	 BUFFER[624]	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define idA3IS31LDU	 241	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
#define A2VP82LDU	 BUFFER[626]	//( - , SDu) Давление ПОДЪЁМ РБ1 в норме
#define idA2VP82LDU	 242	//( - , SDu) Давление ПОДЪЁМ РБ1 в норме
#define B2AD31LDU	 BUFFER[628]	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define idB2AD31LDU	 243	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
#define B1AD32LDU	 BUFFER[630]	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define idB1AD32LDU	 244	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
#define B1AD31LDU	 BUFFER[632]	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define idB1AD31LDU	 245	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
#define A3AD31LDU	 BUFFER[634]	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define idA3AD31LDU	 246	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
#define C1MD31LP1	 BUFFER[636]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define idC1MD31LP1	 247	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
#define C1MD31LP2	 BUFFER[638]	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define idC1MD31LP2	 248	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
#define A1AD31LDU	 BUFFER[640]	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define idA1AD31LDU	 249	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
#define A1AD32LDU	 BUFFER[642]	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define idA1AD32LDU	 250	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
#define A2AD31LDU	 BUFFER[644]	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define idA2AD31LDU	 251	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
#define C2MD31LP1	 BUFFER[646]	//( - , SCM) Кнопка «СБРОС РБ»
#define idC2MD31LP1	 252	//( - , SCM) Кнопка «СБРОС РБ»
#define A2AD32LDU	 BUFFER[648]	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define idA2AD32LDU	 253	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
#define R0VZ71LZ2	 BUFFER[650]	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define idR0VZ71LZ2	 254	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
#define R0VZ71LZ1	 BUFFER[652]	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define idR0VZ71LZ1	 255	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
#define R8AD21LDU	 BUFFER[654]	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
#define idR8AD21LDU	 256	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
#define R0AD14LDU	 BUFFER[656]	//( - , SCM) Имитация срабатывания верхней АС II УР
#define idR0AD14LDU	 257	//( - , SCM) Имитация срабатывания верхней АС II УР
#define R0SR02RIM	 BUFFER[658]	//( - , SCM) Текущая мощность РУ (ватт)
#define idR0SR02RIM	 258	//( - , SCM) Текущая мощность РУ (ватт)
#define R0CR02RIM	 BUFFER[663]	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define idR0CR02RIM	 259	//( - , SCM) Коэффициент 11 связи АЗ1,2
#define B3AD34LDU	 BUFFER[668]	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define idB3AD34LDU	 260	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
#define A3IS35LDU	 BUFFER[670]	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define idA3IS35LDU	 261	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
#define R7II73LZ2	 BUFFER[672]	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ2	 262	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
#define R7II71LZ2	 BUFFER[674]	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ2	 263	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II72LZ2	 BUFFER[676]	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ2	 264	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R0AD16LDU	 BUFFER[678]	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define idR0AD16LDU	 265	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
#define R7II72LZ1	 BUFFER[680]	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
#define idR7II72LZ1	 266	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
#define R7II71LZ1	 BUFFER[682]	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
#define idR7II71LZ1	 267	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
#define R7II73LZ1	 BUFFER[684]	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
#define idR7II73LZ1	 268	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
#define R0SR01RIM	 BUFFER[686]	//( - , SCM) Текущая реактивность PУ
#define idR0SR01RIM	 269	//( - , SCM) Текущая реактивность PУ
#define R0ST01RIM	 BUFFER[691]	//( - , SCM) Текущий период разгона РУ
#define idR0ST01RIM	 270	//( - , SCM) Текущий период разгона РУ
#define A4AD10LDU	 BUFFER[696]	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define idA4AD10LDU	 271	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
#define B4AD10LDU	 BUFFER[698]	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define idB4AD10LDU	 272	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
#define A9AD10LDU	 BUFFER[700]	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define idA9AD10LDU	 273	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
#define B9AD10LDU	 BUFFER[702]	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define idB9AD10LDU	 274	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
#define R0MW13LP2	 BUFFER[704]	//( - , SCM) Переключатель «СЕТЬ»
#define idR0MW13LP2	 275	//( - , SCM) Переключатель «СЕТЬ»
#define B3AD31LDU	 BUFFER[706]	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define idB3AD31LDU	 276	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
#define B2AD32LDU	 BUFFER[708]	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define idB2AD32LDU	 277	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
#define fEM_R0UL01RIM	 BUFFER[710]	//(R0UL01RIM) Среднее время генерации нейтронов
#define idfEM_R0UL01RIM	 278	//(R0UL01RIM) Среднее время генерации нейтронов
#define fEM_R0UN02RIM	 BUFFER[715]	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define idfEM_R0UN02RIM	 279	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
#define fEM_A1UR01RIM	 BUFFER[720]	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR01RIM	 280	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
#define fEM_A1UR00RIM	 BUFFER[725]	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define idfEM_A1UR00RIM	 281	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
#define fEM_A3UR00RIM	 BUFFER[730]	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR00RIM	 282	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
#define fEM_A3UR01RIM	 BUFFER[735]	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define idfEM_A3UR01RIM	 283	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
#define fEM_R0UT01RIM	 BUFFER[740]	//(R0UT01RIM) Температурный коэффициент (долл)
#define idfEM_R0UT01RIM	 284	//(R0UT01RIM) Температурный коэффициент (долл)
#define fEM_R0UT02RIM	 BUFFER[745]	//(R0UT02RIM) Масса топлива в АЗ
#define idfEM_R0UT02RIM	 285	//(R0UT02RIM) Масса топлива в АЗ
#define fEM_R0UT04RIM	 BUFFER[750]	//(R0UT04RIM) Удельная теплоёмкость топлива
#define idfEM_R0UT04RIM	 286	//(R0UT04RIM) Удельная теплоёмкость топлива
#define fEM_R0UT03RIM	 BUFFER[755]	//(R0UT03RIM) Нормальная температура АЗ град
#define idfEM_R0UT03RIM	 287	//(R0UT03RIM) Нормальная температура АЗ град
#define fEM_R0UT05RIM	 BUFFER[760]	//(R0UT05RIM) Энергия деления ядра
#define idfEM_R0UT05RIM	 288	//(R0UT05RIM) Энергия деления ядра
#define fEM_R0UT06RIM	 BUFFER[765]	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define idfEM_R0UT06RIM	 289	//(R0UT06RIM) Конвекционное сопротивление при обдуве
#define fEM_A1UC02RDU	 BUFFER[770]	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define idfEM_A1UC02RDU	 290	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
#define fEM_A1UC04RIM	 BUFFER[775]	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define idfEM_A1UC04RIM	 291	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
#define fEM_A1UC05RIM	 BUFFER[780]	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define idfEM_A1UC05RIM	 292	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
#define fEM_A1UC06RIM	 BUFFER[785]	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define idfEM_A1UC06RIM	 293	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
#define fEM_A2UC06RIM	 BUFFER[790]	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define idfEM_A2UC06RIM	 294	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
#define fEM_A2UC05RIM	 BUFFER[795]	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define idfEM_A2UC05RIM	 295	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
#define fEM_A2UC04RIM	 BUFFER[800]	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define idfEM_A2UC04RIM	 296	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
#define fEM_A2UC02RDU	 BUFFER[805]	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define idfEM_A2UC02RDU	 297	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
#define fEM_A3UC06RIM	 BUFFER[810]	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define idfEM_A3UC06RIM	 298	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
#define fEM_A3UC05RIM	 BUFFER[815]	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define idfEM_A3UC05RIM	 299	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
#define fEM_A3UC04RIM	 BUFFER[820]	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define idfEM_A3UC04RIM	 300	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
#define fEM_A3UC02RDU	 BUFFER[825]	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define idfEM_A3UC02RDU	 301	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
#define fEM_R4UV80RDU	 BUFFER[830]	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define idfEM_R4UV80RDU	 302	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
#define fEM_R4UC10RIM	 BUFFER[835]	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define idfEM_R4UC10RIM	 303	//(R4UC10RIM) Координата верхних механических упоров тележки мм
#define fEM_R4UC20RIM	 BUFFER[840]	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define idfEM_R4UC20RIM	 304	//(R4UC20RIM) Координата нижних механических упоров тележки мм
#define fEM_B8UC21RIM	 BUFFER[845]	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define idfEM_B8UC21RIM	 305	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
#define fEM_B8UC20RIM	 BUFFER[850]	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define idfEM_B8UC20RIM	 306	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
#define fEM_B8UC11RIM	 BUFFER[855]	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define idfEM_B8UC11RIM	 307	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
#define fEM_B8UC10RIM	 BUFFER[860]	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define idfEM_B8UC10RIM	 308	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
#define fEM_B8UV80RDU	 BUFFER[865]	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define idfEM_B8UV80RDU	 309	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
#define fEM_A8UV80RDU	 BUFFER[870]	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define idfEM_A8UV80RDU	 310	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
#define fEM_A8UC10RIM	 BUFFER[875]	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define idfEM_A8UC10RIM	 311	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
#define fEM_A8UC11RIM	 BUFFER[880]	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define idfEM_A8UC11RIM	 312	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
#define fEM_A8UC20RIM	 BUFFER[885]	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define idfEM_A8UC20RIM	 313	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
#define fEM_A8UC21RIM	 BUFFER[890]	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define idfEM_A8UC21RIM	 314	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
#define fEM_A6UC10RIM	 BUFFER[895]	//(A6UC10RIM) Время полного хода БЗ (сек)
#define idfEM_A6UC10RIM	 315	//(A6UC10RIM) Время полного хода БЗ (сек)
#define fEM_R1UC10RIM	 BUFFER[900]	//(R1UC10RIM) Время полного хода МДЗ сек
#define idfEM_R1UC10RIM	 316	//(R1UC10RIM) Время полного хода МДЗ сек
#define fEM_A5UC10RIM	 BUFFER[905]	//(A5UC10RIM) Время полного хода НЛ сек
#define idfEM_A5UC10RIM	 317	//(A5UC10RIM) Время полного хода НЛ сек
#define fEM_A0UN01RIM	 BUFFER[910]	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define idfEM_A0UN01RIM	 318	//(A0UN01RIM) Мощность источника нейтронов ИНИ
#define fEM_R4UC22RIM	 BUFFER[915]	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define idfEM_R4UC22RIM	 319	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
#define fEM_A1UG01RDU	 BUFFER[920]	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define idfEM_A1UG01RDU	 320	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
#define fEM_A2UG01RDU	 BUFFER[925]	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define idfEM_A2UG01RDU	 321	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
#define fEM_A3UG01RDU	 BUFFER[930]	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define idfEM_A3UG01RDU	 322	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
#define fEM_R7UC10RIM	 BUFFER[935]	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define idfEM_R7UC10RIM	 323	//(R7UC10RIM) X-координата КНК53М R7IN13 см
#define fEM_R7UC19RIM	 BUFFER[940]	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define idfEM_R7UC19RIM	 324	//(R7UC19RIM) Y-координата СНМ-11 (11) см
#define fEM_R7UI02RIM	 BUFFER[945]	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define idfEM_R7UI02RIM	 325	//(R7UI02RIM) Коэффициент усиления уровня радиации
#define fEM_R7UL01RIM	 BUFFER[950]	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define idfEM_R7UL01RIM	 326	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
#define fEM_A2UR00RIM	 BUFFER[955]	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define idfEM_A2UR00RIM	 327	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
#define fEM_A2UR01RIM	 BUFFER[960]	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define idfEM_A2UR01RIM	 328	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
#define fEM_A0UN02RIM	 BUFFER[965]	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define idfEM_A0UN02RIM	 329	//(A0UN02RIM) Мощность источника нейтронов с АНИ
#define fEM_R0UR30RIM	 BUFFER[970]	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define idfEM_R0UR30RIM	 330	//(R0UR30RIM) Реактивность вносимая образцами (долл)
#define fEM_R0UR01RIM	 BUFFER[975]	//(R0UR01RIM) Стартовая отрицательная реактивность
#define idfEM_R0UR01RIM	 331	//(R0UR01RIM) Стартовая отрицательная реактивность
#define fEM_R0UT02RDU	 BUFFER[980]	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define idfEM_R0UT02RDU	 332	//(R0UT02RDU) Верхний предел шкалы датчика температуры
#define fEM_R0UT01RDU	 BUFFER[985]	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define idfEM_R0UT01RDU	 333	//(R0UT01RDU) Нижний предел шкалы датчика температуры
#define fEM_A1UC03RDU	 BUFFER[990]	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define idfEM_A1UC03RDU	 334	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
#define fEM_A2UP03RDU	 BUFFER[995]	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP03RDU	 335	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UP04RDU	 BUFFER[1000]	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define idfEM_A2UP04RDU	 336	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
#define fEM_A2UC03RDU	 BUFFER[1005]	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define idfEM_A2UC03RDU	 337	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
#define fEM_A3UP03RDU	 BUFFER[1010]	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP03RDU	 338	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UP04RDU	 BUFFER[1015]	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define idfEM_A3UP04RDU	 339	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
#define fEM_A3UC03RDU	 BUFFER[1020]	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define idfEM_A3UC03RDU	 340	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
#define fEM_R7UI74RIM	 BUFFER[1025]	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define idfEM_R7UI74RIM	 341	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
#define fEM_A8UC03RDU	 BUFFER[1030]	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define idfEM_A8UC03RDU	 342	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
#define fEM_R0UV87RDU	 BUFFER[1035]	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV87RDU	 343	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV81RDU	 BUFFER[1040]	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define idfEM_R0UV81RDU	 344	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
#define fEM_R0UV82RDU	 BUFFER[1045]	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define idfEM_R0UV82RDU	 345	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
#define fEM_R0UV83RDU	 BUFFER[1050]	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define idfEM_R0UV83RDU	 346	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
#define fEM_R0UV84RDU	 BUFFER[1055]	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define idfEM_R0UV84RDU	 347	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
#define fEM_R0UV85RDU	 BUFFER[1060]	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV85RDU	 348	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
#define fEM_R0UV86RDU	 BUFFER[1065]	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define idfEM_R0UV86RDU	 349	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
#define fEM_A8UC08RDU	 BUFFER[1070]	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define idfEM_A8UC08RDU	 350	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
#define fEM_B8UC08RDU	 BUFFER[1075]	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define idfEM_B8UC08RDU	 351	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
#define fEM_R4UC08RDU	 BUFFER[1080]	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define idfEM_R4UC08RDU	 352	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
#define fEM_R0UH01RSS	 BUFFER[1085]	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define idfEM_R0UH01RSS	 353	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
#define fEM_A0UX00RSS	 BUFFER[1090]	//(A0UX00RSS) Эффективный радиус АЗ
#define idfEM_A0UX00RSS	 354	//(A0UX00RSS) Эффективный радиус АЗ
#define fEM_R7UX01RSS	 BUFFER[1095]	//(R7UX01RSS) X-координата камеры R7IN11
#define idfEM_R7UX01RSS	 355	//(R7UX01RSS) X-координата камеры R7IN11
#define fEM_R7UX02RSS	 BUFFER[1100]	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define idfEM_R7UX02RSS	 356	//(R7UX02RSS) X-координата камеры R7IN12 (см)
#define fEM_R7UX04RSS	 BUFFER[1105]	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define idfEM_R7UX04RSS	 357	//(R7UX04RSS) X-координата камеры R7IN21 (см)
#define fEM_R7UX05RSS	 BUFFER[1110]	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define idfEM_R7UX05RSS	 358	//(R7UX05RSS) X-координата камеры R7IN22 (см)
#define fEM_R7UX06RSS	 BUFFER[1115]	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define idfEM_R7UX06RSS	 359	//(R7UX06RSS) X-координата камеры R7IN23 (см)
#define fEM_R7UX07RSS	 BUFFER[1120]	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define idfEM_R7UX07RSS	 360	//(R7UX07RSS) X-координата камеры R7IN31 (см)
#define fEM_R7UX08RSS	 BUFFER[1125]	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define idfEM_R7UX08RSS	 361	//(R7UX08RSS) X-координата камеры R7IN32 (см)
#define fEM_R7UX09RSS	 BUFFER[1130]	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define idfEM_R7UX09RSS	 362	//(R7UX09RSS) X-координата камеры R7IN33 (см)
#define fEM_R7UY01RSS	 BUFFER[1135]	//(R7UY01RSS) Y-координата камеры R7IN11
#define idfEM_R7UY01RSS	 363	//(R7UY01RSS) Y-координата камеры R7IN11
#define fEM_R7UY02RSS	 BUFFER[1140]	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define idfEM_R7UY02RSS	 364	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
#define fEM_R7UY04RSS	 BUFFER[1145]	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define idfEM_R7UY04RSS	 365	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
#define fEM_R7UY05RSS	 BUFFER[1150]	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define idfEM_R7UY05RSS	 366	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
#define fEM_R7UY06RSS	 BUFFER[1155]	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define idfEM_R7UY06RSS	 367	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
#define fEM_R7UY07RSS	 BUFFER[1160]	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define idfEM_R7UY07RSS	 368	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
#define fEM_R7UY08RSS	 BUFFER[1165]	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define idfEM_R7UY08RSS	 369	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
#define fEM_R7UY09RSS	 BUFFER[1170]	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define idfEM_R7UY09RSS	 370	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
#define fEM_R7UX10RSS	 BUFFER[1175]	//(R7UX10RSS) X-координата камеры R7IN41
#define idfEM_R7UX10RSS	 371	//(R7UX10RSS) X-координата камеры R7IN41
#define fEM_R7UX11RSS	 BUFFER[1180]	//(R7UX11RSS) X-координата камеры R7IN42
#define idfEM_R7UX11RSS	 372	//(R7UX11RSS) X-координата камеры R7IN42
#define fEM_R7UX12RSS	 BUFFER[1185]	//(R7UX12RSS) X-координата камеры R7IN43
#define idfEM_R7UX12RSS	 373	//(R7UX12RSS) X-координата камеры R7IN43
#define fEM_R7UY10RSS	 BUFFER[1190]	//(R7UY10RSS) Y-координата камеры R7IN41
#define idfEM_R7UY10RSS	 374	//(R7UY10RSS) Y-координата камеры R7IN41
#define fEM_R7UY11RSS	 BUFFER[1195]	//(R7UY11RSS) Y-координата камеры R7IN42
#define idfEM_R7UY11RSS	 375	//(R7UY11RSS) Y-координата камеры R7IN42
#define fEM_R7UY12RSS	 BUFFER[1200]	//(R7UY12RSS) Y-координата камеры R7IN43
#define idfEM_R7UY12RSS	 376	//(R7UY12RSS) Y-координата камеры R7IN43
#define fEM_A0UX01RSS	 BUFFER[1205]	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define idfEM_A0UX01RSS	 377	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
#define fEM_A0UX02RSS	 BUFFER[1210]	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define idfEM_A0UX02RSS	 378	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
#define fEM_A0UX03RSS	 BUFFER[1215]	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define idfEM_A0UX03RSS	 379	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
#define fEM_A0UX04RSS	 BUFFER[1220]	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define idfEM_A0UX04RSS	 380	//(A0UX04RSS) Первый коэффициент калибровки камеры4
#define fEM_A0UX05RSS	 BUFFER[1225]	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define idfEM_A0UX05RSS	 381	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
#define fEM_A0UX06RSS	 BUFFER[1230]	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define idfEM_A0UX06RSS	 382	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
#define fEM_A0UX07RSS	 BUFFER[1235]	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define idfEM_A0UX07RSS	 383	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
#define fEM_A0UX08RSS	 BUFFER[1240]	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define idfEM_A0UX08RSS	 384	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
#define fEM_A0UX09RSS	 BUFFER[1245]	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define idfEM_A0UX09RSS	 385	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
#define fEM_A0UX10RSS	 BUFFER[1250]	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define idfEM_A0UX10RSS	 386	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
#define fEM_A0UX11RSS	 BUFFER[1255]	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define idfEM_A0UX11RSS	 387	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
#define fEM_A0UX12RSS	 BUFFER[1260]	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define idfEM_A0UX12RSS	 388	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
#define fEM_B0UX01RSS	 BUFFER[1265]	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define idfEM_B0UX01RSS	 389	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
#define fEM_B0UX02RSS	 BUFFER[1270]	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define idfEM_B0UX02RSS	 390	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
#define fEM_B0UX03RSS	 BUFFER[1275]	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define idfEM_B0UX03RSS	 391	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
#define fEM_B0UX04RSS	 BUFFER[1280]	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define idfEM_B0UX04RSS	 392	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
#define fEM_B0UX05RSS	 BUFFER[1285]	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define idfEM_B0UX05RSS	 393	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
#define fEM_B0UX06RSS	 BUFFER[1290]	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define idfEM_B0UX06RSS	 394	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
#define fEM_B0UX07RSS	 BUFFER[1295]	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define idfEM_B0UX07RSS	 395	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
#define fEM_B0UX08RSS	 BUFFER[1300]	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define idfEM_B0UX08RSS	 396	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
#define fEM_B0UX09RSS	 BUFFER[1305]	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define idfEM_B0UX09RSS	 397	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
#define fEM_B0UX10RSS	 BUFFER[1310]	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define idfEM_B0UX10RSS	 398	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
#define fEM_B0UX11RSS	 BUFFER[1315]	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define idfEM_B0UX11RSS	 399	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
#define fEM_B0UX12RSS	 BUFFER[1320]	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define idfEM_B0UX12RSS	 400	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
#define fEM_R0UH02RSS	 BUFFER[1325]	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define idfEM_R0UH02RSS	 401	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
#define fEM_R0UH03RSS	 BUFFER[1330]	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define idfEM_R0UH03RSS	 402	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
#define fEM_R4US80RDU	 BUFFER[1335]	//(R4US80RDU) Тормозной путь тележки (мм)
#define idfEM_R4US80RDU	 403	//(R4US80RDU) Тормозной путь тележки (мм)
#define fEM_R7UI71RIM	 BUFFER[1340]	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define idfEM_R7UI71RIM	 404	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
#define fEM_R7UI72RIM	 BUFFER[1345]	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define idfEM_R7UI72RIM	 405	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
#define fEM_R7UI73RIM	 BUFFER[1350]	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define idfEM_R7UI73RIM	 406	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
#define fEM_A1UP01RIM	 BUFFER[1355]	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define idfEM_A1UP01RIM	 407	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
#define fEM_A2UP01RIM	 BUFFER[1360]	//(A2UP01RIM) Текущее давление на сброс РБ
#define idfEM_A2UP01RIM	 408	//(A2UP01RIM) Текущее давление на сброс РБ
#define fEM_A0UP02RIM	 BUFFER[1365]	//(A0UP02RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP02RIM	 409	//(A0UP02RIM) Текущее давление в АЗ1,2
#define fEM_A3UP01RIM	 BUFFER[1370]	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define idfEM_A3UP01RIM	 410	//(A3UP01RIM) Текущее давление на СПУСК ИС
#define fEM_A1UP82RIM	 BUFFER[1375]	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define idfEM_A1UP82RIM	 411	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
#define fEM_A3UP02RDU	 BUFFER[1380]	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define idfEM_A3UP02RDU	 412	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
#define fEM_A1UV02RIM	 BUFFER[1385]	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define idfEM_A1UV02RIM	 413	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
#define fEM_A3UV02RIM	 BUFFER[1390]	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define idfEM_A3UV02RIM	 414	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
#define fEM_A2UV02RIM	 BUFFER[1395]	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define idfEM_A2UV02RIM	 415	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
#define fEM_B8US80RDU	 BUFFER[1400]	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define idfEM_B8US80RDU	 416	//(B8US80RDU) Тормозной путь АЗ2 (мм)
#define fEM_A8US80RDU	 BUFFER[1405]	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define idfEM_A8US80RDU	 417	//(A8US80RDU) Тормозной путь ДС2 (мм)
#define fEM_A6US80RDU	 BUFFER[1410]	//(A6US80RDU) Тормозной путь БЗ (мм)
#define idfEM_A6US80RDU	 418	//(A6US80RDU) Тормозной путь БЗ (мм)
#define fEM_A1US07RDU	 BUFFER[1415]	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define idfEM_A1US07RDU	 419	//(A1US07RDU) Постоянная времени масляного демпфера ББ
#define fEM_A2US07RDU	 BUFFER[1420]	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define idfEM_A2US07RDU	 420	//(A2US07RDU) Постоянная времени масляного демпфера РБ
#define fEM_A3US07RDU	 BUFFER[1425]	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define idfEM_A3US07RDU	 421	//(A3US07RDU) Постоянная времени масляного демпфера ИС
#define fEM_R7UI75RIM	 BUFFER[1430]	//(R7UI75RIM) Множитель к уровню радиации
#define idfEM_R7UI75RIM	 422	//(R7UI75RIM) Множитель к уровню радиации
#define fEM_R0UH21RSS	 BUFFER[1435]	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define idfEM_R0UH21RSS	 423	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
#define fEM_R0UH22RSS	 BUFFER[1440]	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define idfEM_R0UH22RSS	 424	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
#define fEM_R0UH23RSS	 BUFFER[1445]	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define idfEM_R0UH23RSS	 425	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
#define fEM_R0UH05RSS	 BUFFER[1450]	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define idfEM_R0UH05RSS	 426	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
#define fEM_A4UL10RIM	 BUFFER[1455]	//(A4UL10RIM) Время полного перемещения НИ сек
#define idfEM_A4UL10RIM	 427	//(A4UL10RIM) Время полного перемещения НИ сек
#define fEM_A9UL10RIM	 BUFFER[1460]	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define idfEM_A9UL10RIM	 428	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
#define fEM_R3UL10RIM	 BUFFER[1465]	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define idfEM_R3UL10RIM	 429	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
#define fEM_R5UL10RIM	 BUFFER[1470]	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define idfEM_R5UL10RIM	 430	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
#define fEM_R6UL10RIM	 BUFFER[1475]	//(R6UL10RIM) Время полного хода кран-балки сек
#define idfEM_R6UL10RIM	 431	//(R6UL10RIM) Время полного хода кран-балки сек
#define lEM_C1AD31LRP	 BUFFER[1480]	//(C1AD31LRP) Общий сброс от РПУ
#define idlEM_C1AD31LRP	 432	//(C1AD31LRP) Общий сброс от РПУ
#define lEM_R0IE01LRP	 BUFFER[1482]	//(R0IE01LRP) Отключение питание детекторов
#define idlEM_R0IE01LRP	 433	//(R0IE01LRP) Отключение питание детекторов
#define lEM_R0IE02LRP	 BUFFER[1484]	//(R0IE02LRP) Отключить питание ПР, ПУ
#define idlEM_R0IE02LRP	 434	//(R0IE02LRP) Отключить питание ПР, ПУ
#define fEM_A2UP02RIM	 BUFFER[1486]	//(A2UP02RIM) Текущее давление на подъём РБ
#define idfEM_A2UP02RIM	 435	//(A2UP02RIM) Текущее давление на подъём РБ
#define fEM_A2UP03RIM	 BUFFER[1491]	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define idfEM_A2UP03RIM	 436	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
#define fEM_A0UP01RIM	 BUFFER[1496]	//(A0UP01RIM) Текущее давление в АЗ1,2
#define idfEM_A0UP01RIM	 437	//(A0UP01RIM) Текущее давление в АЗ1,2
#define fEM_A3UP02RIM	 BUFFER[1501]	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define idfEM_A3UP02RIM	 438	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
#define fEM_A4UP01RIM	 BUFFER[1506]	//(A4UP01RIM) Текущее давление на подъём НИ
#define idfEM_A4UP01RIM	 439	//(A4UP01RIM) Текущее давление на подъём НИ
#define fEM_A4UP02RIM	 BUFFER[1511]	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define idfEM_A4UP02RIM	 440	//(A4UP02RIM) Нижняя граница давления на подъём НИ
#define fEM_R7UI76RIM	 BUFFER[1516]	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define idfEM_R7UI76RIM	 441	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
#define fEM_R7UI77RIM	 BUFFER[1521]	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define idfEM_R7UI77RIM	 442	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
#define iEM_TERBB1	 BUFFER[1526]	//(TERBB1) Неисправности  ББ1
#define idiEM_TERBB1	 443	//(TERBB1) Неисправности  ББ1
#define fEM_A1MC02RC1	 BUFFER[1529]	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define idfEM_A1MC02RC1	 444	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
#define fEM_A1MV02RC1	 BUFFER[1534]	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define idfEM_A1MV02RC1	 445	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
#define iEM_TERBB2	 BUFFER[1539]	//(TERBB2) Неисправности  ББ2
#define idiEM_TERBB2	 446	//(TERBB2) Неисправности  ББ2
#define fEM_B1MC02RC1	 BUFFER[1542]	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define idfEM_B1MC02RC1	 447	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
#define fEM_B1MV02RC1	 BUFFER[1547]	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define idfEM_B1MV02RC1	 448	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
#define iEM_TERRB2	 BUFFER[1552]	//(TERRB2) Неисправности  РБ2
#define idiEM_TERRB2	 449	//(TERRB2) Неисправности  РБ2
#define fEM_B2MC02RC1	 BUFFER[1555]	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define idfEM_B2MC02RC1	 450	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
#define fEM_B2MV02RC1	 BUFFER[1560]	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define idfEM_B2MV02RC1	 451	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
#define iEM_TERRB1	 BUFFER[1565]	//(TERRB1) Неисправности  РБ1
#define idiEM_TERRB1	 452	//(TERRB1) Неисправности  РБ1
#define fEM_A2MC02RC1	 BUFFER[1568]	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define idfEM_A2MC02RC1	 453	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
#define fEM_A2MV02RC1	 BUFFER[1573]	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define idfEM_A2MV02RC1	 454	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
#define iEM_TERIS2	 BUFFER[1578]	//(TERIS2) Неисправности  ИС2
#define idiEM_TERIS2	 455	//(TERIS2) Неисправности  ИС2
#define fEM_B3MC02RC1	 BUFFER[1581]	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define idfEM_B3MC02RC1	 456	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
#define fEM_B3MV02RC1	 BUFFER[1586]	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define idfEM_B3MV02RC1	 457	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
#define iEM_TERIS1	 BUFFER[1591]	//(TERIS1) Неисправности  ИС1
#define idiEM_TERIS1	 458	//(TERIS1) Неисправности  ИС1
#define fEM_A3MC02RC1	 BUFFER[1594]	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define idfEM_A3MC02RC1	 459	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
#define fEM_A3MV02RC1	 BUFFER[1599]	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define idfEM_A3MV02RC1	 460	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
#define iEM_TERA1IE04LDU	 BUFFER[1604]	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define idiEM_TERA1IE04LDU	 461	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
#define iEM_TERA1IE03LDU	 BUFFER[1607]	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define idiEM_TERA1IE03LDU	 462	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
#define fEM_A1MC01RC1	 BUFFER[1610]	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define idfEM_A1MC01RC1	 463	//(A1MC01RC1) Заданная координата  ББ1 от ИС
#define iEM_TERB1IE03LDU	 BUFFER[1615]	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define idiEM_TERB1IE03LDU	 464	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
#define iEM_TERB1IE04LDU	 BUFFER[1618]	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define idiEM_TERB1IE04LDU	 465	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
#define fEM_B1MC01RC1	 BUFFER[1621]	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define idfEM_B1MC01RC1	 466	//(B1MC01RC1) Заданная координата ББ2 от ИС
#define fEM_B1MV01RC1	 BUFFER[1626]	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define idfEM_B1MV01RC1	 467	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
#define fEM_B2MC01RC1	 BUFFER[1631]	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define idfEM_B2MC01RC1	 468	//(B2MC01RC1) Заданная координата РБ2 от ИС
#define fEM_B2MV01RC1	 BUFFER[1636]	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define idfEM_B2MV01RC1	 469	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
#define fEM_A3MC01RC1	 BUFFER[1641]	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define idfEM_A3MC01RC1	 470	//(A3MC01RC1) Заданная координата ИС1 от ИС
#define fEM_A3MV01RC1	 BUFFER[1646]	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define idfEM_A3MV01RC1	 471	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
#define fEM_B3MC01RC1	 BUFFER[1651]	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define idfEM_B3MC01RC1	 472	//(B3MC01RC1) Заданная координата ИС2 от ИС
#define fEM_B3MV01RC1	 BUFFER[1656]	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define idfEM_B3MV01RC1	 473	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
#define iEM_TERA2SS21LIM	 BUFFER[1661]	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define idiEM_TERA2SS21LIM	 474	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
#define iEM_TERA2SS12LIM	 BUFFER[1664]	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define idiEM_TERA2SS12LIM	 475	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
#define iEM_TERR6SS21LIM	 BUFFER[1667]	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define idiEM_TERR6SS21LIM	 476	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
#define iEM_TERA2VP82LIM	 BUFFER[1670]	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define idiEM_TERA2VP82LIM	 477	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
#define iEM_TERA2SS11LIM	 BUFFER[1673]	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define idiEM_TERA2SS11LIM	 478	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
#define iEM_TERB3SS21LIM	 BUFFER[1676]	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define idiEM_TERB3SS21LIM	 479	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
#define iEM_TERA0MT01RIM	 BUFFER[1679]	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define idiEM_TERA0MT01RIM	 480	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
#define iEM_TERB0MT01RIM	 BUFFER[1682]	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define idiEM_TERB0MT01RIM	 481	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
#define iEM_TERA2SP01RIM	 BUFFER[1685]	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define idiEM_TERA2SP01RIM	 482	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
#define iEM_TERB2SP01RIM	 BUFFER[1688]	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define idiEM_TERB2SP01RIM	 483	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
#define iEM_TERB3SP02RIM	 BUFFER[1691]	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define idiEM_TERB3SP02RIM	 484	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
#define iEM_TERA3SC01RIM	 BUFFER[1694]	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define idiEM_TERA3SC01RIM	 485	//(TERA3SC01RIM) Искажение: Координата штока ИС1
#define iEM_TERA3VP81LIM	 BUFFER[1697]	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define idiEM_TERA3VP81LIM	 486	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
#define iEM_TERA2SC01RIM	 BUFFER[1700]	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define idiEM_TERA2SC01RIM	 487	//(TERA2SC01RIM) Искажение: Координата штока РБ1
#define iEM_TERA2SS33LIM	 BUFFER[1703]	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define idiEM_TERA2SS33LIM	 488	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
#define iEM_TERA3SS21LIM	 BUFFER[1706]	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define idiEM_TERA3SS21LIM	 489	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
#define iEM_TERA3SS33LIM	 BUFFER[1709]	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define idiEM_TERA3SS33LIM	 490	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
#define iEM_TERA3SS31LIM	 BUFFER[1712]	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define idiEM_TERA3SS31LIM	 491	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
#define iEM_TERB3SS31LIM	 BUFFER[1715]	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define idiEM_TERB3SS31LIM	 492	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
#define iEM_TERB3SS33LIM	 BUFFER[1718]	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define idiEM_TERB3SS33LIM	 493	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
#define iEM_TERB3SC01RIM	 BUFFER[1721]	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define idiEM_TERB3SC01RIM	 494	//(TERB3SC01RIM) Искажение: Координата штока ИС2
#define iEM_TERA3SS11LIM	 BUFFER[1724]	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define idiEM_TERA3SS11LIM	 495	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
#define iEM_TERB3SS11LIM	 BUFFER[1727]	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define idiEM_TERB3SS11LIM	 496	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
#define iEM_TERR6IS64LIM	 BUFFER[1730]	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define idiEM_TERR6IS64LIM	 497	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
#define iEM_TERB3SS22LIM	 BUFFER[1733]	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define idiEM_TERB3SS22LIM	 498	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
#define iEM_TERA3SS22LIM	 BUFFER[1736]	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define idiEM_TERA3SS22LIM	 499	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
#define iEM_TERA3SP02RIM	 BUFFER[1739]	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define idiEM_TERA3SP02RIM	 500	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
#define iEM_TERR6IS62LIM	 BUFFER[1742]	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define idiEM_TERR6IS62LIM	 501	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
#define iEM_TERR6IS66LIM	 BUFFER[1745]	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define idiEM_TERR6IS66LIM	 502	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
#define iEM_TERR6IS67LIM	 BUFFER[1748]	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define idiEM_TERR6IS67LIM	 503	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
#define iEM_TERA0VP81LIM	 BUFFER[1751]	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define idiEM_TERA0VP81LIM	 504	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
#define iEM_TERB0VP81LIM	 BUFFER[1754]	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define idiEM_TERB0VP81LIM	 505	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
#define iEM_TERR0VP81LIM	 BUFFER[1757]	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define idiEM_TERR0VP81LIM	 506	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
#define iEM_TERR6IS68LIM	 BUFFER[1760]	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define idiEM_TERR6IS68LIM	 507	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
#define iEM_TERR7SI74RIM	 BUFFER[1763]	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define idiEM_TERR7SI74RIM	 508	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
#define iEM_TERA5SS21LIM	 BUFFER[1766]	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define idiEM_TERA5SS21LIM	 509	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
#define iEM_TERB5SS11LIM	 BUFFER[1769]	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define idiEM_TERB5SS11LIM	 510	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
#define iEM_TERA5SS11LIM	 BUFFER[1772]	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define idiEM_TERA5SS11LIM	 511	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
#define iEM_TERA9SS11LIM	 BUFFER[1775]	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define idiEM_TERA9SS11LIM	 512	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
#define iEM_TERB2SS11LIM	 BUFFER[1778]	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define idiEM_TERB2SS11LIM	 513	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
#define iEM_TERB2SS12LIM	 BUFFER[1781]	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define idiEM_TERB2SS12LIM	 514	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
#define iEM_TERB2SS21LIM	 BUFFER[1784]	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define idiEM_TERB2SS21LIM	 515	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
#define iEM_TERR3SS11LIM	 BUFFER[1787]	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define idiEM_TERR3SS11LIM	 516	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
#define iEM_TERB2SC01RIM	 BUFFER[1790]	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define idiEM_TERB2SC01RIM	 517	//(TERB2SC01RIM) Искажение: Координата штока РБ2
#define iEM_TERR3SS21LIM	 BUFFER[1793]	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define idiEM_TERR3SS21LIM	 518	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
#define iEM_TERR5SS11LIM	 BUFFER[1796]	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define idiEM_TERR5SS11LIM	 519	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
#define iEM_TERA4SS11LIM	 BUFFER[1799]	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define idiEM_TERA4SS11LIM	 520	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
#define iEM_TERR1SS11LIM	 BUFFER[1802]	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define idiEM_TERR1SS11LIM	 521	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
#define iEM_TERR1SS21LIM	 BUFFER[1805]	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define idiEM_TERR1SS21LIM	 522	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
#define iEM_TERR2SS11LIM	 BUFFER[1808]	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define idiEM_TERR2SS11LIM	 523	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
#define iEM_TERR2SS21LIM	 BUFFER[1811]	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define idiEM_TERR2SS21LIM	 524	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
#define iEM_TERA4VP82LIM	 BUFFER[1814]	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define idiEM_TERA4VP82LIM	 525	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
#define iEM_TERB4SS21LIM	 BUFFER[1817]	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define idiEM_TERB4SS21LIM	 526	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
#define iEM_TERR5SS21LIM	 BUFFER[1820]	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define idiEM_TERR5SS21LIM	 527	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
#define iEM_TERB6SS21LIM	 BUFFER[1823]	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define idiEM_TERB6SS21LIM	 528	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
#define iEM_TERB4SS11LIM	 BUFFER[1826]	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define idiEM_TERB4SS11LIM	 529	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
#define iEM_TERA4SS21LIM	 BUFFER[1829]	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define idiEM_TERA4SS21LIM	 530	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
#define iEM_TERA6MS11LIM	 BUFFER[1832]	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define idiEM_TERA6MS11LIM	 531	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
#define iEM_TERA6SS21LIM	 BUFFER[1835]	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define idiEM_TERA6SS21LIM	 532	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
#define iEM_TERB6SS11LIM	 BUFFER[1838]	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define idiEM_TERB6SS11LIM	 533	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
#define iEM_TERR4SS11LIM	 BUFFER[1841]	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define idiEM_TERR4SS11LIM	 534	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
#define iEM_TERR4MS21LIM	 BUFFER[1844]	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define idiEM_TERR4MS21LIM	 535	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
#define iEM_TERR4SS12LIM	 BUFFER[1847]	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define idiEM_TERR4SS12LIM	 536	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
#define iEM_TERR4SS22LIM	 BUFFER[1850]	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define idiEM_TERR4SS22LIM	 537	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
#define iEM_TERR8SS11LIM	 BUFFER[1853]	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define idiEM_TERR8SS11LIM	 538	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
#define iEM_TERB8SC01RIM	 BUFFER[1856]	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define idiEM_TERB8SC01RIM	 539	//(TERB8SC01RIM) Искажение: Координата АЗ2
#define iEM_TERA8SC01RIM	 BUFFER[1859]	//(TERA8SC01RIM) Искажение: Координата ДС2
#define idiEM_TERA8SC01RIM	 540	//(TERA8SC01RIM) Искажение: Координата ДС2
#define iEM_TERB8SS12LIM	 BUFFER[1862]	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define idiEM_TERB8SS12LIM	 541	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
#define iEM_TERA8SS12LIM	 BUFFER[1865]	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define idiEM_TERA8SS12LIM	 542	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
#define iEM_TERB8SS22LIM	 BUFFER[1868]	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define idiEM_TERB8SS22LIM	 543	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
#define iEM_TERA8SS22LIM	 BUFFER[1871]	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define idiEM_TERA8SS22LIM	 544	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
#define iEM_TERA9SS21LIM	 BUFFER[1874]	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define idiEM_TERA9SS21LIM	 545	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
#define iEM_TERB9SS21LIM	 BUFFER[1877]	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define idiEM_TERB9SS21LIM	 546	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
#define iEM_TERB9SS11LIM	 BUFFER[1880]	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define idiEM_TERB9SS11LIM	 547	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
#define iEM_TERB5SS21LIM	 BUFFER[1883]	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define idiEM_TERB5SS21LIM	 548	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
#define iEM_TERA1SS21LIM	 BUFFER[1886]	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define idiEM_TERA1SS21LIM	 549	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
#define iEM_TERA1SS11LIM	 BUFFER[1889]	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define idiEM_TERA1SS11LIM	 550	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
#define iEM_TERA1SC01RIM	 BUFFER[1892]	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define idiEM_TERA1SC01RIM	 551	//(TERA1SC01RIM) Искажение: Координата штока ББ1
#define iEM_TERA1SS12LIM	 BUFFER[1895]	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define idiEM_TERA1SS12LIM	 552	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
#define iEM_TERB1SS21LIM	 BUFFER[1898]	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define idiEM_TERB1SS21LIM	 553	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
#define iEM_TERB1SS11LIM	 BUFFER[1901]	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define idiEM_TERB1SS11LIM	 554	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
#define iEM_TERB1MC01RIM	 BUFFER[1904]	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define idiEM_TERB1MC01RIM	 555	//(TERB1MC01RIM) Искажение: Координата штока ББ2
#define iEM_TERB1SS12LIM	 BUFFER[1907]	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define idiEM_TERB1SS12LIM	 556	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
#define iEM_TERTLG	 BUFFER[1910]	//(TERTLG) Неисправности  тележки от ИС
#define idiEM_TERTLG	 557	//(TERTLG) Неисправности  тележки от ИС
#define fEM_R4MC01RC1	 BUFFER[1913]	//(R4MC01RC1) Заданная координата тележки от ИС
#define idfEM_R4MC01RC1	 558	//(R4MC01RC1) Заданная координата тележки от ИС
#define fEM_R4MV01RC1	 BUFFER[1918]	//(R4MV01RC1) Заданная скорость тележки от ИС
#define idfEM_R4MV01RC1	 559	//(R4MV01RC1) Заданная скорость тележки от ИС
#define iEM_TERMAZ2	 BUFFER[1923]	//(TERMAZ2) Неисправности АЗ2 от ИС
#define idiEM_TERMAZ2	 560	//(TERMAZ2) Неисправности АЗ2 от ИС
#define fEM_B8MC01RC1	 BUFFER[1926]	//(B8MC01RC1) Заданная координата АЗ2 от ИС
#define idfEM_B8MC01RC1	 561	//(B8MC01RC1) Заданная координата АЗ2 от ИС
#define fEM_B8MV01RC1	 BUFFER[1931]	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define idfEM_B8MV01RC1	 562	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
#define iEM_TERDS2	 BUFFER[1936]	//(TERDS2) Неисправности ДС2 от ИС
#define idiEM_TERDS2	 563	//(TERDS2) Неисправности ДС2 от ИС
#define fEM_A8MC01RC1	 BUFFER[1939]	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define idfEM_A8MC01RC1	 564	//(A8MC01RC1) Заданная координата ДС2 от ИС
#define fEM_A8MV01RC1	 BUFFER[1944]	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define idfEM_A8MV01RC1	 565	//(A8MV01RC1) Заданная скорость ДС2 от ИС
#define iEM_TERBZ1	 BUFFER[1949]	//(TERBZ1) Неисправности БЗ1
#define idiEM_TERBZ1	 566	//(TERBZ1) Неисправности БЗ1
#define fEM_A6MC01RC1	 BUFFER[1952]	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define idfEM_A6MC01RC1	 567	//(A6MC01RC1) Заданная координата БЗ1 от ИС
#define fEM_A6MV01RC1	 BUFFER[1957]	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define idfEM_A6MV01RC1	 568	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
#define iEM_TERBZ2	 BUFFER[1962]	//(TERBZ2) Неисправности БЗ2
#define idiEM_TERBZ2	 569	//(TERBZ2) Неисправности БЗ2
#define fEM_B6MC01RC1	 BUFFER[1965]	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define idfEM_B6MC01RC1	 570	//(B6MC01RC1) Заданная координата БЗ2 от ИС
#define fEM_B6MV01RC1	 BUFFER[1970]	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define idfEM_B6MV01RC1	 571	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
#define lEM_R3AD10LC1	 BUFFER[1975]	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define idlEM_R3AD10LC1	 572	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
#define lEM_R3AD20LC1	 BUFFER[1977]	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define idlEM_R3AD20LC1	 573	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
#define lEM_R6AD10LC1	 BUFFER[1979]	//(R6AD10LC1) Выкатить кран-балку от ИС
#define idlEM_R6AD10LC1	 574	//(R6AD10LC1) Выкатить кран-балку от ИС
#define lEM_R5AD10LC1	 BUFFER[1981]	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define idlEM_R5AD10LC1	 575	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
#define lEM_R5AD20LC1	 BUFFER[1983]	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define idlEM_R5AD20LC1	 576	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
#define iEM_TERMDZ2	 BUFFER[1985]	//(TERMDZ2) Неисправности МДЗ2
#define idiEM_TERMDZ2	 577	//(TERMDZ2) Неисправности МДЗ2
#define fEM_R2MC01RC1	 BUFFER[1988]	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define idfEM_R2MC01RC1	 578	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
#define fEM_R2MV01RC1	 BUFFER[1993]	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define idfEM_R2MV01RC1	 579	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
#define iEM_TERMDZ1	 BUFFER[1998]	//(TERMDZ1) Неисправности МДЗ1
#define idiEM_TERMDZ1	 580	//(TERMDZ1) Неисправности МДЗ1
#define fEM_R1MC01RC1	 BUFFER[2001]	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define idfEM_R1MC01RC1	 581	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
#define fEM_R1MV01RC1	 BUFFER[2006]	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define idfEM_R1MV01RC1	 582	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
#define iEM_TERNL1	 BUFFER[2011]	//(TERNL1) Неисправности НЛ1
#define idiEM_TERNL1	 583	//(TERNL1) Неисправности НЛ1
#define fEM_A5MC01RC1	 BUFFER[2014]	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define idfEM_A5MC01RC1	 584	//(A5MC01RC1) Заданная координата НЛ1 от ИС
#define fEM_A5MV01RC1	 BUFFER[2019]	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define idfEM_A5MV01RC1	 585	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
#define iEM_TERNL2	 BUFFER[2024]	//(TERNL2) Неисправности НЛ2
#define idiEM_TERNL2	 586	//(TERNL2) Неисправности НЛ2
#define fEM_B5MC01RC1	 BUFFER[2027]	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define idfEM_B5MC01RC1	 587	//(B5MC01RC1) Заданная координата НЛ2 от ИС
#define fEM_B5MV01RC1	 BUFFER[2032]	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define idfEM_B5MV01RC1	 588	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
#define lEM_R8AD10LC1	 BUFFER[2037]	//(R8AD10LC1) Установить аварийный НИ от ИС
#define idlEM_R8AD10LC1	 589	//(R8AD10LC1) Установить аварийный НИ от ИС
#define fEM_A1UC08RIM	 BUFFER[2039]	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define idfEM_A1UC08RIM	 590	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
#define fEM_A2UC08RIM	 BUFFER[2044]	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define idfEM_A2UC08RIM	 591	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
#define fEM_A3UC08RIM	 BUFFER[2049]	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define idfEM_A3UC08RIM	 592	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
#define iEM_TERB2SS33LIM	 BUFFER[2054]	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define idiEM_TERB2SS33LIM	 593	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
#define iEM_TERA1VP81LIM	 BUFFER[2057]	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define idiEM_TERA1VP81LIM	 594	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
#define iEM_TERB1VP81LIM	 BUFFER[2060]	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define idiEM_TERB1VP81LIM	 595	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
#define fEM_A0UT03RSP	 BUFFER[2063]	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define idfEM_A0UT03RSP	 596	//(A0UT03RSP) Стартовая  температура АЗ1 град
#define fEM_A0UR01RSP	 BUFFER[2068]	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define idfEM_A0UR01RSP	 597	//(A0UR01RSP) Стартовая  реактивность АЗ1
#define fEM_A0UR02RSP	 BUFFER[2073]	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define idfEM_A0UR02RSP	 598	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
#define fEM_B0UT03RSP	 BUFFER[2078]	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define idfEM_B0UT03RSP	 599	//(B0UT03RSP) Стартовая  температура АЗ2 град
#define fEM_A1MC01RSP	 BUFFER[2083]	//(A1MC01RSP) Стартовая координата  ББ1
#define idfEM_A1MC01RSP	 600	//(A1MC01RSP) Стартовая координата  ББ1
#define fEM_A1MC02RSP	 BUFFER[2088]	//(A1MC02RSP) Стартовая координата штока ББ1
#define idfEM_A1MC02RSP	 601	//(A1MC02RSP) Стартовая координата штока ББ1
#define fEM_A1MV01RSP	 BUFFER[2093]	//(A1MV01RSP) Стартовая скорость движения  ББ1
#define idfEM_A1MV01RSP	 602	//(A1MV01RSP) Стартовая скорость движения  ББ1
#define fEM_A1MV02RSP	 BUFFER[2098]	//(A1MV02RSP) Стартовая скорость движения  ББ1
#define idfEM_A1MV02RSP	 603	//(A1MV02RSP) Стартовая скорость движения  ББ1
#define fEM_B1MC01RSP	 BUFFER[2103]	//(B1MC01RSP) Стартовая координата  ББ2
#define idfEM_B1MC01RSP	 604	//(B1MC01RSP) Стартовая координата  ББ2
#define fEM_B1MV01RSP	 BUFFER[2108]	//(B1MV01RSP) Стартовая скорость движения  ББ2
#define idfEM_B1MV01RSP	 605	//(B1MV01RSP) Стартовая скорость движения  ББ2
#define fEM_B1MC02RSP	 BUFFER[2113]	//(B1MC02RSP) Стартовая координата штока ББ2
#define idfEM_B1MC02RSP	 606	//(B1MC02RSP) Стартовая координата штока ББ2
#define fEM_B1MV02RSP	 BUFFER[2118]	//(B1MV02RSP) Стартовая скорость движения  ББ2
#define idfEM_B1MV02RSP	 607	//(B1MV02RSP) Стартовая скорость движения  ББ2
#define fEM_A2MC01RC1	 BUFFER[2123]	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define idfEM_A2MC01RC1	 608	//(A2MC01RC1) Заданная координата РБ1 от ИС
#define fEM_A2MV01RC1	 BUFFER[2128]	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define idfEM_A2MV01RC1	 609	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
#define fEM_A2MC01RSP	 BUFFER[2133]	//(A2MC01RSP) Стартовая координата  РБ1
#define idfEM_A2MC01RSP	 610	//(A2MC01RSP) Стартовая координата  РБ1
#define fEM_A2MV01RSP	 BUFFER[2138]	//(A2MV01RSP) Стартовая скорость движения  РБ1
#define idfEM_A2MV01RSP	 611	//(A2MV01RSP) Стартовая скорость движения  РБ1
#define fEM_A2MC02RSP	 BUFFER[2143]	//(A2MC02RSP) Стартовая координата штока РБ1
#define idfEM_A2MC02RSP	 612	//(A2MC02RSP) Стартовая координата штока РБ1
#define fEM_A2MV02RSP	 BUFFER[2148]	//(A2MV02RSP) Стартовая скорость движения  РБ1
#define idfEM_A2MV02RSP	 613	//(A2MV02RSP) Стартовая скорость движения  РБ1
#define fEM_B2MC01RSP	 BUFFER[2153]	//(B2MC01RSP) Стартовая координата  РБ2
#define idfEM_B2MC01RSP	 614	//(B2MC01RSP) Стартовая координата  РБ2
#define fEM_B2MV01RSP	 BUFFER[2158]	//(B2MV01RSP) Стартовая скорость движения  РБ2
#define idfEM_B2MV01RSP	 615	//(B2MV01RSP) Стартовая скорость движения  РБ2
#define fEM_B2MC02RSP	 BUFFER[2163]	//(B2MC02RSP) Стартовая координата штока РБ2
#define idfEM_B2MC02RSP	 616	//(B2MC02RSP) Стартовая координата штока РБ2
#define fEM_B2MV02RSP	 BUFFER[2168]	//(B2MV02RSP) Стартовая скорость движения  РБ2
#define idfEM_B2MV02RSP	 617	//(B2MV02RSP) Стартовая скорость движения  РБ2
#define fEM_A3MC01RSP	 BUFFER[2173]	//(A3MC01RSP) Стартовая координата  ИС1
#define idfEM_A3MC01RSP	 618	//(A3MC01RSP) Стартовая координата  ИС1
#define fEM_A3MV01RSP	 BUFFER[2178]	//(A3MV01RSP) Стартовая скорость движения  ИС1
#define idfEM_A3MV01RSP	 619	//(A3MV01RSP) Стартовая скорость движения  ИС1
#define fEM_A3MC02RSP	 BUFFER[2183]	//(A3MC02RSP) Стартовая координата штока ИС1
#define idfEM_A3MC02RSP	 620	//(A3MC02RSP) Стартовая координата штока ИС1
#define fEM_A3MV02RSP	 BUFFER[2188]	//(A3MV02RSP) Стартовая скорость движения  ИС1
#define idfEM_A3MV02RSP	 621	//(A3MV02RSP) Стартовая скорость движения  ИС1
#define fEM_B3MC01RSP	 BUFFER[2193]	//(B3MC01RSP) Стартовая координата  ИС2
#define idfEM_B3MC01RSP	 622	//(B3MC01RSP) Стартовая координата  ИС2
#define fEM_B3MV01RSP	 BUFFER[2198]	//(B3MV01RSP) Стартовая скорость движения  ИС2
#define idfEM_B3MV01RSP	 623	//(B3MV01RSP) Стартовая скорость движения  ИС2
#define fEM_B3MC02RSP	 BUFFER[2203]	//(B3MC02RSP) Стартовая координата штока ИС2
#define idfEM_B3MC02RSP	 624	//(B3MC02RSP) Стартовая координата штока ИС2
#define fEM_B3MV02RSP	 BUFFER[2208]	//(B3MV02RSP) Стартовая скорость движения  ИС2
#define idfEM_B3MV02RSP	 625	//(B3MV02RSP) Стартовая скорость движения  ИС2
#define fEM_B8MC01RSP	 BUFFER[2213]	//(B8MC01RSP) Стартовая координата АЗ2
#define idfEM_B8MC01RSP	 626	//(B8MC01RSP) Стартовая координата АЗ2
#define fEM_B8MV01RSP	 BUFFER[2218]	//(B8MV01RSP) Стартовая скорость АЗ2
#define idfEM_B8MV01RSP	 627	//(B8MV01RSP) Стартовая скорость АЗ2
#define fEM_A8MC01RSP	 BUFFER[2223]	//(A8MC01RSP) Стартовая координата ДС2
#define idfEM_A8MC01RSP	 628	//(A8MC01RSP) Стартовая координата ДС2
#define fEM_A8MV01RSP	 BUFFER[2228]	//(A8MV01RSP) Стартовая скорость ДС2
#define idfEM_A8MV01RSP	 629	//(A8MV01RSP) Стартовая скорость ДС2
#define fEM_A6MC01RSP	 BUFFER[2233]	//(A6MC01RSP) Стартовая координата БЗ1
#define idfEM_A6MC01RSP	 630	//(A6MC01RSP) Стартовая координата БЗ1
#define fEM_A6MV01RSP	 BUFFER[2238]	//(A6MV01RSP) Стартовая скорость БЗ1
#define idfEM_A6MV01RSP	 631	//(A6MV01RSP) Стартовая скорость БЗ1
#define fEM_B6MC01RSP	 BUFFER[2243]	//(B6MC01RSP) Стартовая координата БЗ2
#define idfEM_B6MC01RSP	 632	//(B6MC01RSP) Стартовая координата БЗ2
#define fEM_B6MV01RSP	 BUFFER[2248]	//(B6MV01RSP) Стартовая скорость БЗ2
#define idfEM_B6MV01RSP	 633	//(B6MV01RSP) Стартовая скорость БЗ2
#define fEM_R3UC01RSP	 BUFFER[2253]	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define idfEM_R3UC01RSP	 634	//(R3UC01RSP) Стартовая координата Гомогенных дверей
#define fEM_R3UV01RSP	 BUFFER[2258]	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
#define idfEM_R3UV01RSP	 635	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
#define fEM_R5UC01RSP	 BUFFER[2263]	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define idfEM_R5UC01RSP	 636	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
#define fEM_R5UV01RSP	 BUFFER[2268]	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
#define idfEM_R5UV01RSP	 637	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
#define fEM_R6UC01RSP	 BUFFER[2273]	//(R6UC01RSP) Стартовая координата Кран-балки
#define idfEM_R6UC01RSP	 638	//(R6UC01RSP) Стартовая координата Кран-балки
#define fEM_R6UV01RSP	 BUFFER[2278]	//(R6UV01RSP) Стартовая скорость Кран-балки
#define idfEM_R6UV01RSP	 639	//(R6UV01RSP) Стартовая скорость Кран-балки
#define fEM_R2MC01RSP	 BUFFER[2283]	//(R2MC01RSP) Стартовая координата МДЗ2
#define idfEM_R2MC01RSP	 640	//(R2MC01RSP) Стартовая координата МДЗ2
#define fEM_R2MV01RSP	 BUFFER[2288]	//(R2MV01RSP) Стартовая скорость МДЗ2
#define idfEM_R2MV01RSP	 641	//(R2MV01RSP) Стартовая скорость МДЗ2
#define fEM_R1MC01RSP	 BUFFER[2293]	//(R1MC01RSP) Стартовая координата МДЗ1
#define idfEM_R1MC01RSP	 642	//(R1MC01RSP) Стартовая координата МДЗ1
#define fEM_R1MV01RSP	 BUFFER[2298]	//(R1MV01RSP) Стартовая скорость МДЗ1
#define idfEM_R1MV01RSP	 643	//(R1MV01RSP) Стартовая скорость МДЗ1
#define fEM_A5MC01RSP	 BUFFER[2303]	//(A5MC01RSP) Стартовая координата НЛ1
#define idfEM_A5MC01RSP	 644	//(A5MC01RSP) Стартовая координата НЛ1
#define fEM_A5MV01RSP	 BUFFER[2308]	//(A5MV01RSP) Стартовая скорость НЛ1
#define idfEM_A5MV01RSP	 645	//(A5MV01RSP) Стартовая скорость НЛ1
#define fEM_B5MC01RSP	 BUFFER[2313]	//(B5MC01RSP) Стартовая координата НЛ2
#define idfEM_B5MC01RSP	 646	//(B5MC01RSP) Стартовая координата НЛ2
#define fEM_B5MV01RSP	 BUFFER[2318]	//(B5MV01RSP) Стартовая скорость НЛ2
#define idfEM_B5MV01RSP	 647	//(B5MV01RSP) Стартовая скорость НЛ2
#define fEM_A9MC01RSP	 BUFFER[2323]	//(A9MC01RSP) Стартовая координата НИ ДС1
#define idfEM_A9MC01RSP	 648	//(A9MC01RSP) Стартовая координата НИ ДС1
#define fEM_A9MV01RSP	 BUFFER[2328]	//(A9MV01RSP) Стартовая скорость НИ ДС1
#define idfEM_A9MV01RSP	 649	//(A9MV01RSP) Стартовая скорость НИ ДС1
#define fEM_B9MC01RSP	 BUFFER[2333]	//(B9MC01RSP) Стартовая координата НИ ДС2
#define idfEM_B9MC01RSP	 650	//(B9MC01RSP) Стартовая координата НИ ДС2
#define fEM_B9MV01RSP	 BUFFER[2338]	//(B9MV01RSP) Стартовая скорость НИ ДС2
#define idfEM_B9MV01RSP	 651	//(B9MV01RSP) Стартовая скорость НИ ДС2
#define fEM_A4MC01RSP	 BUFFER[2343]	//(A4MC01RSP) Стартовая координата НИ1
#define idfEM_A4MC01RSP	 652	//(A4MC01RSP) Стартовая координата НИ1
#define fEM_A4MV01RSP	 BUFFER[2348]	//(A4MV01RSP) Стартовая скорость НИ1
#define idfEM_A4MV01RSP	 653	//(A4MV01RSP) Стартовая скорость НИ1
#define fEM_B4MC01RSP	 BUFFER[2353]	//(B4MC01RSP) Стартовая координата НИ2
#define idfEM_B4MC01RSP	 654	//(B4MC01RSP) Стартовая координата НИ2
#define fEM_B4MV01RSP	 BUFFER[2358]	//(B4MV01RSP) Стартовая скорость НИ2
#define idfEM_B4MV01RSP	 655	//(B4MV01RSP) Стартовая скорость НИ2
#define fEM_R4MC01RSP	 BUFFER[2363]	//(R4MC01RSP) Стартовая координата тележки
#define idfEM_R4MC01RSP	 656	//(R4MC01RSP) Стартовая координата тележки
#define fEM_R4MV01RSP	 BUFFER[2368]	//(R4MV01RSP) Стартовая скорость тележки
#define idfEM_R4MV01RSP	 657	//(R4MV01RSP) Стартовая скорость тележки
#define fEM_A1MV01RC1	 BUFFER[2373]	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define idfEM_A1MV01RC1	 658	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
#define iEM_TERB7MS31LIM	 BUFFER[2378]	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define idiEM_TERB7MS31LIM	 659	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
#define iEM_TERA7MS31LIM	 BUFFER[2381]	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define idiEM_TERA7MS31LIM	 660	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
#define fEM_R7UY00RSS	 BUFFER[2384]	//(R7UY00RSS) Y-координата АЗ1 см
#define idfEM_R7UY00RSS	 661	//(R7UY00RSS) Y-координата АЗ1 см
#define iEM_TERA6VS12LIM	 BUFFER[2389]	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define idiEM_TERA6VS12LIM	 662	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
#define iEM_TERA6VS22LIM	 BUFFER[2392]	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define idiEM_TERA6VS22LIM	 663	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
#define iEM_TERB6VS12LIM	 BUFFER[2395]	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define idiEM_TERB6VS12LIM	 664	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
#define iEM_TERB6VS22LIM	 BUFFER[2398]	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define idiEM_TERB6VS22LIM	 665	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
#define iEM_TERA5VS22LIM	 BUFFER[2401]	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define idiEM_TERA5VS22LIM	 666	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
#define iEM_TERA5VS12LIM	 BUFFER[2404]	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define idiEM_TERA5VS12LIM	 667	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
#define iEM_TERB5VS12LIM	 BUFFER[2407]	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define idiEM_TERB5VS12LIM	 668	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
#define iEM_TERB5VS22LIM	 BUFFER[2410]	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define idiEM_TERB5VS22LIM	 669	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
#define iEM_TERR1VS12LIM	 BUFFER[2413]	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define idiEM_TERR1VS12LIM	 670	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
#define iEM_TERR1VS22LIM	 BUFFER[2416]	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define idiEM_TERR1VS22LIM	 671	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
#define iEM_TERR2VS12LIM	 BUFFER[2419]	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define idiEM_TERR2VS12LIM	 672	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
#define iEM_TERR2VS22LIM	 BUFFER[2422]	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define idiEM_TERR2VS22LIM	 673	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
#define iEM_TERR4VS12LDU	 BUFFER[2425]	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS12LDU	 674	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define iEM_TERR4VS22LDU	 BUFFER[2428]	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define idiEM_TERR4VS22LDU	 675	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
#define fEM_R4UC23RIM	 BUFFER[2431]	//(R4UC23RIM) Y-координата АЗ1
#define idfEM_R4UC23RIM	 676	//(R4UC23RIM) Y-координата АЗ1
#define fEM_A0UX13RSS	 BUFFER[2436]	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define idfEM_A0UX13RSS	 677	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
#define fEM_A0UX14RSS	 BUFFER[2441]	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define idfEM_A0UX14RSS	 678	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
#define fEM_A0UX15RSS	 BUFFER[2446]	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define idfEM_A0UX15RSS	 679	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
#define fEM_R7UX13RSS	 BUFFER[2451]	//(R7UX13RSS) X-координата камеры R7IN51
#define idfEM_R7UX13RSS	 680	//(R7UX13RSS) X-координата камеры R7IN51
#define fEM_R7UX14RSS	 BUFFER[2456]	//(R7UX14RSS) X-координата камеры R7IN52
#define idfEM_R7UX14RSS	 681	//(R7UX14RSS) X-координата камеры R7IN52
#define fEM_R7UX15RSS	 BUFFER[2461]	//(R7UX15RSS) X-координата камеры R7IN53
#define idfEM_R7UX15RSS	 682	//(R7UX15RSS) X-координата камеры R7IN53
#define fEM_R7UY13RSS	 BUFFER[2466]	//(R7UY13RSS) Y-координата камеры R7IN51
#define idfEM_R7UY13RSS	 683	//(R7UY13RSS) Y-координата камеры R7IN51
#define fEM_R7UY14RSS	 BUFFER[2471]	//(R7UY14RSS) Y-координата камеры R7IN52
#define idfEM_R7UY14RSS	 684	//(R7UY14RSS) Y-координата камеры R7IN52
#define fEM_R7UY15RSS	 BUFFER[2476]	//(R7UY15RSS) Y-координата камеры R7IN53
#define idfEM_R7UY15RSS	 685	//(R7UY15RSS) Y-координата камеры R7IN53
#define fEM_R7UX16RSS	 BUFFER[2481]	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define idfEM_R7UX16RSS	 686	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
#define bFirstEnterFlag	 BUFFER[2486]	//(bFirstEnterFlag) 
#define idbFirstEnterFlag	 687	//(bFirstEnterFlag) 
#define internal1_m896_Chim0	 BUFFER[2488]	//(internal1_m896_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m896_Chim0	 688	//(internal1_m896_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m886_Chim0	 BUFFER[2493]	//(internal1_m886_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m886_Chim0	 689	//(internal1_m886_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m878_Chim0	 BUFFER[2498]	//(internal1_m878_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m878_Chim0	 690	//(internal1_m878_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m833_Out10	 BUFFER[2503]	//(internal1_m833_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m833_Out10	 691	//(internal1_m833_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m832_Out10	 BUFFER[2505]	//(internal1_m832_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m832_Out10	 692	//(internal1_m832_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1016_Out10	 BUFFER[2507]	//(internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1016_Out10	 693	//(internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1015_Out10	 BUFFER[2509]	//(internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1015_Out10	 694	//(internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1014_Out10	 BUFFER[2511]	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1014_Out10	 695	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1013_Out10	 BUFFER[2513]	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1013_Out10	 696	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m693_Out10	 BUFFER[2515]	//(internal1_m693_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m693_Out10	 697	//(internal1_m693_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m692_Out10	 BUFFER[2517]	//(internal1_m692_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m692_Out10	 698	//(internal1_m692_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m671_Out10	 BUFFER[2519]	//(internal1_m671_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m671_Out10	 699	//(internal1_m671_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m670_Out10	 BUFFER[2521]	//(internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m670_Out10	 700	//(internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m691_Out10	 BUFFER[2523]	//(internal1_m691_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m691_Out10	 701	//(internal1_m691_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m690_Out10	 BUFFER[2525]	//(internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m690_Out10	 702	//(internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m669_Out10	 BUFFER[2527]	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m669_Out10	 703	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m668_Out10	 BUFFER[2529]	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m668_Out10	 704	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m529_Out10	 BUFFER[2531]	//(internal1_m529_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m529_Out10	 705	//(internal1_m529_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m545_Out10	 BUFFER[2533]	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m545_Out10	 706	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m411_Out10	 BUFFER[2535]	//(internal1_m411_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m411_Out10	 707	//(internal1_m411_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m488_q0	 BUFFER[2537]	//(internal1_m488_q0) q0 - внутренний параметр
#define idinternal1_m488_q0	 708	//(internal1_m488_q0) q0 - внутренний параметр
#define internal1_m489_q0	 BUFFER[2539]	//(internal1_m489_q0) q0 - внутренний параметр
#define idinternal1_m489_q0	 709	//(internal1_m489_q0) q0 - внутренний параметр
#define internal1_m474_q0	 BUFFER[2541]	//(internal1_m474_q0) q0 - внутренний параметр
#define idinternal1_m474_q0	 710	//(internal1_m474_q0) q0 - внутренний параметр
#define internal1_m475_q0	 BUFFER[2543]	//(internal1_m475_q0) q0 - внутренний параметр
#define idinternal1_m475_q0	 711	//(internal1_m475_q0) q0 - внутренний параметр
#define internal1_m644_tx	 BUFFER[2545]	//(internal1_m644_tx) tx - время накопленное сек
#define idinternal1_m644_tx	 712	//(internal1_m644_tx) tx - время накопленное сек
#define internal1_m644_y0	 BUFFER[2550]	//(internal1_m644_y0) y0
#define idinternal1_m644_y0	 713	//(internal1_m644_y0) y0
#define internal1_m632_tx	 BUFFER[2551]	//(internal1_m632_tx) tx - время накопленное сек
#define idinternal1_m632_tx	 714	//(internal1_m632_tx) tx - время накопленное сек
#define internal1_m632_y0	 BUFFER[2556]	//(internal1_m632_y0) y0
#define idinternal1_m632_y0	 715	//(internal1_m632_y0) y0
#define internal1_m618_tx	 BUFFER[2557]	//(internal1_m618_tx) tx - время накопленное сек
#define idinternal1_m618_tx	 716	//(internal1_m618_tx) tx - время накопленное сек
#define internal1_m618_y0	 BUFFER[2562]	//(internal1_m618_y0) y0
#define idinternal1_m618_y0	 717	//(internal1_m618_y0) y0
#define internal1_m616_tx	 BUFFER[2563]	//(internal1_m616_tx) tx - время накопленное сек
#define idinternal1_m616_tx	 718	//(internal1_m616_tx) tx - время накопленное сек
#define internal1_m616_y0	 BUFFER[2568]	//(internal1_m616_y0) y0
#define idinternal1_m616_y0	 719	//(internal1_m616_y0) y0
#define internal1_m208_Out10	 BUFFER[2569]	//(internal1_m208_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m208_Out10	 720	//(internal1_m208_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m226_Out10	 BUFFER[2571]	//(internal1_m226_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m226_Out10	 721	//(internal1_m226_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m41_Out10	 BUFFER[2573]	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m41_Out10	 722	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m56_Out10	 BUFFER[2575]	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m56_Out10	 723	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m987_Out10	 BUFFER[2577]	//(internal1_m987_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m987_Out10	 724	//(internal1_m987_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m984_Out10	 BUFFER[2579]	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m984_Out10	 725	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m983_Out10	 BUFFER[2581]	//(internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m983_Out10	 726	//(internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m986_Xtek0	 BUFFER[2583]	//(internal1_m986_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m986_Xtek0	 727	//(internal1_m986_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m969_Xtek0	 BUFFER[2588]	//(internal1_m969_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m969_Xtek0	 728	//(internal1_m969_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m970_Out10	 BUFFER[2593]	//(internal1_m970_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m970_Out10	 729	//(internal1_m970_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m967_Out10	 BUFFER[2595]	//(internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m967_Out10	 730	//(internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m966_Out10	 BUFFER[2597]	//(internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m966_Out10	 731	//(internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1054_Out10	 BUFFER[2599]	//(internal1_m1054_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1054_Out10	 732	//(internal1_m1054_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1035_Out10	 BUFFER[2601]	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1035_Out10	 733	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1034_Out10	 BUFFER[2603]	//(internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1034_Out10	 734	//(internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1033_Out10	 BUFFER[2605]	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1033_Out10	 735	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m854_Out10	 BUFFER[2607]	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m854_Out10	 736	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m856_Out10	 BUFFER[2609]	//(internal1_m856_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m856_Out10	 737	//(internal1_m856_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m853_Out10	 BUFFER[2611]	//(internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m853_Out10	 738	//(internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m855_Out10	 BUFFER[2613]	//(internal1_m855_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m855_Out10	 739	//(internal1_m855_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m829_Out10	 BUFFER[2615]	//(internal1_m829_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m829_Out10	 740	//(internal1_m829_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m830_Out10	 BUFFER[2617]	//(internal1_m830_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m830_Out10	 741	//(internal1_m830_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m828_Out10	 BUFFER[2619]	//(internal1_m828_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m828_Out10	 742	//(internal1_m828_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m827_Out10	 BUFFER[2621]	//(internal1_m827_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m827_Out10	 743	//(internal1_m827_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1049_Out10	 BUFFER[2623]	//(internal1_m1049_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1049_Out10	 744	//(internal1_m1049_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1001_Out10	 BUFFER[2625]	//(internal1_m1001_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1001_Out10	 745	//(internal1_m1001_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1000_Out10	 BUFFER[2627]	//(internal1_m1000_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1000_Out10	 746	//(internal1_m1000_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m999_Out10	 BUFFER[2629]	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m999_Out10	 747	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m998_Out10	 BUFFER[2631]	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m998_Out10	 748	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1050_Out10	 BUFFER[2633]	//(internal1_m1050_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1050_Out10	 749	//(internal1_m1050_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1031_Out10	 BUFFER[2635]	//(internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1031_Out10	 750	//(internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m831_Out10	 BUFFER[2637]	//(internal1_m831_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m831_Out10	 751	//(internal1_m831_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1032_Out10	 BUFFER[2639]	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1032_Out10	 752	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1030_Out10	 BUFFER[2641]	//(internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1030_Out10	 753	//(internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1051_Out10	 BUFFER[2643]	//(internal1_m1051_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1051_Out10	 754	//(internal1_m1051_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1029_Out10	 BUFFER[2645]	//(internal1_m1029_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1029_Out10	 755	//(internal1_m1029_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1012_Out10	 BUFFER[2647]	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1012_Out10	 756	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m997_Out10	 BUFFER[2649]	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m997_Out10	 757	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m546_Out10	 BUFFER[2651]	//(internal1_m546_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m546_Out10	 758	//(internal1_m546_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m421_Xtek0	 BUFFER[2653]	//(internal1_m421_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m421_Xtek0	 759	//(internal1_m421_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m412_Out10	 BUFFER[2658]	//(internal1_m412_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m412_Out10	 760	//(internal1_m412_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m414_Out10	 BUFFER[2660]	//(internal1_m414_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m414_Out10	 761	//(internal1_m414_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m413_Out10	 BUFFER[2662]	//(internal1_m413_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m413_Out10	 762	//(internal1_m413_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m869_Out10	 BUFFER[2664]	//(internal1_m869_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m869_Out10	 763	//(internal1_m869_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m870_Out10	 BUFFER[2666]	//(internal1_m870_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m870_Out10	 764	//(internal1_m870_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m868_Out10	 BUFFER[2668]	//(internal1_m868_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m868_Out10	 765	//(internal1_m868_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1053_Out10	 BUFFER[2670]	//(internal1_m1053_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1053_Out10	 766	//(internal1_m1053_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m706_Out10	 BUFFER[2672]	//(internal1_m706_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m706_Out10	 767	//(internal1_m706_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m707_Out10	 BUFFER[2674]	//(internal1_m707_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m707_Out10	 768	//(internal1_m707_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m704_Out10	 BUFFER[2676]	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m704_Out10	 769	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m705_Out10	 BUFFER[2678]	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m705_Out10	 770	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m562_Out10	 BUFFER[2680]	//(internal1_m562_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m562_Out10	 771	//(internal1_m562_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m561_Out10	 BUFFER[2682]	//(internal1_m561_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m561_Out10	 772	//(internal1_m561_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m850_Xtek0	 BUFFER[2684]	//(internal1_m850_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m850_Xtek0	 773	//(internal1_m850_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m852_Xtek0	 BUFFER[2689]	//(internal1_m852_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m852_Xtek0	 774	//(internal1_m852_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m703_Out10	 BUFFER[2694]	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m703_Out10	 775	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m687_Out10	 BUFFER[2696]	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m687_Out10	 776	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m667_Out10	 BUFFER[2698]	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m667_Out10	 777	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m686_Out10	 BUFFER[2700]	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m686_Out10	 778	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m666_Out10	 BUFFER[2702]	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m666_Out10	 779	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m339_Out10	 BUFFER[2704]	//(internal1_m339_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m339_Out10	 780	//(internal1_m339_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m338_Out10	 BUFFER[2706]	//(internal1_m338_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m338_Out10	 781	//(internal1_m338_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m323_Out10	 BUFFER[2708]	//(internal1_m323_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m323_Out10	 782	//(internal1_m323_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m322_Out10	 BUFFER[2710]	//(internal1_m322_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m322_Out10	 783	//(internal1_m322_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m563_Out10	 BUFFER[2712]	//(internal1_m563_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m563_Out10	 784	//(internal1_m563_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m352_Out10	 BUFFER[2714]	//(internal1_m352_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m352_Out10	 785	//(internal1_m352_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m336_Xtek0	 BUFFER[2716]	//(internal1_m336_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m336_Xtek0	 786	//(internal1_m336_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m351_Out10	 BUFFER[2721]	//(internal1_m351_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m351_Out10	 787	//(internal1_m351_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m349_Out10	 BUFFER[2723]	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m349_Out10	 788	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m329_Xtek0	 BUFFER[2725]	//(internal1_m329_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m329_Xtek0	 789	//(internal1_m329_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m350_Out10	 BUFFER[2730]	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m350_Out10	 790	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m321_Out10	 BUFFER[2732]	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m321_Out10	 791	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m337_Out10	 BUFFER[2734]	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m337_Out10	 792	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m433_Out10	 BUFFER[2736]	//(internal1_m433_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m433_Out10	 793	//(internal1_m433_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m434_Xtek0	 BUFFER[2738]	//(internal1_m434_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define idinternal1_m434_Xtek0	 794	//(internal1_m434_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
#define internal1_m432_Out10	 BUFFER[2743]	//(internal1_m432_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m432_Out10	 795	//(internal1_m432_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m431_Out10	 BUFFER[2745]	//(internal1_m431_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m431_Out10	 796	//(internal1_m431_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m430_Out10	 BUFFER[2747]	//(internal1_m430_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m430_Out10	 797	//(internal1_m430_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m1052_Out10	 BUFFER[2749]	//(internal1_m1052_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m1052_Out10	 798	//(internal1_m1052_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m150_Out10	 BUFFER[2751]	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m150_Out10	 799	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m149_Out10	 BUFFER[2753]	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define idinternal1_m149_Out10	 800	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
#define internal1_m197_tx	 BUFFER[2755]	//(internal1_m197_tx) tx - внутренний параметр
#define idinternal1_m197_tx	 801	//(internal1_m197_tx) tx - внутренний параметр
#define internal1_m25_tx	 BUFFER[2758]	//(internal1_m25_tx) tx - внутренний параметр
#define idinternal1_m25_tx	 802	//(internal1_m25_tx) tx - внутренний параметр
#define internal1_m480_Pav0	 BUFFER[2761]	//(internal1_m480_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m480_Pav0	 803	//(internal1_m480_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m480_Zav0	 BUFFER[2763]	//(internal1_m480_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m480_Zav0	 804	//(internal1_m480_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m480_Pv0	 BUFFER[2765]	//(internal1_m480_Pv0)  - Пер. выключатель механизма
#define idinternal1_m480_Pv0	 805	//(internal1_m480_Pv0)  - Пер. выключатель механизма
#define internal1_m480_Zv0	 BUFFER[2767]	//(internal1_m480_Zv0)  - Зад. выключатель механизма
#define idinternal1_m480_Zv0	 806	//(internal1_m480_Zv0)  - Зад. выключатель механизма
#define internal1_m480_RA00	 BUFFER[2769]	//(internal1_m480_RA00)  - последнее задание вперед
#define idinternal1_m480_RA00	 807	//(internal1_m480_RA00)  - последнее задание вперед
#define internal1_m480_RA10	 BUFFER[2771]	//(internal1_m480_RA10)  - последнее задание назад
#define idinternal1_m480_RA10	 808	//(internal1_m480_RA10)  - последнее задание назад
#define internal1_m480_MyFirstEnterFlag	 BUFFER[2773]	//(internal1_m480_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m480_MyFirstEnterFlag	 809	//(internal1_m480_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m492_Pav0	 BUFFER[2775]	//(internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m492_Pav0	 810	//(internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m492_Zav0	 BUFFER[2777]	//(internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m492_Zav0	 811	//(internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m492_Pv0	 BUFFER[2779]	//(internal1_m492_Pv0)  - Пер. выключатель механизма
#define idinternal1_m492_Pv0	 812	//(internal1_m492_Pv0)  - Пер. выключатель механизма
#define internal1_m492_Zv0	 BUFFER[2781]	//(internal1_m492_Zv0)  - Зад. выключатель механизма
#define idinternal1_m492_Zv0	 813	//(internal1_m492_Zv0)  - Зад. выключатель механизма
#define internal1_m492_RA00	 BUFFER[2783]	//(internal1_m492_RA00)  - последнее задание вперед
#define idinternal1_m492_RA00	 814	//(internal1_m492_RA00)  - последнее задание вперед
#define internal1_m492_RA10	 BUFFER[2785]	//(internal1_m492_RA10)  - последнее задание назад
#define idinternal1_m492_RA10	 815	//(internal1_m492_RA10)  - последнее задание назад
#define internal1_m492_MyFirstEnterFlag	 BUFFER[2787]	//(internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m492_MyFirstEnterFlag	 816	//(internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m479_Pav0	 BUFFER[2789]	//(internal1_m479_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m479_Pav0	 817	//(internal1_m479_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m479_Zav0	 BUFFER[2791]	//(internal1_m479_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m479_Zav0	 818	//(internal1_m479_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m479_Pv0	 BUFFER[2793]	//(internal1_m479_Pv0)  - Пер. выключатель механизма
#define idinternal1_m479_Pv0	 819	//(internal1_m479_Pv0)  - Пер. выключатель механизма
#define internal1_m479_Zv0	 BUFFER[2795]	//(internal1_m479_Zv0)  - Зад. выключатель механизма
#define idinternal1_m479_Zv0	 820	//(internal1_m479_Zv0)  - Зад. выключатель механизма
#define internal1_m479_RA00	 BUFFER[2797]	//(internal1_m479_RA00)  - последнее задание вперед
#define idinternal1_m479_RA00	 821	//(internal1_m479_RA00)  - последнее задание вперед
#define internal1_m479_RA10	 BUFFER[2799]	//(internal1_m479_RA10)  - последнее задание назад
#define idinternal1_m479_RA10	 822	//(internal1_m479_RA10)  - последнее задание назад
#define internal1_m479_MyFirstEnterFlag	 BUFFER[2801]	//(internal1_m479_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m479_MyFirstEnterFlag	 823	//(internal1_m479_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m621_Pav0	 BUFFER[2803]	//(internal1_m621_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m621_Pav0	 824	//(internal1_m621_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m621_Zav0	 BUFFER[2805]	//(internal1_m621_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m621_Zav0	 825	//(internal1_m621_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m621_Pv0	 BUFFER[2807]	//(internal1_m621_Pv0)  - Пер. выключатель механизма
#define idinternal1_m621_Pv0	 826	//(internal1_m621_Pv0)  - Пер. выключатель механизма
#define internal1_m621_Zv0	 BUFFER[2809]	//(internal1_m621_Zv0)  - Зад. выключатель механизма
#define idinternal1_m621_Zv0	 827	//(internal1_m621_Zv0)  - Зад. выключатель механизма
#define internal1_m621_RA00	 BUFFER[2811]	//(internal1_m621_RA00)  - последнее задание вперед
#define idinternal1_m621_RA00	 828	//(internal1_m621_RA00)  - последнее задание вперед
#define internal1_m621_RA10	 BUFFER[2813]	//(internal1_m621_RA10)  - последнее задание назад
#define idinternal1_m621_RA10	 829	//(internal1_m621_RA10)  - последнее задание назад
#define internal1_m621_MyFirstEnterFlag	 BUFFER[2815]	//(internal1_m621_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m621_MyFirstEnterFlag	 830	//(internal1_m621_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m620_Pav0	 BUFFER[2817]	//(internal1_m620_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m620_Pav0	 831	//(internal1_m620_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m620_Zav0	 BUFFER[2819]	//(internal1_m620_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m620_Zav0	 832	//(internal1_m620_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m620_Pv0	 BUFFER[2821]	//(internal1_m620_Pv0)  - Пер. выключатель механизма
#define idinternal1_m620_Pv0	 833	//(internal1_m620_Pv0)  - Пер. выключатель механизма
#define internal1_m620_Zv0	 BUFFER[2823]	//(internal1_m620_Zv0)  - Зад. выключатель механизма
#define idinternal1_m620_Zv0	 834	//(internal1_m620_Zv0)  - Зад. выключатель механизма
#define internal1_m620_RA00	 BUFFER[2825]	//(internal1_m620_RA00)  - последнее задание вперед
#define idinternal1_m620_RA00	 835	//(internal1_m620_RA00)  - последнее задание вперед
#define internal1_m620_RA10	 BUFFER[2827]	//(internal1_m620_RA10)  - последнее задание назад
#define idinternal1_m620_RA10	 836	//(internal1_m620_RA10)  - последнее задание назад
#define internal1_m620_MyFirstEnterFlag	 BUFFER[2829]	//(internal1_m620_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m620_MyFirstEnterFlag	 837	//(internal1_m620_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m606_Pav0	 BUFFER[2831]	//(internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m606_Pav0	 838	//(internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m606_Zav0	 BUFFER[2833]	//(internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m606_Zav0	 839	//(internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m606_Pv0	 BUFFER[2835]	//(internal1_m606_Pv0)  - Пер. выключатель механизма
#define idinternal1_m606_Pv0	 840	//(internal1_m606_Pv0)  - Пер. выключатель механизма
#define internal1_m606_Zv0	 BUFFER[2837]	//(internal1_m606_Zv0)  - Зад. выключатель механизма
#define idinternal1_m606_Zv0	 841	//(internal1_m606_Zv0)  - Зад. выключатель механизма
#define internal1_m606_RA00	 BUFFER[2839]	//(internal1_m606_RA00)  - последнее задание вперед
#define idinternal1_m606_RA00	 842	//(internal1_m606_RA00)  - последнее задание вперед
#define internal1_m606_RA10	 BUFFER[2841]	//(internal1_m606_RA10)  - последнее задание назад
#define idinternal1_m606_RA10	 843	//(internal1_m606_RA10)  - последнее задание назад
#define internal1_m606_MyFirstEnterFlag	 BUFFER[2843]	//(internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m606_MyFirstEnterFlag	 844	//(internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m605_Pav0	 BUFFER[2845]	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m605_Pav0	 845	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m605_Zav0	 BUFFER[2847]	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m605_Zav0	 846	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m605_Pv0	 BUFFER[2849]	//(internal1_m605_Pv0)  - Пер. выключатель механизма
#define idinternal1_m605_Pv0	 847	//(internal1_m605_Pv0)  - Пер. выключатель механизма
#define internal1_m605_Zv0	 BUFFER[2851]	//(internal1_m605_Zv0)  - Зад. выключатель механизма
#define idinternal1_m605_Zv0	 848	//(internal1_m605_Zv0)  - Зад. выключатель механизма
#define internal1_m605_RA00	 BUFFER[2853]	//(internal1_m605_RA00)  - последнее задание вперед
#define idinternal1_m605_RA00	 849	//(internal1_m605_RA00)  - последнее задание вперед
#define internal1_m605_RA10	 BUFFER[2855]	//(internal1_m605_RA10)  - последнее задание назад
#define idinternal1_m605_RA10	 850	//(internal1_m605_RA10)  - последнее задание назад
#define internal1_m605_MyFirstEnterFlag	 BUFFER[2857]	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m605_MyFirstEnterFlag	 851	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m652_y0	 BUFFER[2859]	//(internal1_m652_y0) y0 - внутренний параметр
#define idinternal1_m652_y0	 852	//(internal1_m652_y0) y0 - внутренний параметр
#define internal1_m815_Chim0	 BUFFER[2864]	//(internal1_m815_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m815_Chim0	 853	//(internal1_m815_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m806_Chim0	 BUFFER[2869]	//(internal1_m806_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m806_Chim0	 854	//(internal1_m806_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m798_Chim0	 BUFFER[2874]	//(internal1_m798_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m798_Chim0	 855	//(internal1_m798_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m789_Chim0	 BUFFER[2879]	//(internal1_m789_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m789_Chim0	 856	//(internal1_m789_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m780_Chim0	 BUFFER[2884]	//(internal1_m780_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m780_Chim0	 857	//(internal1_m780_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m772_Chim0	 BUFFER[2889]	//(internal1_m772_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m772_Chim0	 858	//(internal1_m772_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m763_Chim0	 BUFFER[2894]	//(internal1_m763_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m763_Chim0	 859	//(internal1_m763_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m754_Chim0	 BUFFER[2899]	//(internal1_m754_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m754_Chim0	 860	//(internal1_m754_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m746_Chim0	 BUFFER[2904]	//(internal1_m746_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m746_Chim0	 861	//(internal1_m746_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m737_Chim0	 BUFFER[2909]	//(internal1_m737_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m737_Chim0	 862	//(internal1_m737_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m728_Chim0	 BUFFER[2914]	//(internal1_m728_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m728_Chim0	 863	//(internal1_m728_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m719_Chim0	 BUFFER[2919]	//(internal1_m719_Chim0) измеренная частота импульсов камеры Гц
#define idinternal1_m719_Chim0	 864	//(internal1_m719_Chim0) измеренная частота импульсов камеры Гц
#define internal1_m592_Pav0	 BUFFER[2924]	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m592_Pav0	 865	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m592_Zav0	 BUFFER[2926]	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m592_Zav0	 866	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m592_Pv0	 BUFFER[2928]	//(internal1_m592_Pv0)  - Пер. выключатель механизма
#define idinternal1_m592_Pv0	 867	//(internal1_m592_Pv0)  - Пер. выключатель механизма
#define internal1_m592_Zv0	 BUFFER[2930]	//(internal1_m592_Zv0)  - Зад. выключатель механизма
#define idinternal1_m592_Zv0	 868	//(internal1_m592_Zv0)  - Зад. выключатель механизма
#define internal1_m592_RA00	 BUFFER[2932]	//(internal1_m592_RA00)  - последнее задание вперед
#define idinternal1_m592_RA00	 869	//(internal1_m592_RA00)  - последнее задание вперед
#define internal1_m592_RA10	 BUFFER[2934]	//(internal1_m592_RA10)  - последнее задание назад
#define idinternal1_m592_RA10	 870	//(internal1_m592_RA10)  - последнее задание назад
#define internal1_m592_MyFirstEnterFlag	 BUFFER[2936]	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m592_MyFirstEnterFlag	 871	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m577_Pav0	 BUFFER[2938]	//(internal1_m577_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m577_Pav0	 872	//(internal1_m577_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m577_Zav0	 BUFFER[2940]	//(internal1_m577_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m577_Zav0	 873	//(internal1_m577_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m577_Pv0	 BUFFER[2942]	//(internal1_m577_Pv0)  - Пер. выключатель механизма
#define idinternal1_m577_Pv0	 874	//(internal1_m577_Pv0)  - Пер. выключатель механизма
#define internal1_m577_Zv0	 BUFFER[2944]	//(internal1_m577_Zv0)  - Зад. выключатель механизма
#define idinternal1_m577_Zv0	 875	//(internal1_m577_Zv0)  - Зад. выключатель механизма
#define internal1_m577_RA00	 BUFFER[2946]	//(internal1_m577_RA00)  - последнее задание вперед
#define idinternal1_m577_RA00	 876	//(internal1_m577_RA00)  - последнее задание вперед
#define internal1_m577_RA10	 BUFFER[2948]	//(internal1_m577_RA10)  - последнее задание назад
#define idinternal1_m577_RA10	 877	//(internal1_m577_RA10)  - последнее задание назад
#define internal1_m577_MyFirstEnterFlag	 BUFFER[2950]	//(internal1_m577_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m577_MyFirstEnterFlag	 878	//(internal1_m577_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m463_Pav0	 BUFFER[2952]	//(internal1_m463_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m463_Pav0	 879	//(internal1_m463_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m463_Zav0	 BUFFER[2954]	//(internal1_m463_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m463_Zav0	 880	//(internal1_m463_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m463_Pv0	 BUFFER[2956]	//(internal1_m463_Pv0)  - Пер. выключатель механизма
#define idinternal1_m463_Pv0	 881	//(internal1_m463_Pv0)  - Пер. выключатель механизма
#define internal1_m463_Zv0	 BUFFER[2958]	//(internal1_m463_Zv0)  - Зад. выключатель механизма
#define idinternal1_m463_Zv0	 882	//(internal1_m463_Zv0)  - Зад. выключатель механизма
#define internal1_m463_RA00	 BUFFER[2960]	//(internal1_m463_RA00)  - последнее задание вперед
#define idinternal1_m463_RA00	 883	//(internal1_m463_RA00)  - последнее задание вперед
#define internal1_m463_RA10	 BUFFER[2962]	//(internal1_m463_RA10)  - последнее задание назад
#define idinternal1_m463_RA10	 884	//(internal1_m463_RA10)  - последнее задание назад
#define internal1_m463_MyFirstEnterFlag	 BUFFER[2964]	//(internal1_m463_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m463_MyFirstEnterFlag	 885	//(internal1_m463_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m448_Pav0	 BUFFER[2966]	//(internal1_m448_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m448_Pav0	 886	//(internal1_m448_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m448_Zav0	 BUFFER[2968]	//(internal1_m448_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m448_Zav0	 887	//(internal1_m448_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m448_Pv0	 BUFFER[2970]	//(internal1_m448_Pv0)  - Пер. выключатель механизма
#define idinternal1_m448_Pv0	 888	//(internal1_m448_Pv0)  - Пер. выключатель механизма
#define internal1_m448_Zv0	 BUFFER[2972]	//(internal1_m448_Zv0)  - Зад. выключатель механизма
#define idinternal1_m448_Zv0	 889	//(internal1_m448_Zv0)  - Зад. выключатель механизма
#define internal1_m448_RA00	 BUFFER[2974]	//(internal1_m448_RA00)  - последнее задание вперед
#define idinternal1_m448_RA00	 890	//(internal1_m448_RA00)  - последнее задание вперед
#define internal1_m448_RA10	 BUFFER[2976]	//(internal1_m448_RA10)  - последнее задание назад
#define idinternal1_m448_RA10	 891	//(internal1_m448_RA10)  - последнее задание назад
#define internal1_m448_MyFirstEnterFlag	 BUFFER[2978]	//(internal1_m448_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m448_MyFirstEnterFlag	 892	//(internal1_m448_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m504_Pav0	 BUFFER[2980]	//(internal1_m504_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m504_Pav0	 893	//(internal1_m504_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m504_Zav0	 BUFFER[2982]	//(internal1_m504_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m504_Zav0	 894	//(internal1_m504_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m504_Pv0	 BUFFER[2984]	//(internal1_m504_Pv0)  - Пер. выключатель механизма
#define idinternal1_m504_Pv0	 895	//(internal1_m504_Pv0)  - Пер. выключатель механизма
#define internal1_m504_Zv0	 BUFFER[2986]	//(internal1_m504_Zv0)  - Зад. выключатель механизма
#define idinternal1_m504_Zv0	 896	//(internal1_m504_Zv0)  - Зад. выключатель механизма
#define internal1_m504_RA00	 BUFFER[2988]	//(internal1_m504_RA00)  - последнее задание вперед
#define idinternal1_m504_RA00	 897	//(internal1_m504_RA00)  - последнее задание вперед
#define internal1_m504_RA10	 BUFFER[2990]	//(internal1_m504_RA10)  - последнее задание назад
#define idinternal1_m504_RA10	 898	//(internal1_m504_RA10)  - последнее задание назад
#define internal1_m504_MyFirstEnterFlag	 BUFFER[2992]	//(internal1_m504_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m504_MyFirstEnterFlag	 899	//(internal1_m504_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m399_Pav0	 BUFFER[2994]	//(internal1_m399_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m399_Pav0	 900	//(internal1_m399_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m399_Zav0	 BUFFER[2996]	//(internal1_m399_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m399_Zav0	 901	//(internal1_m399_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m399_Pv0	 BUFFER[2998]	//(internal1_m399_Pv0)  - Пер. выключатель механизма
#define idinternal1_m399_Pv0	 902	//(internal1_m399_Pv0)  - Пер. выключатель механизма
#define internal1_m399_Zv0	 BUFFER[3000]	//(internal1_m399_Zv0)  - Зад. выключатель механизма
#define idinternal1_m399_Zv0	 903	//(internal1_m399_Zv0)  - Зад. выключатель механизма
#define internal1_m399_RA00	 BUFFER[3002]	//(internal1_m399_RA00)  - последнее задание вперед
#define idinternal1_m399_RA00	 904	//(internal1_m399_RA00)  - последнее задание вперед
#define internal1_m399_RA10	 BUFFER[3004]	//(internal1_m399_RA10)  - последнее задание назад
#define idinternal1_m399_RA10	 905	//(internal1_m399_RA10)  - последнее задание назад
#define internal1_m399_MyFirstEnterFlag	 BUFFER[3006]	//(internal1_m399_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m399_MyFirstEnterFlag	 906	//(internal1_m399_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m383_Pav0	 BUFFER[3008]	//(internal1_m383_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m383_Pav0	 907	//(internal1_m383_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m383_Zav0	 BUFFER[3010]	//(internal1_m383_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m383_Zav0	 908	//(internal1_m383_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m383_Pv0	 BUFFER[3012]	//(internal1_m383_Pv0)  - Пер. выключатель механизма
#define idinternal1_m383_Pv0	 909	//(internal1_m383_Pv0)  - Пер. выключатель механизма
#define internal1_m383_Zv0	 BUFFER[3014]	//(internal1_m383_Zv0)  - Зад. выключатель механизма
#define idinternal1_m383_Zv0	 910	//(internal1_m383_Zv0)  - Зад. выключатель механизма
#define internal1_m383_RA00	 BUFFER[3016]	//(internal1_m383_RA00)  - последнее задание вперед
#define idinternal1_m383_RA00	 911	//(internal1_m383_RA00)  - последнее задание вперед
#define internal1_m383_RA10	 BUFFER[3018]	//(internal1_m383_RA10)  - последнее задание назад
#define idinternal1_m383_RA10	 912	//(internal1_m383_RA10)  - последнее задание назад
#define internal1_m383_MyFirstEnterFlag	 BUFFER[3020]	//(internal1_m383_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m383_MyFirstEnterFlag	 913	//(internal1_m383_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m366_Pav0	 BUFFER[3022]	//(internal1_m366_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m366_Pav0	 914	//(internal1_m366_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m366_Zav0	 BUFFER[3024]	//(internal1_m366_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m366_Zav0	 915	//(internal1_m366_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m366_Pv0	 BUFFER[3026]	//(internal1_m366_Pv0)  - Пер. выключатель механизма
#define idinternal1_m366_Pv0	 916	//(internal1_m366_Pv0)  - Пер. выключатель механизма
#define internal1_m366_Zv0	 BUFFER[3028]	//(internal1_m366_Zv0)  - Зад. выключатель механизма
#define idinternal1_m366_Zv0	 917	//(internal1_m366_Zv0)  - Зад. выключатель механизма
#define internal1_m366_RA00	 BUFFER[3030]	//(internal1_m366_RA00)  - последнее задание вперед
#define idinternal1_m366_RA00	 918	//(internal1_m366_RA00)  - последнее задание вперед
#define internal1_m366_RA10	 BUFFER[3032]	//(internal1_m366_RA10)  - последнее задание назад
#define idinternal1_m366_RA10	 919	//(internal1_m366_RA10)  - последнее задание назад
#define internal1_m366_MyFirstEnterFlag	 BUFFER[3034]	//(internal1_m366_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m366_MyFirstEnterFlag	 920	//(internal1_m366_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m908_Pav0	 BUFFER[3036]	//(internal1_m908_Pav0)  - Пер.аварийный выключатель механизма
#define idinternal1_m908_Pav0	 921	//(internal1_m908_Pav0)  - Пер.аварийный выключатель механизма
#define internal1_m908_Zav0	 BUFFER[3038]	//(internal1_m908_Zav0)  - Зад.аварийный выключатель механизма
#define idinternal1_m908_Zav0	 922	//(internal1_m908_Zav0)  - Зад.аварийный выключатель механизма
#define internal1_m908_Pv0	 BUFFER[3040]	//(internal1_m908_Pv0)  - Пер. выключатель механизма
#define idinternal1_m908_Pv0	 923	//(internal1_m908_Pv0)  - Пер. выключатель механизма
#define internal1_m908_Zv0	 BUFFER[3042]	//(internal1_m908_Zv0)  - Зад. выключатель механизма
#define idinternal1_m908_Zv0	 924	//(internal1_m908_Zv0)  - Зад. выключатель механизма
#define internal1_m908_RA00	 BUFFER[3044]	//(internal1_m908_RA00)  - последнее задание вперед
#define idinternal1_m908_RA00	 925	//(internal1_m908_RA00)  - последнее задание вперед
#define internal1_m908_RA10	 BUFFER[3046]	//(internal1_m908_RA10)  - последнее задание назад
#define idinternal1_m908_RA10	 926	//(internal1_m908_RA10)  - последнее задание назад
#define internal1_m908_MyFirstEnterFlag	 BUFFER[3048]	//(internal1_m908_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m908_MyFirstEnterFlag	 927	//(internal1_m908_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m182_C1	 BUFFER[3050]	//(internal1_m182_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m182_C1	 928	//(internal1_m182_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m182_C2	 BUFFER[3055]	//(internal1_m182_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m182_C2	 929	//(internal1_m182_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m182_C3	 BUFFER[3060]	//(internal1_m182_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m182_C3	 930	//(internal1_m182_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m182_C4	 BUFFER[3065]	//(internal1_m182_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m182_C4	 931	//(internal1_m182_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m182_C5	 BUFFER[3070]	//(internal1_m182_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m182_C5	 932	//(internal1_m182_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m182_C6	 BUFFER[3075]	//(internal1_m182_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m182_C6	 933	//(internal1_m182_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m182_N20	 BUFFER[3080]	//(internal1_m182_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m182_N20	 934	//(internal1_m182_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m182_C0	 BUFFER[3085]	//(internal1_m182_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m182_C0	 935	//(internal1_m182_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m182_ImpINI0	 BUFFER[3115]	//(internal1_m182_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m182_ImpINI0	 936	//(internal1_m182_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m182_MyFirstEnterFlag	 BUFFER[3117]	//(internal1_m182_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m182_MyFirstEnterFlag	 937	//(internal1_m182_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m300_Ppv0	 BUFFER[3119]	//(internal1_m300_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m300_Ppv0	 938	//(internal1_m300_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m300_Pav0	 BUFFER[3121]	//(internal1_m300_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m300_Pav0	 939	//(internal1_m300_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m300_Zav0	 BUFFER[3123]	//(internal1_m300_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m300_Zav0	 940	//(internal1_m300_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m300_RA00	 BUFFER[3125]	//(internal1_m300_RA00) RA00 - последнее задание вперед
#define idinternal1_m300_RA00	 941	//(internal1_m300_RA00) RA00 - последнее задание вперед
#define internal1_m300_RA10	 BUFFER[3127]	//(internal1_m300_RA10) RA10 - последнее задание назад
#define idinternal1_m300_RA10	 942	//(internal1_m300_RA10) RA10 - последнее задание назад
#define internal1_m300_RA50	 BUFFER[3129]	//(internal1_m300_RA50) Ra50 - последнее задание скорости
#define idinternal1_m300_RA50	 943	//(internal1_m300_RA50) Ra50 - последнее задание скорости
#define internal1_m300_fls	 BUFFER[3130]	//(internal1_m300_fls)  fls - флаг одношагового режима
#define idinternal1_m300_fls	 944	//(internal1_m300_fls)  fls - флаг одношагового режима
#define internal1_m300_flp	 BUFFER[3132]	//(internal1_m300_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m300_flp	 945	//(internal1_m300_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m300_MyFirstEnterFlag	 BUFFER[3134]	//(internal1_m300_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m300_MyFirstEnterFlag	 946	//(internal1_m300_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m130_Ppv0	 BUFFER[3136]	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m130_Ppv0	 947	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m130_Pav0	 BUFFER[3138]	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m130_Pav0	 948	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m130_Zav0	 BUFFER[3140]	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m130_Zav0	 949	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m130_RA00	 BUFFER[3142]	//(internal1_m130_RA00) RA00 - последнее задание вперед
#define idinternal1_m130_RA00	 950	//(internal1_m130_RA00) RA00 - последнее задание вперед
#define internal1_m130_RA10	 BUFFER[3144]	//(internal1_m130_RA10) RA10 - последнее задание назад
#define idinternal1_m130_RA10	 951	//(internal1_m130_RA10) RA10 - последнее задание назад
#define internal1_m130_RA50	 BUFFER[3146]	//(internal1_m130_RA50) Ra50 - последнее задание скорости
#define idinternal1_m130_RA50	 952	//(internal1_m130_RA50) Ra50 - последнее задание скорости
#define internal1_m130_fls	 BUFFER[3147]	//(internal1_m130_fls)  fls - флаг одношагового режима
#define idinternal1_m130_fls	 953	//(internal1_m130_fls)  fls - флаг одношагового режима
#define internal1_m130_flp	 BUFFER[3149]	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m130_flp	 954	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m130_MyFirstEnterFlag	 BUFFER[3151]	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m130_MyFirstEnterFlag	 955	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m267_Ppv0	 BUFFER[3153]	//(internal1_m267_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m267_Ppv0	 956	//(internal1_m267_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m267_Pav0	 BUFFER[3155]	//(internal1_m267_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m267_Pav0	 957	//(internal1_m267_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m267_Zav0	 BUFFER[3157]	//(internal1_m267_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m267_Zav0	 958	//(internal1_m267_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m267_RA00	 BUFFER[3159]	//(internal1_m267_RA00) RA00 - последнее задание вперед
#define idinternal1_m267_RA00	 959	//(internal1_m267_RA00) RA00 - последнее задание вперед
#define internal1_m267_RA10	 BUFFER[3161]	//(internal1_m267_RA10) RA10 - последнее задание назад
#define idinternal1_m267_RA10	 960	//(internal1_m267_RA10) RA10 - последнее задание назад
#define internal1_m267_RA50	 BUFFER[3163]	//(internal1_m267_RA50) Ra50 - последнее задание скорости
#define idinternal1_m267_RA50	 961	//(internal1_m267_RA50) Ra50 - последнее задание скорости
#define internal1_m267_fls	 BUFFER[3164]	//(internal1_m267_fls)  fls - флаг одношагового режима
#define idinternal1_m267_fls	 962	//(internal1_m267_fls)  fls - флаг одношагового режима
#define internal1_m267_flp	 BUFFER[3166]	//(internal1_m267_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m267_flp	 963	//(internal1_m267_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m267_MyFirstEnterFlag	 BUFFER[3168]	//(internal1_m267_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m267_MyFirstEnterFlag	 964	//(internal1_m267_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m96_Ppv0	 BUFFER[3170]	//(internal1_m96_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m96_Ppv0	 965	//(internal1_m96_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m96_Pav0	 BUFFER[3172]	//(internal1_m96_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m96_Pav0	 966	//(internal1_m96_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m96_Zav0	 BUFFER[3174]	//(internal1_m96_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m96_Zav0	 967	//(internal1_m96_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m96_RA00	 BUFFER[3176]	//(internal1_m96_RA00) RA00 - последнее задание вперед
#define idinternal1_m96_RA00	 968	//(internal1_m96_RA00) RA00 - последнее задание вперед
#define internal1_m96_RA10	 BUFFER[3178]	//(internal1_m96_RA10) RA10 - последнее задание назад
#define idinternal1_m96_RA10	 969	//(internal1_m96_RA10) RA10 - последнее задание назад
#define internal1_m96_RA50	 BUFFER[3180]	//(internal1_m96_RA50) Ra50 - последнее задание скорости
#define idinternal1_m96_RA50	 970	//(internal1_m96_RA50) Ra50 - последнее задание скорости
#define internal1_m96_fls	 BUFFER[3181]	//(internal1_m96_fls)  fls - флаг одношагового режима
#define idinternal1_m96_fls	 971	//(internal1_m96_fls)  fls - флаг одношагового режима
#define internal1_m96_flp	 BUFFER[3183]	//(internal1_m96_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m96_flp	 972	//(internal1_m96_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m96_MyFirstEnterFlag	 BUFFER[3185]	//(internal1_m96_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m96_MyFirstEnterFlag	 973	//(internal1_m96_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m229_Ppv0	 BUFFER[3187]	//(internal1_m229_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m229_Ppv0	 974	//(internal1_m229_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m229_Pav0	 BUFFER[3189]	//(internal1_m229_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m229_Pav0	 975	//(internal1_m229_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m229_Zav0	 BUFFER[3191]	//(internal1_m229_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m229_Zav0	 976	//(internal1_m229_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m229_RA00	 BUFFER[3193]	//(internal1_m229_RA00) RA00 - последнее задание вперед
#define idinternal1_m229_RA00	 977	//(internal1_m229_RA00) RA00 - последнее задание вперед
#define internal1_m229_RA10	 BUFFER[3195]	//(internal1_m229_RA10) RA10 - последнее задание назад
#define idinternal1_m229_RA10	 978	//(internal1_m229_RA10) RA10 - последнее задание назад
#define internal1_m229_RA50	 BUFFER[3197]	//(internal1_m229_RA50) Ra50 - последнее задание скорости
#define idinternal1_m229_RA50	 979	//(internal1_m229_RA50) Ra50 - последнее задание скорости
#define internal1_m229_fls	 BUFFER[3198]	//(internal1_m229_fls)  fls - флаг одношагового режима
#define idinternal1_m229_fls	 980	//(internal1_m229_fls)  fls - флаг одношагового режима
#define internal1_m229_flp	 BUFFER[3200]	//(internal1_m229_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m229_flp	 981	//(internal1_m229_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m229_MyFirstEnterFlag	 BUFFER[3202]	//(internal1_m229_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m229_MyFirstEnterFlag	 982	//(internal1_m229_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m60_Ppv0	 BUFFER[3204]	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define idinternal1_m60_Ppv0	 983	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
#define internal1_m60_Pav0	 BUFFER[3206]	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define idinternal1_m60_Pav0	 984	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
#define internal1_m60_Zav0	 BUFFER[3208]	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define idinternal1_m60_Zav0	 985	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
#define internal1_m60_RA00	 BUFFER[3210]	//(internal1_m60_RA00) RA00 - последнее задание вперед
#define idinternal1_m60_RA00	 986	//(internal1_m60_RA00) RA00 - последнее задание вперед
#define internal1_m60_RA10	 BUFFER[3212]	//(internal1_m60_RA10) RA10 - последнее задание назад
#define idinternal1_m60_RA10	 987	//(internal1_m60_RA10) RA10 - последнее задание назад
#define internal1_m60_RA50	 BUFFER[3214]	//(internal1_m60_RA50) Ra50 - последнее задание скорости
#define idinternal1_m60_RA50	 988	//(internal1_m60_RA50) Ra50 - последнее задание скорости
#define internal1_m60_fls	 BUFFER[3215]	//(internal1_m60_fls)  fls - флаг одношагового режима
#define idinternal1_m60_fls	 989	//(internal1_m60_fls)  fls - флаг одношагового режима
#define internal1_m60_flp	 BUFFER[3217]	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define idinternal1_m60_flp	 990	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
#define internal1_m60_MyFirstEnterFlag	 BUFFER[3219]	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m60_MyFirstEnterFlag	 991	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
#define internal1_m14_C1	 BUFFER[3221]	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define idinternal1_m14_C1	 992	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
#define internal1_m14_C2	 BUFFER[3226]	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define idinternal1_m14_C2	 993	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
#define internal1_m14_C3	 BUFFER[3231]	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define idinternal1_m14_C3	 994	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
#define internal1_m14_C4	 BUFFER[3236]	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define idinternal1_m14_C4	 995	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
#define internal1_m14_C5	 BUFFER[3241]	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define idinternal1_m14_C5	 996	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
#define internal1_m14_C6	 BUFFER[3246]	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define idinternal1_m14_C6	 997	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
#define internal1_m14_N20	 BUFFER[3251]	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define idinternal1_m14_N20	 998	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
#define internal1_m14_C0	 BUFFER[3256]	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define idinternal1_m14_C0	 999	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
#define internal1_m14_ImpINI0	 BUFFER[3286]	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define idinternal1_m14_ImpINI0	 1000	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
#define internal1_m14_MyFirstEnterFlag	 BUFFER[3288]	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#define idinternal1_m14_MyFirstEnterFlag	 1001	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
#pragma pack(push,1)
static VarCtrl allVariables[]={      // Описание всех переменных
	{ 1	,1	,1	, &A1IS11LDU},	//(do32_pti:140 - K01DO, - ) Приход на ВУ ББ1
	{ 2	,1	,1	, &A1IS21LDU},	//(do32_pti:140 - K02DO, - ) Приход на НУ ББ1
	{ 3	,1	,1	, &B6IS21LDU},	//(do32_pti:140 - K31DO, - ) Приход на НУ БЗ2
	{ 4	,1	,1	, &B6IS11LDU},	//(do32_pti:140 - K30DO, - ) Приход на ВУ БЗ2
	{ 5	,1	,1	, &A6IS21LDU},	//(do32_pti:140 - K27DO, - ) Приход на НУ БЗ1
	{ 6	,1	,1	, &A6IS11LDU},	//(do32_pti:150 - K18DO, - ) Приход на ВУ БЗ1
	{ 7	,1	,1	, &A8IS12LDU},	//(do32_pti:150 - K15DO, - ) Приход на механический ВУ ДС2
	{ 8	,1	,1	, &A8IS22LDU},	//(do32_pti:150 - K16DO, - ) Приход на механический НУ ДС2
	{ 9	,1	,1	, &B8IS12LDU},	//(do32_pti:150 - K06DO, - ) Приход на ВУ2 АЗ2
	{ 10	,1	,1	, &B8IS22LDU},	//(do32_pti:150 - K07DO, - ) Приход на НУ2 АЗ2
	{ 11	,1	,1	, &R4IS12LDU},	//(do32_pti:140 - K23DO, - ) Приход на  ВУ2 тележки
	{ 12	,1	,1	, &R4IS22LDU},	//(do32_pti:140 - K25DO, - ) Приход на НУ2 тележки
	{ 13	,1	,1	, &R4IS21LDU},	//(do32_pti:140 - K24DO, - ) Приход на НУ1 тележки
	{ 14	,1	,1	, &R4IS11LDU},	//(do32_pti:140 - K22DO, - ) Приход на ВУ1 тележки
	{ 15	,1	,1	, &B4VP82LDU},	//( - , SDu) Давление ПОДЪЁМ НИ2 в норме
	{ 16	,1	,1	, &A4VP82LDU},	//( - , SDu) Давление ПОДЪЁМ НИ1 в норме
	{ 17	,1	,1	, &R2IS21LDU},	//(do32_pti:130 - K25DO, - ) Приход на НУ МДЗ2
	{ 18	,1	,1	, &R0EE04LZ1},	//( - , SBz1) Питание  АКНП4  отключить
	{ 19	,1	,1	, &R0EE03LZ1},	//( - , SBz1) Питание  АКНП3  отключить
	{ 20	,1	,1	, &R0EE02LZ1},	//( - , SBz1) Питание  АКНП  отключить
	{ 21	,1	,1	, &R0EE01LZ2},	//( - , SBz2) Питание  АКНП1  отключить
	{ 22	,1	,1	, &R0EE01LZ1},	//( - , SBz1) Питание  АКНП1  отключить
	{ 23	,1	,1	, &B4IS10LDU},	//( - , - ) Клапан (Подъём НИ2) открыт (обесточен)
	{ 24	,1	,1	, &A4IS10LDU},	//( - , - ) Клапан (Подъём НИ1) открыт (обесточен)
	{ 25	,1	,1	, &B1IE04LDU},	//( - , SCM) Движение ББ2 назад (от БУШД)
	{ 26	,1	,1	, &B1IE03LDU},	//( - , SCM) Движение ББ2 вперед (от БУШД)
	{ 27	,1	,1	, &A1IE04LDU},	//( - , SCM) Движение ББ1 назад (от БУШД)
	{ 28	,1	,1	, &A1IE03LDU},	//( - , SCM) Движение ББ1 вперед (от БУШД)
	{ 29	,1	,1	, &B1IS12LDU},	//(do32_pti:130 - K07DO, - ) Магнит ББ2 зацеплен
	{ 30	,1	,1	, &B1IS11LDU},	//(do32_pti:130 - K08DO, - ) Приход на ВУ ББ2
	{ 31	,1	,1	, &B1IS21LDU},	//(do32_pti:130 - K09DO, - ) Приход на НУ ББ2
	{ 32	,5	,1	, &B1IC01UDU},	//( - , SDu) Координата штока ББ2
	{ 33	,5	,1	, &A1IC01UDU},	//( - , SDu) Координата штока ББ1
	{ 34	,1	,1	, &A1IS12LDU},	//(do32_pti:130 - K32DO, - ) Магнит ББ1 зацеплен
	{ 35	,1	,1	, &B2IS21LDU},	//(do32_pti:130 - K12DO, - ) Приход на НУ РБ2
	{ 36	,1	,1	, &B9IS21LDU},	//(do32_pti:130 - K21DO, - ) Приход на НУ НИ ДС2
	{ 37	,1	,1	, &B9IS11LDU},	//(do32_pti:130 - K20DO, - ) Приход на ВУ НИ ДС2
	{ 38	,1	,1	, &A9IS21LDU},	//(do32_pti:130 - K19DO, - ) Приход на НУ НИ ДС1
	{ 39	,1	,1	, &A9IS11LDU},	//(do32_pti:130 - K18DO, - ) Приход на ВУ НИ ДС1
	{ 40	,1	,1	, &B5IS21LDU},	//(do32_pti:150 - K01DO, - ) Приход на НУ НЛ2
	{ 41	,1	,1	, &B5IS11LDU},	//(do32_pti:140 - K32DO, - ) Приход на ВУ НЛ2
	{ 42	,1	,1	, &A5IS21LDU},	//(do32_pti:140 - K29DO, - ) Приход на НУ НЛ1
	{ 43	,1	,1	, &A5IS11LDU},	//(do32_pti:140 - K28DO, - ) Приход на ВУ НЛ1
	{ 44	,1	,1	, &B0VP81LZZ},	//(do32_pti:110 - K30DO, - ) Давление АЗ2 в норме
	{ 45	,1	,1	, &A0VP81LZZ},	//(do32_pti:100 - K27DO, - ) Давление АЗ1 в норме
	{ 46	,5	,1	, &B8IC01UDU},	//( - , SDu) Координата АЗ2
	{ 47	,5	,1	, &A8IC01UDU},	//( - , SDu) Координата ДС2
	{ 48	,1	,1	, &R6IS68LZZ},	//(do32_pti:100 - K19DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№7) ССДИ-2
	{ 49	,1	,1	, &R6IS67LZZ},	//(do32_pti:100 - K18DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 50	,1	,1	, &R6IS66LZZ},	//(do32_pti:100 - K17DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 51	,1	,1	, &R6IS65LDU},	//(do32_pti:160 - K32DO, - ) Исправность ВИП ССДИ-35 2канал
	{ 52	,1	,1	, &R2IS11LDU},	//(do32_pti:130 - K24DO, - ) Приход на ВУ МДЗ2
	{ 53	,1	,1	, &R1IS21LDU},	//(do32_pti:130 - K23DO, - ) Приход на НУ МДЗ1
	{ 54	,1	,1	, &R1IS11LDU},	//(do32_pti:130 - K22DO, - ) Приход на ВУ МДЗ1
	{ 55	,1	,1	, &B4IS21LDU},	//(do32_pti:140 - K08DO, SCM) Приход на НУ НИ2
	{ 56	,1	,1	, &B4IS11LDU},	//(do32_pti:140 - K07DO, - ) Приход на ВУ НИ2
	{ 57	,1	,1	, &R8IS11LDU},	//(do32_pti:130 - K14DO, - ) Аварийный НИ установлен
	{ 58	,1	,1	, &A4IS21LDU},	//(do32_pti:130 - K17DO, - ) Приход на НУ НИ1
	{ 59	,1	,1	, &A4IS11LDU},	//(do32_pti:130 - K16DO, - ) Приход на ВУ НИ1
	{ 60	,1	,1	, &R5IS21LDU},	//(do32_pti:150 - K11DO, - ) Приход на НУ ворот отстойной зоны
	{ 61	,1	,1	, &R5IS11LDU},	//(do32_pti:150 - K10DO, - ) Приход на ВУ ворот отстойной зоны
	{ 62	,1	,1	, &R3IS21LDU},	//(do32_pti:150 - K03DO, - ) Приход на НУ гомогенных дверей
	{ 63	,1	,1	, &R3IS11LDU},	//(do32_pti:150 - K02DO, - ) Приход на ВУ гомогенных дверей
	{ 64	,1	,1	, &B2VP82LDU},	//( - , SDu) Давление ПОДЪЁМ РБ2 в норме
	{ 65	,3	,1	, &B2IP01IZ2},	//(ao16_pti:320 - K08AO, - ) Текущее давление СБРОС РБ2
	{ 66	,3	,1	, &B2IP01IZ1},	//(ao16_pti:320 - K04AO, - ) Текущее давление СБРОС РБ2
	{ 67	,5	,1	, &B2IC01UDU},	//( - , SDu) Координата штока РБ2
	{ 68	,1	,1	, &B2IS12LDU},	//(do32_pti:130 - K10DO, - ) Магнит РБ2 зацеплен
	{ 69	,1	,1	, &B2IS11LDU},	//(do32_pti:130 - K11DO, - ) Приход на ВУ РБ2
	{ 70	,8	,1	, &R0IN02FI3},	//( - , SA3) Выход КНК15-1 Гц от ПТИ
	{ 71	,8	,1	, &R0IN03FI2},	//( - , SA2) Выход КНК53М Гц от ПТИ
	{ 72	,8	,1	, &R0IN07RIP},	//( - , SRP) Выход СНМ-11-2 Гц от ПТИ
	{ 73	,8	,1	, &R0IN06RIP},	//( - , SRP) Выход СНМ-11-1 Гц от ПТИ
	{ 74	,3	,1	, &TerR0IN06FRP},	//( - , - ) Неисправности СНМ-11 -1,2
	{ 75	,8	,1	, &R0IN03RIP},	//( - , SRP) Выход КНК53М Гц от ПТИ
	{ 76	,8	,1	, &R0IN02RIP},	//( - , SRP) Выход КНК15- Гц от ПТИ
	{ 77	,8	,1	, &R0IN01RIP},	//( - , SRP) Выход СНМ-11 Гц от ПТИ
	{ 78	,8	,1	, &R0IN02FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{ 79	,8	,1	, &R0IN03FI1},	//( - , SA1) Выход КНК53М Гц от ПТИ
	{ 80	,8	,1	, &R0IN02FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
	{ 81	,8	,1	, &R0IN03FI4},	//( - , SA4) Выход КНК53М Гц от ПТИ
	{ 82	,8	,1	, &R0IN02FI4},	//( - , SA4) Выход КНК15-1 Гц от ПТИ
	{ 83	,8	,1	, &R0IN01FI3},	//( - , SA3) Выход СНМ-11 Гц от ПТИ
	{ 84	,8	,1	, &R0IN01FI2},	//( - , SA2) Выход КНК15-1 Гц от ПТИ
	{ 85	,8	,1	, &R0IN01FI4},	//( - , SA4) Выход СНМ-11 Гц от ПТИ
	{ 86	,8	,1	, &R0IN01FI1},	//( - , SA1) Выход КНК15-1 Гц от ПТИ
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
	{ 99	,3	,1	, &R0MW11IP1},	//( - , SCM) Переключатель ВЫСТРЕЛ
	{ 100	,3	,1	, &R0IS01FI0},	//( - , SA1, SA2, SA3, SA4, SRP) Признак работы с имитатором
	{ 101	,3	,1	, &A0IT03IRP},	//(ao16_pti:320 - K11AO, - ) Температура АЗ1-3
	{ 102	,3	,1	, &B0IT03IRP},	//(ao16_pti:320 - K12AO, - ) Температура АЗ2-3
	{ 103	,8	,1	, &R0IN03FI3},	//( - , SA3) Выход КНК53М Гц от ПТИ
	{ 104	,1	,1	, &A1VP81LZZ},	//(do32_pti:100 - K28DO, - ) Давление СБРОС ББ1 в норме
	{ 105	,1	,1	, &B1VP81LZZ},	//(do32_pti:110 - K31DO, - ) Давление СБРОС ББ2 в норме
	{ 106	,1	,1	, &B2IS33LDU},	//( - , - ) Клапан (Подъём РБ2)  открыт (обесточен)
	{ 107	,8	,1	, &A0VN01RIM},	//( - , SCM) Период разгона  AЗ1
	{ 108	,1	,1	, &B2IS32LIM},	//( - , SCM) Клапан cброса РБ2 открыт(обесточен)
	{ 109	,1	,1	, &B2IS11LIM},	//( - , SCM) Магнит РБ2 обесточен
	{ 110	,1	,1	, &A2IS32LIM},	//( - , SCM) Клапан cброса РБ1 открыт(обесточен)
	{ 111	,1	,1	, &A2IS11LIM},	//( - , SCM) Магнит РБ1 обесточен
	{ 112	,1	,1	, &B1IS32LIM},	//( - , SCM) Клапан cброса ББ2 открыт(обесточен)
	{ 113	,1	,1	, &B1IS11LIM},	//( - , SCM) Магнит ББ2 обесточен
	{ 114	,1	,1	, &A1IS32LIM},	//( - , SCM) Клапан cброса ББ1 открыт(обесточен)
	{ 115	,1	,1	, &A1IS11LIM},	//( - , SCM) Магнит ББ1 обесточен
	{ 116	,1	,1	, &A3AD34LDU},	//(vds32_pti:340 - K12VDSR, - ) Клапан (ВПИС ИС1) открыть (обесточить)
	{ 117	,1	,1	, &R0IS02LDU},	//(do32_pti:140 - K17DO, - ) Разрешение ввода от имитатора
	{ 118	,1	,1	, &R0EE04LZ2},	//( - , SBz2) Питание  АКНП4  отключить
	{ 119	,1	,1	, &R0EE03LZ2},	//( - , SBz2) Питание  АКНП3  отключить
	{ 120	,1	,1	, &R0EE02LZ2},	//( - , SBz2) Питание  АКНП  отключить
	{ 121	,1	,1	, &B7AP31LDU},	//(vds32_pti:340 - K31VDSR, - ) Клапан (Обдув АЗ2) открыть (обесточить)
	{ 122	,1	,1	, &A7AP31LDU},	//(vds32_pti:340 - K17VDSR, - ) Клапан (Обдув АЗ1) открыть (обесточить)
	{ 123	,1	,1	, &R4VS12LDU},	//( - , SCM) Движение реактора  к «У ОБРАЗЦОВ»
	{ 124	,1	,1	, &R4VS22LDU},	//( - , SCM) Движение реактора к «У ЗАЩИТЫ»
	{ 125	,1	,1	, &R1VS12LDU},	//( - , SCM) Движение МДЗ1 в сторону ВУ
	{ 126	,1	,1	, &R2VS12LDU},	//( - , SCM) Движение МДЗ2 в сторону ВУ
	{ 127	,1	,1	, &R2VS22LDU},	//( - , SCM) Движение МДЗ2 в сторону НУ
	{ 128	,1	,1	, &R1VS22LDU},	//( - , SCM) Движение МДЗ1 в сторону НУ
	{ 129	,1	,1	, &B5VS12LDU},	//( - , SCM) Движение НЛ2 в сторону ВУ
	{ 130	,1	,1	, &B5VS22LDU},	//( - , SCM) Движение НЛ2 в сторону НУ
	{ 131	,1	,1	, &A5VS12LDU},	//( - , SCM) Движение НЛ1 в сторону ВУ
	{ 132	,1	,1	, &A5VS22LDU},	//( - , SCM) Движение НЛ1 в сторону НУ
	{ 133	,1	,1	, &B6VS12LDU},	//( - , SCM) Движение створок БЗ2  к ОТКРЫТА
	{ 134	,1	,1	, &B6VS22LDU},	//( - , SCM) Движение створок БЗ2  к ЗАКРЫТА
	{ 135	,1	,1	, &A6VS12LDU},	//( - , SCM) Движение створок БЗ1  к  ОТКРЫТА
	{ 136	,1	,1	, &A6VS22LDU},	//( - , SCM) Движение створок БЗ1  к ЗАКРЫТА
	{ 137	,1	,1	, &B8IS21LDU},	//(do32_pti:150 - K05DO, - ) Приход на НУ1 АЗ2
	{ 138	,1	,1	, &B8IS11LDU},	//(do32_pti:150 - K08DO, - ) Приход на ВУ1 АЗ2
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
	{ 225	,1	,1	, &R6IS64LDU},	//(do32_pti:160 - K31DO, - ) Исправность ВИП ССДИ-35 1канал
	{ 226	,1	,1	, &R6IS63LDU},	//(do32_pti:160 - K30DO, - ) Исправность ВИП ССДИ-39 2канал
	{ 227	,1	,1	, &R6IS62LDU},	//(do32_pti:160 - K29DO, - ) Исправность ВИП ССДИ-39 1канал
	{ 228	,1	,1	, &B3IS22LDU},	//(do32_pti:110 - K12DO, - ) Приход на НУП ИС2
	{ 229	,1	,1	, &A3IS22LDU},	//(do32_pti:100 - K06DO, - ) Приход на НУП ИС1
	{ 230	,1	,1	, &B3IS11LDU},	//(do32_pti:110 - K11DO, - ) Приход на ВУ ИС2
	{ 231	,1	,1	, &A3IS11LDU},	//(do32_pti:100 - K05DO, - ) Приход на ВУ ИС1
	{ 232	,3	,1	, &A3IP02IDU},	//(ao16_pti:320 - K09AO, - ) Текущее давление ВЫСТРЕЛ ИС1
	{ 233	,1	,1	, &B3VP81LDU},	//( - , SDu) Давление СПУСК ИС2 в норме
	{ 234	,1	,1	, &A3VP81LDU},	//( - , SDu) Давление СПУСК ИС1 в норме
	{ 235	,1	,1	, &B3IS33LDU},	//( - , - ) Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 236	,5	,1	, &B3IC01UDU},	//( - , SDu) Координата штока ИС2
	{ 237	,1	,1	, &B3IS31LDU},	//( - , - ) Клапан (СПУСК ИС2)  открыт (обесточен)
	{ 238	,3	,1	, &B3IP02IDU},	//(ao16_pti:320 - K10AO, - ) Текущее давление ВЫСТРЕЛ  ИС2
	{ 239	,1	,1	, &A3IS33LDU},	//( - , - ) Клапан (ВЫСТРЕЛ ИС1)  открыт (обесточен)
	{ 240	,5	,1	, &A3IC01UDU},	//( - , SDu) Координата штока ИС1
	{ 241	,1	,1	, &A3IS31LDU},	//( - , - ) Клапан (СПУСК ИС1)  открыт (обесточен)
	{ 242	,1	,1	, &A2VP82LDU},	//( - , SDu) Давление ПОДЪЁМ РБ1 в норме
	{ 243	,1	,1	, &B2AD31LDU},	//(vds32_pti:310 - K30VDSR, - ) Клапан (Сброс РБ2) открыть (обесточить)
	{ 244	,1	,1	, &B1AD32LDU},	//(vds32_pti:310 - K27VDSR, - ) Обесточить ЭМ ББ2
	{ 245	,1	,1	, &B1AD31LDU},	//(vds32_pti:310 - K28VDSR, - ) Клапан (Сброс ББ2) открыть (обесточить)
	{ 246	,1	,1	, &A3AD31LDU},	//(vds32_pti:340 - K16VDSR, - ) Клапан (СПУСК ИС1) открыть (обесточить)
	{ 247	,1	,1	, &C1MD31LP1},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ1
	{ 248	,1	,1	, &C1MD31LP2},	//( - , SCM) Кнопка «СБРОС ББ»  на ОПУ2
	{ 249	,1	,1	, &A1AD31LDU},	//(vds32_pti:310 - K24VDSR, - ) Клапан (Сброс ББ1) открыть (обесточить)
	{ 250	,1	,1	, &A1AD32LDU},	//(vds32_pti:310 - K23VDSR, - ) Обесточить ЭМ ББ1
	{ 251	,1	,1	, &A2AD31LDU},	//(vds32_pti:310 - K26VDSR, - ) Клапан (Сброс РБ1) открыть (обесточить)
	{ 252	,1	,1	, &C2MD31LP1},	//( - , SCM) Кнопка «СБРОС РБ»
	{ 253	,1	,1	, &A2AD32LDU},	//(vds32_pti:310 - K25VDSR, - ) Обесточить ЭМ РБ1
	{ 254	,1	,1	, &R0VZ71LZ2},	//( - , SCM) Обобщенный сигнал по АЗ  2 канала
	{ 255	,1	,1	, &R0VZ71LZ1},	//( - , SCM) Обобщенный сигнал по АЗ  1 канала
	{ 256	,1	,1	, &R8AD21LDU},	//(vds32_pti:310 - K31VDSR, - ) Запуск системы инициирования
	{ 257	,1	,1	, &R0AD14LDU},	//( - , SCM) Имитация срабатывания верхней АС II УР
	{ 258	,8	,1	, &R0SR02RIM},	//( - , SCM) Текущая мощность РУ (ватт)
	{ 259	,8	,1	, &R0CR02RIM},	//( - , SCM) Коэффициент 11 связи АЗ1,2
	{ 260	,1	,1	, &B3AD34LDU},	//(vds32_pti:340 - K26VDSR, - ) Клапан (ВПИС2) открыть (обесточить)
	{ 261	,1	,1	, &A3IS35LDU},	//( - , - ) Клапан (ВПИС1) открыт(обесточен)
	{ 262	,1	,1	, &R7II73LZ2},	//(do32_pti:110 - K26DO, - ) Сработала АС IIУР
	{ 263	,1	,1	, &R7II71LZ2},	//(do32_pti:110 - K24DO, - ) Сработала АС IУР (датчик 1)
	{ 264	,1	,1	, &R7II72LZ2},	//(do32_pti:110 - K25DO, - ) Сработала АС IУР (датчик 2)
	{ 265	,1	,1	, &R0AD16LDU},	//(vds32_pti:310 - K32VDSR, - ) Контроль  I-II УР. РАД
	{ 266	,1	,1	, &R7II72LZ1},	//(do32_pti:100 - K25DO, - ) Сработала АС IУР (датчик 2)
	{ 267	,1	,1	, &R7II71LZ1},	//(do32_pti:100 - K24DO, - ) Сработала АС IУР (датчик 1)
	{ 268	,1	,1	, &R7II73LZ1},	//(do32_pti:100 - K26DO, - ) Сработала АС IIУР
	{ 269	,8	,1	, &R0SR01RIM},	//( - , SCM) Текущая реактивность PУ
	{ 270	,8	,1	, &R0ST01RIM},	//( - , SCM) Текущий период разгона РУ
	{ 271	,1	,1	, &A4AD10LDU},	//(vds32_pti:340 - K15VDSR, - ) Открыть клапан (Подъем НИ1)
	{ 272	,1	,1	, &B4AD10LDU},	//(vds32_pti:340 - K29VDSR, - ) Открыть клапан (Подъем НИ2)
	{ 273	,1	,1	, &A9AD10LDU},	//(vds32_pti:360 - K24VDSR, - ) Открыть клапан (Подъем НИ ДС1)
	{ 274	,1	,1	, &B9AD10LDU},	//(vds32_pti:360 - K25VDSR, - ) Открыть клапан (Подъем НИ ДС2)
	{ 275	,1	,1	, &R0MW13LP2},	//( - , SCM) Переключатель «СЕТЬ»
	{ 276	,1	,1	, &B3AD31LDU},	//(vds32_pti:340 - K30VDSR, - ) Клапан (СПУСК ИС2) открыть (обесточить)
	{ 277	,1	,1	, &B2AD32LDU},	//(vds32_pti:310 - K29VDSR, - ) Обесточить ЭМ РБ2
	{ 278	,8	,1	, &fEM_R0UL01RIM},	//(R0UL01RIM) Среднее время генерации нейтронов
	{ 279	,8	,1	, &fEM_R0UN02RIM},	//(R0UN02RIM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{ 280	,8	,1	, &fEM_A1UR01RIM},	//(A1UR01RIM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{ 281	,8	,1	, &fEM_A1UR00RIM},	//(A1UR00RIM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{ 282	,8	,1	, &fEM_A3UR00RIM},	//(A3UR00RIM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{ 283	,8	,1	, &fEM_A3UR01RIM},	//(A3UR01RIM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{ 284	,8	,1	, &fEM_R0UT01RIM},	//(R0UT01RIM) Температурный коэффициент (долл)
	{ 285	,8	,1	, &fEM_R0UT02RIM},	//(R0UT02RIM) Масса топлива в АЗ
	{ 286	,8	,1	, &fEM_R0UT04RIM},	//(R0UT04RIM) Удельная теплоёмкость топлива
	{ 287	,8	,1	, &fEM_R0UT03RIM},	//(R0UT03RIM) Нормальная температура АЗ град
	{ 288	,8	,1	, &fEM_R0UT05RIM},	//(R0UT05RIM) Энергия деления ядра
	{ 289	,8	,1	, &fEM_R0UT06RIM},	//(R0UT06RIM) Конвекционное сопротивление при обдуве
	{ 290	,8	,1	, &fEM_A1UC02RDU},	//(A1UC02RDU) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{ 291	,8	,1	, &fEM_A1UC04RIM},	//(A1UC04RIM) Координата промежуточного путевого выключателя ББ мм
	{ 292	,8	,1	, &fEM_A1UC05RIM},	//(A1UC05RIM) Координата переднего аварийного выключателя ББ мм
	{ 293	,8	,1	, &fEM_A1UC06RIM},	//(A1UC06RIM) Координата заднего аварийного выключателя ББ мм
	{ 294	,8	,1	, &fEM_A2UC06RIM},	//(A2UC06RIM) Координата заднего аварийного выключателя РБ мм
	{ 295	,8	,1	, &fEM_A2UC05RIM},	//(A2UC05RIM) Координата переднего аварийного выключателя РБ мм
	{ 296	,8	,1	, &fEM_A2UC04RIM},	//(A2UC04RIM) Координата промежуточного путевого выключателя РБ мм
	{ 297	,8	,1	, &fEM_A2UC02RDU},	//(A2UC02RDU) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{ 298	,8	,1	, &fEM_A3UC06RIM},	//(A3UC06RIM) Координата заднего аварийного выключателя ИС мм
	{ 299	,8	,1	, &fEM_A3UC05RIM},	//(A3UC05RIM) Координата переднего аварийного выключателя ИС мм
	{ 300	,8	,1	, &fEM_A3UC04RIM},	//(A3UC04RIM) Координата промежуточного путевого выключателя ИС мм
	{ 301	,8	,1	, &fEM_A3UC02RDU},	//(A3UC02RDU) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{ 302	,8	,1	, &fEM_R4UV80RDU},	//(R4UV80RDU) Номинальная скорость тележки (мм/с)
	{ 303	,8	,1	, &fEM_R4UC10RIM},	//(R4UC10RIM) Координата верхних механических упоров тележки мм
	{ 304	,8	,1	, &fEM_R4UC20RIM},	//(R4UC20RIM) Координата нижних механических упоров тележки мм
	{ 305	,8	,1	, &fEM_B8UC21RIM},	//(B8UC21RIM) Координата верхнего путевого выключателя АЗ2 мм
	{ 306	,8	,1	, &fEM_B8UC20RIM},	//(B8UC20RIM) Координата верхних механических упоров АЗ2 мм
	{ 307	,8	,1	, &fEM_B8UC11RIM},	//(B8UC11RIM) Координата нижнего путевого выключателя АЗ2 мм
	{ 308	,8	,1	, &fEM_B8UC10RIM},	//(B8UC10RIM) Координата нижних механических упоров АЗ2 мм
	{ 309	,8	,1	, &fEM_B8UV80RDU},	//(B8UV80RDU) Номинальная скорость АЗ2 (мм/с)
	{ 310	,8	,1	, &fEM_A8UV80RDU},	//(A8UV80RDU) Номинальная скорость ДС2 (мм/с)
	{ 311	,8	,1	, &fEM_A8UC10RIM},	//(A8UC10RIM) Координата нижних механических упоров ДС2 мм
	{ 312	,8	,1	, &fEM_A8UC11RIM},	//(A8UC11RIM) Координата нижнего путевого выключателя ДС2 мм
	{ 313	,8	,1	, &fEM_A8UC20RIM},	//(A8UC20RIM) Координата верхних механических упоров ДС2 мм
	{ 314	,8	,1	, &fEM_A8UC21RIM},	//(A8UC21RIM) Координата верхнего путевого выключателя ДС2 мм
	{ 315	,8	,1	, &fEM_A6UC10RIM},	//(A6UC10RIM) Время полного хода БЗ (сек)
	{ 316	,8	,1	, &fEM_R1UC10RIM},	//(R1UC10RIM) Время полного хода МДЗ сек
	{ 317	,8	,1	, &fEM_A5UC10RIM},	//(A5UC10RIM) Время полного хода НЛ сек
	{ 318	,8	,1	, &fEM_A0UN01RIM},	//(A0UN01RIM) Мощность источника нейтронов ИНИ
	{ 319	,8	,1	, &fEM_R4UC22RIM},	//(R4UC22RIM) Смещение координаты АЗ от координаты тележки
	{ 320	,8	,1	, &fEM_A1UG01RDU},	//(A1UG01RDU) Расстояние включения масляного демпфера ББ(мм)
	{ 321	,8	,1	, &fEM_A2UG01RDU},	//(A2UG01RDU) Расстояние включения масляного демпфера РБ
	{ 322	,8	,1	, &fEM_A3UG01RDU},	//(A3UG01RDU) Расстояние включения масляного демпфера ИС
	{ 323	,8	,1	, &fEM_R7UC10RIM},	//(R7UC10RIM) X-координата КНК53М R7IN13 см
	{ 324	,8	,1	, &fEM_R7UC19RIM},	//(R7UC19RIM) Y-координата СНМ-11 (11) см
	{ 325	,8	,1	, &fEM_R7UI02RIM},	//(R7UI02RIM) Коэффициент усиления уровня радиации
	{ 326	,8	,1	, &fEM_R7UL01RIM},	//(R7UL01RIM) Постоянная времени изменения уровня радиации в зале
	{ 327	,8	,1	, &fEM_A2UR00RIM},	//(A2UR00RIM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{ 328	,8	,1	, &fEM_A2UR01RIM},	//(A2UR01RIM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{ 329	,8	,1	, &fEM_A0UN02RIM},	//(A0UN02RIM) Мощность источника нейтронов с АНИ
	{ 330	,8	,1	, &fEM_R0UR30RIM},	//(R0UR30RIM) Реактивность вносимая образцами (долл)
	{ 331	,8	,1	, &fEM_R0UR01RIM},	//(R0UR01RIM) Стартовая отрицательная реактивность
	{ 332	,8	,1	, &fEM_R0UT02RDU},	//(R0UT02RDU) Верхний предел шкалы датчика температуры
	{ 333	,8	,1	, &fEM_R0UT01RDU},	//(R0UT01RDU) Нижний предел шкалы датчика температуры
	{ 334	,8	,1	, &fEM_A1UC03RDU},	//(A1UC03RDU) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{ 335	,8	,1	, &fEM_A2UP03RDU},	//(A2UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{ 336	,8	,1	, &fEM_A2UP04RDU},	//(A2UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{ 337	,8	,1	, &fEM_A2UC03RDU},	//(A2UC03RDU) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{ 338	,8	,1	, &fEM_A3UP03RDU},	//(A3UP03RDU) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{ 339	,8	,1	, &fEM_A3UP04RDU},	//(A3UP04RDU) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{ 340	,8	,1	, &fEM_A3UC03RDU},	//(A3UC03RDU) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{ 341	,8	,1	, &fEM_R7UI74RIM},	//(R7UI74RIM) Верхняя граница измерения уровня радиации в зале
	{ 342	,8	,1	, &fEM_A8UC03RDU},	//(A8UC03RDU) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{ 343	,8	,1	, &fEM_R0UV87RDU},	//(R0UV87RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 344	,8	,1	, &fEM_R0UV81RDU},	//(R0UV81RDU) 1-я частота двигателя (шагов/секунду)
	{ 345	,8	,1	, &fEM_R0UV82RDU},	//(R0UV82RDU) 3-я частота двигателя (шагов/секунду)
	{ 346	,8	,1	, &fEM_R0UV83RDU},	//(R0UV83RDU) 4-я частота двигателя (шагов/секунду)
	{ 347	,8	,1	, &fEM_R0UV84RDU},	//(R0UV84RDU) 5-я частота двигателя (шагов/секунду)
	{ 348	,8	,1	, &fEM_R0UV85RDU},	//(R0UV85RDU) 6-я скорость перемещения ББ (шагов/секунду)
	{ 349	,8	,1	, &fEM_R0UV86RDU},	//(R0UV86RDU) 7-я скорость перемещения ББ (шагов/секунду)
	{ 350	,8	,1	, &fEM_A8UC08RDU},	//(A8UC08RDU) Зона срабатывания КВ ДС2(мм)
	{ 351	,8	,1	, &fEM_B8UC08RDU},	//(B8UC08RDU) Зона срабатывания КВ АЗ2(мм)
	{ 352	,8	,1	, &fEM_R4UC08RDU},	//(R4UC08RDU) Зона срабатывания КВ тележки РУ(мм)
	{ 353	,8	,1	, &fEM_R0UH01RSS},	//(R0UH01RSS) Коэфф. преобразования частота->нейтр/с  СНМ11
	{ 354	,8	,1	, &fEM_A0UX00RSS},	//(A0UX00RSS) Эффективный радиус АЗ
	{ 355	,8	,1	, &fEM_R7UX01RSS},	//(R7UX01RSS) X-координата камеры R7IN11
	{ 356	,8	,1	, &fEM_R7UX02RSS},	//(R7UX02RSS) X-координата камеры R7IN12 (см)
	{ 357	,8	,1	, &fEM_R7UX04RSS},	//(R7UX04RSS) X-координата камеры R7IN21 (см)
	{ 358	,8	,1	, &fEM_R7UX05RSS},	//(R7UX05RSS) X-координата камеры R7IN22 (см)
	{ 359	,8	,1	, &fEM_R7UX06RSS},	//(R7UX06RSS) X-координата камеры R7IN23 (см)
	{ 360	,8	,1	, &fEM_R7UX07RSS},	//(R7UX07RSS) X-координата камеры R7IN31 (см)
	{ 361	,8	,1	, &fEM_R7UX08RSS},	//(R7UX08RSS) X-координата камеры R7IN32 (см)
	{ 362	,8	,1	, &fEM_R7UX09RSS},	//(R7UX09RSS) X-координата камеры R7IN33 (см)
	{ 363	,8	,1	, &fEM_R7UY01RSS},	//(R7UY01RSS) Y-координата камеры R7IN11
	{ 364	,8	,1	, &fEM_R7UY02RSS},	//(R7UY02RSS) Y-координата камеры R7IN12 (см)
	{ 365	,8	,1	, &fEM_R7UY04RSS},	//(R7UY04RSS) Y-координата камеры R7IN21 (см)
	{ 366	,8	,1	, &fEM_R7UY05RSS},	//(R7UY05RSS) Y-координата камеры R7IN22 (см)
	{ 367	,8	,1	, &fEM_R7UY06RSS},	//(R7UY06RSS) Y-координата камеры R7IN23 (см)
	{ 368	,8	,1	, &fEM_R7UY07RSS},	//(R7UY07RSS) Y-координата камеры R7IN31 (см)
	{ 369	,8	,1	, &fEM_R7UY08RSS},	//(R7UY08RSS) Y-координата камеры R7IN32 (см)
	{ 370	,8	,1	, &fEM_R7UY09RSS},	//(R7UY09RSS) Y-координата камеры R7IN33 (см)
	{ 371	,8	,1	, &fEM_R7UX10RSS},	//(R7UX10RSS) X-координата камеры R7IN41
	{ 372	,8	,1	, &fEM_R7UX11RSS},	//(R7UX11RSS) X-координата камеры R7IN42
	{ 373	,8	,1	, &fEM_R7UX12RSS},	//(R7UX12RSS) X-координата камеры R7IN43
	{ 374	,8	,1	, &fEM_R7UY10RSS},	//(R7UY10RSS) Y-координата камеры R7IN41
	{ 375	,8	,1	, &fEM_R7UY11RSS},	//(R7UY11RSS) Y-координата камеры R7IN42
	{ 376	,8	,1	, &fEM_R7UY12RSS},	//(R7UY12RSS) Y-координата камеры R7IN43
	{ 377	,8	,1	, &fEM_A0UX01RSS},	//(A0UX01RSS) Первый коэффициент калибровки камеры 1
	{ 378	,8	,1	, &fEM_A0UX02RSS},	//(A0UX02RSS) Первый коэффициент калибровки камеры 2
	{ 379	,8	,1	, &fEM_A0UX03RSS},	//(A0UX03RSS) Первый коэффициент калибровки камеры 3
	{ 380	,8	,1	, &fEM_A0UX04RSS},	//(A0UX04RSS) Первый коэффициент калибровки камеры4
	{ 381	,8	,1	, &fEM_A0UX05RSS},	//(A0UX05RSS) Первый коэффициент калибровки камеры 5
	{ 382	,8	,1	, &fEM_A0UX06RSS},	//(A0UX06RSS) Первый коэффициент калибровки камеры 6
	{ 383	,8	,1	, &fEM_A0UX07RSS},	//(A0UX07RSS) Первый коэффициент калибровки камеры 7
	{ 384	,8	,1	, &fEM_A0UX08RSS},	//(A0UX08RSS) Первый коэффициент калибровки камеры 8
	{ 385	,8	,1	, &fEM_A0UX09RSS},	//(A0UX09RSS) Первый коэффициент калибровки камеры 9
	{ 386	,8	,1	, &fEM_A0UX10RSS},	//(A0UX10RSS) Первый коэффициент калибровки камеры 10
	{ 387	,8	,1	, &fEM_A0UX11RSS},	//(A0UX11RSS) Первый коэффициент калибровки камеры 11
	{ 388	,8	,1	, &fEM_A0UX12RSS},	//(A0UX12RSS) Первый коэффициент калибровки камеры 12
	{ 389	,8	,1	, &fEM_B0UX01RSS},	//(B0UX01RSS) Второй коэффициент калибровки камеры 1
	{ 390	,8	,1	, &fEM_B0UX02RSS},	//(B0UX02RSS) Второй коэффициент калибровки камеры 2
	{ 391	,8	,1	, &fEM_B0UX03RSS},	//(B0UX03RSS) Второй коэффициент калибровки камеры 3
	{ 392	,8	,1	, &fEM_B0UX04RSS},	//(B0UX04RSS) Второй коэффициент калибровки камеры 4
	{ 393	,8	,1	, &fEM_B0UX05RSS},	//(B0UX05RSS) Второй коэффициент калибровки камеры 5
	{ 394	,8	,1	, &fEM_B0UX06RSS},	//(B0UX06RSS) Второй коэффициент калибровки камеры 6
	{ 395	,8	,1	, &fEM_B0UX07RSS},	//(B0UX07RSS) Второй коэффициент калибровки камеры 7
	{ 396	,8	,1	, &fEM_B0UX08RSS},	//(B0UX08RSS) Второй коэффициент калибровки камеры 8
	{ 397	,8	,1	, &fEM_B0UX09RSS},	//(B0UX09RSS) Второй коэффициент калибровки камеры 9
	{ 398	,8	,1	, &fEM_B0UX10RSS},	//(B0UX10RSS) Второй коэффициент калибровки камеры 10
	{ 399	,8	,1	, &fEM_B0UX11RSS},	//(B0UX11RSS) Второй коэффициент калибровки камеры 11
	{ 400	,8	,1	, &fEM_B0UX12RSS},	//(B0UX12RSS) Второй коэффициент калибровки камеры 12
	{ 401	,8	,1	, &fEM_R0UH02RSS},	//(R0UH02RSS) Коэфф. преобразования частота->нейтр/с  КНК15-1
	{ 402	,8	,1	, &fEM_R0UH03RSS},	//(R0UH03RSS) Коэфф. преобразования частота->нейтр/с  КНК53М
	{ 403	,8	,1	, &fEM_R4US80RDU},	//(R4US80RDU) Тормозной путь тележки (мм)
	{ 404	,8	,1	, &fEM_R7UI71RIM},	//(R7UI71RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{ 405	,8	,1	, &fEM_R7UI72RIM},	//(R7UI72RIM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{ 406	,8	,1	, &fEM_R7UI73RIM},	//(R7UI73RIM) Уровень мощности срабатывания АС II УР  ватт
	{ 407	,8	,1	, &fEM_A1UP01RIM},	//(A1UP01RIM) Текущее давление на сброс ББ (МПа)
	{ 408	,8	,1	, &fEM_A2UP01RIM},	//(A2UP01RIM) Текущее давление на сброс РБ
	{ 409	,8	,1	, &fEM_A0UP02RIM},	//(A0UP02RIM) Текущее давление в АЗ1,2
	{ 410	,8	,1	, &fEM_A3UP01RIM},	//(A3UP01RIM) Текущее давление на СПУСК ИС
	{ 411	,8	,1	, &fEM_A1UP82RIM},	//(A1UP82RIM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{ 412	,8	,1	, &fEM_A3UP02RDU},	//(A3UP02RDU) Текущее давление ВЫСТРЕЛ ИС
	{ 413	,8	,1	, &fEM_A1UV02RIM},	//(A1UV02RIM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{ 414	,8	,1	, &fEM_A3UV02RIM},	//(A3UV02RIM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{ 415	,8	,1	, &fEM_A2UV02RIM},	//(A2UV02RIM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{ 416	,8	,1	, &fEM_B8US80RDU},	//(B8US80RDU) Тормозной путь АЗ2 (мм)
	{ 417	,8	,1	, &fEM_A8US80RDU},	//(A8US80RDU) Тормозной путь ДС2 (мм)
	{ 418	,8	,1	, &fEM_A6US80RDU},	//(A6US80RDU) Тормозной путь БЗ (мм)
	{ 419	,8	,1	, &fEM_A1US07RDU},	//(A1US07RDU) Постоянная времени масляного демпфера ББ
	{ 420	,8	,1	, &fEM_A2US07RDU},	//(A2US07RDU) Постоянная времени масляного демпфера РБ
	{ 421	,8	,1	, &fEM_A3US07RDU},	//(A3US07RDU) Постоянная времени масляного демпфера ИС
	{ 422	,8	,1	, &fEM_R7UI75RIM},	//(R7UI75RIM) Множитель к уровню радиации
	{ 423	,8	,1	, &fEM_R0UH21RSS},	//(R0UH21RSS) Верхняя граница измерения частоты импульсов(имп/с) СНМ-11
	{ 424	,8	,1	, &fEM_R0UH22RSS},	//(R0UH22RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-15-1
	{ 425	,8	,1	, &fEM_R0UH23RSS},	//(R0UH23RSS) Верхняя граница измерения частоты импульсов(имп/с) КНК-53М
	{ 426	,8	,1	, &fEM_R0UH05RSS},	//(R0UH05RSS) Кол-во делений/сек на 1 ватт * E^6
	{ 427	,8	,1	, &fEM_A4UL10RIM},	//(A4UL10RIM) Время полного перемещения НИ сек
	{ 428	,8	,1	, &fEM_A9UL10RIM},	//(A9UL10RIM) Время полного перемещения НИ ДС1/ДС2 сек
	{ 429	,8	,1	, &fEM_R3UL10RIM},	//(R3UL10RIM) Время полного хода гомогенных дверей (сек)
	{ 430	,8	,1	, &fEM_R5UL10RIM},	//(R5UL10RIM) Время полного хода ворот отстойной зоны (дес. мс)
	{ 431	,8	,1	, &fEM_R6UL10RIM},	//(R6UL10RIM) Время полного хода кран-балки сек
	{ 432	,1	,1	, &lEM_C1AD31LRP},	//(C1AD31LRP) Общий сброс от РПУ
	{ 433	,1	,1	, &lEM_R0IE01LRP},	//(R0IE01LRP) Отключение питание детекторов
	{ 434	,1	,1	, &lEM_R0IE02LRP},	//(R0IE02LRP) Отключить питание ПР, ПУ
	{ 435	,8	,1	, &fEM_A2UP02RIM},	//(A2UP02RIM) Текущее давление на подъём РБ
	{ 436	,8	,1	, &fEM_A2UP03RIM},	//(A2UP03RIM) Нижняя граница давления на ПОДЪЁМ РБ
	{ 437	,8	,1	, &fEM_A0UP01RIM},	//(A0UP01RIM) Текущее давление в АЗ1,2
	{ 438	,8	,1	, &fEM_A3UP02RIM},	//(A3UP02RIM) Нижняя граница  давления на СПУСК ИС
	{ 439	,8	,1	, &fEM_A4UP01RIM},	//(A4UP01RIM) Текущее давление на подъём НИ
	{ 440	,8	,1	, &fEM_A4UP02RIM},	//(A4UP02RIM) Нижняя граница давления на подъём НИ
	{ 441	,8	,1	, &fEM_R7UI76RIM},	//(R7UI76RIM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{ 442	,8	,1	, &fEM_R7UI77RIM},	//(R7UI77RIM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{ 443	,3	,1	, &iEM_TERBB1},	//(TERBB1) Неисправности  ББ1
	{ 444	,8	,1	, &fEM_A1MC02RC1},	//(A1MC02RC1) Заданная координата штока ББ1 от ИС
	{ 445	,8	,1	, &fEM_A1MV02RC1},	//(A1MV02RC1) Заданная скорость движения  штока ББ1 от ИС
	{ 446	,3	,1	, &iEM_TERBB2},	//(TERBB2) Неисправности  ББ2
	{ 447	,8	,1	, &fEM_B1MC02RC1},	//(B1MC02RC1) Заданная координата штока ББ2 от ИС
	{ 448	,8	,1	, &fEM_B1MV02RC1},	//(B1MV02RC1) Заданная скорость движения штока ББ2 от ИС
	{ 449	,3	,1	, &iEM_TERRB2},	//(TERRB2) Неисправности  РБ2
	{ 450	,8	,1	, &fEM_B2MC02RC1},	//(B2MC02RC1) Заданная координата штока РБ2 от ИС
	{ 451	,8	,1	, &fEM_B2MV02RC1},	//(B2MV02RC1) Заданная скорость движения штока РБ2 от ИС
	{ 452	,3	,1	, &iEM_TERRB1},	//(TERRB1) Неисправности  РБ1
	{ 453	,8	,1	, &fEM_A2MC02RC1},	//(A2MC02RC1) Заданная координата штока РБ1 от ИС
	{ 454	,8	,1	, &fEM_A2MV02RC1},	//(A2MV02RC1) Заданная скорость движения штока РБ1 от ИС
	{ 455	,3	,1	, &iEM_TERIS2},	//(TERIS2) Неисправности  ИС2
	{ 456	,8	,1	, &fEM_B3MC02RC1},	//(B3MC02RC1) Заданная координата штока ИС2 от ИС
	{ 457	,8	,1	, &fEM_B3MV02RC1},	//(B3MV02RC1) Заданная скорость движения штока ИС2 от ИС
	{ 458	,3	,1	, &iEM_TERIS1},	//(TERIS1) Неисправности  ИС1
	{ 459	,8	,1	, &fEM_A3MC02RC1},	//(A3MC02RC1) Заданная координата штока ИС1 от ИС
	{ 460	,8	,1	, &fEM_A3MV02RC1},	//(A3MV02RC1) Заданная скорость движения штока ИС1 от ИС
	{ 461	,3	,1	, &iEM_TERA1IE04LDU},	//(TERA1IE04LDU) Искажение Движение ББ1 назад (от БУШД)
	{ 462	,3	,1	, &iEM_TERA1IE03LDU},	//(TERA1IE03LDU) Искажение Движение ББ1 вперёд (от БУШД)
	{ 463	,8	,1	, &fEM_A1MC01RC1},	//(A1MC01RC1) Заданная координата  ББ1 от ИС
	{ 464	,3	,1	, &iEM_TERB1IE03LDU},	//(TERB1IE03LDU) Искажение Движение ББ2 вперёд (от БУШД)
	{ 465	,3	,1	, &iEM_TERB1IE04LDU},	//(TERB1IE04LDU) Искажение Движение ББ2 назад (от БУШД)
	{ 466	,8	,1	, &fEM_B1MC01RC1},	//(B1MC01RC1) Заданная координата ББ2 от ИС
	{ 467	,8	,1	, &fEM_B1MV01RC1},	//(B1MV01RC1) Заданная скорость движения ББ2 от ИС
	{ 468	,8	,1	, &fEM_B2MC01RC1},	//(B2MC01RC1) Заданная координата РБ2 от ИС
	{ 469	,8	,1	, &fEM_B2MV01RC1},	//(B2MV01RC1) Заданная скорость движения  РБ2 от ИС
	{ 470	,8	,1	, &fEM_A3MC01RC1},	//(A3MC01RC1) Заданная координата ИС1 от ИС
	{ 471	,8	,1	, &fEM_A3MV01RC1},	//(A3MV01RC1) Заданная скорость движения ИС1 от ИС
	{ 472	,8	,1	, &fEM_B3MC01RC1},	//(B3MC01RC1) Заданная координата ИС2 от ИС
	{ 473	,8	,1	, &fEM_B3MV01RC1},	//(B3MV01RC1) Заданная скорость движения ИС2 от ИС
	{ 474	,3	,1	, &iEM_TERA2SS21LIM},	//(TERA2SS21LIM) Искажение: Приход на НУ РБ1
	{ 475	,3	,1	, &iEM_TERA2SS12LIM},	//(TERA2SS12LIM) Искажение: Магнит РБ1 зацеплен
	{ 476	,3	,1	, &iEM_TERR6SS21LIM},	//(TERR6SS21LIM) Искажение: Кран-балка в нерабочем положении
	{ 477	,3	,1	, &iEM_TERA2VP82LIM},	//(TERA2VP82LIM) Искажение: Текущее давление на подъём РБ  в норме
	{ 478	,3	,1	, &iEM_TERA2SS11LIM},	//(TERA2SS11LIM) Искажение: Приход на ВУ РБ1
	{ 479	,3	,1	, &iEM_TERB3SS21LIM},	//(TERB3SS21LIM) Искажение: Приход на НУ ИС2
	{ 480	,3	,1	, &iEM_TERA0MT01RIM},	//(TERA0MT01RIM) Искажение: Текущая температура AЗ1
	{ 481	,3	,1	, &iEM_TERB0MT01RIM},	//(TERB0MT01RIM) Искажение: Текущая температура AЗ2
	{ 482	,3	,1	, &iEM_TERA2SP01RIM},	//(TERA2SP01RIM) Искажение: Текущее давление СБРОС РБ1
	{ 483	,3	,1	, &iEM_TERB2SP01RIM},	//(TERB2SP01RIM) Искажение: Текущее давление СБРОС РБ2
	{ 484	,3	,1	, &iEM_TERB3SP02RIM},	//(TERB3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{ 485	,3	,1	, &iEM_TERA3SC01RIM},	//(TERA3SC01RIM) Искажение: Координата штока ИС1
	{ 486	,3	,1	, &iEM_TERA3VP81LIM},	//(TERA3VP81LIM) Искажение: Текущее давление СПУСК ИС  в норме
	{ 487	,3	,1	, &iEM_TERA2SC01RIM},	//(TERA2SC01RIM) Искажение: Координата штока РБ1
	{ 488	,3	,1	, &iEM_TERA2SS33LIM},	//(TERA2SS33LIM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{ 489	,3	,1	, &iEM_TERA3SS21LIM},	//(TERA3SS21LIM) Искажение: Приход на НУ ИС1
	{ 490	,3	,1	, &iEM_TERA3SS33LIM},	//(TERA3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{ 491	,3	,1	, &iEM_TERA3SS31LIM},	//(TERA3SS31LIM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{ 492	,3	,1	, &iEM_TERB3SS31LIM},	//(TERB3SS31LIM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{ 493	,3	,1	, &iEM_TERB3SS33LIM},	//(TERB3SS33LIM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{ 494	,3	,1	, &iEM_TERB3SC01RIM},	//(TERB3SC01RIM) Искажение: Координата штока ИС2
	{ 495	,3	,1	, &iEM_TERA3SS11LIM},	//(TERA3SS11LIM) Искажение: Приход на ВУ ИС1
	{ 496	,3	,1	, &iEM_TERB3SS11LIM},	//(TERB3SS11LIM) Искажение: Приход на ВУ ИС2
	{ 497	,3	,1	, &iEM_TERR6IS64LIM},	//(TERR6IS64LIM) Искажение: Исправность ВИП ССДИ-35
	{ 498	,3	,1	, &iEM_TERB3SS22LIM},	//(TERB3SS22LIM) Искажение: Приход на НУП ИС2
	{ 499	,3	,1	, &iEM_TERA3SS22LIM},	//(TERA3SS22LIM) Искажение: Приход на НУП ИС1
	{ 500	,3	,1	, &iEM_TERA3SP02RIM},	//(TERA3SP02RIM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{ 501	,3	,1	, &iEM_TERR6IS62LIM},	//(TERR6IS62LIM) Искажение Исправность ВИП ССДИ-39
	{ 502	,3	,1	, &iEM_TERR6IS66LIM},	//(TERR6IS66LIM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{ 503	,3	,1	, &iEM_TERR6IS67LIM},	//(TERR6IS67LIM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{ 504	,3	,1	, &iEM_TERA0VP81LIM},	//(TERA0VP81LIM) Искажение: Давление  АЗ1  в норме
	{ 505	,3	,1	, &iEM_TERB0VP81LIM},	//(TERB0VP81LIM) Искажение: Давление  АЗ2 в норме
	{ 506	,3	,1	, &iEM_TERR0VP81LIM},	//(TERR0VP81LIM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{ 507	,3	,1	, &iEM_TERR6IS68LIM},	//(TERR6IS68LIM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{ 508	,3	,1	, &iEM_TERR7SI74RIM},	//(TERR7SI74RIM) Искажение: Радиация в реакторном зале
	{ 509	,3	,1	, &iEM_TERA5SS21LIM},	//(TERA5SS21LIM) Искажение: Приход на НУ НЛ1
	{ 510	,3	,1	, &iEM_TERB5SS11LIM},	//(TERB5SS11LIM) Искажение: Приход на ВУ НЛ2
	{ 511	,3	,1	, &iEM_TERA5SS11LIM},	//(TERA5SS11LIM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{ 512	,3	,1	, &iEM_TERA9SS11LIM},	//(TERA9SS11LIM) Искажение: Приход на ВУ НИ ДС1
	{ 513	,3	,1	, &iEM_TERB2SS11LIM},	//(TERB2SS11LIM) Искажение: Приход на ВУ РБ2
	{ 514	,3	,1	, &iEM_TERB2SS12LIM},	//(TERB2SS12LIM) Искажение: Магнит РБ2 зацеплен
	{ 515	,3	,1	, &iEM_TERB2SS21LIM},	//(TERB2SS21LIM) Искажение: Приход на НУ РБ2
	{ 516	,3	,1	, &iEM_TERR3SS11LIM},	//(TERR3SS11LIM) Искажение: Приход на ВУ гомогенных дверей-1
	{ 517	,3	,1	, &iEM_TERB2SC01RIM},	//(TERB2SC01RIM) Искажение: Координата штока РБ2
	{ 518	,3	,1	, &iEM_TERR3SS21LIM},	//(TERR3SS21LIM) Искажение: Приход на НУ гомогенных дверей-1
	{ 519	,3	,1	, &iEM_TERR5SS11LIM},	//(TERR5SS11LIM) Искажение: Приход на ВУ ворот отстойной зоны
	{ 520	,3	,1	, &iEM_TERA4SS11LIM},	//(TERA4SS11LIM) Искажение: Приход на ВУ НИ1
	{ 521	,3	,1	, &iEM_TERR1SS11LIM},	//(TERR1SS11LIM) Искажение: Приход на ВУ МДЗ1
	{ 522	,3	,1	, &iEM_TERR1SS21LIM},	//(TERR1SS21LIM) Искажение: Приход на НУ МДЗ1
	{ 523	,3	,1	, &iEM_TERR2SS11LIM},	//(TERR2SS11LIM) Искажение: Приход на ВУ МДЗ2
	{ 524	,3	,1	, &iEM_TERR2SS21LIM},	//(TERR2SS21LIM) Искажение: Приход на НУ МДЗ2
	{ 525	,3	,1	, &iEM_TERA4VP82LIM},	//(TERA4VP82LIM) Искажение Давление ПОДЪЁМ НИ в норме
	{ 526	,3	,1	, &iEM_TERB4SS21LIM},	//(TERB4SS21LIM) Искажение: Приход на НУ НИ2
	{ 527	,3	,1	, &iEM_TERR5SS21LIM},	//(TERR5SS21LIM) Искажение: Приход на НУ ворот отстойной зоны
	{ 528	,3	,1	, &iEM_TERB6SS21LIM},	//(TERB6SS21LIM) Искажение: Приход на НУ БЗ2
	{ 529	,3	,1	, &iEM_TERB4SS11LIM},	//(TERB4SS11LIM) Искажение: Приход на ВУ НИ2
	{ 530	,3	,1	, &iEM_TERA4SS21LIM},	//(TERA4SS21LIM) Искажение: Приход на НУ НИ1
	{ 531	,3	,1	, &iEM_TERA6MS11LIM},	//(TERA6MS11LIM) Искажение: Приход на ВУ БЗ1
	{ 532	,3	,1	, &iEM_TERA6SS21LIM},	//(TERA6SS21LIM) Искажение: Приход на НУ БЗ1
	{ 533	,3	,1	, &iEM_TERB6SS11LIM},	//(TERB6SS11LIM) Искажение: Приход на ВУ БЗ2
	{ 534	,3	,1	, &iEM_TERR4SS11LIM},	//(TERR4SS11LIM) Искажение: Приход на ВУ тележки
	{ 535	,3	,1	, &iEM_TERR4MS21LIM},	//(TERR4MS21LIM) Искажение: Приход на НУ тележки
	{ 536	,3	,1	, &iEM_TERR4SS12LIM},	//(TERR4SS12LIM) Искажение: Приход на механический ВУ тележки
	{ 537	,3	,1	, &iEM_TERR4SS22LIM},	//(TERR4SS22LIM) Искажение: Приход на механический НУ тележки
	{ 538	,3	,1	, &iEM_TERR8SS11LIM},	//(TERR8SS11LIM) Искажение: Аварийный НИ установлен
	{ 539	,3	,1	, &iEM_TERB8SC01RIM},	//(TERB8SC01RIM) Искажение: Координата АЗ2
	{ 540	,3	,1	, &iEM_TERA8SC01RIM},	//(TERA8SC01RIM) Искажение: Координата ДС2
	{ 541	,3	,1	, &iEM_TERB8SS12LIM},	//(TERB8SS12LIM) Искажение: Приход на механический ВУ АЗ2
	{ 542	,3	,1	, &iEM_TERA8SS12LIM},	//(TERA8SS12LIM) Искажение: Приход на механический ВУ ДС2
	{ 543	,3	,1	, &iEM_TERB8SS22LIM},	//(TERB8SS22LIM) Искажение: Приход на механический НУ АЗ2
	{ 544	,3	,1	, &iEM_TERA8SS22LIM},	//(TERA8SS22LIM) Искажение: Приход на механический НУ ДС2
	{ 545	,3	,1	, &iEM_TERA9SS21LIM},	//(TERA9SS21LIM) Искажение: Приход на НУ НИ ДС1
	{ 546	,3	,1	, &iEM_TERB9SS21LIM},	//(TERB9SS21LIM) Искажение: Приход на НУ НИ ДС2
	{ 547	,3	,1	, &iEM_TERB9SS11LIM},	//(TERB9SS11LIM) Искажение: Приход на ВУ НИ ДС2
	{ 548	,3	,1	, &iEM_TERB5SS21LIM},	//(TERB5SS21LIM) Искажение: Приход на НУ НЛ2
	{ 549	,3	,1	, &iEM_TERA1SS21LIM},	//(TERA1SS21LIM) Искажение: Приход на НУ ББ1
	{ 550	,3	,1	, &iEM_TERA1SS11LIM},	//(TERA1SS11LIM) Искажение: Приход на ВУ ББ1
	{ 551	,3	,1	, &iEM_TERA1SC01RIM},	//(TERA1SC01RIM) Искажение: Координата штока ББ1
	{ 552	,3	,1	, &iEM_TERA1SS12LIM},	//(TERA1SS12LIM) Искажение: Магнит ББ1 зацеплен
	{ 553	,3	,1	, &iEM_TERB1SS21LIM},	//(TERB1SS21LIM) Искажение: Приход на НУ ББ2
	{ 554	,3	,1	, &iEM_TERB1SS11LIM},	//(TERB1SS11LIM) Искажение:Приход на ВУ ББ2
	{ 555	,3	,1	, &iEM_TERB1MC01RIM},	//(TERB1MC01RIM) Искажение: Координата штока ББ2
	{ 556	,3	,1	, &iEM_TERB1SS12LIM},	//(TERB1SS12LIM) Искажение: Магнит ББ2 зацеплен
	{ 557	,3	,1	, &iEM_TERTLG},	//(TERTLG) Неисправности  тележки от ИС
	{ 558	,8	,1	, &fEM_R4MC01RC1},	//(R4MC01RC1) Заданная координата тележки от ИС
	{ 559	,8	,1	, &fEM_R4MV01RC1},	//(R4MV01RC1) Заданная скорость тележки от ИС
	{ 560	,3	,1	, &iEM_TERMAZ2},	//(TERMAZ2) Неисправности АЗ2 от ИС
	{ 561	,8	,1	, &fEM_B8MC01RC1},	//(B8MC01RC1) Заданная координата АЗ2 от ИС
	{ 562	,8	,1	, &fEM_B8MV01RC1},	//(B8MV01RC1) Заданная скорость АЗ2 от ИС
	{ 563	,3	,1	, &iEM_TERDS2},	//(TERDS2) Неисправности ДС2 от ИС
	{ 564	,8	,1	, &fEM_A8MC01RC1},	//(A8MC01RC1) Заданная координата ДС2 от ИС
	{ 565	,8	,1	, &fEM_A8MV01RC1},	//(A8MV01RC1) Заданная скорость ДС2 от ИС
	{ 566	,3	,1	, &iEM_TERBZ1},	//(TERBZ1) Неисправности БЗ1
	{ 567	,8	,1	, &fEM_A6MC01RC1},	//(A6MC01RC1) Заданная координата БЗ1 от ИС
	{ 568	,8	,1	, &fEM_A6MV01RC1},	//(A6MV01RC1) Заданная скорость БЗ1 от ИС
	{ 569	,3	,1	, &iEM_TERBZ2},	//(TERBZ2) Неисправности БЗ2
	{ 570	,8	,1	, &fEM_B6MC01RC1},	//(B6MC01RC1) Заданная координата БЗ2 от ИС
	{ 571	,8	,1	, &fEM_B6MV01RC1},	//(B6MV01RC1) Заданная скорость БЗ2 от ИС
	{ 572	,1	,1	, &lEM_R3AD10LC1},	//(R3AD10LC1) Гомогенные двери-1 открыть от ИС
	{ 573	,1	,1	, &lEM_R3AD20LC1},	//(R3AD20LC1) Гомогенные двери-1 закрыть от ИС
	{ 574	,1	,1	, &lEM_R6AD10LC1},	//(R6AD10LC1) Выкатить кран-балку от ИС
	{ 575	,1	,1	, &lEM_R5AD10LC1},	//(R5AD10LC1) Открыть ворота отстойной зоны от ИС
	{ 576	,1	,1	, &lEM_R5AD20LC1},	//(R5AD20LC1) Закрыть ворота отстойной зоны от ИС
	{ 577	,3	,1	, &iEM_TERMDZ2},	//(TERMDZ2) Неисправности МДЗ2
	{ 578	,8	,1	, &fEM_R2MC01RC1},	//(R2MC01RC1) Заданная координата МДЗ2 от ИС
	{ 579	,8	,1	, &fEM_R2MV01RC1},	//(R2MV01RC1) Заданная скорость МДЗ2 от ИС
	{ 580	,3	,1	, &iEM_TERMDZ1},	//(TERMDZ1) Неисправности МДЗ1
	{ 581	,8	,1	, &fEM_R1MC01RC1},	//(R1MC01RC1) Заданная координата МДЗ1 от ИС
	{ 582	,8	,1	, &fEM_R1MV01RC1},	//(R1MV01RC1) Заданная скорость МДЗ1 от ИС
	{ 583	,3	,1	, &iEM_TERNL1},	//(TERNL1) Неисправности НЛ1
	{ 584	,8	,1	, &fEM_A5MC01RC1},	//(A5MC01RC1) Заданная координата НЛ1 от ИС
	{ 585	,8	,1	, &fEM_A5MV01RC1},	//(A5MV01RC1) Заданная скорость НЛ1 от ИС
	{ 586	,3	,1	, &iEM_TERNL2},	//(TERNL2) Неисправности НЛ2
	{ 587	,8	,1	, &fEM_B5MC01RC1},	//(B5MC01RC1) Заданная координата НЛ2 от ИС
	{ 588	,8	,1	, &fEM_B5MV01RC1},	//(B5MV01RC1) Заданная скорость НЛ2 от ИС
	{ 589	,1	,1	, &lEM_R8AD10LC1},	//(R8AD10LC1) Установить аварийный НИ от ИС
	{ 590	,8	,1	, &fEM_A1UC08RIM},	//(A1UC08RIM) Зона срабатывания КВ ББ(мм)
	{ 591	,8	,1	, &fEM_A2UC08RIM},	//(A2UC08RIM) Зона срабатывания КВ  РБ мм
	{ 592	,8	,1	, &fEM_A3UC08RIM},	//(A3UC08RIM) Зона срабатывания КВ ИС(мм)
	{ 593	,3	,1	, &iEM_TERB2SS33LIM},	//(TERB2SS33LIM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{ 594	,3	,1	, &iEM_TERA1VP81LIM},	//(TERA1VP81LIM) Искажение: Текущее давление СБРОС ББ1  в норме
	{ 595	,3	,1	, &iEM_TERB1VP81LIM},	//(TERB1VP81LIM) Искажение: Текущее давление СБРОС ББ2  в норме
	{ 596	,8	,1	, &fEM_A0UT03RSP},	//(A0UT03RSP) Стартовая  температура АЗ1 град
	{ 597	,8	,1	, &fEM_A0UR01RSP},	//(A0UR01RSP) Стартовая  реактивность АЗ1
	{ 598	,8	,1	, &fEM_A0UR02RSP},	//(A0UR02RSP) Стартовый  поток нейтронов АЗ1
	{ 599	,8	,1	, &fEM_B0UT03RSP},	//(B0UT03RSP) Стартовая  температура АЗ2 град
	{ 600	,8	,1	, &fEM_A1MC01RSP},	//(A1MC01RSP) Стартовая координата  ББ1
	{ 601	,8	,1	, &fEM_A1MC02RSP},	//(A1MC02RSP) Стартовая координата штока ББ1
	{ 602	,8	,1	, &fEM_A1MV01RSP},	//(A1MV01RSP) Стартовая скорость движения  ББ1
	{ 603	,8	,1	, &fEM_A1MV02RSP},	//(A1MV02RSP) Стартовая скорость движения  ББ1
	{ 604	,8	,1	, &fEM_B1MC01RSP},	//(B1MC01RSP) Стартовая координата  ББ2
	{ 605	,8	,1	, &fEM_B1MV01RSP},	//(B1MV01RSP) Стартовая скорость движения  ББ2
	{ 606	,8	,1	, &fEM_B1MC02RSP},	//(B1MC02RSP) Стартовая координата штока ББ2
	{ 607	,8	,1	, &fEM_B1MV02RSP},	//(B1MV02RSP) Стартовая скорость движения  ББ2
	{ 608	,8	,1	, &fEM_A2MC01RC1},	//(A2MC01RC1) Заданная координата РБ1 от ИС
	{ 609	,8	,1	, &fEM_A2MV01RC1},	//(A2MV01RC1) Заданная скорость движения РБ1 от ИС
	{ 610	,8	,1	, &fEM_A2MC01RSP},	//(A2MC01RSP) Стартовая координата  РБ1
	{ 611	,8	,1	, &fEM_A2MV01RSP},	//(A2MV01RSP) Стартовая скорость движения  РБ1
	{ 612	,8	,1	, &fEM_A2MC02RSP},	//(A2MC02RSP) Стартовая координата штока РБ1
	{ 613	,8	,1	, &fEM_A2MV02RSP},	//(A2MV02RSP) Стартовая скорость движения  РБ1
	{ 614	,8	,1	, &fEM_B2MC01RSP},	//(B2MC01RSP) Стартовая координата  РБ2
	{ 615	,8	,1	, &fEM_B2MV01RSP},	//(B2MV01RSP) Стартовая скорость движения  РБ2
	{ 616	,8	,1	, &fEM_B2MC02RSP},	//(B2MC02RSP) Стартовая координата штока РБ2
	{ 617	,8	,1	, &fEM_B2MV02RSP},	//(B2MV02RSP) Стартовая скорость движения  РБ2
	{ 618	,8	,1	, &fEM_A3MC01RSP},	//(A3MC01RSP) Стартовая координата  ИС1
	{ 619	,8	,1	, &fEM_A3MV01RSP},	//(A3MV01RSP) Стартовая скорость движения  ИС1
	{ 620	,8	,1	, &fEM_A3MC02RSP},	//(A3MC02RSP) Стартовая координата штока ИС1
	{ 621	,8	,1	, &fEM_A3MV02RSP},	//(A3MV02RSP) Стартовая скорость движения  ИС1
	{ 622	,8	,1	, &fEM_B3MC01RSP},	//(B3MC01RSP) Стартовая координата  ИС2
	{ 623	,8	,1	, &fEM_B3MV01RSP},	//(B3MV01RSP) Стартовая скорость движения  ИС2
	{ 624	,8	,1	, &fEM_B3MC02RSP},	//(B3MC02RSP) Стартовая координата штока ИС2
	{ 625	,8	,1	, &fEM_B3MV02RSP},	//(B3MV02RSP) Стартовая скорость движения  ИС2
	{ 626	,8	,1	, &fEM_B8MC01RSP},	//(B8MC01RSP) Стартовая координата АЗ2
	{ 627	,8	,1	, &fEM_B8MV01RSP},	//(B8MV01RSP) Стартовая скорость АЗ2
	{ 628	,8	,1	, &fEM_A8MC01RSP},	//(A8MC01RSP) Стартовая координата ДС2
	{ 629	,8	,1	, &fEM_A8MV01RSP},	//(A8MV01RSP) Стартовая скорость ДС2
	{ 630	,8	,1	, &fEM_A6MC01RSP},	//(A6MC01RSP) Стартовая координата БЗ1
	{ 631	,8	,1	, &fEM_A6MV01RSP},	//(A6MV01RSP) Стартовая скорость БЗ1
	{ 632	,8	,1	, &fEM_B6MC01RSP},	//(B6MC01RSP) Стартовая координата БЗ2
	{ 633	,8	,1	, &fEM_B6MV01RSP},	//(B6MV01RSP) Стартовая скорость БЗ2
	{ 634	,8	,1	, &fEM_R3UC01RSP},	//(R3UC01RSP) Стартовая координата Гомогенных дверей
	{ 635	,8	,1	, &fEM_R3UV01RSP},	//(R3UV01RSP) Стартовая скорость Гомогенных дверей
	{ 636	,8	,1	, &fEM_R5UC01RSP},	//(R5UC01RSP) Стартовая координата Ворот отстойной зоны
	{ 637	,8	,1	, &fEM_R5UV01RSP},	//(R5UV01RSP) Стартовая скорость Ворот отстойной зоны
	{ 638	,8	,1	, &fEM_R6UC01RSP},	//(R6UC01RSP) Стартовая координата Кран-балки
	{ 639	,8	,1	, &fEM_R6UV01RSP},	//(R6UV01RSP) Стартовая скорость Кран-балки
	{ 640	,8	,1	, &fEM_R2MC01RSP},	//(R2MC01RSP) Стартовая координата МДЗ2
	{ 641	,8	,1	, &fEM_R2MV01RSP},	//(R2MV01RSP) Стартовая скорость МДЗ2
	{ 642	,8	,1	, &fEM_R1MC01RSP},	//(R1MC01RSP) Стартовая координата МДЗ1
	{ 643	,8	,1	, &fEM_R1MV01RSP},	//(R1MV01RSP) Стартовая скорость МДЗ1
	{ 644	,8	,1	, &fEM_A5MC01RSP},	//(A5MC01RSP) Стартовая координата НЛ1
	{ 645	,8	,1	, &fEM_A5MV01RSP},	//(A5MV01RSP) Стартовая скорость НЛ1
	{ 646	,8	,1	, &fEM_B5MC01RSP},	//(B5MC01RSP) Стартовая координата НЛ2
	{ 647	,8	,1	, &fEM_B5MV01RSP},	//(B5MV01RSP) Стартовая скорость НЛ2
	{ 648	,8	,1	, &fEM_A9MC01RSP},	//(A9MC01RSP) Стартовая координата НИ ДС1
	{ 649	,8	,1	, &fEM_A9MV01RSP},	//(A9MV01RSP) Стартовая скорость НИ ДС1
	{ 650	,8	,1	, &fEM_B9MC01RSP},	//(B9MC01RSP) Стартовая координата НИ ДС2
	{ 651	,8	,1	, &fEM_B9MV01RSP},	//(B9MV01RSP) Стартовая скорость НИ ДС2
	{ 652	,8	,1	, &fEM_A4MC01RSP},	//(A4MC01RSP) Стартовая координата НИ1
	{ 653	,8	,1	, &fEM_A4MV01RSP},	//(A4MV01RSP) Стартовая скорость НИ1
	{ 654	,8	,1	, &fEM_B4MC01RSP},	//(B4MC01RSP) Стартовая координата НИ2
	{ 655	,8	,1	, &fEM_B4MV01RSP},	//(B4MV01RSP) Стартовая скорость НИ2
	{ 656	,8	,1	, &fEM_R4MC01RSP},	//(R4MC01RSP) Стартовая координата тележки
	{ 657	,8	,1	, &fEM_R4MV01RSP},	//(R4MV01RSP) Стартовая скорость тележки
	{ 658	,8	,1	, &fEM_A1MV01RC1},	//(A1MV01RC1) Заданная скорость движения  ББ1 от ИС
	{ 659	,3	,1	, &iEM_TERB7MS31LIM},	//(TERB7MS31LIM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{ 660	,3	,1	, &iEM_TERA7MS31LIM},	//(TERA7MS31LIM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{ 661	,8	,1	, &fEM_R7UY00RSS},	//(R7UY00RSS) Y-координата АЗ1 см
	{ 662	,3	,1	, &iEM_TERA6VS12LIM},	//(TERA6VS12LIM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{ 663	,3	,1	, &iEM_TERA6VS22LIM},	//(TERA6VS22LIM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{ 664	,3	,1	, &iEM_TERB6VS12LIM},	//(TERB6VS12LIM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{ 665	,3	,1	, &iEM_TERB6VS22LIM},	//(TERB6VS22LIM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{ 666	,3	,1	, &iEM_TERA5VS22LIM},	//(TERA5VS22LIM) Искажение: Движение створок НЛ1 к НУ
	{ 667	,3	,1	, &iEM_TERA5VS12LIM},	//(TERA5VS12LIM) Искажение: Движение створок НЛ1 к ВУ
	{ 668	,3	,1	, &iEM_TERB5VS12LIM},	//(TERB5VS12LIM) Искажение: Движение створок НЛ2 к ВУ
	{ 669	,3	,1	, &iEM_TERB5VS22LIM},	//(TERB5VS22LIM) Искажение: Движение створок НЛ2 к НУ
	{ 670	,3	,1	, &iEM_TERR1VS12LIM},	//(TERR1VS12LIM) Искажение: Движение МДЗ1 в сторону ВУ
	{ 671	,3	,1	, &iEM_TERR1VS22LIM},	//(TERR1VS22LIM) Искажение: Движение МДЗ1 в сторону НУ
	{ 672	,3	,1	, &iEM_TERR2VS12LIM},	//(TERR2VS12LIM) Искажение: Движение МДЗ2 в сторону ВУ
	{ 673	,3	,1	, &iEM_TERR2VS22LIM},	//(TERR2VS22LIM) Искажение: Движение МДЗ2 в сторону НУ
	{ 674	,3	,1	, &iEM_TERR4VS12LDU},	//(TERR4VS12LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 675	,3	,1	, &iEM_TERR4VS22LDU},	//(TERR4VS22LDU) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{ 676	,8	,1	, &fEM_R4UC23RIM},	//(R4UC23RIM) Y-координата АЗ1
	{ 677	,8	,1	, &fEM_A0UX13RSS},	//(A0UX13RSS) Первый коэффициент калибровки камеры 13
	{ 678	,8	,1	, &fEM_A0UX14RSS},	//(A0UX14RSS) Первый коэффициент калибровки камеры 14
	{ 679	,8	,1	, &fEM_A0UX15RSS},	//(A0UX15RSS) Первый коэффициент калибровки камеры 15
	{ 680	,8	,1	, &fEM_R7UX13RSS},	//(R7UX13RSS) X-координата камеры R7IN51
	{ 681	,8	,1	, &fEM_R7UX14RSS},	//(R7UX14RSS) X-координата камеры R7IN52
	{ 682	,8	,1	, &fEM_R7UX15RSS},	//(R7UX15RSS) X-координата камеры R7IN53
	{ 683	,8	,1	, &fEM_R7UY13RSS},	//(R7UY13RSS) Y-координата камеры R7IN51
	{ 684	,8	,1	, &fEM_R7UY14RSS},	//(R7UY14RSS) Y-координата камеры R7IN52
	{ 685	,8	,1	, &fEM_R7UY15RSS},	//(R7UY15RSS) Y-координата камеры R7IN53
	{ 686	,8	,1	, &fEM_R7UX16RSS},	//(R7UX16RSS) Величина сигнала СНМ11 в БЗ
	{ 687	,1	,1	, &bFirstEnterFlag},	//(bFirstEnterFlag) 
	{ 688	,8	,1	, &internal1_m896_Chim0},	//(internal1_m896_Chim0) измеренная частота импульсов камеры Гц
	{ 689	,8	,1	, &internal1_m886_Chim0},	//(internal1_m886_Chim0) измеренная частота импульсов камеры Гц
	{ 690	,8	,1	, &internal1_m878_Chim0},	//(internal1_m878_Chim0) измеренная частота импульсов камеры Гц
	{ 691	,1	,1	, &internal1_m833_Out10},	//(internal1_m833_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 692	,1	,1	, &internal1_m832_Out10},	//(internal1_m832_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 693	,1	,1	, &internal1_m1016_Out10},	//(internal1_m1016_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 694	,1	,1	, &internal1_m1015_Out10},	//(internal1_m1015_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 695	,1	,1	, &internal1_m1014_Out10},	//(internal1_m1014_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 696	,1	,1	, &internal1_m1013_Out10},	//(internal1_m1013_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 697	,1	,1	, &internal1_m693_Out10},	//(internal1_m693_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 698	,1	,1	, &internal1_m692_Out10},	//(internal1_m692_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 699	,1	,1	, &internal1_m671_Out10},	//(internal1_m671_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 700	,1	,1	, &internal1_m670_Out10},	//(internal1_m670_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 701	,1	,1	, &internal1_m691_Out10},	//(internal1_m691_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 702	,1	,1	, &internal1_m690_Out10},	//(internal1_m690_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 703	,1	,1	, &internal1_m669_Out10},	//(internal1_m669_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 704	,1	,1	, &internal1_m668_Out10},	//(internal1_m668_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 705	,1	,1	, &internal1_m529_Out10},	//(internal1_m529_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 706	,1	,1	, &internal1_m545_Out10},	//(internal1_m545_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 707	,1	,1	, &internal1_m411_Out10},	//(internal1_m411_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 708	,1	,1	, &internal1_m488_q0},	//(internal1_m488_q0) q0 - внутренний параметр
	{ 709	,1	,1	, &internal1_m489_q0},	//(internal1_m489_q0) q0 - внутренний параметр
	{ 710	,1	,1	, &internal1_m474_q0},	//(internal1_m474_q0) q0 - внутренний параметр
	{ 711	,1	,1	, &internal1_m475_q0},	//(internal1_m475_q0) q0 - внутренний параметр
	{ 712	,8	,1	, &internal1_m644_tx},	//(internal1_m644_tx) tx - время накопленное сек
	{ 713	,18	,1	, &internal1_m644_y0},	//(internal1_m644_y0) y0
	{ 714	,8	,1	, &internal1_m632_tx},	//(internal1_m632_tx) tx - время накопленное сек
	{ 715	,18	,1	, &internal1_m632_y0},	//(internal1_m632_y0) y0
	{ 716	,8	,1	, &internal1_m618_tx},	//(internal1_m618_tx) tx - время накопленное сек
	{ 717	,18	,1	, &internal1_m618_y0},	//(internal1_m618_y0) y0
	{ 718	,8	,1	, &internal1_m616_tx},	//(internal1_m616_tx) tx - время накопленное сек
	{ 719	,18	,1	, &internal1_m616_y0},	//(internal1_m616_y0) y0
	{ 720	,1	,1	, &internal1_m208_Out10},	//(internal1_m208_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 721	,1	,1	, &internal1_m226_Out10},	//(internal1_m226_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 722	,1	,1	, &internal1_m41_Out10},	//(internal1_m41_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 723	,1	,1	, &internal1_m56_Out10},	//(internal1_m56_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 724	,1	,1	, &internal1_m987_Out10},	//(internal1_m987_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 725	,1	,1	, &internal1_m984_Out10},	//(internal1_m984_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 726	,1	,1	, &internal1_m983_Out10},	//(internal1_m983_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 727	,8	,1	, &internal1_m986_Xtek0},	//(internal1_m986_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 728	,8	,1	, &internal1_m969_Xtek0},	//(internal1_m969_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 729	,1	,1	, &internal1_m970_Out10},	//(internal1_m970_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 730	,1	,1	, &internal1_m967_Out10},	//(internal1_m967_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 731	,1	,1	, &internal1_m966_Out10},	//(internal1_m966_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 732	,1	,1	, &internal1_m1054_Out10},	//(internal1_m1054_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 733	,1	,1	, &internal1_m1035_Out10},	//(internal1_m1035_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 734	,1	,1	, &internal1_m1034_Out10},	//(internal1_m1034_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 735	,1	,1	, &internal1_m1033_Out10},	//(internal1_m1033_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 736	,1	,1	, &internal1_m854_Out10},	//(internal1_m854_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 737	,1	,1	, &internal1_m856_Out10},	//(internal1_m856_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 738	,1	,1	, &internal1_m853_Out10},	//(internal1_m853_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 739	,1	,1	, &internal1_m855_Out10},	//(internal1_m855_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 740	,1	,1	, &internal1_m829_Out10},	//(internal1_m829_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 741	,1	,1	, &internal1_m830_Out10},	//(internal1_m830_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 742	,1	,1	, &internal1_m828_Out10},	//(internal1_m828_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 743	,1	,1	, &internal1_m827_Out10},	//(internal1_m827_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 744	,1	,1	, &internal1_m1049_Out10},	//(internal1_m1049_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 745	,1	,1	, &internal1_m1001_Out10},	//(internal1_m1001_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 746	,1	,1	, &internal1_m1000_Out10},	//(internal1_m1000_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 747	,1	,1	, &internal1_m999_Out10},	//(internal1_m999_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 748	,1	,1	, &internal1_m998_Out10},	//(internal1_m998_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 749	,1	,1	, &internal1_m1050_Out10},	//(internal1_m1050_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 750	,1	,1	, &internal1_m1031_Out10},	//(internal1_m1031_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 751	,1	,1	, &internal1_m831_Out10},	//(internal1_m831_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 752	,1	,1	, &internal1_m1032_Out10},	//(internal1_m1032_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 753	,1	,1	, &internal1_m1030_Out10},	//(internal1_m1030_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 754	,1	,1	, &internal1_m1051_Out10},	//(internal1_m1051_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 755	,1	,1	, &internal1_m1029_Out10},	//(internal1_m1029_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 756	,1	,1	, &internal1_m1012_Out10},	//(internal1_m1012_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 757	,1	,1	, &internal1_m997_Out10},	//(internal1_m997_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 758	,1	,1	, &internal1_m546_Out10},	//(internal1_m546_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 759	,8	,1	, &internal1_m421_Xtek0},	//(internal1_m421_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 760	,1	,1	, &internal1_m412_Out10},	//(internal1_m412_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 761	,1	,1	, &internal1_m414_Out10},	//(internal1_m414_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 762	,1	,1	, &internal1_m413_Out10},	//(internal1_m413_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 763	,1	,1	, &internal1_m869_Out10},	//(internal1_m869_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 764	,1	,1	, &internal1_m870_Out10},	//(internal1_m870_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 765	,1	,1	, &internal1_m868_Out10},	//(internal1_m868_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 766	,1	,1	, &internal1_m1053_Out10},	//(internal1_m1053_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 767	,1	,1	, &internal1_m706_Out10},	//(internal1_m706_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 768	,1	,1	, &internal1_m707_Out10},	//(internal1_m707_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 769	,1	,1	, &internal1_m704_Out10},	//(internal1_m704_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 770	,1	,1	, &internal1_m705_Out10},	//(internal1_m705_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 771	,1	,1	, &internal1_m562_Out10},	//(internal1_m562_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 772	,1	,1	, &internal1_m561_Out10},	//(internal1_m561_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 773	,8	,1	, &internal1_m850_Xtek0},	//(internal1_m850_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 774	,8	,1	, &internal1_m852_Xtek0},	//(internal1_m852_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 775	,1	,1	, &internal1_m703_Out10},	//(internal1_m703_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 776	,1	,1	, &internal1_m687_Out10},	//(internal1_m687_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 777	,1	,1	, &internal1_m667_Out10},	//(internal1_m667_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 778	,1	,1	, &internal1_m686_Out10},	//(internal1_m686_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 779	,1	,1	, &internal1_m666_Out10},	//(internal1_m666_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 780	,1	,1	, &internal1_m339_Out10},	//(internal1_m339_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 781	,1	,1	, &internal1_m338_Out10},	//(internal1_m338_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 782	,1	,1	, &internal1_m323_Out10},	//(internal1_m323_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 783	,1	,1	, &internal1_m322_Out10},	//(internal1_m322_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 784	,1	,1	, &internal1_m563_Out10},	//(internal1_m563_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 785	,1	,1	, &internal1_m352_Out10},	//(internal1_m352_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 786	,8	,1	, &internal1_m336_Xtek0},	//(internal1_m336_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 787	,1	,1	, &internal1_m351_Out10},	//(internal1_m351_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 788	,1	,1	, &internal1_m349_Out10},	//(internal1_m349_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 789	,8	,1	, &internal1_m329_Xtek0},	//(internal1_m329_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 790	,1	,1	, &internal1_m350_Out10},	//(internal1_m350_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 791	,1	,1	, &internal1_m321_Out10},	//(internal1_m321_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 792	,1	,1	, &internal1_m337_Out10},	//(internal1_m337_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 793	,1	,1	, &internal1_m433_Out10},	//(internal1_m433_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 794	,8	,1	, &internal1_m434_Xtek0},	//(internal1_m434_Xtek0) Xtek0 - положение механизма на прошлом шаге, мм
	{ 795	,1	,1	, &internal1_m432_Out10},	//(internal1_m432_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 796	,1	,1	, &internal1_m431_Out10},	//(internal1_m431_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 797	,1	,1	, &internal1_m430_Out10},	//(internal1_m430_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 798	,1	,1	, &internal1_m1052_Out10},	//(internal1_m1052_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 799	,1	,1	, &internal1_m150_Out10},	//(internal1_m150_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 800	,1	,1	, &internal1_m149_Out10},	//(internal1_m149_Out10) Out10 (psbool) - прошлое значение выходного сигнала
	{ 801	,3	,1	, &internal1_m197_tx},	//(internal1_m197_tx) tx - внутренний параметр
	{ 802	,3	,1	, &internal1_m25_tx},	//(internal1_m25_tx) tx - внутренний параметр
	{ 803	,1	,1	, &internal1_m480_Pav0},	//(internal1_m480_Pav0)  - Пер.аварийный выключатель механизма
	{ 804	,1	,1	, &internal1_m480_Zav0},	//(internal1_m480_Zav0)  - Зад.аварийный выключатель механизма
	{ 805	,1	,1	, &internal1_m480_Pv0},	//(internal1_m480_Pv0)  - Пер. выключатель механизма
	{ 806	,1	,1	, &internal1_m480_Zv0},	//(internal1_m480_Zv0)  - Зад. выключатель механизма
	{ 807	,1	,1	, &internal1_m480_RA00},	//(internal1_m480_RA00)  - последнее задание вперед
	{ 808	,1	,1	, &internal1_m480_RA10},	//(internal1_m480_RA10)  - последнее задание назад
	{ 809	,1	,1	, &internal1_m480_MyFirstEnterFlag},	//(internal1_m480_MyFirstEnterFlag) MyFirstEnterFlag
	{ 810	,1	,1	, &internal1_m492_Pav0},	//(internal1_m492_Pav0)  - Пер.аварийный выключатель механизма
	{ 811	,1	,1	, &internal1_m492_Zav0},	//(internal1_m492_Zav0)  - Зад.аварийный выключатель механизма
	{ 812	,1	,1	, &internal1_m492_Pv0},	//(internal1_m492_Pv0)  - Пер. выключатель механизма
	{ 813	,1	,1	, &internal1_m492_Zv0},	//(internal1_m492_Zv0)  - Зад. выключатель механизма
	{ 814	,1	,1	, &internal1_m492_RA00},	//(internal1_m492_RA00)  - последнее задание вперед
	{ 815	,1	,1	, &internal1_m492_RA10},	//(internal1_m492_RA10)  - последнее задание назад
	{ 816	,1	,1	, &internal1_m492_MyFirstEnterFlag},	//(internal1_m492_MyFirstEnterFlag) MyFirstEnterFlag
	{ 817	,1	,1	, &internal1_m479_Pav0},	//(internal1_m479_Pav0)  - Пер.аварийный выключатель механизма
	{ 818	,1	,1	, &internal1_m479_Zav0},	//(internal1_m479_Zav0)  - Зад.аварийный выключатель механизма
	{ 819	,1	,1	, &internal1_m479_Pv0},	//(internal1_m479_Pv0)  - Пер. выключатель механизма
	{ 820	,1	,1	, &internal1_m479_Zv0},	//(internal1_m479_Zv0)  - Зад. выключатель механизма
	{ 821	,1	,1	, &internal1_m479_RA00},	//(internal1_m479_RA00)  - последнее задание вперед
	{ 822	,1	,1	, &internal1_m479_RA10},	//(internal1_m479_RA10)  - последнее задание назад
	{ 823	,1	,1	, &internal1_m479_MyFirstEnterFlag},	//(internal1_m479_MyFirstEnterFlag) MyFirstEnterFlag
	{ 824	,1	,1	, &internal1_m621_Pav0},	//(internal1_m621_Pav0)  - Пер.аварийный выключатель механизма
	{ 825	,1	,1	, &internal1_m621_Zav0},	//(internal1_m621_Zav0)  - Зад.аварийный выключатель механизма
	{ 826	,1	,1	, &internal1_m621_Pv0},	//(internal1_m621_Pv0)  - Пер. выключатель механизма
	{ 827	,1	,1	, &internal1_m621_Zv0},	//(internal1_m621_Zv0)  - Зад. выключатель механизма
	{ 828	,1	,1	, &internal1_m621_RA00},	//(internal1_m621_RA00)  - последнее задание вперед
	{ 829	,1	,1	, &internal1_m621_RA10},	//(internal1_m621_RA10)  - последнее задание назад
	{ 830	,1	,1	, &internal1_m621_MyFirstEnterFlag},	//(internal1_m621_MyFirstEnterFlag) MyFirstEnterFlag
	{ 831	,1	,1	, &internal1_m620_Pav0},	//(internal1_m620_Pav0)  - Пер.аварийный выключатель механизма
	{ 832	,1	,1	, &internal1_m620_Zav0},	//(internal1_m620_Zav0)  - Зад.аварийный выключатель механизма
	{ 833	,1	,1	, &internal1_m620_Pv0},	//(internal1_m620_Pv0)  - Пер. выключатель механизма
	{ 834	,1	,1	, &internal1_m620_Zv0},	//(internal1_m620_Zv0)  - Зад. выключатель механизма
	{ 835	,1	,1	, &internal1_m620_RA00},	//(internal1_m620_RA00)  - последнее задание вперед
	{ 836	,1	,1	, &internal1_m620_RA10},	//(internal1_m620_RA10)  - последнее задание назад
	{ 837	,1	,1	, &internal1_m620_MyFirstEnterFlag},	//(internal1_m620_MyFirstEnterFlag) MyFirstEnterFlag
	{ 838	,1	,1	, &internal1_m606_Pav0},	//(internal1_m606_Pav0)  - Пер.аварийный выключатель механизма
	{ 839	,1	,1	, &internal1_m606_Zav0},	//(internal1_m606_Zav0)  - Зад.аварийный выключатель механизма
	{ 840	,1	,1	, &internal1_m606_Pv0},	//(internal1_m606_Pv0)  - Пер. выключатель механизма
	{ 841	,1	,1	, &internal1_m606_Zv0},	//(internal1_m606_Zv0)  - Зад. выключатель механизма
	{ 842	,1	,1	, &internal1_m606_RA00},	//(internal1_m606_RA00)  - последнее задание вперед
	{ 843	,1	,1	, &internal1_m606_RA10},	//(internal1_m606_RA10)  - последнее задание назад
	{ 844	,1	,1	, &internal1_m606_MyFirstEnterFlag},	//(internal1_m606_MyFirstEnterFlag) MyFirstEnterFlag
	{ 845	,1	,1	, &internal1_m605_Pav0},	//(internal1_m605_Pav0)  - Пер.аварийный выключатель механизма
	{ 846	,1	,1	, &internal1_m605_Zav0},	//(internal1_m605_Zav0)  - Зад.аварийный выключатель механизма
	{ 847	,1	,1	, &internal1_m605_Pv0},	//(internal1_m605_Pv0)  - Пер. выключатель механизма
	{ 848	,1	,1	, &internal1_m605_Zv0},	//(internal1_m605_Zv0)  - Зад. выключатель механизма
	{ 849	,1	,1	, &internal1_m605_RA00},	//(internal1_m605_RA00)  - последнее задание вперед
	{ 850	,1	,1	, &internal1_m605_RA10},	//(internal1_m605_RA10)  - последнее задание назад
	{ 851	,1	,1	, &internal1_m605_MyFirstEnterFlag},	//(internal1_m605_MyFirstEnterFlag) MyFirstEnterFlag
	{ 852	,8	,1	, &internal1_m652_y0},	//(internal1_m652_y0) y0 - внутренний параметр
	{ 853	,8	,1	, &internal1_m815_Chim0},	//(internal1_m815_Chim0) измеренная частота импульсов камеры Гц
	{ 854	,8	,1	, &internal1_m806_Chim0},	//(internal1_m806_Chim0) измеренная частота импульсов камеры Гц
	{ 855	,8	,1	, &internal1_m798_Chim0},	//(internal1_m798_Chim0) измеренная частота импульсов камеры Гц
	{ 856	,8	,1	, &internal1_m789_Chim0},	//(internal1_m789_Chim0) измеренная частота импульсов камеры Гц
	{ 857	,8	,1	, &internal1_m780_Chim0},	//(internal1_m780_Chim0) измеренная частота импульсов камеры Гц
	{ 858	,8	,1	, &internal1_m772_Chim0},	//(internal1_m772_Chim0) измеренная частота импульсов камеры Гц
	{ 859	,8	,1	, &internal1_m763_Chim0},	//(internal1_m763_Chim0) измеренная частота импульсов камеры Гц
	{ 860	,8	,1	, &internal1_m754_Chim0},	//(internal1_m754_Chim0) измеренная частота импульсов камеры Гц
	{ 861	,8	,1	, &internal1_m746_Chim0},	//(internal1_m746_Chim0) измеренная частота импульсов камеры Гц
	{ 862	,8	,1	, &internal1_m737_Chim0},	//(internal1_m737_Chim0) измеренная частота импульсов камеры Гц
	{ 863	,8	,1	, &internal1_m728_Chim0},	//(internal1_m728_Chim0) измеренная частота импульсов камеры Гц
	{ 864	,8	,1	, &internal1_m719_Chim0},	//(internal1_m719_Chim0) измеренная частота импульсов камеры Гц
	{ 865	,1	,1	, &internal1_m592_Pav0},	//(internal1_m592_Pav0)  - Пер.аварийный выключатель механизма
	{ 866	,1	,1	, &internal1_m592_Zav0},	//(internal1_m592_Zav0)  - Зад.аварийный выключатель механизма
	{ 867	,1	,1	, &internal1_m592_Pv0},	//(internal1_m592_Pv0)  - Пер. выключатель механизма
	{ 868	,1	,1	, &internal1_m592_Zv0},	//(internal1_m592_Zv0)  - Зад. выключатель механизма
	{ 869	,1	,1	, &internal1_m592_RA00},	//(internal1_m592_RA00)  - последнее задание вперед
	{ 870	,1	,1	, &internal1_m592_RA10},	//(internal1_m592_RA10)  - последнее задание назад
	{ 871	,1	,1	, &internal1_m592_MyFirstEnterFlag},	//(internal1_m592_MyFirstEnterFlag) MyFirstEnterFlag
	{ 872	,1	,1	, &internal1_m577_Pav0},	//(internal1_m577_Pav0)  - Пер.аварийный выключатель механизма
	{ 873	,1	,1	, &internal1_m577_Zav0},	//(internal1_m577_Zav0)  - Зад.аварийный выключатель механизма
	{ 874	,1	,1	, &internal1_m577_Pv0},	//(internal1_m577_Pv0)  - Пер. выключатель механизма
	{ 875	,1	,1	, &internal1_m577_Zv0},	//(internal1_m577_Zv0)  - Зад. выключатель механизма
	{ 876	,1	,1	, &internal1_m577_RA00},	//(internal1_m577_RA00)  - последнее задание вперед
	{ 877	,1	,1	, &internal1_m577_RA10},	//(internal1_m577_RA10)  - последнее задание назад
	{ 878	,1	,1	, &internal1_m577_MyFirstEnterFlag},	//(internal1_m577_MyFirstEnterFlag) MyFirstEnterFlag
	{ 879	,1	,1	, &internal1_m463_Pav0},	//(internal1_m463_Pav0)  - Пер.аварийный выключатель механизма
	{ 880	,1	,1	, &internal1_m463_Zav0},	//(internal1_m463_Zav0)  - Зад.аварийный выключатель механизма
	{ 881	,1	,1	, &internal1_m463_Pv0},	//(internal1_m463_Pv0)  - Пер. выключатель механизма
	{ 882	,1	,1	, &internal1_m463_Zv0},	//(internal1_m463_Zv0)  - Зад. выключатель механизма
	{ 883	,1	,1	, &internal1_m463_RA00},	//(internal1_m463_RA00)  - последнее задание вперед
	{ 884	,1	,1	, &internal1_m463_RA10},	//(internal1_m463_RA10)  - последнее задание назад
	{ 885	,1	,1	, &internal1_m463_MyFirstEnterFlag},	//(internal1_m463_MyFirstEnterFlag) MyFirstEnterFlag
	{ 886	,1	,1	, &internal1_m448_Pav0},	//(internal1_m448_Pav0)  - Пер.аварийный выключатель механизма
	{ 887	,1	,1	, &internal1_m448_Zav0},	//(internal1_m448_Zav0)  - Зад.аварийный выключатель механизма
	{ 888	,1	,1	, &internal1_m448_Pv0},	//(internal1_m448_Pv0)  - Пер. выключатель механизма
	{ 889	,1	,1	, &internal1_m448_Zv0},	//(internal1_m448_Zv0)  - Зад. выключатель механизма
	{ 890	,1	,1	, &internal1_m448_RA00},	//(internal1_m448_RA00)  - последнее задание вперед
	{ 891	,1	,1	, &internal1_m448_RA10},	//(internal1_m448_RA10)  - последнее задание назад
	{ 892	,1	,1	, &internal1_m448_MyFirstEnterFlag},	//(internal1_m448_MyFirstEnterFlag) MyFirstEnterFlag
	{ 893	,1	,1	, &internal1_m504_Pav0},	//(internal1_m504_Pav0)  - Пер.аварийный выключатель механизма
	{ 894	,1	,1	, &internal1_m504_Zav0},	//(internal1_m504_Zav0)  - Зад.аварийный выключатель механизма
	{ 895	,1	,1	, &internal1_m504_Pv0},	//(internal1_m504_Pv0)  - Пер. выключатель механизма
	{ 896	,1	,1	, &internal1_m504_Zv0},	//(internal1_m504_Zv0)  - Зад. выключатель механизма
	{ 897	,1	,1	, &internal1_m504_RA00},	//(internal1_m504_RA00)  - последнее задание вперед
	{ 898	,1	,1	, &internal1_m504_RA10},	//(internal1_m504_RA10)  - последнее задание назад
	{ 899	,1	,1	, &internal1_m504_MyFirstEnterFlag},	//(internal1_m504_MyFirstEnterFlag) MyFirstEnterFlag
	{ 900	,1	,1	, &internal1_m399_Pav0},	//(internal1_m399_Pav0)  - Пер.аварийный выключатель механизма
	{ 901	,1	,1	, &internal1_m399_Zav0},	//(internal1_m399_Zav0)  - Зад.аварийный выключатель механизма
	{ 902	,1	,1	, &internal1_m399_Pv0},	//(internal1_m399_Pv0)  - Пер. выключатель механизма
	{ 903	,1	,1	, &internal1_m399_Zv0},	//(internal1_m399_Zv0)  - Зад. выключатель механизма
	{ 904	,1	,1	, &internal1_m399_RA00},	//(internal1_m399_RA00)  - последнее задание вперед
	{ 905	,1	,1	, &internal1_m399_RA10},	//(internal1_m399_RA10)  - последнее задание назад
	{ 906	,1	,1	, &internal1_m399_MyFirstEnterFlag},	//(internal1_m399_MyFirstEnterFlag) MyFirstEnterFlag
	{ 907	,1	,1	, &internal1_m383_Pav0},	//(internal1_m383_Pav0)  - Пер.аварийный выключатель механизма
	{ 908	,1	,1	, &internal1_m383_Zav0},	//(internal1_m383_Zav0)  - Зад.аварийный выключатель механизма
	{ 909	,1	,1	, &internal1_m383_Pv0},	//(internal1_m383_Pv0)  - Пер. выключатель механизма
	{ 910	,1	,1	, &internal1_m383_Zv0},	//(internal1_m383_Zv0)  - Зад. выключатель механизма
	{ 911	,1	,1	, &internal1_m383_RA00},	//(internal1_m383_RA00)  - последнее задание вперед
	{ 912	,1	,1	, &internal1_m383_RA10},	//(internal1_m383_RA10)  - последнее задание назад
	{ 913	,1	,1	, &internal1_m383_MyFirstEnterFlag},	//(internal1_m383_MyFirstEnterFlag) MyFirstEnterFlag
	{ 914	,1	,1	, &internal1_m366_Pav0},	//(internal1_m366_Pav0)  - Пер.аварийный выключатель механизма
	{ 915	,1	,1	, &internal1_m366_Zav0},	//(internal1_m366_Zav0)  - Зад.аварийный выключатель механизма
	{ 916	,1	,1	, &internal1_m366_Pv0},	//(internal1_m366_Pv0)  - Пер. выключатель механизма
	{ 917	,1	,1	, &internal1_m366_Zv0},	//(internal1_m366_Zv0)  - Зад. выключатель механизма
	{ 918	,1	,1	, &internal1_m366_RA00},	//(internal1_m366_RA00)  - последнее задание вперед
	{ 919	,1	,1	, &internal1_m366_RA10},	//(internal1_m366_RA10)  - последнее задание назад
	{ 920	,1	,1	, &internal1_m366_MyFirstEnterFlag},	//(internal1_m366_MyFirstEnterFlag) MyFirstEnterFlag
	{ 921	,1	,1	, &internal1_m908_Pav0},	//(internal1_m908_Pav0)  - Пер.аварийный выключатель механизма
	{ 922	,1	,1	, &internal1_m908_Zav0},	//(internal1_m908_Zav0)  - Зад.аварийный выключатель механизма
	{ 923	,1	,1	, &internal1_m908_Pv0},	//(internal1_m908_Pv0)  - Пер. выключатель механизма
	{ 924	,1	,1	, &internal1_m908_Zv0},	//(internal1_m908_Zv0)  - Зад. выключатель механизма
	{ 925	,1	,1	, &internal1_m908_RA00},	//(internal1_m908_RA00)  - последнее задание вперед
	{ 926	,1	,1	, &internal1_m908_RA10},	//(internal1_m908_RA10)  - последнее задание назад
	{ 927	,1	,1	, &internal1_m908_MyFirstEnterFlag},	//(internal1_m908_MyFirstEnterFlag) MyFirstEnterFlag
	{ 928	,8	,1	, &internal1_m182_C1},	//(internal1_m182_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 929	,8	,1	, &internal1_m182_C2},	//(internal1_m182_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 930	,8	,1	, &internal1_m182_C3},	//(internal1_m182_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 931	,8	,1	, &internal1_m182_C4},	//(internal1_m182_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 932	,8	,1	, &internal1_m182_C5},	//(internal1_m182_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 933	,8	,1	, &internal1_m182_C6},	//(internal1_m182_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 934	,8	,1	, &internal1_m182_N20},	//(internal1_m182_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 935	,8	,6	, &internal1_m182_C0},	//(internal1_m182_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 936	,1	,1	, &internal1_m182_ImpINI0},	//(internal1_m182_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 937	,1	,1	, &internal1_m182_MyFirstEnterFlag},	//(internal1_m182_MyFirstEnterFlag) MyFirstEnterFlag
	{ 938	,1	,1	, &internal1_m300_Ppv0},	//(internal1_m300_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 939	,1	,1	, &internal1_m300_Pav0},	//(internal1_m300_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 940	,1	,1	, &internal1_m300_Zav0},	//(internal1_m300_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 941	,1	,1	, &internal1_m300_RA00},	//(internal1_m300_RA00) RA00 - последнее задание вперед
	{ 942	,1	,1	, &internal1_m300_RA10},	//(internal1_m300_RA10) RA10 - последнее задание назад
	{ 943	,18	,1	, &internal1_m300_RA50},	//(internal1_m300_RA50) Ra50 - последнее задание скорости
	{ 944	,1	,1	, &internal1_m300_fls},	//(internal1_m300_fls)  fls - флаг одношагового режима
	{ 945	,1	,1	, &internal1_m300_flp},	//(internal1_m300_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 946	,1	,1	, &internal1_m300_MyFirstEnterFlag},	//(internal1_m300_MyFirstEnterFlag) MyFirstEnterFlag
	{ 947	,1	,1	, &internal1_m130_Ppv0},	//(internal1_m130_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 948	,1	,1	, &internal1_m130_Pav0},	//(internal1_m130_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 949	,1	,1	, &internal1_m130_Zav0},	//(internal1_m130_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 950	,1	,1	, &internal1_m130_RA00},	//(internal1_m130_RA00) RA00 - последнее задание вперед
	{ 951	,1	,1	, &internal1_m130_RA10},	//(internal1_m130_RA10) RA10 - последнее задание назад
	{ 952	,18	,1	, &internal1_m130_RA50},	//(internal1_m130_RA50) Ra50 - последнее задание скорости
	{ 953	,1	,1	, &internal1_m130_fls},	//(internal1_m130_fls)  fls - флаг одношагового режима
	{ 954	,1	,1	, &internal1_m130_flp},	//(internal1_m130_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 955	,1	,1	, &internal1_m130_MyFirstEnterFlag},	//(internal1_m130_MyFirstEnterFlag) MyFirstEnterFlag
	{ 956	,1	,1	, &internal1_m267_Ppv0},	//(internal1_m267_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 957	,1	,1	, &internal1_m267_Pav0},	//(internal1_m267_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 958	,1	,1	, &internal1_m267_Zav0},	//(internal1_m267_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 959	,1	,1	, &internal1_m267_RA00},	//(internal1_m267_RA00) RA00 - последнее задание вперед
	{ 960	,1	,1	, &internal1_m267_RA10},	//(internal1_m267_RA10) RA10 - последнее задание назад
	{ 961	,18	,1	, &internal1_m267_RA50},	//(internal1_m267_RA50) Ra50 - последнее задание скорости
	{ 962	,1	,1	, &internal1_m267_fls},	//(internal1_m267_fls)  fls - флаг одношагового режима
	{ 963	,1	,1	, &internal1_m267_flp},	//(internal1_m267_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 964	,1	,1	, &internal1_m267_MyFirstEnterFlag},	//(internal1_m267_MyFirstEnterFlag) MyFirstEnterFlag
	{ 965	,1	,1	, &internal1_m96_Ppv0},	//(internal1_m96_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 966	,1	,1	, &internal1_m96_Pav0},	//(internal1_m96_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 967	,1	,1	, &internal1_m96_Zav0},	//(internal1_m96_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 968	,1	,1	, &internal1_m96_RA00},	//(internal1_m96_RA00) RA00 - последнее задание вперед
	{ 969	,1	,1	, &internal1_m96_RA10},	//(internal1_m96_RA10) RA10 - последнее задание назад
	{ 970	,18	,1	, &internal1_m96_RA50},	//(internal1_m96_RA50) Ra50 - последнее задание скорости
	{ 971	,1	,1	, &internal1_m96_fls},	//(internal1_m96_fls)  fls - флаг одношагового режима
	{ 972	,1	,1	, &internal1_m96_flp},	//(internal1_m96_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 973	,1	,1	, &internal1_m96_MyFirstEnterFlag},	//(internal1_m96_MyFirstEnterFlag) MyFirstEnterFlag
	{ 974	,1	,1	, &internal1_m229_Ppv0},	//(internal1_m229_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 975	,1	,1	, &internal1_m229_Pav0},	//(internal1_m229_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 976	,1	,1	, &internal1_m229_Zav0},	//(internal1_m229_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 977	,1	,1	, &internal1_m229_RA00},	//(internal1_m229_RA00) RA00 - последнее задание вперед
	{ 978	,1	,1	, &internal1_m229_RA10},	//(internal1_m229_RA10) RA10 - последнее задание назад
	{ 979	,18	,1	, &internal1_m229_RA50},	//(internal1_m229_RA50) Ra50 - последнее задание скорости
	{ 980	,1	,1	, &internal1_m229_fls},	//(internal1_m229_fls)  fls - флаг одношагового режима
	{ 981	,1	,1	, &internal1_m229_flp},	//(internal1_m229_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 982	,1	,1	, &internal1_m229_MyFirstEnterFlag},	//(internal1_m229_MyFirstEnterFlag) MyFirstEnterFlag
	{ 983	,1	,1	, &internal1_m60_Ppv0},	//(internal1_m60_Ppv0) Ppv0 - Промежуточный путевой выключатель ОРР(80 мм)
	{ 984	,1	,1	, &internal1_m60_Pav0},	//(internal1_m60_Pav0) Pav0 - Пер.аварийный выключатель ОРР
	{ 985	,1	,1	, &internal1_m60_Zav0},	//(internal1_m60_Zav0) Zav0 - Зад.аварийный выключатель ОРР
	{ 986	,1	,1	, &internal1_m60_RA00},	//(internal1_m60_RA00) RA00 - последнее задание вперед
	{ 987	,1	,1	, &internal1_m60_RA10},	//(internal1_m60_RA10) RA10 - последнее задание назад
	{ 988	,18	,1	, &internal1_m60_RA50},	//(internal1_m60_RA50) Ra50 - последнее задание скорости
	{ 989	,1	,1	, &internal1_m60_fls},	//(internal1_m60_fls)  fls - флаг одношагового режима
	{ 990	,1	,1	, &internal1_m60_flp},	//(internal1_m60_flp)  flp - флаг сброса/подъёма от пневматики (0 - без, 1-сброс, 2-подъём)
	{ 991	,1	,1	, &internal1_m60_MyFirstEnterFlag},	//(internal1_m60_MyFirstEnterFlag) MyFirstEnterFlag
	{ 992	,8	,1	, &internal1_m14_C1},	//(internal1_m14_C1) C1 - концентрация запаздывающих нейтронов 1-го типа
	{ 993	,8	,1	, &internal1_m14_C2},	//(internal1_m14_C2) C2 - концентрация запаздывающих нейтронов 2-го типа
	{ 994	,8	,1	, &internal1_m14_C3},	//(internal1_m14_C3) C3 - концентрация запаздывающих нейтронов 3-го типа
	{ 995	,8	,1	, &internal1_m14_C4},	//(internal1_m14_C4) C4 - концентрация запаздывающих нейтронов 4-го типа
	{ 996	,8	,1	, &internal1_m14_C5},	//(internal1_m14_C5) C5 - концентрация запаздывающих нейтронов 5-го типа
	{ 997	,8	,1	, &internal1_m14_C6},	//(internal1_m14_C6) C6 - концентрация запаздывающих нейтронов 6-го типа
	{ 998	,8	,1	, &internal1_m14_N20},	//(internal1_m14_N20) N20 - пред. концентрация нейтронов второй АЗ
	{ 999	,8	,6	, &internal1_m14_C0},	//(internal1_m14_C0) *C0 - пред. концентрация запаздывающих нейтронов
	{ 1000	,1	,1	, &internal1_m14_ImpINI0},	//(internal1_m14_ImpINI0) ImpINI - Запуск системы инициирования(пред.)
	{ 1001	,1	,1	, &internal1_m14_MyFirstEnterFlag},	//(internal1_m14_MyFirstEnterFlag) MyFirstEnterFlag
	{-1,0,NULL},
};
static char NameSaveFile[]="scm.bin\0";   // Имя файла для сохранения констант
#pragma pop
static VarSaveCtrl saveVariables[]={      // Id переменных для сохранения
{278,"fEM_R0UL01RIM\0"}, 
{279,"fEM_R0UN02RIM\0"}, 
{280,"fEM_A1UR01RIM\0"}, 
{281,"fEM_A1UR00RIM\0"}, 
{282,"fEM_A3UR00RIM\0"}, 
{283,"fEM_A3UR01RIM\0"}, 
{284,"fEM_R0UT01RIM\0"}, 
{285,"fEM_R0UT02RIM\0"}, 
{286,"fEM_R0UT04RIM\0"}, 
{287,"fEM_R0UT03RIM\0"}, 
{288,"fEM_R0UT05RIM\0"}, 
{289,"fEM_R0UT06RIM\0"}, 
{290,"fEM_A1UC02RDU\0"}, 
{291,"fEM_A1UC04RIM\0"}, 
{292,"fEM_A1UC05RIM\0"}, 
{293,"fEM_A1UC06RIM\0"}, 
{294,"fEM_A2UC06RIM\0"}, 
{295,"fEM_A2UC05RIM\0"}, 
{296,"fEM_A2UC04RIM\0"}, 
{297,"fEM_A2UC02RDU\0"}, 
{298,"fEM_A3UC06RIM\0"}, 
{299,"fEM_A3UC05RIM\0"}, 
{300,"fEM_A3UC04RIM\0"}, 
{301,"fEM_A3UC02RDU\0"}, 
{302,"fEM_R4UV80RDU\0"}, 
{303,"fEM_R4UC10RIM\0"}, 
{304,"fEM_R4UC20RIM\0"}, 
{305,"fEM_B8UC21RIM\0"}, 
{306,"fEM_B8UC20RIM\0"}, 
{307,"fEM_B8UC11RIM\0"}, 
{308,"fEM_B8UC10RIM\0"}, 
{309,"fEM_B8UV80RDU\0"}, 
{310,"fEM_A8UV80RDU\0"}, 
{311,"fEM_A8UC10RIM\0"}, 
{312,"fEM_A8UC11RIM\0"}, 
{313,"fEM_A8UC20RIM\0"}, 
{314,"fEM_A8UC21RIM\0"}, 
{315,"fEM_A6UC10RIM\0"}, 
{316,"fEM_R1UC10RIM\0"}, 
{317,"fEM_A5UC10RIM\0"}, 
{318,"fEM_A0UN01RIM\0"}, 
{319,"fEM_R4UC22RIM\0"}, 
{320,"fEM_A1UG01RDU\0"}, 
{321,"fEM_A2UG01RDU\0"}, 
{322,"fEM_A3UG01RDU\0"}, 
{323,"fEM_R7UC10RIM\0"}, 
{324,"fEM_R7UC19RIM\0"}, 
{325,"fEM_R7UI02RIM\0"}, 
{326,"fEM_R7UL01RIM\0"}, 
{327,"fEM_A2UR00RIM\0"}, 
{328,"fEM_A2UR01RIM\0"}, 
{329,"fEM_A0UN02RIM\0"}, 
{330,"fEM_R0UR30RIM\0"}, 
{331,"fEM_R0UR01RIM\0"}, 
{332,"fEM_R0UT02RDU\0"}, 
{333,"fEM_R0UT01RDU\0"}, 
{334,"fEM_A1UC03RDU\0"}, 
{335,"fEM_A2UP03RDU\0"}, 
{336,"fEM_A2UP04RDU\0"}, 
{337,"fEM_A2UC03RDU\0"}, 
{338,"fEM_A3UP03RDU\0"}, 
{339,"fEM_A3UP04RDU\0"}, 
{340,"fEM_A3UC03RDU\0"}, 
{341,"fEM_R7UI74RIM\0"}, 
{342,"fEM_A8UC03RDU\0"}, 
{343,"fEM_R0UV87RDU\0"}, 
{344,"fEM_R0UV81RDU\0"}, 
{345,"fEM_R0UV82RDU\0"}, 
{346,"fEM_R0UV83RDU\0"}, 
{347,"fEM_R0UV84RDU\0"}, 
{348,"fEM_R0UV85RDU\0"}, 
{349,"fEM_R0UV86RDU\0"}, 
{350,"fEM_A8UC08RDU\0"}, 
{351,"fEM_B8UC08RDU\0"}, 
{352,"fEM_R4UC08RDU\0"}, 
{353,"fEM_R0UH01RSS\0"}, 
{354,"fEM_A0UX00RSS\0"}, 
{355,"fEM_R7UX01RSS\0"}, 
{356,"fEM_R7UX02RSS\0"}, 
{357,"fEM_R7UX04RSS\0"}, 
{358,"fEM_R7UX05RSS\0"}, 
{359,"fEM_R7UX06RSS\0"}, 
{360,"fEM_R7UX07RSS\0"}, 
{361,"fEM_R7UX08RSS\0"}, 
{362,"fEM_R7UX09RSS\0"}, 
{363,"fEM_R7UY01RSS\0"}, 
{364,"fEM_R7UY02RSS\0"}, 
{365,"fEM_R7UY04RSS\0"}, 
{366,"fEM_R7UY05RSS\0"}, 
{367,"fEM_R7UY06RSS\0"}, 
{368,"fEM_R7UY07RSS\0"}, 
{369,"fEM_R7UY08RSS\0"}, 
{370,"fEM_R7UY09RSS\0"}, 
{371,"fEM_R7UX10RSS\0"}, 
{372,"fEM_R7UX11RSS\0"}, 
{373,"fEM_R7UX12RSS\0"}, 
{374,"fEM_R7UY10RSS\0"}, 
{375,"fEM_R7UY11RSS\0"}, 
{376,"fEM_R7UY12RSS\0"}, 
{377,"fEM_A0UX01RSS\0"}, 
{378,"fEM_A0UX02RSS\0"}, 
{379,"fEM_A0UX03RSS\0"}, 
{380,"fEM_A0UX04RSS\0"}, 
{381,"fEM_A0UX05RSS\0"}, 
{382,"fEM_A0UX06RSS\0"}, 
{383,"fEM_A0UX07RSS\0"}, 
{384,"fEM_A0UX08RSS\0"}, 
{385,"fEM_A0UX09RSS\0"}, 
{386,"fEM_A0UX10RSS\0"}, 
{387,"fEM_A0UX11RSS\0"}, 
{388,"fEM_A0UX12RSS\0"}, 
{389,"fEM_B0UX01RSS\0"}, 
{390,"fEM_B0UX02RSS\0"}, 
{391,"fEM_B0UX03RSS\0"}, 
{392,"fEM_B0UX04RSS\0"}, 
{393,"fEM_B0UX05RSS\0"}, 
{394,"fEM_B0UX06RSS\0"}, 
{395,"fEM_B0UX07RSS\0"}, 
{396,"fEM_B0UX08RSS\0"}, 
{397,"fEM_B0UX09RSS\0"}, 
{398,"fEM_B0UX10RSS\0"}, 
{399,"fEM_B0UX11RSS\0"}, 
{400,"fEM_B0UX12RSS\0"}, 
{401,"fEM_R0UH02RSS\0"}, 
{402,"fEM_R0UH03RSS\0"}, 
{403,"fEM_R4US80RDU\0"}, 
{404,"fEM_R7UI71RIM\0"}, 
{405,"fEM_R7UI72RIM\0"}, 
{406,"fEM_R7UI73RIM\0"}, 
{407,"fEM_A1UP01RIM\0"}, 
{408,"fEM_A2UP01RIM\0"}, 
{409,"fEM_A0UP02RIM\0"}, 
{410,"fEM_A3UP01RIM\0"}, 
{411,"fEM_A1UP82RIM\0"}, 
{412,"fEM_A3UP02RDU\0"}, 
{413,"fEM_A1UV02RIM\0"}, 
{414,"fEM_A3UV02RIM\0"}, 
{415,"fEM_A2UV02RIM\0"}, 
{416,"fEM_B8US80RDU\0"}, 
{417,"fEM_A8US80RDU\0"}, 
{418,"fEM_A6US80RDU\0"}, 
{419,"fEM_A1US07RDU\0"}, 
{420,"fEM_A2US07RDU\0"}, 
{421,"fEM_A3US07RDU\0"}, 
{422,"fEM_R7UI75RIM\0"}, 
{423,"fEM_R0UH21RSS\0"}, 
{424,"fEM_R0UH22RSS\0"}, 
{425,"fEM_R0UH23RSS\0"}, 
{426,"fEM_R0UH05RSS\0"}, 
{427,"fEM_A4UL10RIM\0"}, 
{428,"fEM_A9UL10RIM\0"}, 
{429,"fEM_R3UL10RIM\0"}, 
{430,"fEM_R5UL10RIM\0"}, 
{431,"fEM_R6UL10RIM\0"}, 
{432,"lEM_C1AD31LRP\0"}, 
{433,"lEM_R0IE01LRP\0"}, 
{434,"lEM_R0IE02LRP\0"}, 
{435,"fEM_A2UP02RIM\0"}, 
{436,"fEM_A2UP03RIM\0"}, 
{437,"fEM_A0UP01RIM\0"}, 
{438,"fEM_A3UP02RIM\0"}, 
{439,"fEM_A4UP01RIM\0"}, 
{440,"fEM_A4UP02RIM\0"}, 
{441,"fEM_R7UI76RIM\0"}, 
{442,"fEM_R7UI77RIM\0"}, 
{443,"iEM_TERBB1\0"}, 
{444,"fEM_A1MC02RC1\0"}, 
{445,"fEM_A1MV02RC1\0"}, 
{446,"iEM_TERBB2\0"}, 
{447,"fEM_B1MC02RC1\0"}, 
{448,"fEM_B1MV02RC1\0"}, 
{449,"iEM_TERRB2\0"}, 
{450,"fEM_B2MC02RC1\0"}, 
{451,"fEM_B2MV02RC1\0"}, 
{452,"iEM_TERRB1\0"}, 
{453,"fEM_A2MC02RC1\0"}, 
{454,"fEM_A2MV02RC1\0"}, 
{455,"iEM_TERIS2\0"}, 
{456,"fEM_B3MC02RC1\0"}, 
{457,"fEM_B3MV02RC1\0"}, 
{458,"iEM_TERIS1\0"}, 
{459,"fEM_A3MC02RC1\0"}, 
{460,"fEM_A3MV02RC1\0"}, 
{461,"iEM_TERA1IE04LDU\0"}, 
{462,"iEM_TERA1IE03LDU\0"}, 
{463,"fEM_A1MC01RC1\0"}, 
{464,"iEM_TERB1IE03LDU\0"}, 
{465,"iEM_TERB1IE04LDU\0"}, 
{466,"fEM_B1MC01RC1\0"}, 
{467,"fEM_B1MV01RC1\0"}, 
{468,"fEM_B2MC01RC1\0"}, 
{469,"fEM_B2MV01RC1\0"}, 
{470,"fEM_A3MC01RC1\0"}, 
{471,"fEM_A3MV01RC1\0"}, 
{472,"fEM_B3MC01RC1\0"}, 
{473,"fEM_B3MV01RC1\0"}, 
{474,"iEM_TERA2SS21LIM\0"}, 
{475,"iEM_TERA2SS12LIM\0"}, 
{476,"iEM_TERR6SS21LIM\0"}, 
{477,"iEM_TERA2VP82LIM\0"}, 
{478,"iEM_TERA2SS11LIM\0"}, 
{479,"iEM_TERB3SS21LIM\0"}, 
{480,"iEM_TERA0MT01RIM\0"}, 
{481,"iEM_TERB0MT01RIM\0"}, 
{482,"iEM_TERA2SP01RIM\0"}, 
{483,"iEM_TERB2SP01RIM\0"}, 
{484,"iEM_TERB3SP02RIM\0"}, 
{485,"iEM_TERA3SC01RIM\0"}, 
{486,"iEM_TERA3VP81LIM\0"}, 
{487,"iEM_TERA2SC01RIM\0"}, 
{488,"iEM_TERA2SS33LIM\0"}, 
{489,"iEM_TERA3SS21LIM\0"}, 
{490,"iEM_TERA3SS33LIM\0"}, 
{491,"iEM_TERA3SS31LIM\0"}, 
{492,"iEM_TERB3SS31LIM\0"}, 
{493,"iEM_TERB3SS33LIM\0"}, 
{494,"iEM_TERB3SC01RIM\0"}, 
{495,"iEM_TERA3SS11LIM\0"}, 
{496,"iEM_TERB3SS11LIM\0"}, 
{497,"iEM_TERR6IS64LIM\0"}, 
{498,"iEM_TERB3SS22LIM\0"}, 
{499,"iEM_TERA3SS22LIM\0"}, 
{500,"iEM_TERA3SP02RIM\0"}, 
{501,"iEM_TERR6IS62LIM\0"}, 
{502,"iEM_TERR6IS66LIM\0"}, 
{503,"iEM_TERR6IS67LIM\0"}, 
{504,"iEM_TERA0VP81LIM\0"}, 
{505,"iEM_TERB0VP81LIM\0"}, 
{506,"iEM_TERR0VP81LIM\0"}, 
{507,"iEM_TERR6IS68LIM\0"}, 
{508,"iEM_TERR7SI74RIM\0"}, 
{509,"iEM_TERA5SS21LIM\0"}, 
{510,"iEM_TERB5SS11LIM\0"}, 
{511,"iEM_TERA5SS11LIM\0"}, 
{512,"iEM_TERA9SS11LIM\0"}, 
{513,"iEM_TERB2SS11LIM\0"}, 
{514,"iEM_TERB2SS12LIM\0"}, 
{515,"iEM_TERB2SS21LIM\0"}, 
{516,"iEM_TERR3SS11LIM\0"}, 
{517,"iEM_TERB2SC01RIM\0"}, 
{518,"iEM_TERR3SS21LIM\0"}, 
{519,"iEM_TERR5SS11LIM\0"}, 
{520,"iEM_TERA4SS11LIM\0"}, 
{521,"iEM_TERR1SS11LIM\0"}, 
{522,"iEM_TERR1SS21LIM\0"}, 
{523,"iEM_TERR2SS11LIM\0"}, 
{524,"iEM_TERR2SS21LIM\0"}, 
{525,"iEM_TERA4VP82LIM\0"}, 
{526,"iEM_TERB4SS21LIM\0"}, 
{527,"iEM_TERR5SS21LIM\0"}, 
{528,"iEM_TERB6SS21LIM\0"}, 
{529,"iEM_TERB4SS11LIM\0"}, 
{530,"iEM_TERA4SS21LIM\0"}, 
{531,"iEM_TERA6MS11LIM\0"}, 
{532,"iEM_TERA6SS21LIM\0"}, 
{533,"iEM_TERB6SS11LIM\0"}, 
{534,"iEM_TERR4SS11LIM\0"}, 
{535,"iEM_TERR4MS21LIM\0"}, 
{536,"iEM_TERR4SS12LIM\0"}, 
{537,"iEM_TERR4SS22LIM\0"}, 
{538,"iEM_TERR8SS11LIM\0"}, 
{539,"iEM_TERB8SC01RIM\0"}, 
{540,"iEM_TERA8SC01RIM\0"}, 
{541,"iEM_TERB8SS12LIM\0"}, 
{542,"iEM_TERA8SS12LIM\0"}, 
{543,"iEM_TERB8SS22LIM\0"}, 
{544,"iEM_TERA8SS22LIM\0"}, 
{545,"iEM_TERA9SS21LIM\0"}, 
{546,"iEM_TERB9SS21LIM\0"}, 
{547,"iEM_TERB9SS11LIM\0"}, 
{548,"iEM_TERB5SS21LIM\0"}, 
{549,"iEM_TERA1SS21LIM\0"}, 
{550,"iEM_TERA1SS11LIM\0"}, 
{551,"iEM_TERA1SC01RIM\0"}, 
{552,"iEM_TERA1SS12LIM\0"}, 
{553,"iEM_TERB1SS21LIM\0"}, 
{554,"iEM_TERB1SS11LIM\0"}, 
{555,"iEM_TERB1MC01RIM\0"}, 
{556,"iEM_TERB1SS12LIM\0"}, 
{557,"iEM_TERTLG\0"}, 
{558,"fEM_R4MC01RC1\0"}, 
{559,"fEM_R4MV01RC1\0"}, 
{560,"iEM_TERMAZ2\0"}, 
{561,"fEM_B8MC01RC1\0"}, 
{562,"fEM_B8MV01RC1\0"}, 
{563,"iEM_TERDS2\0"}, 
{564,"fEM_A8MC01RC1\0"}, 
{565,"fEM_A8MV01RC1\0"}, 
{566,"iEM_TERBZ1\0"}, 
{567,"fEM_A6MC01RC1\0"}, 
{568,"fEM_A6MV01RC1\0"}, 
{569,"iEM_TERBZ2\0"}, 
{570,"fEM_B6MC01RC1\0"}, 
{571,"fEM_B6MV01RC1\0"}, 
{572,"lEM_R3AD10LC1\0"}, 
{573,"lEM_R3AD20LC1\0"}, 
{574,"lEM_R6AD10LC1\0"}, 
{575,"lEM_R5AD10LC1\0"}, 
{576,"lEM_R5AD20LC1\0"}, 
{577,"iEM_TERMDZ2\0"}, 
{578,"fEM_R2MC01RC1\0"}, 
{579,"fEM_R2MV01RC1\0"}, 
{580,"iEM_TERMDZ1\0"}, 
{581,"fEM_R1MC01RC1\0"}, 
{582,"fEM_R1MV01RC1\0"}, 
{583,"iEM_TERNL1\0"}, 
{584,"fEM_A5MC01RC1\0"}, 
{585,"fEM_A5MV01RC1\0"}, 
{586,"iEM_TERNL2\0"}, 
{587,"fEM_B5MC01RC1\0"}, 
{588,"fEM_B5MV01RC1\0"}, 
{589,"lEM_R8AD10LC1\0"}, 
{590,"fEM_A1UC08RIM\0"}, 
{591,"fEM_A2UC08RIM\0"}, 
{592,"fEM_A3UC08RIM\0"}, 
{593,"iEM_TERB2SS33LIM\0"}, 
{594,"iEM_TERA1VP81LIM\0"}, 
{595,"iEM_TERB1VP81LIM\0"}, 
{596,"fEM_A0UT03RSP\0"}, 
{597,"fEM_A0UR01RSP\0"}, 
{598,"fEM_A0UR02RSP\0"}, 
{599,"fEM_B0UT03RSP\0"}, 
{600,"fEM_A1MC01RSP\0"}, 
{601,"fEM_A1MC02RSP\0"}, 
{602,"fEM_A1MV01RSP\0"}, 
{603,"fEM_A1MV02RSP\0"}, 
{604,"fEM_B1MC01RSP\0"}, 
{605,"fEM_B1MV01RSP\0"}, 
{606,"fEM_B1MC02RSP\0"}, 
{607,"fEM_B1MV02RSP\0"}, 
{608,"fEM_A2MC01RC1\0"}, 
{609,"fEM_A2MV01RC1\0"}, 
{610,"fEM_A2MC01RSP\0"}, 
{611,"fEM_A2MV01RSP\0"}, 
{612,"fEM_A2MC02RSP\0"}, 
{613,"fEM_A2MV02RSP\0"}, 
{614,"fEM_B2MC01RSP\0"}, 
{615,"fEM_B2MV01RSP\0"}, 
{616,"fEM_B2MC02RSP\0"}, 
{617,"fEM_B2MV02RSP\0"}, 
{618,"fEM_A3MC01RSP\0"}, 
{619,"fEM_A3MV01RSP\0"}, 
{620,"fEM_A3MC02RSP\0"}, 
{621,"fEM_A3MV02RSP\0"}, 
{622,"fEM_B3MC01RSP\0"}, 
{623,"fEM_B3MV01RSP\0"}, 
{624,"fEM_B3MC02RSP\0"}, 
{625,"fEM_B3MV02RSP\0"}, 
{626,"fEM_B8MC01RSP\0"}, 
{627,"fEM_B8MV01RSP\0"}, 
{628,"fEM_A8MC01RSP\0"}, 
{629,"fEM_A8MV01RSP\0"}, 
{630,"fEM_A6MC01RSP\0"}, 
{631,"fEM_A6MV01RSP\0"}, 
{632,"fEM_B6MC01RSP\0"}, 
{633,"fEM_B6MV01RSP\0"}, 
{634,"fEM_R3UC01RSP\0"}, 
{635,"fEM_R3UV01RSP\0"}, 
{636,"fEM_R5UC01RSP\0"}, 
{637,"fEM_R5UV01RSP\0"}, 
{638,"fEM_R6UC01RSP\0"}, 
{639,"fEM_R6UV01RSP\0"}, 
{640,"fEM_R2MC01RSP\0"}, 
{641,"fEM_R2MV01RSP\0"}, 
{642,"fEM_R1MC01RSP\0"}, 
{643,"fEM_R1MV01RSP\0"}, 
{644,"fEM_A5MC01RSP\0"}, 
{645,"fEM_A5MV01RSP\0"}, 
{646,"fEM_B5MC01RSP\0"}, 
{647,"fEM_B5MV01RSP\0"}, 
{648,"fEM_A9MC01RSP\0"}, 
{649,"fEM_A9MV01RSP\0"}, 
{650,"fEM_B9MC01RSP\0"}, 
{651,"fEM_B9MV01RSP\0"}, 
{652,"fEM_A4MC01RSP\0"}, 
{653,"fEM_A4MV01RSP\0"}, 
{654,"fEM_B4MC01RSP\0"}, 
{655,"fEM_B4MV01RSP\0"}, 
{656,"fEM_R4MC01RSP\0"}, 
{657,"fEM_R4MV01RSP\0"}, 
{658,"fEM_A1MV01RC1\0"}, 
{659,"iEM_TERB7MS31LIM\0"}, 
{660,"iEM_TERA7MS31LIM\0"}, 
{661,"fEM_R7UY00RSS\0"}, 
{662,"iEM_TERA6VS12LIM\0"}, 
{663,"iEM_TERA6VS22LIM\0"}, 
{664,"iEM_TERB6VS12LIM\0"}, 
{665,"iEM_TERB6VS22LIM\0"}, 
{666,"iEM_TERA5VS22LIM\0"}, 
{667,"iEM_TERA5VS12LIM\0"}, 
{668,"iEM_TERB5VS12LIM\0"}, 
{669,"iEM_TERB5VS22LIM\0"}, 
{670,"iEM_TERR1VS12LIM\0"}, 
{671,"iEM_TERR1VS22LIM\0"}, 
{672,"iEM_TERR2VS12LIM\0"}, 
{673,"iEM_TERR2VS22LIM\0"}, 
{674,"iEM_TERR4VS12LDU\0"}, 
{675,"iEM_TERR4VS22LDU\0"}, 
{676,"fEM_R4UC23RIM\0"}, 
{677,"fEM_A0UX13RSS\0"}, 
{678,"fEM_A0UX14RSS\0"}, 
{679,"fEM_A0UX15RSS\0"}, 
{680,"fEM_R7UX13RSS\0"}, 
{681,"fEM_R7UX14RSS\0"}, 
{682,"fEM_R7UX15RSS\0"}, 
{683,"fEM_R7UY13RSS\0"}, 
{684,"fEM_R7UY14RSS\0"}, 
{685,"fEM_R7UY15RSS\0"}, 
{686,"fEM_R7UX16RSS\0"}, 
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
	{&fEM_R0UL01RIM,8,1},	//( - , SCM) Среднее время генерации нейтронов
	{&fEM_R0UN02RIM,8,3},	//( - , SCM) Доля запаздывающих нейтронов в общем количестве нейтронов
	{&fEM_A1UR01RIM,8,5},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ББ (долл)
	{&fEM_A1UR00RIM,8,7},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ББ (долл)
	{&fEM_A3UR00RIM,8,9},	//( - , SCM) Коэффициент-0 функции реактивности вносимой ИС (долл)
	{&fEM_A3UR01RIM,8,11},	//( - , SCM) Коэффициент-1 функции реактивности вносимой ИС (долл)
	{&fEM_R0UT01RIM,8,13},	//( - , SCM) Температурный коэффициент (долл)
	{&fEM_R0UT02RIM,8,15},	//( - , SCM) Масса топлива в АЗ
	{&fEM_R0UT04RIM,8,17},	//( - , SCM) Удельная теплоёмкость топлива
	{&fEM_R0UT03RIM,8,19},	//( - , SCM) Нормальная температура АЗ град
	{&fEM_R0UT05RIM,8,21},	//( - , SCM) Энергия деления ядра
	{&fEM_R0UT06RIM,8,23},	//( - , SCM) Конвекционное сопротивление при обдуве
	{&fEM_A1UC02RDU,8,25},	//( - , SCM) Коэффициент преобразования частоты двигателя ББ в скорость мм/с
	{&fEM_A1UC04RIM,8,27},	//( - , SCM) Координата промежуточного путевого выключателя ББ мм
	{&fEM_A1UC05RIM,8,29},	//( - , SCM) Координата переднего аварийного выключателя ББ мм
	{&fEM_A1UC06RIM,8,31},	//( - , SCM) Координата заднего аварийного выключателя ББ мм
	{&fEM_A2UC06RIM,8,33},	//( - , SCM) Координата заднего аварийного выключателя РБ мм
	{&fEM_A2UC05RIM,8,35},	//( - , SCM) Координата переднего аварийного выключателя РБ мм
	{&fEM_A2UC04RIM,8,37},	//( - , SCM) Координата промежуточного путевого выключателя РБ мм
	{&fEM_A2UC02RDU,8,39},	//( - , SCM) Коэффициент преобразования частоты двигателя РБ в скорость мм/с
	{&fEM_A3UC06RIM,8,41},	//( - , SCM) Координата заднего аварийного выключателя ИС мм
	{&fEM_A3UC05RIM,8,43},	//( - , SCM) Координата переднего аварийного выключателя ИС мм
	{&fEM_A3UC04RIM,8,45},	//( - , SCM) Координата промежуточного путевого выключателя ИС мм
	{&fEM_A3UC02RDU,8,47},	//( - , SCM) Коэффициент преобразования частоты двигателя ИС в скорость мм/с
	{&fEM_R4UV80RDU,8,49},	//( - , SCM) Номинальная скорость тележки (мм/с)
	{&fEM_R4UC10RIM,8,51},	//( - , SCM) Координата верхних механических упоров тележки мм
	{&fEM_R4UC20RIM,8,53},	//( - , SCM) Координата нижних механических упоров тележки мм
	{&fEM_B8UC21RIM,8,55},	//( - , SCM) Координата верхнего путевого выключателя АЗ2 мм
	{&fEM_B8UC20RIM,8,57},	//( - , SCM) Координата верхних механических упоров АЗ2 мм
	{&fEM_B8UC11RIM,8,59},	//( - , SCM) Координата нижнего путевого выключателя АЗ2 мм
	{&fEM_B8UC10RIM,8,61},	//( - , SCM) Координата нижних механических упоров АЗ2 мм
	{&fEM_B8UV80RDU,8,63},	//( - , SCM) Номинальная скорость АЗ2 (мм/с)
	{&fEM_A8UV80RDU,8,65},	//( - , SCM) Номинальная скорость ДС2 (мм/с)
	{&fEM_A8UC10RIM,8,67},	//( - , SCM) Координата нижних механических упоров ДС2 мм
	{&fEM_A8UC11RIM,8,69},	//( - , SCM) Координата нижнего путевого выключателя ДС2 мм
	{&fEM_A8UC20RIM,8,71},	//( - , SCM) Координата верхних механических упоров ДС2 мм
	{&fEM_A8UC21RIM,8,73},	//( - , SCM) Координата верхнего путевого выключателя ДС2 мм
	{&fEM_A6UC10RIM,8,75},	//( - , SCM) Время полного хода БЗ (сек)
	{&fEM_R1UC10RIM,8,77},	//( - , SCM) Время полного хода МДЗ сек
	{&fEM_A5UC10RIM,8,79},	//( - , SCM) Время полного хода НЛ сек
	{&fEM_A0UN01RIM,8,81},	//( - , SCM) Мощность источника нейтронов ИНИ
	{&fEM_R4UC22RIM,8,83},	//( - , SCM) Смещение координаты АЗ от координаты тележки
	{&fEM_A1UG01RDU,8,85},	//( - , SCM) Расстояние включения масляного демпфера ББ(мм)
	{&fEM_A2UG01RDU,8,87},	//( - , SCM) Расстояние включения масляного демпфера РБ
	{&fEM_A3UG01RDU,8,89},	//( - , SCM) Расстояние включения масляного демпфера ИС
	{&fEM_R7UC10RIM,8,91},	//( - , SCM) X-координата КНК53М R7IN13 см
	{&fEM_R7UC19RIM,8,93},	//( - , SCM) Y-координата СНМ-11 (11) см
	{&fEM_R7UI02RIM,8,95},	//( - , SCM) Коэффициент усиления уровня радиации
	{&fEM_R7UL01RIM,8,97},	//( - , SCM) Постоянная времени изменения уровня радиации в зале
	{&fEM_A2UR00RIM,8,99},	//( - , SCM) Коэффициент-0 (долл) функции реактивности вносимой РБ (долл)
	{&fEM_A2UR01RIM,8,101},	//( - , SCM) Коэффициент-1 функции реактивности вносимой РБ (долл)
	{&fEM_A0UN02RIM,8,103},	//( - , SCM) Мощность источника нейтронов с АНИ
	{&fEM_R0UR30RIM,8,105},	//( - , SCM) Реактивность вносимая образцами (долл)
	{&fEM_R0UR01RIM,8,107},	//( - , SCM) Стартовая отрицательная реактивность
	{&fEM_R0UT02RDU,8,109},	//( - , SCM) Верхний предел шкалы датчика температуры
	{&fEM_R0UT01RDU,8,111},	//( - , SCM) Нижний предел шкалы датчика температуры
	{&fEM_A1UC03RDU,8,113},	//( - , SCM) Коэффициент преобразования показания энкодера ББ мм/дел.энкодера
	{&fEM_A2UP03RDU,8,115},	//( - , SCM) Верхний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UP04RDU,8,117},	//( - , SCM) Нижний предел шкалы датчика давления на подъем/сброс РБ
	{&fEM_A2UC03RDU,8,119},	//( - , SCM) Коэффициент преобразования показания энкодера РБ, дел.энкодера/мм
	{&fEM_A3UP03RDU,8,121},	//( - , SCM) Верхний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UP04RDU,8,123},	//( - , SCM) Нижний предел шкалы датчика давления на подъем/сброс ИС
	{&fEM_A3UC03RDU,8,125},	//( - , SCM) Коэффициент преобразования показания энкодера ИС, дел.энкодера/мм
	{&fEM_R7UI74RIM,8,127},	//( - , SCM) Верхняя граница измерения уровня радиации в зале
	{&fEM_A8UC03RDU,8,129},	//( - , SCM) Коэффициент преобразования показания энкодера АЗ2/ДС2 мм/дел.энкодера
	{&fEM_R0UV87RDU,8,131},	//( - , SCM) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV81RDU,8,133},	//( - , SCM) 1-я частота двигателя (шагов/секунду)
	{&fEM_R0UV82RDU,8,135},	//( - , SCM) 3-я частота двигателя (шагов/секунду)
	{&fEM_R0UV83RDU,8,137},	//( - , SCM) 4-я частота двигателя (шагов/секунду)
	{&fEM_R0UV84RDU,8,139},	//( - , SCM) 5-я частота двигателя (шагов/секунду)
	{&fEM_R0UV85RDU,8,141},	//( - , SCM) 6-я скорость перемещения ББ (шагов/секунду)
	{&fEM_R0UV86RDU,8,143},	//( - , SCM) 7-я скорость перемещения ББ (шагов/секунду)
	{&fEM_A8UC08RDU,8,145},	//( - , SCM) Зона срабатывания КВ ДС2(мм)
	{&fEM_B8UC08RDU,8,147},	//( - , SCM) Зона срабатывания КВ АЗ2(мм)
	{&fEM_R4UC08RDU,8,149},	//( - , SCM) Зона срабатывания КВ тележки РУ(мм)
	{&fEM_R7UX01RSS,8,151},	//( - , SCM) X-координата камеры R7IN11
	{&fEM_R7UX02RSS,8,153},	//( - , SCM) X-координата камеры R7IN12 (см)
	{&fEM_R7UX04RSS,8,155},	//( - , SCM) X-координата камеры R7IN21 (см)
	{&fEM_R7UX05RSS,8,157},	//( - , SCM) X-координата камеры R7IN22 (см)
	{&fEM_R7UX06RSS,8,159},	//( - , SCM) X-координата камеры R7IN23 (см)
	{&fEM_R7UX07RSS,8,161},	//( - , SCM) X-координата камеры R7IN31 (см)
	{&fEM_R7UX08RSS,8,163},	//( - , SCM) X-координата камеры R7IN32 (см)
	{&fEM_R7UX09RSS,8,165},	//( - , SCM) X-координата камеры R7IN33 (см)
	{&fEM_R7UY01RSS,8,167},	//( - , SCM) Y-координата камеры R7IN11
	{&fEM_R7UY02RSS,8,169},	//( - , SCM) Y-координата камеры R7IN12 (см)
	{&fEM_R7UY04RSS,8,171},	//( - , SCM) Y-координата камеры R7IN21 (см)
	{&fEM_R7UY05RSS,8,173},	//( - , SCM) Y-координата камеры R7IN22 (см)
	{&fEM_R7UY06RSS,8,175},	//( - , SCM) Y-координата камеры R7IN23 (см)
	{&fEM_R7UY07RSS,8,177},	//( - , SCM) Y-координата камеры R7IN31 (см)
	{&fEM_R7UY08RSS,8,179},	//( - , SCM) Y-координата камеры R7IN32 (см)
	{&fEM_R7UY09RSS,8,181},	//( - , SCM) Y-координата камеры R7IN33 (см)
	{&fEM_R7UX10RSS,8,183},	//( - , SCM) X-координата камеры R7IN41
	{&fEM_R7UX11RSS,8,185},	//( - , SCM) X-координата камеры R7IN42
	{&fEM_R7UX12RSS,8,187},	//( - , SCM) X-координата камеры R7IN43
	{&fEM_R7UY10RSS,8,189},	//( - , SCM) Y-координата камеры R7IN41
	{&fEM_R7UY11RSS,8,191},	//( - , SCM) Y-координата камеры R7IN42
	{&fEM_R7UY12RSS,8,193},	//( - , SCM) Y-координата камеры R7IN43
	{&fEM_A0UX01RSS,8,195},	//( - , SCM) Первый коэффициент калибровки камеры 1
	{&fEM_A0UX02RSS,8,197},	//( - , SCM) Первый коэффициент калибровки камеры 2
	{&fEM_A0UX03RSS,8,199},	//( - , SCM) Первый коэффициент калибровки камеры 3
	{&fEM_A0UX04RSS,8,201},	//( - , SCM) Первый коэффициент калибровки камеры4
	{&fEM_A0UX05RSS,8,203},	//( - , SCM) Первый коэффициент калибровки камеры 5
	{&fEM_A0UX06RSS,8,205},	//( - , SCM) Первый коэффициент калибровки камеры 6
	{&fEM_A0UX07RSS,8,207},	//( - , SCM) Первый коэффициент калибровки камеры 7
	{&fEM_A0UX08RSS,8,209},	//( - , SCM) Первый коэффициент калибровки камеры 8
	{&fEM_A0UX09RSS,8,211},	//( - , SCM) Первый коэффициент калибровки камеры 9
	{&fEM_A0UX10RSS,8,213},	//( - , SCM) Первый коэффициент калибровки камеры 10
	{&fEM_A0UX11RSS,8,215},	//( - , SCM) Первый коэффициент калибровки камеры 11
	{&fEM_A0UX12RSS,8,217},	//( - , SCM) Первый коэффициент калибровки камеры 12
	{&fEM_B0UX01RSS,8,219},	//( - , SCM) Второй коэффициент калибровки камеры 1
	{&fEM_B0UX02RSS,8,221},	//( - , SCM) Второй коэффициент калибровки камеры 2
	{&fEM_B0UX06RSS,8,223},	//( - , SCM) Второй коэффициент калибровки камеры 6
	{&fEM_B0UX07RSS,8,225},	//( - , SCM) Второй коэффициент калибровки камеры 7
	{&fEM_B0UX08RSS,8,227},	//( - , SCM) Второй коэффициент калибровки камеры 8
	{&fEM_B0UX09RSS,8,229},	//( - , SCM) Второй коэффициент калибровки камеры 9
	{&fEM_B0UX10RSS,8,231},	//( - , SCM) Второй коэффициент калибровки камеры 10
	{&fEM_B0UX11RSS,8,233},	//( - , SCM) Второй коэффициент калибровки камеры 11
	{&fEM_B0UX12RSS,8,235},	//( - , SCM) Второй коэффициент калибровки камеры 12
	{&fEM_R4US80RDU,8,237},	//( - , SCM) Тормозной путь тележки (мм)
	{&fEM_R7UI71RIM,8,239},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 1)
	{&fEM_R7UI72RIM,8,241},	//( - , SCM) Уровень мощности срабатывания АС IУР  ватт (датчик 2)
	{&fEM_R7UI73RIM,8,243},	//( - , SCM) Уровень мощности срабатывания АС II УР  ватт
	{&fEM_A1UP01RIM,8,245},	//( - , SCM) Текущее давление на сброс ББ (МПа)
	{&fEM_A2UP01RIM,8,247},	//( - , SCM) Текущее давление на сброс РБ
	{&fEM_A0UP02RIM,8,249},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP01RIM,8,251},	//( - , SCM) Текущее давление на СПУСК ИС
	{&fEM_A1UP82RIM,8,253},	//( - , SCM) Нижняя граница нормализации давления СБРОС ББ (МПа)
	{&fEM_A3UP02RDU,8,255},	//( - , SCM) Текущее давление ВЫСТРЕЛ ИС
	{&fEM_A1UV02RIM,8,257},	//( - , SCM) Ускорение сброса ББ от пневматики - g (мм/с^2)
	{&fEM_A3UV02RIM,8,259},	//( - , SCM) Ускорение сброса ИС от пневматики - g (мм/с^2)
	{&fEM_A2UV02RIM,8,261},	//( - , SCM) Ускорение сброса РБ от пневматики - g (мм/с^2)
	{&fEM_B8US80RDU,8,263},	//( - , SCM) Тормозной путь АЗ2 (мм)
	{&fEM_A8US80RDU,8,265},	//( - , SCM) Тормозной путь ДС2 (мм)
	{&fEM_A6US80RDU,8,267},	//( - , SCM) Тормозной путь БЗ (мм)
	{&fEM_A1US07RDU,8,269},	//( - , SCM) Постоянная времени масляного демпфера ББ
	{&fEM_A2US07RDU,8,271},	//( - , SCM) Постоянная времени масляного демпфера РБ
	{&fEM_A3US07RDU,8,273},	//( - , SCM) Постоянная времени масляного демпфера ИС
	{&fEM_R7UI75RIM,8,275},	//( - , SCM) Множитель к уровню радиации
	{&fEM_R0UH05RSS,8,277},	//( - , SCM) Кол-во делений/сек на 1 ватт * E^6
	{&fEM_A4UL10RIM,8,279},	//( - , SCM) Время полного перемещения НИ сек
	{&fEM_A9UL10RIM,8,281},	//( - , SCM) Время полного перемещения НИ ДС1/ДС2 сек
	{&fEM_R3UL10RIM,8,283},	//( - , SCM) Время полного хода гомогенных дверей (сек)
	{&fEM_R5UL10RIM,8,285},	//( - , SCM) Время полного хода ворот отстойной зоны (дес. мс)
	{&fEM_R6UL10RIM,8,287},	//( - , SCM) Время полного хода кран-балки сек
	{&fEM_A2UP02RIM,8,289},	//( - , SCM) Текущее давление на подъём РБ
	{&fEM_A2UP03RIM,8,291},	//( - , SCM) Нижняя граница давления на ПОДЪЁМ РБ
	{&fEM_A0UP01RIM,8,293},	//( - , SCM) Текущее давление в АЗ1,2
	{&fEM_A3UP02RIM,8,295},	//( - , SCM) Нижняя граница  давления на СПУСК ИС
	{&fEM_A4UP01RIM,8,297},	//( - , SCM) Текущее давление на подъём НИ
	{&fEM_A4UP02RIM,8,299},	//( - , SCM) Нижняя граница давления на подъём НИ
	{&fEM_R7UI76RIM,8,301},	//( - , SCM) Время задержки  срабатывания АС II УР при имитации сигнала сек
	{&fEM_R7UI77RIM,8,303},	//( - , SCM) Время задержки  срабатывания АС 1 УР при имитации сигнала сек
	{&iEM_TERBB1,3,305},	//( - , SCM) Неисправности  ББ1
	{&fEM_A1MC02RC1,8,306},	//( - , SCM) Заданная координата штока ББ1 от ИС
	{&fEM_A1MV02RC1,8,308},	//( - , SCM) Заданная скорость движения  штока ББ1 от ИС
	{&iEM_TERBB2,3,310},	//( - , SCM) Неисправности  ББ2
	{&fEM_B1MC02RC1,8,311},	//( - , SCM) Заданная координата штока ББ2 от ИС
	{&fEM_B1MV02RC1,8,313},	//( - , SCM) Заданная скорость движения штока ББ2 от ИС
	{&iEM_TERRB2,3,315},	//( - , SCM) Неисправности  РБ2
	{&fEM_B2MC02RC1,8,316},	//( - , SCM) Заданная координата штока РБ2 от ИС
	{&fEM_B2MV02RC1,8,318},	//( - , SCM) Заданная скорость движения штока РБ2 от ИС
	{&iEM_TERRB1,3,320},	//( - , SCM) Неисправности  РБ1
	{&fEM_A2MC02RC1,8,321},	//( - , SCM) Заданная координата штока РБ1 от ИС
	{&fEM_A2MV02RC1,8,323},	//( - , SCM) Заданная скорость движения штока РБ1 от ИС
	{&iEM_TERIS2,3,325},	//( - , SCM) Неисправности  ИС2
	{&fEM_B3MC02RC1,8,326},	//( - , SCM) Заданная координата штока ИС2 от ИС
	{&fEM_B3MV02RC1,8,328},	//( - , SCM) Заданная скорость движения штока ИС2 от ИС
	{&iEM_TERIS1,3,330},	//( - , SCM) Неисправности  ИС1
	{&fEM_A3MC02RC1,8,331},	//( - , SCM) Заданная координата штока ИС1 от ИС
	{&fEM_A3MV02RC1,8,333},	//( - , SCM) Заданная скорость движения штока ИС1 от ИС
	{&iEM_TERA1IE04LDU,3,335},	//( - , SCM) Искажение Движение ББ1 назад (от БУШД)
	{&iEM_TERA1IE03LDU,3,336},	//( - , SCM) Искажение Движение ББ1 вперёд (от БУШД)
	{&fEM_A1MC01RC1,8,337},	//( - , SCM) Заданная координата  ББ1 от ИС
	{&iEM_TERB1IE03LDU,3,339},	//( - , SCM) Искажение Движение ББ2 вперёд (от БУШД)
	{&iEM_TERB1IE04LDU,3,340},	//( - , SCM) Искажение Движение ББ2 назад (от БУШД)
	{&fEM_B1MC01RC1,8,341},	//( - , SCM) Заданная координата ББ2 от ИС
	{&fEM_B1MV01RC1,8,343},	//( - , SCM) Заданная скорость движения ББ2 от ИС
	{&fEM_B2MC01RC1,8,345},	//( - , SCM) Заданная координата РБ2 от ИС
	{&fEM_B2MV01RC1,8,347},	//( - , SCM) Заданная скорость движения  РБ2 от ИС
	{&fEM_A3MC01RC1,8,349},	//( - , SCM) Заданная координата ИС1 от ИС
	{&fEM_A3MV01RC1,8,351},	//( - , SCM) Заданная скорость движения ИС1 от ИС
	{&fEM_B3MC01RC1,8,353},	//( - , SCM) Заданная координата ИС2 от ИС
	{&fEM_B3MV01RC1,8,355},	//( - , SCM) Заданная скорость движения ИС2 от ИС
	{&iEM_TERA2SS21LIM,3,357},	//( - , SCM) Искажение: Приход на НУ РБ1
	{&iEM_TERA2SS12LIM,3,358},	//( - , SCM) Искажение: Магнит РБ1 зацеплен
	{&iEM_TERR6SS21LIM,3,359},	//( - , SCM) Искажение: Кран-балка в нерабочем положении
	{&iEM_TERA2VP82LIM,3,360},	//( - , SCM) Искажение: Текущее давление на подъём РБ  в норме
	{&iEM_TERA2SS11LIM,3,361},	//( - , SCM) Искажение: Приход на ВУ РБ1
	{&iEM_TERB3SS21LIM,3,362},	//( - , SCM) Искажение: Приход на НУ ИС2
	{&iEM_TERA0MT01RIM,3,363},	//( - , SCM) Искажение: Текущая температура AЗ1
	{&iEM_TERB0MT01RIM,3,364},	//( - , SCM) Искажение: Текущая температура AЗ2
	{&iEM_TERA2SP01RIM,3,365},	//( - , SCM) Искажение: Текущее давление СБРОС РБ1
	{&iEM_TERB2SP01RIM,3,366},	//( - , SCM) Искажение: Текущее давление СБРОС РБ2
	{&iEM_TERB3SP02RIM,3,367},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС2
	{&iEM_TERA3SC01RIM,3,368},	//( - , SCM) Искажение: Координата штока ИС1
	{&iEM_TERA3VP81LIM,3,369},	//( - , SCM) Искажение: Текущее давление СПУСК ИС  в норме
	{&iEM_TERA2SC01RIM,3,370},	//( - , SCM) Искажение: Координата штока РБ1
	{&iEM_TERA2SS33LIM,3,371},	//( - , SCM) Искажение: Клапан «Подъём РБ1»  открыт (обесточен)
	{&iEM_TERA3SS21LIM,3,372},	//( - , SCM) Искажение: Приход на НУ ИС1
	{&iEM_TERA3SS33LIM,3,373},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС1»  открыт (обесточен)
	{&iEM_TERA3SS31LIM,3,374},	//( - , SCM) Искажение: Клапан «СПУСК ИС1»  открыт (обесточен)
	{&iEM_TERB3SS31LIM,3,375},	//( - , SCM) Искажение: Клапан «СПУСК ИС2»  открыт (обесточен)
	{&iEM_TERB3SS33LIM,3,376},	//( - , SCM) Искажение: Клапан «ВЫСТРЕЛ ИС2»  открыт (обесточен)
	{&iEM_TERB3SC01RIM,3,377},	//( - , SCM) Искажение: Координата штока ИС2
	{&iEM_TERA3SS11LIM,3,378},	//( - , SCM) Искажение: Приход на ВУ ИС1
	{&iEM_TERB3SS11LIM,3,379},	//( - , SCM) Искажение: Приход на ВУ ИС2
	{&iEM_TERR6IS64LIM,3,380},	//( - , SCM) Искажение: Исправность ВИП ССДИ-35
	{&iEM_TERB3SS22LIM,3,381},	//( - , SCM) Искажение: Приход на НУП ИС2
	{&iEM_TERA3SS22LIM,3,382},	//( - , SCM) Искажение: Приход на НУП ИС1
	{&iEM_TERA3SP02RIM,3,383},	//( - , SCM) Искажение: Текущее давление на ВЫСТРЕЛ ИС1
	{&iEM_TERR6IS62LIM,3,384},	//( - , SCM) Искажение Исправность ВИП ССДИ-39
	{&iEM_TERR6IS66LIM,3,385},	//( - , SCM) Искажение Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&iEM_TERR6IS67LIM,3,386},	//( - , SCM) Искажение Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&iEM_TERA0VP81LIM,3,387},	//( - , SCM) Искажение: Давление  АЗ1  в норме
	{&iEM_TERB0VP81LIM,3,388},	//( - , SCM) Искажение: Давление  АЗ2 в норме
	{&iEM_TERR0VP81LIM,3,389},	//( - , SCM) Искажение: Давление  в СИСТЕМЕ-1 в норме
	{&iEM_TERR6IS68LIM,3,390},	//( - , SCM) Искажение Исправность ВИП 4,0 (№7) ССДИ-2
	{&iEM_TERR7SI74RIM,3,391},	//( - , SCM) Искажение: Радиация в реакторном зале
	{&iEM_TERA5SS21LIM,3,392},	//( - , SCM) Искажение: Приход на НУ НЛ1
	{&iEM_TERB5SS11LIM,3,393},	//( - , SCM) Искажение: Приход на ВУ НЛ2
	{&iEM_TERA5SS11LIM,3,394},	//( - , SCM) Искажение: Движенеие створок БЗ1 к ОТКРЫТА
	{&iEM_TERA9SS11LIM,3,395},	//( - , SCM) Искажение: Приход на ВУ НИ ДС1
	{&iEM_TERB2SS11LIM,3,396},	//( - , SCM) Искажение: Приход на ВУ РБ2
	{&iEM_TERB2SS12LIM,3,397},	//( - , SCM) Искажение: Магнит РБ2 зацеплен
	{&iEM_TERB2SS21LIM,3,398},	//( - , SCM) Искажение: Приход на НУ РБ2
	{&iEM_TERR3SS11LIM,3,399},	//( - , SCM) Искажение: Приход на ВУ гомогенных дверей-1
	{&iEM_TERB2SC01RIM,3,400},	//( - , SCM) Искажение: Координата штока РБ2
	{&iEM_TERR3SS21LIM,3,401},	//( - , SCM) Искажение: Приход на НУ гомогенных дверей-1
	{&iEM_TERR5SS11LIM,3,402},	//( - , SCM) Искажение: Приход на ВУ ворот отстойной зоны
	{&iEM_TERA4SS11LIM,3,403},	//( - , SCM) Искажение: Приход на ВУ НИ1
	{&iEM_TERR1SS11LIM,3,404},	//( - , SCM) Искажение: Приход на ВУ МДЗ1
	{&iEM_TERR1SS21LIM,3,405},	//( - , SCM) Искажение: Приход на НУ МДЗ1
	{&iEM_TERR2SS11LIM,3,406},	//( - , SCM) Искажение: Приход на ВУ МДЗ2
	{&iEM_TERR2SS21LIM,3,407},	//( - , SCM) Искажение: Приход на НУ МДЗ2
	{&iEM_TERA4VP82LIM,3,408},	//( - , SCM) Искажение Давление ПОДЪЁМ НИ в норме
	{&iEM_TERB4SS21LIM,3,409},	//( - , SCM) Искажение: Приход на НУ НИ2
	{&iEM_TERR5SS21LIM,3,410},	//( - , SCM) Искажение: Приход на НУ ворот отстойной зоны
	{&iEM_TERB6SS21LIM,3,411},	//( - , SCM) Искажение: Приход на НУ БЗ2
	{&iEM_TERB4SS11LIM,3,412},	//( - , SCM) Искажение: Приход на ВУ НИ2
	{&iEM_TERA4SS21LIM,3,413},	//( - , SCM) Искажение: Приход на НУ НИ1
	{&iEM_TERA6MS11LIM,3,414},	//( - , SCM) Искажение: Приход на ВУ БЗ1
	{&iEM_TERA6SS21LIM,3,415},	//( - , SCM) Искажение: Приход на НУ БЗ1
	{&iEM_TERB6SS11LIM,3,416},	//( - , SCM) Искажение: Приход на ВУ БЗ2
	{&iEM_TERR4SS11LIM,3,417},	//( - , SCM) Искажение: Приход на ВУ тележки
	{&iEM_TERR4MS21LIM,3,418},	//( - , SCM) Искажение: Приход на НУ тележки
	{&iEM_TERR4SS12LIM,3,419},	//( - , SCM) Искажение: Приход на механический ВУ тележки
	{&iEM_TERR4SS22LIM,3,420},	//( - , SCM) Искажение: Приход на механический НУ тележки
	{&iEM_TERR8SS11LIM,3,421},	//( - , SCM) Искажение: Аварийный НИ установлен
	{&iEM_TERB8SC01RIM,3,422},	//( - , SCM) Искажение: Координата АЗ2
	{&iEM_TERA8SC01RIM,3,423},	//( - , SCM) Искажение: Координата ДС2
	{&iEM_TERB8SS12LIM,3,424},	//( - , SCM) Искажение: Приход на механический ВУ АЗ2
	{&iEM_TERA8SS12LIM,3,425},	//( - , SCM) Искажение: Приход на механический ВУ ДС2
	{&iEM_TERB8SS22LIM,3,426},	//( - , SCM) Искажение: Приход на механический НУ АЗ2
	{&iEM_TERA8SS22LIM,3,427},	//( - , SCM) Искажение: Приход на механический НУ ДС2
	{&iEM_TERA9SS21LIM,3,428},	//( - , SCM) Искажение: Приход на НУ НИ ДС1
	{&iEM_TERB9SS21LIM,3,429},	//( - , SCM) Искажение: Приход на НУ НИ ДС2
	{&iEM_TERB9SS11LIM,3,430},	//( - , SCM) Искажение: Приход на ВУ НИ ДС2
	{&iEM_TERB5SS21LIM,3,431},	//( - , SCM) Искажение: Приход на НУ НЛ2
	{&iEM_TERA1SS21LIM,3,432},	//( - , SCM) Искажение: Приход на НУ ББ1
	{&iEM_TERA1SS11LIM,3,433},	//( - , SCM) Искажение: Приход на ВУ ББ1
	{&iEM_TERA1SC01RIM,3,434},	//( - , SCM) Искажение: Координата штока ББ1
	{&iEM_TERA1SS12LIM,3,435},	//( - , SCM) Искажение: Магнит ББ1 зацеплен
	{&iEM_TERB1SS21LIM,3,436},	//( - , SCM) Искажение: Приход на НУ ББ2
	{&iEM_TERB1SS11LIM,3,437},	//( - , SCM) Искажение:Приход на ВУ ББ2
	{&iEM_TERB1MC01RIM,3,438},	//( - , SCM) Искажение: Координата штока ББ2
	{&iEM_TERB1SS12LIM,3,439},	//( - , SCM) Искажение: Магнит ББ2 зацеплен
	{&iEM_TERTLG,3,440},	//( - , SCM) Неисправности  тележки от ИС
	{&fEM_R4MC01RC1,8,441},	//( - , SCM) Заданная координата тележки от ИС
	{&fEM_R4MV01RC1,8,443},	//( - , SCM) Заданная скорость тележки от ИС
	{&iEM_TERMAZ2,3,445},	//( - , SCM) Неисправности АЗ2 от ИС
	{&fEM_B8MC01RC1,8,446},	//( - , SCM) Заданная координата АЗ2 от ИС
	{&fEM_B8MV01RC1,8,448},	//( - , SCM) Заданная скорость АЗ2 от ИС
	{&iEM_TERDS2,3,450},	//( - , SCM) Неисправности ДС2 от ИС
	{&fEM_A8MC01RC1,8,451},	//( - , SCM) Заданная координата ДС2 от ИС
	{&fEM_A8MV01RC1,8,453},	//( - , SCM) Заданная скорость ДС2 от ИС
	{&iEM_TERBZ1,3,455},	//( - , SCM) Неисправности БЗ1
	{&fEM_A6MC01RC1,8,456},	//( - , SCM) Заданная координата БЗ1 от ИС
	{&fEM_A6MV01RC1,8,458},	//( - , SCM) Заданная скорость БЗ1 от ИС
	{&iEM_TERBZ2,3,460},	//( - , SCM) Неисправности БЗ2
	{&fEM_B6MC01RC1,8,461},	//( - , SCM) Заданная координата БЗ2 от ИС
	{&fEM_B6MV01RC1,8,463},	//( - , SCM) Заданная скорость БЗ2 от ИС
	{&iEM_TERMDZ2,3,465},	//( - , SCM) Неисправности МДЗ2
	{&fEM_R2MC01RC1,8,466},	//( - , SCM) Заданная координата МДЗ2 от ИС
	{&fEM_R2MV01RC1,8,468},	//( - , SCM) Заданная скорость МДЗ2 от ИС
	{&iEM_TERMDZ1,3,470},	//( - , SCM) Неисправности МДЗ1
	{&fEM_R1MC01RC1,8,471},	//( - , SCM) Заданная координата МДЗ1 от ИС
	{&fEM_R1MV01RC1,8,473},	//( - , SCM) Заданная скорость МДЗ1 от ИС
	{&iEM_TERNL1,3,475},	//( - , SCM) Неисправности НЛ1
	{&fEM_A5MC01RC1,8,476},	//( - , SCM) Заданная координата НЛ1 от ИС
	{&fEM_A5MV01RC1,8,478},	//( - , SCM) Заданная скорость НЛ1 от ИС
	{&iEM_TERNL2,3,480},	//( - , SCM) Неисправности НЛ2
	{&fEM_B5MC01RC1,8,481},	//( - , SCM) Заданная координата НЛ2 от ИС
	{&fEM_B5MV01RC1,8,483},	//( - , SCM) Заданная скорость НЛ2 от ИС
	{&fEM_A1UC08RIM,8,485},	//( - , SCM) Зона срабатывания КВ ББ(мм)
	{&fEM_A2UC08RIM,8,487},	//( - , SCM) Зона срабатывания КВ  РБ мм
	{&fEM_A3UC08RIM,8,489},	//( - , SCM) Зона срабатывания КВ ИС(мм)
	{&iEM_TERB2SS33LIM,3,491},	//( - , SCM) Искажение: Клапан «Подъём РБ2»  открыт (обесточен)
	{&iEM_TERA1VP81LIM,3,492},	//( - , SCM) Искажение: Текущее давление СБРОС ББ1  в норме
	{&iEM_TERB1VP81LIM,3,493},	//( - , SCM) Искажение: Текущее давление СБРОС ББ2  в норме
	{&fEM_A0UT03RSP,8,494},	//( - , SCM) Стартовая  температура АЗ1 град
	{&fEM_A0UR01RSP,8,496},	//( - , SCM) Стартовая  реактивность АЗ1
	{&fEM_A0UR02RSP,8,498},	//( - , SCM) Стартовый  поток нейтронов АЗ1
	{&fEM_B0UT03RSP,8,500},	//( - , SCM) Стартовая  температура АЗ2 град
	{&fEM_A1MC01RSP,8,502},	//( - , SCM) Стартовая координата  ББ1
	{&fEM_A1MC02RSP,8,504},	//( - , SCM) Стартовая координата штока ББ1
	{&fEM_A1MV01RSP,8,506},	//( - , SCM) Стартовая скорость движения  ББ1
	{&fEM_A1MV02RSP,8,508},	//( - , SCM) Стартовая скорость движения  ББ1
	{&fEM_B1MC01RSP,8,510},	//( - , SCM) Стартовая координата  ББ2
	{&fEM_B1MV01RSP,8,512},	//( - , SCM) Стартовая скорость движения  ББ2
	{&fEM_B1MC02RSP,8,514},	//( - , SCM) Стартовая координата штока ББ2
	{&fEM_B1MV02RSP,8,516},	//( - , SCM) Стартовая скорость движения  ББ2
	{&fEM_A2MC01RC1,8,518},	//( - , SCM) Заданная координата РБ1 от ИС
	{&fEM_A2MV01RC1,8,520},	//( - , SCM) Заданная скорость движения РБ1 от ИС
	{&fEM_A2MC01RSP,8,522},	//( - , SCM) Стартовая координата  РБ1
	{&fEM_A2MV01RSP,8,524},	//( - , SCM) Стартовая скорость движения  РБ1
	{&fEM_A2MC02RSP,8,526},	//( - , SCM) Стартовая координата штока РБ1
	{&fEM_A2MV02RSP,8,528},	//( - , SCM) Стартовая скорость движения  РБ1
	{&fEM_B2MC01RSP,8,530},	//( - , SCM) Стартовая координата  РБ2
	{&fEM_B2MV01RSP,8,532},	//( - , SCM) Стартовая скорость движения  РБ2
	{&fEM_B2MC02RSP,8,534},	//( - , SCM) Стартовая координата штока РБ2
	{&fEM_B2MV02RSP,8,536},	//( - , SCM) Стартовая скорость движения  РБ2
	{&fEM_A3MC01RSP,8,538},	//( - , SCM) Стартовая координата  ИС1
	{&fEM_A3MV01RSP,8,540},	//( - , SCM) Стартовая скорость движения  ИС1
	{&fEM_A3MC02RSP,8,542},	//( - , SCM) Стартовая координата штока ИС1
	{&fEM_A3MV02RSP,8,544},	//( - , SCM) Стартовая скорость движения  ИС1
	{&fEM_B3MC01RSP,8,546},	//( - , SCM) Стартовая координата  ИС2
	{&fEM_B3MV01RSP,8,548},	//( - , SCM) Стартовая скорость движения  ИС2
	{&fEM_B3MC02RSP,8,550},	//( - , SCM) Стартовая координата штока ИС2
	{&fEM_B3MV02RSP,8,552},	//( - , SCM) Стартовая скорость движения  ИС2
	{&fEM_B8MC01RSP,8,554},	//( - , SCM) Стартовая координата АЗ2
	{&fEM_B8MV01RSP,8,556},	//( - , SCM) Стартовая скорость АЗ2
	{&fEM_A8MC01RSP,8,558},	//( - , SCM) Стартовая координата ДС2
	{&fEM_A8MV01RSP,8,560},	//( - , SCM) Стартовая скорость ДС2
	{&fEM_A6MC01RSP,8,562},	//( - , SCM) Стартовая координата БЗ1
	{&fEM_A6MV01RSP,8,564},	//( - , SCM) Стартовая скорость БЗ1
	{&fEM_B6MC01RSP,8,566},	//( - , SCM) Стартовая координата БЗ2
	{&fEM_B6MV01RSP,8,568},	//( - , SCM) Стартовая скорость БЗ2
	{&fEM_R3UC01RSP,8,570},	//( - , SCM) Стартовая координата Гомогенных дверей
	{&fEM_R3UV01RSP,8,572},	//( - , SCM) Стартовая скорость Гомогенных дверей
	{&fEM_R5UC01RSP,8,574},	//( - , SCM) Стартовая координата Ворот отстойной зоны
	{&fEM_R5UV01RSP,8,576},	//( - , SCM) Стартовая скорость Ворот отстойной зоны
	{&fEM_R6UC01RSP,8,578},	//( - , SCM) Стартовая координата Кран-балки
	{&fEM_R6UV01RSP,8,580},	//( - , SCM) Стартовая скорость Кран-балки
	{&fEM_R2MC01RSP,8,582},	//( - , SCM) Стартовая координата МДЗ2
	{&fEM_R2MV01RSP,8,584},	//( - , SCM) Стартовая скорость МДЗ2
	{&fEM_R1MC01RSP,8,586},	//( - , SCM) Стартовая координата МДЗ1
	{&fEM_R1MV01RSP,8,588},	//( - , SCM) Стартовая скорость МДЗ1
	{&fEM_A5MC01RSP,8,590},	//( - , SCM) Стартовая координата НЛ1
	{&fEM_A5MV01RSP,8,592},	//( - , SCM) Стартовая скорость НЛ1
	{&fEM_B5MC01RSP,8,594},	//( - , SCM) Стартовая координата НЛ2
	{&fEM_B5MV01RSP,8,596},	//( - , SCM) Стартовая скорость НЛ2
	{&fEM_A9MC01RSP,8,598},	//( - , SCM) Стартовая координата НИ ДС1
	{&fEM_A9MV01RSP,8,600},	//( - , SCM) Стартовая скорость НИ ДС1
	{&fEM_B9MC01RSP,8,602},	//( - , SCM) Стартовая координата НИ ДС2
	{&fEM_B9MV01RSP,8,604},	//( - , SCM) Стартовая скорость НИ ДС2
	{&fEM_A4MC01RSP,8,606},	//( - , SCM) Стартовая координата НИ1
	{&fEM_A4MV01RSP,8,608},	//( - , SCM) Стартовая скорость НИ1
	{&fEM_B4MC01RSP,8,610},	//( - , SCM) Стартовая координата НИ2
	{&fEM_B4MV01RSP,8,612},	//( - , SCM) Стартовая скорость НИ2
	{&fEM_R4MC01RSP,8,614},	//( - , SCM) Стартовая координата тележки
	{&fEM_R4MV01RSP,8,616},	//( - , SCM) Стартовая скорость тележки
	{&fEM_A1MV01RC1,8,618},	//( - , SCM) Заданная скорость движения  ББ1 от ИС
	{&iEM_TERB7MS31LIM,3,620},	//( - , SCM) Искажение: Клапан (Обдув АЗ2) открыт (обесточен)
	{&iEM_TERA7MS31LIM,3,621},	//( - , SCM) Искажение:  Клапан «Обдув АЗ1» открыт (обесточен)
	{&fEM_R7UY00RSS,8,622},	//( - , SCM) Y-координата АЗ1 см
	{&iEM_TERA6VS12LIM,3,624},	//( - , SCM) Искажение: Движение створок БЗ1 к ОТКРЫТА
	{&iEM_TERA6VS22LIM,3,625},	//( - , SCM) Искажение: Движение створок БЗ1 к ЗАКРЫТА
	{&iEM_TERB6VS12LIM,3,626},	//( - , SCM) Искажение: Движение створок БЗ2 к ОТКРЫТА
	{&iEM_TERB6VS22LIM,3,627},	//( - , SCM) Искажение: Движение створок БЗ2 к ЗАКРЫТА
	{&iEM_TERA5VS22LIM,3,628},	//( - , SCM) Искажение: Движение створок НЛ1 к НУ
	{&iEM_TERA5VS12LIM,3,629},	//( - , SCM) Искажение: Движение створок НЛ1 к ВУ
	{&iEM_TERB5VS12LIM,3,630},	//( - , SCM) Искажение: Движение створок НЛ2 к ВУ
	{&iEM_TERB5VS22LIM,3,631},	//( - , SCM) Искажение: Движение створок НЛ2 к НУ
	{&iEM_TERR1VS12LIM,3,632},	//( - , SCM) Искажение: Движение МДЗ1 в сторону ВУ
	{&iEM_TERR1VS22LIM,3,633},	//( - , SCM) Искажение: Движение МДЗ1 в сторону НУ
	{&iEM_TERR2VS12LIM,3,634},	//( - , SCM) Искажение: Движение МДЗ2 в сторону ВУ
	{&iEM_TERR2VS22LIM,3,635},	//( - , SCM) Искажение: Движение МДЗ2 в сторону НУ
	{&iEM_TERR4VS12LDU,3,636},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
	{&iEM_TERR4VS22LDU,3,637},	//( - , SCM) Искажение: Движение реактора к «У ЗАЩИТЫ»
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
	{&R6IS66LZZ,1,0},	//( - K17DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&R6IS67LZZ,1,1},	//( - K18DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&R6IS68LZZ,1,2},	//( - K19DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№7) ССДИ-2
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
	{&R6IS66LZZ,1,0},	//( - K17DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&R6IS67LZZ,1,1},	//( - K18DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&R6IS68LZZ,1,2},	//( - K19DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№7) ССДИ-2
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
	{&B4VP82LDU,1,0},	//( - , SDu) Давление ПОДЪЁМ НИ2 в норме
	{&A4VP82LDU,1,1},	//( - , SDu) Давление ПОДЪЁМ НИ1 в норме
	{&B2VP82LDU,1,2},	//( - , SDu) Давление ПОДЪЁМ РБ2 в норме
	{&R6IS68LZZ,1,3},	//( - K19DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№7) ССДИ-2
	{&R6IS67LZZ,1,4},	//( - K18DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№6) ССДИ-1-2
	{&R6IS66LZZ,1,5},	//( - K17DO, SBz1, SBz2, SDu) Исправность ВИП 4,0 (№5) ССДИ-1-1
	{&B3VP81LDU,1,6},	//( - , SDu) Давление СПУСК ИС2 в норме
	{&A3VP81LDU,1,7},	//( - , SDu) Давление СПУСК ИС1 в норме
	{&A2VP82LDU,1,8},	//( - , SDu) Давление ПОДЪЁМ РБ1 в норме
	{NULL,0,0},
};
#pragma pop
#pragma pack(push,1)
static ModbusRegister ir_SDu[]={  // 
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
	{&A3IP02IDU,3,24},
	{&A2IP01IZ2,3,15},
	{&B0IT02IZ2,3,18},
	{&B0IT01IZ1,3,6},
	{&A0IT02IZ2,3,12},
	{&B3IP02IDU,3,27},
	{&A2IP01IZ1,3,3},
	{&A0IT03IRP,3,30},
	{&B0IT03IRP,3,33},
	{&A0IT01IZ1,3,0},
	{&B2IP01IZ2,3,21},
	{&B2IP01IZ1,3,9},
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
	{&A3IS22LDU,1,10},
	{&A1VP81LZZ,1,54},
	{&A3IS11LDU,1,8},
	{&R7II73LZ1,1,50},
	{&R7II71LZ1,1,46},
	{&R7II72LZ1,1,48},
	{&R6IS66LZZ,1,32},
	{&R6IS67LZZ,1,34},
	{&R6IS68LZZ,1,36},
	{&A0VP81LZZ,1,52},
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
	{&R7II72LZ2,1,48},
	{&R7II71LZ2,1,46},
	{&R7II73LZ2,1,50},
	{&B3IS11LDU,1,20},
	{&B3IS22LDU,1,22},
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
	{&R2IS21LDU,1,48},
	{&B3IS21LDU,1,24},
	{&B2IS11LDU,1,20},
	{&B2IS12LDU,1,18},
	{&A4IS11LDU,1,30},
	{&A4IS21LDU,1,32},
	{&R8IS11LDU,1,26},
	{&R1IS11LDU,1,42},
	{&R1IS21LDU,1,44},
	{&R2IS11LDU,1,46},
	{&B7AS31LDU,1,10},
	{&A7AS31LDU,1,60},
	{&A9IS11LDU,1,34},
	{&A9IS21LDU,1,36},
	{&B9IS11LDU,1,38},
	{&B9IS21LDU,1,40},
	{&B2IS21LDU,1,22},
	{&A1IS12LDU,1,62},
	{&B1IS21LDU,1,16},
	{&B1IS11LDU,1,14},
	{&B1IS12LDU,1,12},
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
	{&A3IS21LDU,1,10},
	{&A2IS12LDU,1,4},
	{&A2IS11LDU,1,6},
	{&A2IS21LDU,1,8},
	{&R0IS02LDU,1,32},
	{&B4IS11LDU,1,12},
	{&B4IS21LDU,1,14},
	{&A5IS11LDU,1,54},
	{&A5IS21LDU,1,56},
	{&B5IS11LDU,1,62},
	{&R4IS11LDU,1,42},
	{&R4IS21LDU,1,46},
	{&R4IS22LDU,1,48},
	{&R4IS12LDU,1,44},
	{&A6IS21LDU,1,52},
	{&B6IS11LDU,1,58},
	{&B6IS21LDU,1,60},
	{&A1IS21LDU,1,2},
	{&A1IS11LDU,1,0},
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
	{&B5IS21LDU,1,0},
	{&B8IS22LDU,1,12},
	{&B8IS12LDU,1,10},
	{&R3IS11LDU,1,2},
	{&R6IS21LDU,1,26},
	{&A8IS22LDU,1,30},
	{&R3IS21LDU,1,4},
	{&A8IS12LDU,1,28},
	{&R5IS11LDU,1,18},
	{&B8IS11LDU,1,14},
	{&B8IS21LDU,1,8},
	{&R5IS21LDU,1,20},
	{&A6IS11LDU,1,34},
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
	{&R6IS62LDU,1,56},
	{&R6IS63LDU,1,58},
	{&R6IS64LDU,1,60},
	{&R6IS65LDU,1,62},
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
	{&A3AD34LDU,1,22},
	{&B7AP31LDU,1,60},
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
	setAsFloat(278,0.015);
	setAsFloat(279,0.0069);
	setAsFloat(280,0.21);
	setAsFloat(281,0);
	setAsFloat(282,0);
	setAsFloat(283,0.0096);
	setAsFloat(284,0.0026);
	setAsFloat(285,106);
	setAsFloat(286,135.227);
	setAsFloat(287,25);
	setAsFloat(288,320.435466);
	setAsFloat(289,0.0055);
	setAsFloat(290,0.000877);
	setAsFloat(291,200);
	setAsFloat(292,100);
	setAsFloat(293,0);
	setAsFloat(294,0);
	setAsFloat(295,100);
	setAsFloat(296,80);
	setAsFloat(297,0.002375);
	setAsFloat(298,0);
	setAsFloat(299,165);
	setAsFloat(300,200);
	setAsFloat(301,0.001675);
	setAsFloat(302,40);
	setAsFloat(303,15630.0);
	setAsFloat(304,1374);
	setAsFloat(305,0);
	setAsFloat(306,390.0);
	setAsFloat(307,2000.0);
	setAsFloat(308,1500.0);
	setAsFloat(309,10.91);
	setAsFloat(310,10.91);
	setAsFloat(311,1500.0);
	setAsFloat(312,2000);
	setAsFloat(313,390.0);
	setAsFloat(314,0);
	setAsFloat(315,55.0);
	setAsFloat(316,15.0);
	setAsFloat(317,5.0);
	setAsFloat(318,1E12);
	setAsFloat(319,43.6);
	setAsFloat(320,20.0);
	setAsFloat(321,20.0);
	setAsFloat(322,20.0);
	setAsFloat(323,1269.0);
	setAsFloat(324,256.0);
	setAsFloat(325,1.0);
	setAsFloat(326,2.0);
	setAsFloat(327,0);
	setAsFloat(328,0.026);
	setAsFloat(329,0.08);
	setAsFloat(330,0.0);
	setAsFloat(331,27.108);
	setAsFloat(332,600);
	setAsFloat(333,0);
	setAsFloat(334,0.00009765625);
	setAsFloat(335,1.6);
	setAsFloat(336,0);
	setAsFloat(337,0.00009765625);
	setAsFloat(338,1.6);
	setAsFloat(339,0);
	setAsFloat(340,0.00009765625);
	setAsFloat(341,10000.0);
	setAsFloat(342,0.0009765625);
	setAsFloat(343,750);
	setAsFloat(344,100);
	setAsFloat(345,200);
	setAsFloat(346,300);
	setAsFloat(347,400);
	setAsFloat(348,500);
	setAsFloat(349,600);
	setAsFloat(350,0.50);
	setAsFloat(351,0.50);
	setAsFloat(352,0.50);
	setAsFloat(353,2);
	setAsFloat(354,11.0);
	setAsFloat(355,1585.0);
	setAsFloat(356,1796.0);
	setAsFloat(357,1555.0);
	setAsFloat(358,1269.0);
	setAsFloat(359,1269.0);
	setAsFloat(360,1585.0);
	setAsFloat(361,1796.0);
	setAsFloat(362,1269.0);
	setAsFloat(363,248.0);
	setAsFloat(364,284.5);
	setAsFloat(365,248.0);
	setAsFloat(366,271.6);
	setAsFloat(367,287.2);
	setAsFloat(368,594.0);
	setAsFloat(369,559.0);
	setAsFloat(370,588.0);
	setAsFloat(371,1555.0);
	setAsFloat(372,1281.2);
	setAsFloat(373,1269.0);
	setAsFloat(374,594.0);
	setAsFloat(375,597.2);
	setAsFloat(376,556.8);
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
	setAsFloat(388,1.0);
	setAsFloat(389,0);
	setAsFloat(390,0);
	setAsFloat(391,0);
	setAsFloat(392,0);
	setAsFloat(393,0.0);
	setAsFloat(394,0);
	setAsFloat(395,0.0);
	setAsFloat(396,0);
	setAsFloat(397,0.0);
	setAsFloat(398,0.0);
	setAsFloat(399,0.0);
	setAsFloat(400,0.0);
	setAsFloat(401,3703.704);
	setAsFloat(402,62500.0);
	setAsFloat(403,20);
	setAsFloat(404,18000);
	setAsFloat(405,18000);
	setAsFloat(406,18000);
	setAsFloat(407,0.76);
	setAsFloat(408,0.245);
	setAsFloat(409,2.9);
	setAsFloat(410,0.13);
	setAsFloat(411,0.73);
	setAsFloat(412,0.41);
	setAsFloat(413,9807.0);
	setAsFloat(414,22975.0);
	setAsFloat(415,12750.0);
	setAsFloat(416,20);
	setAsFloat(417,20);
	setAsFloat(418,0);
	setAsFloat(419,5.0);
	setAsFloat(420,5.0);
	setAsFloat(421,5.0);
	setAsFloat(422,100.0);
	setAsFloat(423,4000);
	setAsFloat(424,100000);
	setAsFloat(425,1000000);
	setAsFloat(426,32000.0);
	setAsFloat(427,5.0);
	setAsFloat(428,15.0);
	setAsFloat(429,15.0);
	setAsFloat(430,20.0);
	setAsFloat(431,10.0);
	setAsBool(432,0);
	setAsBool(433,0);
	setAsBool(434,0);
	setAsFloat(435,0.45);
	setAsFloat(436,0.39);
	setAsFloat(437,2.74);
	setAsFloat(438,0.07);
	setAsFloat(439,0.275);
	setAsFloat(440,0.245);
	setAsFloat(441,0.045);
	setAsFloat(442,0.05);
	setAsShort(443,0);
	setAsFloat(444,0);
	setAsFloat(445,0);
	setAsShort(446,0);
	setAsFloat(447,0);
	setAsFloat(448,0);
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
	setAsShort(462,0);
	setAsFloat(463,0);
	setAsShort(464,0);
	setAsShort(465,0);
	setAsFloat(466,0);
	setAsFloat(467,0);
	setAsFloat(468,0);
	setAsFloat(469,0);
	setAsFloat(470,0);
	setAsFloat(471,0);
	setAsFloat(472,0);
	setAsFloat(473,0);
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
	setAsShort(557,0);
	setAsFloat(558,0);
	setAsFloat(559,0);
	setAsShort(560,0);
	setAsFloat(561,0);
	setAsFloat(562,0);
	setAsShort(563,0);
	setAsFloat(564,0);
	setAsFloat(565,0);
	setAsShort(566,0);
	setAsFloat(567,0);
	setAsFloat(568,0);
	setAsShort(569,0);
	setAsFloat(570,0);
	setAsFloat(571,0);
	setAsBool(572,0);
	setAsBool(573,1);
	setAsBool(574,0);
	setAsBool(575,1);
	setAsBool(576,0);
	setAsShort(577,0);
	setAsFloat(578,0);
	setAsFloat(579,0);
	setAsShort(580,0);
	setAsFloat(581,0);
	setAsFloat(582,0);
	setAsShort(583,0);
	setAsFloat(584,0);
	setAsFloat(585,0);
	setAsShort(586,0);
	setAsFloat(587,0);
	setAsFloat(588,0);
	setAsBool(589,1);
	setAsFloat(590,0.01);
	setAsFloat(591,0.01);
	setAsFloat(592,0.01);
	setAsShort(593,0);
	setAsShort(594,0);
	setAsShort(595,0);
	setAsFloat(596,25.017338);
	setAsFloat(597,-0.15912805);
	setAsFloat(598,0.000000166);
	setAsFloat(599,25.017338);
	setAsFloat(600,0);
	setAsFloat(601,0.000167646);
	setAsFloat(602,0);
	setAsFloat(603,0);
	setAsFloat(604,0);
	setAsFloat(605,0);
	setAsFloat(606,0.000167676);
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
	setAsFloat(617,0);
	setAsFloat(618,0.000885839);
	setAsFloat(619,0);
	setAsFloat(620,0.000885839);
	setAsFloat(621,0);
	setAsFloat(622,0.000885839);
	setAsFloat(623,0);
	setAsFloat(624,0.000885839);
	setAsFloat(625,0);
	setAsFloat(626,390);
	setAsFloat(627,0);
	setAsFloat(628,390);
	setAsFloat(629,0);
	setAsFloat(630,55);
	setAsFloat(631,0);
	setAsFloat(632,55);
	setAsFloat(633,0);
	setAsFloat(634,0);
	setAsFloat(635,0);
	setAsFloat(636,4000.0);
	setAsFloat(637,0);
	setAsFloat(638,10);
	setAsFloat(639,0);
	setAsFloat(640,0);
	setAsFloat(641,0);
	setAsFloat(642,0);
	setAsFloat(643,0);
	setAsFloat(644,5);
	setAsFloat(645,0);
	setAsFloat(646,5);
	setAsFloat(647,0);
	setAsFloat(648,0);
	setAsFloat(649,0);
	setAsFloat(650,0);
	setAsFloat(651,0);
	setAsFloat(652,0);
	setAsFloat(653,0);
	setAsFloat(654,0);
	setAsFloat(655,0);
	setAsFloat(656,15650);
	setAsFloat(657,0);
	setAsFloat(658,0);
	setAsShort(659,0);
	setAsShort(660,0);
	setAsFloat(661,506.6);
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
	setAsShort(675,0);
	setAsFloat(676,5065.0);
	setAsFloat(677,1.0);
	setAsFloat(678,1.0);
	setAsFloat(679,1.0);
	setAsFloat(680,1570.0);
	setAsFloat(681,1269);
	setAsFloat(682,1281.2);
	setAsFloat(683,248.0);
	setAsFloat(684,572.4);
	setAsFloat(685,246.8);
	setAsFloat(686,1);
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
ssint iRM_1_ = {1,0}; /* признак константа */ 

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
psbool  array_m922_x_1[2] = {&lEM_R0IE02LRP,&lEM_R0IE01LRP};
psbool  array_m917_x_1[2] = {&var167,&R0MW13LP2};
psbool  array_m942_x_1[2] = {&var174,&R0MW13LP2};
psbool  array_m935_x_1[2] = {&var175,&R0MW13LP2};
psbool  array_m927_x_1[2] = {&var176,&R0MW13LP2};
psbool  array_m634_x_1[2] = {&var32,&var228};
psbool  array_m631_x_1[2] = {&var32,&var229};
psbool  array_m641_x_1[3] = {&lEM_C1AD31LRP,&R0VZ71LZ1,&R0VZ71LZ2};
psbool  array_m919_x_1[2] = {&var199,&R0MW13LP2};
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
psfloat  array_m130_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m267_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m96_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m229_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m60_Vr_1[8] = {&fRM_1_,&fEM_R0UV81RDU,&fEM_R0UV82RDU,&fEM_R0UV83RDU,&fEM_R0UV84RDU,&fEM_R0UV85RDU,&fEM_R0UV86RDU,&fEM_R0UV87RDU};
psfloat  array_m14_C0_1[6];

/* Объявление структур */
_S_to3val  S_to3val_971_1 = {&fEM_R7UX16RSS,&fRM_900_,&fRM_15_,&fRM_0_0015,&fRM_0_,&fRM_2000_,&fRM_2000_,&TerR0IN06FRP,&var1,&var2,&vainSFloat,&bFirstEnterFlag};
_S_vchs  S_vchs_896_1 = {&var280,&var331,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX15RSS,&fEM_R7UY15RSS,&bRM_5_,&fEM_A0UX15RSS,&fEM_B0UX05RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var3,&internal1_m896_Chim0};
_S_vchs  S_vchs_886_1 = {&var331,&var280,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX14RSS,&fEM_R7UY14RSS,&bRM_4_,&fEM_A0UX14RSS,&fEM_B0UX04RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var4,&internal1_m886_Chim0};
_S_vchs  S_vchs_878_1 = {&var331,&var280,&var241,&fEM_R4UC23RIM,&fEM_R7UY00RSS,&fEM_R7UX13RSS,&fEM_R7UY13RSS,&bRM_2_,&fEM_A0UX13RSS,&fEM_B0UX03RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var5,&internal1_m878_Chim0};
_S_twobool  S_twobool_833_1 = {&var278,&iEM_TERR4VS22LDU,&var6,&vainSBool,&internal1_m833_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_832_1 = {&var277,&iEM_TERR4VS12LDU,&var7,&vainSBool,&internal1_m832_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1016_1 = {&var254,&iEM_TERR2VS22LIM,&var8,&vainSBool,&internal1_m1016_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1015_1 = {&var253,&iEM_TERR2VS12LIM,&var9,&vainSBool,&internal1_m1015_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1014_1 = {&var258,&iEM_TERR1VS22LIM,&var10,&vainSBool,&internal1_m1014_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1013_1 = {&var257,&iEM_TERR1VS12LIM,&var11,&vainSBool,&internal1_m1013_Out10,&bFirstEnterFlag};
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
_S_noto  S_noto_478_1 = {&var184,&var25};
_S_noto  S_noto_481_1 = {&var185,&var26};
_S_rs  S_rs_488_1 = {&var24,&lEM_R5AD10LC1,&var27,&vainSBool,&internal1_m488_q0};
_S_rs  S_rs_489_1 = {&var23,&lEM_R5AD20LC1,&var28,&vainSBool,&internal1_m489_q0};
_S_rs  S_rs_474_1 = {&var25,&lEM_R3AD10LC1,&var29,&vainSBool,&internal1_m474_q0};
_S_rs  S_rs_475_1 = {&var26,&lEM_R3AD20LC1,&var30,&vainSBool,&internal1_m475_q0};
_S_andn  S_andn_357_1 = {array_m357_x_1,&iRM_16_,&vainSBool};
_S_zpfs  S_zpfs_644_1 = {&R0AD14LDU,&fEM_R7UI76RIM,&var31,&internal1_m644_tx,&internal1_m644_y0};
_S_zpfs  S_zpfs_632_1 = {&R0AD16LDU,&fEM_R7UI77RIM,&var32,&internal1_m632_tx,&internal1_m632_y0};
_S_bol  S_bol_957_1 = {&fEM_A4UP01RIM,&fEM_A4UP02RIM,&var33};
_S_bol  S_bol_954_1 = {&fEM_A3UP01RIM,&fEM_A3UP02RIM,&var34};
_S_bol  S_bol_933_1 = {&fEM_A0UP02RIM,&fEM_A0UP01RIM,&var35};
_S_bol  S_bol_955_1 = {&fEM_A2UP02RIM,&fEM_A2UP03RIM,&var36};
_S_bol  S_bol_945_1 = {&fEM_A1UP01RIM,&fEM_A1UP82RIM,&var37};
_S_ampl  S_ampl_374_1 = {&var218,&fRM_0_1,&vainSFloat};
_S_or2  S_or2_946_1 = {&R0EE04LZ1,&R0EE04LZ2,&var38};
_S_or2  S_or2_937_1 = {&R0EE03LZ1,&R0EE03LZ2,&var39};
_S_or2  S_or2_930_1 = {&R0EE02LZ1,&R0EE02LZ2,&var40};
_S_or2  S_or2_923_1 = {&R0EE01LZ1,&R0EE01LZ2,&var41};
_S_zpfs  S_zpfs_618_1 = {&var186,&fRM_1_0,&var42,&internal1_m618_tx,&internal1_m618_y0};
_S_zpfs  S_zpfs_616_1 = {&var189,&fRM_0_5,&var43,&internal1_m616_tx,&internal1_m616_y0};
_S_twobool  S_twobool_208_1 = {&B1AD21LDU,&iEM_TERB1IE04LDU,&var44,&vainSBool,&internal1_m208_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_226_1 = {&B1AD11LDU,&iEM_TERB1IE03LDU,&var45,&vainSBool,&internal1_m226_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_41_1 = {&A1AD21LDU,&iEM_TERA1IE04LDU,&var46,&vainSBool,&internal1_m41_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_56_1 = {&A1AD11LDU,&iEM_TERA1IE03LDU,&var47,&vainSBool,&internal1_m56_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_987_1 = {&var322,&iEM_TERB1SS12LIM,&var48,&vainSBool,&internal1_m987_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_984_1 = {&var318,&iEM_TERB1SS11LIM,&var49,&vainSBool,&internal1_m984_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_983_1 = {&var319,&iEM_TERB1SS21LIM,&var50,&vainSBool,&internal1_m983_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_986_1 = {&var52,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var51,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m986_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_981_1 = {&var221,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB1MC01RIM,&var52,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_969_1 = {&var54,&fEM_A1UC03RDU,&fRM_0_,&iRM_0_,&var53,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m969_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_962_1 = {&var222,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA1SC01RIM,&var54,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_970_1 = {&var329,&iEM_TERA1SS12LIM,&var55,&vainSBool,&internal1_m970_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_967_1 = {&var326,&iEM_TERA1SS11LIM,&var56,&vainSBool,&internal1_m967_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_966_1 = {&var327,&iEM_TERA1SS21LIM,&var57,&vainSBool,&internal1_m966_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1054_1 = {&var260,&iEM_TERB6SS21LIM,&var58,&vainSBool,&internal1_m1054_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1035_1 = {&var259,&iEM_TERB6SS11LIM,&var59,&vainSBool,&internal1_m1035_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1034_1 = {&var264,&iEM_TERA6SS21LIM,&var60,&vainSBool,&internal1_m1034_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1033_1 = {&var263,&iEM_TERA6MS11LIM,&var61,&vainSBool,&internal1_m1033_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_854_1 = {&var269,&iEM_TERA8SS12LIM,&var62,&vainSBool,&internal1_m854_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_856_1 = {&var268,&iEM_TERA8SS22LIM,&var63,&vainSBool,&internal1_m856_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_853_1 = {&var272,&iEM_TERB8SS12LIM,&var64,&var65,&internal1_m853_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_855_1 = {&var271,&iEM_TERB8SS22LIM,&var66,&var67,&internal1_m855_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_829_1 = {&var273,&iEM_TERR4SS12LIM,&var68,&vainSBool,&internal1_m829_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_830_1 = {&var274,&iEM_TERR4SS22LIM,&var69,&vainSBool,&internal1_m830_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_828_1 = {&var276,&iEM_TERR4MS21LIM,&var70,&vainSBool,&internal1_m828_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_827_1 = {&var275,&iEM_TERR4SS11LIM,&var71,&vainSBool,&internal1_m827_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1049_1 = {&var33,&iEM_TERA4VP82LIM,&var72,&var73,&internal1_m1049_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1001_1 = {&var252,&iEM_TERR2SS21LIM,&var74,&vainSBool,&internal1_m1001_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1000_1 = {&var251,&iEM_TERR2SS11LIM,&var75,&vainSBool,&internal1_m1000_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_999_1 = {&var256,&iEM_TERR1SS21LIM,&var76,&vainSBool,&internal1_m999_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_998_1 = {&var255,&iEM_TERR1SS11LIM,&var77,&vainSBool,&internal1_m998_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1050_1 = {&var191,&iEM_TERB4SS21LIM,&var78,&vainSBool,&internal1_m1050_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1031_1 = {&var190,&iEM_TERB4SS11LIM,&var79,&vainSBool,&internal1_m1031_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_831_1 = {&lEM_R8AD10LC1,&iEM_TERR8SS11LIM,&var80,&vainSBool,&internal1_m831_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1032_1 = {&var188,&iEM_TERA4SS21LIM,&var81,&vainSBool,&internal1_m1032_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1030_1 = {&var187,&iEM_TERA4SS11LIM,&var82,&vainSBool,&internal1_m1030_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1051_1 = {&var183,&iEM_TERR5SS21LIM,&var83,&vainSBool,&internal1_m1051_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1029_1 = {&var182,&iEM_TERR5SS11LIM,&var84,&vainSBool,&internal1_m1029_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1012_1 = {&var185,&iEM_TERR3SS21LIM,&var85,&vainSBool,&internal1_m1012_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_997_1 = {&var184,&iEM_TERR3SS11LIM,&var86,&vainSBool,&internal1_m997_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_546_1 = {&var36,&iEM_TERA2VP82LIM,&var87,&var88,&internal1_m546_Out10,&bFirstEnterFlag};
_S_toao  S_toao_550_1 = {&var92,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var89,&bFirstEnterFlag};
_S_toao  S_toao_549_1 = {&var91,&fEM_A2UP04RDU,&fEM_A2UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var90,&bFirstEnterFlag};
_S_to3val  S_to3val_543_1 = {&var149,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A2UP03RDU,&fEM_A2UP03RDU,&iEM_TERB2SP01RIM,&var91,&vainSFloat,&var92,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_421_1 = {&var94,&fEM_A2UC03RDU,&fRM_0_,&iRM_0_,&var93,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m421_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_415_1 = {&var220,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB2SC01RIM,&var94,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_412_1 = {&var307,&iEM_TERB2SS12LIM,&var95,&vainSBool,&internal1_m412_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_414_1 = {&var302,&iEM_TERB2SS11LIM,&var96,&vainSBool,&internal1_m414_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_413_1 = {&var303,&iEM_TERB2SS21LIM,&var97,&vainSBool,&internal1_m413_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_869_1 = {&var197,&iEM_TERB9SS21LIM,&var98,&vainSBool,&internal1_m869_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_870_1 = {&var196,&iEM_TERB9SS11LIM,&var99,&vainSBool,&internal1_m870_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_868_1 = {&var194,&iEM_TERA9SS21LIM,&var100,&vainSBool,&internal1_m868_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_1053_1 = {&var193,&iEM_TERA9SS11LIM,&var101,&vainSBool,&internal1_m1053_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_706_1 = {&var244,&iEM_TERB5SS21LIM,&var102,&vainSBool,&internal1_m706_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_707_1 = {&var243,&iEM_TERB5SS11LIM,&var103,&vainSBool,&internal1_m707_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_704_1 = {&var248,&iEM_TERA5SS21LIM,&var104,&vainSBool,&internal1_m704_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_705_1 = {&var247,&iEM_TERA5SS11LIM,&var105,&vainSBool,&internal1_m705_Out10,&bFirstEnterFlag};
_S_ampl  S_ampl_657_1 = {&var226,&fEM_R7UI75RIM,&var106};
_S_to3val  S_to3val_658_1 = {&var106,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R7UI74RIM,&fEM_R7UI74RIM,&iEM_TERR7SI74RIM,&vainSFloat,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_562_1 = {&var35,&iEM_TERB0VP81LIM,&var107,&vainSBool,&internal1_m562_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_561_1 = {&var35,&iEM_TERA0VP81LIM,&var108,&vainSBool,&internal1_m561_Out10,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_850_1 = {&var110,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var109,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m850_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_842_1 = {&var270,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERB8SC01RIM,&var110,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_ktoenc  S_ktoenc_852_1 = {&var112,&fEM_A8UC03RDU,&fRM_0_,&iRM_0_,&var111,&vainSBool,&vainSBool,&vainSBool,&vainSLong,&internal1_m852_Xtek0,&bFirstEnterFlag};
_S_to3val  S_to3val_844_1 = {&var267,&fRM_0_001,&fRM_0_0015,&fRM_0_0015,&fRM_0_,&fRM_200_,&fRM_200_,&iEM_TERA8SC01RIM,&var112,&vainSFloat,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_703_1 = {&R0MW13LP2,&iEM_TERR6IS68LIM,&var113,&vainSBool,&internal1_m703_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_687_1 = {&R0MW13LP2,&iEM_TERR6IS67LIM,&var114,&vainSBool,&internal1_m687_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_667_1 = {&R0MW13LP2,&iEM_TERR6IS66LIM,&var115,&vainSBool,&internal1_m667_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_686_1 = {&R0MW13LP2,&iEM_TERR6IS64LIM,&var116,&var117,&internal1_m686_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_666_1 = {&R0MW13LP2,&iEM_TERR6IS62LIM,&var118,&var119,&internal1_m666_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_339_1 = {&var288,&iEM_TERB3SS22LIM,&var120,&vainSBool,&internal1_m339_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_338_1 = {&var295,&iEM_TERA3SS22LIM,&var121,&vainSBool,&internal1_m338_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_323_1 = {&var289,&iEM_TERB3SS11LIM,&var122,&vainSBool,&internal1_m323_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_322_1 = {&var296,&iEM_TERA3SS11LIM,&var123,&vainSBool,&internal1_m322_Out10,&bFirstEnterFlag};
_S_toao  S_toao_524_1 = {&var125,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var124,&bFirstEnterFlag};
_S_to3val  S_to3val_517_1 = {&var171,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_A3UP03RDU,&fEM_A3UP03RDU,&iEM_TERA3SP02RIM,&vainSFloat,&var125,&vainSFloat,&bFirstEnterFlag};
_S_twobool  S_twobool_563_1 = {&var34,&iEM_TERA3VP81LIM,&var126,&var127,&internal1_m563_Out10,&bFirstEnterFlag};
_S_toao  S_toao_528_1 = {&var129,&fEM_A3UP04RDU,&fEM_A3UP03RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var128,&bFirstEnterFlag};
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
_S_twobool  S_twobool_1052_1 = {&var181,&iEM_TERR6SS21LIM,&var159,&vainSBool,&internal1_m1052_Out10,&bFirstEnterFlag};
_S_twobool  S_twobool_150_1 = {&var283,&iEM_TERB7MS31LIM,&var160,&vainSBool,&internal1_m150_Out10,&bFirstEnterFlag};
_S_toao  S_toao_164_1 = {&var162,&fEM_R0UT01RDU,&fEM_R0UT02RDU,&fRM_3276_,&fRM_16383_,&iRM_0_,&iRM_719_,&iRM_4195_,&fRM_1_,&var161,&bFirstEnterFlag};
_S_to3val  S_to3val_158_1 = {&var333,&fRM_2_0,&fRM_3_,&fRM_3_,&fRM_0_,&fEM_R0UT02RDU,&fEM_R0UT02RDU,&iEM_TERA0MT01RIM,&var162,&var163,&var164,&bFirstEnterFlag};
_S_twobool  S_twobool_149_1 = {&var334,&iEM_TERA7MS31LIM,&var165,&vainSBool,&internal1_m149_Out10,&bFirstEnterFlag};
_S_orn  S_orn_922_1 = {array_m922_x_1,&iRM_2_,&var166};
_S_andn  S_andn_917_1 = {array_m917_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_921_1 = {&var166,&var167};
_S_noto  S_noto_515_1 = {&B3AD34LDU,&var168};
_S_lk  S_lk_519_1 = {&fEM_A3UP02RDU,&var168,&var169};
_S_noto  S_noto_513_1 = {&A3AD34LDU,&var170};
_S_lk  S_lk_518_1 = {&fEM_A3UP02RDU,&var170,&var171};
_S_ovb1  S_ovb1_197_1 = {&R8AD21LDU,&iRM_500_,&var172,&internal1_m197_tx};
_S_ovb1  S_ovb1_25_1 = {&R8AD21LDU,&iRM_500_,&var173,&internal1_m25_tx};
_S_andn  S_andn_942_1 = {array_m942_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_947_1 = {&var38,&var174};
_S_andn  S_andn_935_1 = {array_m935_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_938_1 = {&var39,&var175};
_S_andn  S_andn_927_1 = {array_m927_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_931_1 = {&var40,&var176};
_S_orn  S_orn_634_1 = {array_m634_x_1,&iRM_2_,&var177};
_S_orn  S_orn_631_1 = {array_m631_x_1,&iRM_2_,&var178};
_S_react  S_react_200_1 = {&var284,&var179};
_S_noto  S_noto_476_1 = {&lEM_R6AD10LC1,&var180};
_S_asmot  S_asmot_480_1 = {&var180,&lEM_R6AD10LC1,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R6UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R6UC01RSP,&fEM_R6UV01RSP,&vainSFloat,&var181,&vainSBool,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m480_Pav0,&internal1_m480_Zav0,&internal1_m480_Pv0,&internal1_m480_Zv0,&internal1_m480_RA00,&internal1_m480_RA10,&internal1_m480_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_492_1 = {&var27,&var28,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R5UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R5UC01RSP,&fEM_R5UV01RSP,&vainSFloat,&var182,&var183,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m492_Pav0,&internal1_m492_Zav0,&internal1_m492_Pv0,&internal1_m492_Zv0,&internal1_m492_RA00,&internal1_m492_RA10,&internal1_m492_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_479_1 = {&var29,&var30,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_R3UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_R3UC01RSP,&fEM_R3UV01RSP,&vainSFloat,&var184,&var185,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m479_Pav0,&internal1_m479_Zav0,&internal1_m479_Pv0,&internal1_m479_Zv0,&internal1_m479_RA00,&internal1_m479_RA10,&internal1_m479_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_617_1 = {&A4AD10LDU,&var186};
_S_asmot  S_asmot_621_1 = {&var186,&A4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A4MC01RSP,&fEM_A4MV01RSP,&vainSFloat,&var187,&var188,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m621_Pav0,&internal1_m621_Zav0,&internal1_m621_Pv0,&internal1_m621_Zv0,&internal1_m621_RA00,&internal1_m621_RA10,&internal1_m621_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_615_1 = {&B4AD10LDU,&var189};
_S_asmot  S_asmot_620_1 = {&var189,&B4AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A4UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B4MC01RSP,&fEM_B4MV01RSP,&vainSFloat,&var190,&var191,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m620_Pav0,&internal1_m620_Zav0,&internal1_m620_Pv0,&internal1_m620_Zv0,&internal1_m620_RA00,&internal1_m620_RA10,&internal1_m620_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_604_1 = {&A9AD10LDU,&var192};
_S_asmot  S_asmot_606_1 = {&var192,&A9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_20_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_A9MC01RSP,&fEM_A9MV01RSP,&vainSFloat,&var193,&var194,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m606_Pav0,&internal1_m606_Zav0,&internal1_m606_Pv0,&internal1_m606_Zv0,&internal1_m606_RA00,&internal1_m606_RA10,&internal1_m606_MyFirstEnterFlag,&bFirstEnterFlag};
_S_noto  S_noto_603_1 = {&B9AD10LDU,&var195};
_S_asmot  S_asmot_605_1 = {&var195,&B9AD10LDU,&fRM_0_,&fRM_0_,&fRM_1_0,&fRM_0_,&iRM_0_,&fEM_A9UL10RIM,&fRM_0_,&fRM_100000_,&fRM_n100_,&fRM_0_5,&fEM_B9MC01RSP,&fEM_B9MV01RSP,&vainSFloat,&var196,&var197,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m605_Pav0,&internal1_m605_Zav0,&internal1_m605_Pv0,&internal1_m605_Zv0,&internal1_m605_RA00,&internal1_m605_RA10,&internal1_m605_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orn  S_orn_641_1 = {array_m641_x_1,&iRM_3_,&var198};
_S_andn  S_andn_919_1 = {array_m919_x_1,&iRM_2_,&vainSBool};
_S_noto  S_noto_924_1 = {&var41,&var199};
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
_S_vchs  S_vchs_815_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX12RSS,&fEM_R7UY12RSS,&bRM_5_,&fEM_A0UX12RSS,&fEM_B0UX12RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var230,&internal1_m815_Chim0};
_S_vchs  S_vchs_806_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX11RSS,&fEM_R7UY11RSS,&bRM_4_,&fEM_A0UX11RSS,&fEM_B0UX11RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var231,&internal1_m806_Chim0};
_S_vchs  S_vchs_798_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX10RSS,&fEM_R7UY10RSS,&bRM_1_,&fEM_A0UX10RSS,&fEM_B0UX10RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var232,&internal1_m798_Chim0};
_S_vchs  S_vchs_789_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX09RSS,&fEM_R7UY09RSS,&bRM_5_,&fEM_A0UX09RSS,&fEM_B0UX09RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var233,&internal1_m789_Chim0};
_S_vchs  S_vchs_780_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX08RSS,&fEM_R7UY08RSS,&bRM_4_,&fEM_A0UX08RSS,&fEM_B0UX08RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var234,&internal1_m780_Chim0};
_S_vchs  S_vchs_772_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX07RSS,&fEM_R7UY07RSS,&bRM_1_,&fEM_A0UX07RSS,&fEM_B0UX07RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var235,&internal1_m772_Chim0};
_S_vchs  S_vchs_763_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX06RSS,&fEM_R7UY06RSS,&bRM_5_,&fEM_A0UX06RSS,&fEM_B0UX06RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var236,&internal1_m763_Chim0};
_S_vchs  S_vchs_754_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX05RSS,&fEM_R7UY05RSS,&bRM_4_,&fEM_A0UX05RSS,&fEM_B0UX05RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var237,&internal1_m754_Chim0};
_S_vchs  S_vchs_746_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX04RSS,&fEM_R7UY04RSS,&bRM_2_,&fEM_A0UX04RSS,&fEM_B0UX04RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var238,&internal1_m746_Chim0};
_S_vchs  S_vchs_737_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UC10RIM,&fEM_R7UC19RIM,&bRM_5_,&fEM_A0UX03RSS,&fEM_B0UX03RSS,&fEM_R0UH03RSS,&fEM_R0UH23RSS,&fRM_0_,&fEM_A0UX00RSS,&var239,&internal1_m737_Chim0};
_S_vchs  S_vchs_728_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX02RSS,&fEM_R7UY02RSS,&bRM_4_,&fEM_A0UX02RSS,&fEM_B0UX02RSS,&fEM_R0UH02RSS,&fEM_R0UH22RSS,&fRM_0_,&fEM_A0UX00RSS,&var240,&internal1_m728_Chim0};
_S_fsumo  S_fsumo_913_1 = {&fEM_R4UC10RIM,&fEM_R4UC22RIM,&var241};
_S_vchs  S_vchs_719_1 = {&var331,&var280,&var241,&fEM_R7UY00RSS,&fEM_R7UY00RSS,&fEM_R7UX01RSS,&fEM_R7UY01RSS,&bRM_2_,&fEM_A0UX01RSS,&fEM_B0UX01RSS,&fEM_R0UH01RSS,&fEM_R0UH21RSS,&fRM_0_,&fEM_A0UX00RSS,&var242,&internal1_m719_Chim0};
_S_asmot  S_asmot_592_1 = {&B5AD10LDU,&B5AD20LDU,&fEM_B5MC01RC1,&fEM_B5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL2,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_B5MC01RSP,&fEM_B5MV01RSP,&vainSFloat,&var243,&var244,&vainSBool,&vainSBool,&vainSFloat,&var245,&var246,&internal1_m592_Pav0,&internal1_m592_Zav0,&internal1_m592_Pv0,&internal1_m592_Zv0,&internal1_m592_RA00,&internal1_m592_RA10,&internal1_m592_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_577_1 = {&A5AD10LDU,&A5AD20LDU,&fEM_A5MC01RC1,&fEM_A5MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERNL1,&fEM_A5UC10RIM,&fRM_0_0,&fRM_1500_0,&fRM_n50_,&fRM_0_10,&fEM_A5MC01RSP,&fEM_A5MV01RSP,&vainSFloat,&var247,&var248,&vainSBool,&vainSBool,&vainSFloat,&var249,&var250,&internal1_m577_Pav0,&internal1_m577_Zav0,&internal1_m577_Pv0,&internal1_m577_Zv0,&internal1_m577_RA00,&internal1_m577_RA10,&internal1_m577_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_463_1 = {&R2AD10LDU,&R2AD20LDU,&fEM_R2MC01RC1,&fEM_R2MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ2,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R2MC01RSP,&fEM_R2MV01RSP,&vainSFloat,&var251,&var252,&vainSBool,&vainSBool,&vainSFloat,&var253,&var254,&internal1_m463_Pav0,&internal1_m463_Zav0,&internal1_m463_Pv0,&internal1_m463_Zv0,&internal1_m463_RA00,&internal1_m463_RA10,&internal1_m463_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_448_1 = {&R1AD10LDU,&R1AD20LDU,&fEM_R1MC01RC1,&fEM_R1MV01RC1,&fRM_1_,&fRM_0_,&iEM_TERMDZ1,&fEM_R1UC10RIM,&fRM_0_0,&fRM_2000_0,&fRM_n150_,&fRM_0_50,&fEM_R1MC01RSP,&fEM_R1MV01RSP,&vainSFloat,&var255,&var256,&vainSBool,&vainSBool,&vainSFloat,&var257,&var258,&internal1_m448_Pav0,&internal1_m448_Zav0,&internal1_m448_Pv0,&internal1_m448_Zv0,&internal1_m448_RA00,&internal1_m448_RA10,&internal1_m448_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_504_1 = {&B6AD10LDU,&B6AD20LDU,&fEM_B6MC01RC1,&fEM_B6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ2,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_B6MC01RSP,&fEM_B6MV01RSP,&vainSFloat,&var259,&var260,&vainSBool,&vainSBool,&vainSFloat,&var261,&var262,&internal1_m504_Pav0,&internal1_m504_Zav0,&internal1_m504_Pv0,&internal1_m504_Zv0,&internal1_m504_RA00,&internal1_m504_RA10,&internal1_m504_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_399_1 = {&A6AD10LDU,&A6AD20LDU,&fEM_A6MC01RC1,&fEM_A6MV01RC1,&fRM_1_0,&fEM_A6US80RDU,&iEM_TERBZ1,&fEM_A6UC10RIM,&fRM_0_0,&fRM_180_0,&fRM_n50_,&fRM_0_10,&fEM_A6MC01RSP,&fEM_A6MV01RSP,&vainSFloat,&var263,&var264,&vainSBool,&vainSBool,&vainSFloat,&var265,&var266,&internal1_m399_Pav0,&internal1_m399_Zav0,&internal1_m399_Pv0,&internal1_m399_Zv0,&internal1_m399_RA00,&internal1_m399_RA10,&internal1_m399_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_383_1 = {&A8AD20LDU,&A8AD10LDU,&fEM_A8MC01RC1,&fEM_A8MV01RC1,&fEM_A8UV80RDU,&fEM_A8US80RDU,&iEM_TERDS2,&fEM_A8UC10RIM,&fEM_A8UC20RIM,&fEM_A8UC11RIM,&fEM_A8UC21RIM,&fEM_A8UC08RDU,&fEM_A8MC01RSP,&fEM_A8MV01RSP,&var267,&var268,&var269,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m383_Pav0,&internal1_m383_Zav0,&internal1_m383_Pv0,&internal1_m383_Zv0,&internal1_m383_RA00,&internal1_m383_RA10,&internal1_m383_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_366_1 = {&B8AD20LDU,&B8AD10LDU,&fEM_B8MC01RC1,&fEM_B8MV01RC1,&fEM_B8UV80RDU,&fEM_B8US80RDU,&iEM_TERMAZ2,&fEM_B8UC10RIM,&fEM_B8UC20RIM,&fEM_B8UC11RIM,&fEM_B8UC21RIM,&fEM_B8UC08RDU,&fEM_B8MC01RSP,&fEM_B8MV01RSP,&var270,&var271,&var272,&vainSBool,&vainSBool,&vainSFloat,&vainSBool,&vainSBool,&internal1_m366_Pav0,&internal1_m366_Zav0,&internal1_m366_Pv0,&internal1_m366_Zv0,&internal1_m366_RA00,&internal1_m366_RA10,&internal1_m366_MyFirstEnterFlag,&bFirstEnterFlag};
_S_asmot  S_asmot_908_1 = {&R4AD10LDU,&R4AD20LDU,&fEM_R4MC01RC1,&fEM_R4MV01RC1,&fEM_R4UV80RDU,&fEM_R4US80RDU,&iEM_TERTLG,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC10RIM,&fEM_R4UC20RIM,&fEM_R4UC08RDU,&fEM_R4MC01RSP,&fEM_R4MV01RSP,&vainSFloat,&var273,&var274,&var275,&var276,&vainSFloat,&var277,&var278,&internal1_m908_Pav0,&internal1_m908_Zav0,&internal1_m908_Pv0,&internal1_m908_Zv0,&internal1_m908_RA00,&internal1_m908_RA10,&internal1_m908_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_182_1 = {&var316,&var300,&var286,&var330,&fEM_R0UR30RIM,&B7AP31LDU,&var190,&lEM_R8AD10LC1,&var172,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var223,&var225,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_B0UT03RSP,&var279,&var280,&var281,&var282,&var283,&var284,&var285,&internal1_m182_C1,&internal1_m182_C2,&internal1_m182_C3,&internal1_m182_C4,&internal1_m182_C5,&internal1_m182_C6,&internal1_m182_N20,array_m182_C0_1,&internal1_m182_ImpINI0,&internal1_m182_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_300_1 = {&B3AD11LDU,&B3AD21LDU,&B3AD02LDU,&B3AD01LDU,&B3AD03LDU,&B3AD04LDU,&B3AD05LDU,&var200,&B3AD33LDU,&lRM_1_,&fEM_B3MC01RC1,&fEM_B3MC02RC1,&fEM_B3MV01RC1,&fEM_B3MV02RC1,&lRM_0_,array_m300_Vr_1,&fEM_A3UC02RDU,&var169,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS2,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_B3MC01RSP,&fEM_B3MC02RSP,&fEM_B3MV01RSP,&fEM_B3MV02RSP,&var286,&var287,&var288,&var289,&var290,&vainSFloat,&vainSFloat,&var291,&var292,&vainSBool,&vainSBool,&internal1_m300_Ppv0,&internal1_m300_Pav0,&internal1_m300_Zav0,&internal1_m300_RA00,&internal1_m300_RA10,&internal1_m300_RA50,&internal1_m300_fls,&internal1_m300_flp,&internal1_m300_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_130_1 = {&A3AD11LDU,&A3AD21LDU,&A3AD02LDU,&A3AD01LDU,&A3AD03LDU,&A3AD04LDU,&A3AD05LDU,&var208,&A3AD33LDU,&lRM_1_,&fEM_A3MC01RC1,&fEM_A3MC02RC1,&fEM_A3MV01RC1,&fEM_A3MV02RC1,&lRM_0_,array_m130_Vr_1,&fEM_A3UC02RDU,&var171,&fEM_A3UP01RIM,&fEM_A3UG01RDU,&fEM_A3US07RDU,&fEM_A3UV02RIM,&iEM_TERIS1,&fEM_A3UC04RIM,&fEM_A3UC05RIM,&fEM_A3UC06RIM,&fEM_A3UC08RIM,&fEM_A3MC01RSP,&fEM_A3MC02RSP,&fEM_A3MV01RSP,&fEM_A3MV02RSP,&var293,&var294,&var295,&var296,&var297,&vainSFloat,&vainSFloat,&var298,&var299,&vainSBool,&vainSBool,&internal1_m130_Ppv0,&internal1_m130_Pav0,&internal1_m130_Zav0,&internal1_m130_RA00,&internal1_m130_RA10,&internal1_m130_RA50,&internal1_m130_fls,&internal1_m130_flp,&internal1_m130_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_267_1 = {&B2AD11LDU,&B2AD21LDU,&B2AD02LDU,&B2AD01LDU,&B2AD03LDU,&B2AD04LDU,&B2AD05LDU,&var201,&B2AD33LDU,&var203,&fEM_B2MC01RC1,&fEM_B2MC02RC1,&fEM_B2MV01RC1,&fEM_B2MV02RC1,&lRM_1_,array_m267_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB2,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_B2MC01RSP,&fEM_B2MC02RSP,&fEM_B2MV01RSP,&fEM_B2MV02RSP,&var300,&var301,&vainSBool,&var302,&var303,&vainSFloat,&vainSFloat,&var304,&var305,&var306,&var307,&internal1_m267_Ppv0,&internal1_m267_Pav0,&internal1_m267_Zav0,&internal1_m267_RA00,&internal1_m267_RA10,&internal1_m267_RA50,&internal1_m267_fls,&internal1_m267_flp,&internal1_m267_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_96_1 = {&A2AD11LDU,&A2AD21LDU,&A2AD02LDU,&A2AD01LDU,&A2AD03LDU,&A2AD04LDU,&A2AD05LDU,&var213,&A2AD33LDU,&var215,&fEM_A2MC01RC1,&fEM_A2MC02RC1,&fEM_A2MV01RC1,&fEM_A2MV02RC1,&lRM_1_,array_m96_Vr_1,&fEM_A2UC02RDU,&fEM_A2UP02RIM,&fEM_A2UP01RIM,&fEM_A2UG01RDU,&fEM_A2US07RDU,&fEM_A2UV02RIM,&iEM_TERRB1,&fEM_A2UC04RIM,&fEM_A2UC05RIM,&fEM_A2UC06RIM,&fEM_A2UC08RIM,&fEM_A2MC01RSP,&fEM_A2MC02RSP,&fEM_A2MV01RSP,&fEM_A2MV02RSP,&var308,&var309,&vainSBool,&var310,&var311,&vainSFloat,&vainSFloat,&var312,&var313,&var314,&var315,&internal1_m96_Ppv0,&internal1_m96_Pav0,&internal1_m96_Zav0,&internal1_m96_RA00,&internal1_m96_RA10,&internal1_m96_RA50,&internal1_m96_fls,&internal1_m96_flp,&internal1_m96_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_229_1 = {&B1AD11LDU,&B1AD21LDU,&B1AD02LDU,&B1AD01LDU,&B1AD03LDU,&B1AD04LDU,&B1AD05LDU,&var207,&lRM_1_,&var206,&fEM_B1MC01RC1,&fEM_B1MC02RC1,&fEM_B1MV01RC1,&fEM_B1MV02RC1,&lRM_1_,array_m229_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB2,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_B1MC01RSP,&fEM_B1MC02RSP,&fEM_B1MV01RSP,&fEM_B1MV02RSP,&var316,&var317,&vainSBool,&var318,&var319,&vainSFloat,&vainSFloat,&var320,&vainSBool,&var321,&var322,&internal1_m229_Ppv0,&internal1_m229_Pav0,&internal1_m229_Zav0,&internal1_m229_RA00,&internal1_m229_RA10,&internal1_m229_RA50,&internal1_m229_fls,&internal1_m229_flp,&internal1_m229_MyFirstEnterFlag,&bFirstEnterFlag};
_S_orrsim  S_orrsim_60_1 = {&A1AD11LDU,&A1AD21LDU,&A1AD02LDU,&A1AD01LDU,&A1AD03LDU,&A1AD04LDU,&A1AD05LDU,&var212,&lRM_1_,&var211,&fEM_A1MC01RC1,&fEM_A1MC02RC1,&fEM_A1MV01RC1,&fEM_A1MV02RC1,&lRM_1_,array_m60_Vr_1,&fEM_A1UC02RDU,&fRM_0_,&fEM_A1UP01RIM,&fEM_A1UG01RDU,&fEM_A1US07RDU,&fEM_A1UV02RIM,&iEM_TERBB1,&fEM_A1UC04RIM,&fEM_A1UC05RIM,&fEM_A1UC06RIM,&fEM_A1UC08RIM,&fEM_A1MC01RSP,&fEM_A1MC02RSP,&fEM_A1MV01RSP,&fEM_A1MV02RSP,&var323,&var324,&var325,&var326,&var327,&vainSFloat,&vainSFloat,&vainSBool,&vainSBool,&var328,&var329,&internal1_m60_Ppv0,&internal1_m60_Pav0,&internal1_m60_Zav0,&internal1_m60_RA00,&internal1_m60_RA10,&internal1_m60_RA50,&internal1_m60_fls,&internal1_m60_flp,&internal1_m60_MyFirstEnterFlag,&bFirstEnterFlag};
_S_azbars  S_azbars_14_1 = {&var323,&var308,&var293,&var279,&fEM_R0UR30RIM,&A7AP31LDU,&var187,&lEM_R8AD10LC1,&var173,&fEM_R0UL01RIM,&fEM_R0UN02RIM,&fEM_R0UT01RIM,&fEM_R0UT02RIM,&fEM_R0UT04RIM,&fEM_R0UT05RIM,&fEM_R0UH05RSS,&fEM_A0UN02RIM,&fEM_A0UN01RIM,&fEM_A1UR00RIM,&fEM_A1UR01RIM,&fEM_A2UR00RIM,&fEM_A2UR01RIM,&fEM_A3UR00RIM,&fEM_A3UR01RIM,&var223,&var225,&fEM_R0UT03RIM,&fEM_R0UT06RIM,&fEM_A0UR02RSP,&fEM_A0UR01RSP,&fEM_A0UT03RSP,&var330,&var331,&var332,&var333,&var334,&var335,&vainSFloat,&internal1_m14_C1,&internal1_m14_C2,&internal1_m14_C3,&internal1_m14_C4,&internal1_m14_C5,&internal1_m14_C6,&internal1_m14_N20,array_m14_C0_1,&internal1_m14_ImpINI0,&internal1_m14_MyFirstEnterFlag,&bFirstEnterFlag};


int freebuff = 0;
void Scheme()
{
if ((getAsShort(idR0MW11IP1) == 2) || (getAsShort(idR0MW11IP1) == 3)) { 
     freebuff = 0;
if(getAsBool(idbFirstEnterFlag)==0) InitInternalParametr();
  noto(&S_noto_86_1);
  noto(&S_noto_256_1);
  noto(&S_noto_603_1);
  noto(&S_noto_604_1);
  ovb1(&S_ovb1_25_1);
  ovb1(&S_ovb1_197_1);
  noto(&S_noto_515_1);
  bol(&S_bol_945_1);
  bol(&S_bol_955_1);
  bol(&S_bol_933_1);
  bol(&S_bol_954_1);
  bol(&S_bol_957_1);
  zpfs(&S_zpfs_632_1);
  zpfs(&S_zpfs_644_1);
  noto(&S_noto_481_1);
  noto(&S_noto_478_1);
  noto(&S_noto_491_1);
  noto(&S_noto_490_1);
  to3val(&S_to3val_971_1);
  asmot(&S_asmot_908_1);
  asmot(&S_asmot_366_1);
  asmot(&S_asmot_383_1);
  asmot(&S_asmot_399_1);
  asmot(&S_asmot_504_1);
  asmot(&S_asmot_448_1);
  asmot(&S_asmot_463_1);
  asmot(&S_asmot_577_1);
  asmot(&S_asmot_592_1);
  fsumo(&S_fsumo_913_1);
  inf(&S_inf_9_1);
  inf(&S_inf_7_1);
  fsubo(&S_fsubo_8_1);
  fsubo(&S_fsubo_373_1);
  noto(&S_noto_45_1);
  noto(&S_noto_46_1);
  noto(&S_noto_215_1);
  noto(&S_noto_216_1);
  orn(&S_orn_641_1);
  asmot(&S_asmot_605_1);
  asmot(&S_asmot_606_1);
  noto(&S_noto_615_1);
  noto(&S_noto_617_1);
  noto(&S_noto_476_1);
  noto(&S_noto_513_1);
  lk(&S_lk_519_1);
  orn(&S_orn_922_1);
  to3val(&S_to3val_542_1);
  toao(&S_toao_547_1);
  toao(&S_toao_548_1);
  to3val(&S_to3val_520_1);
  toao(&S_toao_528_1);
  twobool(&S_twobool_563_1);
  twobool(&S_twobool_666_1);
  twobool(&S_twobool_686_1);
  twobool(&S_twobool_667_1);
  twobool(&S_twobool_687_1);
  twobool(&S_twobool_703_1);
  to3val(&S_to3val_844_1);
  ktoenc(&S_ktoenc_852_1);
  to3val(&S_to3val_842_1);
  ktoenc(&S_ktoenc_850_1);
  twobool(&S_twobool_561_1);
  twobool(&S_twobool_562_1);
  twobool(&S_twobool_705_1);
  twobool(&S_twobool_704_1);
  twobool(&S_twobool_707_1);
  twobool(&S_twobool_706_1);
  twobool(&S_twobool_1053_1);
  twobool(&S_twobool_868_1);
  twobool(&S_twobool_870_1);
  twobool(&S_twobool_869_1);
  to3val(&S_to3val_543_1);
  toao(&S_toao_549_1);
  toao(&S_toao_550_1);
  twobool(&S_twobool_546_1);
  twobool(&S_twobool_997_1);
  twobool(&S_twobool_1012_1);
  twobool(&S_twobool_1029_1);
  twobool(&S_twobool_1051_1);
  twobool(&S_twobool_831_1);
  twobool(&S_twobool_998_1);
  twobool(&S_twobool_999_1);
  twobool(&S_twobool_1000_1);
  twobool(&S_twobool_1001_1);
  twobool(&S_twobool_1049_1);
  twobool(&S_twobool_827_1);
  twobool(&S_twobool_828_1);
  twobool(&S_twobool_830_1);
  twobool(&S_twobool_829_1);
  twobool(&S_twobool_855_1);
  twobool(&S_twobool_853_1);
  twobool(&S_twobool_856_1);
  twobool(&S_twobool_854_1);
  twobool(&S_twobool_1033_1);
  twobool(&S_twobool_1034_1);
  twobool(&S_twobool_1035_1);
  twobool(&S_twobool_1054_1);
  twobool(&S_twobool_56_1);
  twobool(&S_twobool_41_1);
  twobool(&S_twobool_226_1);
  twobool(&S_twobool_208_1);
  zpfs(&S_zpfs_616_1);
  zpfs(&S_zpfs_618_1);
  or2(&S_or2_923_1);
  or2(&S_or2_930_1);
  or2(&S_or2_937_1);
  or2(&S_or2_946_1);
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
  twobool(&S_twobool_1013_1);
  twobool(&S_twobool_1014_1);
  twobool(&S_twobool_1015_1);
  twobool(&S_twobool_1016_1);
  twobool(&S_twobool_832_1);
  twobool(&S_twobool_833_1);
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
  noto(&S_noto_924_1);
  andn(&S_andn_919_1);
  asmot(&S_asmot_620_1);
  asmot(&S_asmot_621_1);
  asmot(&S_asmot_479_1);
  asmot(&S_asmot_492_1);
  asmot(&S_asmot_480_1);
  noto(&S_noto_931_1);
  andn(&S_andn_927_1);
  noto(&S_noto_938_1);
  andn(&S_andn_935_1);
  noto(&S_noto_947_1);
  andn(&S_andn_942_1);
  lk(&S_lk_518_1);
  noto(&S_noto_921_1);
  andn(&S_andn_917_1);
  twobool(&S_twobool_1052_1);
  to3val(&S_to3val_517_1);
  toao(&S_toao_524_1);
  twobool(&S_twobool_1030_1);
  twobool(&S_twobool_1032_1);
  twobool(&S_twobool_1031_1);
  twobool(&S_twobool_1050_1);
  orrsim(&S_orrsim_60_1);
  orrsim(&S_orrsim_229_1);
  orrsim(&S_orrsim_96_1);
  orrsim(&S_orrsim_267_1);
  orrsim(&S_orrsim_130_1);
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
  twobool(&S_twobool_966_1);
  twobool(&S_twobool_967_1);
  twobool(&S_twobool_970_1);
  to3val(&S_to3val_962_1);
  ktoenc(&S_ktoenc_969_1);
  to3val(&S_to3val_981_1);
  ktoenc(&S_ktoenc_986_1);
  twobool(&S_twobool_983_1);
  twobool(&S_twobool_984_1);
  twobool(&S_twobool_987_1);
  andn(&S_andn_357_1);
  twobool(&S_twobool_411_1);
  azbars(&S_azbars_14_1);
  vchs(&S_vchs_719_1);
  vchs(&S_vchs_728_1);
  vchs(&S_vchs_737_1);
  vchs(&S_vchs_746_1);
  vchs(&S_vchs_754_1);
  vchs(&S_vchs_763_1);
  vchs(&S_vchs_772_1);
  vchs(&S_vchs_780_1);
  vchs(&S_vchs_789_1);
  vchs(&S_vchs_798_1);
  vchs(&S_vchs_806_1);
  vchs(&S_vchs_815_1);
  twobool(&S_twobool_149_1);
  to3val(&S_to3val_158_1);
  toao(&S_toao_164_1);
  toao(&S_toao_165_1);
  toao(&S_toao_166_1);
  to3val(&S_to3val_658_1);
  vchs(&S_vchs_878_1);
  vchs(&S_vchs_886_1);
  vchs(&S_vchs_896_1);
  setData(idR0IS01FI0,&iRM_1_);
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
 else {
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
  for( i=0;i<6;i++ )
    array_m182_C0_1[i] = &(&internal1_m182_C0)[i*5];
  for( i=0;i<6;i++ )
    array_m14_C0_1[i] = &(&internal1_m14_C0)[i*5];
}

#endif
