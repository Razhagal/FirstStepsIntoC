/* 
 * Write a program that takes a text and a string of banned words.
 * All words included in the ban list should be replaced with
 * asterisks "*", equal to the word's length. The entries in
 * the ban list will be separated by a comma and space ", ".
 * The ban list should be entered on the first input line
 * and the text on the second input line.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* bannedWords = NULL;
    size_t size = 0;
    int bannedLength = getline(&bannedWords, &size, stdin);
    bannedWords[bannedLength - 1] = '\0';
    
    char* text = NULL;
    int textLength = getline(&text, &size, stdin);
    text[textLength - 1] = '\0';
    
    char* token = strtok(bannedWords, ", ");
    while (token)
    {
        size_t tokenLength = strlen(token);
        char* subString = strstr(text, token);
        while (subString)
        {
            int index = subString - text;
            memset(&text[index], '*', tokenLength);
            subString = strstr(&(*(subString + 1)), token);
        }
        
        token = strtok(NULL, ", ");
    }

    printf("\n%s\n", text);
    
    free(bannedWords);
    free(text);
    return 0;
}

