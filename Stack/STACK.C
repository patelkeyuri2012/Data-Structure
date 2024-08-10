#include<stdio.h>
#define MAX 4

int top = -1, stack[MAX];

void push();
void pop();
void peek();
void show();

int main()
{
    int choice;

    while (choice<5)
    {
        printf("\nSelect operations of the stack that you want to perform:\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1.Push the element\n2.Pop the element\n3.Show last element of Stack\n4.Show all the element of Stack");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            show();
            break;

        default:
            printf("\nInvalid choice!!");
        }
    }
}

void push()
{
    int x;

    if (top == MAX - 1)
    {
        printf("\nStack is Full!!\n");
    }
    else
    {
        printf("\nEnter the elements that you want to add : ");
        scanf("%d", &x);
        top = top + 1;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack is Empty!!\n");
    }
    else
    {
        printf("\nPopped element is : %d\n", stack[top]);
        top = top - 1;
    }
}

void peek()
{
	if (top == -1)
    {
        printf("\nStack is Empty!!\n");
    }
    else
    {
        printf("\nLast elements of stack is :");
        printf("%3d", stack[top]);
        printf("\n");
    }
}

void show()
{
    if (top == -1)
    {
        printf("\nStack is Empty!!\n");
    }
    else
    {
        printf("\nElements of stack is :");
        for (int i = top; i >= 0; --i)
            printf("%3d", stack[i]);
            printf("\n");
    }
}



