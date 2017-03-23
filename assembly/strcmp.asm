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
	CALL strcmp; compare strings
	PUSH eax; push result
	PUSH message; in format of the message
	CALL printf; print result
	ADD ebp, 8
	CALL exit		
	
strcmp:
	PUSH ebp; save ebp
	MOV ebp, esp; set new ebp as stack pointer
	PUSH ebx; push previous ebx value
	PUSH ecx; push previous ecx value
	MOV eax, 0; set eax to 0 (index)
	JMP compare
	compare:; compare byte by byte untill end of string
		MOVZX ebx, BYTE [string1+eax]; MOV the byte in string1 with index eax to ebx (extend zeros to fix size mismatch)
		MOVZX ecx, BYTE [string2+eax]; MOV the byte in string2 with index eax to ebx (extend zeros to fix size mismatch)
		CMP ebx, ecx; compare both chars
		JNE end_not_good; if they dont equal tehn exit with error
		CMP ebx, 0; check if we reached the end of the string
		JE end_good; exit with a good return code
		INC eax; increase index to check next char
		JMP compare; check next char
	
	end_not_good:
		POP ebp; set the previous ebp
		POP ebx; set the previous ebx
		POP ecx; set the previous ecx
		MOV eax, -1; return -1 error (bad)
		RET

	end_good:
		POP ebp; set the previous ebp
		POP ebx; set the previous ebx
		POP ecx; set the previous ecx
		MOV eax, 0; return 0 (good)
		RET

	
	
	
