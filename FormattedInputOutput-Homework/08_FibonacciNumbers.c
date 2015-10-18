/*
Write a program that reads a number n and prints on the console
the first n members of the Fibonacci sequence (at a single line, separated by spaces).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    scanf("%d", &number);

    if (number == 0 || number == 1)
    {
        printf("0");
    }
    else
    {
        int firstNum = 0;
        int secondNum = 1;
        int thirdNum = 1;
        printf("0 1");
        for(int i = 2; i < number; i++)
        {
            thirdNum = firstNum + secondNum;
            if (i < number)
            {
                printf(" %d", thirdNum);
            }
            else
            {
                printf("%d", thirdNum);
            }

            firstNum = secondNum;
            secondNum = thirdNum;
        }
    }

    return 0;
}
