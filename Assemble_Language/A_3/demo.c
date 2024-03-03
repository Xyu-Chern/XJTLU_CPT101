
#include <stdio.h>

int main(void)
{
	char format[] = "%d\n";
	int intValue = 157;
	_asm {
		push intValue
		lea eax, format
		push eax
		call printf
		add esp, 8
	}
	return 0;
}


/*
#include <stdio.h>

int main(void)
{
    char format[] = "%d\n";
    short intValue = 15;

    _asm {
        movsx eax, word ptr intValue; 将16位的intValue扩展为32位
        lea ecx, format; 装载format的地址到ecx寄存器
        push eax; 将扩展后的32位值推送到栈中
        push ecx; 将format的地址推送到栈中
        call printf; 调用printf函数
        add esp, 8; 释放栈空间
    }

    return 0;
}


*/