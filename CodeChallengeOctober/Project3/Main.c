#include <stdio.h>
#include <string.h>

int check_parentheses(char *input);

int main()
{
    char input[81];

    printf("코드 한 줄(80자 이내)을 입력해주세요.\n");
    fgets(input, 81, stdin);

    if (check_parentheses(input)) {
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}

int check_parentheses(char *input)
{
    unsigned i;
    int count = 0;

    for (i = 0; i < strlen(input); i++) {
        switch (input[i]) {
        case '(':
            count++;
            break;
        case ')':
            count--;
            break;
        }
        if (count < 0) {
            return 0;
        }
    }
    return (count == 0) ? 1 : 0;
}
