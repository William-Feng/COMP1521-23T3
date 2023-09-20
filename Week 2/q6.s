        .text
main:
        # Registers:
        # $t0 = x
        
        li      $t0, 0                          # int x = 0;
        
        la      $a0, string_prompt              # printf("Enter a number: ");
        li      $v0, 4
        syscall
        
        li      $v0, 5                          # scanf("%d", &x);
        syscall
        move    $t0, $v0                        # x = $v0 (don't leave the scanned value in $v0)

        ble     $t0, 100, print_small_big       # if (x <= 100) goto print_small_big;
        bge     $t0, 1000, print_small_big      # if (x >= 1000) goto print_small_big;

print_medium:
        la      $a0, medium_output              # printf("medium\n");
        li      $v0, 4
        syscall
        
        j       epilogue                        # goto epilogue;
        
print_small_big:
        la      $a0, small_big_output           # # printf("small/big\n")
        li      $v0, 4
        syscall

epilogue:
        li      $v0, 0                          # return 0;
        jr      $ra


        .data
string_prompt:
        .asciiz "Enter a number: "
small_big_output:
        .asciiz "small/big\n"
medium_output:
        .asciiz "medium\n"
