/*
#include <stdio.h>
int main(void){
	char format[] = "%d";
	int input;
	_asm{
		lea eax,input
		push eax
		lea eax, format
		push eax
		call scanf    //scanf_s����
		add esp,8
		}
	}
*/

#include <stdio.h>

int main(void)
{
	char message[] = "Your number is %i\n";  //%i �������ֵת��Ϊ��������ȡ��
	char format[] = "%d";
	int input;
	int sum1;
	int sum2;
	_asm {
		lea eax, input
		push eax
		lea eax, format
		push eax
		mov sum1, eax
		call scanf
		add esp, 8
		mov sum2, eax
		push input
		lea eax, message
		push eax
		call printf
		add esp, 8
	}
	printf("%d\n", sum2);
	printf("%d\n", sum1);
	return 0;
}
