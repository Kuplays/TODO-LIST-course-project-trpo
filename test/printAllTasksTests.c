#include "task.h"
#include "ctest.h"

void printAllTasksTest(FILE *file)
{
    file = fopen("tasks.dat", "rb");
    fread(&task, sizeof(task), 1, file);
    
    
    
    fclose(file);
}

CTEST(PRINT_TASKS_TESTS, NULL_POINTER_OK)
{
	FILE *file;
	printAllTasksTest(file);
	ASSERT_NOT_NULL(file);
}