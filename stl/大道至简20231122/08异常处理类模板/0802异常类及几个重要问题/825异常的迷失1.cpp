#include <exception>
#include <iostream>
using namespace std;
void myQuit()
{
    cout << "Terminating test because of uncaught exception. " << endl;
    exit(5);
}
int main()
{
    terminate_handler oldHandler = set_terminate(myQuit);
    int switch_K;
    logic_error a("Exception: logic_error. ");
    runtime_error b("Exception: runtime_error. ");
    cout << ". . . . . Please Input 0 for exit. . . . . . " << endl;
loop:
    cout << ". . . . . Please Input 1 or else number: . . . . . " << endl;
    try
    {
        cin >> switch_K;
        if (switch_K == 0)
        {
            goto loop2;
        }
        switch (switch_K)
        {
        case 1:
            throw a;
            break;
        default:
            throw b;
            break;
        }
    }
    catch (logic_error &e)
    {
        cout << e.what() << endl;
    }
    catch (...) // 注意：catch()函数的参数为“. . . ”
    {
        terminate();
    }
    goto loop;
loop2:
    return 0;
}