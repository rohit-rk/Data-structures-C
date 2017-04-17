#include<stdio.h>
#include<stdlib.h>
#define MAX_qa 10
int queue_arr[MAX_qa];
int rear_qa=-1;
int front_qa=-1;
void insert_qa(int item);
int del_qa();
int peek_qa();
void display_qa();
int isFull_qa();
int isEmpty_qa();
void queue_a()
{
    int choice,item;
    printf ("\t\t\t\tQUEUE OPERATION\n");
    while(1)
    {
        printf("1.insert\n");
        printf("2.Delete\n");
        printf("3.Display element at the front\n");
        printf("4.Display all elements of the queue\n");
        printf("5.To go back\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            system("clear");
            printf ("\t\t\t\tQUEUE OPERATION\n");
            printf("Input the element for adding in queue : ");
            scanf("%d",&item);
            insert_qa(item);
            break;
        case 2:
            system("clear");
            printf ("\t\t\t\tQUEUE OPERATION\n");
            item=del_qa();
            printf("Deleted element is  %d\n",item);
            break;
        case 3:
            system("clear");
            printf ("\t\t\t\tQUEUE OPERATION\n");
            printf("Element at the front is %d\n",peek_qa());
            break;
        case 4:
            system("clear");
            printf ("\t\t\t\tQUEUE OPERATION\n");
            display_qa();
            break;
        case 5:
            system("clear");
            printf ("\t\t\t\tQUEUE OPERATION\n");
            return;
            break;
        }
    }
}
void insert_qa(int item)
{
    if( isFull_qa() )
    {
        printf("Queue Overflow\n");
        return;
    }
    if( front_qa == -1 )
        front_qa=0;
    rear_qa=rear_qa+1;
    queue_arr[rear_qa]=item ;
}
int del_qa()
{
    int item;
    if( isEmpty_qa() )
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    item=queue_arr[front_qa];
    front_qa=front_qa+1;
    return item;
}
int peek_qa()
{
    if( isEmpty_qa() )
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    return queue_arr[front_qa];
}
int isEmpty_qa()
{
    if( front_qa==-1 || front_qa==rear_qa+1 )
        return 1;
    else
        return 0;
}
int isFull_qa()
{
    if( rear_qa==MAX_qa-1 )
        return 1;
    else  return 0;
}
void display_qa()
{
    int i;
    if ( isEmpty_qa() )
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is :\n\n");
    for(i=front_qa; i<=rear_qa; i++)
        printf("%d  ",queue_arr[i]);
    printf("\n\n");
}
