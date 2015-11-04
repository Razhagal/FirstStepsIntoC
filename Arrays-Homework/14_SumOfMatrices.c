/* 
 * Write a program to calculate the sum of two matrices.
 * On the first 2 lines, you are given the dimensions of the
 * two matrices (In order for them to be added together,
 * they must be of the same dimensions). The first line represents
 * the rows of the matrices and the second one – the columns.
 * On the next input lines, you are given the members of the matrices.
 */

int** getMatrix(int rowsCount, int colsCount);
void fillMatrix(int** matrix, int rowsCount, int colsCount);
int** sumMatrices(int** firstMatrix, int** secondMatrix, int rowsCount, int colsCount);
void freeMatrixMemory(int** matrix, int rowsCount);

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;
    scanf("%d", &rows);
    scanf("%d", &cols);
    
    int** firstMatrix = getMatrix(rows, cols);
    fillMatrix(firstMatrix, rows, cols);
    
    int** secondMatrix = getMatrix(rows, cols);
    fillMatrix(secondMatrix, rows, cols);
    
    int** resultMatrix = sumMatrices(firstMatrix, secondMatrix, rows, cols);
    
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            printf("%d ", resultMatrix[row][col]);
        }
        
        printf("\n");
    }
    
    freeMatrixMemory(firstMatrix, rows);
    freeMatrixMemory(secondMatrix, rows);
    freeMatrixMemory(resultMatrix, rows);
    return 0;
}

int** getMatrix(int rowsCount, int colsCount)
{
    int** matrix = malloc(rowsCount * sizeof(int*));
    for (int i = 0; i < rowsCount; i++)
    {
        matrix[i] = malloc(colsCount * sizeof(int));
    }
    
    return matrix;
}

void fillMatrix(int** matrix, int rowsCount, int colsCount)
{
    for (int row = 0; row < rowsCount; row++)
    {
        for (int col = 0; col < colsCount; col++)
        {
            scanf("%d", &matrix[row][col]);
        }
    }
}

int** sumMatrices(int** firstMatrix, int** secondMatrix, int rowsCount, int colsCount)
{
    int** resultMatrix = getMatrix(rowsCount, colsCount);
    for (int row = 0; row < rowsCount; row++)
    {
        for (int col = 0; col < colsCount; col++)
        {
            resultMatrix[row][col] = firstMatrix[row][col] + secondMatrix[row][col];
        }
    }
    
    return resultMatrix;
}

void freeMatrixMemory(int** matrix, int rowsCount)
{
    for (int i = 0; i < rowsCount; i++)
    {
        free(matrix[i]);
    }
    
    free(matrix);
}