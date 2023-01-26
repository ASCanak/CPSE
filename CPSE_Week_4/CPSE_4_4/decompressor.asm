.cpu cortex-m0
.bss
	buffer: .zero 80			
.text
.align 2
.global decompress

// Main loop of decompress, walks through asciz, and jumps based on found @ (3) or not (1)
decompress:
	push {r4, lr}
	ldr r4, =compressed 		
decompress_loop:
	ldrb r0, [r4]				
	add r0, r0, #0				
	beq decompress_done		    
	mov r0, r4					
	bl checker					
	add r4, r4, r0				
	b decompress_loop			
decompress_done:
	pop {r4, pc}

// Function checks if char in mem add is @. Based on that puts char in buffer and cout
checker:
	push {r4, r5, r6, lr}
	mov r4, r0 					
	ldrb r0, [r4]				
	cmp r0, #64					
	beq check_at_sign			
check_normal:					
	bl char_actions				
	mov r0, #1					
	b check_done
check_at_sign:					
	ldr r0, =buffer				
	ldrb r1, [r4 , #1]			
	ldrb r2, [r4 , #2]			
	mov r3, #48					
	sub r5, r1, r3				
	sub r6, r2, r3				
	add r4, r0, r5				
at_sign_loop:
	cmp r6, #0					
	beq check_loop_done
	ldrb r0, [r4]				
	bl char_actions				
	sub r6, r6, #1				
	b at_sign_loop				
check_loop_done:
	mov r0, #3					
check_done:
	pop {r4, r5, r6, pc}

// Funtion receives a char and cout and adds to buffer
char_actions:
	push {r4, lr}
	mov r4, r0					
	bl add_to_buffer			
	mov r0, r4					
	cmp r0, #33					
	bne char_print				
	mov r0, #10					
char_print:
	bl uart_put_char			
	pop {r4, pc}

// shifts and puts the given char in r0 to the front
add_to_buffer:
	push {r4, r5, lr}
	mov r4, r0					
	ldr r5, =buffer				
	mov r1, #39					
	add r0, r5, r1 				
add_buffer_loop:
	cmp r0, r5					
	beq add_buffer_done		    
	sub r1, r0, #1 				
	ldrb r2, [r1]				
	strb r2, [r0]				
	mov r0, r1					
	b add_buffer_loop
add_buffer_done:
	strb r4, [r0]				
	pop {r4, r5, pc}