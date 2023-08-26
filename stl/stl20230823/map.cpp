#include<iostream>
#include <string>
#include <map>
using namespace std;

/**
https://blog.csdn.net/chenlong_cxy/article/details/121544974
*/
/**
map的介绍
map是关联式容器，它按照特定的次序（按照key来比较）存储键值key和值value组成的元素，使用map的迭代器遍历map中的元素，可以得到有序序列。

在map中，键值key通常用于排序和唯一地标识元素，而值value中存储与此键值key关联的内容。键值key和值value的类型可能不同，并且在map的内部，key与value通过成员类型value_type绑定在一起，并取别名为pair。

map容器中元素的键值key不能被修改，但是元素的值value可以被修改，因为map底层的二叉搜索树是根据每个元素的键值key进行构建的，而不是值value。

在内部，map中的元素总是按照键值key进行比较排序的。当不传入内部比较对象时，map中元素的键值key默认按照小于来比较。

map容器通过键值key访问单个元素的速度通常比unordered_map容器慢，但map容器允许根据顺序对元素进行直接迭代。

map容器支持下标访问符，即在[]中放入key，就可以找到与key对应的value。

map在底层是用平衡搜索树（红黑树）实现的，所以在map当中查找某个元素的时间复杂度为l o g N logNlogN。


map的定义方式
方式一： 指定key和value的类型构造一个空容器。

map<int, double> m1; //构造一个key为int类型，value为double类型的空容器

方式二： 拷贝构造某同类型容器的复制品。

map<int, double> m2(m1); //拷贝构造key为int类型，value为double类型的m1容器的复制品

方式三： 使用迭代器拷贝构造某一段内容。

map<int, double> m3(m2.begin(), m2.end()); //使用迭代器拷贝构造m2容器某段区间的复制品

方式四： 指定key和value的类型构造一个空容器，key比较方式指定为大于。

map<int, double, greater<int>> m4; //构造一个key为int类型，value为double类型的空容器，key比较方式指定为大于

map的插入
map的插入函数的函数原型如下：

pair<iterator,bool> insert (const value_type& val);
1
insert函数的参数

insert函数的参数显示是value_type类型的，实际上value_type就是pair类型的别名：

typedef pair<const Key, T> value_type;
1
因此，我们向map容器插入元素时，需要用key和value构造一个pair对象，然后再将pair对象作为参数传入insert函数。

但是这种方式会使得我们的代码变得很长，尤其是没有直接展开命名空间的情况下，因此我们最常用的是方式二。
*/

