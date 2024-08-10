// 17. Write a program that store names in an array and uses binary search to find out the name and its position in the array.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortNames(char (*names)[50], int index)
{
    int i, j;
    for (i = 0; i < index; i++)
    {
        for (j = 0; j < index - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                char temp[50];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int binarySearch(char arr[][50], int beg, int end, char *search)
{
    while (beg <= end)
    {
        int mid = (beg + end) / 2;
        int cmp = strcmp(arr[mid], search);

        if (cmp == 0)
        {
            return mid;  
        } else if (cmp < 0)
        {
            beg = mid + 1;
        } else
        {
            end = mid - 1;
        }
    }
    return -1; 
}

void displayNames(char names[][50], int index)
{
    printf("\nNames in the array : \n");
    for (int i = 0; i < index; i++)
    {
        printf("%d: %s\n", i + 1, names[i]);
    }
}

int main()
{
    int arrayLength, nameLength, index = 0;

    printf("Enter size of the array : ");
    scanf("%d", &arrayLength);

    if (arrayLength <= 0)
    {
        printf("Invalid array size..!\n");
        return 1;
    }

    char searchName[50];
    char names[arrayLength][50];

    int choice;
    do
    {
        printf("\nSelect option for the string array\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1. Insert name in array\n2. Search name in array\n3. Display names of array\n4. Exit\n");
        printf("\nEnter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (index < arrayLength)
                {
                    printf("\nEnter a name : ");
                    scanf("%s", names[index]);
                    index++;
                    sortNames(names, index);
                } else
                {
                    printf("\nArray is full..!\n");
                }
                break;
            case 2:
                if (index > 0)
                {
                    printf("\nEnter a name to search: ");
                    scanf("%s", searchName);
                    int position = binarySearch(names, 0, index - 1, searchName);
                    if (position != -1)
                    {
                        printf("\n%s found at position %d in the array\n", searchName, position + 1);
                    } else
                    {
                        printf("\n%s not found in the array\n", searchName);
                    }
                } else
                {
                    printf("\nArray is empty..!\n");
                }
                break;
            case 3:
                if (index > 0)
                {
                    displayNames(names, index);
                } else
                {
                    printf("\nArray is empty..!\n");
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice..!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
