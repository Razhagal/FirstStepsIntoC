/* 
 * Write a program to find all increasing sequences inside an array of integers.
 * The numbers should be entered one at a line.
 * On the first input line you will be given the count of the numbers.
 * Print the sequences in the order of their appearance in the
 * input array, each at a single line. Separate the sequence
 * elements by a space. Find also the longest increasing sequence
 * and print it at the last line. If several sequences have
 * the same longest length, print the left-most of them.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numCount;
    scanf("%d", &numCount);
    
    int* arr = malloc(numCount * sizeof(int));
    for (int i = 0; i < numCount; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int longestSequenceEndIndex = 0;
    int maxSequenceLength = 1;
    int currentSequence = 1;
    for (int i = 0; i < numCount - 1; i++)
    {
        if (arr[i + 1] > arr[i])
        {
            printf("%d ", arr[i]);
            currentSequence++;
            if (currentSequence > maxSequenceLength)
            {
                maxSequenceLength = currentSequence;
                longestSequenceEndIndex = i + 1;
            }
            
            if (i == numCount - 2)
            {
                printf("%d \n", arr[i + 1]);
            }
        }
        else
        {
            printf("%d\n", arr[i]);
            currentSequence = 1;
        }
    }
    
    printf("Longest: ");
    int startIndex = longestSequenceEndIndex - maxSequenceLength + 1;
    for (int i = startIndex; i <= longestSequenceEndIndex; i++)
    {
        printf("%d ", arr[i]);
    }
    
    free(arr);
    
    return 0;
}

