.data
# DONOTMODIFYTHISLINE
frameBuffer: .space 0x80000 #512wideX256highpixels
w: .word 370
h: .word 10
l: .word 20
bgcol: .word 0x00E6CC99
# DONOTMODIFYTHISLINE
# Your variables go BELOW here only (and above .text)
.text
lw $s0, w # w variable
lw $s1, h # h variable 
lw $s2, l # l variable
lw $s3, bgcol # background color variable
li $s4, 512 # screen display width
li $s5, 256 # screen display height


Error_Handling:

	slti $t1, $s0, 60 # Check if width is <= 60 
	beq $t1, 1, error
	
	andi $t1, $s0, 1     # Essentially t1 % 2
	beq $t1, 1, error  # If the result is zero, the value is even
	
	slti $t1, $s0, 512
	
	
	# If the value is odd, continue with odd-specific code here

init:
	li $t7, 0 # Current location to draw
	la $t1, frameBuffer # base address from frameBuffer
	# (256 - h - l - 32 - 32 - (w-48)/2) / 2 
	sub $t2, $s5, $s1 # t2 <- 256 - h
	sub $t2, $t2, $s2  # t2 <- 256 - h - l
	addi $t2, $t2, -32  # t2 <- 256 - h - l - 32
	addi $t2, $t2, -32  # t2 <- 256 - h - l - 32 - 32
	addi $t3, $s0, -48 # t3 <- w - 48
	srl $t3, $t3, 1 #t3 <- (w - 48) / 2 
	sub $t2, $t2, $t3 # t2 <- (256 - h - l - 32 - 32 - (w-48)/2)
	srl $t2, $t2, 1 # t2 <-  ((256 - h - l - 32 - 32 - (w-48)/2) / 2)
	add $s6, $t2, $zero
	li $t6, 0 # Set row index to 0

drawRow_outer:
	li $t4, 0 # Set column index to 0
drawRow_inner:
	sll $t5, $t4, 2 # Multiplying column by 4
	add $t7, $t1, $t5 # Adding 4 * col to base address of buffer
	sw $s3, 0($t7)
	addi $t4, $t4, 1 # incrementing column 
	bne $t4, $s4, drawRow_inner
	
	addi $t6, $t6, 1 # 
	sll $t5, $s4, 2
	add $t1, $t1, $t5
	bne $t6, $t2, drawRow_outer

add $t7, $t1, -2048


drawCap:
	# (512 - 60) / 2
	#addi $t2, $s4, -60 # t2 <- 512 - 60
	#srl $t2, $t2, 1 # t2 <- (512 - 60) / 2, width left/right of the cap
	
	li $t6, 0 # Set row index to 0
drawCap_outer:
	li $t4, -1 # Set column index to -1
	slti $t0, $t6, 32
	beq $t0, $zero, drawFunnel # exit outer loop
	addi $t7, $t7, 2048
drawCap_inner:
	addi $t4, $t4, 1 # incrementing column 
	
	sll $t5, $t4, 2 # Multiplying column by 4
	add $t7, $t7, $t5 # Adding 4 * col to current location 
	la $t1, 0x000000FF
	sw $t1, 0($t7)
	slti $t0, $t4, 226 # Set $t0 to 1 if $t4 < 226, 0 otherwise
 	beq  $t0, 1, then # Branch to "then" if $t0 != 0
	
 	slti $t0, $t4, 286
	beq $t0, $zero, then
	
	sub $t7, $t7, $t5
	
	bne $t4, $s4, drawCap_inner
then: 
	sw $s3, 0($t7)
	sub $t7, $t7, $t5
	bne $t4, $s4, drawCap_inner
	addi $t6, $t6, 1
	j drawCap_outer


drawFunnel:
	li $t6, 0

	
	# s3 is bgcol
	
	srl $t1, $s3, 16   # Shift right by 16 to get the value of red component
	andi $t1, $t1, 0xFF   # AND with 0xFF to clear out the remaining bits
	srl $t1, $t1, 1 # Divide red by 2
	

	srl $t2, $s3, 8    # Shift right by 8 bits to extract the green byte
	andi $t2, $t2, 0xFF   # Mask off all but the blue part
	srl $t2, $t2, 1 # Divide green by 2
	
	andi $t3, $s3, 0xFF # Mask off all but the green part
	srl $t3, $t3, 1 # Divide blue by 2
	
	sll $t1, $t1, 16    # Shift the red byte left by 16 bits
	sll $t2, $t2, 8     # Shift the green byte left by 8 bits
	or $t1, $t1, $t2    # Combine the red and green bytes
	or $t1, $t1, $t3    # Combine the blue byte
