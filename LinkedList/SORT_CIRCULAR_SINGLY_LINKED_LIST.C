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
        printf("\nMemory allocation failed\n");
        exit(1);
    }
    newNode->ele = ele;
    newNode->next = NULL;
    return newNode;
}

void sortedInsert(struct Node** head, int ele) 
{
    struct Node* newNode = createNode(ele);

    if (*head == NULL) 
    {
        *head = newNode;
        newNode->next = *head;
    } 
    else if (ele < (*head)->ele) 
    {
        struct Node* current = *head;
        while (current->next != *head) 
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
        *head = newNode;
    } 
    else 
    {
        struct Node* current = *head;
        while (current->next != *head && current->next->ele < ele) 
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deletion(struct Node** head, int search) 
{
    if (*head == NULL) 
    {
        printf("Circular Linked List is empty\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    while (current->next != *head && current->ele != search) 
    {
        previous = current;
        current = current->next;
    }

    if (current->ele != search) 
    {
        printf("\nElement not found in the circular linked list\n");
        return;
    }

    if (current == *head) 
    {
        *head = current->next;

        struct Node* last = *head;
        while (last->next != current)
        {
            last = last->next;
        }
        last->next = *head;
    } 
    else 
    {
        previous->next = current->next;
    }

    free(current);
}

void display(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("\nCircular Linked List is empty\n");
        return;
    }

    struct Node* current = head;
    printf("\nElements of Linked List : \n\n");
    do 
    {
        printf("%d -> ", current->ele);
        current = current->next;
    } while (current != head);

    printf("\nthe pointer will go to the beginning\n");
}

int main() 
{
    struct Node* head = NULL;
    int choice, ele;

    while (1) 
    {
        printf("\nSelect operations for the Sorted Circular Linked List:\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");     
        printf("\n1. Add an element to the Sorted Circular Linked List\n2. Delete an element from the Sorted Circular Linked List\n3. Display elements of the Sorted Circular Linked List\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d", &ele);
                if(ele == 0)
                {
	                printf("Please enter only interger element");
	            }
	            else
	            {
	            	sortedInsert(&head, ele);
				}
                break;
            case 2:
                printf("\nEnter element to delete: ");
                scanf("%d", &ele);
                deletion(&head, ele);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}
