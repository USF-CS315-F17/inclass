PROGS = count_zeros_first count_zeros_static_in_asm \
        count_zeros_stack_index_in_asm count_zeros_all

OBJS = count_zeros_static_in_asm.o count_zeros_stack_index_in_asm.o \
       count_zeros_a.o

CFLAGS = -g

all : ${PROGS}

count_zeros_first : count_zeros_first.c
	gcc -o count_zeros_first count_zeros_first.c

count_zeros_static_in_asm : count_zeros_static_in_asm.s
	as -o count_zeros_static_in_asm.o count_zeros_static_in_asm.s
	gcc -o count_zeros_static_in_asm count_zeros_static_in_asm.o

count_zeros_stack_index_in_asm : count_zeros_stack_index_in_asm.s
	as -o count_zeros_stack_index_in_asm.o count_zeros_stack_index_in_asm.s
	gcc -o count_zeros_stack_index_in_asm count_zeros_stack_index_in_asm.o

count_zeros_a.o : count_zeros_a.s
	as -o count_zeros_a.o count_zeros_a.s

count_zeros_all : count_zeros_all.c count_zeros_a.o
	gcc -o count_zeros_all count_zeros_all.c count_zeros_a.o

clean:
	rm -rf ${PROGS} ${OBJS}
