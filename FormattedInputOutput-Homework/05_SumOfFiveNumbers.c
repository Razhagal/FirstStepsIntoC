/*
Write a program that enters 5 numbers (given in a single line, separated by a space),
calculates and prints their sum.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float firstNum, secondNum, thirdNum, fourthNum, fifthNum;
    scanf("%f %f %f %f %f", &firstNum, &secondNum, &thirdNum, &fourthNum, &fifthNum);

    float sum = firstNum + secondNum + thirdNum + fourthNum + fifthNum;
    printf("%.2f", sum);

    return 0;
}
