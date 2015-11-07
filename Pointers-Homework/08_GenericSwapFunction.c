/* 
 * Write a function that takes 2 pointers and swaps
 * the memory they point to. The function should
 * also take the size of each memory piece and should work with any data type.
 */

#include <stdio.h>
#include <stdlib.h>

void swap(void* first, void* second, size_t size);

int main()
{
    char letter = 'B', symbol = '+';
    swap(&letter, &symbol, sizeof(char));
    printf("%c %c\n", letter, symbol);
    
    int a = 10, b = 6;
    swap(&a, &b, sizeof(int));
    printf("%d %d\n", a, b);
    
    double c = 3.14, d = 1.23456;
    swap(&c, &d, sizeof(double));
    printf("%.2lf %.2lf", c, d);
    return 0;
}

void swap(void* first, void* second, size_t size)
{
    char* firstPtr = first;
    char* secondPtr = second;
    for (int i = 0; i < size; i++)
    {
        char tmpByte = firstPtr[i];
        firstPtr[i] = secondPtr[i];
        secondPtr[i] = tmpByte;
    }
}