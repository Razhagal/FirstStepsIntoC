/* 
 * Write a program to find the longest area of equal elements
 * in array of strings. You first should read an integer n and
 * n strings (each at a separate line), then find and print the
 * longest sequence of equal elements (first its length, then its elements).
 * If multiple sequences have the same maximal length, print the leftmost of them.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input.");
        exit(1);
    }
    
    getchar();
    size_t index = 0;
    char** array = calloc(n, sizeof(char*));
    if (!array)
    {
        printf("No memory to allocate.");
        exit(1);
    }
    
    while (index < n)
    {
        char* line = NULL;
        size_t lineSize = 0;
        size_t lineLength = getline(&line, &lineSize, stdin);
        line[lineLength - 1] = '\0';
        
        array[index] = calloc(lineLength + 1, sizeof(char));
        if (!array[index])
        {
            printf("No memory to allocate.");
            exit(1);
        }
        
        strcpy(array[index], line);
        free(line);
        index++;
    }
    
    int longestSequenceLength = 1;
    int currentSequenceLength = 1;
    char* longestSequence = array[0];
    char* currentSequence = longestSequence;
    
    for (int i = 1; i < n; i++)
    {
        if (i != n - 1 &&
            strcmp(array[i], currentSequence) == 0)
        {
            currentSequenceLength++;
        }
        else
        {
            if (strcmp(array[i], currentSequence) == 0)
            {
                currentSequenceLength++;
            }
            
            if (currentSequenceLength > longestSequenceLength)
            {
                longestSequenceLength = currentSequenceLength;
                longestSequence = currentSequence;
            }
        
            currentSequence = array[i];
            currentSequenceLength = 1;
        }
    }
    
    printf("%d\n", longestSequenceLength);
    for (int i = 0; i < longestSequenceLength; i++)
    {
        printf("%s\n", longestSequence);
    }
    
    for (int i = 0; i < index; i++)
    {
        free(array[i]);
    }
    
    free(array);
    return 0;
}

