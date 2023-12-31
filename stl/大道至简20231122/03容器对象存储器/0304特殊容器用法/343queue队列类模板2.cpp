#pragma warning(disable : 4786)
#include <iostream>
#include "queue.cpp"
#include <list>
#include <string>
#include <assert.h>
using namespace std;
int main()
{
    try
    {
        Queue<string> q1;
        q1.push("Haidian District. ");
        cout << "\"Haidian District. \" are pushed into the queue. " << endl;
        q1.push("Chaoyang District. ");
        cout << "\"Chaoyang District. \" are pushed into the queue. " << endl;
        q1.push("Xuanwu District. ");
        cout << "\"Xuanwu District. \" are pushed into the queue. " << endl;
        q1.push("Xicheng District. ");
        cout << "\"Xicheng District. \" are pushed into the queue. " << endl;
        assert(q1.size() == 4);
        assert(q1.front() == "Haidian District. ");
        cout << "The Elements are poped from the queue by order. " << endl;
        while (q1.size())
        {
            cout << " " << q1.front() << endl;
            q1.pop();
        }
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}