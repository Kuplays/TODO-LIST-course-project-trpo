#include <stdio.h>
#include <stdlib.h>
#include "task.h"

int main(int argc, char *argv[])
{
  FILE *file;
  newFile(file);
  printAllTasks(file);
  return 0;
}
