#include <stdio.h>
#include <stdlib.h>

int get_max(int *input, int size);
int get_min(int *input, int size);

int main()
{
    int input[5];
    char buf[25];
    char *end_ptr;
    int i;

    printf("수 입력\n");
    for (i = 0; i < sizeof(input) / sizeof(*input); i++) {
        if (fgets(buf, sizeof(buf), stdin) != NULL) {
            input[i] = (int)strtol(buf, &end_ptr, 10);
        }
    }
    printf("최댓값 :%d\n", get_max(input, sizeof(input) / sizeof(*input)));
    printf("최솟값 :%d\n", get_min(input, sizeof(input) / sizeof(*input)));

    return 0;
}

int get_max(int *input, int size)
{
    int max = input[0];
    int i;

    for (i = 0; i < size; i++) {
        if (max < input[i]) {
            max = input[i];
        }
    }
    return max;
}

int get_min(int *input, int size)
{
    int min = input[0];
    int i;

    for (i = 0; i < size; i++) {
        if (min > input[i]) {
            min = input[i];
        }
    }
    return min;
}
