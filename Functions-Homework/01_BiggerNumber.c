/* 
 * Write a program that reads 2 integers from the console
 * and prints the largest of them using the function get_max().
 */

#include <stdio.h>
#include <stdlib.h>

int getMax(int firstNum, int secondNum);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    int bigger = getMax(a, b);
    printf("%d", bigger);
    
    return 0;
}

int getMax(int firstNum, int secondNum)
{
    if (firstNum >= secondNum)
    {
        return firstNum;
    }
    else
    {
        return secondNum;
    }
}