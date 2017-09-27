.data

.balign 4
array_static:
    .word 1
    .word 0
    .word 2
    .word 0
    .word 3

.text

.global main
.func main

main:
    ldr r0, =array_static
    mov r1, #5
    mov r2, #0
    mov r3, #0

loop:
    cmp r2, r1
    beq done
    ldr r4, [r0]
    cmp r4, #0
    addeq r3, r3, #1
    add r0, r0, #4
    add r2, r2, #1
    b loop

done:
    mov r0, r3
    bx lr
   
