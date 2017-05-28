#include "task.h"
#include "ctest.h"
#include <time.h>
#include <string.h>

CTEST(COMPOSE_TASK_TESTS, ID_PASSED_OK) {
	struct Task testTask;
	testTask = composeTask(999, "TEST TITLE", "TEST DESCR", 1);
	ASSERT_EQUAL(999, testTask.id);
}

CTEST(COMPOSE_TASK_TESTS, TITLE_PASSED_OK) {
	struct Task testTask;
	testTask = composeTask(999, "TEST TITLE", "TEST DESCR", 1);
	ASSERT_STR("TEST TITLE", testTask.tTitle);
}

CTEST(COMPOSE_TASK_TESTS, DESCRIPTION_PASSED_OK) {
	struct Task testTask;
	testTask = composeTask(999, "TEST TITLE", "TEST DESCR", 1);
	ASSERT_STR("TEST DESCR", testTask.tInfo);
}

CTEST(COMPOSE_TASK_TESTS, IMPORTANT_PASSED_OK) {
	struct Task testTask;
	testTask = composeTask(999, "TEST TITLE", "TEST DESCR", 1);
	ASSERT_EQUAL(1, testTask.isImportant);
}

CTEST(COMPOSE_TASK_TESTS, IDs_TEST_01) {
	struct Task testTask;
	testTask = composeTask(1, "TEST TITLE", "TEST DESCR", 1);
	ASSERT_EQUAL(1, testTask.id);
}

CTEST(COMPOSE_TASK_TESTS, IDs_TEST_02) {
	struct Task testTask;
	testTask = composeTask(50, "TEST TITLE", "TEST DESCR", 1);
	ASSERT_EQUAL(50, testTask.id);
}

CTEST(COMPOSE_TASK_TESTS, IDs_TEST_03) {
	struct Task testTask;
	testTask = composeTask(10378, "TEST TITLE", "TEST DESCR", 1);
	ASSERT_EQUAL(10378, testTask.id);
}

CTEST(COMPOSE_TASK_TESTS, IDs_TEST_04) {
	struct Task testTask;
	testTask = composeTask(-100, "TEST TITLE", "TEST DESCR", 1);
	ASSERT_EQUAL(-100, testTask.id);
}

CTEST(COMPOSE_TASK_TESTS, IDs_TEST_05_RANGE) {
	struct Task testTask;
	struct Task tasks[100];
	int i;

	for (i = 0; i < 100; i++) {
		testTask = composeTask(i, "TEST TITLE", "TEST DESCR", 1);
		tasks[i] = testTask;
	}
	
	ASSERT_INTERVAL(0, 99, tasks[50].id);
}

CTEST(COMPOSE_TASK_TESTS, TITLE_TEST_01) {
	struct Task testTask;
	testTask = composeTask(1, "small cased title", "TEST DESCR", 1);
	ASSERT_STR("small cased title", testTask.tTitle);
}

CTEST(COMPOSE_TASK_TESTS, TITLE_TEST_02) {
	struct Task testTask;
	testTask = composeTask(1, "РУССКИЕ БУКВЫ", "TEST DESCR", 1);
	ASSERT_STR("РУССКИЕ БУКВЫ", testTask.tTitle);
}

CTEST(COMPOSE_TASK_TESTS, TITLE_TEST_03) {
	struct Task testTask;
	testTask = composeTask(1, "!@#$^&*()", "TEST DESCR", 1);
	ASSERT_STR("!@#$^&*()", testTask.tTitle);
}