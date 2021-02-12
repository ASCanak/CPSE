.cpu cortex-m0
.text
.align 2
.global print_asciz

print_asciz: 
    PUSH { R4, LR }
    MOV R4, R0
loop: 
    LDRB R0, [ R4 ]
    ADD R0, R0, #0
    BEQ done
    BL toggle_case
    BL uart_put_char
    ADD R4, R4, #1
    B loop
done: 
    POP { R4, PC }