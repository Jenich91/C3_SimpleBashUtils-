.PHONY: all clean check test sfleta_grep
CC=gcc -std=c11
LDFLAGS= -Wall -Wextra -Werror
OS := $(shell uname -s)

default: all

all: sfleta_grep

libname=sfleta_grep
static_lib:
	gcc -c -g $(libname).c
	ar -rcs $(libname).a *.o
	ar -rcs lib$(libname).a *.o

use_lib: static_lib
	$(CC) main.c -L. -l$(libname) -o $(libname)

sfleta_grep: clean
ifeq ($(OS), Darwin)
	$(CC) $(LDFLAGS) *.c -o sfleta_grep	
else
	$(CC) -D_GNU_Source $(LDFLAGS) *.c -o sfleta_grep
endif

clean:
	rm -rf *.txt
	rm -rf *_out
	rm -rf *.dSYM
	rm -rf *.cfg
	rm -rf *.o
	rm -rf *.out
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.cov
	rm -rf *.info
	rm -rf report
	# rm -rf *.a
	# rm -rf $(libname)

test:
	sh test_grep.sh

debug:
	$(CC) -D_GNU_Source -g -Og -o sfleta_grep sfleta_grep.c 

check: debug
	cppcheck *.h *.c
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extension=c *.c *.h
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./sfleta_grep
else
	valgrind -q --tool=memcheck --leak-check=full --leak-resolution=med ./sfleta_grep
endif