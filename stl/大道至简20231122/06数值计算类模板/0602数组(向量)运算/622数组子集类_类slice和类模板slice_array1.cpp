#include <valarray>
#include <iostream>
#include <cmath>
using namespace std;
void myprint(valarray<double> &v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
        cout << v[i] << ", ";
    cout << endl;
}
int main()
{
    valarray<double> v1(12), v2;
    for (int i = 0; i < 12; i++)
    {
        v1[i] = 2 * (i + 1);
    }
    cout << "v1(Original): " << endl;
    myprint(v1);
    valarray<double> tv1 = valarray<double>(v1[slice(0, 4, 3)]); // slice 三个参数：始下标，数目，跨度
    valarray<double> tv2 = valarray<double>(v1[slice(2, 4, 3)]);
    v1[slice(0, 4, 3)] = pow(tv1, tv2);
    cout << "v1(Calculated): " << endl;
    myprint(v1);
    valarray<double> v3(v1[slice(0, 4, 3)]);
    cout << "v3: " << endl;
    myprint(v3);
    return 0;
}