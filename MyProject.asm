
_main:
	LDI        R27, 255
	OUT        SPL+0, R27
	LDI        R27, 0
	OUT        SPL+1, R27

;MyProject.c,28 :: 		void main() {
;MyProject.c,30 :: 		DDB0_bit = 0;                     // Set PB0 pin as input
	IN         R27, DDB0_bit+0
	CBR        R27, 1
	OUT        DDB0_bit+0, R27
;MyProject.c,31 :: 		DDRC  = 0xFF;                     // Configure PORTC as output
	LDI        R27, 255
	OUT        DDRC+0, R27
;MyProject.c,32 :: 		PORTC = 0xAA;                     // Initial PORTC value
	LDI        R27, 170
	OUT        PORTC+0, R27
;MyProject.c,34 :: 		oldstate = 0;                     // Oldstate initial value
	LDS        R27, _oldstate+0
	CBR        R27, BitMask(_oldstate+0)
	STS        _oldstate+0, R27
;MyProject.c,38 :: 		while(1)                         // Endless loop
L_main0:
;MyProject.c,40 :: 		PORTC = ~PORTC;               // Invert PORTC
	IN         R16, PORTC+0
	COM        R16
	OUT        PORTC+0, R16
;MyProject.c,41 :: 		oldstate = 0;                 // Update flag
	LDS        R27, _oldstate+0
	CBR        R27, BitMask(_oldstate+0)
	STS        _oldstate+0, R27
;MyProject.c,42 :: 		}
	JMP        L_main0
;MyProject.c,43 :: 		}
L_end_main:
L__main_end_loop:
	JMP        L__main_end_loop
; end of _main
