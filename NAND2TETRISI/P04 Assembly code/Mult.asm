// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
// The algorithm is based on repetitive addition.

//Concept - add R1 to itself a total of R0 times
//for (i=0 to i<=R0; i++){
//      R2=R2+R1
//{

@R0
D=M
@R2
M=0 //initializes R2 at 0
@n
M=D
@i
M=0 //initialize i=0


(LOOP)
@i
D=M
@n
D=D-M
@END
D;JGE //If D reaches 0, then goto end

@R1
D=M //D equal to what is in the memory at this point
@R2
D=D+M //D equal to the addtion of what is in the memory at this point, plus D
M=D
@i
M=M+1
@LOOP
0;JMP

(END) //Termination
@END
0;JMP



//// Replace this comment with your code.