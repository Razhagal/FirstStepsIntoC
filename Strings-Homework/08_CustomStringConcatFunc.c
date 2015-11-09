/* 
 * The standard C function strncat(char *dest, const char *src, size_t n)
 * concatenates the strings located in the src and the dest buffer
 * into the dest buffer. The variable n shows the length from the
 * src string to be concatenated. Try implementing that function yourself.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stringConcat(const char* source, char* destination, size_t length);

int main()
{
    char buffer[10] = "Soft";
    stringConcat("Uni", buffer, 7);
    printf("%s\n", buffer);
    
    return 0;
}

char* stringConcat(const char* source, char* destination, size_t length)
{
    size_t destinationLength = strlen(destination);
    for (int i = 0; i < length; i++)
    {
        if (source[i] != '\0')
        {
            destination[destinationLength + i] = source[i];
        }
        else
        {
            return destination;
        }
    }
    
    destination[destinationLength + length] = '\0';
    return destination;
}