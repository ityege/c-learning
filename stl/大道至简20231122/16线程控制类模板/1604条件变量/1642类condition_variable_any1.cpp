#include <iostream>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <atomic>
#include <thread>
using namespace std;
std::atomic<int> si;
condition_variable_any cva, cvb;
mutex mt, mt1;
void job1()
{
    std::unique_lock<std::mutex> lk(mt);
    std::cout << " Thread 1 (locked): Waiting. . . " << std::endl;
    cva.wait(lk, []
             { return si == 1; });
    std::cout << " Thread 1 exit (0) . . . si = " << si << std::endl;
}
void job2()
{
    std::unique_lock<std::mutex> lk(mt);
    std::cout << " Thread 2 (locked): Waiting. . . " << std::endl;
    cva.wait(lk, []
             { return si == 1; });
    std::cout << " Thread 2 exit (0) . . . si = " << si << std::endl;
}
void job3()
{
    std::unique_lock<std::mutex> lk(mt);
    std::cout << " Thread 3 (locked): Waiting. . . " << std::endl;
    cva.wait(lk, []
             { return si == 1; });
    std::cout << " Thread 3 exit (0) . . . . si = " << si << std::endl;
}
void job4()
{
    std::unique_lock<std::mutex> lk(mt);
    std::cout << " Thread 4 (locked): Waiting. . . " << std::endl;
    cva.wait(lk, []
             { return si == 1; });
    std::cout << " Thread 4 exit (0) . . . . si = " << si << std::endl;
}
void noti_all()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lk(mt);
        std::cout << "Notifying. . . All. " << std::endl;
    }
    si = 1;
    cva.notify_all();
}
void job6()
{
    std::unique_lock<std::mutex> lk(mt1);
    std::cout << "Thread 6 (locked): Waiting. . . " << std::endl;
    cvb.wait(lk, []
             { return si == 6; });
    std::cout << "Thread 6 exit(0). . . . si = " << si << std::endl;
}
void job7()
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    {
        std::lock_guard<std::mutex> lk(mt1);
        std::cout << "Notifying_one. . . first. " << std::endl;
    }
    si = 6;
    cvb.notify_one();
}
int main(int argc, char *argv[])
{
    si.store(0);
    thread t1(job1), t2(job2), t3(job3), t4(job4), t5(noti_all), t6(job6), t7(job7);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    // this_thread::sleep_for(chrono::seconds(5));//wait
    t6.join();
    t7.join();
    cin.get();
    return 0;
}