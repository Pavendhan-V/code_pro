
/*

    Recursive Mutex in C++ (std::recursive_mutex)

It is same as mutex but, same thread can lock one mutex multiple times using recursive mutex
If thread T1 first call lock/try_lock on recursive mutex m1, then m1 is locked by T1, now as T1 is running in recursive T1 can call lock/try_lock any number of times there is no issue.
But if T1 have aquired 10 times lock/try_lock on mutex m1 then thread T1 will have to unlock it 10 times otherwise no other thread will be able to lock mutex m1.
It means recursive_mutex keeps count how many times it was locked so that many times it should be unlocked.
How many time we can lock recursive_mutex is not defined but when that number reaches and if we wer calling lock() it will return std::system_error OR if we were calling try_lock() then it will return false.

note:
It is similar to mutex but have extra facitility that it can be locked multiple time by same thread.
If we can avoid recursive_mutex then we should because it brings overhead to the system.
It can be used in loops also

*/


#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::recursive_mutex m1;
int buffer = 0;

// example 1 : with recursion
 
void recursion(char c, int loopFor)
{
    if (loopFor < 0)
        return;

    m1.lock();
    std::cout << "Thread ID " << c << " " << buffer++ << endl;
    recursion(c, --loopFor);
    m1.unlock();
    std::cout << "Unlocked By thread id : " << c << std::endl;
}

// int main()
// {
//     std::thread t1(recursion, '0', 10);
//     std::thread t2(recursion, '1', 10);

//     t1.join();
//     t2.join();

//     return 0;
// }

// example 2: with loop

int main()
{
    for (int i = 0; i < 5; i++) {
        m1.lock();
        std::cout << "locked " << i << std::endl;
    }

    for (int i = 0; i < 5; i++) {
        m1.unlock();
        std::cout << "unlocked " << i << std::endl;
    }

    return 0;
}