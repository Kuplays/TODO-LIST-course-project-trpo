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
			case 4:
			printf("\033c");
			return EXIT_SUCCESS;
			break;
		}
	}
	/*struct Task task;
	gatherInput(&task);
	writeToFile(task);
	printAllTasks();
*/
	//gatherInput(&tsk);
	//writeToFile(tsk);
	/*int size = getSize("tasks.dat"); //1
	struct Task tasks[size];

	readFromFile(tasks, "tasks.dat");

	for (int i = 0; i < size; i++)
	{
		printf("ID: %d\nTITLE: %s\nDESCR: %s", tasks[i].id, tasks[i].tTitle, tasks[i].tInfo);
		printf("\n======\n");
	}*/
  /*int variant;
  FILE *file;
  while(1) {
  	variant = menu ();
  	switch(variant) {
  	case 1: 
  		if (file_exist("tasks.dat"))
  		{
  			printf("EXIST!");
  			newEntry(file, "ab", countID(file, "tasks.dat"));
  		} else {
  			printf("NEW FILE MODE!");
  			newEntry(file, "wb", 0);
  		}
		break;
  	case 2:
		printAllTasks(file);
		break;
        case 3:
		printImportantTasks(file);
		break;
  	case 4:
		return EXIT_SUCCESS;
		break;
    	}
  }*/

  return 0;
}
