        .text
main:
        # Registers:
        # x = $t0
        # y = $t1
        
        li      $t0, 0                  # int x = 0;
        li      $t1, 0                  # int y = 0;
        
        la      $a0, string_prompt      # printf("Enter a number: ");
        li      $v0, 4
        syscall
        
        li      $v0, 5                  # scanf("%d", &x);
        syscall
        move    $t0, $v0                # x = $v0 (don't leave the scanned value in $v0)
        
        mul     $t1, $t0, $t0           # y = x * x
        
        move    $a0, $t1                # printf("%d", y)
        li      $v0, 1
        syscall
        
        li      $a0, '\n'               # printf("%c", '\n');
        li      $v0, 11
        syscall
        
        li      $v0, 0                  # return 0;
        jr      $ra

        .data
string_prompt:
        .asciiz "Enter a number: "
