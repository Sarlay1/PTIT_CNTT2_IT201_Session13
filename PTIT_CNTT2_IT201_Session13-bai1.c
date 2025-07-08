#include <stdio.h>
#include <stdlib.h>

struct Stack {
int top;
int capacity;
int *array;
};

struct Stack *createStack(int maxSize) {
struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
stack->capacity = maxSize;
stack->top = -1;
stack->array = (int *)malloc(maxSize * sizeof(int));
return stack;}

void printStack(struct Stack *stack) {
printf("Stack capacity %d\n:", stack->capacity);
printf("Stack top %d\n", stack->top);
}

int main() {
    struct Stack* myStack = createStack(5);
    printStack(myStack);
    free(myStack->array);
    free(myStack);

    return 0;
}