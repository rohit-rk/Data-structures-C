#include <stdio.h>
#define MAX_li 50
int linearSearch(int arr[], int n, int item);
void linearsearch()
{
    system("clear");
    printf ("\t\t\t\tLINEAR SEARCH\n");
	int i, n, item, arr[MAX_li], index;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	printf("Enter the elements : \n");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i] );

	printf("Enter the item to be searched : ");
	scanf("%d", &item);

	index = linearSearch(arr, n, item);

	if(index == -1)
		printf("%d not found in array\n", item);
	else
		printf("%d found at position %d\n", item, index+1);
    printf("PRESS ANY BUTTON TO GO BACK");
    getch();
    return;
}     //same main just replace LinearSearch(�) by the type of search
int linearSearch(int arr[], int n, int item)
{
	int i=0;
	while(i<n && item!=arr[i])
			i++;
	if(i < n)
		return i;
	else
		return -1;
}
