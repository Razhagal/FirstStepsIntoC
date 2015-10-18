/*
* Write a program that reads the radius r of a circle
* and prints its perimeter and area formatted with 2 digits after the decimal point.
*/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265359

int main()
{
    float radius;
    printf("Enter radius:");
    scanf("%f", &radius);

    float perimeter = 2 * (PI * radius);
    float area = PI * (radius * radius);
    printf("Circle perimeter: %.2f; Area: %.2f", perimeter, area);

    return 0;
}
