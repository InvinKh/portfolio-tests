all: main

main: server_socket_connection.o worker.o main.o
	gcc server_socket_connection.o worker.o main.o -o main -lstdc++

socket_connection: server_socket_connection.cpp
	gcc -c server_socket_connection.cpp

worker:worker.cpp
	gcc -c worker.cpp

main.o: main.cpp
	gcc -c main.cpp