/* 
 * Write an if-statement that takes two integer variables a and b and
 * exchanges their values if the first one is greater than the second one.
 * As a result print the values a and b, separated by a space.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
     * Disabling the buffer solves the issue with the first printf not showing before
     * the actual input and messing the whole output in the end
     */
    setbuf(stdout, NULL);
    
    float a, b;
    printf("Enter \"a\": ");
    scanf("%f", &a);
    printf("Enter \"b\": ");
    scanf("%f", &b);
    
    if (a > b)
    {
        float temp = a;
        a = b;
        b = temp;
    }
    
    printf("%.1f %.1f", a, b);
    
    return 0;
}

