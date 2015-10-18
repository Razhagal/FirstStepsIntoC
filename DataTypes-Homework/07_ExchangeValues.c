#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;
    int b = 10;
    printf("a = %d, b = %d\n", a, b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("a = %d, b = %d", a, b);

    return 0;
}
