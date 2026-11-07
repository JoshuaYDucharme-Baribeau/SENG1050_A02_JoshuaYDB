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

}

//potential error with declaration/allocation of nameOfDequeued
char* DeQueue(Queue* TaskQueue)
{
    if (IsQueueEmpty(TaskQueue))
    {
        printf("Queue is Empty");
        return NULL;
    }

    //instead of freeing completely, need to relocate the Task on the stack
    Task* TaskToDequeue = TaskQueue->Front;
    //get information
    char* nameOfDequeued = TaskToDequeue->Name;
    TaskQueue->Front = TaskToDequeue->next; // Resetting Head
    free(TaskToDequeue); // Free Up Existing Head
    return nameOfDequeued;
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
    if (TaskQueue == NULL) {
        printf("\nNo tasks are pending.\n");
        return;
    }
    Task* current = TaskQueue->Front;
    printf("\nPending Tasks:\n");
    while (current != NULL) {
        printf("\t%s\t(Priority: %d)\n", current->Name, current->PriorityLevel);
        printf("\n");
        current = current->next;
    }
    return;
}

