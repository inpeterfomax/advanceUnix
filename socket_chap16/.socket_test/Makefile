#!/bin/bash

client_socket:client_socket.o
	gcc client_socket.o -o client_socket
client_socket.o:client_socket.c
	gcc client_socket.c -c client_socket.o
server_socket:server_socket.o
	gcc server_socket.o -o server_socket
server_socket.o:server_socket.c
	gcc server_socket.c -c server_socket.o

clean:
	rm -rf *.o
