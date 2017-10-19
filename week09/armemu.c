#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int add(int x, int y);

#define NREGS 16
#define SP 13
#define LR 14 
#define PC 15

struct arm_state {
    unsigned int regs[NREGS];
    unsigned int cpsr;
    unsigned int stack_size;
    unsigned char *stack;
};

struct arm_state *arm_state_new(unsigned int stack_size, unsigned int *func,
                                unsigned int arg0, unsigned int arg1,
                                unsigned int arg2, unsigned int arg3)
{
    struct arm_state *as;
    int i;

    as = (struct arm_state *) malloc(sizeof(struct arm_state));
    if (as == NULL) {
        printf("malloc() failed, exiting.\n");
        exit(-1);
    }

    as->stack = (unsigned char *) malloc(stack_size);
    if (as->stack == NULL) {
        printf("malloc() failed, exiting.\n");
        exit(-1);
    }
    
    as->stack_size = stack_size;

    /* Initialize all registers to zero. */
    for (i = 0; i < NREGS; i++) {
        as->regs[i] = 0;
    }

    as->regs[PC] = (unsigned int) func;

    as->regs[0] = arg0;
    as->regs[1] = arg1;
    as->regs[2] = arg2;
    as->regs[3] = arg3;

    return as;
}

void arm_state_free(struct arm_state *as)
{
    free(as->stack);
    free(as);
}

void arm_state_print(struct arm_state *as)
{
    int i;
    
    printf("stack size = %d\n", as->stack_size);
    for (i = 0; i < NREGS; i++) {
        printf("regs[%d] = (%X) %d\n", i, as->regs[i], (int) as->regs[i]);
    }
}

bool iw_is_add_instruction(unsigned int iw)
{
    unsigned int op;
    unsigned int opcode;

    op = (iw >> 26) & 0b11;
    opcode = (iw >> 21) & 0b1111;

    return (op == 0) && (opcode == 4);
}

void execute_add_instruction(struct arm_state *as, unsigned int iw)
{
    unsigned int rd;
    unsigned int rn;
    unsigned int rm;

    rd = (iw >> 12) & 0b1111;
    rn = (iw >> 16) & 0b1111;
    rm = iw & 0b1111;

    as->regs[rd] = as->regs[rn] + as->regs[rm];

    as->regs[PC] = as->regs[PC] + 4;
}

bool iw_is_bx_instruction(unsigned int iw)
{
    return ((iw >> 4) & 0xFFFFFF) == 0b000100101111111111110001;
}

void execute_bx_instruction(struct arm_state *as, unsigned int iw)
{
    unsigned int rn;

    rn = iw & 0b1111;

    as->regs[PC] = as->regs[rn];
}

void arm_state_execute_one(struct arm_state *as)
{
    unsigned int iw;
    unsigned int *pc;

    pc = (unsigned int *) as->regs[PC];
    iw = *pc;
        
    if (iw_is_add_instruction(iw)) {
        execute_add_instruction(as, iw);
    } else if (iw_is_bx_instruction(iw)) {
        execute_bx_instruction(as, iw);
    }
}

unsigned int arm_state_execute(struct arm_state *as)
{
    while (as->regs[PC] != 0) {
        arm_state_execute_one(as);
    }

    return as->regs[0];
}           
     
int main(int argc, char **argv)
{
    struct arm_state *as;
    unsigned int rv;

    as = arm_state_new(1024, (unsigned int *) add, 1, 2, 0, 0);
    arm_state_print(as);

    rv = arm_state_execute(as);    

    printf("rv = %d\n", rv);

    return 0;
}
