    .global rec_sum_a
    .func rec_sum_a

rec_sum_a:
    sub sp, sp, #8
    str lr, [sp, #4]
    cmp r1, #0
    bne else
    mov r0, #0
    b done
else:   
    ldr r3, [r0]
    str r3, [sp]
    add r0, r0, #4
    sub r1, r1, #1
    bl rec_sum_a
    ldr r1, [sp]
    add r0, r0, r1
done:
    ldr lr, [sp, #4]
    add sp, sp, #8
    bx lr

    .endfunc
