
/*
    Introduction to threads in C++ 11

What do you understand by thread and give one example in c++?
    In every application there is a default thread which is main(), in side this we create other threads.
    A thread is also known as lighweight process. idea is achieve parallelism by dividing a process into multiple threads.
        Ex:
        The browser has multiple tabs that can be different threads
        MS Word must be using multiple thread, one thread to format the text, another thread to process inputs (spell checker)
        Visual studio code editor would be using threading for auto completing the code. (intellicence)

Ways to create threads in C++11
    1. Function pointers
    2. Lambda functions
    3. Functors
    4. Member functions
    5. Static member functions

*/

// Find the addition of all odd number from 1 to 1900000000 and all even number from 1 to 1900000000

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end)
{
    for (ull i = start; i < end; i++) {
        if ((i & 1) == 0) {
            EvenSum += 1;
        }
    }
}

void findOdd(ull start, ull end)
{ 
    for (ull i = start; i < end; i++) {
        if ((i & 1) == 1) {
            OddSum += 1;
        }
    }
}


int main()
{
    ull start = 0, end = 1900000000;

    auto startTime = high_resolution_clock::now();

    findOdd(start, end);
    findEven(start, end);

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    std::cout << "OddSum : " << OddSum << std::endl;
    std::cout << "EvenSum : " << EvenSum << std::endl;

    std::cout << "sec : " << duration.count()/1000000 << std::endl;


    return 0;
}