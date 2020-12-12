/*
 * tests.h
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_


#include "production.h"
#include "Schedule.h"

bool tests();

bool testReadInputFile();
bool testWriteScheduleToFile();
bool testWriteDecisionListToFile();

bool testInitSchedule();
bool testDisplaySchedule();
bool testSetTimeBusy();
bool testGetTimeBusy();
bool testGetScheduleConflict();


bool testMakeLList();
bool testPrintHistory();





#endif /* TESTS_H_ */
