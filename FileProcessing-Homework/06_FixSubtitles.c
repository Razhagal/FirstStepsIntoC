/* 
 * Write a program that takes as arguments input subtitles file
 * and offset in milliseconds. The program should edit the subtitles'
 * timing by the given offset. The subtitles will contains
 * will be in the format specified below.
 *      #num
 *      hh:mm:ss:ms --> hh:mm:ss:ms
 *      text
 * The program should correctly modify seconds, minutes and hours
 * when overflow occurs (i.e. 61 seconds is not valid).
 * Example: 00:00:52:580 + 700 -> 00:00:53:280.
 * The program should support modifying subtitles in the range [00:00:00:00 - 99:59:59:999].
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 4096

struct time
{
    size_t hours;
    size_t minutes;
    size_t seconds;
    size_t milliseconds;
};

void kill(const char* message);
void processTime(struct time* t, char* token, size_t offset);

int main()
{
    printf("Enter subtitles offset in milliseconds: ");
    size_t offset;
    if (scanf("%lu", &offset) != 1)
    {
        printf("Invalid input.");
        exit(1);
    }
    
    FILE* sourceFile = fopen("source.sub", "r");
    if (!sourceFile)
    {
        kill(NULL);
    }
    
    FILE* destinationFile = fopen("fixed.sub", "w");
    if (!destinationFile)
    {
        kill(NULL);
    }
    
    char* line = NULL;
    size_t size = 0;
    while (!feof(sourceFile))
    {
        size_t lineLength = getline(&line, &size, sourceFile);
        
        
        char* isTimeLine = strstr(line, " -->");
        if (!isTimeLine)
        {
            fwrite(line, 1, lineLength, destinationFile);
        }
        else
        {
            char* leftTime = strtok(line, " --> ");
            char* rightTime = strtok(NULL, " --> ");
            struct time firstTime, secondTime;
            
            processTime(&firstTime, leftTime, offset);
            processTime(&secondTime, rightTime, offset);
            
            char result[30];
            sprintf(result, "%02lu:%02lu:%02lu,%03lu --> %02lu:%02lu:%02lu,%03lu\n",
                    firstTime.hours, firstTime.minutes, firstTime.seconds, firstTime.milliseconds,
                    secondTime.hours, secondTime.minutes, secondTime.seconds, secondTime.milliseconds);
            fwrite(result, 1, strlen(result), destinationFile);
        }
    }

    free(line);
    fclose(sourceFile);
    fclose(destinationFile);
    return 0;
}

void kill(const char* message)
{
    if (errno)
    {
        perror(message);
    }
    else
    {
        printf("Error: %s\n", message);
    }
    
    exit(1);
}

void processTime(struct time* t, char* token, size_t offset)
{
    int milliseconds = offset % 1000;
    int seconds = (offset / 1000) % 60;
    int minutes = ((offset / 1000) / 60) % 60;
    int hours = ((offset / 1000) / 60) / 60;
    
    char* currentHours = strtok(token, " :,");
    char* currentMinutes = strtok(NULL, " :,");
    char* currentSeconds = strtok(NULL, " :,");
    char* currentMilliseconds = strtok(NULL, " :,");
    
    t->hours = atoi(currentHours) + hours;
    t->minutes = atoi(currentMinutes) + minutes;
    t->seconds = atoi(currentSeconds) + seconds;
    t->milliseconds = atoi(currentMilliseconds) + milliseconds;
    
    t->hours += t->minutes / 60;
    t->minutes %= 60;
    t->minutes += t->seconds / 60;
    t->seconds %= 60;
    t->seconds += t->milliseconds / 1000;
    t->milliseconds %= 1000;
}