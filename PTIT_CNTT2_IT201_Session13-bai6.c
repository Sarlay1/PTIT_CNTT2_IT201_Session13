#include <stdio.h>


int doiXung(char str[]) {
    char stack[100];
    int top = -1;
    int i = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] != ' ') {
            stack[++top] = str[i];
        }
        i++;
    }


    for (int j = 0; j < i; j++) {
        if (str[j] != stack[top--]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char chuoi[100];

    printf("Nhap chuoi: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    if (doiXung(chuoi)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
