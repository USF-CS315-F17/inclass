PROGS = count_zeros_first count_zeros_static_in_asm \
        count_zeros_stack_index_in_asm count_zeros_all 6_20

OBJS = count_zeros_static_in_asm.o count_zeros_stack_index_in_asm.o \
       count_zeros_a.o array_times_s_a.o

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

array_times_s_a.o : array_times_s_a.s
	as -o array_times_s_a.o array_times_s_a.s

6_20 : 6_20.c array_times_s_a.o
	gcc -o 6_20 6_20.c array_times_s_a.o

clean:
	rm -rf ${PROGS} ${OBJS}
