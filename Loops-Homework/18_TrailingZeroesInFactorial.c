/* 
 * Write a program that calculates with how many zeroes the
 * factorial of a given number n has at its end.
 * Your program should work well for very big numbers, e.g. n=100000.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    
    int temp = n;
    int result = 0;
    while (temp >= 5)
    {
        temp /= 5;
        result += temp;
    }
    
    printf("%d factorial has %d trailing zeroes in the end", n, result);
    
    return 0;
}

