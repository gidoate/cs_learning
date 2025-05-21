(MAIN_LOOP)
@SCREEN
D=A
@0
M=D

(KBD_CHECK)
@KBD // (@24576) Check if key is pressed
D=M
@SCREEN_ON_LOOP // 
D;JGT // If pressed (D > 0), jump to Screen OFF Loop

@SCREEN_OFF_LOOP
D;JEQ // If not pressed (D = 0), jump to Screen OFF Loop

@KBD_CHECK
0;JMP

(SCREEN_ON_LOOP) // If a key is pressed, fill with -1
@1
M=-1
@FILL
0;JMP

(SCREEN_OFF_LOOP) // If a key is pressed, fill with 0
@1
M=0
@FILL
0;JMP

(FILL) //fill loop
@1	
D=M	//D CONTAINS BLACK OR WHITE

@0
A=M	//GET ADRESS OF SCREEN PIXEL TO FILL
M=D	//FILL IT

@0
D=M+1	//INC TO NEXT PIXEL

@KBD
D=A-D	//KBD-SCREEN=A

@0
M=M+1	//INC TO NEXT PIXEL
A=M

@FILL
D;JGT	//IF A=0 EXIT AS THE WHOLE SCREEN IS BLACK

@MAIN_LOOP
0;JMP


