/* 
 * Classical play cards use the following signs to designate the card face:
 * 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K and A.
 * Write a program that enters a string and prints “yes” if it
 * is a valid card sign or “no” otherwise.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[3];
    fgets(input, 3, stdin);
    size_t inputLength = strlen(input) - 1;
    if (input[inputLength] == '\n')
    {
        input[inputLength] = '\0';
    }
    
    if (input[0] == '1' && input[1] == '0' && input[2] == '\0')
    {
        printf("yes");
    }
    else if (input[1] == '\0')
    {
        switch (input[0])
        {
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'J':
            case 'Q':
            case 'K':
            case 'A':
                printf("yes");
                break;
            default:
                printf("no");
                break;     
        }
    }
    else
    {
        printf("no");
    }
    
    return 0;
}

