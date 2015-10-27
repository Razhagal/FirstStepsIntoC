/* 
 * Write a function that reverses the digits of a given floating-point number.
 * The function should receive a double number and a pointer to an
 * integer variable. In case of format error,
 * it should set error to 1 and in case of success to 0.
 */

double reverse(char* numberAsString, int* error);

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{    
    char input[15];
    printf("number = ");
    fgets(input, 15, stdin);
    
    int errorCode;
    double reversed = reverse(input, &errorCode);
    
    if (!errorCode)
    {
        printf("%.3f", reversed);
    }
    else
    {
        printf("Invalid format");
    }
    
    return 0;
}

double reverse(char* numberAsString, int* error)
{
    int dotFound = 0;
    int inputLength = strlen(numberAsString);
    char reversedInput[15];
    for (int i = inputLength - 2; i >= 0; i--)
    {
        if (numberAsString[i] != '.')
        {
            if (isdigit(numberAsString[i]))
            {
                reversedInput[inputLength - i - 2] = numberAsString[i];
            }
            else
            {
                *error = 1;
                return 0;
            }
        }
        else
        {
            if (!dotFound)
            {
                reversedInput[inputLength - i - 2] = numberAsString[i];
                dotFound = 1;
            }
            else
            {
                *error = 1;
                return 0;
            }
        }
    }
        
    *error = 0;
    double reversedDouble = strtod(reversedInput, NULL);    
    return reversedDouble;
}