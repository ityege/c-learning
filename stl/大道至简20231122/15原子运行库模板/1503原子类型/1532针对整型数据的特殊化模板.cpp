#include <iostream>
#include <atomic>
using namespace std;
int main(int argc, char *argv[])
{
    atomic<long> a11(-1);
    atomic<long> a1;
    cout << "a1: " << a1.load(memory_order_relaxed) << endl;
    cout << "a11: " << a11.load(memory_order_relaxed) << endl;
    bool y, y1;
    y = a1.is_lock_free();
    y1 = a11.is_lock_free();
    cout << "a1 whether is lock free: " << y << endl;
    cout << "a11 whether is lock free: " << y1 << endl;
    a1.store(100, memory_order_relaxed);
    a11.store(101, memory_order_relaxed);
    cout << "a1: " << a1.load(memory_order_relaxed) << endl;
    cout << "a11: " << a11.load(memory_order_relaxed) << endl;
    a1.exchange(20);
    a11.exchange(30);
    cout << "a1: " << a1.load(memory_order_relaxed) << endl;
    cout << "a11: " << a11.load(memory_order_relaxed) << endl;
    a1.fetch_add(20);
    a11.fetch_sub(5);
    cout << "a1: " << a1.load(memory_order_relaxed) << endl;
    cout << "a11: " << a11.load(memory_order_relaxed) << endl;
    cin.get();
    // y1 = a1.compare_exchange_weak((long &)a11._My_val, 1000);
    // cout << "compare(weak): " << y1 << endl;
    // cout << "a1: " << a1.load(memory_order_relaxed) << endl;
    // cout << "a11: " << a11.load(memory_order_relaxed) << endl;
    // cin.get();
    // y1 = a1.compare_exchange_strong((long &)a11._My_val, 1000);
    // cout << "compare(strong): " << y1 << endl;
    // cout << "a1: " << a1.load(memory_order_relaxed) << endl;
    // cout << "a11: " << a11.load(memory_order_relaxed) << endl;
    // cin.get();
    a1++;
    a11 += a1;
    cout << "a1 ++ : " << a1.load(memory_order_relaxed) << endl;
    cout << "a11 + = a1: " << a11.load(memory_order_relaxed) << endl;
    a1 ^= 2;
    a11 |= 10;
    cout << "a1^ =2: " << a1.load(memory_order_relaxed) << endl;
    cout << "a11|=10: " << a11.load(memory_order_relaxed) << endl;
    cin.get();
    return 0;
}