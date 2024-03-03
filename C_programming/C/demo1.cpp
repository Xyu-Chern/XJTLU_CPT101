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
/* 所有的 C 语言程序都需要包含 main() 函数。 代码从 main() 函数开始执行。 */ 
/* printf() 用于格式化输出到屏幕。printf() 函数在 "stdio.h" 头文件中声明。 
stdio.h 是一个头文件(标准输入输出头文件), #include 是一个预处理命令，用来引入头文件。 当编译器遇到 printf() 函数时，如果没有找到 stdio.h 头文件，会发生编译错误。
return 0; 语句用于表示退出程序。*/