#include<iostream>
#include<queue>
using namespace std;

/**
https://blog.csdn.net/chenlong_cxy/article/details/120267391
*/
/**
priority_queue的介绍
优先级队列默认使用vector作为其底层存储数据的容器，在vector上又使用了堆算法将vector中的元素构造成堆的结构，因此priority_queue就是堆，所有需要用到堆的位置，都可以考虑使用priority_queue。

注意： 默认情况下priority_queue是大堆。

priority_queue的定义方式
方式一： 使用vector作为底层容器，内部构造大堆结构。

priority_queue<int, vector<int>, less<int>> q1;

方式二： 使用vector作为底层容器，内部构造小堆结构。

priority_queue<int, vector<int>, greater<int>> q2;

方式三： 不指定底层容器和内部需要构造的堆结构。

priority_queue<int> q;

注意： 此时默认使用vector作为底层容器，内部默认构造大堆结构。

priority_queue各个接口的使用
priority_queue的各个成员函数及其功能如下：

成员函数	功能
push	插入元素到队尾（并排序）
pop	弹出队头元素（堆顶元素）
top	访问队头元素（堆顶元素）
size	获取队列中有效元素个数
empty	判断队列是否为空
swap	交换两个队列的内容

*/
int main() {
	priority_queue<int> q;
	q.push(3);
	q.push(6);
	q.push(0);
	q.push(2);
	q.push(9);
	q.push(8);
	q.push(1);
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl; //9 8 6 3 2 1 0

	return 0;
}