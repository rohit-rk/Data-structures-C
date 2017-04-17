#include<stdio.h>
#include<malloc.h>
struct node_sl
{
    int info;
    struct node_sl *n;
}*top_sl=NULL;
void push_sl(int item);
int pop_sl();
int peek_sl();
int empty_sl();
void display_sl();
void stack_l()
{
    int item,ch;
    while(1)
    {
        system("clear");
        printf ("\t\t\t\tImplementation of Stack with Linked list\n");
        printf("\n 1 for push");
        printf("\n 2 for pop");
        printf("\n 3 for display top item");
        printf("\n 4 for display all item of stack");
        printf("\n 5 To go back");
        printf("\n enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            system("clear");
            printf ("\t\t\t\tImplementation of Stack with Linked list\n");
            printf("enter the element to be pushed\n");
            scanf("%d",&item);
            push_sl(item);
            break;
        case 2:
            system("clear");
            printf ("\t\t\t\tImplementation of Stack with Linked list\n");
            item=pop_sl();
            printf("popped element is %d",item);
            getch();
            break;
        case 3:
            system("clear");
            printf ("\t\t\t\tImplementation of Stack with Linked list\n");
            printf("the top item is %d",peek_sl());
            getch();
            break;
        case 4:
            system("clear");
            printf ("\t\t\t\tImplementation of Stack with Linked list\n");
            display_sl();
            getch();
            break;
        case 5:
            system("clear");
            printf ("\t\t\t\tImplementation of Stack with Linked list\n");
            return;
        }

    }

}
void push_sl(int item)
{
    struct node_sl *tmp;
    tmp=(struct node_sl *)malloc(sizeof (struct node_sl));
    if(tmp==NULL)
    {
        printf("stack is overflow");
        return;
    }
    tmp->info=item;
    tmp->n=top_sl;
    top_sl=tmp;
}
int pop_sl()
{
    struct node_sl*tmp;
    int item;
    if(empty_sl())
    {
        printf("stack is underflow");
    }
    tmp=top_sl;
    item=tmp->info;
    top_sl=tmp->n;
    free(tmp);
    return item;
}
int peek_sl()
{
    if(empty_sl())
    {
        printf("stack is undeflow");
    }
    return top_sl->info;
}
int empty_sl()
{
    if(top_sl==NULL)
    {
        return 1;
    }
    return 0;
}
void display_sl()
{
    struct node_sl *d;
    d=top_sl;
    if(empty_sl())
    {
        printf("stack is empty");
        return;
    }
    printf("stack element is:\n");
    while(d!=NULL)
    {
        printf("%d\n",d->info);
        d=d->n;
    }
    printf("\n");
}
