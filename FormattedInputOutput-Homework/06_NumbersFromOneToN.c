/*
Write a program that reads an integer number n from the console
and prints all the numbers in the interval [1..n], each on a single line.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    scanf("%d", &number);
    for(int i = 1; i <= number; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}
