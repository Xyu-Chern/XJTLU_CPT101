#include <stdio.h>

int main()
{
	char scanf_fmt[] = "%c";
	char printf_fmt[] = "%c\n";
	char character;

	_asm {
		push	1		//ֻ��ȡ�ַ���һ���ַ�		
		lea		eax, character
		push	eax
		lea		eax, scanf_fmt
		push	eax
		call	   scanf_s
		add		esp, 12	//��ֹ��Ŀǰ����ڰ�����ĵ�һ���ַ��洢��character

		movzx	eax, byte ptr[character]//character �������ڵ��ڴ��ַ��Ϊһ���ֽ�ָ�룬ptr �ؼ���ָʾ��������Ϊָ�룬byte �ؼ���ָʾ���ݴ�СΪһ���ֽ�
		//movzx ָ��Ὣ byte ptr [character] ��ָ����ڴ�λ�õ�ֵȡ��������������չ��zero extension�������ڸ�λ���㣬Ȼ�󽫽���洢�� eax �Ĵ����С���������Ŀ����ȷ�� eax �е�ֵΪ�ַ��� ASCII �룬��Ϊ printf ������Ҫ�� ASCII ����Ϊ�������д�ӡ��
		push	eax
		lea		eax, printf_fmt
		push	eax
		call	   printf
		add		esp, 8
	}
	return 0;
}