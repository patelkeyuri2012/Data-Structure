#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *create_node(int);

void getValidInt(int *);
void insert(int);
int deleteNode(int, char); 
int search(struct node *, int);
void inorder(struct node *);

int main()
{
    int choice, data, val;

    while (1)
    {
        printf("\nSelect operations for the Binary Search Tree:\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1. Add an element to the Binary Search Tree");
        printf("\n2. Delete an element from the Binary Search Tree");
        printf("\n3. Search an element in the Binary Search Tree");
        printf("\n4. Exit\n");
        printf("\nEnter your choice: ");
        getValidInt(&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter element to insert : ");
            getValidInt(&data);
            insert(data);
            break;
        case 2:
            if (root == NULL)
            {
                printf("\nNULL\n");
            }
            else
            {
                printf("\n");
                inorder(root);
                printf("\n");
                printf("\nEnter element to delete : ");
                getValidInt(&val);
                deleteNode(val, ' '); 
            }
            break;
        case 3:
            if (root == NULL)
            {
                printf("\nNULL\n");
            }
            else
            {
                printf("\nEnter element to search : ");
                getValidInt(&val);
                search(root, val);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
    return 0;
}

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
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

void insert(int data)
{
    struct node *new_node = create_node(data);

    if (new_node != NULL)
    {
        if (root == NULL)
        {
            root = new_node;
            return;
        }

        struct node *temp = root;
        struct node *prev = NULL;

        while (temp != NULL)
        {
            prev = temp;
            if (data > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }

        if (data > prev->data)
        {
            prev->right = new_node;
        }
        else
        {
            prev->left = new_node;
        }
    }
}

int deleteNode(int val, char d)
{
    bool found = false;
    struct node *curr = root;
    struct node *parent = NULL;

    
    while (curr != NULL)
    {
        if (val == curr->data)
        {
            found = true;
            break;
        }
        else if (val > curr->data)
        {
            parent = curr;
            curr = curr->right;
            d = 'R'; 
        }
        else
        {
            parent = curr;
            curr = curr->left;
            d = 'L'; 
        }
    }

    if (!found)
    {
        printf("\nElement %d not found\n", val);
        return 0;
    }

    if (curr->left == NULL || curr->right == NULL)
    {
        struct node *child = (curr->left != NULL) ? curr->left : curr->right;
        
        if (parent == NULL)
            root = child;
        else
        {
            
            if (d == 'L')
                parent->left = child;
            else
                parent->right = child;
        }
        free(curr);
        printf("\nElement %d is deleted\n", val);
    }
    else
    { 
        struct node *successor = curr->right;
        struct node *successorParent = curr;

        while (successor->left != NULL)
        {
            successorParent = successor;
            successor = successor->left;
        }
        curr->data = successor->data;
        deleteNode(successor->data, 'R');
    }
    return 0;
}

int search(struct node *root, int val)
{
    while (root != NULL)
    {
        if (val == root->data)
        {
            printf("\nElement %d is found\n", val);
            return 1;
        }
        else if (val < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    printf("\nElement %d not found\n", val);
    return 0;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
