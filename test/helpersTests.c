#include "task.h"
#include "ctest.h"

CTEST(FILE_EXIST_FUNCTION, fileExistsOK)
{
	FILE* f = fopen("tasksTest.dat", "wb");
	int result = file_exist("tasksTest.dat");
	fclose(f);
	ASSERT_EQUAL(1, result);
}

CTEST(FILE_EXIST_FUNCTION, fileExistsFAIL)
{
	int result = file_exist("no_such_file.dat");
	ASSERT_EQUAL(0, result);
}

CTEST(COUNT_ID_FUNCTION, tests_dat_return_1_OK)
{
	FILE* f = fopen("tastsTest.dat", "wb");
	task.id = 1;
	fwrite(&task, sizeof(task), 1, f);
	int result = countID("tasksTest.dat");
	fclose(f);
	ASSERT_EQUAL(1, result);
}

CTEST(READ_FROM_FILE_TESTS, fileReadIntoArrayOK) {
	struct Task t[10];
	FILE *f = fopen("TEST.dat", "w");
	int result = readFromFile(t, "TEST.dat");
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

CTEST(GET_SIZE_TESTS, elementsCount_0_OK) {
	FILE *f = fopen("testGetSize.dat", "wb");
	fclose(f);
	int result = getSize("testGetSize.dat");
	ASSERT_EQUAL(0, result);
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

CTEST(GETDATA_TESTS, EmptyArrayOK) {
	FILE *f = fopen("getDataTest_Empty.dat", "wb");
	struct Task *tasks = getData("getDataTest_Empty.dat");
	ASSERT_EQUAL(-1, tasks[0].id);
}

CTEST(GETDATA_TESTS, threeElementsOK) {
	FILE *f = fopen("getDataTest_Three_Elements.dat", "wb");
	struct Task tsk;

	for (int i = 0; i < 3; i++) {
		tsk = composeTask(i, "TITLE", "DESCR", 1);
		fwrite(&tsk, sizeof(tsk), 1, f);
	}

	fclose(f);
	struct Task *tasks = getData("getDataTest_Three_Elements.dat");

	ASSERT_EQUAL(2, tasks[2].id);
}

CTEST(GETDATA_TESTS, 999_Elements_OK) {
	FILE *f = fopen("getDataTest_999_Elements.dat", "wb");
	struct Task tsk;

	for (int i = 0; i < 999; i++) {
		tsk = composeTask(i, "TITLE", "DESCR", 1);
		fwrite(&tsk, sizeof(tsk), 1, f);
	}

	fclose(f);
	struct Task *tasks = getData("getDataTest_999_Elements.dat");

	ASSERT_EQUAL(998, tasks[998].id);
}