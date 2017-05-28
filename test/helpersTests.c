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
	int i;

	for (i = 0; i < 3; i++) {
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
	int i;

	for (i = 0; i < 999; i++) {
		tsk = composeTask(i, "TITLE", "DESCR", 1);
		fwrite(&tsk, sizeof(tsk), 1, f);
	}

	fclose(f);
	struct Task *tasks = getData("getDataTest_999_Elements.dat");

	ASSERT_EQUAL(998, tasks[998].id);
}

CTEST(COMPOSE_INDEX_ARRAY_TESTS, firstBiggerThanLastOK) {
	struct Task tasks[3];
	int indexArr[3];
	tasks[0].id = 0;
	tasks[1].id = 1;
	tasks[2].id = 2;

	composeIndexArray(indexArr, 3, tasks);
	int result;
	if (indexArr[0] > indexArr[2]) {
		result = 1;
	} else {
		result = 0;
	}

	ASSERT_EQUAL(1, result);
}

CTEST(COMPOSE_INDEX_ARRAY_TESTS, middlePointIsLesserThanFirstOK) {
	struct Task tasks[100];
	int indexArr[100];
	int i;

	for (i = 0; i < 100; i++) {
		tasks[i].id = i;
	}

	composeIndexArray(indexArr, 100, tasks);
	int result;
	if (indexArr[50] < indexArr[0]) {
		result = 1;
	} else {
		result = 0;
	}

	ASSERT_EQUAL(1, result);
}

CTEST(COMPOSE_INDEX_ARRAY_TESTS, indexComposingBehaviorOK) {
	struct Task tasks[3];
	int descArr[3];
	descArr[0] = 2;
	descArr[1] = 1;
	descArr[2] = 0;

	int indexArr[3];
	tasks[0].id = 0;
	tasks[1].id = 1;
	tasks[2].id = 2;

	composeIndexArray(indexArr, 3, tasks);

	int i, result;
	for(i = 0; i < 3; i++) {
		if (descArr[i] != indexArr[i]) {
			result = 0;
		} else {
			result = 1;
		}
	}

	ASSERT_EQUAL(1, result);
}

CTEST(GET_SIZE_TESTS, elementsCount_3876_OK) {
	int count, result;	

	FILE *f = fopen("testGetSize.dat", "wb");
	count = 0;

	do {
		task.id = 1;
		fwrite(&task, sizeof(task), 1, f);
		count ++;
	} while (count < 3876);

	fclose(f);
	result = getSize("testGetSize.dat");
	ASSERT_EQUAL(3876, result);
}

