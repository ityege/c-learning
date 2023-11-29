#include <exception>
#include <iostream>
using namespace std;

void myUnexpected()
{
    cout << "myUnexpected() is done. " << endl;
    throw bad_exception();
    exit(5); // 不再执行
}

int main()
{
    set_terminate(myUnexpected); // 设置终止处理程序
    int switch_K;
    runtime_error a("Exception: runtime_error.");
    cout << ". . . . . Please Input 0 for exit. . . . . . " << endl;

loop:
    cout << ". . . . . Please Input 1 or 2: . . . . . " << endl;
    try
    {
        cin >> switch_K;
        if (!switch_K)
        {
            goto loop2;
        }
        switch (switch_K)
        {
        case 1:
            throw a;
            break;
        case 2:
            throw bad_exception(); // 抛出 bad_exception 异常
            break;
        }
    }
    catch (const runtime_error &e)
    {
        cout << "catch: " << e.what() << endl;
    }
    catch (const bad_exception &e)
    {
        cout << "catch: " << e.what() << endl;
        exit(0);
    }

    goto loop;

loop2:
    return 0;
}