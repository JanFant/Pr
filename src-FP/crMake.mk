DIR_PROGR = AKNP1 AKNP2 AKNP3 AKNP4 Baz1 Baz2 RPU DU
cpc108 = /root/cpc108/include
make_o_key = -m32 -c -g -I$(cpc108) `pkg-config --cflags libmodbus` `pkg-config --cflags libfp8` `pkg-config --cflags libteprLib` -std=c99  -MMD -MP -MF
ProgPATH = /root/all_prog
lib_key = -lpthread `pkg-config --libs libmodbus` `pkg-config --libs libfp8` `pkg-config --libs libteprLib`

change: delmake Createmake

Createmake:
#AKNP1
	@echo "ProgPATH = /root/all_prog" >> $(ProgPATH)/AKNP1/Makefile 
	@echo "make_o_key = -m32 -c -g -I$(cpc108) `pkg-config --cflags libmodbus` `pkg-config --cflags libfp8` `pkg-config --cflags libteprLib` -std=c99  -MMD -MP -MF" >> $(ProgPATH)/AKNP1/Makefile
	@echo "lib_key = -lpthread `pkg-config --libs libmodbus` `pkg-config --libs libfp8` `pkg-config --libs libteprLib`" >> $(ProgPATH)/AKNP1/Makefile
	@echo "" >> $(ProgPATH)/AKNP1/Makefile
	@echo "all: clean Create" >> $(ProgPATH)/AKNP1/Makefile
	@echo "Create:" >> $(ProgPATH)/AKNP1/Makefile
	@echo "	gcc $(make_o_key) "$(ProgPATH)/AKNP1/mainfpAKNP.o.d" -o $(ProgPATH)/AKNP1/mainfpAKNP.o $(ProgPATH)/AKNP1/mainfpAKNP.c" >> $(ProgPATH)/AKNP1/Makefile
	@echo "	gcc -m32 -o /root/all_prog/result/AKNP1 $(ProgPATH)/AKNP1/mainfpAKNP.o $(lib_key)" >> $(ProgPATH)/AKNP1/Makefile
	@echo "" >> $(ProgPATH)/AKNP1/Makefile
	@echo "clean:" >> $(ProgPATH)/AKNP1/Makefile
	@echo "	@rm -f *.o*" >> $(ProgPATH)/AKNP1/Makefile
#AKNP2
	@echo "ProgPATH = /root/all_prog" >> $(ProgPATH)/AKNP2/Makefile 
	@echo "make_o_key = -m32 -c -g -I$(cpc108) `pkg-config --cflags libmodbus` `pkg-config --cflags libfp8` `pkg-config --cflags libteprLib` -std=c99  -MMD -MP -MF" >> $(ProgPATH)/AKNP2/Makefile
	@echo "lib_key = -lpthread `pkg-config --libs libmodbus` `pkg-config --libs libfp8` `pkg-config --libs libteprLib`" >> $(ProgPATH)/AKNP2/Makefile
	@echo "" >> $(ProgPATH)/AKNP2/Makefile
	@echo "all: clean Create" >> $(ProgPATH)/AKNP2/Makefile
	@echo "Create:" >> $(ProgPATH)/AKNP2/Makefile
	@echo "	gcc $(make_o_key) "$(ProgPATH)/AKNP2/mainfpAKNP.o.d" -o $(ProgPATH)/AKNP2/mainfpAKNP.o $(ProgPATH)/AKNP2/mainfpAKNP.c" >> $(ProgPATH)/AKNP2/Makefile
	@echo "	gcc -m32 -o /root/all_prog/result/AKNP2 $(ProgPATH)/AKNP2/mainfpAKNP.o $(lib_key)" >> $(ProgPATH)/AKNP2/Makefile
	@echo "" >> $(ProgPATH)/AKNP2/Makefile
	@echo "clean:" >> $(ProgPATH)/AKNP2/Makefile
	@echo "	@rm -f *.o*" >> $(ProgPATH)/AKNP2/Makefile
