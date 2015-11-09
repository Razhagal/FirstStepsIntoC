/* 
 * Write a program to generate the following matrix of
 * palindromes of 3 letters with r rows and c columns.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;
    if (scanf("%d %d", &rows, &cols) != 2)
    {
        printf("Invalid input.");
        return 1;
    }
    
    for (int row = 0; row < rows; row++)
    {
        char letter = 'a' + row;
        for (int col = 0; col < cols; col++)
        {
            printf("%c%c%c ", letter, letter + col, letter);
        }
        
        printf("\n");
    }
    
    return 0;
}

