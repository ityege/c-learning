#include "stdio.h"
#define PI 3.1415926
#define R 5
#define S PI *R *R
#define C(A, B) A *B
void main()
{
    int AC = 0;
    printf("S = %5. 3f\n", S);
    AC = C(3, 4);
    printf("C = % d\n", AC);
    getchar();
}