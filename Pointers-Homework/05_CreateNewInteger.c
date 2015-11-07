/* 
 * Write a function that declares and initializes and integer
 * on the stack, then returning it. Try creating the
 * function with two different declarations.
 */

#include <stdio.h>
#include <stdlib.h>

int newInteger();
int* newIntegerPtr();

int main()
{
    int first = newInteger();
    printf("%d\n", first);
    
    int* second = newIntegerPtr();
    printf("%d", *second);
    
    free(second);
    return 0;
}

int newInteger()
{
    int num = 22;
    
    return num;
}

int* newIntegerPtr()
{
    int* newInt = malloc(sizeof(int));
    *newInt = 15;
    
    return newInt;
}