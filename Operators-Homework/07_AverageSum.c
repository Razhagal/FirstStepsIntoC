/* 
 * Write a program that finds the average of the sum of 3 numbers.
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
    
    int firstNum, secondNum, thirdNum;
    printf("Enter 3 numbers separated by space:\n");
    scanf("%d %d %d", &firstNum, &secondNum, &thirdNum);
    
    int sum = firstNum + secondNum + thirdNum;
    printf("The average of three is %f", (sum / 3.0));
    
    return 0;
}

