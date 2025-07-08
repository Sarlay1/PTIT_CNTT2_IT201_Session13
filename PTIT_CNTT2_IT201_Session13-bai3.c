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
        return;
    }
    stack->top++;
    stack->array[stack->top] = value;
}
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Không có phần tử trong ngăn xếp\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int main() {
    struct Stack* stack = createStack(5);
    int value;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &value);
        push(stack, value);
    }

    int result = pop(stack);
    if (result != -1) {
        printf("%d\n", result);
    }

    free(stack->array);
    free(stack);
    return 0;
}
