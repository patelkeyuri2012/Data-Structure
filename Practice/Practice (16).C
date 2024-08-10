// 27. Implement Heap sort

#include<stdio.h>

void heapify(int*, int, int);
void heapsort(int*, int);
void print_array(int*, int);

int main()
{
    int len, i;

    printf("Enter size of array : ");
    scanf("%d", &len);
    printf("\n");
    int a[len];

    for (i = 0; i < len; i++)
    {
        printf("Enter %d element of array : ",i+1);
		scanf("%d",&a[i]);
    }

    printf("\nBefore sorting elements of array are : ");
    print_array(a, len);

    heapsort(a, len);

    printf("\n\nAfter sorting elements of array are : ");
    print_array(a, len);

    return 0;
}

void heapsort(int* arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        heapify(arr, i, 0);
    }
}

void heapify(int* arr, int n, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void print_array(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}
