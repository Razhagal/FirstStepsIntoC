/* 
 * Write a program that calculates n! / (k! * (n-k)!) for given n and k (1 < k < n < 100).
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
    else if (n >= 100 || k >= 100)
    {
        printf("Input numbers are too big");
    }
    else if (k >= n)
    {
        printf("k must be smaller than n");
    }
    else
    {
        int divisor = 1;
        unsigned long long result = 1;
        for (int i = k + 1; i <= n; i++)
        {
            result = (result * i) / divisor;
            divisor++;
        }
        
        printf("%llu", result);
    }
    
    return 0;
}

