all: main

main: worker1.o client_socket_connection.o worker2.o main.o
	gcc worker1.o client_socket_connection.o worker2.o main.o -o main -lstdc++

worker1.o: worker1.cpp
	gcc -c worker1.cpp

socket_connection: client_socket_connection.cpp
	gcc -c client_socket_connection.cpp

worker2: worker2.cpp
	gcc -c worker2.cpp

main.o: main.cpp
	gcc -c main.cpp