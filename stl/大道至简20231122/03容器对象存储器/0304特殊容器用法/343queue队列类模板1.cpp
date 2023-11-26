#pragma warning(disable : 4786)
#include <iostream>
#include <queue>
#include <string>
#include <list>
#include <assert.h>
using namespace std;
int main()
{
    queue<string, list<string>> q1; // 使用 list 型容器
    q1.push("Haidian District. ");
    cout << "\"Haidian District. \" are pushed into the queue. " << endl;
    q1.push("Chaoyang District. ");
    cout << "\"Chaoyang District. \" are pushed into the queue. " << endl;
    q1.push("Xuanwu District. ");
    cout << "\"Xuanwu District. \" are pushed into the queue. " << endl;
    q1.push("Xicheng District. ");
    cout << "\"Xicheng District. \" are pushed into the queue. " << endl;
    assert(q1.size() == 4);                     // 断言
    assert(q1.front() == "Haidian District. "); // 断言
    cout << "The Elements are poped from the stack by order. " << endl;
    while (q1.size())
    {
        cout << " " << q1.front() << endl;
        q1.pop(); // 取出缓冲区中的元素
    }
    return 0;
}