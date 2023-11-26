#include <iostream>
#include <vector>
using namespace std;
struct ST
{ // 定义结构体类型
    int id;
    double db;
};
void Origin(int num, vector<ST> &vt) // 定义初始化函数
{
    int m = num;
    ST temp;
    for (int i = 0; i < m; i++)
    {
        temp.id = i + 1;
        temp.db = (i + 1) * 10;
        vt.push_back(temp); // 初始化向量
    }
}
int main()
{
    ST tmp;
    vector<ST> myvt;                   // 定义向量
    Origin(5, myvt);                   // 初始化向量
    int size = myvt.size();            // 统计向量中元素个数
    cout << " size: " << size << endl; // 输出向量个数
    while (!myvt.empty())              // 判断向量是否为空
    {
        tmp = myvt.back(); // 如果非空， 输出其末尾元素， 并弹出
        cout << " id " << tmp.id << ", db: " << tmp.db << endl;
        myvt.pop_back();
    }
    return 0;
}