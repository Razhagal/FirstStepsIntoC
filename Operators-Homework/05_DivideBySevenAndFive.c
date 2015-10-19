/* 
 * Write a Boolean expression that checks for given integer if it can be divided
 * (without remainder) by 7 and 5 in the same time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int number;
    scanf("%d", &number);
    
    bool result = number % 5 == 0 && number % 7 == 0;
    printf(result ? "true" : "false");
    
    return 0;
}

