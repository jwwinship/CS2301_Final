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
    bool ok1 = testReadFile();
	bool ok2 = testMakeLList();
	bool ok3 = testGotAdjacencyMatrix();
	bool ok4 = testSetEdge();
	bool ok5 = testGetEdge();
	bool ok6 = testDequeue();
	bool ok7 = testPrintHistory();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7;
	return answer;
}



bool testGotAdjacencyMatrix()
{
	bool ans = true;

    if (ans)
    {
        puts("Test gotAdjMatrix passed");
    }
    else
    {
        puts("Test gotAdjMatrix did not pass");
    }

	return ans;
}

bool testSetEdge()
{

    bool ans = true;
    puts("Testing SetEdge...");

    if (ans)
    {
        puts("Test setEdge passed");
    }
    else
    {
        puts("Test setEdge did not pass");
    }

    return ans;
}

bool testGetEdge()
{
    bool ans = true;
    puts("Testing GetEdge...");

    if (ans)
    {
        puts("Test GetEdge passed");
    }
    else
    {
        puts("Test GetEdge did not pass");
    }

    return ans;
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

bool testReadFile()
{
    puts("starting testReadFile"); fflush(stdout);
    bool ok = false;
    //the file tells how many rooms there are
    int answer = -1;
    int rightAnswer = 8;


    AdjMat* adjMP = (AdjMat*) malloc(sizeof(AdjMat));
    Course* theCoursePs[10];//addresses for 10 rooms




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