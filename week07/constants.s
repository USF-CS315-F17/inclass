    /* hello.s */
    .data
greeting:
    .asciz "Hello, World! %X\n"

    .text
    .global main
    .func main

main:
    sub sp, sp, #16
    str lr, [sp]
    str r0, [sp, #4]
    str r1, [sp, #8]

    ldr r1, =0xFFAA3311
    ldr r0, =greeting

    bl printf

    ldr lr, [sp]
    add sp, sp, #8
    bx lr

    .endfunc
