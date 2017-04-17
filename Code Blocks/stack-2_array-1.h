#include<stdio.h>
void push2s(int);
int pop2s();
void display2s(int);
int top=-1;
int max2s=10;
int top1=10;
int a[10];
int isempty();
int isfull();

void push2s(int item)
{
    if(!isfull())
    {
        top++;
        a[top]=item;
        return ;
    }
    else
    {
        printf("stack1 is full\n");
        return;
    }
}
int isfull()
{
    if(top==top1-1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int pop2s()
{
    int i;
    if(!isempty())
    {
        i=a[top];
        top--;
        return i;
    }
}
void display2s(int i)
{
    if(isempty())
    {
        printf("stack1 is empty\n");
        return;
    }
    int j;
    for(j=i; j>=0; j--)
        printf("%d\n",a[j]);
}
int isfull1()
{
    if(top1==top+1)
        return 1;
    else
        return 0;
}

void push2s_1(int item)
{
    if(!isfull1())
    {
        top1--;
        a[top1]=item;
        return ;
    }
    else
    {
        printf("stack2 is full\n");
        return;
    }
}

int isempty1()
{
    if(top1==max2s)
        return 1;
    else
        return 0;
}
void display2s1(int i)
{
    if(isempty1())
    {
        printf("stack2 is empty\n");
        return;
    }
    int j;
    for(j=i; j<max2s; j++)
        printf("%d\n",a[j]);
}
int pop2s_1()
{
    int i;
    if(!isempty1())
    {
        i=a[top1];
        top1++;
        return i;
    }
}

void stack_2()
{
    int k,item;
    while(1)
    {
        system("clear");
        printf ("\t\t\t\tImplementation Two Stacks using an Array\n");
        printf("1.push in stack 1\n2.pop in stack 1\n3.display stack 1\n4.push in stack 2.\n5.pop in stack 2\n6.display stack 2\n7.To go back\n");
        scanf("%d",&k);
        switch(k)
        {
        case 1:
            system("clear");
            printf ("\t\t\t\tImplementation Two Stacks using an Array\n");
            printf("enter the element\n");
            scanf("%d",&item);
            push2s(item);
            break;
        case 2:
            system("clear");
            printf ("\t\t\t\tImplementation Two Stacks using an Array\n");
            if(isempty())
            {
                printf("stack is empty\n");
                break;
            }
            printf("element removed is %d\n",pop2s());
            break;
        case 3:
            system("clear");
            printf ("\t\t\t\tImplementation Two Stacks using an Array\n");
            display2s(top);
            getch();
            break;
        case 4:
            system("clear");
            printf ("\t\t\t\tImplementation Two Stacks using an Array\n");
            printf("enter the element\n");
            scanf("%d",&item);
            push2s_1(item);
            break;
        case 5:
            system("clear");
            printf ("\t\t\t\tImplementation Two Stacks using an Array\n");
            if(isempty1())
            {
                printf("stack is empty\n");
                break;
            }
            printf("element removed is %d\n",pop2s_1());
            break;
        case 6:
            system("clear");
            printf ("\t\t\t\tImplementation Two Stacks using an Array\n");
            display2s1(top1);
            getch();
            break;
        case 7:
            system("clear");
            printf ("\t\t\t\tImplementation Two Stacks using an Array\n");
            return;
        }
    }
}

