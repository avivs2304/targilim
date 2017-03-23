	global main
	extern printf, exit
	section .data

string1:
	db "hello there",0

string2:
	db "hello there",0

	section .text

message db "(0 is good, FFFFFFFF is bad) == %08X", 10, 0

main:
	CALL strcmp
	PUSH eax
	PUSH message
	CALL printf
	ADD ebp, 8
	CALL exit		
	
strcmp:
	PUSH ebp
	MOV ebp, esp
	PUSH ebx
	PUSH ecx
	MOV eax, 0
	JMP compare
	compare:
		MOVZX ebx, BYTE [string1+eax]
		MOVZX ecx, BYTE [string2+eax]
		CMP ebx, ecx
		JNE end_not_good
		CMP ebx, 0		
		JE end_good
		INC eax
		JMP compare
	
	end_not_good:
		POP ebp
		POP ebx
		POP ecx
		MOV eax, -1
		RET

	end_good:
		POP ebp
		POP ebx
		POP ecx
		MOV eax, 0
		RET

	
	
	
