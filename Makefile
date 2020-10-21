CC = gcc

CFLAGS = -c -Wall

all: hw1

hw1: hw1.o functions.o test.o 
	$(CC) hw1.o functions.o test.o  -lm -o hw1

hw1.o: hw1.c
	$(CC) $(CFLAGS) hw1.c

functions.o: functions.c
	$(CC) $(CFLAGS) functions.c

test.o: test.c
	$(CC) $(CFLAGS) test.c


clean:
	rm -rf *.o hello