/* 
 * You are given a sample array as input and your task
 * is to print the array in reversed order using pointer
 * arithmetic instead of indexing.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arrSize;
    scanf("%d", &arrSize);
    
    int* arr = malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for (int i = arrSize - 1; i >= 0; i--)
    {
        printf("%d ", *(arr + i));
    }
    
    free(arr);
    return 0;
}

