/* 
 * Write a program to find how many times a given string appears
 * in a given text as substring. The text is given at the first
 * input line. The search string is given at the second input line.
 * The output is an integer number. Please ignore the character casing.
 * Overlapping between occurrences is allowed.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void stringTolower(char *str);

int main()
{
    char *input = NULL;
    char *searchedWord = NULL;
    size_t occurrencesCount = 0, size = 0;
    
    int inputLength = getline(&input, &size, stdin);
    input[inputLength - 1] = '\0';
    stringTolower(input);
    
    int searchedLength = getline(&searchedWord, &size, stdin);
    searchedWord[searchedLength - 1] = '\0';
    stringTolower(searchedWord);
    
    char *substr = strstr(input, searchedWord);
    while (substr)
    {
        occurrencesCount++;
        substr = strstr(&(*(substr + 1)), searchedWord);
    }
    
    printf("%lu", occurrencesCount);
    free(input);
    free(searchedWord);
    
    return 0;
}

void stringTolower(char *str)
{
    size_t length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        str[i] = tolower(str[i]);
    }
}