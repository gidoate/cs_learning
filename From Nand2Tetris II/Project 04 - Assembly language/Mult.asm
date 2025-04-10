// Set result to 0
@0 // Could be @R0 (same with the rest of the register from R0 to R15)
D=A
@16 // Result (could be as well @result)
M=D
// Set mult to R0
@0
D=M
@17 // Mult (could be as well @mult)
M=D

(LOOP)
@1
D=M
@16
M=D+M
@17
M=M-1
D=M
@8 // select LOOP
D; JGT // go to loop only if D > 0

@16 // From here, write value in @result (@16) into R2 and end the program
D=M
@2
M=D

(END)
@21 // END
0; JMP
