#include <iostream>
#include <future>
#include <thread>
#include <utility>
#include <algorithm>
using namespace std;
long job2(int arg1)
{
    return arg1;
}
int job1(int arg1)
{
    return arg1;
}
int main(int argc, char *argv[])
{
    std::packaged_task<long(int)> task1(job1);
    std::future<long> f1 = task1.get_future();
    task1(1);
    cout << " Thread 1 (shared_status): " << f1.get() << endl;
    std::packaged_task<long(int)> task2(job2);
    std::future<long> f2 = task2.get_future();
    std::thread(std::move(task2), 5).detach();
    cout << " Thread 2 (shared_status): " << f2.get() << endl;
    std::packaged_task<long(int)> task3(job1);
    std::packaged_task<long(int)> task4(job2);
    std::future<long> f3 = task3.get_future();
    std::future<long> f4 = task4.get_future();
    swap(task3, task4);
    task3(1);
    std::thread(std::move(task4), 5).detach();
    cout << " Thread 3 (shared_status): " << f3.get() << endl;
    cout << " Thread 4 (shared_status): " << f4.get() << endl;
    cin.get();
    return 0;
}