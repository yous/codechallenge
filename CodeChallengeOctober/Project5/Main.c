#include <stdio.h>
#include <stdlib.h>

enum Direction {
    East, South, West, North
};

void move(enum Direction dir, short *x, short *y);

int main()
{
    short *field;
    char buf[25];
    char *end_ptr;
    short size;
    short i, j, x = 0, y = 0;
    enum Direction dir = East;

    printf("Please enter any value for nXn array :  ");
    if (fgets(buf, sizeof(buf), stdin) != NULL) {
        size = (short)strtol(buf, &end_ptr, 10);
    }
    field = (short *)calloc(size * size, sizeof(short));

    for (i = 1; i <= size * size; i++) {
        field[y * size + x] = i;
        switch (dir) {
        case East:
            if (x == size - 1 || field[y * size + x + 1] != 0) {
                dir = South;
            }
            break;
        case South:
            if (y == size - 1 || field[(y + 1) * size + x] != 0) {
                dir = West;
            }
            break;
        case West:
            if (x == 0 || field[y * size + x - 1] != 0) {
                dir = North;
            }
            break;
        case North:
            if (y == 0 || field[(y - 1) * size + x] != 0) {
                dir = East;
            }
            break;
        }
        move(dir, &x, &y);
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%4d", field[i * size + j]);
        }
        printf("\n");
    }

    free(field);

    return 0;
}

void move(enum Direction dir, short *x, short *y)
{
    switch (dir) {
    case East:
        (*x)++;
        break;
    case South:
        (*y)++;
        break;
    case West:
        (*x)--;
        break;
    case North:
        (*y)--;
        break;
    }
}
