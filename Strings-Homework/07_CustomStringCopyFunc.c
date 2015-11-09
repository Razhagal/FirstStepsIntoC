/* 
 * The standard C function strncpy(char *dest, const char *src, size_t n)
 * copies a chunk from the src string to the dest buffer.
 * Try implementing that function manually. Try doing it without a
 * buffer, by returning a string created in the body of the function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stringCopy(const char* source, char* destination, size_t size);

int main()
{
    char firstDestination[8];
    memset(firstDestination, 0, 8 * sizeof(char));
    stringCopy("SoftUni", firstDestination, 7);
    printf("First example: %s\n", firstDestination);
    
    char secondDestination[8];
    memset(secondDestination, 0, 8 * sizeof(char));
    stringCopy("SoftUni", secondDestination, 3);
    printf("Second example: %s\n", secondDestination);
    
    char thirdDestination[8];
    memset(thirdDestination, 0, 8 * sizeof(char));
    stringCopy("C is cool", thirdDestination, 0);
    printf("Third example: %s\n", thirdDestination);
    
    return 0;
}

char* stringCopy(const char* source, char* destination, size_t size)
{
    int isEndOfSource = 0;
    for (int i = 0; i < size; i++)
    {
        if (source[i] == '\0')
        {
            isEndOfSource = 1;
        }
        
        if (isEndOfSource)
        {
            destination[i] = '\0';
        }
        else
        {
            destination[i] = source[i];
        }
    }
    
    return destination;
}