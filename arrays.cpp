#include <stdio.h>

#define MAX 20

int a[MAX], n;

void insert(int x, int pos)
{
    int i;

    // Array full
    if(n >= MAX)
    {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    // Invalid position
    if(pos < 1 || pos > n + 1)
    {
        printf("Invalid insertion position\n");
        return;
    }

    // Insert at end
    if(pos == n + 1)
    {
        a[n] = x;
        n++;
    }
    else
    {
        // Shift elements right
        for(i = n - 1; i >= pos - 1; i--)
        {
            a[i + 1] = a[i];
        }

        a[pos - 1] = x;
        n++;
    }
}


void del(int pos)
{
    int i;

    // Empty array
    if(n == 0)
    {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    // Invalid position
    if(pos < 1 || pos > n)
    {
        printf("Invalid deletion position\n");
        return;
    }

    // Shift elements left
    for(i = pos - 1; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    n--;

    printf("Element deleted successfully\n");
}


void display()
{
    int i;

    if(n == 0)
    {
        printf("Array is empty\n");
        return;
    }

    printf("The array is: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}


int search(int x)
{
    int i;

    // Empty array
    if(n == 0)
    {
        return -1;
    }

    for(i = 0; i < n; i++)
    {
        if(a[i] == x)
            return i + 1;
    }

    return -1;
}


int main()
{
    int item, pos, ch, c, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);


    // Initial size check
    if(n > MAX || n < 0)
    {
        printf("Invalid array size\n");
        return 0;
    }


    printf("Enter the array elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }


    display();


    do
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Display");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);


        switch(ch)
        {
            case 1:

                printf("Enter element to insert: ");
                scanf("%d",&item);

                printf("Enter position: ");
                scanf("%d",&pos);

                insert(item,pos);
                display();

                break;


            case 2:

                printf("Enter position to delete: ");
                scanf("%d",&pos);

                del(pos);
                display();

                break;


            case 3:

                printf("Enter element to search: ");
                scanf("%d",&item);

                pos = search(item);

                if(pos != -1)
                    printf("%d found at position %d\n",item,pos);
                else
                    printf("%d not found\n",item);

                break;


            case 4:

                display();
                break;


            default:

                printf("Invalid choice\n");
        }


        printf("\nDo you want to continue? (1-Yes, 0-No): ");
        scanf("%d",&c);


    }while(c);


    return 0;
}
