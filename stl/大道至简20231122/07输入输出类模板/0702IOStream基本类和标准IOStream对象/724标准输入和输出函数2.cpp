#include <iostream>
#include <fstream>
#include <istream>
#include <string>
using namespace std;

int main()
{
    char chardim[30];
    char ch[6];
    fstream fio;
    fio.open("./test5.txt", ios::in | ios::out); // 打开文件
    int cnt = 10;
    int gcnt = 0;
    fio.read(chardim, cnt); // 从流中读取 cnt 个字符
    if (fio.good())
    {
        cout << "Read success!" << endl;
    }
    gcnt = fio.gcount(); // 统计个数
    string buf;
    buf.assign(chardim, 10); // 存入字符串
    cout << "The input chars from file test5.txt are: " << buf << endl;
    cout << "The count of the last read function: " << gcnt << endl;
    fio.ignore(3, EOF);                // 忽略
    buf.erase(buf.begin(), buf.end()); // 清除
    fio.read(ch, 5);                   // 读字符
    if (fio.good())
    {
        cout << "Read success!" << endl;
    }
    buf.assign(ch, 5);
    cout << "Secondly The input chars from file test5.txt are: " << buf << endl;
    char chc = fio.peek();
    if (chc == EOF)
    {
        cout << "file eof reach. " << endl;
    }
    else
    {
        cout << "some char has existed in file. " << endl;
    }
    fio.unget();
    fio.read(ch, 5);
    if (fio.good())
    {
        cout << "Read success!" << endl;
    }
    buf.assign(ch, 5);
    cout << "Thirdly The input chars from file test5.txt are: " << buf << endl;
    fio.flush();
    fio.close();
    return 0;
}