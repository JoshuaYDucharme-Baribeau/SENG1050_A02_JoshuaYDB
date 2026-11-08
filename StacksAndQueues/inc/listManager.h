/*
 * FILE             : listManager.h
 * PROJECT          : Assignment 2 Data Structures Stacks and Queues
 * PROGRAMMERS      : Joshua Ducharme-Baribeau
 * FIRST VERSION    : October 27 2026
 * DESCRIPTION      : header file for "listManager.c"
 *	This file contains prototypes and definitions for:
 *		- any stack or queue manipulations
 *		- any deletions or insertions of items
 *		- adtl helper functions for the above
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

//queue management prototypes
//initialize a queue
Queue* InititalizeQueue(void);

//add a task to the queue
void EnQueue(Queue* TaskQueue, char* TaskName, int PriorityLevel);

//return if queue is empty
bool IsQueueEmpty(Queue* TaskQueue);

//remove a task from the queue, coupled with adding to the stack
void DeQueue(Queue* TaskQueue, Stack* CompletedTaskStack);

//return the front of the queue
char* FrontOfQueue(Queue* TaskQueue);

//return the back of the queue
char* BackOfQueue(Queue* TaskQueue);

//create a node/task struct
Task* CreateTaskNode(char* TaskName, int PriorityLevel);

//required, add a task to the queue
void AddTask(Queue* TaskQueue, char* TaskName, int PriorityLevel);

//required, print the queued tasks
void ViewPendingTasks(Queue* TaskQueue);

//required, dequeue a task and push it on the stack
void ProcessTask(Queue* TaskQueue, Stack* CompletedTaskStack);


//prototypes for stack management below

//initialize a stack
Stack* InitializeStack(void);

//return if stack is empty
bool IsStackEmpty(Stack* stack);
//return if stack is full
bool IsStackFull(Stack* stack);

//peek at a task on the stack
Task* Peek(Stack* stack, int ixToPeek);

//part of processing a task
void Push(Stack* stack, Task taskToPush);

//part of undoing a task
Task Pop(Stack* stack);

//required
void ViewCompletedTasks(Stack* CompletedTaskStack);

//required
void UndoLastTask(Stack* CompletedTaskStack, Queue* TaskQueue);





#endif