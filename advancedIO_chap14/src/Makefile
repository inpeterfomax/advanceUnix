#use this makefile to compile to  
BINDIR = ../bin
LIBDIR = ../lib
EXCU = nonblock
OBJ = nonblock.o 
LIB = $(LIBDIR)/set_clr_fl.o
###################make lib####################
#fi[ -e ../lib/set_clr_fl.o ]
#	LIB = ../lib/set_clr_fl.o
#else
#	make clean;
#	gcc -c set_clr_fl.c
#	sleep(3)
#	mv set_clr_fl.o  ../lib/
#fi
#################compile######################
.PHONY :all clean 

all:nonblock 

nonblock:$(OBJ)
	gcc -o $@ $(OBJ) $(LIB) 

	mv -f $(EXCU)  $(BINDIR) 

clean:
	rm -rf *.o
