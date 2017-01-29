#include<stdio.h>
#define MAX_ms 50
void merge_sort(int ar[],int low, int high);
void merge(int ar[],int temp[],int low1,int low2,int high1,int high2);
void copy(int ar[],int temp[],int low,int n);
void mergesort()
{
    int n,i;
    printf("\t\t\t\t MERGE SORT\n");
    printf("enter the value of size of array\n");
    scanf("%d",&n);
    int ar[n];
    printf("enter the element of array\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&ar[i]);
    }
    merge_sort(ar,0,n-1);
    printf("\n\n");
    for(i=0; i<n; i++)
        printf("%d\t",ar[i]);
    printf("PRESS ANY BUTTON TO GO BACK");
    getch();
    return;
}
void merge_sort(int ar[],int low,int high)
{
    int mid;
    int temp[MAX_ms];
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(ar,low,mid);
        merge_sort(ar,mid+1,high);
        merge(ar ,temp,low,mid+1,mid,high);
        copy(ar,temp,low,high);

    }
}
void merge(int ar[],int temp[],int low1,int low2,int high1,int high2)
{
    int  i=low1;
    int j=low2;
    int k=low1;
    while((i<= high1)&&(j<=high2))
    {
        if(ar[i]<=ar[j])
            temp[k++]=ar[i++];
        else
            temp[k++]=ar[j++];
    }
    while(i<=high1)
        temp[k++]=ar[i++];
    while(j<=high2)
        temp[k++]=ar[j++];
}
void copy(int ar[],int temp[],int low,int n )
{
    int i;
    for(i=low; i<=n; i++)
        ar[i]=temp[i];
}
