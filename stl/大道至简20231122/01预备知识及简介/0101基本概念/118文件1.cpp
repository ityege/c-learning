#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f1;
    ofstream f2;
    char filename1[256];
    char filename2[256];
    char content[1024];
    cout << "请输入文件名(源):"; // 输入源文件名
    cin >> filename1;
    cout << "请输入文件名(目的):"; // 输入目标文件名
    cin >> filename2;
    f1.open(filename1, ios::in);  // 打开源文件，用于读取
    f2.open(filename2, ios::out); // 打开目标文件，用于写入

    while (f1.good())
    {
        f1.getline(content, 1024);
        f2 << content << endl; // 将数据写入目标文件
    }
    f1.close();
    f2.close();
    return 0;
}