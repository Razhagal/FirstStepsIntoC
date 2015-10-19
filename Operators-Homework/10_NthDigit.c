/* 
 * Write a program that prints the n-th digit of a number (from right to left).
 * If no such digit exists, print a dash "-".
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /*
     * Disabling the buffer solves the issue with the first printf not showing before
     * the actual input and messing the whole output in the end
     */
    setbuf(stdout, NULL);
    
    int number, digitPosition;
    printf("Enter a number: ");
    scanf("%d", &number);
    
    printf("Enter a digit position: ");
    scanf("%d", &digitPosition);
    
    // Check if the number is big enough to have such position
    if (number < (pow(10, digitPosition)))
    {
        printf("-");
    }
    else
    {
        int counter = 1, numberAtPosition;
        while (counter < digitPosition)
        {
            number /= 10;
            counter++;
        }
        
        numberAtPosition = number % 10;
        printf("%d", numberAtPosition);
    }
    
    return 0;
}

