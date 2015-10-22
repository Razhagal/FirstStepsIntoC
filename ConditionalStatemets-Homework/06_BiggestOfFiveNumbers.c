/* 
 * Write a program that finds the biggest of five numbers
 * by using only five if statements.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    setbuf(stdout, NULL);
    
    float a, b, c, d, e;
    printf("Enter \"a\": ");
    scanf("%f", &a);
    printf("Enter \"b\": ");
    scanf("%f", &b);
    printf("Enter \"c\": ");
    scanf("%f", &c);
    printf("Enter \"d\": ");
    scanf("%f", &d);
    printf("Enter \"e\": ");
    scanf("%f", &e);
    
    float biggestNum = a;
    if (b >= a && b >= c && b >= d && b >= e)
    {
        biggestNum = b;
    }
    else if (c >= a && c >= b && c >= d && c >= e)
    {
        biggestNum = c;
    }
    else if (d >= a && d >= b && d >= c && d >= e)
    {
        biggestNum = d;
    }
    else if (e >= a && e >= b && e >= c && e >= d)
    {
        biggestNum = e;
    }
    
    printf("Biggest is %.1f", biggestNum);
    
    return 0;
}

