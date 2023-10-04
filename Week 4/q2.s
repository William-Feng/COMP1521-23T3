FLAG_ROWS = 6
FLAG_COLS = 12

        .text
main:
        # Registers:
        # $t0 = row
        # $t1 = col
        # $t2 = &flag[0][0] = Base Address
        # $t3 = &flag[row][col] = Final Address
        # $t4 = flag[row][col] = Value
        
row_loop_init:
        li      $t0, 0                  # int row = 0;
        
row_loop_cond:
        bge     $t0, FLAG_ROWS, row_loop_end            # if (row >= FLAG_ROWS) goto row_loop_end;

col_loop_init:
        li      $t1, 0                  # int col = 0;
        
col_loop_cond:
        bge     $t1, FLAG_COLS, col_loop_end            # if (col >= FLAG_COLS) goto col_loop_end;
        
col_loop_body:
        # Final Address = Base Address + Offset
        # Offset = (Row * Number_of_columns + Column) * Element_size
        
        la      $t2, flag               # $t2 = &flag[0][0]
        
        mul     $t3, $t0, FLAG_COLS     # $t3 = row * FLAG_COLS
        add     $t3, $t3, $t1           # $t3 += col
        # mul     $t3, $t3, 1             # $t3 *= 1
        add     $t3, $t3, $t2           # $t3 = &flag[row][col]
        
        lb      $t4, ($t3)              # $t4 = flag[row][col]
        
        move    $a0, $t4                # printf("%c", flag[row][col]);
        li      $v0, 11
        syscall

        addi    $t1, $t1, 1             # col = col + 1;
        j       col_loop_cond           # goto col_loop_cond;

col_loop_end:
        li      $a0, '\n'               # printf("%c", \n);
        li      $v0, 11
        syscall

        addi    $t0, $t0, 1             # row = row + 1;
        j       row_loop_cond           # goto row_loop_cond;

row_loop_end:
        li      $v0, 0                  # return 0;
        jr      $ra


        .data
flag:
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
