/*
 * Write an expression that checks if given integer is odd or even.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    scanf("%d", &number);
    printf("%d", number % 2 == 0 ? 1 : 0);
    
    return 0;
}

