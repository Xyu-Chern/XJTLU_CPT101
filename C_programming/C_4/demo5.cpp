#include <stdio.h>
/*
int main() {
    int i;

    for (i = 0; i < 10; i++) {
        int day, year;
        char monthname[20];

        printf("Enter day-month-year in the format (e.g. 16 Feb 2007): ");
        scanf_s("%d %s %d", &day, monthname, sizeof(monthname), &year);

        printf("Entered date: %d %s %d\n", day, monthname, year);
    }

    return 0;
}
*/





int main(void) {
    char format[] = "Hello World\n";
    int i;
    for (i = 0; i < 10; i++) {
        printf("%c \n", format[i]);  // 注意这里的格式化字符串和修正了表达式
    }
    return 0;
}
