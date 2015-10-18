#include <stdio.h>
#include <stdlib.h>

int main()
{
    //34.567839023, 12.345, 8923.1234857, 3456.091
    float smallFloat = 12.345f;
    float anotherSmallFloat = 3456.091f;
    double someDouble = 34.567839023;
    long double anotherDouble = 8923.1234857;

    printf("%.7lf", anotherDouble);

    return 0;
}
