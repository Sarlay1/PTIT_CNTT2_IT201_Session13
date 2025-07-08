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
    if (stack->top == stack->capacity - 1) return;
    stack->array[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (stack->top == -1) return -1;
    return stack->array[stack->top--];
}

void daoNguocMang(int arr[], int n) {
    struct Stack* stack = createStack(n);

    for (int i = 0; i < n; i++) {
        push(stack, arr[i]);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = pop(stack);
    }

    free(stack->array);
    free(stack);
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    daoNguocMang(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");

    return 0;
}
