
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL, *temp;

/* PUSH: Insert an element */
void push(int x) {
    temp = (struct node *)malloc(sizeof(struct node));

    // Edge case 1: Memory allocation failure
    if (temp == NULL) {
        printf("Stack Overflow: Memory allocation failed\n");
        return;
    }

    temp->data = x;
    temp->next = top;
    top = temp;

    printf("%d pushed into stack\n", x);
}

/* POP: Remove the top element */
void pop() {
    // Edge case 2: Empty stack
    if (top == NULL) {
        printf("Stack Underflow: Stack is empty\n");
        return;
    }

    temp = top;
    int x = temp->data;

    top = top->next;

    printf("Popped element is %d\n", x);
    free(temp);

    // Edge case 3: Last element removed
    // top automatically becomes NULL
}

/* PEEK: View the top element */
int peek() {
    // Edge case 4: Peek on an empty stack
    if (top == NULL) {
        printf("Stack is empty. No top element.\n");
        return 0;
    }

    return top->data;
}

/* DISPLAY: Print all elements */
void display() {
    // Edge case 5: Display an empty stack
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    printf("Stack (top to bottom): ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

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
                if (top != NULL) {
                    printf("Top element is %d\n", peek());
                } else {
                    peek();
                }
                break;

            case 4:
                display();
                break;

            
            default:
                printf("Invalid choice. Enter 1 to 5.\n");
        }
    }
}

