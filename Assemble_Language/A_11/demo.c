#include <stdio.h>
#include <string.h>


#define MAX_SZ 6

int main()
{
	char myArray[MAX_SZ] = "Hello";
	char newArray[MAX_SZ];
	memset(newArray, 0, sizeof(newArray));		//memset �������ǽ����� newArray ��ÿ���ֽڶ�����Ϊ 0��ͨ������ newArray ��ָ����Ϊ��һ��������0 ��Ϊ�ڶ����������Լ� sizeof(newArray) ��Ϊ������������memset(newArray, 0, sizeof(newArray)) ���Ὣ newArray �����е�ÿ���ֽڶ�����Ϊ 0��ȷ�� newArray �����е�ÿ��Ԫ�ض�����ʼ��Ϊ null �ַ����Է�ֹ�ں��������г���δ�������Ϊ��

	_asm {
		mov		ecx, MAX_SZ - 1
		mov		esi, 0

		pushIt:movzx eax, myArray[esi]
			push	eax
			inc		esi//ע������ char һ���ֽ�����ֻ��1
			loop	pushIt

			mov		ecx, MAX_SZ - 1
			mov		esi, 0

		popIt :pop	eax
			mov		newArray[esi], al//al��ʾ�Ͱ�λ ���ۼ�������λ����ͬ
			inc		esi
			loop	popIt

			lea		eax, newArray
			push	eax
			call	printf
			add		esp, 4
	}
	return 0;
}
