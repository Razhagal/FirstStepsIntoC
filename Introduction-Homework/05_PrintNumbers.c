#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    /*
     * scanf to read 3 numbers and assign them to the integers
     * then print them using only one printf with placeholders
     * and \n for new line
    */
    int firstNum, secondNum, thirdNum;
    scanf("%d", &firstNum);
    scanf("%d", &secondNum);
    scanf("%d", &thirdNum);
    
    printf("%d\n%d\n%d\n", firstNum, secondNum, thirdNum);
    
    return 0;
}

