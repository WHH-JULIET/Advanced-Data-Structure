
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX], maxStack[MAX], minStack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = x;

    if (top == 0) {
        maxStack[top] = x;
        minStack[top] = x;
    } else {
        if (x > maxStack[top - 1])
            maxStack[top] = x;
        else
            maxStack[top] = maxStack[top - 1];

        if (x < minStack[top - 1])
            minStack[top] = x;
        else
            minStack[top] = minStack[top - 1];
    }

    printf("%d pushed into stack\n", x);
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }

    int x = stack[top];
    top--;

    printf("Popped element: %d\n", x);
    return x;
}

int max() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }

    return maxStack[top];
}

int min() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }

    return minStack[top];
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    printf("\nMaximum element: %d\n", max());
    printf("Minimum element: %d\n", min());
}

int main() {
    int choice, x;

    while (1) {
        printf("\n--- MIN-MAX STACK ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Find Maximum\n");
        printf("4. Find Minimum\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice) ;

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x) 
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                if (top != -1)
                    printf("Maximum: %d\n", max());
                else
                    printf("Stack is empty\n");
                break;

            case 4:
                if (top != -1)
                    printf("Minimum: %d\n", min());
                else
                    printf("Stack is empty\n");
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

