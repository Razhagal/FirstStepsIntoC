/* 
 * Declare an array of integers and print it on the console. Do NOT use the indexer operator [].
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = { 2, 3, 5, 1, 3, 10 };
    int arrSize = sizeof(arr) / sizeof(int);
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", *(arr + i));
    }
    
    return 0;
}

