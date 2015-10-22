/* 
 * Write a program that shows the sign (+, - or 0) of the product
 * of three real numbers, without calculating it.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
     * Disabling the buffer solves the issue with the first printf not showing before
     * the actual input and messing the whole output in the end
     */
    setbuf(stdout, NULL);
    
    float a, b, c;
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter c: ");
    scanf("%f", &c);
    
    if (a == 0 || b == 0 || c == 0)
    {
        printf("0");
    }
    else
    {
        int positiveNumbersCount = 0;
        if (a > 0)
        {
            positiveNumbersCount++;
        }
        
        if (b > 0)
        {
            positiveNumbersCount++;
        }
        
        if (c > 0)
        {
            positiveNumbersCount++;
        }
        
        if (positiveNumbersCount % 2 == 1)
        {
            printf("+");
        }
        else
        {
            printf("-");
        }
    }
    
    return 0;
}

