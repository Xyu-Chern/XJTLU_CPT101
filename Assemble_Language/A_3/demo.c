
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
        movsx eax, word ptr intValue; ��16λ��intValue��չΪ32λ
        lea ecx, format; װ��format�ĵ�ַ��ecx�Ĵ���
        push eax; ����չ���32λֵ���͵�ջ��
        push ecx; ��format�ĵ�ַ���͵�ջ��
        call printf; ����printf����
        add esp, 8; �ͷ�ջ�ռ�
    }

    return 0;
}


*/