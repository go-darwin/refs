	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 11, 0
	.intel_syntax noprefix
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
## %bb.0:
	push	rbp
	mov	rbp, rsp
	push	rbx
	and	rsp, -16
	sub	rsp, 96
	mov	rbx, rsi
	mov	rsi, qword ptr [rip + __NSConcreteStackBlock@GOTPCREL]
	mov	qword ptr [rsp + 48], rsi
	mov	qword ptr [rsp + 56], 1073741824
	lea	rax, [rip + ___main_block_invoke]
	mov	qword ptr [rsp + 64], rax
	lea	rax, [rip + ___block_descriptor_tmp]
	mov	qword ptr [rsp + 72], rax
	mov	dword ptr [rsp + 80], 1
	mov	qword ptr [rsp], rsi
	mov	qword ptr [rsp + 8], 1107296256
	lea	rax, [rip + ___main_block_invoke_2]
	mov	qword ptr [rsp + 16], rax
	lea	rax, [rip + ___block_descriptor_tmp.3]
	mov	qword ptr [rsp + 24], rax
	mov	dword ptr [rsp + 40], edi
	lea	rax, [rsp + 48]
	mov	qword ptr [rsp + 32], rax
	lea	rdi, [rip + L_.str.4]
	xor	eax, eax
	call	_printf
	mov	esi, dword ptr [rsp + 8]
	lea	rdi, [rip + L_.str.5]
	xor	eax, eax
	call	_printf
	mov	rsi, qword ptr [rsp + 24]
	lea	rdi, [rip + L_.str.6]
	xor	eax, eax
	call	_printf
	mov	rax, qword ptr [rsp + 24]
	mov	rsi, qword ptr [rax + 8]
	lea	rdi, [rip + L_.str.7]
	xor	eax, eax
	call	_printf
	mov	rdi, rsp
	call	__Block_copy
	mov	rdi, rax
	call	__Block_release
	mov	rsi, qword ptr [rbx]
	lea	rdi, [rip + L_.str.8]
	xor	eax, eax
	call	_printf
	xor	eax, eax
	lea	rsp, [rbp - 8]
	pop	rbx
	pop	rbp
	ret
                                        ## -- End function
	.p2align	4, 0x90                         ## -- Begin function __main_block_invoke
___main_block_invoke:                   ## @__main_block_invoke
## %bb.0:
	push	rbp
	mov	rbp, rsp
	and	rsp, -8
	mov	eax, dword ptr [rdi + 32]
	add	eax, eax
	lea	eax, [rax + 4*rax]
	mov	rsp, rbp
	pop	rbp
	ret
                                        ## -- End function
	.p2align	4, 0x90                         ## -- Begin function __main_block_invoke_2
___main_block_invoke_2:                 ## @__main_block_invoke_2
## %bb.0:
	push	rbp
	mov	rbp, rsp
	and	rsp, -16
	cmp	dword ptr [rdi + 40], 0
	jle	LBB2_2
## %bb.1:
	mov	rdi, qword ptr [rdi + 32]
	call	qword ptr [rdi + 16]
	lea	rdi, [rip + L_.str.1]
	mov	esi, eax
	xor	eax, eax
	call	_printf
LBB2_2:
	mov	rsp, rbp
	pop	rbp
	ret
                                        ## -- End function
	.private_extern	___copy_helper_block_8_32b ## -- Begin function __copy_helper_block_8_32b
	.globl	___copy_helper_block_8_32b
	.weak_def_can_be_hidden	___copy_helper_block_8_32b
	.p2align	4, 0x90
___copy_helper_block_8_32b:             ## @__copy_helper_block_8_32b
## %bb.0:
	push	rbp
	mov	rbp, rsp
	and	rsp, -16
	add	rdi, 32
	mov	rsi, qword ptr [rsi + 32]
	mov	edx, 7
	call	__Block_object_assign
	mov	rsp, rbp
	pop	rbp
	ret
                                        ## -- End function
	.private_extern	___destroy_helper_block_8_32b ## -- Begin function __destroy_helper_block_8_32b
	.globl	___destroy_helper_block_8_32b
	.weak_def_can_be_hidden	___destroy_helper_block_8_32b
	.p2align	4, 0x90
___destroy_helper_block_8_32b:          ## @__destroy_helper_block_8_32b
## %bb.0:
	push	rbp
	mov	rbp, rsp
	and	rsp, -16
	mov	rdi, qword ptr [rdi + 32]
	mov	esi, 7
	call	__Block_object_dispose
	mov	rsp, rbp
	pop	rbp
	ret
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"i8@?0"

	.section	__DATA,__const
	.p2align	3                               ## @__block_descriptor_tmp
___block_descriptor_tmp:
	.quad	0
	.quad	36
	.quad	L_.str
	.quad	0

	.section	__TEXT,__cstring,cstring_literals
L_.str.1:                               ## @.str.1
	.asciz	"intblock returns %d\n"

L_.str.2:                               ## @.str.2
	.asciz	"v8@?0"

	.section	__DATA,__const
	.p2align	3                               ## @__block_descriptor_tmp.3
___block_descriptor_tmp.3:
	.quad	0
	.quad	44
	.quad	___copy_helper_block_8_32b
	.quad	___destroy_helper_block_8_32b
	.quad	L_.str.2
	.quad	0

	.section	__TEXT,__cstring,cstring_literals
L_.str.4:                               ## @.str.4
	.asciz	"isa %p\n"

L_.str.5:                               ## @.str.5
	.asciz	"flags %x\n"

L_.str.6:                               ## @.str.6
	.asciz	"descriptor %p\n"

L_.str.7:                               ## @.str.7
	.asciz	"descriptor->size %lu\n"

L_.str.8:                               ## @.str.8
	.asciz	"%s: success\n"

.subsections_via_symbols
