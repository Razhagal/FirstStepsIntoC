/* 
 * Write a program to perform a scalar multiplication of a vector.
 * You are given an input number representing the dimension of a
 * vector on the first input line. On the second input line,
 * you are given the scalar to multiply the vector and on the
 * next n lines, you are given the members of the vector.
 * 
 * [a * scalar, b * scalar, c * scalar]
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dimention, scalar;
    scanf("%d", &dimention);
    scanf("%d", &scalar);
    
    int* vector = malloc(dimention * sizeof(int));
    for (int i = 0; i < dimention; i++)
    {
        scanf("%d", &vector[i]);
        vector[i] *= scalar;
    }
    
    for (int i = 0; i < dimention; i++)
    {
        printf("%d ", vector[i]);
    }
    
    free(vector);
    return 0;
}

