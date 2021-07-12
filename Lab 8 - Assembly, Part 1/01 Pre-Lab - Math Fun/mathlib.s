; Iain Muir, iam9ez
; March 31st, 2020
; mathlib.s
;
; Purpose : This file contains two functions, product and power. 
;	    Given two integer parameters, x and y, these functions will compute x * y and x ^ y
;
; Parameter 1 (in rdi) is the first integer, x
; Parameter 2 (in rsi) is the second integer, y
;
; Return value for product(x, y) : x * y
; Return value for power(x, y) : x ^ y
;
; Code has been formatted for compilation on a x64 Linux machine.
; 	Add an underscore before each instance of product and power in only this assembly file for macOS
	
	global product		; _product
	global power		; _power

	section .text
product:			; _product
	;; Prologue - NONE
	;; Subroutine body
	xor 	rax, rax	; zero out rax register
	xor 	r10, r10	; zero out r10 register
prodLoop:
	cmp	r10, rsi	; if (i == y)
	je	prodDone	; jump to done
	add	rax, rdi	; else: add x to the rax register
	dec	rsi		; y--
	jmp 	prodLoop	; jump to beginning of loop	
prodDone:
	;; Epilogue	
	ret			; return --> rax register


power:				; _power
	;; Prologue
	;; Subroutine Body
	push 	rdi		; save value of x
start:
	cmp 	rsi, 1		; if (y == 1)  -> Base Case
	je	powDone		; jump to done
	
	dec	rsi		; y--
	call 	power		; x ^ y recursive call  (_power)  

	pop	rdi		; restore value of x
	mov	rsi, rdi	; copy the base value into rsi
	mov	rdi, rax	; copy the return value into rdi
	call 	product		; x * y ( _product)
	ret

powDone:
	;; Epilogue
	mov	rax, rdi	; store/copy return value
	pop 	rdi		; pop rdi (in case not done in loop)
	ret			; return --> rax register
