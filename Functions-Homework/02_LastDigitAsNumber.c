/* 
 * Write a function that returns the last digit
 * of a given integer as an English word.
 */

#include <stdio.h>
#include <stdlib.h>

char* getDigitAsWord(int number);

int main()
{
    int number;
    scanf("%d", &number);
    
    char *result = getDigitAsWord(number);
    printf("%s", result);
    
    return 0;
}

char* getDigitAsWord(int number)
{
    int lastDigit = number % 10;
    char *digitAsWord;
    switch (lastDigit)
    {
        case 1: digitAsWord =  "one"; break;
        case 2: digitAsWord = "two"; break;
        case 3: digitAsWord = "three"; break;
        case 4: digitAsWord = "four"; break;
        case 5: digitAsWord = "five"; break;
        case 6: digitAsWord = "six"; break;
        case 7: digitAsWord = "seven"; break;
        case 8: digitAsWord = "eight"; break;
        case 9: digitAsWord = "nine"; break;
        case 0: digitAsWord = "zero"; break;
        default:
            digitAsWord = "invalid digit";
            break;
    }
    
    return digitAsWord;
}

