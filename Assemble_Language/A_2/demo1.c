#include <stdio.h>
#include <stdlib.h>

int main() {
    short myarray[5];
    myarray[0] = 1;
    myarray[1] = 3;
    myarray[2] = 5;
    myarray[3] = 7;
    myarray[4] = 9;
    short sum;
    _asm
    {
        mov ecx, 5
        mov ax, 0
        mov ebx, 0
  loop1:add ax, myarray[ebx]
        add ebx, 2
        loop loop1
        mov sum, ax
    }
    printf("Sum: %d\n", sum);
    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    int myarray[5];
    myarray[0] = 1;
    myarray[1] = 3;
    myarray[2] = 5;
    myarray[3] = 7;
    myarray[4] = 9;
    int sum;
    _asm
    {
        mov ecx, 5
        mov eax, 0
        mov ebx,0
   loop1:add eax,myarray[ebx]
        add ebx, 4    //why this is 4 not 1 like myarray[1]? I will explain next code.
        loop loop1
        mov sum, eax
    }
printf("Sum: %d\n", sum);
    return 0;
}
*/