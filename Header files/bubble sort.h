#include<stdio.h>
void bubbleSort(int ar[],int n)
{
    int i,j,counter,swap;
    for(i=0; i<n-1; i++)
    {
        counter=0;
        for(j=0; j<n-1-i; j++)
        {
            if(ar[j]>ar[j+1])
            {
                swap=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=swap;
                counter++;
            }
        }
        if(counter==0)
            break;
    }
}
bubblesort()
{
    int i,n;
    printf("\t\t\t\tBUBBLE SORT\n");
    printf("enter the size of array\n");
    scanf("%d",&n);
    int ar[n];
    printf("enter the elements of an array\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&ar[i]);
    }
    bubbleSort(ar,n);
    printf("\n\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",ar[i]);
    }
    printf("PRESS ANY BUTTON TO GO BACK");
    getch();
    return;
}
