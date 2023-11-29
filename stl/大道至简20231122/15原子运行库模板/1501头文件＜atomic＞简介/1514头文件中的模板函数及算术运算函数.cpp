#include <iostream>
#include <atomic>
using namespace std;
int main(int argc, char *argv[])
{
    cout << "Atomic operation Example :" << endl;
    atomic<int> aa(0);
    cout << "原子类型对象 aa 数值(构造赋值)： " << aa.load() << endl;
    atomic_init(&aa, 50);
    cout << "原子类型对象 aa 数值(init)： " << aa.load() << endl;
    aa.store(100);
    cout << "原子类型对象 aa 数值(store)： " << aa.load() << endl;
    atomic_fetch_add(&aa, 150);
    cout << "原子类型对象 aa 数值( +150)： " << aa.load() << endl;
    bool y = atomic_is_lock_free(&aa);
    cout << "aa is lock free： " << y << endl;
    cin.get();
    atomic<int> bb(1), cc;
    cout << "原子类型对象 bb 数值(构造赋值)： " << bb.load() << endl;
    cc.store(aa.load());
    atomic_exchange(&aa, bb.load());
    atomic_exchange(&bb, cc.load());
    cout << "原子类型对象 aa ,bb 数值(交换之后)： " << aa.load() << "," << bb.load() << endl;
    cin.get();
    int dd = 90;
    bool res = 0;
    res = atomic_compare_exchange_weak(&aa, &dd, 5);
    cout << "The first : compare_exchange_weak(aa,dd):" << res << endl
         << endl;
    cout << "原子类型对象 aa ：" << aa.load() << endl;
    cout << "原子类型对象 dd ：" << dd << endl;
    res = atomic_compare_exchange_weak(&aa, &dd, 5);
    cout << "The second : compare_exchange_weak(aa,dd):" << res << endl
         << endl;
    cout << "原子类型对象 aa ：" << aa.load() << endl;
    cout << "原子类型对象 dd ：" << dd << endl;
    cin.get();
    return 0;
}