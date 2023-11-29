#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
void myprint(vector<T> &vv) // 输出 vector
{
    typename vector<T>::iterator it; // Add 'typename' before vector<T>::iterator
    for (it = vv.begin(); it != vv.end(); it++)
    {
        cout << *it << " , ";
    }
    cout << endl;
}
void myprintA(allocator<int>::pointer vv, size_t num) // 输出配置器
{
    int i;
    for (i = 0; i < num; i++)
    {
        cout << vv[i] << " , ";
    }
    cout << endl;
}
int main(int argc, char *argv[])
{
    cout << "allocator test. " << endl;
    vector<int> v1;
    vector<int>::iterator v1It;
    vector<int>::allocator_type v1A;
    allocator<int>::const_pointer cv1P;
    allocator<int>::pointer v1p;
    allocator<int> AL;
    int i;
    for (i = 1; i <= 8; i++)
    {
        v1.push_back(i); // 初始化 vector
    }
    cout << "The Original Vector v1: " << endl;
    myprint(v1);
    int kk = 6;
    cv1P = v1A.address(*find(v1.begin(), v1.end(), kk)); // 使用 address
    cout << "find an element by address. " << endl;
    cout << *cv1P << endl;
    v1p = AL.allocate(10); // 分配内存
    int ar[6] = {0, 9, 8, 7, 6, 5};
    for (i = 0; i < 6; i++)
        v1p[i] = ar[i];
    cout << "array v1p:" << endl;
    myprintA(v1p, 6);
    AL.deallocate(v1p, 10); // 释放内存
    kk = 6;
    int kb = 12;
    v1p = v1A.address(*find(v1.begin(), v1.end(), kk));
    v1A.destroy(v1p);
    v1A.construct(v1p, kb); // 修改数据
    cout << "destroy and construct :" << endl;
    myprint(v1);
    allocator<int>::size_type size;
    size = v1A.max_size(); // max_size
    cout << "max_size : " << size << endl;
    return 0;
}