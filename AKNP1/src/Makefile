NAME = AKNP1   #имя исполняемого файла
SPATH = $(shell pwd)
ifeq "$(AKEY)" "D"
DK = -g
endif
ifeq "$(AKEY)" "R"
DK = -O2
endif
ifeq "$(SYS)" "G"
LIBPATH = /usr/local
PTHREAD = -lpthread
endif
ifeq "$(SYS)" "OW"
LIBPATH = /usr
endif

OMK =  -m32 -c $(DK) -w -DLINUXMODE -I$(LIBPATH)/include/modbus -I$(LIBPATH)/include/teprLib -I$(LIBPATH)/include/fp8 -std=c99  -MMD -MP -MF
LK = -L$(LIBPATH)/lib -lmodbus -L$(LIBPATH)/lib -lteprLib -L$(LIBPATH)/lib -lfp8 $(PTHREAD) -lm

all: clean Create

Create:
	gcc $(OMK) $(SPATH)/mainfp.o.dt -o $(SPATH)/mainfp.o $(SPATH)/mainfp.c
	gcc -m32 -o ../result/$(NAME) $(SPATH)/mainfp.o $(LK)




clean:
	@rm -f *.o*
