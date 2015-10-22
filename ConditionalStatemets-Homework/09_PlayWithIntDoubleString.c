/* 
 * Write a program that, depending on the user’s choice, inputs an int,
 * double or string variable. If the variable is int or double,
 * the program increases it by one. If the variable is a string,
 * the program appends "*" at the end. Print the result at the console.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    setbuf(stdout, NULL);
    
    int type;
    printf("Please choose a type: \n");
    printf("1 --> int\n");
    printf("2 --> double\n");
    printf("3 --> string\n");
    scanf("%d", &type);
    
    int integerNum;
    double doubleNum;
    char someString[15];
    
    switch (type)
    {
        case 1:
            printf("Please enter an int: ");
            scanf("%d", &integerNum);
            printf("%d", integerNum + 1);
            break;
        case 2:
            printf("Please enter a double: ");
            scanf("%lf", &doubleNum);
            printf("%.2f", doubleNum + 1);
            break;
        case 3:
            printf("Please enter a string: ");
            fgets(someString, 15, stdin);
            if (someString[0] == '\n')
            {
                fgets(someString, 15, stdin);
            }
            
            printf("%s*", someString);
            break;
        default:
            printf("Invalid type!");
            break;
    }
    
    return 0;
}