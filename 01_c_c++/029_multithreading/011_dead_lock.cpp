
/*

do not change the order of the mutex lock

// task 1
m1.lock
m2.lock

// task 2
m1.lock
m2.lock

*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m1;
std::mutex m2;

void task1()
{
    m1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    m2.lock();
    std::cout << "Critical section of the thread one" << std::endl;
    m1.unlock();
    m2.unlock();
}

void task2()
{
    m2.lock();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    m1.lock();
    std::cout << "Critical section of the thread two" << std::endl;
    m2.unlock();
    m1.unlock();
}

int main()
{
    std::thread t1(task1);
    std::thread t2(task2);

    t1.join();
    t2.join();

    return 0;
}