/*
 * FILE             : listManager.c
 * PROJECT          : Assignment 2 Data Structures Stacks and Queues
 * PROGRAMMERS      : Joshua Ducharme-Baribeau
 * FIRST VERSION    : October 27 2026
 * DESCRIPTION      : C Source file for "listManager.c" containing the logic for manipulating the tasks.
 *                    
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../inc/listManager.h"

//queue management

//initialize the queue
Queue* InititalizeQueue(void)
{
    Queue* task_queue = (Queue*)malloc(sizeof(Queue));
    if (task_queue == NULL)
    {
        printf("Memory allocation failed. Exiting");
        exit(EXIT_FAILURE);
    }

    task_queue->Front = NULL;
    task_queue->Back = NULL;
    return task_queue;
}



void EnQueue(Queue* TaskQueue, char* TaskName, int PriorityLevel)
{
    if (TaskQueue == NULL)
    {
        TaskQueue = InititalizeQueue();
    }

    Task* toEnqueue = CreateTaskNode(TaskName, PriorityLevel);
    if (IsQueueEmpty(TaskQueue))
    {
        TaskQueue->Front = toEnqueue;
        TaskQueue->Back = toEnqueue;
    }
    else
    {
        TaskQueue->Back->next = toEnqueue;
        TaskQueue->Back = toEnqueue;
    }
    printf("\t>> Task added successfully.");
    return;
}

void DeQueue(Queue* TaskQueue, Stack* CompletedTaskStack)
{
    if (IsQueueEmpty(TaskQueue))
    {
        //should not occur since it was verified externally
        printf("There are no pending tasks to process");
    }
    if (!IsQueueEmpty(TaskQueue) && !IsStackFull(CompletedTaskStack))
    {
        Task* TaskToDequeue = TaskQueue->Front;
        //create a new pointer for the stack to use
        Task* TaskToPush = TaskToDequeue;

        TaskQueue->Front = TaskToDequeue->next; // Resetting Head of the queue

        //reset the back of the queue to null if the dequeued task was the only task
        if (TaskQueue->Front == NULL)
        {
            TaskQueue->Back = NULL;
        }
        
        //add to stack here, sternly coupled bc you can only add to the stack by dequeuing
        Push(CompletedTaskStack, *TaskToPush);

        free(TaskToDequeue); // Free the existing head pointer of the queue
        printf("\t>> Task marked as completed and moved to the completed tasks stack.");
    }
    else
    {
        printf("The stack is full, could not process a task!\n");
    }
    return;
}

//check if queue is empty
bool IsQueueEmpty(Queue* TaskQueue)
{
    return TaskQueue->Front == NULL;
}

//check the name of the task at the front of the queue
char* FrontOfQueue(Queue* TaskQueue) 
{
    if (IsQueueEmpty(TaskQueue))
    {
        printf("Queue is Empty");
        return NULL;
    }

    return TaskQueue->Front->Name;
}

//check the name of the task at the back of the queue
char* BackOfQueue(Queue* TaskQueue)
{
    if (IsQueueEmpty(TaskQueue))
    {
        printf("Queue is Empty");
        return NULL;
    }

    return TaskQueue->Back->Name;
}

//create a task node
Task* CreateTaskNode(char* TaskName, int PriorityLevel)
{
    Task* newTask = (Task*)malloc(sizeof(Task));
    if (newTask == NULL) {
        printf("Memory allocation failed. Exiting.");
        exit(EXIT_FAILURE);
    }

    snprintf(newTask->Name, sizeof newTask->Name, "%s", TaskName);
    newTask->PriorityLevel = PriorityLevel;
    newTask->next = NULL;
    return newTask;
}

//add [MENU FUNCTION CALL FOR ADDING A TASK TO THE LIST] I DON'T LIKE THIS UNSPECIFIC NAME BUT IT IS IN THE REQUIREMENTS AND I GOT DOCKED LAST ASSIGNMENT FOR CHANGING IT.
//this helper function allows a place for us to re-direct the enqueuing process if needed or add additional logic/validation
void AddTask(Queue* TaskQueue, char* TaskName, int PriorityLevel)
{
    //this is where we actually enqueue the task
    EnQueue(TaskQueue, TaskName, PriorityLevel);
}



//view a list of tasks in the queue
void ViewPendingTasks(Queue* TaskQueue)
{
    if (IsQueueEmpty(TaskQueue))
    {
        printf("\nNo tasks are pending.\n");
    }
    else
    {
        Task* current = TaskQueue->Front;
        printf("\nPending Tasks:\n");
        while (current != NULL)
        {
            printf("\t%s\t(Priority: %d)\n", current->Name, current->PriorityLevel);
            printf("\n");
            current = current->next;
        }
    }

    return;
}



void ProcessTask(Queue* TaskQueue, Stack* CompletedTaskStack)
{
    if (!IsQueueEmpty(TaskQueue))
    {
        printf("Processing task: \"%s\"\n", FrontOfQueue(TaskQueue));
        DeQueue(TaskQueue, CompletedTaskStack); //dequeue will also move the task to the stack due to stern coupling

    }
    //queue is empty
    else
    {
        printf("There are no tasks to process!\n");
    }

    return;
}

//stack management functions

//initialize the stack to be empty
Stack* InitializeStack(void) {
    Stack* taskStack = (Stack*)malloc(sizeof(Stack));
    taskStack->bottomOfStack = (Task*)malloc(MAX_STACK_SIZE * sizeof(Task));
    taskStack->topIndex = -1;
    return taskStack;
}


//check if stack is empty
bool IsStackEmpty(Stack* stack)
{
    return stack->topIndex == -1;
}

//check if stack is full
bool IsStackFull(Stack* stack)
{
    return stack->topIndex == MAX_STACK_SIZE - 1;
}

//Peek at the stack
//  only call if you have verified that the stack is not empty
//  will likely only be called by the ViewCompletedTasks function's loop
Task* Peek(Stack* stack, int ixToPeek)
{
    //should be avoided if possible
    if (IsStackEmpty(stack))
    {
        printf("Stack Underflow Exception");
        exit(EXIT_FAILURE);
    }

    //return the address of the pointer to the peeked item so caller can decide what to do with it
    return &stack->bottomOfStack[ixToPeek];
}

void Push(Stack* stack, Task taskToPush)
{
    //avoid with validation if possible
    if (IsStackFull(stack))
    {
        printf("Stack Overflow Exception");
        exit(EXIT_FAILURE);
    }

    //NOTE: scrubbing/nulling the pointer of the Next task when pushing onto the stack, since it may be pointing to something that changes
    taskToPush.next = NULL;

    // pushing a piece of data onto the top of the stack and
    // incrementing the index in one "combo" statement
    stack->bottomOfStack[++stack->topIndex] = taskToPush;
}

Task Pop(Stack* stack) {
    if (IsStackEmpty(stack)) {
        printf("Stack Underflow Exception");
        exit(EXIT_FAILURE);
    }

    // popping the piece of data off the top of the stack and 
    // decrementing the index in one "combo" statement
    return stack->bottomOfStack[stack->topIndex--];
}

void ViewCompletedTasks(Stack* CompletedTaskStack)
{
    if (IsStackEmpty(CompletedTaskStack))
    {
        printf("\nNo Completed tasks to display.\n");
    }
    else
    {
        Task* current;
        int ix_to_peek = CompletedTaskStack->topIndex; //set the pointer to the top of the stack
        printf("\nPending Tasks:\n");
        while (ix_to_peek >= 0)
        {
            //could use this instead of the peek function here 
            //  current = &CompletedTaskStack->bottomOfStack[ix_to_peek];
            // I like the way this looks and it helped me understand the way things are being accessed/dereferenced
            current = Peek(CompletedTaskStack, ix_to_peek);

            printf("\t%s\t(Priority: %d) [Done!]\n", current->Name, current->PriorityLevel);
            printf("\n");
            ix_to_peek--;
        }
    }

    return;
}