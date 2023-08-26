#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;

/**
算法主要是由头文件<algorithm> <functional> <numeric>组成。
<algorithm>是所有STL头文件中最大的一个,其中常用的功能涉及到比较，交换，查找,遍历，复制，修改，反转，排序，合并等...
<numeric>体积很小，只包括在几个序列容器上进行的简单运算的模板函数.
<functional> 定义了一些模板类,用以声明函数对象。
*/
/**
常用遍历算法
*/
namespace bianli {
	/**
常见的遍历算法

	遍历算法 遍历容器元素
	@param beg 开始迭代器
	@param end 结束迭代器
	@param _callback  函数回调或者函数对象
	@return 函数对象
for_each(iterator beg, iterator end, _callback);

	transform算法 将指定容器区间元素搬运到另一容器中
	注意 : transform 不会给目标容器分配内存，所以需要我们提前分配好内存
	@param beg1 源容器开始迭代器
	@param end1 源容器结束迭代器
	@param beg2 目标容器开始迭代器
	@param _cakkback 回调函数或者函数对象
	@return 返回目标容器迭代器
transform(iterator beg1, iterator end1, iterator beg2, _callbakc)
*/
	namespace foreach {
		/*

	template<class _InIt,class _Fn1> inline
	void for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
	{
		for (; _First != _Last; ++_First)
			_Func(*_First);
	}

	*/

	//普通函数
		void print01(int val) {
			cout << val << " ";
		}
		//函数对象
		struct print001 {
			void operator()(int val) {
				cout << val << " ";
			}
		};

		//for_each算法基本用法
		void test01() {

			vector<int> v;
			for (int i = 0; i < 10; i++) {
				v.push_back(i);
			}

			//遍历算法
			for_each(v.begin(), v.end(), print01);
			cout << endl;

			for_each(v.begin(), v.end(), print001());
			cout << endl;

		}

		struct print02 {
			print02() {
				mCount = 0;
			}
			void operator()(int val) {
				cout << val << " ";
				mCount++;
			}
			int mCount;
		};

		//for_each返回值
		void test02() {

			vector<int> v;
			for (int i = 0; i < 10; i++) {
				v.push_back(i);
			}

			print02 p = for_each(v.begin(), v.end(), print02());
			cout << endl;
			cout << p.mCount << endl;
		}

		struct print03 : public binary_function<int, int, void> {
			void operator()(int val, int bindParam) const {
				cout << val + bindParam << " ";
			}
		};

		//for_each绑定参数输出
		void test03() {

			vector<int> v;
			for (int i = 0; i < 10; i++) {
				v.push_back(i);
			}

			for_each(v.begin(), v.end(), bind2nd(print03(), 100));
		}


	}

	namespace transform1 {
		//transform 将一个容器中的值搬运到另一个容器中
	/*
		template<class _InIt, class _OutIt, class _Fn1> inline
		_OutIt _Transform(_InIt _First, _InIt _Last,_OutIt _Dest, _Fn1 _Func)
		{

			for (; _First != _Last; ++_First, ++_Dest)
				*_Dest = _Func(*_First);
			return (_Dest);
		}

		template<class _InIt1,class _InIt2,class _OutIt,class _Fn2> inline
		_OutIt _Transform(_InIt1 _First1, _InIt1 _Last1,_InIt2 _First2, _OutIt _Dest, _Fn2 _Func)
		{
			for (; _First1 != _Last1; ++_First1, ++_First2, ++_Dest)
				*_Dest = _Func(*_First1, *_First2);
			return (_Dest);
		}
	*/

		struct transformTest01 {
			int operator()(int val) {
				return val + 100;
			}
		};
		struct print01 {
			void operator()(int val) {
				cout << val << " ";
			}
		};
		void test01() {

			vector<int> vSource;
			for (int i = 0; i < 10; i++) {
				vSource.push_back(i + 1);
			}

			//目标容器
			vector<int> vTarget;
			//给vTarget开辟空间
			vTarget.resize(vSource.size());
			//将vSource中的元素搬运到vTarget
			vector<int>::iterator it = transform(vSource.begin(), vSource.end(), vTarget.begin(), transformTest01());
			//打印
			for_each(vTarget.begin(), vTarget.end(), print01()); cout << endl;

		}

