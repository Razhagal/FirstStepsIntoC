/* 
 * Write an expression that checks if given
 * point (x, y) is inside a circle K({0, 0}, 2).
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
    
    float x, y, radius = 2.0f;
    printf("Enter X: ");
    scanf("%f", &x);
    
    printf("Enter Y: ");
    scanf("%f", &y);
    
    int insideCircle;
    if ((x * x) + (y * y) <= (radius * radius))
    {
        insideCircle = 1;
    }
    else
    {
        insideCircle = 0;
    }
    
    printf("Inside? %s", insideCircle ? "Yes" : "No");
    
    return 0;
}

