/* 
 * Write a method that returns the index of the first element in array
 * that is larger than its neighbours, or -1 if there's no such element.
 */

#include <stdio.h>
#include <stdlib.h>

int getLargerThanNeighboursIndex(int arr[], int length);

int main()
{
    int testArr[] = { 1, 3, 4, 5, 1, 0, 5 };
    int testArrLength = sizeof(testArr) / sizeof(int);
    
    int index = getLargerThanNeighboursIndex(testArr, testArrLength);    
    printf("Index of the first larger number than its neighbours is %d", index);
    
    return 0;
}

int getLargerThanNeighboursIndex(int arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        if (arr[i] > arr[i - 1] &&
            arr[i] > arr[i + 1])
        {
            return i;
        }
    }
    
    return - 1;
}