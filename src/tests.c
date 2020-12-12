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
    bool ok1 = testReadInputFile();
	bool ok2 = testMakeLList();
	bool ok3 = testInitSchedule();
	bool ok4 = testSetTimeBusy();
	bool ok5 = testGetTimeBusy();
	bool ok6 = testGetScheduleConflict();
	bool ok7 = testPrintHistory();
	bool ok8 = testWriteScheduleToFile();
	bool ok9 = testWriteDecisionListToFile();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9;
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
bool testDisplaySchedule() { //Largely visual test
    bool ok = true;
    Schedule* testScheduleP = (Schedule*) malloc(sizeof(Schedule));
    testScheduleP->edgeTimeP = (int* ) malloc(5*13*sizeof(int));
    puts("Testing DisplaySchedule");
    initSchedule(testScheduleP);
    displaySchedule(testScheduleP);
    return ok;
}

bool testSetTimeBusy()
{

    bool ok = true;

    puts("Testing setTimeBusy...");
    Schedule* testScheduleP = (Schedule*) malloc(sizeof(Schedule));
    testScheduleP->edgeTimeP = (int* ) malloc(5*13*sizeof(int));

    //Test Case 1, testing if setTimeBusy will accurately set a time slot
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

    //Test Case 2, testing if setTimeBusy accidentally sets the wrong time slot.
    initSchedule(testScheduleP); //Reinit
    setTimeBusy(testScheduleP, 13, 3); //Test setting 1PM on wednesday.
    for (int time = 0; time<13; time++)
    {
        for (int day = 0; day<5; day++)
        {
            if (*(testScheduleP->edgeTimeP + (5*time) + day) == 1 && time != 5) //If any slot is filled except the one we wanted, then the test has failed.
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

    //Test case 1, every time slot should be filled, and the function should indicate that. Tests for false negatives
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

    //Test case 2, testing if getTimeBusy ever returns a false positive
    initSchedule(testScheduleP); //Reinit
    for (int row = 0; row<13; row++)
    {
        for (int col = 0; col<5; col++)
        {
            if((getTimeBusy(testScheduleP, row+8, col))) //Add 8 to time to get the right time.
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

bool testGetScheduleConflict()
{
    bool ok = true;

    puts("Testing getScheduleConflict...");
    Schedule* testScheduleP = (Schedule*) malloc(sizeof(Schedule));
    testScheduleP->edgeTimeP = (int* ) malloc(5*13*sizeof(int));

    //Test case 1, tests for false negatives
    initSchedule(testScheduleP);
    char testDates[5];
    char* testDatesP = "MTWR";
    strcpy(testDates, testDatesP);
    for(int i = 0; i<5; i++)
    {
        setTimeBusy(testScheduleP, 13, i);
    }
    displaySchedule(testScheduleP);
    bool answer=getScheduleConflict(testScheduleP, testDates, 13);
    bool rightAnswer = true;
    if (answer != rightAnswer)
    {
        ok = false;
    }

    //Test case 2, tests for false positives
    initSchedule(testScheduleP);
    testDates[5];
    testDatesP = "MTWR";
    strcpy(testDates, testDatesP);
    for(int i = 0; i<5; i++)
    {
        setTimeBusy(testScheduleP, 13, i);
    }
    displaySchedule(testScheduleP);
    for(int i = 0; i<13; i++)
    {
        answer= i + 8 == 13 != 0 == !getScheduleConflict(testScheduleP, testDates, i + 8);
        rightAnswer = false;
        if (answer != rightAnswer)
        {
            ok = false;
        }
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

bool testMakeLList() //Tests the making of a list
{
    bool ok = true;
    puts("starting testMakeLList");fflush(stdout);
    //what are the criteria for success for make LList?
    //should be able to make one, add data to it, get the data back
    LLNode* theListP = makeEmptyLinkedList();
    bool rightAnswer;
    bool answer;
    if (ok)
    {
        //test case 1:

        rightAnswer = true;
        answer = isEmpty(theListP);
        if(answer!=rightAnswer)
        {
            ok = false;
        }
    }

    CourseDecision * testDecisionP = malloc(sizeof(CourseDecision));
    if (ok)
    {
        //test case 2:

        savePayload(theListP, testDecisionP);
        rightAnswer = false;
        answer = isEmpty(theListP);
        if(answer!=rightAnswer)
        {
            ok = false;
        }
    }

    CourseDecision * testDecision2P = malloc(sizeof(CourseDecision));
    if (ok)
    {
        //test case 3:

        savePayload(theListP, testDecision2P);
        if (!(theListP->next)) //If there is no next, then our second save did not work, or there is an issue with saving payloads to the list.
        {
            ok = false;
        }
    }

    if (ok)
    {
        //Test case 4:
        LLNode* temp = theListP;
        while (temp->next)
        {
            temp = (LLNode*) temp->next;
            if (!(temp->prev)) //If we move to the second element, and there is no first element, then we know that something is wrong with prev.
            {
                ok = false;
            }

        }

    }
    if (ok)
    {
        //Test Case 5
        CourseDecision * testDecisionCompareP = theListP->payP;
        if (isEmpty(theListP)||testDecisionCompareP->courseTime != testDecisionP->courseTime || testDecisionCompareP->courseAdded != testDecisionP->courseAdded || testDecisionCompareP->courseDates != testDecisionP->courseDates) //If there are discrepancies between the original room and the one from the list, then we know something is wrong.
        {
            ok = false;
        }
    }

    if (ok)
    {
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

bool testPrintHistory() //Visual test. If the following list of course decisions is printed, the test is a success.
{
	bool ok = true;
    puts ("Testing PrintHistory...");
    LLNode* decisionListP = makeEmptyLinkedList();
    char testDates[5];
    char* testDatesP = "MTWRF";
    for(int i = 0; i<5; i++)
    {
        CourseDecision * tempDecisionP= malloc(sizeof(CourseDecision));
        tempDecisionP->courseTime = i;
        tempDecisionP->courseDates = testDatesP;
        tempDecisionP->courseAdded = i%2; //Easy way to vary if courses added.
        savePayload(decisionListP, tempDecisionP);
    }
    printHistory(decisionListP);
	return ok;
}

bool testReadInputFile() //This will rigidly test our test input file, but if that test file changes, the test will fail.
{
    puts("starting testReadInputFile\n"); fflush(stdout);
    bool ok = false;
    //the file tells how many rooms there are
    int answer = -1;
    int rightAnswer = 4;

    LLNode* courseDecisionP = makeEmptyLinkedList();
    Schedule* scheduleP = (Schedule *) malloc(sizeof(Schedule));
    Course* theCoursePs[20];//addresses for 20 courses
    scheduleP->edgeTimeP = (int* ) malloc(5*13*sizeof(int)); //There are 5 days in the week, and 13 valid hours in each day. We'll allocate some memory for every one of them.

   //Test case 1: the "answer" variable, representing the number of lines detected inthe file, is passed out of the function as a pointer, and compared against the expected answer
    initSchedule(scheduleP);
    ok = readInputFile("final2020B.txt", &answer, scheduleP, theCoursePs, courseDecisionP); //This will ensure we have the right number of lines


    //Test Case 2: Tests the contents of the file very specifically, but by doing this makes sure the funtion is working.
    //Since the readInputFile function only reads the number of lines, and parses those lines into courses, we can use the following to rigidly test it.
    bool ok1 = true, ok2 = true, ok3 = true, ok4 = true; //4 lines in our test file.
    ok1 = getTimeBusy(scheduleP, 10, MONDAY);
    ok1 = ok1 ? getTimeBusy(scheduleP, 10, TUESDAY) : ok1; //Only set it if it's already true. If it's been made false, it will stay false.
    ok1 = ok1 ? getTimeBusy(scheduleP, 10, THURSDAY) : ok1;
    ok1 = ok1 ? getTimeBusy(scheduleP, 10, FRIDAY) : ok1;

    ok2 = getTimeBusy(scheduleP, 12, TUESDAY);
    ok2 = ok2 ? getTimeBusy(scheduleP, 12, FRIDAY) : ok2;

    ok3 = getTimeBusy(scheduleP, 9,WEDNESDAY);

    ok4 = getTimeBusy(scheduleP, 16, MONDAY);
    ok4 = ok4 ? getTimeBusy(scheduleP, 16, TUESDAY) : ok4; //Only set it if it's already true. If it's been made false, it will stay false.
    ok4 = ok4 ? getTimeBusy(scheduleP, 16, THURSDAY) : ok4;
    ok4 = ok4 ? getTimeBusy(scheduleP, 16, FRIDAY) : ok4;

    ok = ok1 && ok2 && ok3 && ok4;

    if (answer != rightAnswer)
    {
        puts("test readInputFile failed on number of courses\n");
        ok = false;
    }
    if (ok)
    {
        puts("Test readInputFile passed\n");
    }
    else
    {
        puts("Test readInputFile did not pass\n");
    }
    return ok;
}

bool testWriteScheduleToFile() //This is necessarily a visual test, though we can get some useful information from if the file fails to open, or we encounter some other IO error.
{
    bool ok = true;

    Schedule* testScheduleP = (Schedule*) malloc(sizeof(Schedule));
    testScheduleP->edgeTimeP = (int* ) malloc(5*13*sizeof(int));

    //This is necessarily a visual test, though we can get some useful information from if the file fails to open, or we encounter some other IO error.
    initSchedule(testScheduleP);
    char testDates[5];
    char* testDatesP = "MTWR";
    strcpy(testDates, testDatesP);
    for(int i = 0; i<5; i++)
    {
        setTimeBusy(testScheduleP, 13, i);
    }

    ok = writeScheduleToFile("testWriteFile_output.txt", testScheduleP);
    if (ok)
    {
        puts("Test WriteScheduleToFile passed");
    }
    else
    {
        puts("Test WriteScheduleToFile did not pass");
    }
    return ok;
}

bool testWriteDecisionListToFile() //This is necessarily a visual test, though we can get some useful information from if the file fails to open, or we encounter some other IO error.
{
    bool ok = true;
    LLNode* courseDecisionListP = makeEmptyLinkedList();


    char* courseDaysP[6] = {"MTW", "MRF", "TWR", "MTWRF"};

    for (int i = 0; i<4; i++)
    {
        CourseDecision* courseDecision = malloc(sizeof(CourseDecision));
        courseDecision->courseDates = malloc(7*sizeof(char));
        strcpy(courseDecision->courseDates, courseDaysP[i]);
        courseDecision->courseTime = i+8;
        courseDecision->courseAdded = i%2;
        savePayload(courseDecisionListP,courseDecision);
    }
    ok = writeDecisionListToFile("testWriteFile_output.txt",courseDecisionListP); //This method is written to append to the end of a file, so we can write it to the end of the other test file.

    if (ok)
    {
        puts("Test WriteScheduleToFile passed");
    }
    else
    {
        puts("Test WriteScheduleToFile did not pass");
    }
    return ok;
}


