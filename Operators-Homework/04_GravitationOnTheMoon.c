/* 
 * The gravitational field of the Moon is approximately 17% of that on the Earth.
 * Write a program that calculates the weight of a man on the moon by a given weight on the Earth.
 */

#include <stdio.h>
#include <stdlib.h>

#define MOON_GRAVITATION 0.17f

int main()
{
    /*
     * Disabling the buffer solves the issue with the first printf not showing before
     * the actual input and messing the whole output in the end
     */
    setbuf(stdout, NULL);
    
    float weight;
    printf("Enter your weight: ");
    scanf("%f", &weight);
    float moonWeight = weight * MOON_GRAVITATION;
    
    printf("On the Moon you will weight merely %.3f kg.", moonWeight);
    
    return 0;
}

