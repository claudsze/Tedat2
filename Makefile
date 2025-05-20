CC=gcc
CFLAGS=-Wall -g -pedantic

.PHONY: clean_object clean_exe clean

all: test_duplicate

test_duplicate: test_duplicate.o duplicate.o
	gcc -o $@ test_duplicate.o duplicate.o

duplicate.o: duplicate.c duplicate.h types.h
	$(CC) $(CFLAGS) -c $< -o $@

test_duplicate.o: test_duplicate.c duplicate.h types.h
	$(CC) $(CFLAGS) -c $< -o $@

clean_object:
	rm -f *.o

clean_exe :
	rm -f test_duplicate

clean: clean_object clean_exe