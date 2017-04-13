#include <stdio.h>
#include "task.h"

int main(void) {
    struct Task task;
    char ch;
    task.id = 1;
    printf("Test Run\nTask title: ");
    fgets(task.tTitle, 40, stdin);
    printf("\nTask Description: ");
    fgets(task.tInfo, 100, stdin);

    do {
        printf("\nIs it important? [y/n]: ");
        scanf("%c", &ch);
        if (ch == 'y') {
            task.isImportant = 1;
        } else task.isImportant = 0;
    } while (ch != 'y' && ch != 'n');
    
    task.isInProgress = 1;

    printf("\n\n=============\n");
    printf("Task ID: %d", task.id);
    printf("\nTITLE: %s", task.tTitle);
    printf("\nDESCRIPTION:");
    printf("\n===========\n");
    printf("%s\n", task.tInfo);
    printf("\nIMPORTANT? : %d", task.isImportant);
    printf("\nIN PROGRESS STATE: %d\n", task.isInProgress);
    
    return 0;
}
