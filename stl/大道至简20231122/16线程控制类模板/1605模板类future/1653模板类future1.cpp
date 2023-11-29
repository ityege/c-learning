#include <iostream>
#include <thread>
// #include <mutex>
#include <future>
#include <chrono>
using namespace std;
int job1(int arg) // 线程函数 1
{
    int x;
    x = arg;
    return x;
}
int job2(int arg) // 线程函数 2
{
    int y;
    y = arg;
    return y;
}
int job3(int arg) // 线程函数 3
{
    int y = 0;
    y = arg;
    return y;
}
int job4(int arg) // 线程函数 4
{
    int z = 0;
    z = arg;
    return z;
}
int job5(int arg) // 线程函数 5
{
    int z = 0;
    z = arg;
    this_thread::sleep_for(chrono::seconds(8));
    return z;
}
int main(int argc, char *argv[])
{
    int temp = -1;
    std::future<int> f1 = std::async(job1, 1); // wait_for ()
    while (f1.wait_for(chrono::milliseconds(100)) == std::future_status::timeout)
        std::cout << '.';
    temp = f1.get();
    cout << " future one: " << temp << endl;
    std::future<int> f2 = std::async(job2, 2);
    temp = f2.get(); // get ()
    cout << " future two: " << temp << endl;
    std::shared_future<int> shf = f2.share(); // share ()
    cout << "future shared(two): " << shf.get() << endl;
    std::future<int> f3 = std::move(f1);
    if (f3.valid()) // valid()
        cout << "future three( move(one)). " << f3.get() << endl;
    else
        cout << "future three( move(one)) is not valid : " << endl;
    std::future<int> f4 = std::async(job3, 4);
    std::future<int> f5 = std::move(f4);
    if (f5.valid())
        cout << "future four: " << f5.get() << endl;
    else
        cout << "future five( move(four)) is not valid : " << endl;
    std::future<int> f6 = std::async(job4, 6);
    std::cout << "waiting. . . \n";
    f6.wait(); // wait()
    cout << "future six: " << f6.get() << endl;
    if (f6.valid())
        cout << "futrue six is valid" << endl;
    else
        cout << "futrue six is not valid" << endl;
    std::future<int> f7 = std::async(job5, 7);
    auto fts = f7.wait_until(chrono::system_clock::now() + chrono::seconds(5));
    // wait_until
    if (fts == future_status::timeout)
    {
        cout << " future seven . . . timeout. " << endl;
    }
    else if (fts == future_status::ready)
    {
        cout << " future seven . . . ready. " << endl;
    }
    else
    {
        cout << " future seven . . . deferred. " << endl;
    }
    if (f7.valid())
    {
        cout << " future seven is valid. its value : " << f7.get() << endl;
    }
    else
    {
        cout << " future seven is not valid" << endl;
    }
    return 0;
}