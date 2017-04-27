#include <stdio.h>
#include <time.h>
#include "task.h"

int newFile(FILE *file)
{
    char ch = 'n';
    file = fopen("tasks.dat", "wb");
    system("CLS");
    printf("==========NEW FILE MODE============\n\n");
    
    int idCount = 0;
    do
    {
        task.id = ++idCount;
        printf("TASK TITILE: ");
        fgets(task.tTitle, 30, stdin);
        printf("TASK DESCRIPTION:");
        fgets(task.tInfo, 100, stdin);
        
        do {
            printf("\nIs it important? [y/n]: ");
            scanf(" %c", &ch);
            fflush(stdin);
            if (ch == 'y') {
                task.isImportant = 1;
            } else task.isImportant = 0;
    } while (ch != 'y' && ch != 'n');

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(task.tAcceptedDate, "%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    task.isInProgress = 1;
        
        fwrite(&task, sizeof(task), 1, file);
        printf("Are we done? [y/n]: ");
        scanf(" %c", &ch);
        fflush(stdin);
    } while (ch != 'y');
    
    fclose(file);
}