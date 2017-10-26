.global add
.func add
 
add:
    add r0, r0, r1
    b done
    add r0, r0, r0
done:
    add r0, r0, #99
    bx lr
