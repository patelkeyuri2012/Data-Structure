// 25. Write a program to insert an item before specified node in a linked list.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("\nMemory allocation is failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode() {
    int newData;
    printf("\nEnter the element to insert : ");
    scanf("%d", &newData);
    if (head == NULL) {
        head = createNode(newData);
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createNode(newData);
    }
}

void insertBefore(int newData, int beforeData) {
    struct Node *newNode, *current, *previous;
    newNode = createNode(newData);

    previous = NULL;
    current = head;

    while (current != NULL && current->data != beforeData) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\nNode with data %d not found\n", beforeData);
        free(newNode);
        return;
    }

    if (previous == NULL) {
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = current;
        previous->next = newNode;
    }

    printf("\nNode with data %d inserted before node with data %d\n", newData, beforeData);
}

void freeList() {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void display() {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, newData, beforeData;

    while (1) {
        printf("\nSelect operations for the linked list :\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1. Regular insertion in the linked list\n2. Before specified node insertion in the linked list\n3. Display elements of the linked list\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertNode();
                break;
            case 2:
            	printf("\n");
                display();
                printf("\nEnter the element to insert : ");
                scanf("%d", &newData);
                printf("\nEnter the before element: ");
                scanf("%d", &beforeData);
                insertBefore(newData, beforeData);
                break;
            case 3:
            	printf("\nElements of linked list : \n\n");
                display();
                break;
            case 4:
                freeList();
                exit(0);
            default:
                printf("\nInvalid choice..!\n");
        }
    }

    return 0;
}
