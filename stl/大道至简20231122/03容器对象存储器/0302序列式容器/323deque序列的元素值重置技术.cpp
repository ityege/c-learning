#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
void Out(double &Ele)

{
    cout.width(5);
    cout.precision(1);
    cout << std::fixed << Ele << " ";
}
int main()
{
    deque<double>::iterator Iter;
    deque<double>::reverse_iterator rIter;
    deque<double> D1, D2, D3;
    for (int i = 0; i < 10; i++)
    {
        D1.push_front(90 + i / 10.0);
    }
    cout << " All the elements of 双端序列 D1:" << endl;
    for_each(D1.begin(), D1.end(), Out);
    cout << endl;
    Iter = D1.begin();
    double begin = *Iter;
    Iter = D1.end();
    double end = *(--Iter);
    ///////////////
    rIter = D1.rbegin();
    double rbegin = *(rIter);
    rIter = D1.rend();
    double rend = *(--rIter); // 注意是 “ - - ”
    double front = D1.front();
    double back = D1.back();
    cout << " begin :" << begin << ","
         << " end :" << end << ","
         << " front :" << front << ","
         << " back : " << back << endl;
    cout << " reverse begin :"
         << rbegin
         << " reverse end :"
         << rend
         << ","
         << endl;
    if (D1.empty())
    {
        cout << " 双端序列为空 . " << endl;
    }
    else
    {
        int size = D1.size();
        cout << " 双短序列中包含" << size << " 个元素 . " << endl;
    }
    double five = D1.at(5);
    cout << " 第 5 个元素是" << five << " . " << endl;
    D2.assign(6, 0);
    D3.assign(D1.begin(), D1.end());
    cout << " All the elements of 双端序列 D2:" << endl;
    for_each(D2.begin(), D2.end(), Out);
    cout << endl;
    cout << " All the elements of 双端序列 D3:" << endl;
    for_each(D3.begin(), D3.end(), Out);
    cout << endl;
    return 0;
}