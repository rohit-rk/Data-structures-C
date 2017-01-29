#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue_arr[MAX];
int rear=-1;
int front=-1;
void insert(int item);
int del();
int peek();
void display();
int isFull();
int isEmpty();
main()
{
    int choice,item;
    printf ("\t\t\t\tQUEUE OPERATION\n");
    while(1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display element at the front\n");
        printf("4.Display all elements of the queue\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            system("cls");
            printf ("\t\t\t\tQUEUE OPERATION\n");
            printf("Input the element for adding in queue : ");
            scanf("%d",&item);
            insert(item);
            break;
        case 2:
            system("cls");
            printf ("\t\t\t\tQUEUE OPERATION\n");
            item=del();
            printf("Deleted element is  %d\n",item);
            break;
        case 3:
            system("cls");
            printf ("\t\t\t\tQUEUE OPERATION\n");
            printf("Element at the front is %d\n",peek());
            break;
        case 4:
            system("cls");
            printf ("\t\t\t\tQUEUE OPERATION\n");
            display();
            break;
        case 5:
            system("cls");
            printf ("\t\t\t\tQUEUE OPERATION\n");
            return;
            break;
        }
    }
}
void insert(int item)
{
    if( isFull() )
    {
        printf("Queue Overflow\n");
        return;
    }
    if( front == -1 )
        front=0;
    rear=rear+1;
    queue_arr[rear]=item ;
}
int del()
{
    int item;
    if( isEmpty() )
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    item=queue_arr[front];
    front=front+1;
    return item;
}
int peek()
{
    if( isEmpty() )
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    return queue_arr[front];
}
int isEmpty()
{
    if( front==-1 || front==rear+1 )
        return 1;
    else
        return 0;
}
int isFull()
{
    if( rear==MAX-1 )
        return 1;
    else  return 0;
}
void display()
{
    int i;
    if ( isEmpty() )
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is :\n\n");
    for(i=front; i<=rear; i++)
        printf("%d  ",queue_arr[i]);
    printf("\n\n");
}
