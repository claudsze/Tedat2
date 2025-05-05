CC=gcc
CFLAGS=-Wall -g -pedantic

.PHONY: clean_object clean_exe clean

all: test_prune

test_prune: test_prune.o bt.o
	gcc -o $@ test_prune.o bt.o

bt.o: bt.c bt.h types.h
	$(CC) $(CFLAGS) -c $< -o $@

test_prune.o: test_prune.c bt.h types.h
	$(CC) $(CFLAGS) -c $< -o $@

clean_object:
	rm -f *.o

clean_exe :
	rm -f test_prune

clean: clean_object clean_exe