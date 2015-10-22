/* 
 * A beer time is after 1:00 PM and before 3:00 AM.
 * Write a program that enters a time in format “hh:mm tt” (an hour in range [01...12],
 * a minute in range [00…59] and AM / PM designator) and prints “beer time”
 * or “non-beer time” according to the definition above or
 * “invalid time” if the time cannot be parsed.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[10], timeDesignator;
    fgets(input, 10, stdin);
    int hour, minutes;
    char *endPointer;
    char mins[2];
    
    if (input[1] == ':')
    {
        hour = strtol(input, &endPointer, 10);
        if (endPointer[0] != ':')
        {
            printf("Invalid input");
        }
        
        mins[0] = input[2];
        mins[1] = input[3];
        timeDesignator = input[5];
    }
    else if (input[2] == ':')
    {
        hour = strtol(input, &endPointer, 10);
        if (endPointer[0] != ':')
        {
            printf("Invalid input");
        }
        
        mins[0] = input[3];
        mins[1] = input[4];
        timeDesignator = input[6];
    }
    
    minutes = strtol(mins, &endPointer, 10);
    
    if ((timeDesignator == 'A' && hour < 3) ||
        (timeDesignator == 'P' && hour >= 1))
    {
        printf("beer time");
    }
    else
    {
        printf("non beer time");
    }
    
    return 0;
}

