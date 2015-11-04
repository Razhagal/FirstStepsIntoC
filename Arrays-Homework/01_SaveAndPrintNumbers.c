/* 
 * Write a program that reads n numbers from the console and saves them in an array.
 * The program should then print the elements of the array on the console.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++)
    {
        int currentNum;
        scanf("%d", &currentNum);
        arr[i] = currentNum;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

