//Program Rect.asm
//Draws a rectangle at the top left corner of the screen (16wide x R0height pixels)

@SCREEN
D=A
@addr
M=D
@R0
D=M
@n
M=D //n is set to the value written in R0
@i
M=0

(LOOP)
@i
D=M
@n
D=D-M
@END
D;JGE //when i-n=0, jumps to end (this means that when i reaches the value written in R0, the loop finishes)

@addr
A=M
M=-1 //write 1111111111111111 into the corresponding address

@i
M=M+1
@32
D=A
@addr
M=D+M
@LOOP
0;JMP 

(END)
@END 
0;JMP

