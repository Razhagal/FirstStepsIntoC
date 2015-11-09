/* 
 * Write a program that reads a string from the console and
 * replaces all series of consecutive identical letters with a single one.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* input = NULL;
    size_t size = 0;
    getline(&input, &size, stdin);
    
    size_t inputLength = strlen(input);
    char* result = calloc(inputLength - 1, sizeof(char));
    strncat(result, &input[0], 1);
    for (int i = 1; i < inputLength - 1; i++)
    {
        if (input[i] != input[i - 1])
        {
            strncat(result, &input[i], 1);
        }
    }
    
    free(input);
    size_t resultLength = strlen(result) + 1;
    char* newResult = realloc(result, resultLength);
    if (!newResult)
    {
        printf("No memory to allocate.");
        exit(1);
    }
    
    result = newResult;
    result[resultLength - 1] = '\0';
    printf("%s", result);
    
    free(result);
    return 0;
}

