#include <stdio.h>
#include <stdlib.h>

void prompt(int *num);
void print_line(int size);

int main()
{
    int num;
    int i;

    prompt(&num);
    while (num < 1 || num > 9) {
        printf("1~9 사이의 숫자로 다시 입력해주세요------------\n");
        prompt(&num);
    }

    for (i = 1; i <= 9; i++) {
        print_line(num * i);
    }
    return 0;
}

void prompt(int *num)
{
    char buf[25];
    char *end_ptr;

    printf("출력할 단을 입력해주세요: ");
    if (fgets(buf, sizeof(buf), stdin) != NULL) {
        *num = (int)strtol(buf, &end_ptr, 10);
    }
}

void print_line(int size)
{
    int i;

    for (i = 0; i < size; i++) {
        printf("*");
    }
    printf("\n");
}
