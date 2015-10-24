/* 
 * Using loops write a program that converts a hexadecimal integer number
 * to its decimal form. The input is entered as string.
 * The output should be a variable of type long.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 50

int main()
{
    char hexInput[BUFFER_SIZE];
    fgets(hexInput, BUFFER_SIZE, stdin);
    long long decimalResult = 0, sixteen = 1;
    size_t hexLength = strlen(hexInput);
    
    for (int i = hexLength - 2; i >= 0; i--)
    {
        int currentNum = 0;
        switch (hexInput[i])
        {
            case 'A': currentNum = 10; break;
            case 'B': currentNum = 11; break;
            case 'C': currentNum = 12; break;
            case 'D': currentNum = 13; break;
            case 'E': currentNum = 14; break;
            case 'F': currentNum = 15; break;
            default: currentNum = hexInput[i] - 48; break;
        }
        
        decimalResult += currentNum * sixteen;
        sixteen *= 16;
    }
    
    printf("%lld", decimalResult);
    
    return 0;
}

