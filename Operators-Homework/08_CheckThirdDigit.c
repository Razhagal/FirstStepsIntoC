/* 
 * Write an expression that checks for given integer if its
 * third digit from right-to-left is 7. Print true or false
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    scanf("%d", &number);
    
    if (number < 100)
    {
        printf("false");
    }
    else
    {
        int thirdDigit = (number / 100) % 10;
        if (thirdDigit == 7)
        {
            printf("true");
        }
        else
        {
            printf("false");
        }
    }
    
    return 0;
}

