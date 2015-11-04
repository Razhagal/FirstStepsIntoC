/* 
 * Write a program that reverses an array of numbers.
 * The numbers should be entered one at a line.
 * On the first input line you will be given the count of the numbers.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arrSize;
    scanf("%d", &arrSize);
    
    int arr[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int endIndex = arrSize / 2;
    for (int i = 0; i < endIndex; i++)
    {
        int temp = arr[i];
        arr[i] = arr[arrSize - 1 - i];
        arr[arrSize - 1 - i] = temp;
    }
    
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

