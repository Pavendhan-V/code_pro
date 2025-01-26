
/*

    unique_loc in C++ | std::unique_lock<mutex> lock(m1)

The class unique_lock is a mutex ownership wrapper
It allows:
    Can have different locking strategies
    time-constrained attempts at locking (try_lock_for, try_lock_until)
    recursive locking
    transfer of lock ownership (move not copy)
    condition variables

Locking strategies
    Type                Effects
1. defer_lock           do not acquire ownership of the mutex
2. try_to_lock          try to acquire ownership of the mutex without blocking
3. adopt_lock           assume the calling thread already has ownership of the mutex

*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m1;

int buffer = 0;

// example 1

// void task(const char* threadNumber, int loopFor)
// {
//     std::unique_lock<mutex> lock(m1);   // Automatically calls lock on mutex m1

//     for (int i = 0; i < loopFor; i++) {
//         buffer++;
//         std::cout << threadNumber << buffer << std::endl;
//     }
// }

// example 2
void task(const char* threadNumber, int loopFor)
{
    std::unique_lock<mutex> lock(m1, std::defer_lock);   // does not call lock on mutex m1, because used defer_lock
    lock.lock();

    for (int i = 0; i < loopFor; i++) {
        buffer++;
        std::cout << threadNumber << buffer << std::endl;
    }

    // lock.unlock(); is not needed as it will be unlocked in destructor of unique_lock
}

int main()
{
    std::thread t1(task, "T1 ", 10);
    std::thread t2(task, "T2 ", 10);

    t1.join();
    t2.join();

    return 0;
}
