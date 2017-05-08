#include <stdio.h>
#include <stdlib.h>
#include "task.h"

int main(int argc, char *argv[])
{
  int variant;
  FILE *file;
  do {
  	variant = menu ();
  	switch(variant) {
  	case 1: 
		newFile(file, "wb");
		break;
  	case 2:
		printAllTasks(file);
		break;
  	case 3:
		appendTask(file);
		break;
  	case 4:
		return EXIT_SUCCESS;
		break;
    	}
  } while(variant != 4);

  return 0;
}
