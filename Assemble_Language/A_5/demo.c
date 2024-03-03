#include <stdio.h>
#include <stdlib.h>

//只是展现部分代码21-22
int main(void)
{
    int intArray[] = { 3,2,1 };
    _asm {
        lea esi, intArray
      
        L1 : mov eax, [esi]
            cmp [esi + 4], eax
            jg L2
            mov eax, [esi + 4]
            mov [esi], eax
        L2 : add esi, 4
            jmp L1
    }
    for (int i = 0; i < 3; i++) {
        printf("%d ", intArray[i]);
    }

    return 0;
}