/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include "production.h"
#include "AdjMat.h"

#include "LinkedList.h"
#include "Schedule.h"

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
                            puts("Filename is too long.\n");
                            fflush(stdout);
                            answer = false;
                        } else {
                            strcpy(output_filename, argv[i]);
                            printf("Output filename was %s.\n", output_filename);
                            fflush(stdout);
                        }

                        break;

                    default:
                        puts("Unexpected argument count.");
                        fflush(stdout);
                        answer = false;
                        break;
                }//end of switch
                printf("\n");
            }//end of for loop on argument count
            puts("after reading arguments"); fflush(stdout);
            //we'll want to read the file
            int nCourses = -1;
            Schedule* scheduleP = (Schedule *) malloc(sizeof(Schedule)); //TODO change this to schedule

            Course* theCoursePs[20];//addresses for 20 courses
            scheduleP->edgeTimeP = (int* ) malloc(5*13*sizeof(int)); //There are 5 days in the week, and 13 valid hours in each day. We'll allocate some memory for every one of them.
            puts("About to initialize the schedule");
            initSchedule(scheduleP);


            puts("Before read initial input file"); fflush(stdout);
            answer = readInitialInputFile(input_initial_filename, &nCourses, scheduleP, theCoursePs); //read the file
            puts("Back from read file"); fflush(stdout);

            puts("Before read additional input file"); fflush(stdout);
            answer = readInitialInputFile(input_additional_filename, &nCourses, scheduleP, theCoursePs); //read the file
            puts("Back from read file"); fflush(stdout);

            answer = writeScheduleToFile(output_filename,&nCourses, scheduleP, theCoursePs);
        }//end of argument read




        //while search is not done
        //search is now done, time to print the history
        //printHistory(historyP);


    }//end of else we have good arguments

    return answer;
}



bool readInitialInputFile(char* filename, int* nCourses, Schedule* theScheduleP, Course** theCoursePs) //TODO: Add ability to add decisions to a linked list
{
    bool ok = false;
    //the file tells how many rooms there are
    FILE* fp = fopen(filename, "r");

    int courseCount = 0;
    char c;
    char potentialCourseDays[5];

    int potentialCourseTime;
    int daysUsedCounter=0;


    displaySchedule(theScheduleP); //TODO: Remove line, just here for debugging.
    if(fp == NULL)
    {
        puts("Error opening file!");
    }
    else
    {
        //Begins the part where we count the number of courses
        puts("Printing the file to console..");
        for (c = getc(fp); c != EOF; c = getc(fp))
        {
            if (c == '\n' || c =='\0')
            {
                char tempGet = getc(fp);
                if (tempGet !='\n' && tempGet != EOF)//Test if line is empty
                {
                    courseCount++;
                }
                ungetc(tempGet, fp); //Puts back the character we tested
            }


            printf("%c", c); fflush(stdout);
        }
        printf("\n");
        courseCount++;
        *nCourses = courseCount;
        //End count courses
        rewind(fp); //This will reset us to the start of the file, so we can read again, looking for different information.
        //Begin parsing course data.
        char courseDates[10][5];
        for(int i = 0; i<courseCount; i++)
        {
            char *courseDays = "";
            int courseTime = 0;
            fscanf(fp, "%s",courseDays);
            fscanf(fp, "%d", &courseTime);
            strcpy(courseDates[i], courseDays);

            printf("Days for course: %s\n", courseDays);
            printf("The course is held at time: %d\n", courseTime); fflush(stdout);

            int array_length = *(&courseDates[i]+1)-courseDates[i];
            bool conflictsFound = getScheduleConflict(theScheduleP, courseDates[i], courseTime);
            if (!conflictsFound)
            {
                for(int j = 0; j<5; j++)//Should only be 5 possible dates in the string.
                {
                    switch (courseDates[i][j])
                    {
                        case 'M':
                            setTimeBusy(theScheduleP, courseTime, MONDAY);
                            break;
                        case 'T':
                            setTimeBusy(theScheduleP, courseTime, TUESDAY);
                            break;
                        case 'W':
                            setTimeBusy(theScheduleP, courseTime, WEDNESDAY);
                            break;
                        case 'R':
                            setTimeBusy(theScheduleP, courseTime, THURSDAY);
                            break;
                        case 'F':
                            setTimeBusy(theScheduleP, courseTime, FRIDAY);
                            break;
                        default:
                            break;
                    }

                }
            }

        }

    }
    printf("The schedule %s has %d lines\n", filename, courseCount); fflush(stdout);
    displaySchedule(theScheduleP);
    ok = true;



    return ok;
}

bool writeScheduleToFile(char* filename, int* nCourses, Schedule* theScheduleP, Course** theCoursePs)
{
    bool ok = false;
    //the file tells how many rooms there are
    FILE* fp = fopen(filename, "w");

    int courseCount = 0;
    char c;
    char potentialCourseDays[5];

    int potentialCourseTime;
    int daysUsedCounter=0;

    puts("About to write the following schedule to file...\n");
    //displaySchedule(theScheduleP);
    if(fp == NULL)
    {
        puts("Error opening file!\n");
    }
    else
    {
        const int DaysInWeek = 5;
        const int HoursInDay = 13; //Is 8PM a valid start time?

        fputs("   M T W R F \n",fp);
        for (int row = 0; row<HoursInDay; row++)
        {
            fprintf(fp,"%2d", row+8); //We start at 8AM. Formatting is to pad the times
            for (int col = 0; col<DaysInWeek; col++)
            {
                int* memoryToCheck = ((theScheduleP->edgeTimeP)+(row*DaysInWeek)+col);

                fprintf(fp,"|%d", *memoryToCheck);
            }
            fprintf(fp,"|\n");fflush(stdout);
        }
    }
    fclose(fp);
}
