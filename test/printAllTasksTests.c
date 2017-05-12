#include "task.h"
#include "ctest.h"

void printAllTasksTest(FILE *file)
{
    file = fopen("tasksTest.dat", "rb");
    
    fclose(file);
}

CTEST(PRINT_ALL_TASKS_TESTS, Opened_File_Not_NULL)
{
	FILE *file;
	printAllTasksTest(file);
	ASSERT_NOT_NULL(file);
}