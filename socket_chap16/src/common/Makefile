#this is a test makefile
#date:2013:06:17
#func:in order to get the knowledge of the make's auto find and auto make dependency

TOPDIR := ~/samba/apue/
BIN := $(TOPDIR)/chap16/bin 
LIB := $(TOPDIR)/chap16/lib

OBJS := struct.o parameter.o slowio.o
LIBS := -lm -lmpthead
INCL := -I -I./../include/
CFLAGS := -Wall

struct:$(OBJS)
	#gcc -o struct $(OBJS) -lm -I../include/
	gcc -o $@ $(OBJS) $(LIBS) $(INCL)   #$< :what is it ?
clean:
	rm -rf $(OBJS)
