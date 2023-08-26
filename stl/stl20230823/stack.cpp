#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/**
https://blog.csdn.net/chenlong_cxy/article/details/120077784
*/
/**
stack
stack是一种容器适配器，专门用在具有后进先出操作的上下文环境中，其只能从容器的一端进行元素的插入与提取操作。
stack的定义方式
方式一： 使用默认的适配器定义栈。

stack<int> st1;

方式二： 使用特定的适配器定义栈。

stack<int, vector<int>> st2;
stack<int, list<int>> st3;

注意： 如果没有为stack指定特定的底层容器，默认情况下使用deque。

stack的使用
stack当中常用的成员函数如下：

成员函数	功能
empty	判断栈是否为空
size	获取栈中有效元素个数
top	获取栈顶元素
push	元素入栈
pop	元素出栈
swap	交换两个栈中的数据

*/
int main() {
	stack<int, vector<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout << st.size() << endl; //4
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl; //4 3 2 1

	return 0;
}