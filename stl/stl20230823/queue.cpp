#include<iostream>
#include<queue>
#include<list>
using namespace std;

/**
https://blog.csdn.net/chenlong_cxy/article/details/120077784
*/

/**
queue
队列是一种容器适配器，专门用在具有先进先出操作的上下文环境中，其只能从容器的一端插入元素，另一端提取元素。
queue的定义方式
方式一： 使用默认的适配器定义队列。

queue<int> q1;
1
方式二： 使用特定的适配器定义队列。

queue<int, vector<int>> q2;
queue<int, list<int>> q3;
1
2
注意： 如果没有为queue指定特定的底层容器，默认情况下使用deque。

queue的使用
queue当中常用的成员函数如下：

成员函数	功能
empty	判断队列是否为空
size	获取队列中有效元素个数
front	获取队头元素
back	获取队尾元素
push	队尾入队列
pop	队头出队列
swap	交换两个队列中的数据
*/
int main() {
	queue<int, list<int>> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.size() << endl; //4
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl; //1 2 3 4

	return 0;
}