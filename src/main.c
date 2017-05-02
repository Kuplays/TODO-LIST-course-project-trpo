#include <stdio.h>
#include <stdlib.h>
#include "task.h"

int main(int argc, char *argv[])
{
  FILE *file;
  int variant = menu ();
  switch(variant) {
  case 1: 
	newFile(file);
	break;
  case 2:
	printAllTasks(file);
	break;
  case 3:
	break;
    }
  return 0;
}
