.section .text
.globl _start

_start:
    li sp, 0x8003fffc
    
    # Initialize loop counter (10000 iterations)
    li t0, 10000
    
loop_start:
    # Perform some arithmetic operations
    li t1, 0
    
    # Inner loop - do some work
    addi t1, t1, 1
    addi t1, t1, 2
    xor t1, t1, t0
    and t1, t1, t0
    or t1, t1, t0
    sll t1, t1, 1
    srl t1, t1, 1
    
    # Decrement outer loop
    addi t0, t0, -1
    bnez t0, loop_start
    
    # Store result at output location
    lui a0, 0
    addi a0, a0, 100
    sw t1, 0(a0)
    
    # Done - infinite loop
inf_loop:
    j inf_loop
