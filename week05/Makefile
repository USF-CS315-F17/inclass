PROGS = add_main add_test pow_128_main pow_128_test
OBJS = add_main.o add_a.o pow_128_main.o pow_128_a.o

all: ${PROGS}

add_main : add_main.s
	as -o add_main.o add_main.s
	gcc -o add_main add_main.o

add_a.o : add_a.s
	as -o add_a.o add_a.s

add_test : add_test.c add_a.o
	gcc -o add_test add_test.c add_a.o

pow_128_main : pow_128_main.s
	as -o pow_128_main.o pow_128_main.s
	gcc -o pow_128_main pow_128_main.o

pow_128_a : pow_128_a.s
	as -o pow_128_a.o pow_128_a.s

pow_128_test: pow_128_test.c pow_128_a.o
	gcc -g -o pow_128_test pow_128_test.c pow_128_a.o


clean:
	rm -f ${PROGS} ${OBJS}
