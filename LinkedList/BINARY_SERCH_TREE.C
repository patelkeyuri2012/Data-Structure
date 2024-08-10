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

void insert(int);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n\nSelect operations for the Binary Search Tree:\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1. Add an element to the Binary Search Tree\n2. Preorder Traversals of the Binary Search Tree\n3. Inorder Traversals of the Binary Search Tree\n4. Postorder Traversals of the Binary Search Tree\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter data to Binary Search Tree : ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
        	printf("\nElements of the Binary Search Tree in Preorder Traversals : ");
            preorder(root);
            break;
        case 3:
        	printf("\nElements of the Binary Search Tree in Inorder Traversals : ");
            inorder(root);
            break;
        case 4:
        	printf("\nElements of the Binary Search Tree in Postorder Traversals : ");
        	postorder(root);
            break;
        case 5:
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
        printf("\nMemory for a new node can't be allocated");
        return NULL;
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
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

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
