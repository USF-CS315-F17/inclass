    .global main
    .func main

main:
    sub sp, sp, #8
    str lr, [sp]
    
    mov r0, #1
    mov r1, #2

    bl add

    ldr lr, [sp]
    add sp, sp, #8
    
    bx lr
    .endfunc

    .func add
add:
    add r0, r0, r1
    bx lr
    .endfunc
    
