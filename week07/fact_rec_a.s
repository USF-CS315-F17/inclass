    .global fact_rec_a
    .func fact_rec_a

fact_rec_a:
    sub sp, sp, #8
    str lr, [sp, #4]
    str r0, [sp]

    cmp r0, #0
    bne fact_else
    mov r0, #1
    b fact_ret

fact_else:
    sub r0, r0, #1
    bl fact_rec_a
    ldr r1, [sp]
    mul r0, r1, r0

fact_ret:
    ldr lr, [sp, #4]
    add sp, sp, #8
    bx lr
    
