/* 
 * Write a program that reads a text file and prints on the console its odd lines.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 4096

void kill(const char* message);

int main()
{
    FILE* file = fopen("SomeDocument", "r");
    if (!file)
    {
        kill(NULL);
    }
    
    char* line = NULL;
    size_t size = 0;
    int isOdd = 1;
    while (!feof(file))
    {
        size_t lineLength = getline(&line, &size, file);
        if (isOdd)
        {
            printf("%s", line);
        }
        
        isOdd = !isOdd;
    }

    free(line);
    fclose(file);    
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