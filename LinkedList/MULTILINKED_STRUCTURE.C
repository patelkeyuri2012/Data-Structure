#include <stdio.h>
#include <stdlib.h>

struct graphnode
{
    int rownum;
    int columnnum;
    int val;
    struct graphnode *next;
};

struct graphnode *insertion(struct graphnode *head, int row, int column, int value)
{
    struct graphnode *newNode = (struct graphnode *)malloc(sizeof(struct graphnode));

    if (newNode != NULL)
    {
        newNode->rownum = row;
        newNode->columnnum = column;
        newNode->val = value;
        newNode->next = head;
        head = newNode;
    }
    else
    {
        printf("Memory allocation failed\n");
    }
    return head;
}

void display(struct graphnode *head)
{
    int maxRow = 0, maxColumn = 0;
    struct graphnode *current = head;

    while (current != NULL)
    {
        if (current->rownum > maxRow)
        {
            maxRow = current->rownum;
        }
        if (current->columnnum > maxColumn)
        {
            maxColumn = current->columnnum;
        }
        current = current->next;
    }

    int **matrix = (int **)malloc((maxRow + 1) * sizeof(int *));
    for (int i = 0; i <= maxRow; ++i)
    {
        matrix[i] = (int *)malloc((maxColumn + 1) * sizeof(int));
        for (int j = 0; j <= maxColumn; ++j)
        {
            matrix[i][j] = 0;
        }
    }

    current = head;
    while (current != NULL)
    {
        matrix[current->rownum][current->columnnum] = current->val;
        current = current->next;
    }

    for (int i = 0; i <= maxRow; ++i)
    {
        for (int j = 0; j <= maxColumn; ++j)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i <= maxRow; ++i)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void getValidInt(int *num)
{
    int validInput = 0;
    do
    {
        if (scanf("%d", num) == 1)
        {
            validInput = 1;
        }
        else
        {
            while (getchar() != '\n');
        }

    } while (!validInput);
}

int main()
{
    struct graphnode *head1 = NULL;
    int choice, row, column, val;

    while (1)
    {
        printf("\nSelect Operations for Multilinked Structure\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1. Insert an element to the Multilinked Structure \n2. Display elements of the Multilinked Structures\n3. Exit\n");
        printf("\nEnter your choice : ");
        getValidInt(&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter row index : ");
            getValidInt(&row);
            printf("Enter column index : ");
            getValidInt(&column);
            printf("Enter element value : ");
            getValidInt(&val);
            head1 = insertion(head1, row, column, val);
            break;
        case 2:
            printf("\nElements of the Multilinked Structure 1 : \n\n");
            display(head1);
            break;
        case 3:
            while (head1 != NULL)
            {
                struct graphnode *temp = head1;
                head1 = head1->next;
                free(temp);
            }
            exit(0);
        default:
            printf("\nInvalid choice..!!\n");
        }
    }
    return 0;
}
