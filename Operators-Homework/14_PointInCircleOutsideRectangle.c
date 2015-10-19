/* 
 * Write an expression that checks for given point (x, y)
 * if it is within the circle K({1, 1}, 1.5)
 * and out of the rectangle R(top=1, left=-1, width=6, height=2).
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
    
    double x, y;
    printf("Enter X: ");
    scanf("%lf", &x);
    
    printf("Enter Y: ");
    scanf("%lf", &y);
    
    double xCircle = 1;
    double yCircle = 1;
    double circleRadius = 1.5;
    
    double rectTopBorder = 1;
    double rectLeftBorder = -1;
    double rectWidth = 6;
    double rectHeight = 2;    
    double rectBottomBorder = rectTopBorder - rectHeight;
    double rectRightBorder = rectLeftBorder + rectWidth;
    
    int isInCircle = 0;
    int isInRectangle = 0;
    
    double xOffset = x - xCircle;
    double yOffset = y - yCircle;
    if ((xOffset * xOffset) + (yOffset * yOffset) <= circleRadius * circleRadius)
    {
        isInCircle = 1;
    }
    
    if ((x >= rectLeftBorder && x <= rectRightBorder) &&
        (y >= rectBottomBorder && y <= rectTopBorder))
    {
        isInRectangle = 1;
    }
    
    printf("Inside the circle and outside the rectangle? %s", (isInCircle && !isInRectangle) ? "Yes" : "No");
    
    return 0;
}

