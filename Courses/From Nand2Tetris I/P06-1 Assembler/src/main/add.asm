// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/06/add/Add.asm

// Computes R0 = 2 + 3

@2 // Selection of address 2
D=A // D equals to 2
@3
D=D+A
@0
M=D