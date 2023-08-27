#pragma once

#include <iostream>
#include "custom_queue.h"
#include <string>

using namespace std;

class Worker1 {
    string string_for_change;
private:
    void replace_even_with_string(string &inout, string added_phase);
    void receiving_messages(string& entering_string);
public:
    Worker1(string change_string);
    void operator()(CustomQueue<string> &buffer);
};