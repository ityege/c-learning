#include <iostream>
#include <future>
#include <thread>
#include <utility>
using namespace std;
int job1(int arg)
{
    return arg * 5;
}
int main(int argc, char *argv[])
{
    std::packaged_task<int(int)> pt1;       // default - constructed
    std::packaged_task<int(int)> pt2(job1); // 设置
    if (!pt2.valid())
        return -1;
    pt1 = std::move(pt2);                   // 赋值操作
    std::future<int> f1 = pt1.get_future(); // get future
    pt1(2);                                 // operator () //生成线程， 并调用任务
    int value = f1.get();                   // wait for the task to finish and get result
    std::cout << " The stored value in future is " << value << endl;
    pt1.reset();
    f1 = pt1.get_future();                   // get future
    std::thread(std::move(pt1), 7).detach(); // 生成线程， 并调用任务
    std::cout << " The stored value in future is " << f1.get() << endl;
    return 0;
}