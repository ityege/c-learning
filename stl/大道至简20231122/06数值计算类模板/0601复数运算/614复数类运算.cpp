#include <iostream>
#include <complex>
using namespace std;
int main()
{
    complex<float> c1(1.5, 2.5);
    complex<float> c2(c1);
    complex<float> c3;
    float re = 3.5;
    float im = 5.2;
    c2.real(re);
    c2.imag(im);
    cout << "c1: " << c1 << "; c2: " << c2 << endl;
    c3 = c1 + c2;
    cout << "c3 = c1 + c2 : " << c3 << endl;
    c3 = c1 - c2;
    cout << "c3 = c1 - c2 : " << c3 << endl;
    c3 = c1 * c2;
    cout << "c3 = c1* c2 : " << c3 << endl;
    c3 = c1 / c2;
    cout << "c3 = c1/c2 : " << c3 << endl;
    c1 += c2;
    cout << "c1 + = c2 : " << c1 << endl;
    c1 -= c2;
    cout << "c1 - = c2 : " << c1 << endl;
    c1 *= c2;
    cout << "c1* = c2 : " << c1 << endl;
    c1 /= c2;
    cout << "c1/ = c2 : " << c1 << endl;
    bool cmp = (c1 == c2);
    if (cmp)
        cout << "c1 == c2. " << endl;
    else
        cout << "c1! = c2. " << endl;

    return 0;
}