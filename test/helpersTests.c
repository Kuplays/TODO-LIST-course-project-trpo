#include "task.h"
#include "ctest.h"

CTEST(FILE_EXIST_FUNCTION, fileExistsOK)
{
	int result = file_exist("tasksTest.dat");
	ASSERT_EQUAL(1, result);
}

CTEST(FILE_EXIST_FUNCTION, fileExistsFAIL)
{
	int result = file_exist("no_such_file.dat");
	ASSERT_EQUAL(0, result);
}

CTEST(COUNT_ID_FUNCTION, tests_dat_return_1_OK)
{
	FILE *file;
	int result = countID(file, "tasksTest.dat");
	ASSERT_EQUAL(1, result);
}