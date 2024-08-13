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
        printf("\nSelect operations of the queue that you want to perform:\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1.Add the element\n2.Delete the element\n3.Show all the element of Queue");
        printf("\n\nEnter the choice: ");
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
            printf("\nInvalid choice!!");
        }
    }
}

void insertion()
{
	int a;
	if (rear == MAX-1)
	{
		printf("\nQueue is Full..!\n");
	}
	else
	{
		if(front == -1 && rear == -1)
		{
			printf("\nEnter the elements that you want to add : ");
			scanf("%d",&a);
			front = 0;
			rear = rear + 1;
			queue[rear] = a;
		}
		else
		{
			printf("\nEnter the elements that you want to add : ");
			scanf("%d",&a);
			rear = rear + 1;
			queue[rear] = a;
		}
	}	
}

void deletion()
{
	if(front == -1 && rear == -1)
	{
		printf("\nQueue is Empty..!\n");
	}
	else
	{
		if(front == rear)
		{
			printf("\nDeletion element : %d\n",queue[front]);
			front = rear = -1;
		}
		else
		{
			printf("\nDeletion element : %d\n",queue[front]);
			front = front + 1;	  
		}
	}
}

void traverse()
{
	if(front == -1 && rear == -1)
	{
		printf("\nQueue is Empty..!\n");
	}
	else
	{
		printf("\nElement of Queue : ");
		for (int i = front; i <= rear; i++)
			printf("%3d",queue[i]);
			printf("\n");
	}
}

