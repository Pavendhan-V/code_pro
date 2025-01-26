
/*

    Timed mutex in C++ threading std::timed_mutex

Learn about mutex, race condition, critical sections

Notes:
std::timed_mutex is blocked till timeout_time or lock is aquired and returns true if success otherwise false
Member function:
    lock
    try_lock
    try_loc_for     ---\    These two functions makes it different from mutex
    try_lock_until  ---/
    unlock

Ex: try_lock_for();
waits until specified timeout duration has elapsed or the lock is acquired, whichever comes first
On successful lock acquisition returns true, otherwise returns false
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono;

int myAmount = 0;
std::timed_mutex m;

void increment(int i)
{
    if (m.try_lock_for(chrono::seconds(1))) {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Thread " << i << " Entered" << std::endl;
        m.unlock();
    }
    else {
        std::cout << "Thread " << i << " couldn't enter" << std::endl;
    }
}

int main()
{
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);

    t1.join();
    t2.join();

    std::cout << myAmount << std::endl;

    return 0;
}