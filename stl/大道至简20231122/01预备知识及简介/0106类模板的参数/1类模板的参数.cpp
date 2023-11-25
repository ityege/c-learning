#include <iostream>
template <class T>
class Table
{                       // 模板类 Table
    typename T::iter t; // typename 关键字说明 T 代表类型
public:
    explicit Table(const typename T::iter &ti) : t(ti) // 构造器
    {
    }
    void show() // 输出
    {
        typename T::iter *y;
        y = &t;
        std::cout << (*y)->p << std::endl;
    }
};
class card
{
public:
    typedef card *iter;
    int p;
    card(int pos) : p(pos) // 构造器
    {
    }
};
int main()
{
    card pc(3);
    Table<card> S_Table(&pc); // 使用类 card 作为类模板 Table 的参数
    S_Table.show();           // 输出
    return 0;
}