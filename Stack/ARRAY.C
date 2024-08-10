#include<stdio.h>
#define MAX 4

int array[MAX];
int index = 0;

void add();
void delet();
void sort();
void display();
void simple_search();
void binary_search();

int main()
{
    int choice;

    while (choice<7)
    {
        printf("\nSelect operations of the stack that you want to perform:\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n1.Add the element in array\n2.Delete the element in array\n3.Sort elements of array\n4.Display elements of array\n5.Search the element in array using simple search\n6.Search the element in array using binary search");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            delet();
            break;
        case 3:
            sort();
            break;
        case 4:
        	display();
        	break;
        case 5:
        	simple_search();
        	break;
        case 6:
        	binary_search();
        	break;
        default:
            printf("\nInvalid choice!!");
        }
    }
}

void add() 
{
    int ele;

    if (index >= 0 && index < MAX) 
	{
        printf("\nEnter the element to add to the array: ");
        scanf("%d", &ele);

        printf("\nEnter the position to add the element in the array (0-%d): ", MAX - 1);
        scanf("%d", &index);

        if (index < 0 || index > MAX - 1) 
		{
            printf("\nInvalid position.\nPlease enter position in range 0-%d\n", MAX - 1);
        } 
		else 
		{
            for (int i = MAX - 1; i > index; i--) 
			{
                array[i] = array[i - 1];
            }

            array[index] = ele;
            index++;   
        }
        printf("\nElement at position %d is inserted\n", index-1);
        
    } else {
        printf("\nArray is full..!!\n");
    }
}



void delet() 
{
    int i;

	display();
	
    printf("\nEnter the position to delete an element from the array (0-%d): ", MAX - 1);
    scanf("%d", &index);

    if (index < 0 || index >= MAX) 
	{
        printf("\nInvalid position. Please enter position in range 0-%d\n", MAX - 1);
    } 
	else 
	{
        for (i = index; i < MAX - 1; i++) 
		{
            array[i] = array[i + 1];
        }

        index--; 
        MAX == MAX - 1; 

        printf("\nElement at position %d is deleted\n", index + 1);
    }
}

void sort() {
    for (int i = 0; i < index; i++) {
        for (int j = i + 1; j < index; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("\nSorted elements of the array : ");
    for (int i = 0; i < index; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void display() {
	int i;
    if (index == 0) 
	{
        printf("Array is Empty..!\n");
    } else 
	{
        printf("\nElements of array are : ");
        for (i = 0; i < index; i++)
    	{
        	printf("%d ", array[i]);
   		}
    }
    printf("\n");
}


void simple_search()
{
	int search, count=0;
    
    display();
    
    printf("\nEnter element to search: ");
    scanf("%d", &search);
	for (int i = 0; i <= index; i++)
	{
        if (array[i] == search) 
		{ 
            printf("\n%d is found at position %d\n", search, i);
            count=1;
        }
        
	}
	if(count==0)
	{
       	printf("\n%d is not found\n", search);
	}        
}

void binary_search() {
    int left = 0;
    int right = index - 1;
    int middle;
    int search;

	sort();
	
    printf("\nEnter element to search: ");
    scanf("%d", &search);

    while (left <= right) {
        middle = (left + right) / 2;

        if (array[middle] == search) {
            printf("\n%d is found at position %d\n", search, middle);
            return;
        } else if (array[middle] < search) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    printf("\n%d is not found\n", search);
}


