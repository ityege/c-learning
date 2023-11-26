#include <iostream>
#include <list>
using namespace std;
template <class T>
void print(list<T> &mylist)
{
    typename list<T>::iterator Iter;
    mylist.reverse();
    for (Iter = mylist.begin(); Iter != mylist.end(); Iter++)
    {
        cout << *Iter << ", ";
    }
    cout << endl;
}
int main()
{
    list<double> list_One, list_Two, list_Three;
    double Ele = 0.0;
    for (int i = 0; i < 10; i++)
    {
        Ele = i + i / 10.0;
        list_One.push_front(Ele);
    }
    cout << " List_One :" << endl;
    print(list_One);
    list_Two.assign(5, 5.6);
    cout << " List_Two :" << endl;
    print(list_Two);
    list_Three.assign(list_One.begin(), list_One.end());
    cout << " list_Three :" << endl;
    print(list_Three);
    list_One.swap(list_Two);
    cout << " list_one aned list_Two swapped：" << endl;
    cout << " List_One :" << endl;
    print(list_One);
    cout << " List_Two :" << endl;
    print(list_Two);
    swap(list_One, list_Three);
    cout << " list_one 和 list_Three swapped：" << endl;
    cout << " List_One :" << endl;
    print(list_One);
    cout << " list_Three :" << endl;
    print(list_Three);
    return 0;
}