/* 
 * Write a program to calculate the nth Catalan number by given n (1 < n < 100).
 * (2n)! / ((n + 1)! * n!)
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    
    if (n < 2 || n >= 100)
    {
        printf("n must be in range between 2 and 99");
    }
    else
    {
        long double nFactorial = 1;
        long double twoNFactorial = 1;
        long double nPlusOneFact = 1;
        long double catalan = 1;
        
        int j = 2 * n;
        for (int i = n; i >= 1; i--)
        {
            nFactorial *= i;
            twoNFactorial *= j;
            nPlusOneFact = (n + 1) * i;
            catalan = twoNFactorial / (nPlusOneFact * nFactorial);
            j--;
        }
        
        printf("%.Lf", catalan);
        
    }
    
    
    return 0;
}

