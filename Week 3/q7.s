N_SIZE = 10
        
        .text
main:
        # Registers:
        # $t0 = i
        # $t1 = &numbers[0] = Base Address
        # $t2 = i * 4 = Offset
        # $t3 = &numbers[i] = Address of element
        # $t4 = numbers[i] = Value of element
        
        li      $t0, 0                  # int i = 0;

loop_condition:
        bge     $t0, N_SIZE, epilogue   # if (i >= N_SIZE) goto epilogue;

loop_body:
        # We want to calculate the address of the element we're interested about
        # Base Address + i * Element_Size
        
        la      $t1, numbers            # $t1 = &numbers[0]
        mul     $t2, $t0, 4             # $t2 = i * 4
        add     $t3, $t1, $t2           # $t3 = &numbers[i]
        lw      $t4, ($t3)              # $t4 = numbers[i]
        
        bge     $t4, 0, non_negative    # if (numbers[i] >= 0) goto non_negative;
        
        addi    $t4, $t4, 42            # numbers[i] = numbers[i] + 42;
        
        # Make sure to store the updated array element so that it's saved in memory
        sw      $t4, ($t3)
        
non_negative:
        move    $a0, $t4                # printf("%d", numbers[i]);
        li      $v0, 1
        syscall
        
        li      $a0, '\n'               # printf("%c", '\n');
        li      $v0, 11
        syscall

loop_step:
        addi    $t0, $t0, 1             # i = i + 1;
        j       loop_condition          # goto loop_condition;

epilogue:
        li      $v0, 0                  # return 0;
        jr      $ra
        
        .data
numbers:
        .word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9
