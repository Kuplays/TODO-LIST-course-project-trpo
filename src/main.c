#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *file;
  newFile(file);
  printAllTasks(file);
  system("PAUSE");	
  return 0;
}
