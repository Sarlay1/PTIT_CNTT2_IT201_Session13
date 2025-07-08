#include <stdio.h>

int laCapNgoacDung(char mo, char dong) {
    return (mo == '(' && dong == ')') ||
           (mo == '[' && dong == ']') ||
           (mo == '{' && dong == '}');
}

int kiemTraNgoac(char str[]) {
    char stack[1000];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == -1 || !laCapNgoacDung(stack[top--], c)) {
                return 0;
            }
        }
    }

    return top == -1;
}

int main() {
    char str[100];
    printf("Nhap bieu thuc: ");
    fgets(str, sizeof(str), stdin);

    if (kiemTraNgoac(str)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
