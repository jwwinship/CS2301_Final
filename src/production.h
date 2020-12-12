/*
 * production.h
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol

#include "Course.h"
#include "Schedule.h"



#define FILENAMELENGTHALLOWANCE 50

bool production(int argc, char* argv[]);
bool readInitialInputFile();
bool writeScheduleToFile(char* filename, int* nCourses, Schedule* theScheduleP, Course** theCoursePs);
void displayBoard();

#endif /* PRODUCTION_H_ */
