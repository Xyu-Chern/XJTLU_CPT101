#include <stdio.h>
#include <string.h>


#define MAX_SZ 6

int main()
{
	char myArray[MAX_SZ] = "Hello";
	char newArray[MAX_SZ];
	memset(newArray, 0, sizeof(newArray));		//memset 的作用是将数组 newArray 的每个字节都设置为 0。通过传递 newArray 的指针作为第一个参数，0 作为第二个参数，以及 sizeof(newArray) 作为第三个参数，memset(newArray, 0, sizeof(newArray)) 将会将 newArray 数组中的每个字节都设置为 0。确保 newArray 数组中的每个元素都被初始化为 null 字符，以防止在后续操作中出现未定义的行为。

	_asm {
		mov		ecx, MAX_SZ - 1
		mov		esi, 0

		pushIt:movzx eax, myArray[esi]
			push	eax
			inc		esi//注意这里 char 一个字节所以只加1
			loop	pushIt

			mov		ecx, MAX_SZ - 1
			mov		esi, 0

		popIt :pop	eax
			mov		newArray[esi], al//al表示低八位 的累加器保持位数相同
			inc		esi
			loop	popIt

			lea		eax, newArray
			push	eax
			call	printf
			add		esp, 4
	}
	return 0;
}
