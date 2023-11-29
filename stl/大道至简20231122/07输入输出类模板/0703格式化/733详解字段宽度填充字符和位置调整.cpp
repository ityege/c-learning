#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    bool varb = 1;
    cout << std::noboolalpha << varb << " == " << std::boolalpha << varb << endl;
    float varf = 123.4512;
    int wid = cout.width(); // 返回原有的字段宽度
    cout.width(6);          // 设置输出宽度
    cout << varf << endl;
    cout << setw(7) << varf << endl; // 设置输出字段宽度
    cout.width(6);
    cout << cout.fill('_') << varf << endl;                       // 使用字符“_”填充
    cout << setw(9) << setfill('*') << varf << " " << 45 << endl; // 使用字符“* ”填充
    cout << setw(9) << setfill(' ') << setiosflags(ios::right) << varf << "; :" << setw(9) << 45.234 << endl;
    double varf1 = 123.4512;
    double varf2 = 456.892;
    cout << setw(10) << setfill(' ') << setiosflags(ios::right) << varf1 << ";" << resetiosflags(ios::left) << setw(10)
         << setfill(' ') << setiosflags(ios::right) << varf2 << endl; // 使用空格填充，右对齐输出 varf1，varf2
    resetiosflags(ios::left);                                         // 恢复左对齐
    cout << varf1 << " ; " << varf2 << endl;
    // 注意输出没有将格式控制直接插入流输出中，这是因为下述格式控制调用时均有返回值；
    // 程序运行时，会将这些函数的返回值输出，带来不必要的麻烦
    cout.width(12);
    cout.fill('*');
    cout.setf(ios_base::right, ios_base::adjustfield); // 右对齐
    cout << varf1 << ";" << endl;
    cout << varf2 << ";" << endl;
    cout.width(12);
    cout.fill('*');
    cout.setf(ios_base::right, ios_base::adjustfield);
    cout << varf2 << ";" << endl;
    cout.width(12);
    cout.fill('*');
    cout.setf(ios_base::left, ios_base::adjustfield);
    cout << varf1 << ";" << endl;
    cout.width(12);
    cout.fill('*');
    cout.setf(ios_base::left, ios_base::adjustfield);
    cout << varf2 << ";" << endl;
    return 0;
}