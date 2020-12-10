//
// Created by John on 12/8/2020.
//

#ifndef CS2301_HW4_ADJMAT_H
#define CS2301_HW4_ADJMAT_H

#include <stdbool.h>
typedef struct
{
    int n; //TODO: Maybe change to nCourses?
    int* edgesP; //TODO: Change to something like timeP, to represent the inital time, 8AM on monday. We can probably use pointers just like those in the adjacency matrix.
}AdjMat;


void setEdge(AdjMat* adjMP, int row, int col);
int getEdge(AdjMat* adjMP, int row, int col);
void init(AdjMat* adjMP);

#endif //CS2301_HW4_ADJMAT_H
