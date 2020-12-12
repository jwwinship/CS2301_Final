//
// Created by John on 12/10/2020.
//

#include <stdio.h>
#include "Schedule.h"

void initSchedule(Schedule* scheduleP)
{
    printf("Initializing empty schedule\n"); fflush(stdout);
    const int DaysInWeek = 5;
    const int HoursInDay = 13; //Is 8PM a valid start time?

    /* Schedule will look like this
     *
     *      M   T   W   R   F
     *  8   X   X   X   X   X
     *  9   X   X   X   X   X
     *  10  X   X   X   X   X
     *  11  X   X   X   X   X
     *  12  X   X   X   X   X
     *  13  X   X   X   X   X
     *  14  X   X   X   X   X
     *  15  X   X   X   X   X
     *  16  X   X   X   X   X
     *  17  X   X   X   X   X
     *  18  X   X   X   X   X
     *  19  X   X   X   X   X
     *  20  X   X   X   X   X
     *
     *  Where each x will be a space in our schedule. The Days of week and hours of day will be displayed separately, probably in a loop when we're writing. 
     */


    for (int row = 0; row<HoursInDay; row++)
    {
        for (int col = 0; col<DaysInWeek; col++)
        {
            int* memoryToAssign = ((scheduleP->edgeTimeP)+(row*DaysInWeek)+col);
            *memoryToAssign= 0;
        }
    }
    //displaySchedule(scheduleP);
}

void displaySchedule(Schedule* scheduleP)
{
    printf("Printing Schedule...\n"); fflush(stdout);
    const int DaysInWeek = 5;
    const int HoursInDay = 13; //Is 8PM a valid start time?

    printf("   M T W R F \n");
    for (int row = 0; row<HoursInDay; row++)
    {
        printf("%2d", row+8 ); //We start at 8AM. Formatting is to pad the times
        for (int col = 0; col<DaysInWeek; col++)
        {
            int* memoryToCheck = ((scheduleP->edgeTimeP)+(row*DaysInWeek)+col);

            printf("|%d", *memoryToCheck);
        }
        printf("|\n");fflush(stdout);
    }
}
void setTimeBusy(Schedule* scheduleP,int time, int dayOfWeek)
{
    int* scheduleBeginning = scheduleP->edgeTimeP;
    *(scheduleBeginning + (5*(time-8)) + dayOfWeek)  = 1; //Some strange looking math here, but there are 5 days in a week, and we subtract time by 8 because 8AM is our start time, and our time passed in is based on that.
}

bool getTimeBusy(Schedule* scheduleP, int time,int dayOfWeek)
{
    bool busy = false;
    int* scheduleBeginning = scheduleP->edgeTimeP;
    int* memoryToCheck = (scheduleBeginning + (5*(time-8)) + dayOfWeek);
    if (*memoryToCheck == 1)
    {
        busy = true;
    }
    return busy;
}

bool getScheduleConflict(Schedule* theScheduleP, char courseDates[], int courseTime) //TODO: modify to add linked list of decisions
{
    bool conflictsFound = false;
    puts ("Checking schedule for conflicts");
    for(int j = 0; j<5; j++)//Should only be 5 possible dates in the string.
    {
        switch (courseDates[j])
        {
            case 'M':
                if(getTimeBusy(theScheduleP,courseTime, MONDAY))
                {
                    conflictsFound = true;
                }
                break;

            case 'T':
                if(getTimeBusy(theScheduleP,courseTime, TUESDAY))
                {
                    conflictsFound = true;
                }
                break;
            case 'W':
                if(getTimeBusy(theScheduleP,courseTime, WEDNESDAY))
                {
                    conflictsFound = true;
                }
                break;
            case 'R':
                if(getTimeBusy(theScheduleP,courseTime, THURSDAY))
                {
                    conflictsFound = true;
                }
                break;
            case 'F':
                if(getTimeBusy(theScheduleP,courseTime, FRIDAY))
                {
                    conflictsFound = true;
                }
                break;
            default:
                break;
        }

    }
    if (conflictsFound)
    {
        puts("Conflict found with schedule, can't add course\n");
    }
    else
    {
        puts("No conflicts found!\n");
    }
    return conflictsFound;
}

