/*
 * LinkedList.c
 *
 *  Created on: Nov 4, 2019
 *      Author: Therese
 */


#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool isEmpty(LLNode* lp)
{
    bool ans = false;
    if(lp->payP == (Payload*)0)
    {
        ans = true;
    }
    return ans;
}

LLNode* makeEmptyLinkedList()
{
    LLNode* lp = (LLNode*) malloc(sizeof(LLNode));
    CourseDecision* cdP = (CourseDecision*) (sizeof(CourseDecision));
    lp->next = (struct LLNode*)0;
    lp->prev = (struct LLNode*)0;
    lp->payP = (Payload*)0;

    return lp;
}



void savePayload(LLNode* lp, Payload* mp)
{
    //if the list is empty, then make payP be mp
    //else traverse the list,
    //make a new list element
    //put mp in that
    //attach the new list element to the existing list
    if(isEmpty(lp))
    {

        lp->payP = mp;
    }
    else
    {
        LLNode* temp = lp;
        while(temp->next)
        {
            temp=(LLNode*)temp->next;
        }
        //now temp points to the last element

        //make a new element, attach mp to it, wire up the new element

        LLNode* newList = makeEmptyLinkedList();
        newList->payP = mp;
        temp->next = (struct LLNode*)newList;
        newList->prev = (struct LLNode*) temp;
    }
}
void printHistory(LLNode* hp)
{
    puts("Printing history");
    if(hp->payP ==(Payload*)0)
    {
        puts("Empty list");
    }
    else
    {
        int courseTime = 0;
        bool courseAdded = false;
        char courseDates[7];
        LLNode* temp = hp;
        while (temp->next)
        {

            courseTime = temp->payP->courseTime;

            courseAdded = temp->payP->courseAdded;
            strcpy(courseDates, temp->payP->courseDates);
            if (courseAdded)
            {
                printf("No conflict found. The course with meeting dates %s at time %d:00 was added to the schedule.\n", courseDates, courseTime);
            }
            else
            {
                printf("Conflict found. The course with meeting dates %s at time %d:00 was NOT added to the schedule.\n", courseDates, courseTime);
            }
            temp = (LLNode*)temp->next;
        }
        courseTime = temp->payP->courseTime;
        courseAdded = temp->payP->courseAdded;
        strcpy(courseDates, temp->payP->courseDates);
        if (courseAdded)
        {
            printf("No conflict found. The course with meeting dates %s at time %d:00 was added to the schedule.\n", courseDates, courseTime);
        }
        else
        {
            printf("Conflict found. The course with meeting dates %s at time %d:00 was NOT added to the schedule.\n", courseDates, courseTime);
        }
    }
}





