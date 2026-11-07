/*
 * FILE             : main.c
 * PROJECT          : Assignment 2 Data Structures Stacks and Queues
 * PROGRAMMERS      : Joshua Ducharme-Baribeau
 * FIRST VERSION    : October 27 2026
 * DESCRIPTION      : C Source file for "main.c" containing the application's core logic.
 *                    Main entry for the application
 */


#include "../inc/userInterface.h"

int main() 
{
	int choice;
	while (1) {

		displayMenu();

		if (scanf("%d", &choice) != 1) {
			printf("\nInvalid input. Please enter a number.\n");
			while (getchar() != '\n'); // Clear the input buffer
			continue;
		}
		switch (choice) {
		case 1:
			CreateTaskNode(&head, &tail, &minID, &maxID);
			break;
		case 2:
			PrintTasks(&head);
			break;
		case 3:
			FindTaskViaId(&head);
			break;
		case 4:
			FindTaskWithText(&head);
			break;
		case 5:
			DeleteTaskById(&head, &tail, &minID, &maxID);
			break;
		case 6:
			printf("\n\nExiting and Freeing Allocated Memory.\n");
			FreeAllTasks(&head, &tail, &minID, &maxID);
			printf("Memory freed!\n");
			return 0;
		default:
			printf("\n\nInvalid choice. Please try again using the listed options.\n");
		}
	}
}