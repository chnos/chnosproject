[FORMAT "WCOFF"]
[INSTRSET "i486p"]
[BITS 32]
[FILE "chnapi2000.nas"]

		GLOBAL	_api_printf

[SECTION .text]

_api_printf:		; void api_printf(void);
		MOV		EDX,0x2000
		INT		0x40
		RET