#include<stdio.h>
int partition(int ar[],int low,int high);
void quick(int ar[],int low,int high);
quicksort()
{
    int n,i,j,ar[100];
    printf("\t\t\t\t QUICK SORT\n");
    printf("enter the size of array\n");
    scanf("%d",&n);

    printf("enter the elements of array\n");
    for(i=0; i<n; i++)
        scanf("%d",&ar[i]);
    quick(ar,0,n-1);
    printf("\n\n");
    for(i=0; i<n; i++)
        printf("%d\t",ar[i]);
    printf("PRESS ANY BUTTON TO GO BACK");
    getch();
    return;

}

void quick(int ar[],int low,int high)
{
    int parti;
    if(low>=high)
        return;
    parti=partition(ar,low,high);
    quick(ar,low,parti-1);
    quick(ar,parti+1,high);
}

int partition(int ar[],int low,int high)
{
    int i,j,temp,pivot;
    pivot=ar[low];;
    i=low+1;
    j=high;
    while(i<=j)
    {
        while((pivot>ar[i])&&(i<high))
            i++;
        while(ar[j]>pivot)
            j--;
        if(i<j)
        {
            temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
            i++;
            j--;
        }
        else
            i++;
    }
    ar[low]=ar[j];
    ar[j]=pivot;
    return j;
}
