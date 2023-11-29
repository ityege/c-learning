#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cerr << "Usage: " << argv[0] << " filename[s]\n"; // 输出程序的名称
        exit(EXIT_FAILURE);
    }
    else
    {
        int count = argc;
        for (int i = 0; i < count; i++)
        {
            cout << "Paramter: " << argv[i] << endl; // 输出程序的参数
        }
    }
    return 0;
}