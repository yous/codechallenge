#include <stdio.h>
#include <string.h>

int main()
{
    char buf[1024];
    char chr;
    unsigned i;

    printf("문자열을 입력하세요: ");
    fgets(buf, 1024, stdin);

    printf("바뀐 문자열: ");
    for (i = 0; i < strlen(buf); i++) {
        chr = buf[i];
        if (65 <= chr && chr <= 90) {
            chr += 32;
        }
        else if (97 <= chr && chr <= 122) {
            chr -= 32;
        }
        printf("%c", chr);
    }

    return 0;
}
