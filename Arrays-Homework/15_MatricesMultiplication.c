/* 
 * On the first two input lines you are given the dimensions of the first matrix.
 * The second matrix has the same dimensions in inversed order.
 * 
 * | a1, a2, a3 |   | b1, b2 |   | (a1*b1 + a2*b4 + a3*b7) , (a1*b2 + a2*b5 + a3*b8) |
 * | a4, a5, a6 | x | b4, b5 | = | (a4*b1 + a5*b4 + a6*b7) , (a4*b2 + a5*b5 + a6*b8) |
 *                  | b7, b8 |
 */

#include <stdio.h>
#include <stdlib.h>

int** getMatrix(int rowsCount, int colsCount);
void fillMatrix(int** matrix, int rowsCount, int colsCount);
int** multiplyMatrices(int** firstMatrix, int** secondMatrix, int rowsCount, int colsCount);
void freeMatrixMemory(int** matrix, int rowsCount);

int main()
{
    int rows, cols;
    scanf("%d", &rows);
    scanf("%d", &cols);
    
    int** firstMatrix = getMatrix(rows, cols);
    fillMatrix(firstMatrix, rows, cols);
    
    int** secondMatrix = getMatrix(cols, rows);
    fillMatrix(secondMatrix, cols, rows);
    
    int** resultMatrix = multiplyMatrices(firstMatrix, secondMatrix, rows, cols);
    
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < rows; col++)
        {
            printf("%d ", resultMatrix[row][col]);
        }
        
        printf("\n");
    }
    
    freeMatrixMemory(firstMatrix, rows);
    freeMatrixMemory(secondMatrix, cols);
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

int** multiplyMatrices(int** firstMatrix, int** secondMatrix, int rowsCount, int colsCount)
{
    int** resultMatrix = getMatrix(rowsCount, rowsCount);
    for (int row = 0; row < rowsCount; row++)
    {
        for (int col = 0; col < rowsCount; col++)
        {
            int currentCellValue = 0;
            int currentRow = col;
            for (int currentCol = 0; currentCol < colsCount; currentCol++)
            {
                // second matrix: currentCol is the row and currentRow is the col
                currentCellValue += (firstMatrix[row][currentCol] * secondMatrix[currentCol][currentRow]);
            }
            
            resultMatrix[row][col] = currentCellValue;
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