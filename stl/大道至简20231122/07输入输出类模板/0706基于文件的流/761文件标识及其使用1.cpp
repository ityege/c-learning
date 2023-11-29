#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string filename;
    cout << "Enter filename for new file: ";
    cin >> filename;
    ofstream fout(filename.c_str());  // 将流与文件关联
    fout << "For your eyes only! \n"; // 输出至文件
    cout << "Enter your secret number: ";
    float secret;
    cin >> secret;
    fout << "Your secret number is " << secret << endl; // 将变量 secret 输出至文件
    fout.clear();                                       // 清除文件状态标识
    fout.close();
    ifstream fin(filename.c_str());
    cout << "Here are the contents of " << filename.c_str() << ": \n";
    char ch;
    while (fin.get(ch)) // 读取文件的一种形式
    {
        cout << ch;
    }
    cout << "Done! \n";
    fin.clear();
    fin.close();
    cout << "Other file read test:\n";
    ifstream fin2(filename.c_str());
    cout << "Here are the contents of " << filename.c_str() << ": \n";
    cout << fin2.rdbuf(); // 读文件的另一种形式
    fin2.clear();
    fin2.close();
    return 0;
}