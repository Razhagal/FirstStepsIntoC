#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // First get the current date and time
    time_t currentDateTimeEpoch = time(NULL);
    struct tm *DateTimeNow = localtime(&currentDateTimeEpoch);
    
    int currentYear = DateTimeNow->tm_year + 1900; // tm_year returns years count after 1900
    int currentMonth = DateTimeNow->tm_mon + 1; // tm_mon start from 0. Add 1 to compenasate
    int currentDay = DateTimeNow->tm_mday;
    
    // Then get your birthday from the console in some format
    int birthDay, birthMonth, birthYear;
    if (scanf("%d.%d.%d", &birthDay, &birthMonth, &birthYear) == 1)
    {
        printf("Invalid input.");
        return 0;
    }
    
    int currentAge = currentYear - birthYear;
    if (birthMonth < currentMonth)
    {
        printf("Your are now %d years old. After 10 years on this date you will be %d years old.",
                currentAge, currentAge + 10);
    }
    else if (birthMonth > currentMonth)
    {
        printf("You are now %d years old. After 10 years on this date you will be %d years old.",
                currentAge- 1, currentAge + 9);
    }
    else if (birthMonth == currentMonth)
    {
        if (birthDay > currentDay)
        {
            printf("You are now %d years old. After 10 years on this date you will be %d years old.", 
                    currentAge - 1, currentAge + 9);
        }
        else
        {
            printf("You are now %d years old. After 10 years on this date you will be %d years old.", 
                    currentAge, currentAge + 10);
        }
    }
    
    return 0;
}

