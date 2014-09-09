.PHONY:all 

OBJS:= client.o single-client-server.o multi-clients-server.o
FLAGS:= -O2 -Wall

all: client single-client-server multi-clients-server

client:client.o
	gcc $(FLAGS) -o $@ $<
single-client-server:single-client-server.o
	gcc $(FLAGS) -o $@ $<
multi-clients-server:multi-clients-server.o
	gcc $(FLAGS) -o $@ $<
	#gcc $(FLAGS) -o multi-clients-server multi-clients-server.o

clean:
	rm -rf $(OBJS)
	rm -rf client single-client-server multi-clients-server
