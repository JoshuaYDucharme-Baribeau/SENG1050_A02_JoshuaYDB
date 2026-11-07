/*
 * FILE             : listManager.h
 * PROJECT          : Assignment 2 Data Structures Stacks and Queues
 * PROGRAMMERS      : Joshua Ducharme-Baribeau
 * FIRST VERSION    : October 27 2026
 * DESCRIPTION      : header file for "listManager.c"
 *	This file contains prototypes and definitions for:
 *		- Any memory freeing functions
 *		- any stack or queue manipulations
 *		- any deletions or insertions of items
 * 
 */
#ifndef LISTMANAGER_H
#define LISTMANAGER_H

//struct as defined in instructions
typedef struct Task
{
	char Name[50];
	int PriorityLevel;
	struct Task* next;
}Task;

//void AddTask(Queue* TaskQueue, char* TaskName, int PriorityLevel);
// 
//void ProcessTask(Queue* TaskQueue, Stack* CompletedTaskStack);
// 
//void UndoLastTask(Stack* CompletedTaskStack, Queue* TaskQueue);
// 
//void ViewPendingTasks(Queue* TaskQueue);
// 
//void ViewCompletedTasks(Stack* CompletedTaskStack);

#endif