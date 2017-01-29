#include<stdio.h>
void selectionSort(int ar[],int n)
{
    int i,j,swap,min;
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1; j<n; j++)
        {
            if(ar[min]>ar[j])
            {
                min=j;
            }
        }
        if(i!=min)
        {
            swap=ar[min];
            ar[min]=ar[i];
            ar[i]=swap;
        }
    }
}
selectionsort()
{
    int i,n;
    printf("\t\t\t\tSELECTION SORT\n");
    printf("enter the size of array\n");
    scanf("%d",&n);
    int ar[n];
    printf("enter the elements of an array\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&ar[i]);
    }
    selectionSort(ar,n);
    printf("\n\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",ar[i]);
    }
    printf("PRESS ANY BUTTON TO GO BACK");
    getch();
    return;
}
