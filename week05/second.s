/* -- first.s */
/* This is a comment */
.global main /* 'main' is our entry point and must be global */
 
main:          /* This is main */  
    add r1, r0, #100
    mov r2, r1
    mov r3, r1
    mov r0, r3
    bx lr      /* Return from main */


