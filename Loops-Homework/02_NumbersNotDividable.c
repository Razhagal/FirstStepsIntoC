/* 
 * Write a program that enters from the console a positive integer n and
 * prints all the numbers from 1 to n not divisible by 3 and 7,
 * on a single line, separated by a space.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 != 0 && i % 7 != 0)
        {
            printf("%d ", i);
        }
    }
    
    return 0;
}

