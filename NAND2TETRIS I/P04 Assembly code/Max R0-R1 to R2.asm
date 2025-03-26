//Program Max.asm
//Max out the values in R0 and R1 and write the maximum in R2
//Pseudocode:
//If R0-R1>0 write R0 in R2, else write R1

@R0
D=M
@R1
D=D-M
@POSITIVE
D;JGT // If R0>0 go to POSTIVE, else, carry on below

@R1
D=M
@R2
M=D
@END
0;JMP

(POSITIVE)
@R0
D=M
@R2
M=D
@END
0;JMP

(END)
0;JMP
