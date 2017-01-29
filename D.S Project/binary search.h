#include <stdio.h>
#define MAX 50

int binarySearch(int arr[], int size, int item)
{
	int low=0, up=size-1, mid;
	while(low<=up)
	{
		mid = (low+up)/2;
		if(item>arr[mid])
			low = mid+1;
		else if(item<arr[mid])
			up = mid-1;
		else
			return mid;
	}
	return -1;
}

void binarysearch()
{
    system("cls");
    printf ("\t\t\t\tBINARY SEARCH\n");
	int i, n, item, arr[MAX], index;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	printf("Enter the elements in increasing order : \n");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i] );

	printf("Enter the item to be searched : ");
	scanf("%d", &item);

	index = binarySearch(arr, n, item);

	if(index == -1)
		printf("%d not found in array\n", item);
	else
		printf("%d found at position %d\n", item, index+1);
    printf("PRESS ANY BUTTON TO GO BACK");
    getch();
    return;
}
