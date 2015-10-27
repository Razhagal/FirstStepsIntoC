/* 
 * Write a recursive string reverse function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(const char* input, const int inputLength, int currentIndex, char* destination);

int main()
{
    char inputString[20];
    printf("String to reverse: ");
    fgets(inputString, 20, stdin);
    
    char reversedString[20];
    int startIndex = strlen(inputString) - 2;
    reverse(inputString, startIndex, startIndex, reversedString);
    
    printf("Reversed: %s", reversedString);
    return 0;
}

void reverse(const char* input, const int inputLength, int currentIndex, char* destination)
{
    if (currentIndex < 0)
    {
        return;
    }
    
    int inputIndex = inputLength - currentIndex;
    destination[currentIndex] = input[inputIndex];
    
    currentIndex--;
    reverse(input, inputLength, currentIndex, destination);
}