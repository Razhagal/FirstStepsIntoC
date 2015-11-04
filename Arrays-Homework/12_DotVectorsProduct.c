/* 
 * You are given the length n of each of the vectors
 * on the first input line (In order to perform a dot
 * product of two vectors, they have to be with equal dimensions).
 * On the next n lines, you are given the members of the first vector,
 * and on the next n ones, the members of the second one.
 * 
 * product = (a1 * b1) + (a2 * b2) + (a3 * b3)
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vectorSize;
    scanf("%d", &vectorSize);
    
    int* firstVector = malloc(vectorSize * sizeof(int));
    for (int i = 0; i < vectorSize; i++)
    {
        scanf("%d", &firstVector[i]);
    }
    
    int product = 0;
    int* secondVector = malloc(vectorSize * sizeof(int));
    for (int i = 0; i < vectorSize; i++)
    {
        scanf("%d", &secondVector[i]);
        product += (firstVector[i] * secondVector[i]);
    }
    
    printf("product = %d", product);
    
    free(firstVector);
    free(secondVector);
    return 0;
}

