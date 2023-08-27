#pragma once

#include "server_socket_connection.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

void analysis_message(int num);
int init_my_socket();