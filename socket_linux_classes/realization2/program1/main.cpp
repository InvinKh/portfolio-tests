#include <thread>
#include <string>
#include "custom_queue.h"
#include "worker1.h"
#include "worker2.h"

using namespace std;

int main()
{
    CustomQueue<string> buffer;
    Worker1 function1("KB");
    Worker2 function2;
    thread f1(ref(function1), ref(buffer));
    thread f2(ref(function2), ref(buffer));
    f1.join();
    f2.join();
    return 0;
}