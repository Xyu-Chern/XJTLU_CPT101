/*#include <stdio.h>
#include <limits.h>

int main()
{
	printf("int �洢��С : %lu \n", sizeof(int));

	return 0;
}*/


#include <stdio.h>

/*���������������������

1��һ������Ҫ�����洢�ռ�ġ����磺int a ��������ʱ����Ѿ������˴洢�ռ䡣
2����һ���ǲ���Ҫ�����洢�ռ�ģ�ͨ��ʹ��extern�ؼ������������������������� ���磺extern int a ���б��� a �����ڱ���ļ��ж���ġ�*/

// �����ⶨ����� x �� y
int x;
int y;
int addtwonum()
{
    // �������������� x �� y Ϊ�ⲿ����
    extern int x;
    extern int y;
    // ���ⲿ������ȫ�ֱ�����x �� y ��ֵ
    x = 4;
    y = 2;
    return x + y;
}

int main()
{
    int result;
    printf("%d\n",x);
    // ���ú��� addtwonum
    result = addtwonum();
    printf("result Ϊ: %d\n", result);
    printf("%d", x);
    return 0;
}