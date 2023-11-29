#include <iostream>
#include <atomic>
using namespace std;
int main(int argc, char *argv[])
{
    int dim[10] = {1, 2, 3, 4};
    atomic<int *> a1;
    atomic<int *> a11(dim);
    cout << "a11: " << a11.load(memory_order_relaxed) << endl;
    a11.fetch_add(2); // 向前移动指针
    cout << " * (a11 +2): " << *a11.load(memory_order_relaxed) << endl;
    a1.store((int *)0xffffe);
    cout << "a1: " << a1.load(memory_order_relaxed) << endl;
    a1.exchange((int *)0x897543);
    cout << "a1: " << a1.load(memory_order_relaxed) << endl;
    a1++;
    a11++;
    cout << "a1 ++ : " << a1.load(memory_order_relaxed) << endl;
    cout << " * (a11 ++ ): " << *a11.load(memory_order_relaxed) << endl;
    cin.get();
    return 0;
}