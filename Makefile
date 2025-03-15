CC = gcc
CFLAGS = -Wall -Wextra

all: Dylan_testFS

Dylan_libFS.o: Dylan_libFS.c Dylan_libFS.h
	$(CC) $(CFLAGS) -c Dylan_libFS.c -o Dylan_libFS.o

Dylan_testFS: Dylan_testFS.c Dylan_libFS.o
	$(CC) $(CFLAGS) Dylan_testFS.c Dylan_libFS.o -o Dylan_testFS

clean:
	rm -f Dylan_testFS Dylan_libFS.o

