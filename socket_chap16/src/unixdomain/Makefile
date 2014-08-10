#!/bind/sh
.PHONY:all 

all : client single-client-server

client:client.o
	gcc -o client client.o

single-client-server:single-client-server.o
	gcc -o single-client-server single-client-server.o

clean:
	rm -rf *.o

