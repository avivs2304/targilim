	global main
	extern printf, exit
	section .text

message db "Register == %08X", 10, 0
main:
	MOV eax, 2; base number
	MOV ebx, 3; exponent
	CALL Pow; base number^exponent
	PUSH eax; push result
	PUSH message; push the format of the result string
	CALL printf; print the result
	ADD esp, 8
	CALL exit


Pow:
	PUSH ebp; save ebp
	MOV ebp, esp; set the ebp as the stack pointed
	PUSH ecx; save previous ecx
	PUSH ebx; save previous ebx
	MOV ecx, eax; move the base number into ecx
	JMP power
	power:; multipy base number by itself exponent times
		CMP ebx, 1; check if exponent is 1
		JLE end; if its 1 then we finished
		IMUL eax, ecx; multipy eax by base number
		DEC ebx; ebx=ebx-1
		JMP power
	end:
		POP ebx; set to previous exponent value
		POP ecx; set to previous ecx value;
		POP ebp; set to previous ebp value
		RET
		
