#include <stdio.h>

int math(char expr[]) {
    int stack[100];
    int top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (c == ' ' || c == '\n') continue;

        if (c >= '0' && c <= '9') {
            stack[++top] = c - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            int result;

            if (c == '+') result = a + b;
            else if (c == '-') result = a - b;
            else if (c == '*') result = a * b;
            else if (c == '/') result = a / b;

            stack[++top] = result;
        }
    }

    return stack[top];
}

int main() {
    char bieuThuc[100];
    printf("Nhap bieu thuc: ");
    fgets(bieuThuc, sizeof(bieuThuc), stdin);

    int result = math(bieuThuc);
    printf("Ket qua: %d\n", result);

    return 0;
}