		//将容器1和容器2中的元素相加放入到第三个容器中
		struct transformTest02 {
			int operator()(int v1, int v2) {
				return v1 + v2;
			}
		};
		void test02() {

			vector<int> vSource1;
			vector<int> vSource2;
			for (int i = 0; i < 10; i++) {
				vSource1.push_back(i + 1);
			}

			for (int i = 0; i < 11; i++) {
				vSource2.push_back(i + 1);
			}
			//目标容器
			vector<int> vTarget;
			//给vTarget开辟空间
			vTarget.resize(vSource1.size());
			transform(vSource1.begin(), vSource1.end(), vSource2.begin(), vTarget.begin(), transformTest02());
			//打印
			for_each(vTarget.begin(), vTarget.end(), print01()); cout << endl;
		}


	}

}

/**
常用查找算法
*/
namespace chazhao {
	/**
		find算法 查找元素
		@param beg 容器开始迭代器
		@param end 容器结束迭代器
		@param value 查找的元素
		@return 返回查找元素的位置
		find(iterator beg, iterator end, value)

		find_if算法 条件查找
		@param beg 容器开始迭代器
		@param end 容器结束迭代器
		@param  callback 回调函数或者谓词(返回bool类型的函数对象)
		@return bool 查找返回true 否则false

		find_if(iterator beg, iterator end, _callback);


		adjacent_find算法 查找相邻重复元素
		@param beg 容器开始迭代器
		@param end 容器结束迭代器
		@param  _callback 回调函数或者谓词(返回bool类型的函数对象)
		@return 返回相邻元素的第一个位置的迭代器

		adjacent_find(iterator beg, iterator end, _callback);

		binary_search算法 二分查找法
		注意: 在无序序列中不可用
		@param beg 容器开始迭代器
		@param end 容器结束迭代器
		@param value 查找的元素
		@return bool 查找返回true 否则false

		bool binary_search(iterator beg, iterator end, value);

		count算法 统计元素出现次数
		@param beg 容器开始迭代器
		@param end 容器结束迭代器
		@param  value回调函数或者谓词(返回bool类型的函数对象)
		@return int返回元素个数

		count(iterator beg, iterator end, value);

		count算法 统计元素出现次数
		@param beg 容器开始迭代器
		@param end 容器结束迭代器
		@param  callback 回调函数或者谓词(返回bool类型的函数对象)
		@return int返回元素个数

		count_if(iterator beg, iterator end, _callback);

	*/

	void test01()
	{
		vector<int> v;
		for (int i = 0; i < 10; i++)
		{
			v.push_back(i);
		}

		vector<int>::iterator pos = find(v.begin(), v.end(), 5);

		if (pos != v.end())
		{
			cout << "找到了元素：" << *pos << endl;
		}
		else
		{
			cout << "未找到" << endl;
		}
	}

	class Person
	{
	public:
		Person(string name, int age)
		{
			this->m_Name = name;
			this->m_Age = age;
		}

		bool operator==(const Person& p)
		{
			return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
		}

		string m_Name;
		int m_Age;
	};

	void test02()
	{
		vector<Person> v;

		Person p1("aaa", 10);
		Person p2("bbb", 20);
		Person p3("ccc", 30);
		Person p4("ddd", 40);

		v.push_back(p1);
		v.push_back(p2);
		v.push_back(p3);
		v.push_back(p4);

		vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
		if (pos != v.end())
		{
			cout << "找到了元素  姓名： " << (*pos).m_Name << " 年龄： " << (*pos).m_Age << endl;
		}
	}

	class MyComparePerson : public binary_function<Person*, Person*, bool>
	{
	public:
		bool operator()(Person* p1, Person* p2) const
		{
			return p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age;
		}
	};

