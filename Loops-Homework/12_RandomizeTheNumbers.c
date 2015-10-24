/* 
 * Write a program that enters in integer n and
 * prints the numbers 1, 2, …, n in random order.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    
    time_t t;
    srand(time(&t));
    
    int producedNumbers[n];
    for (int i = 0; i < n; i++)
    {
        producedNumbers[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        int number = rand() % n;
        if (producedNumbers[number] == 0)
        {
            printf("%d ", number);
            producedNumbers[number] = 1;
        }
        else
        {
            i--;
        }
    }
    
    
    return 0;
}

