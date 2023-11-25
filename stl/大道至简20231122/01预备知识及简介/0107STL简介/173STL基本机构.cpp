#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> st; // 定义堆栈对象
    for (int i = 0; i < 10; i++)
        st.push(i); // 将数据压入堆栈
    while (!st.empty())
    {
        cout << st.top() << " "; // 弹出堆栈的第一个元素，并输出
        st.pop();                // 弹出堆栈元素
    }
    cout << endl;
    cin.get(); // 任意键退出
    return 0;
}