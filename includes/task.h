#include <stdio.h>
#include <sys/stat.h>
#ifndef TASK_H
#define TASK_H
struct Task {
    int id;
    char tTitle[30]; //probably enough, heh?
    char tInfo[100]; //do we need more?
    char tAcceptedDate[30]; //probably change later
    int isImportant; //1 means important, 0 not
    int isInProgress; //1 means done 0 in progress. Probably won`t need this, but who knows
} task;

//function prototypes goes here
int newEntry(FILE *, char*, int);
void printAllTasks(FILE *);
void showTask(FILE *, int); //probably by id?
int removeTask(FILE *, int);//same as above?
int menu ();
int appendTask(FILE *);
int file_exist(char *);
int countID(FILE *file, char*);
#endif
