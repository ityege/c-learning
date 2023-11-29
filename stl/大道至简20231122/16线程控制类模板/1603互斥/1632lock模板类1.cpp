#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;
mutex mt;
void mysleep(int ms)
{
    chrono::seconds m(ms);
    this_thread::sleep_for(m);
}
void job1()
{
    long cnt = 3;
    while (cnt--)
    {
        lock_guard<mutex> lg(mt);
        cout << "Thread ID : " << this_thread::get_id() << endl;
        mysleep(1);
    }
}
void job2()
{
    long cnt = 3;
    while (cnt--)
    {
        mt.lock();
        lock_guard<mutex> lg(mt, adopt_lock);
        cout << "Thread ID : " << this_thread::get_id() << endl;
        mysleep(1);
    }
}
int main(int argc, char *argv[])
{
    thread t1(job1);
    thread t2(job2);
    t1.join();
    t2.join();
    cin.get();
    return 0;
}