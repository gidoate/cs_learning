	.file	"addition.c"
	.section .rdata,"dr"
LC0:
	.ascii "Returning 1\0"
	.align 4
LC1:
	.ascii "Returning %d + addition(%d - 1) = %d\12\0"
	.text
	.globl	_addition
	.def	_addition;	.scl	2;	.type	32;	.endef
_addition:
LFB12:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$20, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	cmpl	$1, %ebx
	je	L5
	leal	-1(%ebx), %eax
	movl	%eax, (%esp)
	call	_addition
	leal	(%ebx,%eax), %esi
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
L1:
	movl	%esi, %eax
	addl	$20, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
L5:
	.cfi_restore_state
	movl	$LC0, (%esp)
	call	_puts
	movl	%ebx, %esi
	jmp	L1
	.cfi_endproc
LFE12:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC2:
	.ascii "Input the last number of the range starting from 1: \0"
LC3:
	.ascii "%d\0"
LC4:
	.ascii "Addition result is: %d\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$0, 28(%esp)
	movl	$LC2, (%esp)
	call	_printf
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_scanf
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	_addition
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
