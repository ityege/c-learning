#include<iostream>
#include<set>

using namespace std;
/**
https://blog.csdn.net/chenlong_cxy/article/details/121544974
*/
/**
multiset容器与set容器的底层实现一样，都是平衡搜索树（红黑树），其次，multiset容器和set容器所提供的成员函数的接口都是基本一致的，这里就不再列举了，multiset容器和set容器的唯一区别就是，multiset允许键值冗余，即multiset容器当中存储的元素是可以重复的。

由于multiset容器允许键值冗余，因此两个容器中成员函数find和count的意义也有所不同：

成员函数find	功能
set对象	返回值为val的元素的迭代器
multiset对象	返回底层搜索树中序的第一个值为val的元素的迭代器
成员函数count	功能
set对象	值为val的元素存在则返回1，不存在则返回0（find成员函数可代替）
multiset对象	返回值为val的元素个数（find成员函数不可代替）
*/
int main() {

	multiset<int> ms;
	//插入元素（允许重复）
	ms.insert(1);
	ms.insert(4);
	ms.insert(3);
	ms.insert(3);
	ms.insert(2);
	ms.insert(2);
	ms.insert(3);
	for (auto e : ms)
	{
		cout << e << " ";
	}
	cout << endl; //1 2 2 3 3 3 4
	return 0;
}