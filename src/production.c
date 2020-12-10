/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include "production.h"
#include "AdjMat.h"

#include "LinkedList.h"
bool production(int argc, char* argv[])
{
    bool answer = false;

    if(argc <=1) //no interesting information
    {
        puts("Didn't find any arguments.");
        fflush(stdout);
        answer = false;
    }
    else //there is interesting information
    {
        printf("Found %d interesting arguments.\n", argc-1);
        fflush(stdout);
        char input_initial_filename[FILENAMELENGTHALLOWANCE];
        char input_additional_filename[FILENAMELENGTHALLOWANCE];
        char output_filename[FILENAMELENGTHALLOWANCE];
        char* eptr=(char*) malloc(sizeof(char*));
        long aL=-1L;

        if (argc !=4)
        {
            printf("Unexpected argument count! Expected 3 interesting arguments, found %d.", argc-1);
        }
        else {
            for (int i = 1; i < argc; i++) //don't want to read argv[0]
            {//argv[i] is a string
                //in this program our arguments are NR, NC, gens, filename, print and pause
                //because pause is optional, argc could be 6 or 7
                //because print is optional (if print is not present, neither is pause) argc could be 5
                switch (i) {
                    case 1:
                        //this is filename for the file with the initial schedule
                        printf("The length of the initial input filename is %d.\n", strlen(argv[i]));
                        printf("The proposed initial input filename is %s.\n", argv[i]);
                        if (strlen(argv[i]) >= FILENAMELENGTHALLOWANCE) {
                            puts("Filename is too long.");
                            fflush(stdout);
                            answer = false;
                        } else {
                            strcpy(input_initial_filename, argv[i]);
                            printf("Input Filename with initial courses was %s.\n", input_initial_filename);
                            fflush(stdout);
                        }
                        break;
                    case 2:
                        //this is the filename for the file with the proposed additional courses
                        printf("The length of the additional input filename is %d.\n", strlen(argv[i]));
                        printf("The proposed additional input filename is %s.\n", argv[i]);
                        if (strlen(argv[i]) >= FILENAMELENGTHALLOWANCE)
                        {
                            puts("Filename is too long.");
                            fflush(stdout);
                            answer = false;
                        }
                        else
                        {
                            strcpy(input_additional_filename, argv[i]);
                            printf("Input Filename with additional courses was %s.\n", input_additional_filename);
                            fflush(stdout);
                        }

                        break;
                    case 3:
                        //this is filename for the output file
                        printf("The length of the output filename is %d.\n", strlen(argv[i]));
                        printf("The proposed output filename is %s.\n", argv[i]);
                        if (strlen(argv[i]) >= FILENAMELENGTHALLOWANCE) {
                            puts("Filename is too long.");
                            fflush(stdout);
                            answer = false;
                        } else {
                            strcpy(input_initial_filename, argv[i]);
                            printf("Output filename was %s.\n", input_initial_filename);
                            fflush(stdout);
                        }

                        break;

                    default:
                        puts("Unexpected argument count.");
                        fflush(stdout);
                        answer = false;
                        break;
                }//end of switch
            }//end of for loop on argument count
        }//end of argument read
        puts("after reading arguments"); fflush(stdout);
        //we'll want to read the file
        int nrooms = -1;
        AdjMat* adjMP = (AdjMat*) malloc(sizeof(AdjMat)); //TODO change this to schedule

        Course* theCoursePs[10];//addresses for 10 rooms

        puts("Before read file"); fflush(stdout);
        //answer = readFile(input_initial_filename, &nrooms, adjMP, theCoursePs); //read the file
        puts("Back from read file"); fflush(stdout);



        //while search is not done
        //search is now done, time to print the history
        //printHistory(historyP);


    }//end of else we have good arguments

    return answer;
}
bool readInitialInputFile()
{
    bool ok = false;
    //the file tells how many rooms there are

    ok = true;



    return ok;
}

