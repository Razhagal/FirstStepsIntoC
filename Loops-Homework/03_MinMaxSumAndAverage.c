/* 
 * Write a program that reads from the console a sequence of n integer
 * numbers and returns the minimal, the maximal number, the sum and
 * the average of all numbers (displayed with 2 digits after the decimal point).
 * The input starts by the number n (alone in a line) followed by n lines,
 * each holding an integer number.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;
    float average = 0;
    
    for (int i = 0; i < n; i++)
    {
        int currentNum = 0;
        scanf("%d", &currentNum);
        
        if (currentNum < min)
        {
            min = currentNum;
        }
        
        if (currentNum > max)
        {
            max = currentNum;
        }
        
        sum += currentNum;
    }
    
    average = (float)sum / n;
    printf("min = %.2f\n", (float)min);
    printf("max = %.2f\n", (float)max);
    printf("sum = %.2f\n", (float)sum);
    printf("avg = %.2f", average);
    
    return 0;
}

