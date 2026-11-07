/*
 * FILE             : inputHandler.c
 * PROJECT          : Assignment 2 Data Structures Stacks and Queues
 * PROGRAMMERS      : Joshua Ducharme-Baribeau
 * FIRST VERSION    : October 27 2026
 * DESCRIPTION      : C Source file for "inputHandler.c" containing logic for handling
 *                    and validating user input
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//might need to pass the queue and stack to check for duplicate names if we want to prevent duplicate tasks
//	since there is nothing in the instructions, will omit validating duplicate task names for now
void GetNewTaskName(char** TaskName)
{
	bool isValidNameFlag = false;
	
	char* input = (char*)malloc(50);
	//check for allocation failure
	if (input == NULL) {
		printf("\n\nMemory allocation failed. Exiting\n");
		exit(EXIT_FAILURE);
	}

	while (getchar() != '\n'); // Clear the input buffer in case of previous inputs

	while (!isValidNameFlag)
	{
		printf("\nEnter Task Name: ");
		if (fgets(input, 50, stdin) == NULL) {
			// if there was an error reading input
			input[0] = '\0';
			printf("\n\nError reading input. Please try again.\n");
			//try again
			continue;
		}

		//get the length of the output string
		size_t len = strlen(input);

		//if length bigger than 0, make sure the last char is null terminator
		if (len > 0 && input[len - 1] == '\n') {
			// remove trailing newline from user pressing enter
			input[len - 1] = '\0';
		}
		//else if input was longer than buffer and thus had no null terminator, truncate the input 
		else {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}

		//if the resulting string is empty, re-prompt
		if (input[0] == '\0') {
			printf("\n\nThe input was invalid. Please try again.\nThe maximum number of characters is allowed is %d.\n", 49);
			input[0] = '\0'; // set the output to an empty string just in case
			continue;
		}

		//name is valid at this point, set flag to true
		isValidNameFlag = true;

	}

	*TaskName = input;

	return;

}

int GetNewTaskPriority()
{
	int outputInt = -1;
	bool isValidInt = false;
	char input[10];

	while (getchar() != '\n'); // Clear the input buffer in case of previous inputs
	while (!isValidInt)
	{
		outputInt = -1; // reeset the input to a -1 in case of error

		printf("\nEnter Task Priority (1-5): ");
		//if the input is a valid integer (between 1 and 5)
		
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n\nInvalid input. Please enter an integer from 1 to 5.\n");
			continue; //too many chars, retry
		}
		else if (sscanf(input, "%d", &outputInt) == 1 && outputInt > 0 && outputInt < 6)
		{
			isValidInt = true; //change flag to exit
		}
		else 
		{
			printf("\n\nInvalid input. Please enter an integer from 1 to 5.\n");
		}
	}

	return outputInt;
}