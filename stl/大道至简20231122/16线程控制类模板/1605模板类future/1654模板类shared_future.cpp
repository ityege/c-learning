#include <iostream>
#include <future>
using namespace std;
int job1(int arg)
{
    int x = 0;
    x = arg;
    return x;
}
int main(int argc, char *argv[])
{
    future<int> f1 = std::async(job1, 1);
    if (f1.valid())
        cout << "future 1: " << f1.get() << endl;
    else
        cout << "future 1 is not valid. " << endl;
    future<int> f2 = std::async(job1, 2);
    if (f2.valid())
        cout << "future 2: " << f2.get() << endl;
    else
        cout << "future 2 is not valid ." << endl;
    shared_future<int> f3 = std::async(job1, 3);
    shared_future<int> f4 = std::move(f1);
    if (f1.valid())
        cout << " future 1: " << f1.get() << endl;
    else
        cout << " future 1 is not valid. " << endl;
    shared_future<int> f5 = f2.share();
    if (f2.valid())
        cout << " future 2: " << f2.get() << endl;
    else
        cout << " future 2 is not valid. " << endl;
    int cnt = 3;
    cout << " future 3 : " << endl;
    while (cnt--)
    {
        cout << f3.get() << " ;" << endl;
    }
    cout << " future 4: " << f4.get() << endl;
    cout << " future 5: " << f5.get() << endl;
    return 0;
}