#include<iostream>
#include <string>
#include <map>
using namespace std;

/**
https://blog.csdn.net/chenlong_cxy/article/details/121544974
*/
/**
multimap
multimap容器与map容器的底层实现一样，也都是平衡搜索树（红黑树），其次，multimap容器和map容器所提供的成员函数的接口都是基本一致的，这里也就不再列举了，multimap容器和map容器的区别与multiset容器和set容器的区别一样，multimap允许键值冗余，即multimap容器当中存储的元素是可以重复的。
由于multimap容器允许键值冗余，因此两个容器中成员函数find和count的意义也有所不同：

成员函数find	功能
map对象	返回值为键值为key的元素的迭代器
multimap对象	返回底层搜索树中序的第一个键值为key的元素的迭代器
成员函数count	功能
map对象	键值为key的元素存在则返回1，不存在则返回0（find成员函数可代替）
multimap对象	返回键值为key的元素个数（find成员函数不可代替）

其次，由于multimap容器允许键值冗余，调用[ ]运算符重载函数时，应该返回键值为key的哪一个元素的value的引用存在歧义，因此在multimap容器当中没有实现[ ]运算符重载函数。
*/
void test01() {
	multimap<int, string> mm;
	//插入元素（允许重复）
	mm.insert(make_pair(2, "two"));
	mm.insert(make_pair(2, "double"));
	mm.insert(make_pair(1, "one"));
	mm.insert(make_pair(3, "three"));
	for (auto e : mm)
	{
		cout << "<" << e.first << "," << e.second << ">" << " ";
	}
	cout << endl; //<1,one> <2,two> <2,double> <3,three>
}
int main() {
	auto p = test01;
	p();
	return 0;
}