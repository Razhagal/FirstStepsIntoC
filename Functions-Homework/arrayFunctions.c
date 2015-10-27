#include <stdlib.h>
#include <stdio.h>

#include "arrayFunctions.h"

int arr_min(int arr[], int length)
{
    int min = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    
    return min;
}

int arr_max(int arr[], int length)
{
    int max = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    
    return max;
}

void arr_clear(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = 0;
    }
}

int arr_sum(int arr[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += arr[i];
    }
    
    return sum;
}

float arr_average(int arr[], int length)
{
    int sum = arr_sum(arr, length);
    float average = (float)sum / length;
    
    return average;
}

int arr_contains(int arr[], int length, int element)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == element)
        {
            return 1;
        }
    }
    
    return 0;
}

int* arr_merge(int firstArr[], int firstArrLength, int secondArr[], int secondArrLength)
{
    int newArrSize = firstArrLength + secondArrLength;
    int *mergedArr = (int *)malloc(sizeof(int) * newArrSize);    
    for (int i = 0; i < newArrSize; i++)
    {
        if (i < firstArrLength)
        {
            mergedArr[i] = firstArr[i];
        }
        else
        {
            mergedArr[i] = secondArr[i - firstArrLength];
        }
    }
    
    return mergedArr;
}