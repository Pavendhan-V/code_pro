
/*

    lock_guard in C++ | std::lock_guard<mutex> lock(m1)

It is very light weight wrapper for owning mutex on scoped basics
It aquires mutex lock the moment you create the object of lock_guard
It automatically removes the lock while goes out of scope
You can not explicitly unlock the lock_guard
You can not copy lock_guard

*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m1;

int buffer = 0;

void task(const char *threadNumber, int loopFor)
{
    // m1.lock();
    std::lock_guard<mutex> lock(m1);
    
    for (int i = 0; i < loopFor; i++) {
        buffer++;
        std::cout << threadNumber << buffer << std::endl;
    }
    // m1.unlock();
}

int main()
{
    std::thread t1(task, "T0 ", 10);
    std::thread t2(task, "T1 ", 10);

    t1.join();
    t2.join();

    return 0;
}