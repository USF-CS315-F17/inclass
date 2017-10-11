PROGS = rec_sum_test signed.s
OBJS = 

CFLAGS = -g

all : ${PROGS}

rec_sum_test: rec_sum_test.c rec_sum.c rec_sum.s
	gcc ${CFLAGS} -o rec_sum_test rec_sum_test.c rec_sum.c rec_sum.s

signed.s : signed.c
	gcc -S -o signed.s signed.c

negvalues : negvalues.s
	as -o negvalues.o negvalues.s
	objdump -S negvalues.o

clean:
	rm -rf ${PROGS} ${OBJS}
