#include<iostream>
#include <string>
#include <unordered_map>
using namespace std;

/**
https://blog.csdn.net/chenlong_cxy/article/details/122277348
*/
/**
unordered_map的介绍
unordered_map是存储<key, value>键值对的关联式容器，其允许通过key值快速的索引到与其对应是value。
在unordered_map中，键值通常用于唯一地标识元素，而映射值是一个对象，其内容与此键关联。键和映射值的类型可能不同。
在内部，unordered_map没有对<key, value>按照任何特定的顺序排序，为了能在常数范围内找到key所对应的value，unordered_map将相同哈希值的键值对放在相同的桶中。
unordered_map容器通过key访问单个元素要比map快，但它通常在遍历元素子集的范围迭代方面效率较低。
unordered_map实现了直接访问操作符（operator[]），它允许使用key作为参数直接访问value。
它的迭代器至少是前向迭代器。
unordered_map的使用
unordered_map的定义方式
方式一： 指定key和value的类型构造一个空容器。

unordered_map<int, double> um1; //构造一个key为int类型，value为double类型的空容器

方式二： 拷贝构造某同类型容器的复制品。

unordered_map<int, double> um2(um1); //拷贝构造同类型容器um1的复制品

方式三： 使用迭代器拷贝构造某一段内容。

unordered_map<int, double> um3(um2.begin(), um2.end()); //使用迭代器拷贝构造um2容器某段区间的复制品

unordered_map接口的使用
unordered_map当中常用的成员函数如下：

成员函数	功能
insert	插入键值对
erase	删除指定key值的键值对
find	查找指定key值的键值对
size	获取容器中元素的个数
empty	判断容器是否为空
clear	清空容器
swap	交换两个容器中的数据
count	获取容器中指定key值的元素个数
除了上述的成员函数之外，unordered_map容器当中还实现了[ ]运算符重载函数，该重载函数的功能非常强大：[key]

若当前容器中已有键值为key的键值对，则返回该键值对value的引用。
若当前容器中没有键值为key的键值对，则先插入键值对<key, value()>，然后再返回该键值对中value的引用。
unordered_map当中迭代器相关函数如下：

成员函数	功能
begin	获取容器中第一个元素的正向迭代器
end	获取容器中最后一个元素下一个位置的正向迭代器

*/

int main() {
	unordered_map<int, string> um;
	//插入键值对方式一：构造匿名对象插入
	um.insert(pair<int, string>(1, "one"));
	um.insert(pair<int, string>(2, "two"));
	um.insert(pair<int, string>(3, "three"));
	//遍历方式一：范围for
	for (auto e : um)
	{
		cout << e.first << "->" << e.second << " ";
	}
	cout << endl; //1->one 2->two 3->three
	//插入键值对方式二：调用make_pair函数模板插入
	um.insert(make_pair(4, "four"));
	um.insert(make_pair(5, "five"));
	um.insert(make_pair(6, "six"));
	//遍历方式二：迭代器遍历
	unordered_map<int, string>::iterator it = um.begin();
	while (it != um.end())
	{
		cout << it->first << "->" << it->second << " ";
		it++;
	}
	cout << endl; //1->one 2->two 3->three 4->four 5->five 6->six
	//插入键值对方式三：利用[]运算符重载函数进行插入（常用）
	um[7] = "seven";
	um[8] = "eight";
	um[9] = "nine";
	for (auto e : um)
	{
		cout << e.first << "->" << e.second << " ";
	}
	cout << endl; //9->nine 1->one 2->two 3->three 4->four 5->five 6->six 7->seven 8->eight
	//删除键值对方式一：根据key值删除
	um.erase(5);
	//删除键值对方式二：根据迭代器删除
	unordered_map<int, string>::iterator pos = um.find(7); //查找键值为7的键值对
	if (pos != um.end())
	{
		um.erase(pos);
	}
	for (auto e : um)
	{
		cout << e.first << "->" << e.second << " ";
	}
	cout << endl; //9->nine 1->one 2->two 3->three 4->four 6->six 8->eight
	//修改键值对方式一：通过find获得迭代器，通过迭代器修改
	pos = um.find(1);
	if (pos != um.end())
	{
		pos->second = "one/first";
	}
	//修改键值对方式二：利用[]运算符重载函数进行修改（常用）
	um[2] = "two/second";
	for (auto e : um)
	{
		cout << e.first << "->" << e.second << " ";
	}
	cout << endl; //9->nine 1->one/first 2->two/second 3->three 4->four 6->six 8->eight
	//容器中key值为3的键值对的个数
	cout << um.count(3) << endl;
	//容器的大小
	cout << um.size() << endl;
	//清空容器
	um.clear();
	//容器判空
	cout << um.empty() << endl;
	//交换两个容器的数据
	unordered_map<int, string> tmp{ { 2021, "before" }, { 2023, "now" } };
	um.swap(tmp);
	for (auto e : um)
	{
		cout << e.first << "->" << e.second << " ";
	}
	cout << endl; //2021->before 2023->now

	return 0;
}