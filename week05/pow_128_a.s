/* pow_128_a.s */
.global pow_128_a
.func pow_128_a

pow_128_a:
    mov r0, #1 /* r0 : pow */
    mov r1, #0 /* r1 : x */
while:
    cmp r0, #128
    beq done
    lsl r0, r0, #1
    add r1, r1, #1
    b while
done:
    bx lr
