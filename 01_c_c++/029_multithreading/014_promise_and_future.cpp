
/*

    std::future and std::promise in threading

std::promise
    used to set a value or exceptions.
std::future
    used to get a value from promise
    ask promise if the value is available
    wait for promise

*/

#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <algorithm>

using namespace std;
using namespace std::chrono;

typedef long long ull;

void findOdd(std::promise<ull>&& oddSumPromise, ull start, ull end)
{
    ull oddSum = 0;
    for (ull i = start; i < end; i++) {
        if (i & 1) {
            oddSum += i;
        }
    }

    oddSumPromise.set_value(oddSum);
}

int main()
{
    ull start = 0, end = 1900000000;

    std::promise<ull> oddSum;
    std::future<ull> oddFuture = oddSum.get_future();

    std::cout << "Thread created" << std::endl;

    std::thread t1(findOdd, std::move(oddSum), start, end);

    std::cout << "waiting for result" << std::endl;

    std::cout << "oddSum : " << oddFuture.get() << std::endl;

    std::cout << "completed" << std::endl;

    t1.join();

    return 0;
}