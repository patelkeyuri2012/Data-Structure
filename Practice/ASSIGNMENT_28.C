// 28. Implement radix sort, quick sort and insertion sort

#include <stdio.h>

int findMax(int arr[], int n);
void countingSort(int arr[], int n, int exp);
void radixSort(int arr[], int n);
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);
void insertionSort(int arr[], int n);
void print_array(int *arr, int n);

int main()
{
    int len, i;

    printf("Enter size of array : ");
    scanf("%d", &len);
    printf("\n");
    int a[len];

    for (i = 0; i < len; i++)
    {
        printf("Enter %d element of array : ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\nOriginal elements of array are : ");
    print_array(a, len);

    radixSort(a, len);

    printf("\n\nAfter radix sort elements of array are : ");
    print_array(a, len);

    quicksort(a, 0, len - 1);

    printf("\n\nAfter quick sort elements of array are : ");
    print_array(a, len);

    insertionSort(a, len);

    printf("\n\nAfter insertion sort elements of array are : ");
    print_array(a, len);

    return 0;
}

int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int exp)
{
    const int RANGE = 10;
    int output[n];
    int count[RANGE] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % RANGE]++;
    }

    for (int i = 1; i < RANGE; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % RANGE] - 1] = arr[i];
        count[(arr[i] / exp) % RANGE]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int max = findMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
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

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}
