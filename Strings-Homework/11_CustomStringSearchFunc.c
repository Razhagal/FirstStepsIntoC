/* 
 * Implement a function which checks whether a string appears as a
 * substring in another string. It should return 1 if the
 * string occurs and 0 if it does not.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strSearch(char* source, char* subString);

int main()
{
    printf("%d\n", strSearch("SoftUni", "Soft"));
    printf("%d\n", strSearch("Hard Rock", "Rock"));
    printf("%d\n", strSearch("Ananas", "nasa"));
    printf("%d\n", strSearch("Coolness", "cool"));
    
    return 0;
}

int strSearch(char* source, char* subString)
{
    size_t sourceLength = strlen(source);
    size_t searchedLength = strlen(subString);
    if (searchedLength > sourceLength)
    {
        return 0;
    }
    
    for (int i = 0; i < sourceLength; i++)
    {
        int j;
        for (j = 0; j < searchedLength; j++)
        {
            if (subString[j] != source[i + j])
            {
                break;
            }
        }
        
        if (j == searchedLength)
        {
            return 1;
        }
    }
    
    return 0;
}