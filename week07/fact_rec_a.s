    .global fact_rec_a
    .func fact_rec_a

fact_rec_a:
    push {r4, lr}

    cmp r0, #0
    bne fact_else
    mov r0, #1
    b fact_ret

fact_else:
    mov r4, r0
    sub r0, r0, #1
    bl fact_rec_a
    mul r0, r4, r0

fact_ret:
    pop {r4, lr}
    bx lr
    
