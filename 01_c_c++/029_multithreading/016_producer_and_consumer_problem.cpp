
/*

    Producer consumer or Bounded buffer problem

1. producer will produce and consumer will consume with synchronization of a common buffer
2. until producer thread produces any data consumer thread can't consume
3. threads will use condition_variable to notify each other
4. we need mutex if we use condition_variable because CV waits on mutex
5. this is the one of the example of producer consumer there are many

producer thread steps:
1. lock mutex, if success then go ahead otherwise wait for mutex to get free
2. check if buffer is full and if it is full then unlock mutex and sleep, if not then go ahead and produce
3. insert item in buffer
4. unlock mutex
5. notify consumer

consumer thread steps:
1. lock mutex, if success then go ahead otherwise wait for mutex to get free
2. check if the buffer is empty and if it is, the unlock mutex and sleep, if not then go ahead and consume
3. consume item from buffer
4. unlock mutex
5. notify producer


producer and consumer have to nofity each other upon completion of their job

*/

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <condition_variable>

using namespace std;

std::mutex m;
std::condition_variable cond;
std::deque<int> buffer;

const unsigned int maxBufferSize = 50;

void producer(int val)
{
    while (val) {
        std::unique_lock<std::mutex> lock(m);
        cond.wait(lock, [](){return buffer.size() < maxBufferSize;});
        buffer.push_back(val);
        std::cout << "produced : " << val << std::endl;
        val--;
        lock.unlock();
        cond.notify_one();
    }
}

void consumer()
{
    while (true) {
        std::unique_lock<std::mutex> lock(m);
        cond.wait(lock, [](){return buffer.size() > 0;});
        int val = buffer.back();
        buffer.pop_back();
        std::cout << "consumed : " << val << std::endl;
        lock.unlock();
        cond.notify_one();
    }
}

int main()
{
    std::thread t1(producer, 100);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}