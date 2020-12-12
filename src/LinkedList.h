/*
 * LinkedList.h
 *
 *  Created on: Nov 4, 2019
 *      Author: Therese
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdbool.h>

#include "Course.h"


typedef struct
{
    int courseTime;
    char* courseDates;
    bool courseAdded;
}CourseDecision;
typedef CourseDecision Payload;

struct LLNode;
typedef struct
{
    struct LLNode* next;
    struct LLNode* prev;
    Payload* payP;
}LLNode;




LLNode* makeEmptyLinkedList();
void savePayload(LLNode* lp, Payload* mp);
bool isEmpty(LLNode* lp);
void printHistory(LLNode* hp);






#endif /* LINKEDLIST_H_ */

