/* pow_128_main.s */
.global main
.func main

main:
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
