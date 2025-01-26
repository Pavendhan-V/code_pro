/*
    Tyes of thread creation in C++11
There are 5 different types we can create thread in C++11 using callable objects

Note: Ife we create multiple thread at the same time it doesn't guarantee which one will start first
*/

#include <iostream>
#include <thread>

using namespace std;

// 1. Function pointer
// This is the very basic form of thread creation

// void fun(int x)
// {
//     while (x-- > 0) {
//         std::cout << x << std::endl;
//     }
// }

// int main()
// {
//     std::thread t1(fun, 10);
//     t1.join();

//     return 0;
// }


// 2. Lambda _Function_args

// int main()
// {
//     // we can directly inject lambda at thread creation time
//     // auto fun = [](int x) {
//     //     while (x-- > 0) {
//     //         std::cout << x << std::endl;
//     //     }
//     // };

//     // std::thread t(fun, 10);
//     std::thread t([](int x) {
//         while(x-- > 0) {
//             std::cout << x << std::endl;
//         }
//     },10);

//     t.join();

//     return 0;
// }


// 3. Functor (function object)

// class Base
// {
// public:
//     void operator ()(int x)
//     {
//         while (x-- > 0) {
//             std::cout << x << std::endl;
//         }
//     }
// };

// int main()
// {
//     std::thread t((Base()), 10);
//     t.join();

//     return 0;
// }



// 4. Non-static member function

// class Base
// {
// public:
//     void run(int x)
//     {
//         while(x-- > 0) {
//             std::cout << x << std::endl;
//         }
//     }
// };

// int main()
// {
//     Base b;
    
//     std::thread t(&Base::run, &b, 10);
//     t.join();

//     return 0;
// }



// 5. Static member function

class Base
{
public:
    static void run(int x)
    {
        while (x-- > 0) {
            std::cout << x << std::endl;
        }
    }
};

int main()
{
    std::thread t(&Base::run, 10);
    t.join();

    return 0;
}
