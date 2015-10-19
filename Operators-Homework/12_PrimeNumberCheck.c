/* 
 * Write an expression that checks if given positive integer number n
 * is prime (i.e. it is divisible without remainder only to itself and 1). Print true or false.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int number;
    scanf("%d", &number);
    
    if (number < 2)
    {
        printf("Prime? false");
    }
    else
    {
        int divider = 2;
        int maxDivider = (int)sqrt(number);
        int isPrime = 1;
        while (isPrime && (divider <= maxDivider))
        {
            if (number % divider == 0)
            {
                isPrime = 0;
            }

            divider++;
        }
        
        printf("Primer? %s", isPrime ? "true" : "false");
    }
    
    return 0;
}