drawFunnel_outer:
	li $t4, -1 # Set column index to -1
	slti $t0, $t6, 32
	beq $t0, $zero, drawTaper # exit outer loop
	addi $t7, $t7, 2048
	
drawFunnel_inner:
	addi $t4, $t4, 1 # incrementing column 
	
	sll $t5, $t4, 2 # Multiplying column by 4
	add $t7, $t7, $t5 # Adding 4 * col to current location 

	sw $t1, 0($t7)
	
	slti $t0, $t4, 232 # Set $t0 to 1 if $t4 < 226, 0 otherwise
 	beq  $t0, 1, funnel_then # Branch to "then" if $t0 != 0
	
 	slti $t0, $t4, 280
	beq $t0, $zero, funnel_then
	
	sub $t7, $t7, $t5
	
	bne $t4, $s4, drawFunnel_inner
funnel_then: 
	sw $s3, 0($t7)
	sub $t7, $t7, $t5
	bne $t4, $s4, drawFunnel_inner
	addi $t6, $t6, 1
	j drawFunnel_outer
	
	

drawTaper:
	li $t6, 0
	li $t8, 232
	li $t9, 280
	addi $t2, $s0, -48 # t2 <- w - 48
	srl $t2, $t2, 1 # t2 <- (w - 48) / 2, width left/right of the cap
drawTaper_outer:
	li $t4, -1 # Set column index to -1
	addi $t8, $t8, -1
	
	addi $t9, $t9, 1
	slt $t0, $t6, $t2
	beq $t0, $zero, drawSecondBox # exit outer loop
	addi $t7, $t7, 2048
	
drawTaper_inner:
	addi $t4, $t4, 1 # incrementing column 
	
	sll $t5, $t4, 2 # Multiplying column by 4
	add $t7, $t7, $t5 # Adding 4 * col to current location 
	sw $t1, 0($t7)
	slt $t0, $t4, $t8 # Set $t0 to 1 if $t4 < 226, 0 otherwise
 	beq  $t0, 1, taper_then # Branch to "then" if $t0 != 0
 	slt $t0, $t4, $t9
	beq $t0, $zero, taper_then
	#addi $t9, $t9, 1
	sub $t7, $t7, $t5
	
	bne $t4, $s4, drawTaper_inner
taper_then: 
	sw $s3, 0($t7)
	sub $t7, $t7, $t5
	bne $t4, $s4, drawTaper_inner
	addi $t6, $t6, 1
	j drawTaper_outer
	
	
	
	
drawSecondBox:
	li $t6, 0
#	sub $t8, $s4, $s0
#	srl $t8, $t8, 1
	
	sub $t8, $s4, $s0
	srl $t8, $t8, 1
	add $t9, $t8, $s0
	addi $t2, $s4, -48 # t2 <- 512 - 48
	srl $t2, $t2, 1 # t2 <- (512 - 48) / 2, width left/right of the cap
drawSecondBox_outer:
	li $t4, -1 # Set column index to -1
	slt $t0, $t6, $s1
	beq $t0, $zero, drawFinalBox # exit outer loop
	addi $t7, $t7, 2048
	
drawSecondBox_inner:
	addi $t4, $t4, 1 # incrementing column 
	
	sll $t5, $t4, 2 # Multiplying column by 4
	add $t7, $t7, $t5 # Adding 4 * col to current location 
	sw $t1, 0($t7)
	slt $t0, $t4, $t8 # Set $t0 to 1 if $t4 < 226, 0 otherwise
 	beq $t0, 1, secondbox_then # Branch to "then" if $t0 != 0
	
 	slt $t0, $t4, $t9
	beq $t0, $zero, secondbox_then
	
	sub $t7, $t7, $t5
	
	bne $t4, $s4, drawSecondBox_inner
secondbox_then: 
	sw $s3, 0($t7)
	sub $t7, $t7, $t5
	bne $t4, $s4, drawSecondBox_inner
	addi $t6, $t6, 1
	j drawSecondBox_outer
	
	
	
drawFinalBox:
	li $t6, 0
