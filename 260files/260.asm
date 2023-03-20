.data
# DONOTMODIFYTHISLINE
frameBuffer: .space 0x80000 #512wideX256highpixels
w: .word 70
h: .word 20
l: .word 70
bgcol: .word 0x00FF00FF
# DONOTMODIFYTHISLINE
# Your variables go BELOW here only (and above .text)
.text
lw $s0, w # w variable
lw $s1, h # h variable 
lw $s2, l # l variable
lw $s3, bgcol # background color variable
li $s4, 512 # screen display width
li $s5, 256 # screen display height
init:
	li $t7, 0 # Current location to draw
	la $t1, frameBuffer # base address from frameBuffer
	# (256 - h - l - 32 - 32 - (w-48)/2) / 2 
	sub $t2, $s5, $s1 # t2 <- 256 - h
	sub $t2, $t2, $s2  # t2 <- 256 - h - l
	addi $t2, $t2, -32  # t2 <- 256 - h - l - 32
	addi $t2, $t2, -32  # t2 <- 256 - h - l - 32 - 32
	addi $t3, $s0, -48  # t3 <- w - 48 
	srl $t3, $t3, 1 # t3 <- (w - 48) / 2 
	sub $t2, $t2, $t3 # t2 <- (256 - h - l - 32 - 32 - (w-48)/2)
	srl $t2, $t2, 1 # t2 <-  ((256 - h - l - 32 - 32 - (w-48)/2) / 2)
	li $t6, 0 # Set row index to 0
drawRow_outer:
	li $t4, 0 # Set column index to 0
drawRow_inner:
	sll $t5, $t4, 2 # Multiplying column by 4
	add $t7, $t1, $t5 # Adding 4 * col to base address of buffer
	#sw $s3, 0($t7)
	addi $t4, $t4, 1 # incrementing column 
	bne $t4, $s4, drawRow_inner
	
	addi $t6, $t6, 1 # 
	sll $t5, $s4, 2
	add $t1, $t1, $t5
	bne $t6, $t2, drawRow_outer

add $t7, $t1, $zero


drawCap:
	# (512 - 60) / 2
	addi $t2, $s4, -60 # t2 <- 512 - 60
	srl $t2, $t2, 1 # t2 <- (512 - 60) / 2, width left/right of the cap
	li $t3, 0 # Set row index to 0
	li $t4, -1 # Set column index to -1
drawCap_outer:
	li $t6, 0
drawCap_inner:
	addi $t4, $t4, 1 # incrementing column 
	
	sll $t5, $t4, 2 # Multiplying column by 4
	add $t7, $t7, $t5 # Adding 4 * col to current location 
	la $s7, 0x000000FF
	sw $s7, 0($t7)
	slti $t0, $t4, 226 # Set $t0 to 1 if $t4 < 226, 0 otherwise
 	beq  $t0, 1, then # Branch to "then" if $t0 != 0
	
 	slti $t0, $t4, 286
 	
	#slti $t0, $s4, 286
	beq $t0, $zero, second_then
	sub $t7, $t7, $t5
	
	bne $t4, $s4, drawCap_inner
then: 
	sw $s3, 0($t7)
	sub $t7, $t7, $t5
	bne $t4, $s4, drawCap_inner
second_then:
	sw $s3, 0($t7)
	sub $t7, $t7, $t5
	bne $t4, $s4, drawCap_inner

end_loop:	
	li $v0, 10 # exit
	syscall
	
