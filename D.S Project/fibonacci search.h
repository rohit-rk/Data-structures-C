#include <stdio.h>
#define MAX_f 50

int min(int x, int y)
{
    return (x<=y)? x : y;
}
int fibonacciSearch(int arr[],int n, int x)
{
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM  = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = min(offset+fibMMm2, n-1);

        if (arr[i] < x)
        {
            fibM  = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }

        else if (arr[i] > x)

        {
            fibM  = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else return i;
    }

    if(fibMMm1 && arr[offset+1]==x)return offset+1;

    return -1;
}

void fibonaccisearch(void)
{
    system("cls");
    printf ("\t\t\t\tFIBONACCI SEARCH\n");
    int i, n, item, arr[MAX_f], index;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements in increasing order: \n");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i] );
    printf("Enter the item to be searched : ");
    scanf("%d", &item);
    index=fibonacciSearch(arr, n, item);
    printf("Found at position: %d \n",index+1);
    printf("PRESS ANY BUTTON TO GO BACK");
    getch();
    return;
}
