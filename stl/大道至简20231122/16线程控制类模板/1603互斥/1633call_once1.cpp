#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;
int winner;                 // 公共数据，仅初始化一次即可
std::once_flag winner_flag; // 标识
void set_winner(int x)
{
    winner = x;
    std::cout << "Thread ID (call_once()): " << winner << std::endl;
}
void job1(int id)
{
    std::call_once(winner_flag, set_winner, id + 2);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "thread id: " << id << std::endl;
}
void job2(int id)
{
    std::call_once(winner_flag, set_winner, id + 2);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "thread id: " << id << std::endl;
}
int main()
{
    std::thread threads[10];
    for (int i = 0; i < 5; ++i)
        threads[i * 2] = std::thread(job1, i * 2 + 1);
    for (int i = 0; i < 5; ++i)
        threads[i * 2 + 1] = std::thread(job2, i * 2 + 1 + 1);
    for (auto &th : threads)
        th.join();
    cin.get();
    return 0;
}