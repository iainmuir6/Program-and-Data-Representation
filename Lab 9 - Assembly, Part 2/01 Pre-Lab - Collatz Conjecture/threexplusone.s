; Iain Muir, iam9ez
; April 7th, 2020
; threexplusone.s
;
; Purpose: This file contains one function, threexplusone.
;	   Given one integer paramter, the function will return the number of steps 
; 	   required for that integer to reach 1 by following the Collatz conjecture
;
; Paramter 1 (rdi) is the first integer, x
;
; Return value is the number of steps
;
; Code has been formatted for compilation on a x64 Linux machine.
; 	Add an underscore before each instance of threexplusone in only this assembly file for macOS
;
; Optimizations:
;	1. The biggest optimization I used was the lea instruction for multiplication. This reduced the 3x+1 aspect of the
; 	subroutine from 5 lines to 1 simple instruction
;	2. Switching to lea multiplication also helped reduce my memory accesses because previously I would push
; 	and pop a register to save the inital value of rdi
;	3. Lastly, I switched the lea instruction from 3*rdi + 1 to 2*rdi + rdi + 1 to minimize multiplication
	
	global threexplusone						; _threexplusone

	section .text

threexplusone:								; _threexplusone
	mov	rax, 0			; zero out rax register
threexplusoneMain:							; _threexplusoneMain
	cmp 	rdi, 1			; Check if argument = 1
	je	done			; If x == 1, done
	
	inc	rax			; steps++
	push 	rdi			; save rdi
	and	rdi, 1			; check if odd or even
	jz	even			; if 0, jump to even
	pop	rdi			; restore rdi
	
	lea	rdi, [2*rdi + rdi + 1] 	; 3x + 1
	call	threexplusoneMain	; recursive call		; _threexplusoneMain
	ret
even:
	pop	rdi			; restore rdi
	shr	rdi, 1			; x / 2
	call	threexplusoneMain	; recursive call		; _threexplusoneMain
done:
	ret



	
