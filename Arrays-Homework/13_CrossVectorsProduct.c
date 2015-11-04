/* 
 * [a1, a2, a3] x [b1, b2, b3] = [(a2*b3 – a3*b2), (a3*b1 – a1*b3), ( a1*b2 – a2*b1)]
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int vectorSize = 3;
    
    int* firstVector = malloc(vectorSize * sizeof(int));
    for (int i = 0; i < vectorSize; i++)
    {
        scanf("%d", &firstVector[i]);
    }
    
    int* secondVector = malloc(vectorSize * sizeof(int));
    for (int i = 0; i < vectorSize; i++)
    {
        scanf("%d", &secondVector[i]);
    }
    
    int* resultVector = malloc(vectorSize * sizeof(int));
    resultVector[0] = (firstVector[1] * secondVector[2]) - (firstVector[2] * secondVector[1]);
    resultVector[1] = (firstVector[2] * secondVector[0]) - (firstVector[0] * secondVector[2]);
    resultVector[2] = (firstVector[0] * secondVector[1]) - (firstVector[1] * secondVector[0]);
    
    printf("[%d, %d, %d]", resultVector[0], resultVector[1], resultVector[2]);
    
    free(firstVector);
    free(secondVector);
    free(resultVector);
    return 0;
}

