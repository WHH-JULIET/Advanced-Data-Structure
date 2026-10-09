#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;


// Insert at beginning
void ins_beg(int x)
{
    struct node *temp;

    temp=(struct node*)malloc(sizeof(struct node));

    if(temp==NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    temp->data=x;
    temp->next=head;
    head=temp;
}


// Insert at end
void ins_end(int x)
{
    struct node *temp,*t;

    temp=(struct node*)malloc(sizeof(struct node));

    if(temp==NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    temp->data=x;
    temp->next=NULL;


    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        t=head;

        while(t->next!=NULL)
            t=t->next;

        t->next=temp;
    }
}


// Insert at position
void ins_pos(int x,int pos)
{
    struct node *temp,*t;
    int c=1;


    // Invalid position
    if(pos<1)
    {
        printf("Invalid position\n");
        return;
    }


    // Insert at beginning
    if(pos==1)
    {
        ins_beg(x);
        return;
    }


    temp=(struct node*)malloc(sizeof(struct node));

    if(temp==NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }


    temp->data=x;
    temp->next=NULL;


    t=head;


    while(t!=NULL && c<pos-1)
    {
        t=t->next;
        c++;
    }


    // Position greater than list length
    if(t==NULL)
    {
        printf("Invalid position\n");
        free(temp);
        return;
    }


    temp->next=t->next;
    t->next=temp;

}



// Delete beginning
void del_beg()
{
    struct node *t;


    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }


    t=head;
    head=head->next;

    printf("\nDeleted node info is %d",t->data);

    free(t);
}



// Delete end
void del_end()
{
    struct node *t,*prev;


    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }


    // Only one node
    if(head->next==NULL)
    {
        printf("\nDeleted node info is %d",head->data);
        free(head);
        head=NULL;
        return;
    }


    t=head;


    while(t->next!=NULL)
    {
        prev=t;
        t=t->next;
    }


    printf("\nDeleted node info is %d",t->data);

    prev->next=NULL;

    free(t);
}



// Delete at position
void del_pos(int pos)
{
    struct node *t,*temp;
    int c=1;


    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }


    // Delete first node
    if(pos==1)
    {
        del_beg();
        return;
    }


    if(pos<1)
    {
        printf("Invalid position\n");
        return;
    }


    t=head;


    while(t!=NULL && c<pos-1)
    {
        t=t->next;
        c++;
    }


    // Invalid position
    if(t==NULL || t->next==NULL)
    {
        printf("Invalid position\n");
        return;
    }


    temp=t->next;

    printf("\nDeleted node info is %d",temp->data);


    t->next=temp->next;

    free(temp);

}



// Display
void display()
{
    struct node *t=head;


    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }


    printf("\nList: ");

    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
}



// Search
int search(int k)
{
    struct node *t=head;
    int c=1;


    if(head==NULL)
        return -1;


    while(t!=NULL)
    {
        if(t->data==k)
            return c;

        t=t->next;
        c++;
    }


    return -1;
}



int main()
{
    int ch,c,x,pos;


    do
    {

    printf("\n\n1.Insert Beginning");
    printf("\n2.Insert End");
    printf("\n3.Insert Position");
    printf("\n4.Delete Beginning");
    printf("\n5.Delete End");
    printf("\n6.Delete Position");
    printf("\n7.Search");


    printf("\nEnter your choice: ");
    scanf("%d",&ch);



    switch(ch)
    {

    case 1:
        printf("Enter element: ");
        scanf("%d",&x);

        ins_beg(x);
        display();
        break;



    case 2:
        printf("Enter element: ");
        scanf("%d",&x);

        ins_end(x);
        display();
        break;



    case 3:
        printf("Enter element and position: ");
        scanf("%d%d",&x,&pos);

        ins_pos(x,pos);
        display();
        break;



    case 4:
        del_beg();
        display();
        break;



    case 5:
        del_end();
        display();
        break;



    case 6:
        printf("Enter position: ");
        scanf("%d",&pos);

        del_pos(pos);
        display();
        break;



    case 7:
        printf("Enter element to search: ");
        scanf("%d",&x);


        pos=search(x);


        if(pos!=-1)
            printf("%d found at position %d",x,pos);
        else
            printf("%d not found",x);

        break;



    default:
        printf("Invalid choice");

    }


    printf("\nContinue? (1-Yes 0-No): ");
    scanf("%d",&c);


    }while(c);


    return 0;
}
