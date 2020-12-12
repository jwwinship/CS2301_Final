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

typedef enum
{
    MONDAY = 0,
    TUESDAY = 1,
    WEDNESDAY = 2,
    THURSDAY = 3,
    FRIDAY = 4

}weekdays;

void setTimeBusy(Schedule* scheduleP, int time,int dayOfWeek);
bool getTimeBusy(Schedule* scheduleP, int time,int dayOfWeek);
void initSchedule(Schedule* scheduleP);
void displaySchedule(Schedule* scheduleP);
bool getScheduleConflict(Schedule* theScheduleP, char courseDates[], int courseTime);
#endif //ADJMAT_C_SCHEDULE_H
