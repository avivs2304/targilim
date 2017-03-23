	global main
	extern printf,
	section .text

message db "eax == %08X", 10, 0
main:
	MOV ebx, 10 ; n=10
	CALL fibo
	PUSH eax; eax=current value of n
	PUSH message
	CALL printf
	ADD esp, 8
	MOV eax, 1; syscall 1 to exit
	MOV ebx, 0; return code 0
	int 80h

fibo:
	PUSH ebp; save ebp
	MOV ebp, esp; move stack pointet to base pointer
	CMP ebx, 1; if we hit the flag condition (end or recursion)
	JE flag; jump to flag;
	DEC ebx; set the parameter to n-1
	CALL fibo; call fibo with n-1
	PUSH eax; push current level value
	ADD eax, ecx; add previous value to current value to get the next level value; 
	POP ecx; set the current level value as previous value
	POP ebp; set the saved ebp
	RET; previous level
	flag:; this gets called when n=1
		MOV ecx, 0; previous value 0
		MOV eax, 1; current value 1
		POP ebp; set the saves ebp
		RET; return to after recursion call. 

	
	
