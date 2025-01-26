
/*

    std::async
It runs a function asynchronously (potentially in a new thread) and returns a std::future that will hold a result
There are three launch policies for creating task
    std::launch::async
    std::launch::deffered
    std::launch::async | std::launch::deffered

how it works:
It automatically creates a thread (or picks from internal thread pool) and a promise object for us.
Then passes the std::promise object to thread function and returns the associated std::future object
When our passed argument function exits then its value will be set in this promise object
    so eventually return value will be available in std::future object

note:
    we can send functor and lambda function as callback to std::sync, it will work the same

*/

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;

typedef long long ull;

ull findOdd(ull start, ull end)
{
    std::cout << "find odd thread id " << std::this_thread::get_id() << std::endl;

    ull oddSum = 0;
    for (int i = start; i < end; i++) {
        if (i & 1) {
            oddSum += i;
        }
    }

    return oddSum;
}

int main()
{
    ull start = 0, end = 1900000000;

    std::cout << "Thread created if policy is std::launch::async " << std::endl;

    std::cout << "main thread id " << std::this_thread::get_id() << std::endl;

    // std::future<ull> oddSum = std::async(std::launch::deferred, findOdd, start, end);
    std::future<ull> oddSum = std::async(std::launch::async, findOdd, start, end);

    std::cout << "Waiting for result" << std::endl;
    std::cout << "oddSum : " << oddSum.get() << std::endl;

    std::cout << "completed" << std::endl;

    return 0;
}