/* 
 * You are given a square matrix of city names. Your task is to
 * print the names of those cities which are stationed on the
 * matrix's main diagonal. On the first input line you are given
 * the count of the rows. The names of the cities will
 * consist of one word only.
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
    char** array = calloc(n, sizeof(char*));
    if (!array)
    {
        printf("No memory to allocate.");
        exit(1);
    }
    
    for (int i = 0; i < n; i++)
    {
        char* line = NULL;
        size_t lineSize = 0;
        size_t lineLength = getline(&line, &lineSize, stdin);
        line[lineLength - 1] = '\0';
        
        char* token = strtok(line, " \t");
        int tokenCount = 0;
        while (tokenCount <= i)
        {
            if (tokenCount == i)
            {
                array[i] = calloc(lineLength + 1, sizeof(char));
                if (!array[i])
                {
                    printf("No memory to allocate.");
                    exit(1);
                }
                
                size_t tokenLength = strlen(token);
                strcpy(array[i], token);
                array[i][tokenLength] = '\0';
            }
            
            tokenCount++;
            token = strtok(NULL, " \t");
        }
        
        free(line);
    }
    
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", array[i]);
        free(array[i]);
    }
    
    free(array);
    return 0;
}

