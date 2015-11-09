/* 
 * Write a program that extracts from a given text all palindromes,
 * e.g. ABBA, lamal, exe and prints them on the console on a single line,
 * separated by comma and space. Use spaces, commas, dots,
 * question marks and exclamation marks as word delimiters.
 * Print only unique palindromes, sorted lexicographically.
 * String comparison should be case-sensitive.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPalindrom(char* string);
char* reverseString(char* string);
int isContained(char** array, char* searched, int length);
void bubbleSort(char** array, int length);
char* toLowerString(char* str, size_t size);
void printArray(char** array, int length);

int main()
{
    char* text = NULL;
    size_t size = 0;
    int textLength = getline(&text, &size, stdin);
    text[textLength - 1] = '\0';
    textLength -= 1;
    
    char** palindromes = calloc(textLength, sizeof(char*));
    if (!palindromes)
    {
        printf("Cannot allocate enough memory.");
        exit(1);
    }
    
    char* token = strtok(text, " ,.?!");
    int index = 0;
    while (token)
    {
        if (isPalindrom(token))
        {
            int palindromLength = strlen(token);
            palindromes[index] = calloc(palindromLength + 1, sizeof(char));
            if (!palindromes[index])
            {
                printf("Cannot allocate enough memory.");
                exit(1);
            }
            
            int contains = isContained(palindromes, token, index);
            if (!contains)
            {
                strncat(palindromes[index], token, palindromLength);
                palindromes[index][palindromLength] = '\0';
                index++;
            }
            else
            {
                free(palindromes[index]);
            }
        }
        
        token = strtok(NULL, " ,.?!");
    }
    
    free(text);
    bubbleSort(palindromes, index);
    printArray(palindromes, index);
    
    for (int i = 0; i < index; i++)
    {
        free(palindromes[i]);
    }
    
    free(palindromes);
    return 0;
}

int isPalindrom(char* string)
{
    int isPalindrom = 0;
    char* reversed = reverseString(string);
    if (!strcmp(string, reversed))
    {
        isPalindrom = 1;
    }
    
    free(reversed);
    return isPalindrom;
}

char* reverseString(char* string)
{
    size_t stringLength = strlen(string);
    char* reversed = calloc(stringLength + 1, sizeof(char));
    if (!reversed)
    {
        printf("Cannot allocate enough memory.");
        exit(1);
    }
    
    int index = 0;
    for (int i = stringLength -1; i >= 0; i--)
    {
        reversed[index] = string[i];
        index++;
    }
    
    reversed[index] = '\0';
    return reversed;
}

int isContained(char** array, char* searched, int length)
{
    int isFound = 0;
    for (int i = 0; i < length; i++)
    {
        char* subString = strstr(array[i], searched);
        if (subString)
        {
            isFound = 1;
            break;
        }
    }
    
    return isFound;
}

void bubbleSort(char** array, int length)
{
    int hasSwapped = 1;
    while (hasSwapped)
    {
        hasSwapped = 0;
        for (int i = 0; i < length - 1; i++)
        {
            size_t currentStringLength = strlen(array[i]);
            char* currentString = toLowerString(array[i], currentStringLength);
            
            size_t nextStringLength = strlen(array[i + 1]);            
            char* nextString = toLowerString(array[i + 1], nextStringLength);            
            if (strcmp(currentString, nextString) > 0)
            {
                char* temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                hasSwapped = 1;
            }
        }
    }
}

char* toLowerString(char* str, size_t size)
{
    char* result = calloc(size + 1, sizeof(char));
    if (!result)
    {
        printf("No memory to allocate.");
        exit(1);
    }
    
    for (int i = 0; i < size; i++)
    {
        result[i] = tolower(str[i]);
    }
    
    result[size] = '\0';
    return result;
}

void printArray(char** array, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (i < length - 1)
        {
            printf("%s, ", array[i]);
        }
        else
        {
            printf("%s", array[i]);
        }
    }
}