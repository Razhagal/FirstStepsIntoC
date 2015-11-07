/* 
 * Write a function that takes a string as input and replaces
 * all occurrences of a digit (0-9) with a slash '/'.
 * The function should NOT modify the original string.
 * It should return the resulting string as result.
 * The function should also notify the calling function
 * how many digits were replaced.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* replaceDigits(char* line, int size, int* digitsCount);

int main()
{
    char *line;
    size_t size = 0;
    getline(&line, &size, stdin);
    int length = strlen(line);
    
    int digitsCount = 0;
    char* result = replaceDigits(line, length, &digitsCount);
    
    printf("In \"%s\" %d digits were replaced", result, digitsCount);
    
    free(line);
    free(result);
    return 0;
}

char* replaceDigits(char* line, int size, int* digitsCount)
{
    char* result = malloc(size * sizeof(char));
    for (int i = 0; i < size; i++)
    {
        if (isdigit(line[i]))
        {
            result[i] = '/';
            *digitsCount += 1;
        }
        else
        {
            result[i] = line[i];
        }
    }
    
    return result;
}