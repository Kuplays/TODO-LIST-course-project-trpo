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
struct Task composeTask(int, char*, char*, int); 
void gatherInput(struct Task*);
void writeToFile(struct Task);

int getSize(char*);
int readFromFile(struct Task*, char*);
struct Task* getData(char*);

void printAllTasks();
void composeIndexArray(int*, int, struct Task*);
void showMenu();
int file_exist(char *);
int countID(char*);
#endif
