/*
 ============================================================================
 Name        : 2020HW3starter.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "TMSName.h"
#include <time.h>


int main(int argc, char* argv[]) {
	puts("!!!Let's do  HW4!!!"); /* prints !!!Hello World!!! */
	srand(time(0));
	if(tests())
	{
	    puts ("All tests passed");
	    puts ("----------------------------");
		puts("About to run production.");
		production(argc, argv);
	}
	else
	{
		 puts("Tests did not pass.");
	}

	return EXIT_SUCCESS;

}