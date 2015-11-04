#include <stdio.h>
#include <stdlib.h>

int binarySearchRecursive(int arr[], int searchedElement, int minIndex, int maxIndex);

int main()
{
    int arr[] = { 1, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 };
    int arrSize = 17;
    int searchedElement = 47;
    
    int index = binarySearchRecursive(arr, searchedElement, 0, arrSize - 1);
    printf("index = %d", index);
    return 0;
}

int binarySearchRecursive(int arr[], int searchedElement, int minIndex, int maxIndex)
{
    int midIndex = minIndex + ((maxIndex - minIndex) / 2);
    if (arr[midIndex] == searchedElement)
    {
        return midIndex;
    }
    else if (arr[midIndex] < searchedElement)
    {
        return binarySearchRecursive(arr, searchedElement, midIndex + 1, maxIndex);
    }
    else if (arr[midIndex] > searchedElement)
    {
        return binarySearchRecursive(arr, searchedElement, minIndex, midIndex - 1);
    }
}