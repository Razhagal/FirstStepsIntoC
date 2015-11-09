/* 
 * Write a program that reads from the console a string
 * of maximum 20 characters. If the length of the string
 * is less than 20, the rest of the characters should be
 * filled with asterisks '*'. Print the resulting string on the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* input = NULL;
    size_t size = 0;
    getline(&input, &size, stdin);
    input[strlen(input) - 1] = '\0';
    
    char string[21];
    strncpy(string, input, 20);
    string[20] = '\0';
    size_t length = strlen(string);
    if (length < 20)
    {
        int count = 20 - length;
        char asterixes[count];
        memset(asterixes, '*', count);
        strncat(string, asterixes, count);
    }
    
    printf("%s", string);
    free(input);
    return 0;
}

