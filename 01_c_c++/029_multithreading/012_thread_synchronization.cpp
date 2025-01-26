
/*

    Thread or Process synchronization

Thread or process synchronize is to access the critical section
Critical section is one or collection of program statements which should be executed by only one thread or process at a time 

*/

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

long long bankBalance = 0;
std::mutex m;

void addMoney(long long val)
{
    m.lock();
    bankBalance += val;
    m.unlock();
}

int main()
{
    std::thread t1(addMoney, 100);
    std::thread t2(addMoney, 200);

    t1.join();
    t2.join();

    std::cout << "Final bankBalance : " << bankBalance << std::endl;

    return 0;
}