	void test03()
	{

		vector<Person*> v;

		Person p1("aaa", 10);
		Person p2("bbb", 20);
		Person p3("ccc", 30);
		Person p4("ddd", 40);

		v.push_back(&p1);
		v.push_back(&p2);
		v.push_back(&p3);
		v.push_back(&p4);

		Person* p = new Person("bbb", 20);

		vector<Person*>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyComparePerson(), p));

		if (pos != v.end())
		{
			cout << "找到了元素--- 姓名： " << (*pos)->m_Name << " 年龄： " << (*pos)->m_Age << endl;
		}
		else
		{
			cout << "未找到" << endl;
		}
	}

	// adjacent_find算法 查找相邻重复元素
	void test04()
	{

		vector<int> v;

		v.push_back(3);
		v.push_back(2);
		v.push_back(300);
		v.push_back(300);
		v.push_back(6);
		v.push_back(3);

		vector<int>::iterator ret = adjacent_find(v.begin(), v.end());

		if (ret != v.end())
		{
			cout << "找到了相邻的重复元素： " << *ret << endl;
		}
		else
		{
			cout << "未找到" << endl;
		}
	}

	/*
	binary_search算法 二分查找法
	注意: 在无序序列中不可用
	*/

	void test05()
	{

		vector<int> v;
		for (int i = 0; i < 10; i++)
		{
			v.push_back(i);
		}
		// v.push_back(4);  必须是有序序列，如果无效 结果未知

		bool ret = binary_search(v.begin(), v.end(), 2);
		if (ret)
		{
			cout << "查到了数据2" << endl;
		}
		else
		{
			cout << "未找到数据2" << endl;
		}
	}

	/*
	count算法 统计元素出现次数
	@param beg 容器开始迭代器
	@param end 容器结束迭代器
	@param  value回调函数或者谓词(返回bool类型的函数对象)
	@return int返回元素个数
	*/
	class GreaterThan3
	{
	public:
		bool operator()(int val)
		{
			return val >= 3;
		}
	};

	void test06()
	{

		vector<int> v;
		for (int i = 0; i < 10; i++)
		{
			v.push_back(i);
		}

		v.push_back(3);
		v.push_back(3);
		v.push_back(3);

		int num = count(v.begin(), v.end(), 3);

		cout << "3的个数为： " << num << endl;

		// 统计大于等于3的个数
		num = count_if(v.begin(), v.end(), GreaterThan3());
		// 0 1 2 3 4 5 6 7 8 9 3 3 3
		cout << "大于等于3的个数为： " << num << endl;
	}

}

/**
常用排序算法
*/
namespace paixu {
	/**

		merge算法 容器元素合并，并存储到另一容器中
		@param beg1 容器1开始迭代器
		@param end1 容器1结束迭代器
		@param beg2 容器2开始迭代器
		@param end2 容器2结束迭代器
		@param dest  目标容器开始迭代器

		merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

		sort算法 容器元素排序
		注意:两个容器必须是有序的
		@param beg 容器1开始迭代器
		@param end 容器1结束迭代器
		@param _callback 回调函数或者谓词(返回bool类型的函数对象)

		sort(iterator beg, iterator end, _callback)

		sort算法 对指定范围内的元素随机调整次序
		@param beg 容器开始迭代器
		@param end 容器结束迭代器

		random_shuffle(iterator beg, iterator end)

		reverse算法 反转指定范围的元素
		@param beg 容器开始迭代器
		@param end 容器结束迭代器

		reverse(iterator beg, iterator end)


	*/

	/*
	merge算法 容器元素合并，并存储到另一容器中
	注意 : 两个容器必须是有序的,顺序要一致
	*/
	void test01()
	{

		vector<int> v1;
		vector<int> v2;

		for (int i = 0; i < 10; i++)
		{
			v1.push_back(i);
			v2.push_back(i + 1);
		}

		vector<int> vTarget; // 目标容器
		vTarget.resize(v1.size() + v2.size());

		merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

		for_each(vTarget.begin(), vTarget.end(), [](int val)
			{ cout << val << " "; });
		cout << endl;
	}

