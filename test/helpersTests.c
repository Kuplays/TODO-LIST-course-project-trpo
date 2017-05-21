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
	int result = countID("tasksTest.dat");
	ASSERT_EQUAL(1, result);
}

CTEST(READ_FROM_FILE_TESTS, fileReadIntoArrayOK) {
	struct Task t[10];
	int result = readFromFile(t, "tasks.dat");
	ASSERT_EQUAL(0, result);
}

CTEST(READ_FROM_FILE_TESTS, fileNotPresentOK) {
	struct Task t[10];
	int result = readFromFile(t, "dummyFile.dat");
	ASSERT_EQUAL(-1, result);
}

CTEST(GET_SIZE_TESTS, fileNotPresentOK) {
	int result = getSize("dummyFile.dat");
	ASSERT_EQUAL(-1, result);
}

CTEST(GET_SIZE_TESTS, elementsCount_2_OK) {
	FILE *f = fopen("testGetSize.dat", "wb");
	task.id = 100;
	fwrite(&task, sizeof(task), 1, f);
	task.id = 200;
	fwrite(&task, sizeof(task), 1, f);
	fclose(f);
	int result = getSize("testGetSize.dat");
	ASSERT_EQUAL(2, result);
}

CTEST(GET_SIZE_TESTS, elementsCount_10_OK) {
	FILE *f = fopen("testGetSize.dat", "wb");
	int count = 0;

	do {
		task.id = 1;
		fwrite(&task, sizeof(task), 1, f);
		count ++;
	} while (count < 10);

	fclose(f);
	int result = getSize("testGetSize.dat");
	ASSERT_EQUAL(10, result);
}