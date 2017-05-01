CC = gcc
FLAGS = -I includes
EXEC = bin/testRun.exe
BUILD_DIR = build/src

all: $(BUILD_DIR)/main.o $(BUILD_DIR)/task.o
	mkdir -p bin
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/task.o -o $(EXEC)

$(BUILD_DIR)/main.o: src/main.c
	mkdir -p build
	mkdir -p build/src
	$(CC) $(FLAGS) -c src/main.c -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/task.o: src/task.c
	$(CC) $(FLAGS) -c src/task.c -o $(BUILD_DIR)/task.o

