#include "client_socket_connection.h"

int update_socket(struct sockaddr_in addr, int& Socket)
{
    Socket = socket(AF_INET, SOCK_STREAM, 0);
    if (Socket < 0) {
        return 0;
    }
    if (connect(Socket, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        return 0;
    } else {
        return 1;
    }
}

struct sockaddr_in create_client_address(const char* ip_addr, int port) {
    struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(ip_addr);	
	addr.sin_port = htons(port);
    return addr;
}

bool check_connection(int sock) {
    char msg[4];
    sprintf(msg, "%i", -1);
    int err = send(sock, msg, sizeof(msg), MSG_NOSIGNAL);
    if (err >= 0) { // checking for a false positive
        err = send(sock, msg, sizeof(msg), MSG_NOSIGNAL);
    }
    if(err < 0) {
        return false;
    }
    return true;
}