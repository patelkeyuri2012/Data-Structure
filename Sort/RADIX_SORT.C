#include <stdio.h>

void getValidInt(int *num);
int findMax(int arr[], int n);
void countingSort(int arr[], int n, int exp);
void radixSort(int arr[], int n);
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

    radixSort(a, len);

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

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}
