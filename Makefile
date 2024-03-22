UNAME:=$(shell uname -s)
ifeq ($(UNAME),Linux)
	LFLAGS=-lcheck -lsubunit -lrt -lm -lpthread
endif
ifeq ($(UNAME),Darwin)
	LFLAGS=-lcheck -lm
endif


lib.o: quadratic_equation.c
	gcc -c -std=c11 quadratic_equation.c

main: lib.o
	gcc -c -std=c11 main.c
	gcc -std=c11 quadratic_equation.o main.o -o result
	./result

check: lib.o
	gcc -c -std=c11 tests.c
	gcc -std=c11 quadratic_equation.o tests.o -L. $(LFLAGS) -o tests
	./tests

clean:
	rm -rf *.o result tests