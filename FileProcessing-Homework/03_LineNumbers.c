/* 
 * Write a program that reads a text file and inserts
 * line numbers in front of each of its lines. The result
 * should be written to another text file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void kill(const char* message);

int main()
{
    FILE* source = fopen("SomeDocument", "r");
    if (!source)
    {
        kill(NULL);
    }
    
    FILE* destination = fopen("ResultDocument.txt", "w");
    if (!destination)
    {
        kill(NULL);
    }
    
    char* line = NULL;
    size_t size = 0;
    size_t lineNum = 1;
    while (1)
    {
        size_t lineLength = getline(&line, &size, source);
        if (feof(source))
        {
            break;
        }
        
        char lineNumber[4];
        int num = sprintf(lineNumber, "%-4lu ", lineNum);
        fwrite(lineNumber, 1, num, destination);
        fwrite(line, 1, lineLength, destination);
        
        lineNum++;
    }
    
    free(line);
    fclose(source);
    fclose(destination);
    return 0;
}

void kill(const char* message)
{
    if (errno)
    {
        perror(message);
    }
    else
    {
        printf("Error: %s\n", message);
    }
    
    exit(1);
}