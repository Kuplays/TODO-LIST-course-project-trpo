#include <stdio.h>
#include <stdlib.h>
#include "task.h"

int main(int argc, char *argv[])
{
  int variant;
  FILE *file;
  while(1) {
  	variant = menu ();
  	switch(variant) {
  	case 1: 
  		if (file_exist("tasks.dat"))
  		{
  			printf("EXIST!");
  			newFile(file, "ab", countID(file));
  		} else {
  			printf("NEW FILE MODE!");
  			newFile(file, "wb", 0);
  		}
		break;
  	case 2:
		printAllTasks(file);
		break;
  	case 3:
		//appendTask(file);
		break;
  	case 4:
		return EXIT_SUCCESS;
		break;
    	}
  }

  return 0;
}
