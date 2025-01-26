
/*

    Condition variable in C++ threading

Important point:
    condition variable are used for two purpose
        1. Motify other threads
        2. Waiting for some conditions

condition variable allows running threads to wait on some conditions and once those conditions are met the waiting thread is notified using:
    1. notify_one()
    2. notify_all()
You need mutex to use condition variable
If some thread want to wait on some condition then it has to do these things
    1. Acquire the mutex lock using std::unitque_lock<mutex> lock(m1)
    2. Execute wait, wait_for, or wait_until. The wait operations automatically release the mutex and suspend the execution of the thread
    3. When the condition variable is modified, the thread is awakened, and the mutex is automatially reaquired.
       The thread should then check the condition and resume waiting if the wake up was spurious

*/

// Note:
// 1. The condition variable are used to synchronize two or more threads.
// 2. Best use case of condition variable is Producer/Consumer problems

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::condition_variable cv;
std::mutex m;

long balance = 0;

void addMoney(int money)
{
    std::lock_guard<mutex> lg(m);
    balance += money;
    std::cout << "Amount added current balance : " << balance << std::endl;
    cv.notify_one();
}

void withdrowMoney(int money)
{
    std::unique_lock<mutex> ul(m);

    cv.wait(ul, []{return (balance != 0) ? true : false;});

    if (balance >= money) {
        balance -= money;
        std::cout << "Amount deducted: " << money << endl;
    }
    else {
        std::cout << "Amount can't be deducted, Current balance is less then " << money << std::endl;
    }

    std::cout << "Current balance is : " << balance << std::endl;
}

int main()
{
    std::thread t1(withdrowMoney, 500);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread t2(addMoney, 500);

    t1.join();
    t2.join();

    return 0;
}
