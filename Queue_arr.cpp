#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int q[MAX];

int front=-1;
int rear=-1;


// Enqueue operation
void enqueue(int x)
{
    // Queue overflow condition
    if(rear == MAX-1)
    {
        printf("Queue Overflow! Cannot insert element\n");
        return;
    }


    // First element
    if(front == -1)
    {
        front=0;
    }


    q[++rear]=x;


    printf("%d inserted into queue\n",x);
}



// Dequeue operation
void dequeue()
{
    // Queue underflow condition
    if(front==-1 || front>rear)
    {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }


    printf("Deleted element: %d\n",q[front]);


    front++;


    // Reset queue after deleting last element
    if(front>rear)
    {
        front=-1;
        rear=-1;
    }
}



// Display queue
void display()
{
    int i;


    // Empty queue
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }


    printf("Queue elements:\n");


    for(i=front;i<=rear;i++)
    {
        printf("%d ",q[i]);
    }


    printf("\n");
}


int main()
{
    int choice,value;


    while(1)
    {

        printf("\n------QUEUE MENU------");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");


        printf("\nEnter your choice: ");
        scanf("%d",&choice);



        switch(choice)
        {

        case 1:

            printf("Enter value: ");
            scanf("%d",&value);

            enqueue(value);

            break;



        case 2:

            dequeue();

            break;



        case 3:

            display();

            break;


        case 4:

            printf("Program ended\n");
            exit(0);



        default:

            printf("Invalid choice! Enter 1-5\n");

        }

    }


    return 0;
}
