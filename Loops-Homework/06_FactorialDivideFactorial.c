/* 
 * Write a program that calculates n! / k! for given n and k (1 < k < n < 100).
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);
    
    if (n < 2 || k < 2)
    {
        printf("Input numbers too low");
    }
    else if (k >= n)
    {
        printf("k must be smaller than n");
    }
    else
    {
        unsigned int nFactorial = 1;
        unsigned int kFactorial = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i <= k)
            {
                kFactorial *= i;
            }
            
            nFactorial *= i;
        }
        
        printf("%d", nFactorial / kFactorial);
    }
    
    return 0;
}

