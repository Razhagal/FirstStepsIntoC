/* 
 * Write a program that copies the contents of a binary file
 * (e.g. image, video, etc.) to another file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 4096

void kill(const char* message);

int main()
{
    FILE* source = fopen("Puppies.jpg", "r");
    if (!source)
    {
        kill(NULL);
    }
    
    FILE* destination = fopen("Puppies-copy.jpg", "w");
    if (!destination)
    {
        kill(NULL);
    }
    
    char buffer[BUFFER_SIZE];
    while (!feof(source))
    {
        size_t readBytes = fread(buffer, 1, BUFFER_SIZE, source);
        fwrite(buffer, 1, readBytes, destination);
    }
    
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