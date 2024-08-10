#include<stdio.h>

void mergeSort (int [], int , int);		
void merge (int [], int , int, int);
void printArray (int[], int);

// main function to implement of merge sort algorithm
void main()
{
	int len,i;
	
	printf("Enter Size of Array : ");
	scanf("%d",&len);
	printf("\n");
	int a[len];
	
	for(i=0; i<len; i++)
	{
		printf("Enter %d Element of Array : ",i+1);
		scanf("%d",&a[i]);
	}
	
	printf("\nBefore sorting elements of array are : ");
	printArray(a, len);
	
	mergeSort(a,0,len-1);
	
	printf("\n\nAfter sorting elements of array are : ");  
    printArray(a, len); 
    printf("\n");
}

// mergeSort function represent of merge sort algorithm
void mergeSort (int a[], int beg, int end)
{	
	int mid;
	
	if(beg<end)
	{
		mid=(beg+end)/2;
		mergeSort(a,beg,mid);			//for divided left side array
		mergeSort(a,mid+1,end);			//for divided right side array
		merge(a,mid,beg,end);			//to merge two sorted array
	}
}

// merge function for merging two arrays
void merge (int a[], int mid, int beg, int end)
{	
	int i, j, k, b[end + 1];					// b[] is store sorted elements
	i = beg;					// represent divided fisrt array 
	j = mid + 1;					// represent divided second array 
	k = beg;					// represent index of sorted array 
	
	//to compare two sorted array
	while(i<=mid && j<=end)
	{
		if(a[i]<a[j]){
			b[k]=a[i];
			i++;
		}
		else{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	
	//if first half array elememts are not consider yet
	while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}

	//if second half array elememts are not consider yet
	while(j<=end)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	
	//to print sorted elements in given array
	for(i=beg;i<end+1;i++)
	{
		a[i]=b[i];
	}
}

// printArray function for print elements in array
void printArray(int a[],int len)
{
	int i;
	for(i=0;i<len;i++){
		printf("%d\t",a[i]);
	}
}