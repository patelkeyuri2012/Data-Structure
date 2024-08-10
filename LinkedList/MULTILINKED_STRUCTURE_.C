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

void addMatrices(struct graphnode *head1, struct graphnode *head2)
{
    struct graphnode *result = NULL;
    struct graphnode *current1 = head1;
    struct graphnode *current2 = head2;

    while (current1 != NULL)
    {
        int row = current1->rownum;
        int column = current1->columnnum;
        int value = current1->val;

        while (current2 != NULL && (current2->rownum < row || (current2->rownum == row && current2->columnnum < column)))
        {
            result = insertion(result, current2->rownum, current2->columnnum, current2->val);
            current2 = current2->next;
        }

        if (current2 != NULL && current2->rownum == row && current2->columnnum == column)
        {
            value += current2->val;
            current2 = current2->next;
        }

        result = insertion(result, row, column, value);
        current1 = current1->next;
    }

    while (current2 != NULL)
    {
        result = insertion(result, current2->rownum, current2->columnnum, current2->val);
        current2 = current2->next;
    }

    printf("\nAddition of the Multilinked Structures : \n\n");
    display(result);

    while (result != NULL)
    {
        struct graphnode *temp = result;
        result = result->next;
        free(temp);
    }
}

void multiplyMatrices(struct graphnode *head1, struct graphnode *head2)
{
    struct graphnode *result = NULL;
    struct graphnode *current1 = head1;
    struct graphnode *current2 = head2;

    while (current1 != NULL)
    {
        int row1 = current1->rownum;
        int column1 = current1->columnnum;
        int value1 = current1->val;

        while (current2 != NULL)
        {
            int row2 = current2->rownum;
            int column2 = current2->columnnum;
            int value2 = current2->val;

            if (column1 == row2)
            {
                int resultValue = value1 * value2;

                struct graphnode *resultNode = result;
                while (resultNode != NULL && (resultNode->rownum != row1 || resultNode->columnnum != column2))
                {
                    resultNode = resultNode->next;
                }

                if (resultNode != NULL)
                {
                    resultNode->val += resultValue;
                }
                else
                {
                    result = insertion(result, row1, column2, resultValue);
                }
            }

            current2 = current2->next;
        }

        current1 = current1->next;
        current2 = head2; 
    }

    printf("\nMultiplication of the Multilinked Structures : \n\n");
    display(result);

    while (result != NULL)
    {
        struct graphnode *temp = result;
        result = result->next;
        free(temp);
    }
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
    struct graphnode *head2 = NULL;
    
    head1 = insertion(head1, 0, 0, 1);
	head1 = insertion(head1, 0, 1, 4);
	head1 = insertion(head1, 0, 2, 2);
    head1 = insertion(head1, 1, 1, 5);
    head1 = insertion(head1, 2, 2, 3);

    head2 = insertion(head2, 1, 0, 2);
    head2 = insertion(head2, 1, 1, 3);
    head2 = insertion(head2, 1, 2, 5);
    head2 = insertion(head2, 2, 2, 6);

    while (1)
    {
        printf("\nSelect Operations for Multilinked Structure\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1. Display elements of the Multilinked Structures\n");
        printf("2. Addition of the Multilinked Structures\n");
        printf("3. Multiplication of the Multilinked Structures\n");
        printf("4. Exit\n");
        printf("\nEnter your choice : ");
        int choice;
        getValidInt(&choice);

        switch (choice)
        {
        case 1:
            printf("\nElements of the Multilinked Structure 1 : \n\n");
            display(head1);
            printf("\nElements of the Multilinked Structure 2 : \n\n");
            display(head2);
            break;
        case 2:
            addMatrices(head1, head2);
            break;
        case 3:
            multiplyMatrices(head1, head2);
            break;
        case 4:
            while (head1 != NULL)
            {
                struct graphnode *temp = head1;
                head1 = head1->next;
                free(temp);
            }
            while (head2 != NULL)
            {
                struct graphnode *temp = head2;
                head2 = head2->next;
                free(temp);
            }
            exit(0);
        default:
            printf("\nInvalid choice..!!\n");
        }
    }

    return 0;
}

/*
int main()
{
    struct graphnode *head1 = NULL;
    struct graphnode *head2 = NULL;
    int choice, row, column, val;

    while (1)
    {
        printf("\nSelect Operations for Multilinked Structure\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1. Insert an element to the Multilinked Structure 1\n2. Insert an element to the Multilinked Structure 2\n3. Display elements of the Multilinked Structures\n4. Addition of the Multilinked Structures\n5. Multiplication of the Multilinked Structures\n6. Exit\n");
        printf("\nEnter your choice : ");
        getValidInt(&choice);

        switch (choice)
        {
        case 1:
        	printf("\nEnter data for the Multilinked Structures 1\n");
            printf("\nEnter row index : ");
            getValidInt(&row);
            printf("Enter column index : ");
            getValidInt(&column);
            printf("Enter element value : ");
            getValidInt(&val);
            head1 = insertion(head1, row, column, val);
            break;
        case 2:
        	printf("\nEnter data for the Multilinked Structures 2\n");
            printf("\nEnter row index : ");
            getValidInt(&row);
            printf("Enter column index : ");
            getValidInt(&column);
            printf("Enter element value : ");
            getValidInt(&val);
            head2 = insertion(head2, row, column, val);
            break;
        case 3:
            printf("\nElements of the Multilinked Structure 1 : \n\n");
            display(head1);
            printf("\nElements of the Multilinked Structure 2 : \n\n");
            display(head2);
            break;
        case 4:
            if (head1 != NULL && head2 != NULL)
            {
                addMatrices(head1, head2);
            }
            else
            {
                printf("\nMultilinked Structures are not properly filled..!\n\n");
            }
            break;
        case 5:
            if (head1 != NULL && head2 != NULL)
            {
                multiplyMatrices(head1, head2);
            }
            else
            {
                printf("\nMultilinked Structures are not filled completely..!\n\n");
            }
            break;
        case 6:
            while (head1 != NULL)
            {
                struct graphnode *temp = head1;
                head1 = head1->next;
                free(temp);
            }
            while (head2 != NULL)
            {
                struct graphnode *temp = head2;
                head2 = head2->next;
                free(temp);
            }
            exit(0);
        default:
            printf("\nInvalid choice..!!\n");
        }
    }

    return 0;
}
*/