/* 
 * Write a program that enters 3 integers n, min and max (min ≤ max)
 * and prints n random numbers in the range [min...max].
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, min, max;
    printf("n = ");
    scanf("%d", &n);
    printf("min = ");
    scanf("%d", &min);
    printf("max = ");
    scanf("%d", &max);
    
    time_t t;
    srand(time(&t));
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", rand() % (max + 1 - min) + min);
    }
    
    return 0;
}

