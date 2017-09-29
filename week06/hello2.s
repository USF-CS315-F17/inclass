    /* hello.s */
    .data
greeting:
    .asciz "Hello, World! %d\n"

    .text
    .global main
    .func main

main:
    sub sp, sp, #16
    str lr, [sp]
    str r0, [sp, #4]
    str r1, [sp, #8]

    ldr r0, =greeting
    bl strlength

    mov r1, r0
    ldr r0, =greeting

    bl printf

    ldr lr, [sp]
    add sp, sp, #8
    bx lr

    .endfunc

strlength:
    mov r1, #0
loop:
    ldrb r2, [r0]
    cmp r2, #0
    beq done
    add r1, r1, #1
    add r0, r0, #1
    b loop
done:
    mov r0, r1
    bx lr
    
