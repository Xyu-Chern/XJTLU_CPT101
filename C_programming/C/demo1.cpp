#include <stdio.h>
int max = 100;
void main() {
	int x;
	x = 1;
	while (x <= max) {
		printf("%d\n", x);
		x++;
	}
}

/*
#include <stdio.h>

int main()
{
	printf("Hello, World! \n");

	return 0;
}*/
/* ���е� C ���Գ�����Ҫ���� main() ������ ����� main() ������ʼִ�С� */ 
/* printf() ���ڸ�ʽ���������Ļ��printf() ������ "stdio.h" ͷ�ļ��������� 
stdio.h ��һ��ͷ�ļ�(��׼�������ͷ�ļ�), #include ��һ��Ԥ���������������ͷ�ļ��� ������������ printf() ����ʱ�����û���ҵ� stdio.h ͷ�ļ����ᷢ���������
return 0; ������ڱ�ʾ�˳�����*/