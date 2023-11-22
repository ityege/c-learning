#include <iostream>
using namespace std;
int main()
{
    int x;
    for (x = 1; x < 11; ++x)
        printf("% d ", x * x);
    printf("\n");
    cin.get();
    return 0;
}