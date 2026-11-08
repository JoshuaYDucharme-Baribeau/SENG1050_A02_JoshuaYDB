/*
 * FILE             : inputHandler.h
 * PROJECT          : Assignment 2 Data Structures Stacks and Queues
 * PROGRAMMERS      : Joshua Ducharme-Baribeau
 * FIRST VERSION    : October 27 2026
 * DESCRIPTION      : header file for "inputHandler.c"
 *	This file contains prototypes and definitions for:
 *		- Any user input functions
 *		- Any deep data validation (!null checks and such may be externalized to avoid complete atomization)
 *
 */
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#define MAX_NAME_LENGTH 50
void GetNewTaskName(char taskName[MAX_NAME_LENGTH]);

int GetNewTaskPriority();


#endif