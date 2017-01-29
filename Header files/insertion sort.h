#include<stdio.h>
void insertionSort(int ar[],int n)
{
    int i,j,k;
    for(i=1; i<n; i++)
    {
        k=ar[i];
        for(j=i-1; j>=0&&k<ar[j]; j--)
        {
            ar[j+1]=ar[j];
        }
        ar[j+1]=k;
    }

}
insertionsort()
{
    int i,n;
    printf("\t\t\t\tINSERTION SORT\n");
    printf("enter the size of array\n");
    scanf("%d",&n);
    int ar[n];
    printf("enter the elements of an array\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&ar[i]);
    }
    insertionSort(ar,n);
    printf("\n\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",ar[i]);
    }
    printf("PRESS ANY BUTTON TO GO BACK");
    getch();
    return;
}
