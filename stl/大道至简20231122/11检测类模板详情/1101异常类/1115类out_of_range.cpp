#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
void print(vector<int> &v)
{
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " ;";
    cout << endl;
}
int main()
{
    vector<int> vi;
    int array[] = {1, 2, 3, 4, 5};
    vi.assign(array, array + 5); // 初始化 vector 向量
    print(vi);                   // 输出向量
    try
    {
        int var = vi.at(-1); // 获取某个元素
        int var2 = vi.at(0);
    }
    catch (out_of_range &oe) // 捕获异常
    {
        cout << oe.what() << endl;         // 输出异常的信息
        cout << typeid(oe).name() << endl; // 获取异常类的名称
    }
    return 0;
}