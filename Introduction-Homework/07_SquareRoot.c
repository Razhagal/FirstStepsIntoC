#include <stdio.h>
#include <math.h>

int main()
{
    /*
     * %lf is the format for double floating point
     */
    double number;
    scanf("%lf", &number);
    double numberSquare = sqrt(number);
    printf("%lf", numberSquare);
    return 0;
}

