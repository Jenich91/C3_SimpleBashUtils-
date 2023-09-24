.PHONY: all clean check test sfleta_cat sfleta_grep

default: all

all: sfleta_cat sfleta_grep

sfleta_cat:
	make use_lib -C cat/

sfleta_grep:
	make use_lib -C grep/

clean:
	make clean -C cat/
	make clean -C grep/

test:
	make test -C cat/
	make test -C grep/

check:
	make check -C cat/
	make check -C grep/
