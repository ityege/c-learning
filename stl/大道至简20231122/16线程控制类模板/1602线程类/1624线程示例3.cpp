#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <future>
using namespace std;
bool cont = 0;
void thread_entry1()
{
    long a = 10000;
    int sec = 0;
    cout << "Wait for 10 sec. . . " << std::endl;
    while (a--)
    {
        chrono::milliseconds dura(1);
        this_thread::sleep_for(dura); // 睡眠相对延时 dura 时间
    }
    cout << "Wait for 8 sec. . . " << endl;
    while (sec <= 8)
    {
        this_thread::sleep_until(chrono::system_clock::now() + chrono::seconds(sec));
        // 睡眠至新的指定时间
        cout << ". ";
    }
    std::cout << std::endl;
    cout << "Thread(1) id : " << this_thread::get_id() << endl;
    cont = 1;
}
void thread_entry2()
{
    cout << "Thread(2) id: " << this_thread::get_id() << endl;
    std::cout << "Thread(2) exit. . . " << std::endl;
}
int main(int argc, char *argv[])
{
    cout << "Hello waiter : ";
    chrono::milliseconds dura(2000);
    this_thread::sleep_for(dura);
    cout << "Waited 2000 ms\n";
    thread t(thread_entry1);
    thread t2(thread_entry2);
    cout << "Thread(1) origin id : " << t.get_id() << endl;
    cout << "Thread(2) origin id: " << t2.get_id() << endl;
    t.swap(t2);
    cout << "Thread(1) swapped id : " << t.get_id() << endl;
    cout << "Thread(2) swapped id: " << t2.get_id() << endl;
    t2.swap(t);
    cout << "Thread(1) swapped id secondly: " << t.get_id() << endl;
    cout << "Thread(2) swapped id secondly: " << t2.get_id() << endl;
    if (t.joinable())
        t.detach();
    if (t2.joinable())
        t2.join();
    std::thread::native_handle_type hd = t.native_handle();
    cout << "native_handle: " << hd << endl;
    unsigned int tc = t.hardware_concurrency();
    cout << "hardware_concurrency: " << tc << endl;
    cin.get();
    return 0;
}