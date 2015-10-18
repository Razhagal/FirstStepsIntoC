/*
Write a program that enters a number n and after that
enters more n numbers and calculates and prints their sum.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    float sum;
    scanf("%d", &number);
    for(int i = 1; i <= number; i++)
    {
        float currentNum;
        scanf("%f", &currentNum);

        sum += currentNum;
    }

    printf("Sum = %.1f", sum);

    return 0;
}
