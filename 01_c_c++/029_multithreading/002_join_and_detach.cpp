/*
    Use of join(), detach() and joinable(), detachable() in thread in C++11
join notes:
    Once a thread is started we wait for this thread to finish by calling join() function on thread object
    Duble join will result int program termination
    If needed we should check thread is joinable before joining. (uinsg joinable() function)

detach notes:
    This is used to detach newly created thread from the parent thread
    Always check before detaching a thread that it is joinable otherwise we may end up double detaching and double detach() will result into program termination
    If we have detached thread and main function is returning then the detached thread execution is suspended

Notes:
    Either join() or detach() should be called on thread object, otherwise during thread object's destructor it will terminate the program.
    because inside destructor it checks if thread is still joinable? if yes then it terminate the program.
*/

// The momement you create a thread that thread is marked as joinable and then later once either you apply join() or detach() on that thread then it automatically becomes non-joinable

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void fun(int cout)
{
    while (cout-- > 0) {
        std::cout << "thread" << std::endl;
    }
    std::this_thread::sleep_for(chrono::seconds(3));
}

int main()
{
    std::thread t(fun, 10);

    std::cout << "main" << std::endl;
    t.join();   // when the program it the join of its threads. it wait here for the completion of its thread
    if (t.joinable())
        t.join();
    std::cout<< "main end" << std::endl;

    return 0;
}