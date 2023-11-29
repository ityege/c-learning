#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void printfile(string filename)
{
    ifstream fin(filename.c_str());
    cout << fin.rdbuf(); // 输出缓冲区内容
    fin.seekg(0);        // 文件指针放至文件头
    cout << fin.rdbuf(); // 输出文件内容
}
int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        cout << "The contents of file " << argv[i] << " is below. \n"
             << endl;
        printfile(string(argv[i]));
    }
    return 0;
}