#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char format[] = "Hello World\n"; // 1
    _asm {
        mov ecx, 10       // 初始化循环计数器
   Lj : push ecx         // 将循环计数器保存到栈中
        lea eax, format   // 装载数组的地址
        push eax        // 字符串的地址，作为栈参数
        call printf       // 调用printf库函数
        add esp, 4      // 清理栈上的4字节参数
        pop ecx         // 恢复循环计数器，准备进行测试
        loop Lj          // ECX递减，如果ECX非零则跳回Lj
    }

    return 0;
}