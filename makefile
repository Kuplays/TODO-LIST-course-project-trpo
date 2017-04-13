CC = gcc
FLAGS = -I includes -Wall -Werror

EXEC = testRun.exe

all: main.o
	$(CC) main.o -o $(EXEC)

main.o: src/main.c
	$(CC) $(FLAGS) -c src/main.c -o main.o

.c.o:
	$(CC) $(FLAGS) $< -o $@

