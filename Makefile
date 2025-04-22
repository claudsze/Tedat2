CC=gcc
CFLAGS=-Wall -g -pedantic

.PHONY: clean_object clean_exe clean

all: test_pop_min

test_pop_min: test_pop_min.o list.o
	gcc -o $@ test_pop_min.o list.o

list.o: list.c list.h types.h
	$(CC) $(CFLAGS) -c $< -o $@

test_pop_min.o: test_pop_min.c list.h types.h
	$(CC) $(CFLAGS) -c $< -o $@

clean_object:
	rm -f *.o

clean_exe :
	rm -f test_pop_min

clean: clean_object clean_exe