#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Student
{
    int id;
    double score;
};
template <class T>
void Original(T &myvt)
{
    Student temp;
    temp.id = 1;
    temp.score = 90;
    myvt.push_back(temp);
    temp.id = 2;
    temp.score = 95;
    myvt.push_back(temp);
    temp.id = 3;
    temp.score = 98;
    myvt.push_back(temp);
    temp.id = 4;
    temp.score = 97;
    myvt.push_back(temp);
    temp.id = 5;
    temp.score = 95;
    myvt.push_back(temp);
    temp.id = 6;
    temp.score = 90;
    myvt.push_back(temp);
}
void out(Student &stu)
{
    cout << " id: " << stu.id << " , score: " << stu.score << endl; // 输出信息
}
bool greater95(Student &stu)
{
    if (stu.score >= 95.0) // 如果大于 95， 就返回 “true”
        return 1;
    else
        return 0;
}
int main()
{
    vector<Student> myvt;           // 声明向量容器
    vector<Student>::iterator iter; // 声明迭代器
    int countV = 0;
    Original(myvt);                                                   // 初始化
    for_each(myvt.begin(), myvt.end(), out);                          // for_each 算法
    countV = count_if(myvt.begin(), myvt.end(), greater95);           // 统计 score >95. 0 的元素个数
    cout << " The Number of the elements > 95.0: " << countV << endl; // 输出符合条件的元素个数
    return 0;
}