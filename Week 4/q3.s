# Recursive maximum of array function (provided solutions)

        # Register usage:
        # - `array' is in $a0 (only before function call)
        # - `length' is in $a1 (only before function call)
        # - `first_element' is in $s0
        # - `max_so_far' is in $t0 (only after function call)

        # $s0 is used for first_element because it needs
        # to keep its value across the recursive call
        .text
max:
max__prologue:
        begin
        push    $ra
        push    $s0                     # Push $s0 to the stack to save its original value

max__body:
        lw      $s0, ($a0)              # Load the value of array[0] into $s0

        bne     $a1, 1, max__length_gt_1        # if (length != 1), go to the recursive case

max__base_case:                         # Base case of recursion
        move    $v0, $s0                # return first_element;
        b       max__epilogue

max__length_gt_1:                       # Recursive case
        addi    $a0, $a0, 4             # Get the address of array[1] by adding 4 to array
                                        # Works because each element is 4 bytes in size
        addi    $a1, $a1, -1            # length = length - 1;
        jal     max                     # Recursive call:
        move    $t0, $v0                # max_so_far = max(&array[1], length - 1);

        ble     $s0, $t0, max__ret_max_so_far   # if (first_element <= max_so_far), goto max__ret_max_so_far
        move    $t0, $s0                        # max_so_far = first_element

max__ret_max_so_far:
        move    $v0, $t0                # return max_so_far;

max__epilogue:
        pop     $s0                     # Pop $s0 from the stack
        pop     $ra                     # Pop $ra from the stack
        end

        jr      $ra                     # return;


        # Some simple test code which calls max
main:
main__prologue:
        push    $ra

main__body:
        la      $a0, array
        li      $a1, 10
        jal     max                     # result = max(array, 10)

        move    $a0, $v0
        li      $v0, 1                  # syscall 1: print_int
        syscall                         # printf("%d", result)

        li      $a0, '\n'
        li      $v0, 11                 # syscall 11: print_char
        syscall                         # printf("%c", '\n');

        li      $v0, 0

main__epilogue:
        pop     $ra
        jr      $ra                     # return 0;


.data
array:
        .word 1, 2, 3, 4, 5, 6, 4, 3, 2, 1
