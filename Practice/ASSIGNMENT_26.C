// 26. Implement threaded binary tree

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int isThreaded;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("\nMemory for a new node can't be allocated");
        return NULL;
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->isThreaded = 0;

    return newNode;
}

struct Node *leftMost(struct Node *node)
{
    while (node != NULL && node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    struct Node *current = root;
    struct Node *parent = NULL;

    while (current != NULL)
    {
        parent = current;

        if (data < current->data)
        {
            if (!current->left)
            {
                struct Node *newNode = createNode(data);
                current->left = newNode;
                newNode->right = current;
                newNode->isThreaded = 1;
                return root;
            }
            current = current->left;
        } else if (data > current->data || (data == current->data && current->isThreaded))
        {
            if (!current->right || current->isThreaded)
            {
                struct Node *newNode = createNode(data);
                if (current->right || current->isThreaded)
                {
                    newNode->right = current->right;
                    newNode->isThreaded = 1;
                }
                current->right = newNode;
                current->isThreaded = 0;
                return root;
            }
            current = current->right;
        } else
        {
            printf("\nDuplicate value detected..!!\n");
            return root;
        }
    }
    return root;
}

void threadedInOrderTraversal(struct Node *root)
{
    struct Node *current = leftMost(root);

    while (current != NULL)
    {
        printf("%d ", current->data);

        if (current->isThreaded)
            current = current->right;
        else
            current = leftMost(current->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, data;

    while (1)
    {
        printf("\nSelect operations for the threaded binary tree :\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1. Insert an element to the threaded binary tree\n");
        printf("2. Inorder traversals of the threaded binary tree\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter element to insert : ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("\nElements of the threaded binary tree in inorder traversals : ");
                threadedInOrderTraversal(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice..!!\n");
                break;
        }
    }
    return 0;
}
