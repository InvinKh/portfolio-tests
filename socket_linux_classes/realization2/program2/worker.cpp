#include "worker.h"

void analysis_message(int num) {
	if (num >= 0) {
		if ((num > 99) && (num%32 == 0)) {
			cout << "Number received: " << num << endl;
		} else {
			cout << "The resulting number does not satisfy all the conditions." << endl; 
		}	
	}
}

int init_my_socket() {
    struct sockaddr_in addr;
    addr = create_server_address(1111);
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    int conn;
    create_socket(ref(listenfd), ref(conn), ref(addr));
	while (true) {
        char msg[4];
		short sizeof_message = 0;
		while (true) {
			sizeof_message = recv(conn, msg, sizeof(msg), 0);
            if (sizeof_message == 0) {
				close(conn);
				close(listenfd);
				return 1;
            }
			int num = atoi(msg);
            analysis_message(num);
    	}
    }
    close(conn);
    close(listenfd);
    return 0;
}