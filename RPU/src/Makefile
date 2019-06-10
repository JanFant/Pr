NAME = RPU   #имя исполняемого файла
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
EXEP = ../result
endif
ifeq "$(SYS)" "OW"
LIBPATH = /usr
EXEP = ../
endif

OMK =  -m32 -c $(DK) -w -DLINUXMODE -I$(LIBPATH)/include/modbus -I$(LIBPATH)/include/teprLib -I$(LIBPATH)/include/fp8 -std=c99  -MMD -MP -MF
LK = -L$(LIBPATH)/lib -lmodbus -L$(LIBPATH)/lib -lteprLib -L$(LIBPATH)/lib -lfp8 $(PTHREAD)

all: clean Create

Create:
	gcc $(OMK) $(SPATH)/mainfp.o.dt -o $(SPATH)/mainfp.o $(SPATH)/mainfp.c
	gcc -m32 -o $(EXEP)/$(NAME) $(SPATH)/mainfp.o $(LK)

test:
	$(SPATH)

clean:
	@rm -f *.o*
