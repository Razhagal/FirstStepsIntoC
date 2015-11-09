/* 
 * Write a program that takes as input two lists of names
 * and removes from the first list all names given in the
 * second list. The input and output lists are given as words,
 * separated by a space, each list at a separate line.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* firstList = NULL;
    char* secondList = NULL;
    size_t firstSize = 0;
    size_t secondSize = 0;
    
    size_t firstLength = getline(&firstList, &firstSize, stdin);
    size_t secondLength = getline(&secondList, &secondSize, stdin);
    
    char* token = strtok(secondList, " ");
    while (token)
    {
        size_t tokenLength = strlen(token);
        char* subStr = strstr(firstList, token);
        while (subStr)
        {
            int index = subStr - firstList;
            memmove(&firstList[index], &firstList[index + tokenLength + 1], firstLength - index);
            
            subStr = strstr(firstList, token);
        }
        
        token = strtok(NULL, " ");
    }
    
    printf("%s", firstList);
    
    free(firstList);
    free(secondList);
    return 0;
}

