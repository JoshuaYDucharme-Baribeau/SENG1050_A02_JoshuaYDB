/*
 * FILE             : main.c
 * PROJECT          : Assignment 2 Data Structures Stacks and Queues
 * PROGRAMMERS      : Joshua Ducharme-Baribeau
 * FIRST VERSION    : October 27 2026
 * DESCRIPTION      : C Source file for "main.c" containing the application's core logic.
 *                    Main entry for the application
 */


#include "../inc/userInterface.h"
#include "../inc/listManager.h"

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
			//Add a task
			break;
		case 2:
			//Process task
			break;
		case 3:
			//Undo task
			break;
		case 4:
			//view queue
			break;
		case 5:
			//view stack
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