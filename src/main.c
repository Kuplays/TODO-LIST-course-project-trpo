#include <stdio.h>
#include <stdlib.h>
#include "task.h"

int main(int argc, char *argv[])
{
	int choice;
	struct Task task;
	while(1) {
		showMenu();
		printf("\n\nTHE CHOISE IS YOURS: ");
		scanf("%d%*c", &choice);

		switch(choice) {
			case 1:
			gatherInput(&task);
			writeToFile(task);
			break;
			case 2:
			printAllTasks(0, 0);
			break;
			case 3:
			printAllTasks(1, 0);
			break;
			case 4:
			printAllTasks(0, 1);
			break;
			case 5:
			printf("\033c");
			return EXIT_SUCCESS;
			break;
		}
	}
  return 0;
}
