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
        puts("Test initSchedule passed\n");
    }
    else
    {
        puts("Test initSchedule did not pass\n");
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
        puts("Test setTimeBusy passed\n");
    }
    else
    {
        puts("Test setTimeBusy did not pass\n");
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
        puts("Test GetTimeBusy passed\n");
    }
    else
    {
        puts("Test GetTimeBusy did not pass\n");
    }

    return ok;
}

bool testMakeLList() //Tests the making of a list
{
	bool ok = true;
    puts("starting testMakeLList");fflush(stdout);
    //what are the criteria for success for make LList?
    //should be able to make one, add data to it, get the data back
    //test case 1:
    LLNode* theListP = makeEmptyLinkedList();
    bool rightAnswer = true;
    bool answer = isEmpty(theListP);
    if(answer!=rightAnswer)
    {
        ok = false;
    }
    //test case 2:
    CourseDecision * testDecisionP = malloc(sizeof(CourseDecision));
    savePayload(theListP, testDecisionP);
    rightAnswer = false;
    answer = isEmpty(theListP);
    if(answer!=rightAnswer)
    {
        ok = false;
    }

    //test case 3:
    CourseDecision * testDecision2P = malloc(sizeof(CourseDecision));
    savePayload(theListP, testDecision2P);
    if (!(theListP->next)) //If there is no next, then our second save did not work, or there is an issue with saving payloads to the list.
    {
        ok = false;
    }

    //Test case 4:
    LLNode* temp = theListP;
    while (temp->next)
    {
        temp = temp->next;
        if (!(temp->prev)) //If we move to the second element, and there is no first element, then we know that something is wrong with prev.
        {
            ok = false;
        }

    }

    //Test Case 5
    CourseDecision * testDecisionCompareP = theListP->payP;
    if (isEmpty(theListP)||testDecisionCompareP->courseTime != testDecisionP->courseTime || testDecisionCompareP->courseAdded != testDecisionP->courseAdded || testDecisionCompareP->courseDates != testDecisionP->courseDates) //If there are discrepancies between the original room and the one from the list, then we know something is wrong.
    {
        ok = false;
    }

    //Test case 6
    LLNode* tempP = theListP;
    while (tempP->next)
    {
        if ((LLNode*)tempP->next == (LLNode*)tempP) //If next points to the same place, then something is wrong with the savePayload function
        {
            ok = false;
        }
        tempP = (LLNode*)tempP->next;
    }
    while (tempP->prev)
    {
        if ((LLNode*)tempP->prev == (LLNode*)tempP) //If prev points to the same place, then something is wrong with the savePayload function
        {
            ok = false;
        }
        tempP = (LLNode*)tempP->prev;
    }

    if (!ok)
    {
        puts("test make LList did not pass.\n");
    }
    else
    {
        puts("Test make LList passed.\n");
    }

    return ok;
}

bool testPrintHistory() //Visual test. If the following list of search results is printed, the test is a success.
{
	bool ok = true;
    puts ("Testing PrintHistory...");
    LLNode2* historyListP = makeEmptyLinkedList2();
    char testDates[5];
    char* testDatesP = "MTWRF";
    for(int i = 0; i<5; i++)
    {
        CourseDecision * tempDecisionP= malloc(sizeof(CourseDecision));
        tempDecisionP->courseTime = i;
        tempDecisionP->courseDates = testDatesP;
        tempDecisionP->courseAdded = i%2; //Easy way to vary if courses added.
        savePayload2(historyListP, tempDecisionP);
    }
    printHistory(historyListP);
	return ok;
}

bool testReadInitialInputFile()
{
    puts("starting testReadInitialInputFile\n"); fflush(stdout);
    bool ok = false;
    //the file tells how many rooms there are
    int answer = -1;
    int rightAnswer = 4;

    LLNode* courseDecisionP = makeEmptyLinkedList();
    Schedule* scheduleP = (Schedule *) malloc(sizeof(Schedule));
    Course* theCoursePs[20];//addresses for 20 courses
    scheduleP->edgeTimeP = (int* ) malloc(5*13*sizeof(int)); //There are 5 days in the week, and 13 valid hours in each day. We'll allocate some memory for every one of them.
    initSchedule(scheduleP);
    ok = readInitialInputFile("final2020B.txt", &answer, scheduleP, theCoursePs, courseDecisionP);
    if (ok)
    {
        if (answer != rightAnswer)
        {
            puts("test failed on number of courses\n");
        }
    }
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