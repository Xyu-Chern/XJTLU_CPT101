// Handling Character.cpp : Defines the entry point for the console application.
//
#include <stdio.h>

int main()
{
	char scanf_fmt[] = "%c";
	char printf_fmt[] = "%c\n";
	char character;

	_asm {
		push	1							// Buffer size, you can also write `push size character`
		lea		eax, character
		push	eax							// Pointer to character
		lea		eax, scanf_fmt
		push	eax							// Pointer to format string
		call	scanf_s
		add		esp, 12						// Clean up three pushes

		movzx	eax, byte ptr[character]	// MOVZX: Load one unsigned byte into a 32-bit-register
		push	eax							// Character as value
		lea		eax, printf_fmt
		push	eax							// Pointer to format string
		call	printf
		add		esp, 8						// Clean up two pushes
	}
	return 0;
}