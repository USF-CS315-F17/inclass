PROGS = analyze armemu
OBJS = 

CFLAGS = -g

all : ${PROGS}

analyze : analyze.c addsub.s
	gcc ${CFLAGS} -o analyze analyze.c addsub.s

armemu : armemu.c add.s
	gcc ${CFLAGS} -o armemu armemu.c add.s

clean:
	rm -rf ${PROGS} ${OBJS}
