#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;
mutex mt;
condition_variable cv1, cv2, cv3;
void job1(int arg)
{
    std::cv_status status;
    std::unique_lock<std::mutex> lck1(mt);
    status = cv1.wait_for(lck1, chrono::seconds(8));
    if (status == std::cv_status::timeout)
    {
        cout << "wait_for timeout. " << endl;
    }
    else
    {
        cout << "wait_for timing. " << endl;
    }
    cout << "Thread " << arg << endl;
}

void job2(int arg)
{
    std::cv_status status;
    std::unique_lock<std::mutex> lck2(mt);
    status = cv2.wait_for(lck2, chrono::seconds(7));
    if (status == std::cv_status::timeout)
    {
        cout << "wait_for timeout. " << endl;
    }
    else
    {
        cout << "wait_for timing. " << endl;
    }
    cout << "Thread " << arg << endl;
}

void job3(int arg)
{
    std::cv_status status;
    std::unique_lock<std::mutex> lck3(mt);
    status = cv3.wait_for(lck3, chrono::seconds(3));
    if (status == std::cv_status::timeout)
    {
        cout << "wait_for timeout. " << endl;
    }
    else
    {
        cout << "wait_for timing. " << endl;
    }
    cv1.notify_one();
    cv2.notify_one();
    cout << "Thread " << arg << endl;
}
void job4(int arg)
{
    // bool bl =0;
    std::unique_lock<std::mutex> lck3(mt);
    auto nowt = chrono::system_clock().now();
    if (cv3.wait_until(lck3, chrono::seconds(arg) + nowt) == std::cv_status::timeout)
    {
        cout << "wait_for timeout. " << endl;
    }
    else
    {
        cout << "wait_for timing. " << endl;
    }
    cv3.notify_one();
    cout << "Thread 4" << endl;
}
int main(int argc, char *argv[])
{
    thread t1(job1, 1);
    thread t2(job2, 2);
    thread t3(job3, 3);
    thread t4(job4, 1);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    // cin. get();
    return 0;
}