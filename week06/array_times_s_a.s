.global array_times_s_a
.func array_times_s_a

/* void array_times_s(int *array, int len, int s) */
/* int *array : r0 */
/* int len : r1 */
/* int s : r2 */

/* int i : r3 */
/* int tmp : 4 */
    
array_times_s_a:
    mov r3, #0

loop:
    cmp r3, r1
    beq done
    ldr r4, [r0, r3, lsl #2]
    mul r4, r2, r4
    str r4, [r0, r3, lsl #2]
    add r3, r3, #1
    b loop

done:
    bx lr
    
