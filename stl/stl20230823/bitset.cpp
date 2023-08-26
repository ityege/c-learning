#include<iostream>
#include <bitset>
using namespace std;

/**
bitset的定义方式
方式一： 构造一个16位的位图，所有位都初始化为0。

bitset<16> bs1; //0000000000000000

方式二： 构造一个16位的位图，根据所给值初始化位图的前n位。

bitset<16> bs2(0xfa5); //0000111110100101

方式三： 构造一个16位的位图，根据字符串中的0/1序列初始化位图的前n位。

bitset<16> bs3(string("10111001")); //0000000010111001

bitset成员函数的使用
bitset中常用的成员函数如下：

成员函数	功能
set	设置指定位或所有位
reset	清空指定位或所有位
flip	反转指定位或所有位
test	获取指定位的状态
count	获取被设置位的个数
size	获取可以容纳的位的个数
any	如果有任何一个位被设置则返回true
none	如果没有位被设置则返回true
all	如果所有位都被设置则返回true

注意： 使用成员函数set、reset、flip时，若指定了某一位则操作该位，若未指定位则操作所有位。

*/
void test01() {

	bitset<8> bs;
	bs.set(2); //设置第2位
	bs.set(4); //设置第4位
	cout << bs << endl; //00010100

	bs.flip(); //反转所有位
	cout << bs << endl; //11101011
	cout << bs.count() << endl; //6

	cout << bs.test(3) << endl; //1

	bs.reset(0); //清空第0位
	cout << bs << endl; //11101010

	bs.flip(7); //反转第7位
	cout << bs << endl; //01101010

	cout << bs.size() << endl; //8

	cout << bs.any() << endl; //1

	bs.reset(); //清空所有位
	cout << bs.none() << endl; //1

	bs.set(); //设置所有位
	cout << bs.all() << endl; //1
}
/**
bitset运算符的使用
一、bitset中>>、<<运算符的使用。
bitset容器对>>、<<运算符进行了重载，我们可以直接使用>>、<<运算符对biset容器定义出来的对象进行输入输出操作。
*/
void test02() {
	bitset<8> bs;
	cin >> bs; //10110
	cout << bs << endl; //00010110
}
/**二、bitset中赋值运算符、关系运算符、复合赋值运算符、单目运算符的使用。
bitset容器中不仅对赋值运算符和一些关系运算符进行了重载，而且对一些复合赋值运算符和单目运算符也进行了重载，我们可以直接使用这些运算符对各个位图进行操作。

包括如下运算符：

赋值运算符：=。
关系运算符：==、!=。
复合赋值运算符：&=、|=、^=、<<=、>>=。
单目运算符：~。

*/
void test03() {
	bitset<8> bs1(string("10101010"));
	bitset<8> bs2(string("10101010"));
	bs1 >>= 1;
	cout << bs1 << endl; //01010101

	bs2 |= bs1;
	cout << bs2 << endl; //11111111

}
/**
三、bitset中位运算符的使用。
bitset容器中同时也对三个位运算符进行了重载，我们可以直接使用&、|、^对各个位图进行操作。
*/
void test04() {
	bitset<8> bs1(string("10101010"));
	bitset<8> bs2(string("01010101"));

	cout << (bs1 & bs2) << endl; //00000000
	cout << (bs1 | bs2) << endl; //11111111
	cout << (bs1 ^ bs2) << endl; //11111111

}
/**
四、bitset中[ ]运算符的使用。
bitset容器中对[ ]运算符进行了重载，我们可以直接使用[ ]对指定位进行访问或修改。
*/
void test05() {
	bitset<8> bs(string("00110101"));
	cout << bs[0] << endl; //1
	bs[0] = 0;
	cout << bs << endl; //00110100
}
int main() {
	auto p = test05;
	p();
	return 0;
}