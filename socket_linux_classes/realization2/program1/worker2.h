#pragma once

#include <string>
#include <algorithm>
#include <iostream>
#include "custom_queue.h"
#include "client_socket_connection.h"

using namespace std;

class Worker2 {
    private:
        int summer(string entering_string);
    public:
        void operator()(CustomQueue<string> &buffer);
};
