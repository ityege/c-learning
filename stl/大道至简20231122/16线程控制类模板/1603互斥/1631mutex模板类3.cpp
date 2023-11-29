#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::timed_mutex mutex;

void job1()
{
    bool bl = false;
    int count = 5;
    while (count--)
    {
        bl = mutex.try_lock_for(std::chrono::milliseconds(9));
        std::cout << "Thread 1: " << count << std::endl;
        if (bl)
            mutex.unlock();
    }
    std::cout << "Thread 1: Exiting..." << std::endl;
}

void job2()
{
    bool bl = false;
    int count = 5;
    while (count--)
    {
        bl = mutex.try_lock_for(std::chrono::milliseconds(11));
        std::cout << "Thread 2: " << count << std::endl;
        if (bl)
            mutex.unlock();
    }
    std::cout << "Thread 2: Exiting..." << std::endl;
}

int main()
{
    std::thread t1(job1);
    std::thread t2(job2);
    t1.join();
    t2.join();
    return 0;
}