#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top=-1;

void push(int x)
{
    // Stack overflow condition
    if(top == MAX-1)
    {
        printf("Stack Overflow!");
        return;
    }

    stack[++top]=x;

    printf("%d pushed into the stack\n",x);
}


void pop()
{
    // Stack underflow condition
    if(top == -1)
    {
        printf("Stack Underflow! Stack is empty\n");
        return;
    }

    printf("%d popped from stack\n",stack[top]);

    top--;
}


void peek()
{
    // Empty stack condition
    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element is %d\n",stack[top]);
}


// Display operation
void display()
{
    int i;

    // Empty stack condition
    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }


    printf("Stack elements from top to bottom:\n");


    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}



int main()
{
    int choice,value;


    while(1)
    {
        printf("\n------STACK MENU------");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");


        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:

            printf("Enter value: ");
            scanf("%d",&value);

            push(value);

            break;



        case 2:

            pop();

            break;



        case 3:

            peek();

            break;



        case 4:

            display();

            break;

        case 5:

            printf("Program ended\n");
            break;

        default:

            printf("Invalid choice! Enter between 1-5\n");

        }

    }


    return 0;
}
