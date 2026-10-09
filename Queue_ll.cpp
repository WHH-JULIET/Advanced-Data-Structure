#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};


struct node *front=NULL;
struct node *rear=NULL;



// Enqueue operation
void enqueue(int x)
{
    struct node *newNode;


    newNode=(struct node*)malloc(sizeof(struct node));


    // Memory overflow condition
    if(newNode==NULL)
    {
        printf("Memory Overflow! Cannot insert\n");
        return;
    }


    newNode->data=x;
    newNode->next=NULL;



    // First element
    if(front==NULL)
    {
        front=rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }


    printf("%d inserted into queue\n",x);
}




// Dequeue operation
void dequeue()
{
    struct node *temp;


    // Queue underflow
    if(front==NULL)
    {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }


    temp=front;


    printf("Deleted element: %d\n",temp->data);


    front=front->next;



    // Queue becomes empty
    if(front==NULL)
    {
        rear=NULL;
    }


    free(temp);
}

// Display operation
void display()
{
    struct node *temp;


    // Empty queue
    if(front==NULL)
    {
        printf("Queue is empty\n");
        return;
    }


    temp=front;


    printf("Queue elements:\n");


    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }


    printf("NULL\n");
}




// Free memory before exit
void destroy()
{
    struct node *temp;


    while(front!=NULL)
    {
        temp=front;
        front=front->next;
        free(temp);
    }


    rear=NULL;
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

            destroy();

            printf("Program ended\n");

            exit(0);



        default:

            printf("Invalid choice! Enter 1-5\n");

        }

    }


    return 0;
}
