/* 
 * Write a function that takes a pointer of any type,
 * size of bytes n and row length len. The function should print
 * a total of n bytes, starting from the address of the pointer.
 * The output should be formatted into several rows, each holding
 * len bytes. At the start of each row, print the address of the initial byte.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void memoryDump(void* array, size_t size, int rowLength);

int main()
{
    char* text = "I love to break free";
    int arr[] = { 7, 3, 2, 10, -5 };
    size_t size = sizeof(arr) / sizeof(int);
    
    memoryDump(text, strlen(text) + 1, 5);
    printf("\n");
    memoryDump(arr, size * sizeof(int), 4);
    
    return 0;
}

void memoryDump(void* array, size_t size, int rowLength)
{
    char* arrPtr = array;
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            printf("%p    ", &arrPtr[i]);
        }
        else if (i % rowLength == 0)
        {
            printf("\n%p    ", &arrPtr[i]);
        }
        
        printf("%02hhx ", *arrPtr);
        arrPtr++;
    }
}