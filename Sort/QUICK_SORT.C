#include <stdio.h>

void getValidInt(int *num);
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);
void print_array(int *arr, int n);

int main()
{
    int len, i;
    
    printf("Enter size of array : ");
    getValidInt(&len);
    printf("\n");
    int a[len];
   
    for (i = 0; i < len; i++)
    {
    	printf("Enter %d element of array : ",i+1);
		getValidInt(&a[i]);
    }

    printf("\nBefore sorting elements of array are : ");
    print_array(a, len);

    quicksort(a, 0, len - 1);

    printf("\n\nAfter sorting elements of array are : ");
    print_array(a, len);

    return 0;
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}
