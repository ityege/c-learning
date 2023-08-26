#include<iostream>
#include <unordered_set>
using namespace std;

/**
https://blog.csdn.net/chenlong_cxy/article/details/122277348
*/
/**
unordered_set的介绍
unordered_set是不按特定顺序存储键值的关联式容器，其允许通过键值快速的索引到对应的元素。
在unordered_set中，元素的值同时也是唯一地标识它的key。
在内部，unordered_set中的元素没有按照任何特定的顺序排序，为了能在常数范围内找到指定的key，unordered_set将相同哈希值的键值放在相同的桶中。
unordered_set容器通过key访问单个元素要比set快，但它通常在遍历元素子集的范围迭代方面效率较低。
它的迭代器至少是前向迭代器。
unordered_set的使用
unordered_set的定义方式
方式一： 构造一个某类型的空容器。

unordered_set<int> us1; //构造int类型的空容器

方式二： 拷贝构造某同类型容器的复制品。

unordered_set<int> us2(us1); //拷贝构造同类型容器us1的复制品

方式三： 使用迭代器拷贝构造某一段内容。

string str("abcedf");
unordered_set<char> us3(str.begin(), str.end()); //构造string对象某段区间的复制品


unordered_set接口的使用
unordered_set当中常用的成员函数如下：

成员函数	功能
insert	插入指定元素
erase	删除指定元素
find	查找指定元素
size	获取容器中元素的个数
empty	判断容器是否为空
clear	清空容器
swap	交换两个容器中的数据
count	获取容器中指定元素值的元素个数
unordered_set当中迭代器相关函数如下：

成员函数	功能
begin	获取容器中第一个元素的正向迭代器
end	获取容器中最后一个元素下一个位置的正向迭代器

*/

int main() {

	unordered_set<int> us;
	//插入元素（去重）
	us.insert(1);
	us.insert(4);
	us.insert(3);
	us.insert(3);
	us.insert(2);
	us.insert(2);
	us.insert(3);
	//遍历容器方式一（范围for）
	for (auto e : us)
	{
		cout << e << " ";
	}
	cout << endl; //1 4 3 2
	//删除元素方式一
	us.erase(3);
	//删除元素方式二
	unordered_set<int>::iterator pos = us.find(1); //查找值为1的元素
	if (pos != us.end())
	{
		us.erase(pos);
	}
	//遍历容器方式二（迭代器遍历）
	unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl; //4 2
	//容器中值为2的元素个数
	cout << us.count(2) << endl; //1
	//容器大小
	cout << us.size() << endl; //2
	//清空容器
	us.clear();
	//容器判空
	cout << us.empty() << endl; //1
	//交换两个容器的数据
	unordered_set<int> tmp{ 11, 22, 33, 44 };
	us.swap(tmp);
	for (auto e : us)
	{
		cout << e << " ";
	}
	cout << endl; //11 22 33 44

	return 0;
}