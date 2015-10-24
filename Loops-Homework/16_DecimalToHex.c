/* 
 * Using loops write a program that converts an integer number to its
 * hexadecimal representation. The input is entered as long.
 * The output should be a variable of type string.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToHex(long decimalNum, char *buffer);
void reverseString(char *stringToReverse);

int main()
{
    long decimal;
    scanf("%ld", &decimal);
    
    char hexResult[64];
    decimalToHex(decimal, hexResult);
    printf("%s", hexResult);
    
    return 0;
}

void decimalToHex(long decimalNum, char *buffer)
{
    if (decimalNum == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }
    
    char hexValues[] = "0123456789ABCDEF";
    long index = 0;
    while(decimalNum > 0)
    {
        int valuesIndex = decimalNum % 16;
        buffer[index] = hexValues[valuesIndex];
        decimalNum /= 16;
        index++;
    }
    
    buffer[index] = '\0';
    reverseString(buffer);
}

void reverseString(char *stringToReverse)
{
    int length = strlen(stringToReverse);
    int loopEnd = strlen(stringToReverse) / 2;
    for (int i = 0; i < loopEnd; i++)
    {
        int temp = stringToReverse[i];
        stringToReverse[i] = stringToReverse[length - i - 1];
        stringToReverse[length - i - 1] = temp;
    }
}