#	sub $t8, $s4, $s0
#	srl $t8, $t8, 1
	srl $t4, $s3, 16   # Shift right by 16 to get the value of red component
	andi $t4, $t4, 0xFF   # AND with 0xFF to clear out the remaining bits
	

	srl $t2, $s3, 8    # Shift right by 8 bits to extract the green byte
	andi $t2, $t2, 0xFF   # Mask off all but the green part
	
	andi $t3, $s3, 0xFF # Mask off all but the blue part
	
	sll $t1, $t3, 16    # Shift the red byte left by 16 bits
	sll $t2, $t2, 8     # Shift the green byte left by 8 bits
	or $t1, $t1, $t2    # Combine the red and green bytes
	or $t1, $t1, $t3    # Combine the blue byte
	
	
	sll $t1, $t3, 16    # Shift the red byte left by 16 bits
	sll $t2, $t2, 8     # Shift the green byte left by 8 bits
	or $t1, $t1, $t2    # Combine the red and green bytes
	or $t1, $t1, $t4    # Combine the blue byte
	
	addi $t2, $s4, -48 # t2 <- 512 - 48
	srl $t2, $t2, 1 # t2 <- (512 - 48) / 2, width left/right of the cap
drawFinalBox_outer:
	li $t4, -1 # Set column index to -1
	slt $t0, $t6, $s2
	beq $t0, $zero, drawFinalRows # exit outer loop
	addi $t7, $t7, 2048
	
drawFinalBox_inner:
	addi $t4, $t4, 1 # incrementing column 
	
	sll $t5, $t4, 2 # Multiplying column by 4
	add $t7, $t7, $t5 # Adding 4 * col to current location 
	la $s7, 0x0000FFFF
	sw $t1, 0($t7)
	slt $t0, $t4, $t8 # Set $t0 to 1 if $t4 < 226, 0 otherwise
 	beq $t0, 1, finalbox_then # Branch to "then" if $t0 != 0
	
 	slt $t0, $t4, $t9
	beq $t0, $zero, finalbox_then
	
	sub $t7, $t7, $t5
	
	bne $t4, $s4, drawFinalBox_inner
finalbox_then: 
	sw $s3, 0($t7)
	sub $t7, $t7, $t5
	bne $t4, $s4, drawFinalBox_inner
	addi $t6, $t6, 1
	j drawFinalBox_outer
	
	
	

drawFinalRows:

	# s3 is bgcol
	li $t4, 0
	li $t6, 0
drawFinalRows_outer:
	li $t4, -1 # Set column index to -1
	slt $t0, $t6, $s6
	beq $t0, $zero, exit # exit outer loop
	addi $t7, $t7, 2048
	
drawFinalRows_inner:
	addi $t4, $t4, 1 # incrementing column 
	
	sll $t5, $t4, 2 # Multiplying column by 4
	add $t7, $t7, $t5 # Adding 4 * col to current location 
	sw $s3, 0($t7)
	slt $t0, $t4, $t8 # Set $t0 to 1 if $t4 < 226, 0 otherwise
 	beq $t0, 1, finalrows_then # Branch to "then" if $t0 != 0
	
 	slt $t0, $t4, $t9
	beq $t0, $zero, finalrows_then
	
	sub $t7, $t7, $t5
	
	bne $t4, $s4, drawFinalRows_inner
finalrows_then: 
	sw $s3, 0($t7)
	sub $t7, $t7, $t5
	bne $t4, $s4, drawFinalRows_inner
	addi $t6, $t6, 1
	j drawFinalRows_outer
	
error:
	# (512 - 60) / 2
	#addi $t2, $s4, -60 # t2 <- 512 - 60
	#srl $t2, $t2, 1 # t2 <- (512 - 60) / 2, width left/right of the cap
	li $t6, 0 # Set row index to 0
	la $t1, frameBuffer # base address from frameBuffer
error_outer:
	li $t4, -1 # Set column index to -1
	addi $t1, $t1, 2048
error_inner:
	addi $t4, $t4, 1 # incrementing column 
	
	sll $t5, $t4, 2 # Multiplying column by 4
	add $t1, $t1, $t5 # Adding 4 * col to current location 
	sw $s3, 0($t1)
	sub $t1, $t1, $t5
	bne $t4, $s4, error_inner
	addi $t6, $t6, 1
	bne $t6, 256, error_outer
	
	j exit

exit:
	li $v0, 10 # exit
	syscall
	
