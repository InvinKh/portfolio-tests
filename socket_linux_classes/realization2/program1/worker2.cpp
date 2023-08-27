#include "worker2.h"


int Worker2::summer(string entering_string) {
    int sum = 0;
    for_each(entering_string.begin(), entering_string.end(), [&sum](char c) {
        if (isdigit(c))
            sum += atoi(&c);
    });
    return sum;
}

void Worker2::operator()(CustomQueue<string> &buffer) {
    struct sockaddr_in addr;
    queue<string> queue_in_buffer;
    string entering_string;
    int check_send;

	addr = create_client_address("127.0.0.1", 1111);
    int Connection;
    while (true) {
        queue_in_buffer = buffer.get();
        while (!queue_in_buffer.empty()) {
            entering_string = queue_in_buffer.front();
            cout << entering_string << endl;
            int sum;
            sum = summer(entering_string);
            char msg[4];
            sprintf(msg, "%i", sum);
            if (!check_connection(Connection)) {
                update_socket(addr, Connection);
                check_send = send(Connection, msg, sizeof(msg), MSG_NOSIGNAL);
            } else {
                check_send = send(Connection, msg, sizeof(msg), MSG_NOSIGNAL);
            }
            if (check_send <= 0) {
                buffer.returned_queue(queue_in_buffer);
                break;
            } else {
                queue_in_buffer.pop();
            }
        }
    }
}