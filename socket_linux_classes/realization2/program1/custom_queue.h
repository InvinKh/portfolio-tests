#pragma once

#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

template <typename Message>
class CustomQueue
{
private:
    mutex                    lockqueue;
    condition_variable      queuecheck;
    queue<Message>              buffer;
    bool                    check_done;

    void get_queue(queue<Message> &change_queue) {
        Message get_message;
        while (!buffer.empty()) {
            get_message = buffer.front();
            buffer.pop();
            change_queue.push(get_message);
        }
    }

public:
    void push(Message new_message) {
        {
            unique_lock<mutex> locker(lockqueue);
            buffer.push(new_message);
            queuecheck.notify_one();
        }
    }

    queue<Message> get() {
        queue<Message> returned_queue;
        while(!check_done) {
            unique_lock<mutex> locker(lockqueue);
            queuecheck.wait(locker); {
                get_queue(returned_queue);
                return returned_queue;
            }
        }
        return returned_queue;
    }

    void returned_queue(queue<Message> received_queue) {
        unique_lock<mutex> locker(lockqueue);
        get_queue(received_queue);
        Message get_message;
        while (!received_queue.empty()) {
            get_message = received_queue.front();
            received_queue.pop();
            buffer.push(get_message);
        }
    }
};