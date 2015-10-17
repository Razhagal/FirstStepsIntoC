#include <stdio.h>
#include <time.h>

int main()
{
    time_t currentTimeEpoch = time(NULL);
    struct tm *DateTimeNow = localtime(&currentTimeEpoch);
    char currentTimeText[100];
    
    if (currentTimeEpoch != -1)
    {
        strftime(currentTimeText, sizeof(currentTimeText), "%d %B %Y %H:%M:%S", DateTimeNow);
        printf("%s", currentTimeText);
    }
    
    return 0;
}

