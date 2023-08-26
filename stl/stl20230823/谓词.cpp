#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
谓词=特殊的函数对象，只返回bool类型的函数对象（仿函数）

谓词是指普通函数或重载的operator()返回值是bool类型的函数对象(仿函数)。如果operator接受一个参数，那么叫做一元谓词,如果接受两个参数，那么叫做二元谓词，谓词可作为一个判断式。


*/
class GreaterThenFive
{
public:
	bool operator()(int num)
	{
		return num > 5;
	}

};
//一元谓词
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterThenFive());
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到了: " << *it << endl;
	}
}

//二元谓词
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(90);
	v.push_back(60);

	//默认从小到大
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "----------------------------" << endl;
	//使用函数对象改变算法策略，排序从大到小
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}




int main() {
	auto p = test02;
	p();
	return 0;

}