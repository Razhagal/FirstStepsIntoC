/* 
 * Implement a function which extracts a substring from a given
 * string by specifying the position from which to
 * extract and the length to extract.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* subStr(char* source, int position, int length);

int main()
{
    char* firstResult = subStr("Breaking Bad", 0, 2);
    printf("%s\n", firstResult);
    
    char* secondResult = subStr("Maniac", 3, 3);
    printf("%s\n", secondResult);
    
    char* thirdResult = subStr("Maniac", 3, 5);
    printf("%s\n", thirdResult);
    
    char* fourthResult = subStr("Master Yoda", 13, 5);
    printf("%s\n", fourthResult);
    
    free(firstResult);
    free(secondResult);
    free(thirdResult);
    free(fourthResult);
    return 0;
}

char* subStr(char* source, int position, int length)
{
    size_t sourceLength = strlen(source);
    if (position> sourceLength)
    {
        char* substr = malloc(1 * sizeof(char));
        substr[0] = '\0';
        return substr;
    }
    else if (position < 0)
    {
        printf("Invalid starting position %d", position);
        exit(1);
    }
    
    char* subString = calloc(length + 1, sizeof(char));
    if (!subString)
    {
        printf("Not enough memory.");
        exit(1);
    }
    
    for (int i = 0; i < length; i++)
    {
        subString[i] = source[position + i];
    }
    
    subString[length] = '\0';
    return subString;
}