#AKNP3
	@echo "ProgPATH = /root/all_prog" >> $(ProgPATH)/AKNP3/Makefile 
	@echo "make_o_key = -m32 -c -g -I$(cpc108) `pkg-config --cflags libmodbus` `pkg-config --cflags libfp8` `pkg-config --cflags libteprLib` -std=c99  -MMD -MP -MF" >> $(ProgPATH)/AKNP3/Makefile
	@echo "lib_key = -lpthread `pkg-config --libs libmodbus` `pkg-config --libs libfp8` `pkg-config --libs libteprLib`" >> $(ProgPATH)/AKNP3/Makefile
	@echo "" >> $(ProgPATH)/AKNP3/Makefile
	@echo "all: clean Create" >> $(ProgPATH)/AKNP3/Makefile
	@echo "Create:" >> $(ProgPATH)/AKNP3/Makefile
	@echo "	gcc $(make_o_key) "$(ProgPATH)/AKNP3/mainfpAKNP.o.d" -o $(ProgPATH)/AKNP3/mainfpAKNP.o $(ProgPATH)/AKNP3/mainfpAKNP.c" >> $(ProgPATH)/AKNP3/Makefile
	@echo "	gcc -m32 -o /root/all_prog/result/AKNP3 $(ProgPATH)/AKNP3/mainfpAKNP.o $(lib_key)" >> $(ProgPATH)/AKNP3/Makefile
	@echo "" >> $(ProgPATH)/AKNP3/Makefile
	@echo "clean:" >> $(ProgPATH)/AKNP3/Makefile
	@echo "	@rm -f *.o*" >> $(ProgPATH)/AKNP3/Makefile
#AKNP4
	@echo "ProgPATH = /root/all_prog" >> $(ProgPATH)/AKNP4/Makefile 
	@echo "make_o_key = -m32 -c -g -I$(cpc108) `pkg-config --cflags libmodbus` `pkg-config --cflags libfp8` `pkg-config --cflags libteprLib` -std=c99  -MMD -MP -MF" >> $(ProgPATH)/AKNP4/Makefile
	@echo "lib_key = -lpthread `pkg-config --libs libmodbus` `pkg-config --libs libfp8` `pkg-config --libs libteprLib`" >> $(ProgPATH)/AKNP4/Makefile
	@echo "" >> $(ProgPATH)/AKNP4/Makefile
	@echo "all: clean Create" >> $(ProgPATH)/AKNP4/Makefile
	@echo "Create:" >> $(ProgPATH)/AKNP4/Makefile
	@echo "	gcc $(make_o_key) "$(ProgPATH)/AKNP4/mainfpAKNP.o.d" -o $(ProgPATH)/AKNP4/mainfpAKNP.o $(ProgPATH)/AKNP4/mainfpAKNP.c" >> $(ProgPATH)/AKNP4/Makefile
	@echo "	gcc -m32 -o /root/all_prog/result/AKNP4 $(ProgPATH)/AKNP4/mainfpAKNP.o $(lib_key)" >> $(ProgPATH)/AKNP4/Makefile
	@echo "" >> $(ProgPATH)/AKNP4/Makefile
	@echo "clean:" >> $(ProgPATH)/AKNP4/Makefile
	@echo "	@rm -f *.o*" >> $(ProgPATH)/AKNP4/Makefile
#Baz1
	@echo "ProgPATH = /root/all_prog" >> $(ProgPATH)/Baz1/Makefile 
	@echo "make_o_key = -m32 -c -g -I$(cpc108) `pkg-config --cflags libmodbus` `pkg-config --cflags libfp8` `pkg-config --cflags libteprLib` -std=c99  -MMD -MP -MF" >> $(ProgPATH)/Baz1/Makefile
	@echo "lib_key = -lpthread `pkg-config --libs libmodbus` `pkg-config --libs libfp8` `pkg-config --libs libteprLib`" >> $(ProgPATH)/Baz1/Makefile
	@echo "" >> $(ProgPATH)/Baz1/Makefile
	@echo "all: clean Create" >> $(ProgPATH)/Baz1/Makefile
	@echo "Create:" >> $(ProgPATH)/Baz1/Makefile
	@echo "	gcc $(make_o_key) "$(ProgPATH)/Baz1/mainfp.o.d" -o $(ProgPATH)/Baz1/mainfp.o $(ProgPATH)/Baz1/mainfp.c" >> $(ProgPATH)/Baz1/Makefile
	@echo "	gcc -m32 -o /root/all_prog/result/Baz1 $(ProgPATH)/Baz1/mainfp.o $(lib_key)" >> $(ProgPATH)/Baz1/Makefile
	@echo "" >> $(ProgPATH)/Baz1/Makefile
	@echo "clean:" >> $(ProgPATH)/Baz1/Makefile
	@echo "	@rm -f *.o*" >> $(ProgPATH)/Baz1/Makefile
