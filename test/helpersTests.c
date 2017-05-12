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