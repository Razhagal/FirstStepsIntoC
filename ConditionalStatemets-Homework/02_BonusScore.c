/* 
 * Write a program that applies bonus score to given score in the range [1…9] by the following rules:
 * - If the score is between 1 and 3, the program multiplies it by 10.
 * - If the score is between 4 and 6, the program multiplies it by 100.
 * - If the score is between 7 and 9, the program multiplies it by 1000.
 * - If the score is 0 or more than 9, the program prints “invalid score”.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
     * Disabling the buffer solves the issue with the first printf not showing before
     * the actual input and messing the whole output in the end
     */
    setbuf(stdout, NULL);
    
    int score;
    printf("Enter score between 1 and 9: ");
    int matches = scanf("%d", &score);
    
    if (matches)
    {
        if (score < 1 || score > 9)
        {
            printf("Invalid score");
        }
        else
        {
            if (score >= 1 && score <= 3)
            {
                score *= 10;
            }
            else if (score >= 4 && score <= 6)
            {
                score *= 100;
            }
            else
            {
                score *= 1000;
            }
            
            printf("%d", score);
        }
    }
    else
    {
        printf("Invalid score");
    }
    
    return 0;
}

