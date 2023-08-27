#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

struct sockaddr_in create_server_address(int port);
void check_listen_socket(int& listen_socket);
void my_bind_socket(int& listen_socket, struct sockaddr_in& addr);
void my_listen_socket(int& listen_socket);
void my_accept_socket(int& listen_socket, int& connection, struct sockaddr_in& client_addr);
void create_socket(int& listen_socket, int& connection, struct sockaddr_in& addr);