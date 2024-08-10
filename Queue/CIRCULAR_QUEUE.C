#include<stdio.h>
#define MAX 4

int front = -1, rear = -1, queue[MAX];

void insertion();
void deletion();
void traverse();

int main()
{
    int choice;

    while (choice<4) 
    {
        printf("\nSelect operations on the circular queue:\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1. Add element\n2. Delete element\n3. Show all elements in the queue");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            traverse();
            break;
        default:
            printf("Invalid choice!!\n");
        }
    }
}

void insertion()
{
    int a;

    if ((rear == MAX - 1 && front == 0) || (rear == front - 1))
    {
        printf("\nQueue is Full..!\n");
    }
    else
    {
        printf("\nEnter the element that you want to add: ");
        scanf("%d", &a);

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == MAX - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear] = a;
    }
}

void deletion()
{
    if (front == -1)
    {
        printf("\nQueue is Empty..!\n");
    }
    else
    {
        printf("\nDeleted element: %d\n", queue[front]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

void traverse()
{
    if (front == -1)
    {
        printf("\nQueue is Empty..!\n");
    }
    else
    {
        printf("\nElements of the Circular Queue: ");
        int i = front;

        if (front <= rear)
        {
            while (i <= rear)
            {
                printf("%3d", queue[i]);
                i++;
            }
        }
        else
        {
            while (i < MAX)
            {
                printf("%3d", queue[i]);
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                printf("%3d", queue[i]);
                i++;
            }
        }
        printf("\n");
    }
}

