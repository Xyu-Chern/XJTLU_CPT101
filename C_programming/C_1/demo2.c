/*#include <stdio.h>
#include <limits.h>

int main()
{
	printf("int 存储大小 : %lu \n", sizeof(int));

	return 0;
}*/


#include <stdio.h>

/*变量的声明有两种情况：

1、一种是需要建立存储空间的。例如：int a 在声明的时候就已经建立了存储空间。
2、另一种是不需要建立存储空间的，通过使用extern关键字声明变量名而不定义它。 例如：extern int a 其中变量 a 可以在别的文件中定义的。*/

// 函数外定义变量 x 和 y
int x;
int y;
int addtwonum()
{
    // 函数内声明变量 x 和 y 为外部变量
    extern int x;
    extern int y;
    // 给外部变量（全局变量）x 和 y 赋值
    x = 4;
    y = 2;
    return x + y;
}

int main()
{
    int result;
    printf("%d\n",x);
    // 调用函数 addtwonum
    result = addtwonum();
    printf("result 为: %d\n", result);
    printf("%d", x);
    return 0;
}