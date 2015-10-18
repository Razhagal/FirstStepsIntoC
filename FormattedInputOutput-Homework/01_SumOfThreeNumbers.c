/*
Write a program that reads 3 real numbers from the console and prints their sum.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c;

    printf("Enter 3 numbers on a new line to get their sum.\n");

    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    printf("Sum = %.2f\n", (a + b + c));

    return 0;
}
