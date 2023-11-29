#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;
recursive_timed_mutex rtm;
void mysleep(short s)
{
    this_thread::sleep_for(chrono::seconds(s));
}
void job1()
{
    long cnt = 6;
    bool bl;
    while (cnt--)
    {
        bl = rtm.try_lock();
        if (bl)
        {
            cout << "Thread ID: " << this_thread::get_id() << endl;
            rtm.unlock();
        }
        mysleep(1);
    }
}
void job2()
{
    long cnt = 6;
    bool bl;
    while (cnt--)
    {
        bl = rtm.try_lock_for(chrono::milliseconds(10));
        if (bl)
        {
            cout << "Thread ID: " << this_thread::get_id() << endl;
            rtm.unlock();
        }
        mysleep(1);
    }
}
void job3()
{
    bool bl;
    long cnt = 6;
    while (cnt--)
    {
        bl = bl = rtm.try_lock_until(chrono::steady_clock::now() + chrono::milliseconds(10));
        if (bl)
        {
            cout << "Thread ID: " << this_thread::get_id() << endl;
            rtm.unlock();
        }
        mysleep(1);
    }
}
int main(int argc, char *argv[])
{
    thread t1(job1);
    thread t2(job2);
    thread t3(job3);
    t1.join();
    t2.join();
    t3.join();
    cin.get();
    return 0;
}