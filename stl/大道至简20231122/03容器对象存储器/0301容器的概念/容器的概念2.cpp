#include <iostream>
#include <valarray>
using namespace std;
template <typename T>
void printValarray(const valarray<T> &va) // 体验一下模板函数的用法
{
    for (int i = 0; i < va.size(); i++)
        cout << va[i] << " ";
    cout << endl;
}
int main()
{
    valarray<int> val(4);    // 包含 4 个元素，但未指定元素的值
    printValarray(val);      // 输出
    valarray<int> va2(3, 4); // 包含 4 个元素，其数值均为 3；
    printValarray(va2);
    int ia[] = {1, 2, 3, 4, 5, 6};                     // 定义整数型数组
    valarray<int> va3(ia, sizeof(ia) / sizeof(ia[0])); // 动态数组大小和数组 ia 的元素个数相同
    printValarray(va3);
    valarray<int> va4(ia + 1, 4); // 4 个元素,数值分别为数组 ia 的前4 个元素加1
    printValarray(va4);
    val = (va2 + va4) * va4; // 给 val 赋值
    printValarray(val);
    return 0;
}