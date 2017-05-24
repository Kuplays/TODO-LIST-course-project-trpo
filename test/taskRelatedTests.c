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