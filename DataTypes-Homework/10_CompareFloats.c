#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    const double esp = 0.000001;

    double firstNum;
    double secondNum;
    scanf("%lf", &firstNum);
    scanf("%lf", &secondNum);

    printf("Equal: %s", fabs(secondNum - firstNum) < esp ? "true" : "false");

    return 0;
}
