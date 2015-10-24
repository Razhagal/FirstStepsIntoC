/* 
 * Write a program that reads from the console a positive integer
 * number n (1 ≤ n ≤ 20) and prints a matrix holding the numbers
 * from 1 to n*n in the form of square spiral.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrixSize;
    printf("Enter matrix size: ");
    scanf("%d", &matrixSize);
    
    if (matrixSize < 1 || matrixSize > 20)
    {
        printf("The size of the matrix must be in the range from 1 to 20!");
    }
    else
    {
        int matrixEnd = matrixSize * matrixSize;
        // 1 -> right | 2 -> down | 3 -> left | 4 -> up
        int direction = 1;
        int counter = 1;
        int currentRow= 0;
        int currentCol = 0;

        int spiral[matrixSize][matrixSize];
        for (int row = 0; row < matrixSize; row++)
        {
            for (int col = 0; col < matrixSize; col++)
            {
                spiral[row][col] = 0;
            }
        }
        
        while (counter <= matrixEnd)
        {
            if (direction == 1)
            {
                spiral[currentRow][currentCol] = counter;
                currentCol++;
                if (currentCol == matrixSize || spiral[currentRow][currentCol] != 0)
                {
                    direction = 2;
                    currentCol--;
                    currentRow++;
                }
            }
            else if (direction == 2)
            {
                spiral[currentRow][currentCol] = counter;
                currentRow++;
                if (currentRow == matrixSize || spiral[currentRow][currentCol] != 0)
                {
                    direction = 3;
                    currentCol--;
                    currentRow--;
                }
            }
            else if (direction == 3)
            {
                spiral[currentRow][currentCol] = counter;
                currentCol--;
                if (currentCol < 0 || spiral[currentRow][currentCol] != 0)
                {
                    direction = 4;
                    currentCol++;
                    currentRow--;
                }
            }
            else if (direction == 4)
            {
                spiral[currentRow][currentCol] = counter;
                currentRow--;
                if (currentRow == 0 || spiral[currentRow][currentCol] != 0)
                {
                    direction = 1;
                    currentCol++;
                    currentRow++;
                }
            }
            
            counter++;
        }
        
        for (int row = 0; row < matrixSize; row++)
        {
            for (int col = 0; col < matrixSize; col++)
            {
                printf("%d ", spiral[row][col]);
            }
            
            printf("\n");
        }
    }
    
    return 0;
}

