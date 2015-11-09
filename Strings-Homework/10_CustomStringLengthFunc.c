/* 
 * The standard C function size_t strlen(const char *s) returns
 * the size of the input string. Try implementing it yourself.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t strLength(char* str);

int main()
{
    printf("%lu\n", strlen("Soft"));
    printf("%lu\n", strlen("Johny Bravo"));
    
    char buffer[10] = { 'C', '\0', 'B', 'a', 'b', 'y' };
    printf("%lu\n", strlen(buffer));
    
    return 0;
}

size_t strLength(char* str)
{
    size_t length = 0;
    while (*str != '\0')
    {
        length++;
        *str++;
    }
    
    return length;
}