#include "task.h"
#include "ctest.h"
#include <time.h>
#include <string.h>

int newFileTest(FILE *file)
{
    char ch = 'n';
    file = fopen("tasks.dat", "wb");
    int idCount = 0;
    task.id = ++idCount;
    strcpy(task.tTitle, "Test Title");
    strcpy(task.tInfo, "Test Description");
    task.isImportant = 1;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(task.tAcceptedDate, "%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    task.isInProgress = 1;
        
   	fwrite(&task, sizeof(task), 1, file);
    fclose(file);
}

CTEST(NEW_FILE_TESTS, fileNotNULL) {
	FILE *f;
	newFileTest(f);
	ASSERT_NOT_NULL(f);
}

CTEST(NEW_FILE_TESTS, idCountIncrementOnFirst) {
	FILE *f;
	newFileTest(f);
	ASSERT_EQUAL(1, task.id);
}

CTEST(NEW_FILE_TESTS, validTitle) {
	FILE *f;
	newFileTest(f);
	ASSERT_STR("Test Title", task.tTitle);
}

CTEST(NEW_FILE_TESTS, validDescription) {
	FILE *f;
	newFileTest(f);
	ASSERT_STR("Test Description", task.tInfo);
}

CTEST(NEW_FILE_TESTS, isImportantStateCorrect) {
	FILE *f;
	newFileTest(f);
	ASSERT_EQUAL(1, task.isImportant);
}

CTEST(NEW_FILE_TESTS, isInProgressStateOne) {
	FILE *f;
	newFileTest(f);
	ASSERT_EQUAL(1, task.isInProgress);
}
