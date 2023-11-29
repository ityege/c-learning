#include <iostream>
#include <future>
using namespace std;
long job1(long arg)
{
    int tmp = 0;
    for (int id = 1; id <= arg; id++)
        tmp += id;
    return tmp;
}
int main(int argc, char *argv[])
{
    std::future<long> f1 = std::async(job1, 100);
    cout << "Thread 1 return : " << f1.get() << endl;
    cin.get(); // 等待回车键，程序退出
    return 0;
}