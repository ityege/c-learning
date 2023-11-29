#include <iostream>
#include <thread>
using namespace std;
int thread_id = 0;
void thread_task_add()
{
    thread_id++;
    cout << "hello thread. " << endl;
    cout << "thread_id( ++ ) 's value :" << thread_id << endl;
}
void thread_task_sub()
{
    thread_id--;
    cout << "thread_id( -- ) 's value :" << thread_id << endl;
}
int main(int argc, char *argv[])
{
    thread t(thread_task_add);
    t.join();
    thread t1(thread_task_sub);
    t1.join();
    cin.get();
    return 0;
}