#include <stdio.h>

int main()
{
	char msgTotalAmt[] = "Total amount is %d";
	int testArray[3] = { 8, 6, 4 };
	int loopCounter = 3;
	int totalAmt = 0;
	_asm {

		lea		esi, testArray
		mov		ecx, loopCounter

		addLoop :mov eax, [esi]
			add		totalAmt, eax
			add		esi, 4
			loop	addLoop

			mov		eax, totalAmt
			push	eax
			lea		eax, msgTotalAmt
			push	eax
			call	printf
			add		esp, 8
	}
	return 0;
}