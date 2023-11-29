#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <atomic>
// #include < lock >
using namespace std;
condition_variable cv;
mutex mt;
atomic<int> ai;
void job1()
{
    std::unique_lock<mutex> lk(mt);
    cv.wait_for(lk, chrono::seconds(1));
    ai = 1;
    cout << " Thread 1 . . . exit (0) . ai = " << ai << endl;
}
void job2()
{
    std::unique_lock<mutex> lk(mt);
    cv.wait_until(lk, chrono::system_clock::now() + chrono::seconds(5));
    ai = 2;
    cout << " Thread 1 . . . exit (0) . ai = " << ai << endl;
}
void job3()
{
    std::unique_lock<mutex> lk(mt);
    cv.wait_for(lk, chrono::seconds(9));
    ai = 3;
    cout << " Thread 1 . . . exit (0) . ai = " << ai << endl;
}
void noti_all()
{
    this_thread::sleep_for(chrono::seconds(6));
    cv.notify_all();
    cout << "Thread noti_all :" << endl;
}
int main(int argc, char *argv[])
{
    ai.store(0);
    thread t1(job1), t2(job2), t3(job3), t4(noti_all);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    cin.get();
    return 0;
}