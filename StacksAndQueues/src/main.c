/*
 * FILE             : main.c
 * PROJECT          : Assignment 2 Data Structures Stacks and Queues
 * PROGRAMMERS      : Joshua Ducharme-Baribeau
 * FIRST VERSION    : October 27 2026
 * DESCRIPTION      : C Source file for "main.c" containing the application's core logic.
 *                    Main entry for the application
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/userInterface.h"
#include "../inc/inputHandler.h"
#include "../inc/listManager.h"

int main() 
{
	//initialize the queue
	Queue* queue = InititalizeQueue();
	Stack* stack = InitializeStack();

	int choice;
	char* NewTaskName = NULL;
	int NewTaskPriority;

	while (1) {

		displayMenu();

		if (scanf("%d", &choice) != 1) {
			printf("\nInvalid input. Please enter a number.\n");
			while (getchar() != '\n'); // Clear the input buffer
			continue;
		}
		switch (choice) {
		case 1:
			//Add a task TO QUEUE

			//clear the input name and priority in case
			NewTaskName = NULL;
			NewTaskPriority = -1;
			
			//get input of the name
			GetNewTaskName(&NewTaskName);
			//get input of the priority
			NewTaskPriority = GetNewTaskPriority();

			if (NewTaskName[0] == '\0')
			{
				//show name error, should not occur as input handler handles validation
			}
			if (NewTaskPriority == -1)
			{
				//show priority error, should not occur as input handler handles validation
			}
			if (NewTaskName[0] != '\0' && NewTaskPriority != -1)
			{
				AddTask(queue, NewTaskName, NewTaskPriority);
				//free the memory that taskNameInput was assigned within the AddTask call
				free(NewTaskName);
				//empty the NewTaskName pointer so it doesn't point to random memory later
				NewTaskName = NULL;
			}
			break;
		case 2:
			//Process task
			ProcessTask(queue, stack);

			break;
		case 3:
			//Undo task
			break;
		case 4:
			//view queue
			ViewPendingTasks(queue);
			break;
		case 5:
			//view stack
			ViewCompletedTasks(stack);
			break;
		case 6:
			//exit
			printf("\n\nExiting and Freeing Allocated Memory.\n");
			printf("Memory freed!\n");
			return 0;
		default:
			printf("\n\nInvalid choice. Please try again using the listed options.\n");
		}
	}
}