#include <iostream>
#include <list>
#include <cstring>
using namespace std;
struct PERSON
{ // 定义结构 PERSON
    int id, sex;
    double core;
    void clear()
    {
        id = 0;
        sex = 0;
        core = 0;
    }
};
int main()
{
    PERSON temp;
    list<PERSON> C1; // 声明一个 list 容器的对象 C1，容器中元素是 PERSON 类型的对象
    int id_temp, sex_temp, size;
    double core_temp;
    C1.clear(); // 清空容器
    int counter = 0;
    cout << "This is a simplest C++ Example! \n"
         << endl;
    cout << " 任意键开始 . . . . . . ";
    cin.get();          // 按 < Enter > 键等待
    while (counter < 5) // 输入数据
    {
        cout << " 请输入 ID:";
        cin >> id_temp;
        cout << " 请输入性别:";
        cin >> sex_temp;
        cout << " 请输入分数:";
        cin >> core_temp;
        temp.id = id_temp;
        temp.sex = sex_temp;
        temp.core = core_temp;
        C1.push_back(temp);               // 将结构 PERSON 类型的变量 temp 装入容器 C1
        memset(&temp, 0, sizeof(PERSON)); // 将变量 temp 清零
        counter++;                        // 计数器加 1
    }
    cout << " 按 < Enter > 键继续 . . . . . . ";
    cin.get(); // 输入等待
    size = C1.size();
    cout << endl;
    list<PERSON>::iterator Iter;                      // 声明 list 容器的迭代器类型变量 Iter
    for (Iter = C1.begin(); Iter != C1.end(); Iter++) // 遍历输出容器中的每个元素
    {
        temp.clear();
        temp = *Iter;
        cout << " ID: " << temp.id << ", SEX: " << temp.sex << ", Core: " << temp.core << endl;
    }
    cout << "任意键退出程序 . . . . . . "; // << endl;
    cin.get();
    return 0;
}