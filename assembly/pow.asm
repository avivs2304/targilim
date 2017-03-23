	global main
	extern printf, exit
	section .text

message db "Register == %08X", 10, 0
main:
	MOV eax, 2
	MOV ebx, 3
	CALL Pow
	PUSH eax
	PUSH message
	CALL printf
	ADD esp, 8
	CALL exit


Pow:
	PUSH ebp
	MOV ebp, esp
	PUSH ecx	
	PUSH ebx
	MOV ecx, eax
	JMP power
	power:
		CMP ebx, 1
		JLE end
		IMUL eax, ecx
		DEC ebx
		JMP power
	end:
		POP ebx
		POP ecx
		POP ebp
		RET
		
