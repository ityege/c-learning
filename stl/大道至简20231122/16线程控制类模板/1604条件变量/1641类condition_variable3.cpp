#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
using namespace std;
std::mutex mtx;
std::condition_variable cv1, cv2;
int cargo = 0;
void job2() // 消费者
{
    std::unique_lock<std::mutex> lck(mtx);
    cout << " ";
    while (cargo == 0)
        cv2.wait(lck);
    cout << cargo << endl;
    cargo = 0;
    cv1.notify_one();
}
void job1(int id) // 生产者
{
    std::unique_lock<std::mutex> lck(mtx);
    cout << "++ " << endl;
    while (cargo != 0)
        cv1.wait(lck);
    cargo = id;
    cout << "The notify Thread ID: " << id << endl;
    cv2.notify_one();
}
int main()
{
    std::thread t1[5], t2[5];
    for (int i = 0; i < 5; ++i)
    {
        t1[i] = std::thread(job2);
        t2[i] = std::thread(job1, i + 1);
    }
    for (int i = 0; i < 5; ++i)
    {
        t2[i].join();
        t1[i].join();
    }
    cin.get();
    return 0;
}