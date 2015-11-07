/* 
 * Write a function that reads an entire line from the standard
 * input stream (console) and returns a pointer to the read string.
 * The function should be able to read lines of unknown size.
 */

#include <stdio.h>
#include <stdlib.h>

char* readLine();

int main()
{
    char* line = readLine();
    printf("%s", line);
    return 0;
}

char* readLine()
{
    int initialSize = 4;
    char* readline = malloc(initialSize);
    int index = 0;
    char ch = getchar();
    while (ch != '\n')
    {
        if (index == initialSize - 1)
        {
            char* newReadline = realloc(readline, initialSize * 2);
            if (!newReadline)
            {
                printf("Not enough memory.");
                exit(1);
            }
            
            readline = newReadline;
            initialSize *= 2;
        }
        
        *(readline + index) = ch;
        index++;
        ch = getchar();
    }

    *(readline + index) = '\0';
    return readline;
}