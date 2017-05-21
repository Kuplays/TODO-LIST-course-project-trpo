CC = gcc
FLAGS = -I includes
EXEC = bin/testRun.exe
TEST_EXEC = bin/TODO-test.exe
BUILD_DIR = build/src
BUILD_DIR_TEST = build/test

all: $(BUILD_DIR)/main.o $(BUILD_DIR)/task.o
	mkdir -p bin
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/task.o -o $(EXEC)

$(BUILD_DIR)/main.o: src/main.c
	mkdir -p build
	mkdir -p build/src
	$(CC) $(FLAGS) -c src/main.c -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/task.o: src/task.c
	$(CC) $(FLAGS) -c src/task.c -o $(BUILD_DIR)/task.o

all: todo-test

todo-test: $(BUILD_DIR_TEST)/main.o $(BUILD_DIR_TEST)/taskRelatedTests.o $(BUILD_DIR_TEST)/printAllTasksTests.o $(BUILD_DIR)/task.o $(BUILD_DIR_TEST)/helpersTests.o
	mkdir -p bin
	$(CC) $(BUILD_DIR_TEST)/main.o $(BUILD_DIR_TEST)/taskRelatedTests.o $(BUILD_DIR_TEST)/printAllTasksTests.o $(BUILD_DIR)/task.o $(BUILD_DIR_TEST)/helpersTests.o -o $(TEST_EXEC)

$(BUILD_DIR_TEST)/main.o: test/main.c
	mkdir -p build/test
	$(CC) $(FLAGS) -c test/main.c -o $(BUILD_DIR_TEST)/main.o

$(BUILD_DIR_TEST)/taskRelatedTests.o: test/taskRelatedTests.c
	$(CC) $(FLAGS) -c test/taskRelatedTests.c -o $(BUILD_DIR_TEST)/taskRelatedTests.o

$(BUILD_DIR_TEST)/printAllTasksTests.o: test/printAllTasksTests.c
	$(CC) $(FLAGS) -c test/printAllTasksTests.c -o $(BUILD_DIR_TEST)/printAllTasksTests.o

$(BUILD_DIR_TEST)/helpersTests.o: test/helpersTests.c
	$(CC) $(FLAGS) -c test/helpersTests.c -o $(BUILD_DIR_TEST)/helpersTests.o

