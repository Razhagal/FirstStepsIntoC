/* 
 * Using loops write a program that converts an integer number to its binary representation.
 * The input is entered as long. The output should be a variable of type string.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 32

int main()
{
    long decimalInput;
    scanf("%ld", &decimalInput);
    
    char binaryFormat[BUFFER_SIZE + 1];    
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        binaryFormat[i] = '0';
    }
    
    binaryFormat[BUFFER_SIZE] = '\0';
    for (int i = BUFFER_SIZE - 1; i >= 0; i--)
    {
        binaryFormat[i] = decimalInput & 1 == 1 ? '1' : '0';
        decimalInput >>= 1;
    }
    
    printf("%s", binaryFormat);
    
    return 0;
}

