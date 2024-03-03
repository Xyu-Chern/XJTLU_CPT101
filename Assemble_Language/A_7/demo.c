#include <stdio.h>

int main()
{
	char message1[] = "Give me a first number: ";
	char message2[] = "Give me a second number: ";
	char message3[] = "The numbers are equal!\n";
	char message5[] = "Type in any integer and press ENTER key to finish: ";
	char format[] = "%d";
	char message6[] = "The first number is greater!\n";
	char message7[] = "The second number is greater!\n";

	int first;
	int second;
	int end;

	_asm {
		lea		eax, message1
		push	eax
		call	printf
		add		esp, 4

		lea		eax, first
		push	eax
		lea		eax, format
		push	eax
		call	  scanf_s
		add		esp, 8

		lea		eax, message2
		push	eax
		call 	printf
		add		esp, 4

		lea		eax, second
		push	eax
		lea		eax, format
		push	eax
		call	   scanf_s
		add		esp, 8

		mov		eax, first
		mov		ebx, second
		cmp		eax, ebx //不能直接比较俩个内存变量的值
		jg		firstNumGreater
		jl		secondNumGreater

		equal : lea	eax, message3
		push	eax
		call 	printf
		add		esp, 4
		jmp		finish

		firstNumGreater : lea eax, message6
		push	eax
		call	    printf
		add		esp, 4
		jmp		finish

		secondNumGreater : lea eax, message7
		push	eax
		call	    printf
		add		esp, 4

		finish : lea eax, message5
		push	eax
		call	    printf
		add		esp, 4

		lea		eax, end
		push	eax
		lea		eax, format
		push	eax
		call	    scanf_s
		add		esp, 8
	}
	return 0;
}