/* 
 * Write a program that asks for a digit (0-9), and depending on the input,
 * shows the digit as a word (in English). Print “not a digit” in case of invalid input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[5];
    fgets(input, 5, stdin);
    
    if (input[strlen(input) - 1] == '\n')
    {
        input[strlen(input) - 1] = '\0';
    }
    
    if (strlen(input) > 1)
    {
        printf("not a digit");
    }
    else
    {
        switch (input[0])
        {
            case '1': printf("one"); break;
            case '2': printf("two"); break;
            case '3': printf("three"); break;
            case '4': printf("four"); break;
            case '5': printf("five"); break;
            case '6': printf("six"); break;
            case '7': printf("seven"); break;
            case '8': printf("eight"); break;
            case '9': printf("nine"); break;
            default: printf("not a digit"); break;
        }
    }
    
    return 0;
}

