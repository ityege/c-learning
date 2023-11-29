#include <iostream>   // std::cout
#include <functional> // std::ref
#include <memory>     // std::allocator, std::allocator_arg
#include <thread>     // std::thread
#include <future>     // std::promise, std::future
#include <mutex>
#include <stdlib.h>
#include <exception> // std::set_terminate
#include <cstdlib>
using namespace std;
std::mutex mt;
void job1(std::promise<int> &prom)
{
    int x;
    lock_guard<mutex> lmt(mt);
    std::cout << "Please, enter an integer value(Thread 1): " << std::endl;
    std::cin.exceptions(std::ios::failbit); // throw on failbit
    try
    {
        std::cin >> x; // sets failbit if input is not int
        prom.set_value(x);
    }
    catch (std::exception &)
    {
        prom.set_exception(std::current_exception());
    }
    cout << "Thread 1. . . exit(0). " << endl;
}
void job_print1(std::future<int> &fut)
{
    try
    {
        int x = fut.get();
        std::cout << "value: " << x << endl;
    }
    catch (std::exception &e)
    {
        std::cout << "[exception caught: " << e.what() << "]" << std::endl;
    }
}
void job3(std::promise<int> &prom)
{
    int x;
    lock_guard<mutex> lmt(mt);
    std::cout << "Please, enter an integer value(Thread 3): " << std::endl;
    std::cin.exceptions(std::ios::failbit); // throw on failbit
    try
    {
        std::cin >> x; // sets failbit if input is not int
        prom.set_value_at_thread_exit(x);
    }
    catch (std::exception &)
    {
        prom.set_exception_at_thread_exit(std::current_exception());
    }
    cout << "Thread 3. . . exit(0). " << std::endl;
}
void job_print3(std::future<int> &fut)
{
    try
    {
        int x = fut.get();
        std::cout << "value: " << x << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "[exception caught: " << e.what() << "]" << std::endl;
    }
}
int main()
{
    std::promise<int> prom, prom3;
    std::future<int> fut = prom.get_future();   // 获取对象
    std::future<int> fut3 = prom3.get_future(); // 获取对象
    try
    {
        std::thread th1(job_print1, std::ref(fut));
        std::thread th2(job1, std::ref(prom));
        std::thread th5(job_print3, std::ref(fut3));
        std::thread th6(job3, std::ref(prom3));
        th1.join();
        th2.join();
        th5.join();
        th6.join();
    }
    catch (...)
    {
    }
    return 0;
}