/* 
 * Write a program that takes any file and slices it to n parts.
 * Write the following functions:
 * - slice(const char *sourceFile, const char *destinationFile, size_t parts) - slices
 *      the given source file into n parts and saves them in destinationDirectory.
 * - assemble(const char **parts, const char *destinationDirectory) - combines all
 *      parts into one, in the order they are passed, and saves the result in destinationDirectory.
 * 
 * The input file names, destination directory and parts should be
 * passed to the program as arguments. The program should produce proper
 * error messages in case of errors. Use buffered reading.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 4096

void kill(const char* message);
void slice(const char* srcFilePath, const char* destFilePath, size_t partsCount);
void assemble(char** parts, const char* destinationDir, size_t partsCount);

int main(int argc, char **argv)
{
    char* sourcePath = argv[1];
    char* destinationPath = argv[2];
    int partsCount = atoi(argv[3]);
    
    slice(sourcePath, destinationPath, partsCount);
    
    char** partsArr = calloc(partsCount, sizeof(char*));
    if (!partsArr)
    {
        printf("No memory to allocate");
        exit(1);
    }
    
    int i;
    for (i = 0; i < partsCount; i++)
    {
        size_t destLength = strlen(destinationPath);
        partsArr[i] = calloc(11 + destLength, sizeof(char));
        if (!partsArr[i])
        {
            printf("No memory to allocate");
            exit(1);
        }
        
        sprintf(partsArr[i], "%s-Part-%d.jpg", destinationPath, i);
    }
    
    assemble(partsArr, destinationPath, partsCount);
    
    for (i = 0; i < partsCount; i++)
    {
        free(partsArr[i]);
    }
    
    free(partsArr);
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

void slice(const char* srcFilePath, const char* destFilePath, size_t partsCount)
{
    FILE* sourceFile = fopen(srcFilePath, "r");
    if (!sourceFile)
    {
        kill(NULL);
    }
    
    fseek(sourceFile, 0, SEEK_END);
    unsigned long long size = ftell(sourceFile);
    fseek(sourceFile, 0, SEEK_SET);
    
    unsigned long long partSize = size / partsCount;
    char buffer[BUFFER_SIZE];
    int i;
    for (i = 0; i < partsCount; i++)
    {
        char name[30];
        sprintf(name, "%s-Part-%d.jpg", destFilePath, i);
        FILE* currentFile = fopen(name, "w");
        if (!currentFile)
        {
            kill(NULL);
        }
        
        size_t writtenBytes = 0;
        while (!feof(sourceFile) && writtenBytes <= partSize)
        {
            size_t readBytes = fread(buffer, 1, BUFFER_SIZE, sourceFile);
            fwrite(buffer, 1, readBytes, currentFile);
            writtenBytes += readBytes;
        }
        
        fclose(currentFile);
    }
    
    fclose(sourceFile);
}

void assemble(char** parts, const char* destinationDir, size_t partsCount)
{
    char name[30];
    sprintf(name, "%s-assembled.jpg", destinationDir);
    
    FILE* resultFile = fopen(name, "w");
    if (!resultFile)
    {
        kill(NULL);
    }
    
    
    char buffer[BUFFER_SIZE];
    int i;
    for (i = 0; i < partsCount; i++)
    {
        FILE* currentPart = fopen(parts[i], "r");
        if (!currentPart)
        {
            kill(NULL);
        }
        
        while (!feof(currentPart))
        {
            size_t readBytes = fread(buffer, 1, BUFFER_SIZE, currentPart);
            fwrite(buffer, 1, readBytes, resultFile);
        }
        
        fclose(currentPart);
    }
    
    fclose(resultFile);
}