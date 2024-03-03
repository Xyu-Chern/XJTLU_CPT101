#include <stdio.h>

int main()
{
	char scanf_fmt[] = "%c";
	char printf_fmt[] = "%c\n";
	char character;

	_asm {
		push	1		//只读取字符串一个字符		
		lea		eax, character
		push	eax
		lea		eax, scanf_fmt
		push	eax
		call	   scanf_s
		add		esp, 12	//截止到目前完成在把输入的第一个字符存储给character

		movzx	eax, byte ptr[character]//character 变量所在的内存地址作为一个字节指针，ptr 关键字指示数据类型为指针，byte 关键字指示数据大小为一个字节
		//movzx 指令会将 byte ptr [character] 所指向的内存位置的值取出，并进行零拓展（zero extension），即在高位补零，然后将结果存储到 eax 寄存器中。这样做的目的是确保 eax 中的值为字符的 ASCII 码，因为 printf 函数需要将 ASCII 码作为参数进行打印。
		push	eax
		lea		eax, printf_fmt
		push	eax
		call	   printf
		add		esp, 8
	}
	return 0;
}