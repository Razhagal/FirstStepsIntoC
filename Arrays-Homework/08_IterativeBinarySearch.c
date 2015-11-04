#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int arrSize, int searchedElement);

int main()
{
    int arr[] = { 1, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 };
    int arrSize = 17;
    int searchedElement = 3;
    
    int index = binarySearch(arr, arrSize, searchedElement);
    printf("index = %d", index);
    
    return 0;
}

int binarySearch(int arr[], int arrSize, int searchedElement)
{
    int min = 0;
    int max = arrSize - 1;
    int midIndex = 0;
    while (max >= min)
    {
        midIndex = min + ((max - min) / 2);
        if (arr[midIndex] == searchedElement)
        {
            return midIndex;
        }
        else if (arr[midIndex] < searchedElement)
        {
            min = midIndex + 1;
        }
        else if (arr[midIndex] > searchedElement)
        {
            max = midIndex - 1;
        }
    }
    
    return 0;
}