#include <iostream>
using namespace std;
int Factor(int n)
{
    int answer = 0;
    if (n == 1) // 递归结束条件
        return (1);
    answer = Factor(n - 1) * n; // 函数的递归调用
    return answer;
}
int main()
{
    int n = 5;
    int result = 0;
    result = Factor(n);                                   // 求整数 5 的阶乘
    cout << "5! = 5x4x3x2x1 = " << result << " " << endl; // 输出计算结果
    cin.get();                                            // 等待程序退出
    return 0;
}