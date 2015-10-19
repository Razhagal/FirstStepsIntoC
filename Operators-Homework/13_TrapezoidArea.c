/* 
 * Write an expression that calculates trapezoid's area by given sides a and b and height h.
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
    
    float a, b, height;
    printf("Enter A: ");
    scanf("%f", &a);
    
    printf("Enter B: ");
    scanf("%f", &b);
    
    printf("Enter Height: ");
    scanf("%f", &height);
    
    float area = ((a + b) / 2) * height;
    printf("The trapezoid area is %.2f", area);
    
    return 0;
}

