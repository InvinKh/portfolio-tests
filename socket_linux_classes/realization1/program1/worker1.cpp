#include "worker1.h"

    void Worker1::replace_even_with_string(string &inout, string added_phase) {
        auto is_even = [](char ch) {
            return isdigit(static_cast<unsigned char>(ch)) && ((ch - '0') % 2) == 0;
        };
        for (string::size_type pos{};
            (pos = (find_if(inout.begin() + pos, inout.end(), is_even) - inout.begin())) < inout.length();
            pos += added_phase.length() - 1) {
            inout.replace(pos, 1, added_phase.data());
        }
    }

    void Worker1::receiving_messages(string& entering_string) {
        cout << "Enter a string of digits (or \"exit\" for close program):" << endl;
        cin >> entering_string;
        while ((entering_string.length()>64) || (entering_string.find_first_not_of("0123456789") != std::string::npos)) {
            cout << "[!] The string must not exceed 64 characters and must consist only of digits [!]\n";
            cout << "Enter a string of digits(or \"exit\" for close program):" << endl;
            cin >> entering_string;
        }
    }

    Worker1::Worker1(string change_string){
        string_for_change = change_string;
    }

    void Worker1::operator()(CustomQueue<string> &buffer) {
        while (true) {
            string my_str;
            receiving_messages(my_str);
            sort(my_str.begin(), my_str.end());
            reverse(my_str.begin(), my_str.end());
            replace_even_with_string(my_str, string_for_change);
            buffer.push(my_str);
        }
    }