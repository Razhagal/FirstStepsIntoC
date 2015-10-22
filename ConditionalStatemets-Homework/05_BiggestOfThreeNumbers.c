/* 
 * Write a program that finds the biggest of three numbers.
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
    printf("Enter c: " );
    scanf("%f", &c);
    
    float biggestNum = a;
    if (b > a)
    {
        if (b > c)
        {
            biggestNum = b;
        }
        else
        {
            biggestNum = c;
        }
    }
    else if (c > a)
    {
        if (c > b)
        {
            biggestNum = c;
        }
        else
        {
            biggestNum = b;
        }
    }
    
    printf("Biggest is %.1f", biggestNum);
    
    return 0;
}