#Baz2
	@echo "ProgPATH = /root/all_prog" >> $(ProgPATH)/Baz2/Makefile 
	@echo "make_o_key = -m32 -c -g -I$(cpc108) `pkg-config --cflags libmodbus` `pkg-config --cflags libfp8` `pkg-config --cflags libteprLib` -std=c99  -MMD -MP -MF" >> $(ProgPATH)/Baz2/Makefile
	@echo "lib_key = -lpthread `pkg-config --libs libmodbus` `pkg-config --libs libfp8` `pkg-config --libs libteprLib`" >> $(ProgPATH)/Baz2/Makefile
	@echo "" >> $(ProgPATH)/Baz2/Makefile
	@echo "all: clean Create" >> $(ProgPATH)/Baz2/Makefile
	@echo "Create:" >> $(ProgPATH)/Baz2/Makefile
	@echo "	gcc $(make_o_key) "$(ProgPATH)/Baz2/mainfp.o.d" -o $(ProgPATH)/Baz2/mainfp.o $(ProgPATH)/Baz2/mainfp.c" >> $(ProgPATH)/Baz2/Makefile
	@echo "	gcc -m32 -o /root/all_prog/result/Baz2 $(ProgPATH)/Baz2/mainfp.o $(lib_key)" >> $(ProgPATH)/Baz2/Makefile
	@echo "" >> $(ProgPATH)/Baz2/Makefile
	@echo "clean:" >> $(ProgPATH)/Baz2/Makefile
	@echo "	@rm -f *.o*" >> $(ProgPATH)/Baz2/Makefile
#RPU
	@echo "ProgPATH = /root/all_prog" >> $(ProgPATH)/RPU/Makefile 
	@echo "make_o_key = -m32 -c -g -I$(cpc108) `pkg-config --cflags libmodbus` `pkg-config --cflags libfp8` `pkg-config --cflags libteprLib` -std=c99  -MMD -MP -MF" >> $(ProgPATH)/RPU/Makefile
	@echo "lib_key = -lpthread `pkg-config --libs libmodbus` `pkg-config --libs libfp8` `pkg-config --libs libteprLib`" >> $(ProgPATH)/RPU/Makefile
	@echo "" >> $(ProgPATH)/RPU/Makefile
	@echo "all: clean Create" >> $(ProgPATH)/RPU/Makefile
	@echo "Create:" >> $(ProgPATH)/RPU/Makefile
	@echo "	gcc $(make_o_key) "$(ProgPATH)/RPU/mainfpRPU.o.d" -o $(ProgPATH)/RPU/mainfpRPU.o $(ProgPATH)/RPU/mainfpRPU.c" >> $(ProgPATH)/RPU/Makefile
	@echo "	gcc -m32 -o /root/all_prog/result/RPU $(ProgPATH)/RPU/mainfpRPU.o $(lib_key)" >> $(ProgPATH)/RPU/Makefile
	@echo "" >> $(ProgPATH)/RPU/Makefile
	@echo "clean:" >> $(ProgPATH)/RPU/Makefile
	@echo "	@rm -f *.o*" >> $(ProgPATH)/RPU/Makefile
#DU
	@echo "ProgPATH = /root/all_prog" >> $(ProgPATH)/DU/Makefile 
	@echo "make_o_key = -m32 -c -g -I$(cpc108) `pkg-config --cflags libmodbus` `pkg-config --cflags libfp8` `pkg-config --cflags libteprLib` -std=c99  -MMD -MP -MF" >> $(ProgPATH)/DU/Makefile
	@echo "lib_key = -lpthread `pkg-config --libs libmodbus` `pkg-config --libs libfp8` `pkg-config --libs libteprLib`" >> $(ProgPATH)/DU/Makefile
	@echo "" >> $(ProgPATH)/DU/Makefile
	@echo "all: clean Create" >> $(ProgPATH)/DU/Makefile
	@echo "Create:" >> $(ProgPATH)/DU/Makefile
	@echo "	gcc $(make_o_key) "$(ProgPATH)/DU/mainfp.o.d" -o $(ProgPATH)/DU/mainfp.o $(ProgPATH)/DU/mainfp.c" >> $(ProgPATH)/DU/Makefile
	@echo "	gcc -m32 -o /root/all_prog/result/DU $(ProgPATH)/DU/mainfp.o $(lib_key)" >> $(ProgPATH)/DU/Makefile
	@echo "" >> $(ProgPATH)/DU/Makefile
	@echo "clean:" >> $(ProgPATH)/DU/Makefile
	@echo "	@rm -f *.o*" >> $(ProgPATH)/DU/Makefile

delmake:
	@rm -f $(ProgPATH)/AKNP1/Makefile
	@rm -f $(ProgPATH)/AKNP2/Makefile
	@rm -f $(ProgPATH)/AKNP3/Makefile
	@rm -f $(ProgPATH)/AKNP4/Makefile
	@rm -f $(ProgPATH)/Baz1/Makefile
	@rm -f $(ProgPATH)/Baz2/Makefile
	@rm -f $(ProgPATH)/RPU/Makefile
	@rm -f $(ProgPATH)/DU/Makefile