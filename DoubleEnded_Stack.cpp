
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int a[MAX], top1 = -1, top2 = MAX;

/* PUSH into Stack 1 */
void push1(int x) {
    // Both stacks share the same array
    if (top1 + 1 == top2) {
        printf("Stack Overflow: Array is full\n");
        return;
    }

    top1++;
    a[top1] = x;
    printf("%d pushed into Stack 1\n", x);
}

/* POP from Stack 1 */
void pop1() {
    if (top1 == -1) {
        printf("Stack 1 Underflow: Stack is empty\n");
        return;
    }

    printf("Popped element from Stack 1 is %d\n", a[top1]);
    top1--;
}

/* PUSH into Stack 2 */
void push2(int x) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow: Array is full\n");
        return;
    }

    top2--;
    a[top2] = x;
    printf("%d pushed into Stack 2\n", x);
}

/* POP from Stack 2 */
void pop2() {
    if (top2 == MAX) {
        printf("Stack 2 Underflow: Stack is empty\n");
        return;
    }

    printf("Popped element from Stack 2 is %d\n", a[top2]);
    top2++;
}

/* DISPLAY both stacks */
void display() {
    int i;

    printf("\nStack 1 elements (top to bottom): ");
    if (top1 == -1) {
        printf("Empty");
    } else {
        for (i = top1; i >= 0; i--) {
            printf("%d ", a[i]);
        }
    }

    printf("\nStack 2 elements (top to bottom): ");
    if (top2 == MAX) {
        printf("Empty");
    } else {
        for (i = top2; i < MAX; i++) {
            printf("%d ", a[i]);
        }
    }

    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("\n--- TWO STACKS MENU ---\n");
        printf("1. Push Stack 1\n");
        printf("2. Pop Stack 1\n");
        printf("3. Push Stack 2\n");
        printf("4. Pop Stack 2\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice) ;

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push1(x);
                break;

            case 2:
                pop1();
                break;

            case 3:
                printf("Enter element: ");
                scanf("%d", &x);
                push2(x);
                break;

            case 4:
                pop2();
                break;

            case 5:
                display();
                break;
            case 6:
                return 0;
                break;

            default:
                printf("Invalid choice. Enter 1 to 6\n");
        }
    }
}
