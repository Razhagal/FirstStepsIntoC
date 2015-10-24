/* 
 * Write a program that, for a given two integer numbers n and x, calculates
 * the sum S = 1 + 1!/x + 2!/x2 + … + n!/xn.
 * Print the result with 5 digits after the decimal point.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x;
    printf("n = ");
    scanf("%d", &n);
    printf("x = ");
    scanf("%d", &x);
    
    double sum = 1;
    int pow = 1;
    int factorial = 1;
    
    for (int i = 1; i<= n; i++)
    {
        factorial *= i;
        pow *= x;
        sum += (double)factorial / pow;
    }
    
    printf("%.5lf", sum);
    
    return 0;
}

