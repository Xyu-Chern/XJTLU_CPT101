#include <stdio.h>
/*
#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'

int main()
{

	int area;

	area = LENGTH * WIDTH;
	printf("value of area : %d", area);

	
	�� printf �����У�% c ����ָ�����һ���ַ��������� printf ��ʹ��% c�����Ὣ�����ṩ�Ĳ�������Ϊһ���ַ����������ַ��������׼�����
	����Ĵ����У�printf("%c", NEWLINE) �����һ�����з�����Ϊ�㶨���� NEWLINE ������������ֵΪ '\n'���������з���
	���⣬�㻹����ʹ�� printf("%c", LENGTH) ������� LENGTH ��ֵ������ LENGTH ��һ����������������һ����Ч���ַ����������������ܲ���õ�Ԥ�ڵĽ���������������������� LENGTH ��ֵ��Ӧ��ʹ�� % d ��ʽ���Ʒ������� % c��
	

	printf("%c", NEWLINE);
	printf("%d", LENGTH);

	return 0;
}

������#define ����ĳ���û�����������ƣ����ڶ���֮������������ж���Ч���� const ����ĳ������п鼶������ֻ���䶨�����ڵ�����������Ч��
*/

int main()
{
	const int  LENGTH = 10;
	const int  WIDTH = 5;
	const char NEWLINE = '\n';
	int area;

	area = LENGTH * WIDTH;
	printf("value of area : %d", area);
	printf("%c", NEWLINE);

	return 0;
}