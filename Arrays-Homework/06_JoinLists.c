/* 
 * Write a program that takes as input two arrays of integers
 * and joins them. The result should hold all numbers from
 * the first array, and all numbers from the second array,
 * without repeating numbers, and arranged in increasing order.
 * On the first input line, you are given the count of the elements
 * of the first array. On the next line you are given the length of the second array.
 */

#include <stdio.h>
#include <stdlib.h>

void joinArrays(int resultArr[], int resultArrSize, int firstArr[], int firstArrSize, int secondArr[], int secondArrSize);
int countUniqueElements(int firstArr[], int firstArrSize, int secondArr[], int secondArrSize);
int isContainedInArray(int arr[], int lastIndex, int element);
void sort(int arrToSort[], int arrSize);

int main()
{
    int firstArrSize, secondArrSize;
    scanf("%d", &firstArrSize);
    scanf("%d", &secondArrSize);
    
    int* firstArr = malloc(firstArrSize * sizeof(int));
    for (int i = 0; i < firstArrSize; i++)
    {
        scanf("%d", &firstArr[i]);
    }
    
    int* secondArr = malloc(secondArrSize * sizeof(int));
    for (int i = 0; i < secondArrSize; i++)
    {
        scanf("%d", &secondArr[i]);
    }
    
    int countTotal = countUniqueElements(firstArr, firstArrSize, secondArr, secondArrSize);
    int* resultArr = malloc(countTotal * sizeof(int));
    joinArrays(resultArr, countTotal, firstArr, firstArrSize, secondArr, secondArrSize);
    sort(resultArr, countTotal);
    
    for (int i = 0; i < countTotal; i++)
    {
        printf("%d ", resultArr[i]);
    }
    
    free(firstArr);
    free(secondArr);
    free(resultArr);
    return 0;
}

int isContainedInArray(int arr[], int lastIndex, int element)
{
    for (int i = 0; i < lastIndex; i++)
    {
        if (arr[i] == element)
        {
            return 1;
        }
    }
    
    return 0;
}

int countUniqueElements(int firstArr[], int firstArrSize, int secondArr[], int secondArrSize)
{
    int totalSize = firstArrSize + secondArrSize;
    int tempArr[totalSize];
    int tempIndex = 0;
    for (int i = 0; i < totalSize; i++)
    {
        if (i < firstArrSize)
        {
            tempArr[i] = firstArr[i];
        }
        else
        {
            tempArr[i] = secondArr[tempIndex];
            tempIndex++;
        }
    }
    
    int count = 1;
    for (int i = 1; i < firstArrSize; i++)
    {
        if (!isContainedInArray(tempArr, i, firstArr[i]))
        {
            count++;
        }
    }
    
    tempIndex = firstArrSize - 1;
    for (int i = 0; i < secondArrSize; i++)
    {
        if (!isContainedInArray(tempArr, tempIndex, secondArr[i]))
        {
            count++;
            tempIndex++;
        }
    }
    
    return count;
}

void joinArrays(int resultArr[], int resultArrSize, int firstArr[], int firstArrSize, int secondArr[], int secondArrSize)
{
    int tempIndex = 0;
    for (int i = 0; i < firstArrSize; i++)
    {
        if (!isContainedInArray(resultArr, i, firstArr[i]))
        {
            resultArr[tempIndex] = firstArr[i];
            tempIndex++;
        }
    }
    
    for (int i = 0; i < secondArrSize; i++)
    {
        if (!isContainedInArray(resultArr, tempIndex, secondArr[i]))
        {
            resultArr[tempIndex] = secondArr[i];
            tempIndex++;
        }
    }
}

void sort(int arrToSort[], int arrSize)
{
    // insertion sort magic going on in here    
    for (int i = 2; i < arrSize; i++)
    {
        for (int k = i; k >= 1; k--)
        {
            if (arrToSort[k] < arrToSort[k - 1])
            {
                arrToSort[k] =  arrToSort[k] ^ arrToSort[k - 1];
                arrToSort[k - 1] = arrToSort[k] ^ arrToSort[k - 1];
                arrToSort[k] = arrToSort[k] ^ arrToSort[k - 1];
            }
        }
    }
}