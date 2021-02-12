.cpu cortex-m0
.text
.align 2
.global application

application:
    LDR R0, =tekst
    BL print_asciz

.data

tekst:
    .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"