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
        printf("|\n");
    }
}
void setTimeBusy(Schedule* scheduleP,int time, int dayOfWeek)
{
    int* scheduleBeginning = scheduleP->edgeTimeP;
    *(scheduleBeginning + (5*time) + dayOfWeek)  = 1;
}

bool getTimeBusy(Schedule* scheduleP, int time,int dayOfWeek)
{
    bool busy = false;
    int* scheduleBeginning = scheduleP->edgeTimeP;
    if (*(scheduleBeginning + (5*time) + dayOfWeek)  == 1)
    {
        busy = true;
    }
    return busy;
}