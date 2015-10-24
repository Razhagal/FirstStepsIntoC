/* 
 * Write a program that reads from the console a positive
 * integer number n (1 ≤ n ≤ 20) and prints a matrix.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    
    for (int row = 0; row < n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            printf("%d ", row + col);
        }
        
        printf("\n");
    }
    
    return 0;
}

