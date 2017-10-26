.global addsub
.func addsub
 
addsub:
    add r0, r0, r1
    sub r0, r0, #1
    bx lr
