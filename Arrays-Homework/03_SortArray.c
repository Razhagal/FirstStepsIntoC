/* 
 * Write a program to read an array of numbers from the console,
 * sort them and print them back on the console.
 * Use a sorting algorithm of your choosing.
 * The numbers should be entered one at a line.
 * On the first input line you will be given the count of the numbers.
 */

#include <stdio.h>
#include <stdlib.h>

void sort(int arrToSort[], int arrSize);

int main()
{
    int arrSize;
    scanf("%d", &arrSize);
    
    int* arr = malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++)
    {
        int currentNum;
        scanf("%d", &currentNum);
        arr[i] = currentNum;
    }
    
    sort(arr, arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }
    
    free(arr);
    
    return 0;
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