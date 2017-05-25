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
			printAllTasks();
			break;
			case 4:
			printf("\033c");
			return EXIT_SUCCESS;
			break;
		}
	}
  return 0;
}
