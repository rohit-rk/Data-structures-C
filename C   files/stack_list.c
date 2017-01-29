#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *n
        }*top=NULL;
void push(int item);
int pop();
int peek();
int empty();
void display();
void main()
{
    int item,ch;
    while(1)
    {
        system("cls");
        printf ("\t\t\t\tImplementation of Stack with Linked list\n");
        printf("\n 1 for push");
        printf("\n 2 for pop");
        printf("\n 3 for display top item");
        printf("\n 4 for display all item of stack");
        printf("\n 5 for quit");
        printf("\n enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            system("cls");
            printf ("\t\t\t\tImplementation of Stack with Linked list\n");
            printf("enter the element to be pushed\n");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            system("cls");
            printf ("\t\t\t\tImplementation of Stack with Linked list\n");
            item=pop();
            printf("popped element is %d",item);
            getch();
            break;
        case 3:
            system("cls");
            printf ("\t\t\t\tImplementation of Stack with Linked list\n");
            printf("the top item is %d",peek());
            getch();
            break;
        case 4:
            system("cls");
            printf ("\t\t\t\tImplementation of Stack with Linked list\n");
            display();
            getch();
            break;
        case 5:
            system("cls");
            printf ("\t\t\t\tImplementation of Stack with Linked list\n");
            return;
        }

    }

}
void push(int item)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof (struct node));
    if(tmp==NULL)
    {
        printf("stack is overflow");
        return;
    }
    tmp->info=item;
    tmp->n=top;
    top=tmp;
}
int pop()
{
    struct node*tmp;
    int item;
    if(empty())
    {
        printf("stack is underflow");
    }
    tmp=top;
    item=tmp->info;
    top=tmp->n;
    free(tmp);
    return item;
}
int peek()
{
    if(empty())
    {
        printf("stack is undeflow");
    }
    return top->info;
}
int empty()
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}
void display()
{
    struct node *d;
    d=top;
    if(empty())
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
