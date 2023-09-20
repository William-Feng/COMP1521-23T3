        .text
main:
        # Registers:
        # $t0 = n
        # $t1 = factorial
        # $t2 = i

        la      $a0, initial_str                # printf("n  = ");
        li      $v0, 4
        syscall

        li      $v0, 5                          # scanf("%d", &n);
        syscall
        move    $t0, $v0                        # Move scanned value from $v0 to $t0

factorial_init:
        li      $t1, 1                          # int factorial = 1;
        li      $t2, 1                          # int i = 1;

factorial_cond:
        bgt     $t2, $t0, factorial_end         # if (i > n) goto factorial_end;

factorial_body:
        mul     $t1, $t1, $t2                   # factorial = factorial * i;

factorial_step:
        addi    $t2, $t2, 1                     # i = i + 1;
        j       factorial_cond                  # goto factorial_cond;

factorial_end:
        la      $a0, output_str                 # printf("n! = "); 
        li      $v0, 4
        syscall

        move    $a0, $t1                        # printf("%d", factorial);
        li      $v0, 1
        syscall

        li      $a0, '\n'                       # printf("%c", '\n');
        li      $v0, 11
        syscall

        li      $v0, 0                          # return 0;
        jr      $ra


        .data
initial_str:
        .asciiz         "n  = "
output_str:
        .asciiz         "n! = "
