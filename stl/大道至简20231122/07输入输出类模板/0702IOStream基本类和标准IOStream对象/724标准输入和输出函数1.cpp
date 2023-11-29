#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char chdim[7] = {0, 0, 0, 0, 0, 0, 0};
    cout << "int cin. get(): " << endl;
    cin.get(chdim, 6, '\n'); // 获取输入
    cout.write(chdim, 6);    // 输出
    cout << endl;
    cin.get(); // 获取输入
    cout << "cin. get(char ch) : " << endl;
    char ch;
    cin.get(ch);
    cout.put(ch); // 输出该字符
    cout << endl;
    cin.get();
    cout << "cin. getline(char* ch,nCount,\\n)" << endl;
    cin.getline(chdim, 6, '\n'); // 获取该行数据
    cout.write(chdim, 6);        // 输出该行数据
    cout << endl;
    char dim[20];
    fstream fio;                        // 流
    fio.open(". \\test. txt", ios::in); // 打开文件
    fio.read(dim, 20);                  // 从文件中获取
    cout.write(dim, 20);                // 输出获取的数据
    fio.close();                        // 关闭数据流
    cout << endl;
    return 0;
}