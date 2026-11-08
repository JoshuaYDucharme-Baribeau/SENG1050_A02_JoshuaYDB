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

	char input[20];
	int choice;
	char NewTaskName[MAX_NAME_LENGTH];
	int NewTaskPriority;



	while (1) {

		displayMenu();

		fgets(input, sizeof(input), stdin);
		//sscanf(input, "%d", &choice);

		if (sscanf(input, "%d", &choice) != 1) {
			printf("\nInvalid input. Please enter a number.\n");
			while (getchar() != '\n'); // Clear the input buffer
			continue;
		}
		switch (choice) {
		case 1:
			//Add a task TO QUEUE

			//clear the input name and priority in case
			NewTaskPriority = -1;
			
			//get input of the name
			GetNewTaskName(NewTaskName);
			//get input of the priority
			NewTaskPriority = GetNewTaskPriority();

			if (NewTaskName[0] != '\0' && NewTaskPriority != -1)
			{
				AddTask(queue, NewTaskName, NewTaskPriority);
			}
			break;
		case 2:
			//Process task
			ProcessTask(queue, stack);

			break;
		case 3:
			//Undo task
			UndoLastTask(stack, queue);
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
			printf("\n\nExiting Task Scheduler...\n\t>> Freeing Allocated Memory...");
			//do the freeing


			Task* current = queue->Front;
			//free anything in the queue
			while (current != NULL)
			{
				Task* tempNext = current->next;
				free(current);
				current = tempNext;
			}
			//free the queue struct
			free(queue);
			//free tasks on stack
			free(stack->bottomOfStack);
			//free the task struct
			free(stack);


			printf("\n\t>> Memory Cceanup complete!\n");
			return 0;
		default:
			printf("\n\nInvalid choice. Please try again using the listed options.\n");
		}
	}
}