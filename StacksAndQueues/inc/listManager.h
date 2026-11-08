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

#include <stdbool.h>

//define a maximum size for the stack
#define MAX_STACK_SIZE 10

//struct as defined in instructions
typedef struct Task
{
	char Name[50];
	int PriorityLevel;
	struct Task* next;
}Task;

//struct for the queue, from instructor demo code
typedef struct Queue
{
	Task* Front; // HEAD POINTER
	Task* Back; // TAIL POINTER
}Queue;

//struct for the stack, from instructor demo code
typedef struct Stack
{
	Task* bottomOfStack;
	int topIndex;
}Stack;


Queue* InititalizeQueue(void);

void EnQueue(Queue* TaskQueue, char* TaskName, int PriorityLevel);

bool IsQueueEmpty(Queue* TaskQueue);

//potential error with declaration/allocation of nameOfDequeued
void DeQueue(Queue* TaskQueue, Stack* CompletedTaskStack);

char* FrontOfQueue(Queue* TaskQueue);

char* BackOfQueue(Queue* TaskQueue);

Task* CreateTaskNode(char* TaskName, int PriorityLevel);

// req
void AddTask(Queue* TaskQueue, char* TaskName, int PriorityLevel);

// req
void ViewPendingTasks(Queue* TaskQueue);

//req
void ProcessTask(Queue* TaskQueue, Stack* CompletedTaskStack);


//prototypes for stack management
Stack* InitializeStack(void);


bool IsStackEmpty(Stack* stack);
bool IsStackFull(Stack* stack);

Task* Peek(Stack* stack, int ixToPeek);

//part of processing a task
void Push(Stack* stack, Task taskToPush);

//part of undoing a task
Task Pop(Stack* stack);

//req
void ViewCompletedTasks(Stack* CompletedTaskStack);



//req 
void UndoLastTask(Stack* CompletedTaskStack, Queue* TaskQueue);





#endif