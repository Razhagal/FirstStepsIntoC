/* 
 * You are given n integers (given in a single line, separated by a space).
 * Write a program that checks whether the product of the odd elements is equal
 * to the product of the even elements. Elements are counted from 1 to n,
 * so the first element is odd, the second is even, etc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 40

int main()
{
    char input[BUFFER_SIZE];
    fgets(input, BUFFER_SIZE, stdin);
    
    int isOdd = 1;
    int oddProduct = 1;
    int evenProduct = 1;
    
    char *currentValue = strtok(input, " ");
    while (currentValue != NULL)
    {
        int parsedNum = atoi(currentValue);
        if (isOdd)
        {
            oddProduct *= parsedNum;
        }
        else
        {
            evenProduct *= parsedNum;
        }
        
        isOdd = !isOdd;
        currentValue = strtok(NULL, " ");
    }
    
    if (oddProduct == evenProduct)
    {
        printf("yes\n");
        printf("product = %d", oddProduct);
    }
    else
    {
        printf("no\n");
        printf("odd_product = %d\n", oddProduct);
        printf("even_product = %d", evenProduct);
    }
    
    
    
    return 0;
}

