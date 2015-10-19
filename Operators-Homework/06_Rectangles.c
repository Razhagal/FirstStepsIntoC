/* 
 * Write an expression that calculates rectangle’s perimeter and area by given width and height.
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
    
    float width, height;
    
    printf("Enter rectangle width: ");
    scanf("%f", &width);
    printf("Enter rectangle height: ");
    scanf("%f", &height);
    
    float perimeter = (2 * width) + (2 * height);
    float area = width * height;
    
    printf("Rectangle perimeter: %.1f Area: %.1f", perimeter, area);
    
    return 0;
}

