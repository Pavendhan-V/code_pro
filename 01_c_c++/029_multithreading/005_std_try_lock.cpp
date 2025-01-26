
/*

    std::try_lock() in C++11 threading
std::try_lock() tries to lock all the lockable objects passed in it one by one in given order
    syntax: std::try_lock(m1, m2, m3, ....mn);
On success this function returns -1 otherwise it will return 0-based mutex index number which it could not lock.
It it fails to lock any of the mutex then it will release all the mutex it locked before
If a call to try_lock results in an exception, unlock is called for any locked objects before rethrowing
 
*/
// The actual use of std::try_lock() function is, it can try to lock multiple mutex objects at the same time

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int x = 0, y = 0;
std::mutex m1, m2;

void mySleep(int sec)
{
    std::this_thread::sleep_for(chrono::seconds(sec));
}

void incrementXY(int &XorY, std::mutex &m, const char *desc)
{
    for (int i = 0; i < 5; ++i) {
        m.lock();
        ++XorY;
        std::cout << desc << XorY << std::endl;
        m.unlock();
        mySleep(1);
    }
}

void consumeXY()
{
    int useCount = 5;
    int XplusY = 0;

    while (1) {
        int lockResult = std::try_lock(m1, m2);
        if (lockResult == -1) {
            if (x != 0 && y != 0) {
                --useCount;
                XplusY += x + y;
                x = 0;
                y = 0;
                std::cout << "XplusY " << XplusY << std::endl;
            }
            m1.unlock();
            m2.unlock();

            if (useCount == 0)
                break;
        }
    }
}

int main()
{
    std::thread t1(incrementXY, std::ref(x), std::ref(m1), "X ");
    std::thread t2(incrementXY, std::ref(y), std::ref(m2), "Y ");
    std::thread t3(consumeXY);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}