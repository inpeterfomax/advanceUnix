.PHONY:all

CC ?= gcc
OBJS := pairesocket.o  pairesocketchi-par.o

all:pairesocket pairesocketchi-par

#pairsocket:pairsocket.o
#	$(CC)  -o pairsocket pairsocket.o
#pairsocket.o:pairsocket.c
#	$(CC) -c pairsocket.o pairsocket.c
#	
##pairsocketchi-par:pairsocketchi-par.o
#	$(CC) -o $@ $<

all:$(OBJS)
	$(CC) -o $@ $<

clean:
	rm -rf $(OBJS)
	rm -rf pairesocket pairesocketchi-par
	rm -rf all
