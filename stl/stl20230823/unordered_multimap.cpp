#include<iostream>
#include <string>
#include <unordered_map>
using namespace std;

/**
https://blog.csdn.net/chenlong_cxy/article/details/122277348
*/
/**
unordered_multimap容器与unordered_map容器的底层数据结构是一样的，都是哈希表，其次，它们所提供的成员函数的接口都是基本一致的，这里就不再列举了，这两种容器唯一的区别就是，unordered_multimap容器允许键值冗余，即unordered_multimap容器当中存储的键值对的key值是可以重复的。

由于unordered_multimap容器允许键值对的键值冗余，因此该容器中成员函数find和count的意义与unordered_map容器中的也有所不同：

成员函数find	功能
unordered_map容器	返回键值为key的键值对的迭代器
unordered_multimap容器	返回底层哈希表中第一个找到的键值为key的键值对的迭代器
成员函数count	功能
unordered_map容器	键值为key的键值对存在则返回1，不存在则返回0（find成员函数可替代）
unordered_multimap容器	返回键值为key的键值对的个数（find成员函数不可替代）
其次，由于unordered_multimap容器允许键值对的键值冗余，调用[ ]运算符重载函数时，应该返回键值为key的哪一个键值对的value的引用存在歧义，因此在unordered_multimap容器当中没有实现[ ]运算符重载函数。


*/

int main() {
	unordered_multimap<int, string> umm;
	//插入键值对（允许键值重复）
	umm.insert(make_pair(2023, "吃饭"));
	umm.insert(make_pair(2023, "睡觉"));
	umm.insert(make_pair(2023, "敲代码"));
	for (auto e : umm)
	{
		cout << e.first << "->" << e.second << " ";
	}
	cout << endl; //2023->吃饭 2023->睡觉 2023->敲代码

	return 0;
}