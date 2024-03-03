
#include <stdio.h>

int main()
{
	char msgSelectPositiveInt[] = "Select total number of positive integers (between 2-5): ";
	char msgEnterPositiveInt[] = "Enter positive integer %d: ";
	char msgProgEnds[] = "Program terminates and has looped %d times.\n";
	char msgListInt[] = "Your integers from lowest to highest are ";
	char msgComma[] = " , ";
	char msgTotalAmt[] = "\nThe total amount is %d \n";

	char format[] = "%d"; 

	int totalNumInt;
	int intList[5];

	int cntNumInt = 0;
	int positiveInt;
	int totalAmt = 0;

	_asm {

	readTotalPositiveInt:lea eax, msgSelectPositiveInt
			push	eax
			call	printf
			add		esp, 4

			lea		eax, totalNumInt
			push	eax
			lea		eax, format
			push	eax
			call	scanf_s
			add		esp, 8

			mov		eax, totalNumInt
			cmp		eax, 5
			jg		readTotalPositiveInt
			cmp		eax, 2
			jl		readTotalPositiveInt

			lea		esi, intList

	readIntList:inc	 cntNumInt
			mov		eax, cntNumInt
			cmp		totalNumInt, eax
			js		printNumLoop//如果 totalNumInt 小于 cntNumInt，说明已经输入的正整数个数超过了设定的总个数，此时程序将跳转到 printNumLoop 标签处执行相应的操作，否则继续执行下一条指令。

			push	eax
			lea		eax, msgEnterPositiveInt
			push	eax
			call	printf
			add		esp, 8

			lea		eax, positiveInt
			push	eax
			lea		eax, format
			push	eax
			call	scanf_s
			add		esp, 8

			cmp		positiveInt, 0
			js		printNumLoop

			mov		eax, positiveInt
			mov [esi], eax
			add		esi, 4

			jmp		readIntList

	printNumLoop :dec	cntNumInt
			mov		ebx, cntNumInt
			push	ebx
			lea		ebx, msgProgEnds
			push	ebx
			call	printf
			add		esp, 8

			mov		ecx, cntNumInt
			cmp		ecx, 0
			je		finish
			cmp		ecx, 1
			je		printSortedIntMsg
			dec		ecx

	        push ecx
			lea	esi, intList

	L2:mov	eax, [esi]
			cmp [esi + 4], eax
			jge		L3
			xchg	eax, [esi + 4]//xchg 交换俩个操作数的值
			mov[esi], eax
	L3 :add	esi, 4
			loop	L2
			pop		ecx

	printSortedIntMsg :lea	eax, msgListInt
			push	eax
			call	printf
			add		esp, 4

			mov		ebx, cntNumInt
			dec		ebx
			lea		esi, intList

	printSortedInt:cmp	ebx, 0
			js		printTotalAmt

			mov		eax, [esi]
			push	eax
			lea		eax, format
			push	eax
			call	printf
			add		esp, 8

			cmp		ebx, 1
			js		skipLastComma

			lea		eax, msgComma
			push	eax
			call	printf
			add		esp, 4

	skipLastComma:add	esi, 4
			dec		ebx
			jmp		printSortedInt

	printTotalAmt :lea	edi, intList
			mov		ecx, cntNumInt
			mov		eax, totalAmt

	addPositiveInt :add		eax, [edi]
			add		edi, 4
			loop	addPositiveInt

			push	eax
			lea		ebx, msgTotalAmt
			push	ebx
			call	printf
			add		esp, 8

	finish:
	}

	return 0;
}