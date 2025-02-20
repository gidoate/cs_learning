// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, 
// the screen should be cleared.

(RESTART)
@SCREEN
D=A
@0
M=D 

(KBDcheck) //KBD pressed or not
@KBD
D=M //Read what's in KBD
@BLACK
D;JGT //Jump if any keyboard key is pressed
@WHITE
D;JEQ //Goto white if D=0

@KBDcheck
0;JMP

(BLACK) //if a key is pressed, fill with -1
@1
M=-1
@FILL
0;JMP

(WHITE) //if no key is pressed, fill with 0
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
/////////////////////////
@RESTART
0;JMP

//// Replace this comment with your code.