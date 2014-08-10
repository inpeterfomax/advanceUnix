
CC := gcc
AR := ar
LD := ld
CROSSCOMPILE := arm-7077-linux-
CFLAGS := -g -o2 -Wall -DDEBUG
INC := -I. -I./../include/
LDFLAGS :=  
TOPDIR := ./../../
TOPBIN := ./../../bin
TOPLIB := ./../../lib
#OBJS:= *.o  #objects := $(wildcard *.o) 

all: server clientapple

server:server.o
	$(CC) $(CFLAGS) -o server server.o $(LDFLAGS)
server.o:server.c
	$(CC) $(CFLAGS) -c server.c $(LDFLAGS)
clientapple:clientapple.o
	$(CC) $(CFLAGS) -o clientapple clientapple.o $(LDFLAGS)
clientapple.o:clientapple.c
	$(CC) $(CFLAGS) -c clientapple.c $(LDFLAGS)


.PHONY:all install clean disclean


install:
	mv -f $(ALL) $(TOPDIR)/bin 

clean:
	rm -rf *.o 
disclean:
	rem -rf *.ko
