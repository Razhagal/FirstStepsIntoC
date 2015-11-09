/* 
 * Write a function that reads an entire line from the standard input
 * stream (until end of line ('\n') or end of file (EOF) and returns
 * a pointer to the read string. The function should be able to
 * read lines of unknown size.
 */

#include <stdio.h>
#include <stdlib.h>

char* readLine();

int main()
{
    char* line = readLine();
    printf("%s", line);
    
    free(line);
    return 0;
}

char* readLine()
{
    int initialSize = 4;
    char *readline = malloc(initialSize);
    int index = 0;
    char ch = getchar();
    while (ch != '\n' && ch != EOF)
    {
        if (index == initialSize - 1)
        {
            char *newReadLine = realloc(readline, initialSize * 2);
            if (!newReadLine)
            {
                printf("Not enough memory!");
                exit(1);
            }
            
            readline = newReadLine;
            initialSize *= 2;
        }
        
        *(readline + index) = ch;
        index++;
        ch = getchar();
    }
    
    *(readline + index) = '\0';
    return readline;
}