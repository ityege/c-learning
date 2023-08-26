#include<iostream>
#include <unordered_set>
using namespace std;

/**
https://blog.csdn.net/chenlong_cxy/article/details/122277348
*/
/**

unordered_multiset容器与unordered_set容器的底层数据结构是一样的，都是哈希表，其次，它们所提供的成员函数的接口都是基本一致的，这里就不再列举了，这两种容器唯一的区别就是，unordered_multiset容器允许键值冗余，即unordered_multiset容器当中存储的元素是可以重复的。

由于unordered_multiset容器允许键值冗余，因此该容器中成员函数find和count的意义与unordered_set容器中的也有所不同：

成员函数find	功能
unordered_set容器	返回键值为val的元素的迭代器
unordered_multiset容器	返回底层哈希表中第一个找到的键值为val的元素的迭代器
成员函数count	功能
unordered_set容器	键值为val的元素存在则返回1，不存在则返回0（find成员函数可替代）
unordered_multiset容器	返回键值为val的元素个数（find成员函数不可替代）

*/

int main() {

	unordered_multiset<int> ums;
	//插入元素（允许重复）
	ums.insert(1);
	ums.insert(4);
	ums.insert(3);
	ums.insert(3);
	ums.insert(2);
	ums.insert(2);
	ums.insert(3);
	for (auto e : ums)
	{
		cout << e << " ";
	}
	cout << endl; //1 4 3 3 3 2 2

	return 0;
}