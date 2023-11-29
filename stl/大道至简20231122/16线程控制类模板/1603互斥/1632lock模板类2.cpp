#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

std::mutex mt;
std::recursive_timed_mutex mt1;

void job1()
{
    unique_lock<mutex> lgm(mt, defer_lock);
    lgm.lock();
    std::cout << "Thread 1: . . . " << std::endl;
    lgm.unlock();
}

void job2()
{
    unique_lock<mutex> ulm(mt);
    std::cout << "Thread 2: . . . " << std::endl;
}

void job3()
{
    unique_lock<mutex> ulm3(mt, try_to_lock);
    if (ulm3.owns_lock())
    {
        std::cout << "Thread 3: owned . . . " << std::endl;
        ulm3.unlock();
    }
    else
    {
        std::cout << "Thread 3: not owned . . . " << std::endl;
    }
}

void job4()
{
    unique_lock<mutex> ulm4;
    unique_lock<mutex> ulmTemp(mt);
    ulm4.swap(ulmTemp);
    if (ulm4.owns_lock())
    {
        std::cout << "Thread 4: owned . . . " << std::endl;
    }
}

void job5()
{
    mt.lock();
    unique_lock<mutex> ulm5(mt, adopt_lock);
    std::cout << "Thread 5: . . . " << std::endl;
}

void job6()
{
    const chrono::duration<int> dur(3);
    unique_lock<recursive_timed_mutex> ulm6(mt1, dur);
    std::cout << "Thread 6: . . . " << std::endl;
}

void job7()
{
    chrono::steady_clock::time_point t1 = chrono::steady_clock().now();
    chrono::steady_clock::time_point t2 = t1 + chrono::seconds(1);
    unique_lock<recursive_timed_mutex> ulm7(mt1, t2);
    if (!ulm7.owns_lock())
    {
        std::cout << "Thread 7: not owned. " << std::endl;
    }
    else
    {
        std::cout << "Thread 7: owned. . . " << std::endl;
        ulm7.unlock();
    }
}

void job8()
{
    unique_lock<recursive_timed_mutex> ulm8(mt1, defer_lock);
    ulm8.lock();
    if (ulm8.owns_lock())
    {
        std::cout << "Thread 8: lock() usage. . . " << std::endl;
        ulm8.unlock();
    }
    if (ulm8.try_lock())
    {
        std::cout << "Thread 8: try_lock() usage. . . " << std::endl;
        ulm8.unlock();
    }
    if (ulm8.try_lock_for(chrono::seconds(1)))
    {
        std::cout << "Thread 8: try_lock_for() usage. . . " << std::endl;
        ulm8.unlock();
    }
    if (ulm8.try_lock_until(chrono::steady_clock().now() + chrono::seconds(1)))
    {
        std::cout << "Thread 8: try_lock_until() usage. . . " << std::endl;
        ulm8.unlock();
    }
}

int main(int argc, char *argv[])
{
    thread t1(job1);
    thread t2(job2);
    thread t3(job3);
    thread t4(job4);
    thread t5(job5);
    thread t6(job6);
    thread t7(job7);
    thread t8(job8);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    cin.get();
    return 0;
}