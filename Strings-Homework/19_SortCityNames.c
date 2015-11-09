/* 
 * You are given a list of cities. You have to process them and
 * sort them in ascending order. On the first input line, you are
 * given the count of the cities. Use an algorithm other than bubble sort.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(char** array, int length);

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
    
    printf("\n");
    selectionSort(array, n);
    for (int i = 0; i < index; i++)
    {
        printf("%s\n", array[i]);
        free(array[i]);
    }
    
    free(array);
    return 0;
}

void selectionSort(char** array, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (strcmp(array[i], array[j]) > 1)
            {
                char* temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}