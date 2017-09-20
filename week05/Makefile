PROGS = add_main add_test
OBJS = add_main.o add_a.o

all: ${PROGS}

add_main : add_main.s
	as -o add_main.o add_main.s
	gcc -o add_main add_main.o

add_a.o : add_a.s
	as -o add_a.o add_a.s

add_test : add_test.c add_a.o
	gcc -o add_test add_test.c add_a.o

clean:
	rm ${PROGS} ${OBJS}
