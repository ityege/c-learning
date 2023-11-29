#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;
recursive_mutex mt;
long dim[11];
void mysleep(long ms)
{
    chrono::milliseconds md(10);
    this_thread::sleep_for(md);
}
void thread_proc1()
{
    int index = 0;
    for (index = 0; index < 5; index++)
    {
        mt.lock();
        dim[index * 2] = 1;
        cout << "The First Thread. . . : " << dim[index * 2 + 1] << endl;
        mt.unlock();
        mysleep(10);
    }
    cout << "The First Thread. . . exit(0). " << endl;
}
void thread_proc2()
{
    int index = 0;
    for (index = 0; index < 5; index++)
    {
        mt.lock();
        dim[index * 2 + 1] = 2;
        cout << "The Second Thread. . . : " << dim[index * 2 + 1] << endl;
        mt.unlock();
        mysleep(10);
    }
    cout << "The Second Thread. . . exit(0). " << endl;
}
int main(int argc, char *argv[])
{
    thread t1(thread_proc1);
    thread t2(thread_proc2);
    t1.join();
    t2.join();
    cin.get();
    return 0;
}