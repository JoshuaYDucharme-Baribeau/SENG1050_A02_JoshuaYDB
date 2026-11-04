/*
 * FILE             : userInterface.c
 * PROJECT          : Assignment 2 Data Structures Stacks and Queues
 * PROGRAMMERS      : Joshua Ducharme-Baribeau
 * FIRST VERSION    : October 27 2026
 * DESCRIPTION      : C Source file for "userInterface.c" containing functions for
 *                    displaying menus, feedback and output to the user
 */

//Includes
#include <stdio.h>
#include <string.h>

//NB: add appropriate "../" depending on relative pathing to the h file
	//thus, if the src and h files are all in the same folder, remove "../inc/"
#include "../inc/userInterface.h"

//functions

/*
 * FUNCTION		: displayMsg
 * DESCRIPTION	: displays a message to the console
 * 
 * PARAMETERS	: char* message - a message to display
 * 
 * 
 * 
 * 
 * RETURNS		: void NOTHING
 */
void displayMsg(char* message)
{
	printf("\n%s\n", message);
}

/*
 * FUNCTION		: displayError
 * DESCRIPTION	: displays an error message to the console
 *
 * PARAMETERS	: char* message - an error message to display
 *
 *
 *
 *
 * RETURNS		: void NOTHING
 */
void displayError(char* message)
{
	printf("\nAn error occured:\n");
	printf("%s\n", errorMessage);
}

//display the main menu