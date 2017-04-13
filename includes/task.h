#ifndef TASK_H
#define TASK_H
struct Task {
    int id;
    char tTitle[40]; //probably enough, heh?
    char tInfo[100]; //do we need more?
    char tAcceptedDate[80]; //probably change later
    int isImportant; //1 means important, 0 not
    int isInProgress; //1 means done 0 in progress. Probably won`t need this, but who knows
};

//function prototypes goes here
void newTask(FILE *);
void printAllTasks(FILE *);
void showTask(FILE *, int); //probably by id?
void removeTask(FILE *, int);//same as above?
#endif
