PROGS = constants driver
OBJS = 

CFLAGS = -g

all : ${PROGS}

constants : constants.s
	gcc ${CFLAGS} -o constants constants.s

driver: driver.c sum_array_c.c fact_rec_c.c fact_rec_a.s
	gcc ${CFLAGS} -o driver driver.c sum_array_c.c fact_rec_c.c fact_rec_a.s

clean:
	rm -rf ${PROGS} ${OBJS}
