// 24. Write a program that creates a linear linked list and displays it on the screen.

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int ele;
    struct Node* next;
};

struct Node* createNode(int ele) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("\nMemory allocation is failed\n");
        exit(1);
    }
    newNode->ele = ele;
    newNode->next = NULL;
    return newNode;
}

void insertion(struct Node** head, int ele) 
{
    struct Node* newNode = createNode(ele);
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        struct Node* current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(struct Node* head) 
{
    struct Node* current = head;
    printf("\nElements of linked list : \n\n");
    while (current != NULL) 
    {
        printf("%d -> ", current->ele);
        current = current->next;
    }
    printf("NULL\n");
}

int main() 
{
    struct Node* head = NULL;
    int choice, ele;

    while (1) 
    {
        printf("\nSelect operations for the linked list\n");
   		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");     
        printf("\n1. Insert an element to the linked list\n2. Display elements of the linked list\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d", &ele); 
                insertion(&head, ele);
                break;
            case 2:
                display(head);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice..!!\n");
        }
    }

    return 0;
}
