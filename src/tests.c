/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "LinkedList.h"



bool tests()
{
	bool answer = false;
    bool ok1 = testReadInitialInputFile();
	bool ok2 = testMakeLList();
	bool ok3 = testInitSchedule();
	bool ok4 = testSetTimeBusy();
	bool ok5 = testGetTimeBusy();
	bool ok6 = testGetScheduleConflict();
	bool ok7 = testPrintHistory();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7;
	return answer;
}



bool testInitSchedule()
{
	bool ok = true;
    Schedule* testScheduleP = (Schedule*) malloc(sizeof(Schedule));
    testScheduleP->edgeTimeP = (int* ) malloc(5*13*sizeof(int));
    puts("Testing initSchedule");
    initSchedule(testScheduleP);

    for (int row = 0; row<13; row++)
    {
        for (int col = 0; col<5; col++)
        {
            int* memoryToTest = ((testScheduleP->edgeTimeP)+(row*5)+col);
            if(*memoryToTest != 0)
            {
                ok = false;
            }
        }
    }
    if (ok)
    {
        puts("Test initSchedule passed");
    }
    else
    {
        puts("Test initSchedule did not pass");
    }

	return ok;
}

bool testSetTimeBusy()
{

    bool ok = true;

    puts("Testing setTimeBusy...");
    Schedule* testScheduleP = (Schedule*) malloc(sizeof(Schedule));
    testScheduleP->edgeTimeP = (int* ) malloc(5*13*sizeof(int));

    initSchedule(testScheduleP);

    for (int time = 0; time<13; time++)
    {
        for (int day = 0; day<5; day++)
        {
            setTimeBusy(testScheduleP, time+8, day);
            if (*(testScheduleP->edgeTimeP + (5*time) + day) != 1)
            {
                ok = false;
            }
        }

    }

    if (ok)
    {
        puts("Test setTimeBusy passed");
    }
    else
    {
        puts("Test setTimeBusy did not pass");
    }

    return ok;
}

bool testGetTimeBusy()
{
    bool ok = true;

    puts("Testing getTimeBusy...");
    Schedule* testScheduleP = (Schedule*) malloc(sizeof(Schedule));
    testScheduleP->edgeTimeP = (int* ) malloc(5*13*sizeof(int));

    initSchedule(testScheduleP);

    for (int row = 0; row<13; row++)
    {
        for (int col = 0; col<5; col++)
        {
            *(testScheduleP->edgeTimeP + (5*row) + col) = 1;
            if(!(getTimeBusy(testScheduleP, row+8, col))) //Add 8 to time to get the right time.
            {
                ok = false;
            }
        }

    }
    if (ok)
    {
        puts("Test GetTimeBusy passed");
    }
    else
    {
        puts("Test GetTimeBusy did not pass");
    }

    return ok;
}

bool testMakeLList() //Tests the making of a list and the enqueue behavior.
{
	bool ok = true;

	return ok;
}

bool testPrintHistory() //Visual test. If the following list of search results is printed, the test is a success.
{
	bool ok = true;

	return ok;
}

bool testReadInitialInputFile()
{
    puts("starting testReadInitialInputFile\n"); fflush(stdout);
    bool ok = false;
    //the file tells how many rooms there are
    int answer = -1;
    int rightAnswer = 4;


    Schedule* scheduleP = (Schedule *) malloc(sizeof(Schedule));
    Course* theCoursePs[20];//addresses for 20 courses
    scheduleP->edgeTimeP = (int* ) malloc(5*13*sizeof(int)); //There are 5 days in the week, and 13 valid hours in each day. We'll allocate some memory for every one of them.
    initSchedule(scheduleP);
    ok = readInitialInputFile("final2020B.txt", &answer, scheduleP, theCoursePs);
    if (ok)
    {
        if (answer != rightAnswer)
        {
            puts("test failed on number of courses\n");
        }
    }






    //fclose();
    return ok;
}

bool testDequeue()
{
    bool ok = true;
    puts ("Testing DequeueLIFO..");
    LLNode* queue = makeEmptyLinkedList();

    if (ok)
    {
        puts("Test DequeueLIFO passed");
    }
    else
    {
        puts("Test DequeueLIFO did not pass");
    }

    return ok;
}

bool testGetScheduleConflict()
{
    bool ok = true;

    puts("Testing getScheduleConflict...");
    Schedule* testScheduleP = (Schedule*) malloc(sizeof(Schedule));
    testScheduleP->edgeTimeP = (int* ) malloc(5*13*sizeof(int));

    initSchedule(testScheduleP);
    char testDates[5];
    char* testDatesP = "MTWR";
    strcpy(testDates, testDatesP);
    for(int i = 0; i<5; i++)
    {
        setTimeBusy(testScheduleP, 13, i);
    }

    displaySchedule(testScheduleP);
    bool answer =getScheduleConflict(testScheduleP, testDates, 13);

    bool rightAnswer = true;

    if (answer != rightAnswer)
    {
        ok = false;
    }

    if (ok)
    {
        puts("Test GetScheduleConflict passed");
    }
    else
    {
        puts("Test GetScheduleConflict did not pass");
    }
    return ok;
}