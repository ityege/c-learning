#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;
mutex m, m2;
long shareddata[11];
void thread_proc1()
{
    int index = 0;
    for (index = 0; index < 5; index++)
    {
        m.try_lock();
        shareddata[2 * index] = 2 * index;
        std::cout << "thread 1 -- shareddata: " << shareddata[2 * index] << std::endl;
        m.unlock();
        chrono::milliseconds sd(10);
        this_thread::sleep_for(sd); // 休眠 10ms
    }
    std::cout << "thread 1: exit (0);" << std::endl;
}
void thread_proc2()
{
    int index_2 = 0;
    for (index_2 = 0; index_2 < 5; index_2++)
    {
        m.lock();
        shareddata[2 * index_2 + 1] = 2 * index_2 + 1;
        std::cout << " thread 2 -- shareddata: " << shareddata[2 * index_2 + 1] << std::endl;
        m.unlock();
        chrono::milliseconds sd(10);
        this_thread::sleep_for(sd); // 休眠 10ms
    }
    std::cout << " thread 2: exit (0);" << std::endl;
}
int main(int argc, char *argv[])
{
    thread t1(thread_proc1);
    thread t2(thread_proc2);
    t1.detach();
    t2.join();
    cin.get();
    return 0;
}