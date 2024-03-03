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

	
	在 printf 函数中，% c 用于指定输出一个字符。当你在 printf 中使用% c，它会将后面提供的参数解释为一个字符，并将该字符输出到标准输出。
	在你的代码中，printf("%c", NEWLINE) 将输出一个换行符，因为你定义了 NEWLINE 常量并设置其值为 '\n'，它代表换行符。
	另外，你还尝试使用 printf("%c", LENGTH) 输出常量 LENGTH 的值。但是 LENGTH 是一个整数常量，不是一个有效的字符，所以这个输出可能不会得到预期的结果。如果你想输出整数常量 LENGTH 的值，应该使用 % d 格式控制符而不是 % c。
	

	printf("%c", NEWLINE);
	printf("%d", LENGTH);

	return 0;
}

作用域：#define 定义的常量没有作用域限制，它在定义之后的整个代码中都有效。而 const 定义的常量具有块级作用域，只在其定义所在的作用域内有效。
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