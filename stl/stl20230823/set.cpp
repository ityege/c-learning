#include<iostream>
#include<set>
using namespace std;

/**
https://blog.csdn.net/chenlong_cxy/article/details/121544974
*/
/**
set的介绍
set是按照一定次序存储元素的容器，使用set的迭代器遍历set中的元素，可以得到有序序列。

set当中存储元素的value都是唯一的，不可以重复，因此可以使用set进行去重。

与map/multimap不同，map/multimap中存储的是真正的键值对<key, value>，set中只放value，但在底层实际存放的是由<value, value>构成的键值对，因此在set容器中插入元素时，只需要插入value即可，不需要构造键值对。

set中的元素不能被修改，因为set在底层是用二叉搜索树来实现的，若是对二叉搜索树当中某个结点的值进行了修改，那么这棵树将不再是二叉搜索树。

在内部，set中的元素总是按照其内部比较对象所指示的特定严格弱排序准则进行排序。当不传入内部比较对象时，set中的元素默认按照小于来比较。

set容器通过key访问单个元素的速度通常比unordered_set容器慢，但set容器允许根据顺序对元素进行直接迭代。

set在底层是用平衡搜索树（红黑树）实现的，所以在set当中查找某个元素的时间复杂度为l o g N logNlogN。

set的定义方式
方式一： 构造一个某类型的空容器。

set<int> s1; //构造int类型的空容器

方式二： 拷贝构造某类型set容器的复制品。

set<int> s2(s1); //拷贝构造int类型s1容器的复制品

方式三： 使用迭代器拷贝构造某一段内容。

string str("abcdef");
set<char> s3(str.begin(), str.end()); //构造string对象某段区间的复制品

方式四： 构造一个某类型的空容器，比较方式指定为大于。

set < int, greater<int>> s4; //构造int类型的空容器，比较方式指定为大于
1
set的使用
set当中常用的成员函数如下：

成员函数	功能
insert	插入指定元素
erase	删除指定元素
find	查找指定元素
size	获取容器中元素的个数
empty	判断容器是否为空
clear	清空容器
swap	交换两个容器中的数据
count	获取容器中指定元素值的元素个数
set当中迭代器相关函数如下：

成员函数	功能
begin	获取容器中第一个元素的正向迭代器
end	获取容器中最后一个元素下一个位置的正向迭代器
rbegin	获取容器中最后一个元素的反向迭代器
rend	获取容器中第一个元素前一个位置的反向迭代器
*/
int main() {
	set<int> s;
	//插入元素（去重）
	s.insert(1);
	s.insert(4);
	s.insert(3);
	s.insert(3);
	s.insert(2);
	s.insert(2);
	s.insert(3);
	//遍历容器方式一（范围for）
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl; //1 2 3 4
	//删除元素方式一
	s.erase(3);
	//删除元素方式二
	set<int>::iterator pos = s.find(1); //查找值为1的元素
	if (pos != s.end())
	{
		s.erase(pos);
	}
	//遍历容器方式二（正向迭代器）
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl; //2 4
	//容器中值为2的元素个数
	cout << s.count(2) << endl; //1
	//容器大小
	cout << s.size() << endl; //2
	//清空容器
	s.clear();
	//容器判空
	cout << s.empty() << endl; //1
	//交换两个容器的数据
	set<int> tmp{ 11, 22, 33, 44 };
	s.swap(tmp);
	//遍历容器方式三（反向迭代器）
	set<int>::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl; //44 33 22 11

	return 0;
}