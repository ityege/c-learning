#include "stdio.h"
#define C(A, B) A *B
void main()
{
    int AC = 0;
    AC = C(3, 4);
    printf("C = % d\n", AC);
    getchar();
}