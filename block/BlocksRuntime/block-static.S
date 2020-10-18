	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 11, 0
	.intel_syntax noprefix
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
## %bb.0:
	push	rbp
	mov	rbp, rsp
	and	rsp, -16
	sub	rsp, 16
	mov	eax, edi
	lea	rdi, [rip + ___block_literal_global]
	mov	dword ptr [rsp + 12], 0
	mov	dword ptr [rsp + 8], eax
	mov	qword ptr [rsp], rsi
	call	qword ptr [rip + ___block_literal_global+16]
	cmp	dword ptr [rip + _main.numberOfSquesals], 6
	jne	LBB0_2
## %bb.1:
	mov	rax, qword ptr [rsp]
	mov	rsi, qword ptr [rax]
	lea	rdi, [rip + L_.str.1]
	mov	al, 0
	call	_printf
	mov	dword ptr [rsp + 12], 0
	jmp	LBB0_3
LBB0_2:
	lea	rdi, [rip + L_.str.2]
	mov	al, 0
	call	_printf
	mov	dword ptr [rsp + 12], 1
LBB0_3:
	mov	eax, dword ptr [rsp + 12]
	mov	rsp, rbp
	pop	rbp
	ret
                                        ## -- End function
	.p2align	4, 0x90                         ## -- Begin function __main_block_invoke
___main_block_invoke:                   ## @__main_block_invoke
## %bb.0:
	push	rbp
	mov	rbp, rsp
	and	rsp, -8
	sub	rsp, 16
	mov	qword ptr [rsp + 8], rdi
	mov	qword ptr [rsp], rdi
	mov	dword ptr [rip + _main.numberOfSquesals], 6
	mov	rsp, rbp
	pop	rbp
	ret
                                        ## -- End function
	.section	__DATA,__data
	.p2align	2                               ## @main.numberOfSquesals
_main.numberOfSquesals:
	.long	5                               ## 0x5

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"v8@?0"

	.section	__DATA,__const
	.p2align	3                               ## @__block_descriptor_tmp
___block_descriptor_tmp:
	.quad	0                               ## 0x0
	.quad	32                              ## 0x20
	.quad	L_.str
	.quad	0

	.p2align	3                               ## @__block_literal_global
___block_literal_global:
	.quad	__NSConcreteGlobalBlock
	.long	1342177280                      ## 0x50000000
	.long	0                               ## 0x0
	.quad	___main_block_invoke
	.quad	___block_descriptor_tmp

	.section	__TEXT,__cstring,cstring_literals
L_.str.1:                               ## @.str.1
	.asciz	"%s: success\n"

L_.str.2:                               ## @.str.2
	.asciz	"**** did not update static local, rdar://6177162\n"

.subsections_via_symbols
