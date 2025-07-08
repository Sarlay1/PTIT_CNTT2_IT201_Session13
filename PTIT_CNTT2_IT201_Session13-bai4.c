#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int capacity;
    int top;
    int *array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) {
        printf("khong thêm phần tử, ngăn xếp đầy.\n");
        return;
    }
    stack->top++;
    stack->array[stack->top] = value;
}


void xemStack(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Ngăn xếp trống.\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->array[i]);
    }
}

int main() {
    struct Stack* stack = createStack(5);
    int value;

    printf("Nhap 5 phần tu:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &value);
        push(stack, value);
    }

    xemStack(stack);

    free(stack->array);
    free(stack);
    return 0;
}
