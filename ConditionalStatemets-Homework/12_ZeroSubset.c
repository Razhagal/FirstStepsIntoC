/* 
 * We are given 5 integer numbers. Write a program that finds
 * all subsets of these numbers whose sum is 0. Assume that
 * repeating the same subset several times is not a problem.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[30];
    fgets(input, 30, stdin);
    int numbers[5];
    int combinationsCount = 1 << 5; // no need for pow()
    char currentSubset[] = "*****";
    int subsetFound = 0;
    
    int index = 0;
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        int number = atoi(token);
        numbers[index] = number;
        index++;
        token = strtok(NULL, " ");
    }
    
    for (int i = 0; i < combinationsCount; i++)
    {
        int currentSubsetSum = 0;
        index = 0;
        int subsetsCount = 0;
        for (int j = 0; j < 5; j++)
        {
            if (((1 << j) & i) != 0)
            {
                currentSubset[index] = numbers[j];
                currentSubsetSum += currentSubset[index];
                subsetsCount++;
                index++;
            }
        }
        
        if (subsetsCount > 0 && currentSubsetSum == 0)
        {
            subsetFound = 1;
            for (int k = 0; k < subsetsCount; k++)
            {
                if (currentSubset[k] != '*')
                {
                    if (k < subsetsCount - 1)
                    {
                        printf("%d + ", currentSubset[k]);
                    }
                    else
                    {
                        printf("%d ", currentSubset[k]);
                    }
                }
            }
            
            printf("= 0\n");
        }
        
        memset(currentSubset, '*', 5);
    }
    
    if (!subsetFound)
    {
        printf("no zero subset");
    }
    
    return 0;
}

