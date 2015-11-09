/* 
 * Write a program that reads a string from the console,
 * reverses it and prints the result back at the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* input = NULL;
    size_t size = 0;
    getline(&input, &size, stdin);
    size_t inputLength = strlen(input);
    char reversed[inputLength];
    
    int index = 0;
    for (int i = inputLength - 2; i >= 0; i--)
    {
        reversed[index] = input[i];
        index += 1;
    }
    
    reversed[index] = '\0';
    printf("%s", reversed);
    
    free(input);
    return 0;
}

