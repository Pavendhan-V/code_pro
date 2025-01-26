
/*
    Mutex in C++ threading | why use mutex | what is race condition and how to solve it? | what is critical section

Mutex: mutual exclusion
    Mutex is used to avoid race condition
    we use lock(), unloc() on mutex to avoid race condition
Race condition:
    Race condition is a situation where two or more threads/process happend to change a common data at the same time
    If there is a race condition then we have to protect it and the protected section is called critical section/region
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m;

int myAmount = 0;

void addMoney()
{
    m.lock();
    for (int i = 0; i < 10000; i++) {
        ++myAmount;
    }
    m.unlock();
}

int main()
{
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    std::cout << myAmount << std::endl;

    return 0;
}