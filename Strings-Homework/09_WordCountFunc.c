/* 
 * Implement a function which counts the words in a given input.
 * The function accepts as parameter the input from which to count
 * the words and the delimiter separating the words.
 */

#include <stdio.h>
#include <stdlib.h>

int countWords(char* input, char delimiter);

int main()
{
    printf("%d\n", countWords("Hard Rock, Hallelujah!", ' '));
    printf("%d\n", countWords("Hard Rock, Hallelujah!", ','));
    printf("%d\n", countWords("Uncle Sam wants you Man", ' '));
    printf("%d\n", countWords("Beat the beat!", '!'));
    
    return 0;
}

int countWords(char* input, char delimiter)
{
    int count = 1;
    while (*input != '\0')
    {
        if (*input == delimiter)
        {
            count++;
        }
        
        *input++;
    }

    return count;
}