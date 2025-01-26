/*
There are so many try_lock function
    1. std::try_cock()
    2. std::mutex::try_lock()
    3. std::shared_lock::try_lock()
    4. std::timed_mutex::try_lock()
    5. std::unique_lock::try_lock()
    6. std::shared_mutex::try_lock()
    7. std::recursive_mutex::try_lock()
    8. std::shared_timed_mutex::try_lock()
    9. std::recursive_timed_mutex::try_lock()
*/

/*
    std::mutex::try_lock() on murex in C++11 threading

try_lock() tries to lock the mutex, returns immediately. on successful lock acquision returns true otherwise returns false
If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking
If try_lock() is called again by the same thread which owns the mutes, the behavior is undefined
It is a dead lock situation with undefined behaviour. (if you want to be able to lock the smae mutex by same thread more than one time then go for recursive_mutex)

*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m;
int counter = 0;

void increaseCounter()
{
    for (int i = 0; i < 100000; i++) {
        if (m.try_lock()) {
            ++counter;
            m.unlock();
        }
    }
}

int main()
{
    std::thread t1(increaseCounter);
    std::thread t2(increaseCounter);

    t1.join();
    t2.join();

    std::cout << "counter could increase upto : " << counter << std::endl;

    return 0;
}