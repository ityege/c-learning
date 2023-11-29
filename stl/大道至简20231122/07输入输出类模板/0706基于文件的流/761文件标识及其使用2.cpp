#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
const string filename = "test.txt";
int main()
{
    ifstream fin;
    fin.open(filename.c_str(), ios_base::in); // 打开文件
    if (fin.is_open())
    {
        cout << "Here are the current contents of the \'" << filename << "\' :" << endl;
        cout << fin.rdbuf(); // 输出文件内容
        cout << endl;
    }
    fin.clear();
    fin.close();
    ofstream fout;
    fout.open(filename.c_str(), ios_base::out | ios_base::app);
    if (!fout.is_open())
    {
        cerr << "Can't open " << filename << " file for output. \n";
        exit(EXIT_FAILURE);
    }
    cout << "Enter new file contents (to be append):\n";
    string buffer;
    while (getline(cin, buffer) && buffer.size() > 0) // 输入整行数据
    {
        fout << buffer << endl;
    }
    fout.clear();
    fout.close(); // 关闭文件
    fin.open(filename.c_str(), ios_base::in);
    if (fin.is_open())
    {
        cout << "Here are the current contents of the \'" << filename << "\' :" << endl;
        cout << fin.rdbuf();
        cout << endl;
    }
    fin.clear();
    fin.close();
    return 0;
}