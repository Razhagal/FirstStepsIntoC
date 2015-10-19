/* 
 * Write a program that takes as input a four-digit number in format abcd (e.g. 2011) and performs the following:
 * - Calculates the sum of the digits (in our example 2+0+1+1 = 4).
 * - Prints on the console the number in reversed order: dcba (in our example 1102).
 * - Puts the last digit in the first position: dabc (in our example 1201).
 * - Exchanges the second and the third digits: acbd (in our example 2101).
 * The number has always exactly 4 digits and cannot start with 0.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    scanf("%d", &number);
    
    if (number < 1000)
    {
        printf("Not a four digit number!");
    }
    else
    {
        int a = (number / 1000) % 10;
        int b = (number / 100) % 10;
        int c = (number / 10) % 10;
        int d = number % 10;
        
        printf("Sum of digits: %d\n", (a + b + c + d));
        printf("Digits in reverse %d%d%d%d\n", d, c, b, a);
        printf("Last digit on first position: %d%d%d%d\n", d, a, b, c);
        printf("Exchanged second and third digit: %d%d%d%d\n", a, c, b, d);
    }
    
    return 0;
}

