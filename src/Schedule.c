//
// Created by John on 12/10/2020.
//

#include <stdio.h>
#include "Schedule.h"

void initSchedule(Schedule* scheduleP)
{
    printf("Initializing empty schedule"); fflush(stdout);
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

        }
    }
}