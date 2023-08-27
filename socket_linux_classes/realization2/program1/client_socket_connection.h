#pragma once

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int update_socket(struct sockaddr_in addr, int& Socket);
struct sockaddr_in create_client_address(const char* ip_addr, int port);
bool check_connection(int sock);