
int front = -1, rear = -1, deque[MAX];

void insertionFront();
void insertionRear();
void deletionFront();
void deletionRear();
void traverse();

int main()
{
    int choice;

    while (choice<6)
    {
        printf("\nSelect operations on the deque that you want to perform:\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1. Add element at the front\n2. Add element at the rear\n3. Delete element from the front\n4. Delete element from the rear\n5. Show all elements");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertionFront();
            break;
        case 2:
            insertionRear();
            break;
        case 3:
            deletionFront();
            break;
        case 4:
            deletionRear();
            break;
        case 5:
            traverse();
            break;
        default:
            printf("\nInvalid choice!!");
        }
    }

    return 0;
}

void insertionFront()
{
    int a;

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("\nDeque is Full..!\n");
    }
    else
    {
        printf("\nEnter the element that you want to add at the front: ");
        scanf("%d", &a);

        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = MAX - 1;
        }
        else
        {
            front--;
        }
        deque[front] = a;
    }
}

void insertionRear()
{
    int a;

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("\nDeque is Full..!\n");
    }
    else
    {
        printf("\nEnter the element that you want to add at the rear: ");
        scanf("%d", &a);

        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else if (rear == MAX - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        deque[rear] = a;
    }
}

void deletionFront()
{
    if (front == -1 && rear == -1)
    {
        printf("\nDeque is Empty..!\n");
    }
    else
    {
        printf("\nDeleted element from the front: %d\n", deque[front]);

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

void deletionRear()
{
    if (front == -1 && rear == -1)
    {
        printf("\nDeque is Empty..!\n");
    }
    else
    {
        printf("\nDeleted element from the rear: %d\n", deque[rear]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = MAX - 1;
        }
        else
        {
            rear--;
        }
    }
}

void traverse()
{
    if (front == -1 && rear == -1)
    {
        printf("\nDeque is Empty..!\n");
    }
    else
    {
        printf("\nElements of Dedeque: ");
        int i = front;

        if (front <= rear)
        {
            while (i <= rear)
            {
                printf("%3d", deque[i]);
                i++;
            }
        }
        else
        {
            while (i < MAX)
            {
                printf("%3d", deque[i]);
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                printf("%3d", deque[i]);
                i++;
            }
        }
        printf("\n");
    }
}

