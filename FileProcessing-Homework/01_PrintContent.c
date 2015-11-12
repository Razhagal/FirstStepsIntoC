/* 
 * Write a program that reads a text file and prints its contents on the console.
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
    
    char buffer[BUFFER_SIZE];
    while (!feof(file))
    {
        size_t readBytes = fread(buffer, 1, BUFFER_SIZE, file);
        printf("%s", buffer);
    }

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