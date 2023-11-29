#include <iostream> // std::cout
#include <atomic>   // std::atomic_flag
using namespace std;

int main()
{
    atomic_flag lock = ATOMIC_FLAG_INIT;
    bool set = atomic_flag_test_and_set(&lock);
    cout << "锁在测试设置之前是否被设置: " << set << endl;
    atomic_flag_clear(&lock);
    cin.get();
    return 0;
}