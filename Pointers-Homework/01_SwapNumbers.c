/* 
 * Implement a function which takes as input two numbers and swaps their values.
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int* first, int* second);

int main()
{
    int firstNum, secondNum;
    scanf("%d %d", &firstNum, &secondNum);
    
    swap(&firstNum, &secondNum);
    printf("%d %d", firstNum, secondNum);
    
    return 0;
}

void swap(int* first, int* second)
{
    *first = *first ^ *second;
    *second = *first ^ *second;
    *first = *first ^ *second;
}