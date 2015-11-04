/* 
 * You are given a matrix of numbers. Your task is to print
 * out the numbers, one group at a line, which are stationed
 * beneath the matrix’s main diagonal along with the diagonal itself.
 * On the first input line, you are given the matrix’s rows and cols count.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrixSize;
    scanf("%d", &matrixSize);
    
    int** matrix = malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i] = malloc(matrixSize * sizeof(int));
    }
    
    int count = 1;
    for (int row = 0; row < matrixSize; row++)
    {
        for (int col = 0; col < matrixSize; col++)
        {
            matrix[row][col] = count;
            count++;
        }
    }
    
    for (int row = 0; row < matrixSize; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            printf("%d ", matrix[row][col]);
        }
        
        printf("\n");
    }
    
    // Free the memory
    for (int i = 0; i < matrixSize; i++)
    {
        free(matrix[i]);
    }
    
    free(matrix);
    
    return 0;
}