void test01() {
	map<int, string> m;
	//方式一：调用pair的构造函数，构造一个匿名对象插入
	m.insert(pair<int, string>(2, "two"));
	m.insert(pair<int, string>(1, "one"));
	m.insert(pair<int, string>(3, "three"));
	for (auto e : m)
	{
		cout << "<" << e.first << "," << e.second << ">" << " ";
	}
	cout << endl; //<1,one> <2,two> <3,three>

}
/**
方式二： 调用make_pair函数模板插入。
在库当中提供以下make_pair函数模板：

template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y)
{
	return (pair<T1, T2>(x, y));
}
1
2
3
4
5
我们只需向make_pair函数传入key和value，该函数模板会根据传入参数类型进行自动隐式推导，最终构造并返回一个对应的pair对象。

insert函数的返回值

insert函数的返回值也是一个pair对象，该pair对象中第一个成员的类型是map的迭代器类型，第二个成员的类型的一个bool类型，具体含义如下：

若待插入元素的键值key在map当中不存在，则insert函数插入成功，并返回插入后元素的迭代器和true。
若待插入元素的键值key在map当中已经存在，则insert函数插入失败，并返回map当中键值为key的元素的迭代器和false。

*/
void test02() {
	map<int, string> m;
	//方式二：调用函数模板make_pair，构造对象插入
	m.insert(make_pair(2, "two"));
	m.insert(make_pair(1, "one"));
	m.insert(make_pair(3, "three"));
	for (auto e : m)
	{
		cout << "<" << e.first << "," << e.second << ">" << " ";
	}
	cout << endl; //<1,one> <2,two> <3,three>

}
/**
map的查找
map的查找函数的函数原型如下：

iterator find (const key_type& k);

map的查找函数是根据所给key值在map当中进行查找，若找到了，则返回对应元素的迭代器，若未找到，则返回容器中最后一个元素下一个位置的正向迭代器。
*/
void test03() {

	map<int, string> m;
	m.insert(make_pair(2, "two"));
	m.insert(make_pair(1, "one"));
	m.insert(make_pair(3, "three"));
	//获取key值为2的元素的迭代器
	map<int, string>::iterator pos = m.find(2);
	if (pos != m.end())
	{
		cout << pos->second << endl; //two
	}

}
/**
map的删除
map的删除函数的函数原型如下：

//删除函数1
size_type erase (const key_type& k);
//删除函数2
void erase(iterator position);

也就是说，我们既可以根据key值删除指定元素，也可以根据迭代器删除指定元素，若是根据key值进行删除，则返回实际删除的元素个数。


*/
void test04() {

	map<int, string> m;
	m.insert(make_pair(2, "two"));
	m.insert(make_pair(1, "one"));
	m.insert(make_pair(3, "three"));
	//方式一：根据key值进行删除
	m.erase(3);
	//方式二：根据迭代器进行删除
	map<int, string>::iterator pos = m.find(2);
	if (pos != m.end())
	{
		m.erase(pos);
	}

}
/**
map的[ ]运算符重载

如果k不在map中，则先插入键值对<k, V()>，然后返回该键值对中V对象的引用。
如果k已经在map中，则返回键值为k的元素对应的V对象的引用。

*/
void test05() {
	map<int, string> m;
	m.insert(make_pair(2, "two"));
	m.insert(make_pair(1, "one"));
	m.insert(make_pair(3, "three"));
	m[2] = "dragon"; //修改key值为2的元素的value为dragon
	m[6] = "six"; //插入键值对<6, "six">
	for (auto e : m)
	{
		cout << "<" << e.first << "," << e.second << ">" << " ";
	}
	cout << endl; //<1,one> <2,dragon> <3,three> <6,six>

}
/**
map的迭代器遍历
map当中迭代器相关函数如下：

成员函数	功能
begin	获取容器中第一个元素的正向迭代器
end	获取容器中最后一个元素下一个位置的正向迭代器
rbegin	获取容器中最后一个元素的反向迭代器
rend	获取容器中第一个元素前一个位置的反向迭代器
*/
void test06() {
	map<int, string> m;
	m.insert(make_pair(2, "two"));
	m.insert(make_pair(1, "one"));
	m.insert(make_pair(3, "three"));
	//用正向迭代器进行遍历
	map<int, string>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << "<" << it->first << "," << it->second << ">" << " ";
		it++;
	}
	cout << endl; //<1,one> <2,two> <3,three>

}
/**
遍历方式二： 用反向迭代器进行遍历。
*/

void test07() {
	map<int, string> m;
	m.insert(make_pair(2, "two"));
	m.insert(make_pair(1, "one"));
	m.insert(make_pair(3, "three"));
	//用反向迭代器进行遍历
	map<int, string>::reverse_iterator rit = m.rbegin();
	while (rit != m.rend())
	{
		cout << "<" << rit->first << "," << rit->second << ">" << " ";
		rit++;
	}
	cout << endl; //<3,three> <2,two> <1,one>


}
/**
遍历方式三： 用范围for进行遍历
注意： 编译器在编译时会自动将范围for替换为迭代器的形式，因此支持了迭代器实际上就支持了范围for。
*/
void test08() {
	map<int, string> m;
	m.insert(make_pair(2, "two"));
	m.insert(make_pair(1, "one"));
	m.insert(make_pair(3, "three"));
	//用范围for进行遍历
	for (auto e : m)
	{
		cout << "<" << e.first << "," << e.second << ">" << " ";
	}
	cout << endl; //<1,one> <2,two> <3,three>

}

/**
map的其他成员函数
除了上述成员函数外，set当中还有如下几个常用的成员函数：

成员函数	功能
size	获取容器中元素的个数
empty	判断容器是否为空
clear	清空容器
swap	交换两个容器中的数据
count	获取容器中指定key值的元素个数

*/
void test09() {
	map<int, string> m;
	m.insert(make_pair(2, "two"));
	m.insert(make_pair(1, "one"));
	m.insert(make_pair(3, "three"));
	//获取容器中元素的个数
	cout << m.size() << endl; //3
	//容器中key值为2的元素个数
	cout << m.count(2) << endl; //1
	//清空容器
	m.clear();
	//容器判空
	cout << m.empty() << endl; //1
	//交换两个容器中的数据
	map<int, string> tmp;
	m.swap(tmp);

}

int main() {
	auto p = test09;
	p();
	return 0;
}