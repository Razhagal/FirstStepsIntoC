/* 
 * Write a program that calculates the greatest common divisor (GCD)
 * of given two integers a and b. Use the Euclidean algorithm (find it in Internet).
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    
    int temp;
    int aTemp = a;
    int bTemp = b;
    while (bTemp != 0)
    {
        temp = bTemp;
        bTemp = aTemp % bTemp;
        aTemp = temp;
    }
    
    printf("The Greatest Common Division of %d and %d is %d", a, b, aTemp);
    
    return 0;
}

