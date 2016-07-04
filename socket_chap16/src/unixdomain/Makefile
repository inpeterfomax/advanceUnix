.PHONY:all 

#OBJS:= client.o single-client-server.o multi-clients-server.o
OBJS:= *.o
FLAGS:= -O2 -Wall

all: client single-client-server multi-clients-server

#all:$(OBJS)
#	gcc $(FLAGS) -O $@ $<

client:client.o
	gcc $(FLAGS) -o $@ $<
single-client-server:single-client-server.o
	gcc $(FLAGS) -o $@ $<
multi-clients-server:multi-clients-server.o
	gcc $(FLAGS) -o $@ $<
	#gcc $(FLAGS) -o multi-clients-server multi-clients-server.o

clean:
	rm -rf $(OBJS)
	rm -rf *.socket
	rm -rf client single-client-server multi-clients-server
