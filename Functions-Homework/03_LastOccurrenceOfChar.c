/* 
 * Write a function that takes determines the position of the rightmost
 * occurrence of a character ch in a string str.
 * If no such character exists, the function should return -1.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getCharIndex(char *input, char searchedChar);

int main()
{
    char input[50];
    fgets(input, 50, stdin);
    char searchedChar = getchar();
    
    int index = getCharIndex(input, searchedChar);
    printf("Index = %d", index);
    
    return 0;
}

int getCharIndex(char* input, char searchedChar)
{
    int inputLength = strlen(input);
    for (int i = inputLength - 1; i >= 0; i--)
    {
        if (input[i] == searchedChar)
        {
            return i;
        }
    }
    
    return -1;
}