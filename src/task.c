#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "task.h"

#define RED   "\x1B[31m"
#define RESET "\x1B[0m"

struct Task composeTask(int id, char* title, char *descr, int important) {
    struct Task newTask;
    newTask.id = id;
    strcpy(newTask.tTitle, title);
    strcpy(newTask.tInfo, descr);
    newTask.isImportant = important;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(newTask.tAcceptedDate, "%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    return newTask;
}

void gatherInput(struct Task* t) {
    char ch = 'n';
    int id, important;
    char title[30], descr[100]; 
    printf("\033c");
    printf("=====NEW ENTRY======\n\n");
    printf("ENTER TITLE: ");
    fgets(title, 30, stdin);
    printf("ENTER DESCRIPTION: ");
    fgets(descr, 100, stdin);

    do {
        printf("\nIs it important? [y/n]: ");
        scanf("%c%*c", &ch);;
        if (ch == 'y') {
            important = 1;
        } else important = 0;
    } while (ch != 'y' && ch != 'n');

    if (file_exist("tasks.dat") == 0) {
        id = 1;
    } else {
        id = countID("tasks.dat") + 1;
    }

    (*t) = composeTask(id, title, descr, important);
}

void writeToFile(struct Task t) {
    FILE *file;

    if (file_exist("tasks.dat")) {
        file = fopen("tasks.dat", "ab");
    } else {
        file = fopen("tasks.dat", "wb");
    }

    fwrite(&t, sizeof(t), 1, file);
    fclose(file);

}

int readFromFile(struct Task* t, char* fName) {
    if (file_exist(fName) == 0) {
        return -1;
    }

    int i = 0;
    FILE *f = fopen(fName, "rb");
    fread(&task, sizeof(task), 1, f);

    while(!feof(f)) {
        t[i] = task;
        i++;
        fread(&task, sizeof(task), 1, f);
    }

    fclose(f);
    return 0;
}

int getSize(char* fName) {
    if (file_exist(fName) == 0) {
        return -1;
    }

    int size = 0;
    FILE *f = fopen(fName, "rb");
    fread(&task, sizeof(task), 1, f);
    while(!feof(f)) {
        ++size;
        fread(&task, sizeof(task), 1, f);       
    }

    fclose(f);
    return size;
}

void composeIndexArray(int* index, int indSize, struct Task* t) {
    int temp, i, j;

    for (i = 0; i < indSize; i++) index[i] = i;

    for (i = 1; i < indSize; i++) {
        temp = index[i];
        j = i - 1;

        while(j >= 0 && t[temp].id > t[j].id) {
            index[j + 1] = index[j];
            j--;
        }
        index[j + 1] = temp;
    }
}


void printAllTasks(int descMode, int importantTask) {
    struct Task *tasks = getData("tasks.dat");

    int i;
    int size = getSize("tasks.dat");

    int indexArr[size];

    composeIndexArray(indexArr, size, tasks);

    printf("\033c");

    if (importantTask == 1) {
        for (i = 0; i < size; i++) {
            if(tasks[i].isImportant == importantTask) {
                printf("[ID]: %d\n[TITLE]: %s[DESCRIPTION]: %s[DATE ACCEPTED]: %s",
                tasks[i].id, tasks[i].tTitle, tasks[i].tInfo, tasks[i].tAcceptedDate);
                printf("\n==========================\n");
            }
        }
	printf("\nPRESS ENTER TO CONTINUE...");
	getchar();

	return;	

    }

    if (descMode == 1) {
        for (i = 0; i < size; i++) {
	    if (tasks[i].isImportant == 1) {
                printf(RED "[ID]: %d\n[TITLE]: %s[DESCRIPTION]: %s[DATE ACCEPTED]: %s" RESET,
                tasks[indexArr[i]].id, tasks[indexArr[i]].tTitle, tasks[indexArr[i]].tInfo, tasks[indexArr[i]].tAcceptedDate);
                printf("\n==========================\n");
                continue;
            }
            printf("[ID]: %d\n[TITLE]: %s[DESCRIPTION]: %s[DATE ACCEPTED]: %s",
                tasks[indexArr[i]].id, tasks[indexArr[i]].tTitle, tasks[indexArr[i]].tInfo, tasks[indexArr[i]].tAcceptedDate);
            printf("\n==========================\n");
        }


    } else {
        for (i = 0; i < size; i++) {
            if (tasks[i].isImportant == 1) {
                printf(RED "[ID]: %d\n[TITLE]: %s[DESCRIPTION]: %s[DATE ACCEPTED]: %s" RESET,
                tasks[i].id, tasks[i].tTitle, tasks[i].tInfo, tasks[i].tAcceptedDate);
                printf("\n==========================\n");
                continue;
            }
	    printf("[ID]: %d\n[TITLE]: %s[DESCRIPTION]: %s[DATE ACCEPTED]: %s", 
		tasks[i].id, tasks[i].tTitle, tasks[i].tInfo, tasks[i].tAcceptedDate);
            printf("\n==========================\n");
        }
      }

    printf("\nPRESS ENTER TO CONTINUE...");
    getchar();
}

void showMenu() {
    printf("\033c");
    printf("TO-DO LIST\n");
    printf("\n[1] NEW ENTRY");
    printf("\n[2] SHOW ALL ENTRIES");
    printf("\n[3] SHOW ALL ENTRIES BY DATE");
    printf("\n[4] SHOW IMPORTANT ENTRIES");
    printf("\n[5] TERMINATE\n");
}

struct Task* getData(char* fName) {
    struct Task *tasks;

    if (getSize(fName) == 0) {
        tasks = malloc(sizeof(struct Task) * 1);
        tasks[0].id = -1;

        return tasks;
    }

    int size = getSize(fName);
    tasks = malloc(sizeof(struct Task) * size);
    readFromFile(tasks, fName);

    return tasks;
}

int file_exist(char *filename)
{
    struct stat buffer; 

    return (stat (filename, &buffer) == 0);
}

int countID(char* fName)
{
    FILE *file;
    int id = 0;
    file = fopen(fName, "r");

    while (!feof(file))
    {
        fread(&task, sizeof(task), 1, file);
        id = task.id;
    }

    fclose(file);

    return id;
}


