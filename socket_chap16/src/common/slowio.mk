#this is a test makefile
#date:2013:06:17
#func:in order to get the knowledge of the make's auto find and auto make dependency

TOPDIR := $(HOME)/ws/advanceUnix/
BIN := $(TOPDIR)/socket_chap16/bin 
LIB := $(TOPDIR)/socket_chap16/lib

OBJS := slowio.o
LIBS := -lm -lpthread
INCL := -I -I./../include/
CFLAGS := -Wall
CC:=gcc

slowio:$(OBJS)
	$(CC) $(CFLAGS) -o $@ $(LIBS) $(INCL) $<

clean:
	rm -rf $(OBJS)
	rm -rf *.out
