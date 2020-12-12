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

bool testReadInitialInputFile();
bool testInitSchedule();
bool testMakeLList();
bool testSetTimeBusy();
bool testGetTimeBusy();
bool testDequeue();
bool testPrintHistory();
bool testGetScheduleConflict();



#endif /* TESTS_H_ */
