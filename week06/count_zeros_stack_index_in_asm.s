.global main
.func main

main:
    sub sp, sp, #20
    mov r2, #1
    str r2, [sp]
    mov r2, #0
    str r2, [sp, #4]
    mov r2, #2
    str r2, [sp, #8]
    mov r2, #0
    str r2, [sp, #12]
    mov r2, #3
    str r2, [sp, #16]
    
    mov r0, sp
    mov r1, #5
    mov r2, #0
    mov r3, #0

loop:
    cmp r2, r1
    beq done
    /* lsl r5, r2, #2 */ /* i * 4 */
    /* add r5, r0, r5 */ /* array + (i * 4) */
    ldr r4, [r0, r2, LSL #2]
    cmp r4, #0
    addeq r3, r3, #1
    add r2, r2, #1
    b loop

done:
    mov r0, r3
    bx lr
   
