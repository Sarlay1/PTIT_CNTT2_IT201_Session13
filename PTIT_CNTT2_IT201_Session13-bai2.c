#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int capacity;
    int top;
    int *array;
};

struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(struct Stack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        printf("khong the them");
        return;
    }
    stack->top++;
    stack->array[stack->top] = value;
}

void printStack(struct Stack* stack) {
    printf("Stack: [");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d", stack->array[i]);
        if (i < stack->top) printf(", ");
    }
    printf("]\n");
}


int main() {
    struct Stack* myStack = createStack(5);
    int value;

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &value);
        push(myStack, value);
    }

    printStack(myStack);

    free(myStack->array);
    free(myStack);

    return 0;
}