	// sort
	void test02()
	{

		vector<int> v;
		for (int i = 0; i < 10; i++)
		{
			v.push_back(i);
		}

		// 降序排序

		sort(v.begin(), v.end(), greater<int>());
		for_each(v.begin(), v.end(), [](int val)
			{ cout << val << " "; });
		cout << endl;
	}

	// random_shuffle算法 对指定范围内的元素随机调整次序
	void test03()
	{
		vector<int> v;
		for (int i = 0; i < 10; i++)
		{
			v.push_back(i);
		}

		random_shuffle(v.begin(), v.end());
		for_each(v.begin(), v.end(), [](int val)
			{ cout << val << " "; });
		cout << endl;
	}

	// reverse算法 反转指定范围的元素
	void test04()
	{

		vector<int> v;
		for (int i = 0; i < 10; i++)
		{
			v.push_back(i);
		}

		cout << "反转前打印：" << endl;
		for_each(v.begin(), v.end(), [](int val)
			{ cout << val << " "; });
		cout << endl;

		reverse(v.begin(), v.end());

		cout << "反转后打印： " << endl;
		for_each(v.begin(), v.end(), [](int val)
			{ cout << val << " "; });

		cout << endl;
	}

}
/**
常用拷贝和替换算法
*/
namespace kaobeitihaun {
	/**

		copy算法 将容器内指定范围的元素拷贝到另一容器中
		@param beg 容器开始迭代器
		@param end 容器结束迭代器
		@param dest 目标起始迭代器

		copy(iterator beg, iterator end, iterator dest)

		replace算法 将容器内指定范围的旧元素修改为新元素
		@param beg 容器开始迭代器
		@param end 容器结束迭代器
		@param oldvalue 旧元素
		@param oldvalue 新元素

		replace(iterator beg, iterator end, oldvalue, newvalue)

		replace_if算法 将容器内指定范围满足条件的元素替换为新元素
		@param beg 容器开始迭代器
		@param end 容器结束迭代器
		@param callback函数回调或者谓词(返回Bool类型的函数对象)
		@param oldvalue 新元素

		replace_if(iterator beg, iterator end, _callback, newvalue)

		swap算法 互换两个容器的元素
		@param c1容器1
		@param c2容器2

		swap(container c1, container c2)

	*/
	// copy算法 将容器内指定范围的元素拷贝到另一容器中
	void test01()
	{
		vector<int> v;
		for (int i = 0; i < 10; i++)
		{
			v.push_back(i);
		}

		vector<int> v2;
		v2.resize(v.size());
		copy(v.begin(), v.end(), v2.begin());

		for_each(v2.begin(), v2.end(), [](int val)
			{ cout << val << " "; });
		cout << endl;

		copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	// replace算法 将容器内指定范围的旧元素修改为新元素
	// replace_if(iterator beg, iterator end, _callback, newvalue) 按条件替换

	class MyReplace
	{
	public:
		bool operator()(int val)
		{
			return val > 3;
		}
	};
	void test02()
	{

		vector<int> v;
		for (int i = 0; i < 10; i++)
		{
			v.push_back(i);
		}

		// 将容器中的3替换为 3000
		replace(v.begin(), v.end(), 3, 3000);

		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		// 将容器中所有大于3的都替换为 30000;
		replace_if(v.begin(), v.end(), MyReplace(), 30000);
		// 0 1 2 30000 ...
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	// swap交换
	void test03()
	{

		vector<int> v;
		for (int i = 0; i < 10; i++)
		{
			v.push_back(i);
		}

		vector<int> v2(10, 100);

		cout << "交换数据前：" << endl;
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		cout << "交换数据后：" << endl;
		swap(v, v2);

		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		cout << endl;

		copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}

/**
* 常用算数生成算法
*/
namespace suanfushengchen {
	/**

		accumulate算法 计算容器元素累计总和
		@param beg 容器开始迭代器
		@param end 容器结束迭代器
		@param value累加值

		accumulate(iterator beg, iterator end, value)

		fill算法 向容器中添加元素
		@param beg 容器开始迭代器
		@param end 容器结束迭代器
		@param value t填充元素

		fill(iterator beg, iterator end, value)

	*/

	// accumulate算法 计算容器元素累计总和
	void test01()
	{

		vector<int> v;
		for (int i = 0; i <= 100; i++)
		{
			v.push_back(i);
		}

		int num = accumulate(v.begin(), v.end(), 1000); // 参数3代表 累加起始值

		cout << "num = " << num << endl;
	}

	// fill算法 向容器中添加元素
	void test02()
	{

		vector<int> v;
		v.resize(10);

		fill(v.begin(), v.end(), 100);

		for_each(v.begin(), v.end(), [](int val)
			{ cout << val << " "; });
		cout << endl;
	}

}
/**
常用集合算法
*/
namespace jihe {
	/**

		set_intersection算法 求两个set集合的交集
		注意:两个集合必须是有序序列
		@param beg1 容器1开始迭代器
		@param end1 容器1结束迭代器
		@param beg2 容器2开始迭代器
		@param end2 容器2结束迭代器
		@param dest  目标容器开始迭代器
		@return 目标容器的最后一个元素的迭代器地址

		set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

		set_union算法 求两个set集合的并集
		注意:两个集合必须是有序序列
		@param beg1 容器1开始迭代器
		@param end1 容器1结束迭代器
		@param beg2 容器2开始迭代器
		@param end2 容器2结束迭代器
		@param dest  目标容器开始迭代器
		@return 目标容器的最后一个元素的迭代器地址

		set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

		set_difference算法 求两个set集合的差集
		注意:两个集合必须是有序序列
		@param beg1 容器1开始迭代器
		@param end1 容器1结束迭代器
		@param beg2 容器2开始迭代器
		@param end2 容器2结束迭代器
		@param dest  目标容器开始迭代器
		@return 目标容器的最后一个元素的迭代器地址

		set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

	*/

	/*
	set_intersection算法 求两个set集合的交集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
	*/
	void test01()
	{
		
		vector<int> v1;
		vector<int> v2;

		for (int i = 0; i < 10; i++)
		{
			v1.push_back(i);
			v2.push_back(i + 5);
		}

		vector<int> vTarget;

		vTarget.resize(min(v1.size(), v2.size()));

		vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

		for_each(vTarget.begin(), itEnd, [](int val)
			{ cout << val << " "; });
		cout << endl;
	}

	/*
	set_union算法 求两个set集合的并集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
	*/

	void test02()
	{
		
		vector<int> v1;
		vector<int> v2;

		for (int i = 0; i < 10; i++)
		{
			v1.push_back(i);
			v2.push_back(i + 5);
		}

		vector<int> vTarget;
		vTarget.resize(v1.size() + v2.size());
		vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

		for_each(vTarget.begin(), itEnd, [](int val)
			{ cout << val << " "; });
		cout << endl;
	}

	/*
	set_difference算法 求两个set集合的差集
	注意:两个集合必须是有序序列
	@param beg1 容器1开始迭代器
	@param end1 容器1结束迭代器
	@param beg2 容器2开始迭代器
	@param end2 容器2结束迭代器
	@param dest  目标容器开始迭代器
	@return 目标容器的最后一个元素的迭代器地址
	*/

	void test03()
	{
		vector<int> v1;
		vector<int> v2;

		for (int i = 0; i < 10; i++)
		{
			v1.push_back(i);
			v2.push_back(i + 5);
		}

		vector<int> vTarget;
		vTarget.resize(max(v1.size(), v2.size()));

		// A 与 B 差集
		// vector<int>::iterator itEnd  = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

		// B 与 A 差集
		vector<int>::iterator itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());

		for_each(vTarget.begin(), itEnd, [](int val)
			{ cout << val << " "; });
		cout << endl;
	}


}
int main() {
	srand((unsigned int)time(NULL));
	auto p = jihe::test03;
	p();
	return 0;
}