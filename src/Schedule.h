//
// Created by John on 12/10/2020.
//

#ifndef ADJMAT_C_SCHEDULE_H
#define ADJMAT_C_SCHEDULE_H

#include <stdbool.h>
typedef struct
{
    int nCourses;
    int* edgeTimeP; //Points to 8AM on Monday on the schedule, the first time in our schedule.
} Schedule;

void setTimeBusy(int dayOfWeek, int time);
bool getTimeBusy(int dayOfWeek, int time);
void initSchedule(Schedule* scheduleP);
#endif //ADJMAT_C_SCHEDULE_H
