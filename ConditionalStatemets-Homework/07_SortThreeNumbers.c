/*
 * Write a program that enters 3 real numbers and prints them sorted in descending order.
 * Don’t use arrays and the built-in sorting functionality.
 */

#include <stdio.h>

int main()
{
    setbuf(stdout, NULL);
    
    float a, b, c;
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter c: ");
    scanf("%f", &c);
    
    if (a >= b && a >= c)
    {
        if (b >= c)
        {
            printf("%.1f %.1f %.1f", a, b, c);
        }
        else
        {
            printf("%.1f %.1f %.1f", a, c, b);
        }
    }
    else if (b >= a && b >= c)
    {
        if (a >= c)
        {
            printf("%.1f %.1f %.1f", b, a, c);
        }
        else
        {
            printf("%.1f %.1f %.1f", b, c, a);
        }
    }
    else if (c >= a && c >= b)
    {
        if (a > b)
        {
            printf("%.1f %.1f %.1f", c, a, b);
        }
        else
        {
            printf("%.1f %.1f %.1f", c, b, a);
        }
    }
    
    return 0;
}