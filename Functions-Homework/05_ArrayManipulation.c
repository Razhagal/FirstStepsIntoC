/* 
 * Declare the following functions in a header file (.h).
 * Implement them in a separate .c file. Include the .h file in your 
 * main program and demonstrate the written functions.
 * - arr_min() - returns the smallest element in the array
 * - arr_max() - returns the largest element in the array
 * - arr_clear() - sets all array elements to 0
 * - arr_average() - returns the average of all elements
 * - arr_sum() - returns the sum of all array elements
 * - arr_contains() - returns whether the array contains the specified element
 * - arr_merge() - receives two arrays, merges them into one and returns a pointer to the resulting array
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayFunctions.h"

int main()
{
    int testArr[] = { 2, 3, 1, 6, 9, 5 };
    int testArrLength = sizeof(testArr) / sizeof(int);
    
    int minValue = arr_min(testArr, testArrLength);
    printf("Min = %d\n", minValue);
    
    int maxValue = arr_max(testArr, testArrLength);
    printf("Max = %d\n", maxValue);
    
    printf("Array elements before clear:\n");
    for (int i = 0; i < testArrLength; i++)
    {
        printf("%d ", testArr[i]);
    }
    
    printf("\n");
    
    arr_clear(testArr, testArrLength);
    printf("Array elements after clear:\n");
    for (int i = 0; i < testArrLength; i++)
    {
        printf("%d ", testArr[i]);
    }
    
    printf("\n");
    
    int firstArr[] = { 2, 3, 1, 6, 9, 5 };
    int firstArrLength = sizeof(firstArr) / sizeof(int);
    
    int sumValue = arr_sum(firstArr, firstArrLength);
    printf("Sum = %d\n", sumValue);
    
    float averageValue = arr_average(firstArr, firstArrLength);
    printf("Average = %.2f\n", averageValue);
    
    int numberToFind = 3;
    int isContained = arr_contains(firstArr, firstArrLength, numberToFind);
    if (isContained)
    {
        printf("%d is contained in the array\n", numberToFind);
    }
    else
    {
        printf("%d is not contained in the array\n", numberToFind);
    }
    
    int secondArr[] = { 10, 15, 22, 4 };
    int secondArrLength = sizeof(secondArr) / sizeof(int);
    
    int* mergedArr = arr_merge(firstArr, firstArrLength, secondArr, secondArrLength);
    
    //sizeof(mallocMemory) will return the size of the pointer itself
    int mergedArrLength = firstArrLength + secondArrLength;
    printf("Merged array elements:\n");
    for (int i = 0; i < mergedArrLength; i++)
    {
        printf("%d ", mergedArr[i]);
    }
    
    free(mergedArr);
    return 0;
}

