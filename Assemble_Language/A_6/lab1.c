
#include <stdio.h>

int main()
{
	char message1[] = "Give me a first number: ";
	char message2[] = "Give me a second number: ";
	char message3[] = "The numbers are equal!\n";
	char message4[] = "The numbers are not equal!\n";
	char message5[] = "Type in any integer and press ENTER key to finish: ";
	char format[] = "%d";	// format string for the scanf function

	int first;
	int second;
	int end;

	_asm {
		lea		eax, message1
		push	eax
		call	printf; printing the first message
		add		esp, 4

		lea		eax, first
		push	eax
		lea		eax, format
		push	eax
		call	scanf_s; reading the first number
		add		esp, 8

		lea		eax, message2
		push	eax
		call	printf; printing the second message
		add		esp, 4

		lea		eax, second
		push	eax
		lea		eax, format
		push	eax
		call	scanf_s; reading the second number
		add		esp, 8

		mov		eax, first
		sub		eax, second
		jnz		nequal

		equal :
		lea		eax, message3
			push	eax
			call	printf; printing the third message
			add		esp, 4
			jmp		finish

		nequal :
		lea		eax, message4
			push	eax
			call	printf; printing the fourth message
			add		esp, 4

		finish:
		lea		eax, message5
			push	eax
			call	printf; printing the fifth message
			add		esp, 4

			lea		eax, end
			push	eax
			lea		eax, format
			push	eax
			call	scanf_s; reading any integer to end program
			add		esp, 8
	}
	return 0;
}


