/* 
 * Given an array of n integers, write a linear search function
 * that determines whether a given element exists in the array.
 * On the first line you will receive the number n.
 * On the second line, there will be n numbers, space-separated.
 * On the third line, the search number will be given.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{    
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int searchedNumber;
    scanf("%d", &searchedNumber);
    
    int isFound = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == searchedNumber)
        {
            isFound = 1;
            break;
        }
    }
    
    printf("%s", isFound ? "yes" : "no");
    
    return 0;
}

