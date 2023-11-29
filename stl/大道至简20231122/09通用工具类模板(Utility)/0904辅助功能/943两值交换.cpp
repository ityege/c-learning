#include <iostream>
#include <algorithm>
#include <memory>
#include <exception>

using namespace std;
class MyContrainer
{ // 自定义容器类
public:
    int *elem;    // 容器的存储空间（数组）
    int num_elem; // 容器中存储元素的个数
public:
    MyContrainer() // 构造函数
    {
        try
        {
            elem = new int[128]; // 开辟部分空间
        }
        catch (exception &e) // 捕获异常
        {
            std::cout << "exception. " << e.what() << std::endl;
            exit(0);
        }
    }
    void myswap(MyContrainer &mc) // 自定义交换算法
    {
        std::swap(elem, mc.elem);
        std::swap(num_elem, mc.num_elem);
    }
    void myassign(int *mc_elem, int num) // 自定义 assign 算法
    {
        memcpy(elem, mc_elem, num * sizeof(int));
        num_elem = num;
    }
    ~MyContrainer() // 析构函数
    {
        delete[] elem;
    }
};
inline void myswap(MyContrainer &c1, MyContrainer &c2) // 全局函数声明
{
    c1.myswap(c2);
}
void print(MyContrainer &c1) // 输出容器对象
{
    int num = c1.num_elem;
    for (int i = 0; i < num; i++)
    {
        std::cout << " " << *(c1.elem + i);
    }
    std::cout << std::endl;
}
int main()
{
    int array_one[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};           // 数组 1
    int array_two[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; // 数组 2
    MyContrainer mc1, mc2;
    mc1.myassign(array_one, 10); // 初始化容器对象 mc1
    std::cout << "the original mc1: " << std::endl;
    print(mc1);                  // 输出容器的对象
    mc2.myassign(array_two, 10); // 初始化容器对象 mc2
    std::cout << "the original mc2: " << std::endl;
    print(mc2);      // 输出容器的对象
    mc1.myswap(mc2); // 交换算法
    std::cout << "the original mc1(swaped): " << std::endl;
    print(mc1); // 输出容器的对象
    std::cout << "the original mc2(swaped): " << std::endl;
    print(mc2);       // 输出容器的对象
    myswap(mc1, mc2); // 交换算法
    std::cout << "the original mc1(swaped twice. ): " << std::endl;
    print(mc1); // 输出容器的对象
    std::cout << "the original mc2(swaped twice. ): " << std::endl;
    print(mc2); // 输出容器的对象
    return 0;
}