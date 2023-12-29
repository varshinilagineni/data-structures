#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
struct Stack {
    int arr[MAX_SIZE];
    int top;
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d.\n", data);
        return;
    }
    stack->arr[++stack->top] = data;
    printf("%d pushed to stack.\n", data);
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}
int main() {
    struct Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    display(stack);

    printf("Popped element: %d\n", pop(stack));
    display(stack);

    return 0;
}
