/*

    std::lock() in C++11

It is used lock multiple mutex at the same time.

Important point:
    syntax : std::lock(m1, m2, m3...mn);
    All arguments are locked via a sequence of calles to lock(), try_lock(), or unlock() on each arguments
    Order of locking is not defined (it will try to lock provided mutex in any order and ensure that there is no dead lock())
    It is a blocking call

*/


/*
Example : 01    No dead lock
        Thread 1                        Thread 2
    std::lock(m1, m2);              std::lock(m1, m2);
*/

/*
Example : 02    No dead lock
        Thread 1                        Thread 2
    std::lock(m1, m2);              std::lock(m2, m1);
*/


/*
Example : 03    No dead lock
        Thread 1                        Thread 2
    std::lock(m1, m2, m3, m4);      std::lock(m3, m4);
                                    std::lock(m1, m2);
*/

/*
Example : 04    Yes, the below can be dead lock
        Thread 1                        Thread 2
    std::lock(m1, m2);      std::lock(m3, m4);
    std::lock(m3, m4);      std::lock(m1, m2);
*/


#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m1, m2;

void task_a()
{
    while (1) {
        std::lock(m1, m2);
        std::cout << "Task a" << std::endl;
        m1.unlock();
        m2.unlock();
    }
}

void task_b()
{
    while (1) {
        std::lock(m2, m1);
        std::cout << "Task b" << std::endl;
        m2.unlock();
        m1.unlock();
    }
}

int main()
{
    std::thread t1(task_a);
    std::thread t2(task_b);

    t1.join();
    t2.join();

    return 0;
}
