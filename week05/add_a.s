/* add_a.s - standalone assembly code to add two numbers */

.global add_a

add_a:
    add r0, r0, r1
    bx lr
