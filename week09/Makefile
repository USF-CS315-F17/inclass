PROGS = analyze
OBJS = 

CFLAGS = -g

all : ${PROGS}

analyze : analyze.c add.s
	gcc ${CFLAGS} -o analyze analyze.c add.s

clean:
	rm -rf ${PROGS} ${OBJS}
