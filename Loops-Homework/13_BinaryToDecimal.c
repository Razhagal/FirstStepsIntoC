/* 
 * Using loops write a program that converts a binary integer number to its decimal form.
 * The input is entered as string.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 33

int main()
{
    char binaryInput[BUFFER_SIZE];
    fgets(binaryInput, BUFFER_SIZE, stdin);
    unsigned long decimalResult = 0;
    int currentBit = 0;
    
    int inputLength = strlen(binaryInput) - 2;
    for (int i = inputLength; i >= 0; i--)
    {
        if (binaryInput[i] == '1')
        {
            currentBit = 1;
        }
        else
        {
            currentBit = 0;
        }
        
        decimalResult += (currentBit * (1 << (inputLength - i)));
    }
    
    printf("%d", decimalResult);
    
    return 0;
}

