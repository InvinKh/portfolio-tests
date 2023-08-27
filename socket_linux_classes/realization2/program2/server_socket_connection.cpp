#include "server_socket_connection.h"


struct sockaddr_in create_server_address(int port) {
    struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;	
	addr.sin_port = htons(port);
    return addr;
}

void check_listen_socket(int& listen_socket) {
    if (listen_socket == -1) {
        cout << "Error: socket is already open" << endl;
        exit(1);
    }
}

void my_bind_socket(int& listen_socket, struct sockaddr_in& addr) {
    if (bind(listen_socket, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        cout << "Error: bind" << endl;
        exit(1);
    }
}

void my_listen_socket(int& listen_socket) {
    if(listen(listen_socket, 1) == -1) {
        cout << "Error: listen" << endl;
        exit(1);
    }
}

void my_accept_socket(int& listen_socket, int& connection, struct sockaddr_in& client_addr) {
    socklen_t client_addr_len = sizeof(client_addr);
    connection = accept(listen_socket, (struct sockaddr*)&client_addr, &client_addr_len);
    if (connection < 0) {
        cout << "Error: accept" << endl;
        exit(1);
    }
}

void create_socket(int& listen_socket, int& connection, struct sockaddr_in& addr) {
    check_listen_socket(ref(listen_socket));
    my_bind_socket(ref(listen_socket), ref(addr));
    my_listen_socket(ref(listen_socket));
    struct sockaddr_in client_addr;
    my_accept_socket(ref(listen_socket), ref(connection), ref(client_addr));
}



