#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char format[] = "Hello World\n"; // 1
    _asm {
        mov ecx, 10       // ��ʼ��ѭ��������
   Lj : push ecx         // ��ѭ�����������浽ջ��
        lea eax, format   // װ������ĵ�ַ
        push eax        // �ַ����ĵ�ַ����Ϊջ����
        call printf       // ����printf�⺯��
        add esp, 4      // ����ջ�ϵ�4�ֽڲ���
        pop ecx         // �ָ�ѭ����������׼�����в���
        loop Lj          // ECX�ݼ������ECX����������Lj
    }

    return 0;
}