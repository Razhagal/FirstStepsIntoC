/*
Write a program that reads two positive integer numbers and prints
how many numbers p exist between them such that the reminder of the division by 5 is 0.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstNum, secondNum, numbersCount = 0;
    printf("Start: ");
    scanf("%d", &firstNum);

    printf("End: ");
    scanf("%d", &secondNum);

    for(int i = firstNum; i <= secondNum; i++)
    {
        if (i % 5 == 0)
        {
            numbersCount++;
        }
    }

    printf("The count of numbers dividable by 5 without reminder between %d and %d is %d",
           firstNum, secondNum, numbersCount);

    return 0;
}
