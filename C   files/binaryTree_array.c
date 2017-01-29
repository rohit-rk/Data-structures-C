#include<stdio.h>
void preorder(int tree[],int n,int k)
{
    if(k>n)
        return;
    if(tree[k]>1000)
        return;
    else
    {
        printf("%d\n",tree[k]);
    }
    preorder(tree,n,2*k);
    preorder(tree,n,2*k+1);
}
void inorder(int tree[],int n,int k)
{
    if(k>n)
        return;

    if(tree[k]>1000)
        return;
    inorder(tree,n,2*k);
    if(tree[k]<=1000)
        printf("%d\n",tree[k]);
    inorder(tree,n,2*k+1);
}
void postorder(int tree[],int n,int k)
{
    if(k>n)
        return;
    if(tree[k]>1000)
        return;
    postorder(tree,n,2*k);
    postorder(tree,n,2*k+1);
    if(tree[k]<=1000)
        printf("%d\n",tree[k]);
}
int main()
{
    system("cls");
    printf("\t\t\t\tBINARY TREE\n");
    int n,i,j,data,data2;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    int tree[n+1];
    for(i=1; i<=n; i++)
        scanf("%d",&tree[i]);
    printf("\n\n");

    for(i=1; i<=n; i++)
        printf("%d\n",tree[i]);
    system("cls");
    printf("\t\t\t\tBINARY TREE\n");
    printf("\n\n");
    printf("preordre\n");
    preorder(tree,n,1);
    getch();
    system("cls");
    printf("\t\t\t\tBINARY TREE\n");
    printf("\n");
    printf("postorder\n");
    postorder(tree,n,1);
    getch();
    system("cls");
    printf("\t\t\t\tBINARY TREE\n");
    printf("\n");
    printf("inorder\n");
    inorder(tree,n,1);
    getch();
    system("cls");
    printf("\t\t\t\tBINARY TREE\n");
    printf("the number whose ancestors required\n");
    scanf("%d",&data);
    for(j=1; j<=n+1; j++)
    {
        if(tree[j]==data)
            break;
    }

    while(j!=1)
    {
        j=j/2;
        printf("%d\n",tree[j]);
    }
    getch();
    system("cls");
    printf("\t\t\t\tBINARY TREE\n");
    printf("the data whose decentent required\n");
    scanf("%d",&data2);
    for(i=1; i<=n+1; i++)
    {
        if(tree[i]==data);
        break;
    }
    preorder(tree,n,i);
}
