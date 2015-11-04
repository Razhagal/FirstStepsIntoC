/* 
 * Write a program that reads N floating-point numbers from the console.
 * Your task is to separate them in two sets, one containing only the
 * round numbers (e.g. 1, 1.00, etc.) and the other containing the
 * floating-point numbers with non-zero fraction.
 * Print both arrays along with their minimum, maximum, sum and average (rounded to two decimal places).
 * The numbers should be entered one at a line. On the first input line
 * you will be given the count of the numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getWholeNumbersCount(float arr[], int arrSize);
float getMinValue(float arr[], int arrSize);
float getMaxValue(float arr[], int arrSize);
float getSum(float arr[], int arrSize);
float getAverage(float arr[], int arrSize);

int main()
{
    int n;
    scanf("%d", &n);
    
    float* inputNumbers = malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &inputNumbers[i]);
    }
    
    int countOfWholeNumbers = getWholeNumbersCount(inputNumbers, n);
    int countOfDecimalNumbers = n - countOfWholeNumbers;
    float* wholeNumbers = malloc(countOfWholeNumbers * sizeof(float));
    float* decimalNumbers = malloc(countOfDecimalNumbers * sizeof(float));
    
    int wholeIndex = 0;
    int decimalIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (fmod(inputNumbers[i], 1) == 0)
        {
            wholeNumbers[wholeIndex] = inputNumbers[i];
            wholeIndex++;
        }
        else
        {
            decimalNumbers[decimalIndex] = inputNumbers[i];
            decimalIndex++;
        }
    }
    
    float wholeNumbersMin = getMinValue(wholeNumbers, countOfWholeNumbers);
    float wholeNumbersMax = getMaxValue(wholeNumbers, countOfWholeNumbers);
    float wholeNumbersSum = getSum(wholeNumbers, countOfWholeNumbers);
    float wholeNumbersAverage = wholeNumbersSum != 0 ? wholeNumbersSum / countOfWholeNumbers : 0;
    
    printf("[");
    for (int i = 0; i < countOfWholeNumbers; i++)
    {
        printf("%.0f", wholeNumbers[i]);
        if (i < countOfWholeNumbers - 1)
        {
            printf(", ");
        }
    }
    
    printf("] -> min: %.0f, max: %.0f, sum: %.0f, avg: %.2f\n",
            wholeNumbersMin, wholeNumbersMax, wholeNumbersSum, wholeNumbersAverage);
    
    float decimalNumbersMin = getMinValue(decimalNumbers, countOfDecimalNumbers);
    float decimalNumbersMax = getMaxValue(decimalNumbers, countOfDecimalNumbers);
    float decimalNumbersSum = getSum(decimalNumbers, countOfDecimalNumbers);
    float decimalNumbersAverage = decimalNumbersSum != 0 ? decimalNumbersSum / countOfDecimalNumbers : 0;
    
    printf("[");
    for (int i = 0; i < countOfDecimalNumbers; i++)
    {
        printf("%f", decimalNumbers[i]);
        if (i < countOfDecimalNumbers - 1)
        {
            printf(", ");
        }
    }
    
    printf("] -> min: %f, max: %f, sum: %f, avg: %.2f",
            decimalNumbersMin, decimalNumbersMax, decimalNumbersSum, decimalNumbersAverage);
    
    free(inputNumbers);
    free(wholeNumbers);
    free(decimalNumbers);
    
    return 0;
}

int getWholeNumbersCount(float arr[], int arrSize)
{
    int count = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (fmod(arr[i], 1) == 0)
        {
            count++;
        }
    }
    
    return count;
}

float getMinValue(float arr[], int arrSize)
{
    float min = arr[0];
    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    
    return min;
}

float getMaxValue(float arr[], int arrSize)
{
    float max = arr[0];
    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    
    return max;
}

float getSum(float arr[], int arrSize)
{
    float sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        sum += arr[i];
    }
    
    return sum;
}

float getAverage(float arr[], int arrSize)
{
    float sum = getSum(arr, arrSize);
    return sum == 0 ? sum / arrSize : 0;
}