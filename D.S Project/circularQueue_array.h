#include<stdio.h>
#include<stdlib.h>
#define MAX_cq 10
int cqueue_arr[MAX_cq];
int rear_cq=-1;
int front_cq=-1;
void insert_cq(int item);
int del_cq();
int peek_cq();
void display_cq();
int isFull_cq();
int isEmpty_cq();
void cqueue_a()
{
    int choice,item;
    printf ("\t\t\t\tCIRCULAR QUEUE OPERATION\n");
    while(1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display element at the front\n");
        printf("4.Display all elements of the queue\n");
        printf("5.To go back\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            system("cls");
            printf ("\t\t\t\tCIRCULAR QUEUE OPERATION\n");
            printf("Input the element for adding in queue : ");
            scanf("%d",&item);
            insert_cq(item);
            break;
        case 2:
            system("cls");
            printf ("\t\t\t\tCIRCULAR QUEUE OPERATION\n");
            item=del_cq();
            printf("Deleted element is  %d\n",item);
            break;
        case 3:
            system("cls");
            printf ("\t\t\t\tCIRCULAR QUEUE OPERATION\n");
            printf("Element at the front is %d\n",peek_cq());
            break;
        case 4:
            system("cls");
            printf ("\t\t\t\tCIRCULAR QUEUE OPERATION\n");
            display_cq();
            break;
        case 5:
            system("cls");
            printf ("\t\t\t\tCIRCULAR QUEUE OPERATION\n");
            return;
            break;
        }
    }
}
void insert_cq(int item)
{
    if( isFull_cq() )
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front_cq == -1 )
        front_cq=0;

    if(rear_cq==MAX_cq-1)
        rear_cq=0;
    else
        rear_cq=rear_cq+1;
    cqueue_arr[rear_cq]=item ;
}

int del_cq()
{
    int item;
    if( isEmpty_cq() )
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    item=cqueue_arr[front_cq];
    if(front_cq==rear_cq)
    {
        front_cq=-1;
        rear_cq=-1;
    }
    else if(front_cq==MAX_cq-1)
        front_cq=0;
    else
        front_cq=front_cq+1;
    return item;
}

int isEmpty_cq()
{
    if(front_cq==-1)
        return 1;
    else
        return 0;
}

int isFull_cq()
{
    if((front_cq==0 && rear_cq==MAX_cq-1) || (front_cq==rear_cq+1))
        return 1;
    else
        return 0;
}

int peek_cq()
{
    if( isEmpty_cq() )
    {
        printf("Queue Underflow\n");

    }
    return cqueue_arr[front_cq];
}

void display_cq()
{
    int i;
    if(isEmpty_cq())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    i=front_cq;
    if( front_cq<=rear_cq )
    {
        while(i<=rear_cq)
            printf("%d ",cqueue_arr[i++]);
    }
    else
    {
        while(i<=MAX_cq-1)
            printf("%d ",cqueue_arr[i++]);
        i=0;
        while(i<=rear_cq)
            printf("%d ",cqueue_arr[i++]);
    }
    printf("\n");
}
