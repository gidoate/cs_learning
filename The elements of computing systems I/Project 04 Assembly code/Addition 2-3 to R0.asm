//Program Add.asm
//Adds the constants 2 and 3 and writes to R0

@2
D=A
@R0
M=D
@3
D=A
@R1
M=D
@R0
M=D+M
@END
0;JMP //Termination Jump
(END)
0;JMP //Program termination