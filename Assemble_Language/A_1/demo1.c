#include <stdio.h>
#include <stdlib.h>

int main() {
    int myarray[5]; // declaration of an array of integers
    myarray[0] = 1;
    myarray[1] = 3;
    myarray[2] = 5;
    myarray[3] = 7;
    myarray[4] = 9;
    int sum;
    _asm
    {
        lea ebx, myarray
        mov ecx, 5
        mov eax, 0
        loop1:add eax, [ebx]
        add ebx, 4
        loop loop1
        mov sum, eax
    }
    printf("Sum: %d\n", sum);
    return 0;
}







