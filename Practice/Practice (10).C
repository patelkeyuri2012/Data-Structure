// 21. Write a program that creates, updates and display link list for customers of a computer vendor. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer
{
    int customerno;
    char customername[50];
    char computertype[50];
    struct Customer* next;
    struct Customer* prev;
};

struct Customer* head = NULL;

struct Customer* createNode(int customerno)
{
    struct Customer* newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
    if (newCustomer == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newCustomer->customerno = customerno;
    newCustomer->next = newCustomer;
    newCustomer->prev = newCustomer;
    return newCustomer;
}

void insertCustomer()
{
    int customerno;
    struct Customer* newCustomer;

    printf("\nEnter customer number : ");
    scanf("%d", &customerno);

    newCustomer = createNode(customerno);

    printf("Enter customer name : ");
    scanf("%s", newCustomer->customername);

    printf("Enter computer type  : ");
    scanf("%s", newCustomer->computertype);

    if (head == NULL)
    {
        head = newCustomer;
    } else
    {
        struct Customer* temp = head->prev;
        temp->next = newCustomer;
        newCustomer->prev = temp;
        newCustomer->next = head;
        head->prev = newCustomer;
    }

    printf("\nCustomer with customer number %d added\n", newCustomer->customerno);
}

void deleteCustomer(int customerno)
{
    if (head == NULL)
    {
        printf("\nCustomer list is empty\n");
        return;
    }

    struct Customer* current = head;
    struct Customer* prev = NULL;

    do
    {
        if (current->customerno == customerno)
        {
            if (current == head)
            {
                if (head->next == head)
                {
                    head = NULL;
                } else
                {
                    head = head->next;
                    current->prev->next = head;
                    head->prev = current->prev;
                }
            } else
            {
                prev->next = current->next;
                current->next->prev = prev;
            }
            free(current);
            printf("\nCustomer with customer number %d deleted\n", customerno);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != head);

    printf("\nCustomer with customer number %d not found\n", customerno);
}

void updateCustomer(int customerno)
{
    if (head == NULL)
    {
        printf("\nCustomer list is empty\n");
        return;
    }

    struct Customer* current = head;

    while (current != NULL && current->customerno != customerno)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("\nCustomer with customer number %d not found\n", customerno);
        return;
    }

    int choice;
    char newCustomerName[50];
    char newComputerType[50];

    printf("\nWhat do you want to update?\n");
    printf("1. Customer name\n2. Computer type\n3. Both\n");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1 :
            printf("\nEnter new customer name : ");
            scanf("%s", newCustomerName);
            strcpy(current->customername, newCustomerName);
            break;
        case 2 :
            printf("Enter new computer type : ");
            scanf("%s", newComputerType);
            strcpy(current->computertype, newComputerType);
            break;
        case 3 :
            printf("\nEnter new customer name : ");
            scanf("%s", newCustomerName);
            printf("Enter new computer type : ");
            scanf("%s", newComputerType);
            strcpy(current->customername, newCustomerName);
            strcpy(current->computertype, newComputerType);
            break;
        default :
            printf("\nInvalid choice..!\n");
            return;
    }

    printf("\nCustomer with customer number %d updated\n", customerno);
}

void displayCustomers()
{
    if (head == NULL)
    {
        printf("\nCustomer list is empty\n");
        return;
    }

    struct Customer* current = head;
    printf("\nCustomers of a computer vendor list :\n");

    do
    {
        printf("\nCustomer number : %d\nCustomer name : %s\nComputer type : %s\n", current->customerno, current->customername, current->computertype);
        current = current->next;
    } while (current != head);
}

int main()
{
    int choice, customerno;

    while (1)
    {
        printf("\nSelect option for customers of a computer vendor list :\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1. Insert customer data\n2. Delete customer data\n3. Update customer data\n4. Display customer list\n5. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertCustomer();
                break;
            case 2:
                if (head != NULL)
                {
                    printf("\nEnter customer number to delete : ");
                    scanf("%d", &customerno);
                    deleteCustomer(customerno);
                } else
                {
                    printf("\nCustomer list is empty\n");
                }
                break;
            case 3:
                printf("\nEnter customer number to update : ");
                scanf("%d", &customerno);
                updateCustomer(customerno);
                break;
            case 4:
                displayCustomers();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice..!\n");
        }
    }

    return 0;
}
