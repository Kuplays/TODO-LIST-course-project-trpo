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
	FILE* f = fopen("tasksTest.dat", "wb");
	task.id = 1;
	fwrite(&task, sizeof(task), 1, f);
	int result = countID("tasksTest.dat");
	fclose(f);
	ASSERT_EQUAL(1, result);
}

CTEST(COUNT_ID_FUNCTION, returnLastIDByMath)
{
	FILE* f = fopen("tasksTest.dat", "wb");
	task.id = 24 * 2;
	fwrite(&task, sizeof(task), 1, f);
	int result = countID("tasksTest.dat");
	fclose(f);
	ASSERT_EQUAL(48, result);
}

CTEST(COUNT_ID_FUNCTION, returnID_67)
{
	FILE* f = fopen("tasksTest.dat", "wb");
	int id1 = 40, id2 = 20, id3 = id1 + id2 + 7;

	task.id = id1;
	fwrite(&task, sizeof(task), 1, f);
	task.id = id2;
	fwrite(&task, sizeof(task), 1, f);
	task.id = id3;
	fwrite(&task, sizeof(task), 1, f);

	int result = countID("tasksTest.dat");
	fclose(f);
	ASSERT_EQUAL(67, result);
}

CTEST(COUNT_ID_FUNCTION, id_returned99)
{
	FILE* f = fopen("tasksTest.dat", "wb");

	int i;
	for (i = 0; i < 100; i++) {
		task.id = i;
		fwrite(&task, sizeof(task), 1, f);
	}

	fclose(f);
	int result = countID("tasksTest.dat");
	ASSERT_EQUAL(99, result);
}

CTEST(COUNT_ID_FUNCTION, id_returnedMidPoint_200)
{
	FILE* f = fopen("tasksTest.dat", "wb");

	int i;
	for (i = 1; i <= 400; i++) {
		task.id = i;
		fwrite(&task, sizeof(task), 1, f);
	}

	fclose(f);
	int result = countID("tasksTest.dat") / 2;
	ASSERT_EQUAL(200, result);
}

CTEST(COUNT_ID_FUNCTION, id_returned10000)
{
	FILE* f = fopen("tasksTest.dat", "wb");

	int i;
	for (i = 1; i <= 10000; i++) {
		task.id = i;
		fwrite(&task, sizeof(task), 1, f);
	}

	fclose(f);
	int result = countID("tasksTest.dat");
	ASSERT_EQUAL(10000, result);
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

CTEST(GET_SIZE_TESTS, changedSize) {
	FILE *f = fopen("testGetSize.dat", "wb");
	task.id = 100;
	fwrite(&task, sizeof(task), 1, f);
	fclose(f);

	int result1 = getSize("testGetSize.dat"); //1

	f = fopen("testGetSize.dat", "ab");
	task.id = 200;
	fwrite(&task, sizeof(task), 1, f);
	fclose(f);

	int result2 = getSize("testGetSize.dat");
	ASSERT_NOT_EQUAL(result1, result2);
}

CTEST(GET_SIZE_TESTS, changedSize_GetBackToEqual) {
	FILE *f = fopen("testGetSize.dat", "wb");
	task.id = 100;
	fwrite(&task, sizeof(task), 1, f);
	fclose(f);

	int result1 = getSize("testGetSize.dat"); //1

	f = fopen("testGetSize.dat", "ab");
	task.id = 200;
	fwrite(&task, sizeof(task), 1, f);
	fclose(f);

	int result2 = getSize("testGetSize.dat"); //2

	f = fopen("testGetSize.dat", "wb");
	task.id = 999;
	fwrite(&task, sizeof(task), 1, f);
	fclose(f);

	int result3 = getSize("testGetSize.dat"); //1
	ASSERT_EQUAL(result2 - result1, result3);
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

CTEST(GET_SIZE_TESTS, elementsCount_9000_OK) {
	FILE *f = fopen("testGetSize.dat", "wb");
	int count = 0;

	do {
		task.id = count;
		fwrite(&task, sizeof(task), 1, f);
		count ++;
	} while (count < 9000);

	fclose(f);
	int result = getSize("testGetSize.dat");
	ASSERT_EQUAL(9000, result);
}

CTEST(GET_SIZE_TESTS, elementsCount_20000_OK) {
	FILE *f = fopen("testGetSize.dat", "wb");
	int count = 0;

	do {
		task.id = count;
		fwrite(&task, sizeof(task), 1, f);
		count ++;
	} while (count < 20000);

	fclose(f);
	int result = getSize("testGetSize.dat");
	ASSERT_EQUAL(20000, result);
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

CTEST(COMPOSE_INDEX_ARRAY_TESTS, lastIsLesserThanSecond) {
	struct Task tasks[25];
	int indexArr[25];
	int i;

	for (i = 0; i < 25; i++) {
		tasks[i].id = i;
	}

	composeIndexArray(indexArr, 25, tasks);
	int result;
	if (indexArr[24] < indexArr[1]) {
		result = 1;
	} else {
		result = 0;
	}

	ASSERT_EQUAL(1, result);
}

CTEST(COMPOSE_INDEX_ARRAY_TESTS, differentID_Composed_FirstBiggest) {
	struct Task tasks[4];
	int indexArr[4];
	int i;

	tasks[0].id = 25;
	tasks[1].id = 11;
	tasks[2].id = 50;
	tasks[3].id = 51;
	composeIndexArray(indexArr, 4, tasks); 
	int result;

	if(tasks[indexArr[0]].id == 51) {
		result = 1;
	} else {
		result = 0;
	}

	ASSERT_EQUAL(1, result);
}

CTEST(COMPOSE_INDEX_ARRAY_TESTS, differentID_Composed_LastSmallest) {
	struct Task tasks[4];
	int indexArr[4];
	int i;

	tasks[0].id = 25;
	tasks[1].id = 11;
	tasks[2].id = 50;
	tasks[3].id = 51;
	composeIndexArray(indexArr, 4, tasks); 
	int result;

	if(tasks[indexArr[3]].id == 11) {
		result = 1;
	} else {
		result = 0;
	}

	ASSERT_EQUAL(1, result);
}

CTEST(COMPOSE_INDEX_ARRAY_TESTS, differentID_Composed_SecondLessThanFirstAndBiggerThanNext) {
	struct Task tasks[4];
	int indexArr[4];
	int i;

	tasks[0].id = 25;
	tasks[1].id = 11;
	tasks[2].id = 50;
	tasks[3].id = 51;
	composeIndexArray(indexArr, 4, tasks); 
	int result;

	if(tasks[indexArr[1]].id < tasks[indexArr[0]].id && tasks[indexArr[1]].id > tasks[indexArr[2]].id) {
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

CTEST(GET_SIZE_TESTS, fileCreatedButThenDeleted) {
	int result;
	FILE *f = fopen("testGetSize.dat", "wb");
	fclose(f);
	remove("testGetSize.dat");
	result = getSize("testGetSize.dat");
	ASSERT_EQUAL(-1, result);
}
