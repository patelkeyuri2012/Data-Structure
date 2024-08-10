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
    struct Node* current = *head;
    struct Node* previous = NULL;

    while(current != NULL && ele > current->ele) 
	{
        previous = current;
        current = current->next;
    }

    if(previous == NULL) 
	{
        newNode->next = *head;
        *head = newNode;
    } 
	else 
	{
        previous->next = newNode;
        newNode->next = current;
    }
}

void deletion(struct Node** head, int search) 
{
    struct Node* current = *head;
    struct Node* previous = NULL;

    if (current != NULL && current->ele == search) 
    {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->ele != search) 
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL) 
    {
        printf("\nElement not found in the linked list\n");
        return;
    }

    previous->next = current->next;
    free(current);
}

void display(struct Node* head) 
{
    struct Node* current = head;
    printf("\nElements of Linked List : \n\n");
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
        printf("\nSelect operations for the Sorted Linked List:\n");
   		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");     
        printf("\n1. Add an element to the Sorted Linked List\n2. Delete an element from the Sorted Linked List\n3. Display elements of the Sorted Linked List\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        
            case 1:
                printf("\nEnter element to insert: ");
                scanf("%d", &ele); 
                insertion(&head, ele)
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
                printf("\nInvalid choice..!!\n");
        }
    }
    return 0;
}
