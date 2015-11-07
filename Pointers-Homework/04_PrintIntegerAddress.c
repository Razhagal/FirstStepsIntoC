/* 
 * Write a function which takes as input an integer
 * and prints the address of it in the memory.
 */

#include <stdio.h>
#include <stdlib.h>

void printAddress(int num);

int main()
{
    int num;
    scanf("%d", &num);
    
    printf("Addres in main func: %p\n", &num);
    printAddress(num);
    return 0;
}

void printAddress(int num)
{
    printf("Addres inside \"printAddress\" func: %p", &num);
}