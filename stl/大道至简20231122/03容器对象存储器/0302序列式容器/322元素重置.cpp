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
    cout << " list_One: ";
    print(list_One);
    list_Two.assign(5, 5.6);
    cout << " list_Two: ";
    print(list_Two);
    list_Three.assign(list_One.begin(), list_One.end());
    cout << " list_Three: ";
    print(list_Three);
    return 0;
}