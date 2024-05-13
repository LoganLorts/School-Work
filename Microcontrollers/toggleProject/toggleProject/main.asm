;
; toggleProject.asm
;
; Created: 2/11/2024 10:04:43 PM
; Author : pheag
;


; Replace with your application code
	LDI R16,0XFF
	OUT DDRB,R16

L1: OUT PORTB,R16
	LDI R20,0
	OUT PORTB,R20
	RJMP L1