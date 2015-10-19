/* 
 * Write a program that that prints if the number is both greater than 20 and odd.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    scanf("%d", &number);
    
    printf("%d", (number > 20 && number % 2 != 0) ? 1 : 0);
    return 0;
}

