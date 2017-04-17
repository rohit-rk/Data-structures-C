#include<stdio.h>
#include<stdlib.h>
#define MAX_dq 7

int deque_arr[MAX_dq];
int front_dq=-1;
int rear_dq=-1;

void insert_frontEnd(int item);
void insert_rearEnd(int item);
int delete_frontEnd();
int delete_rearEnd();
void display_dq();
int isEmpty_dq();
int isFull_dq();

void dq()
{
    int choice,item;
    system("clear");
    printf ("\t\t\t\tDEQUEUE OPERATION\n");
    while(1)
    {
        printf("1.Insert at the front end\n");
        printf("2.Insert at the rear end\n");
        printf("3.Delete from front end\n");
        printf("4.Delete from rear end\n");
        printf("5.Display\n");
        printf("6.To go back\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            system("clear");
            printf ("\t\t\t\tDEQUEUE OPERATION\n");
            printf("Input the element for adding in queue : ");
            scanf("%d",&item);
            insert_frontEnd(item);
            break;
        case 2:
            system("clear");
            printf ("\t\t\t\tDEQUEUE OPERATION\n");
            printf("Input the element for adding in queue : ");
            scanf("%d",&item);
            insert_rearEnd(item);
            break;
        case 3:
            system("clear");
            printf ("\t\t\t\tDEQUEUE OPERATION\n");
            printf("Element deleted from front end is : %d\n",delete_frontEnd());
            break;
        case 4:
            system("clear");
            printf ("\t\t\t\tDEQUEUE OPERATION\n");
            printf("Element deleted from rear end is : %d\n",delete_rearEnd());
            break;
        case 5:
            system("clear");
            printf ("\t\t\t\tDEQUEUE OPERATION\n");
            display_dq();
            break;
        case 6:
            system("clear");
            printf ("\t\t\t\tDEQUEUE OPERATION\n");
            return;
        default:
            system("clear");
            printf ("\t\t\t\tDEQUEUE OPERATION\n");
            printf("Wrong choice\n");
        }/*End of switch*/
        printf("front = %d, rear =%d\n", front_dq , rear_dq);
        display_dq();
    }/*End of while*/
}/*End of main()*/

void insert_frontEnd(int item)
{
    if( isFull_dq() )
    {
        printf("Queue Overflow\n");
        return;
    }
    if( front_dq==-1 )/*If queue is initially empty*/
    {
        front_dq=0;
        rear_dq=0;
    }
    else if(front_dq==0)
        front_dq=MAX_dq-1;
    else
        front_dq=front_dq-1;
    deque_arr[front_dq]=item ;
}/*End of insert_frontEnd()*/

void insert_rearEnd(int item)
{
    if( isFull_dq() )
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front_dq==-1)  /*if queue is initially empty*/
    {
        front_dq=0;
        rear_dq=0;
    }
    else if(rear_dq==MAX_dq-1)  /*rear is at last position of queue */
        rear_dq=0;
    else
        rear_dq=rear_dq+1;
    deque_arr[rear_dq]=item ;
}/*End of insert_rearEnd()*/

int delete_frontEnd()
{
    int item;
    if( isEmpty_dq() )
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    item=deque_arr[front_dq];
    if(front_dq==rear_dq) /*Queue has only one element */
    {
        front_dq=-1;
        rear_dq=-1;
    }
    else if(front_dq==MAX_dq-1)
        front_dq=0;
    else
        front_dq=front_dq+1;
    return item;
}/*End of delete_frontEnd()*/

int delete_rearEnd()
{
    int item;
    if( isEmpty_dq() )
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    item=deque_arr[rear_dq];

    if(front_dq==rear_dq) /*queue has only one element*/
    {
        front_dq=-1;
        rear_dq=-1;
    }
    else if(rear_dq==0)
        rear_dq=MAX_dq-1;
    else
        rear_dq=rear_dq-1;
    return item;
}/*End of delete_rearEnd() */

int isFull_dq()
{
    if ( (front_dq==0 && rear_dq==MAX_dq-1) || (front_dq==rear_dq+1) )
        return 1;
    else
        return 0;
}/*End of isFull_dq()*/

int isEmpty_dq()
{
    if( front_dq == -1)
        return 1;
    else
        return 0;
}/*End of isEmpty_dq()*/

void display_dq()
{
    int i;
    if( isEmpty_dq() )
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    i=front_dq;
    if( front_dq<=rear_dq )
    {
        while(i<=rear_dq)
            printf("%d ",deque_arr[i++]);
    }
    else
    {
        while(i<=MAX_dq-1)
            printf("%d ",deque_arr[i++]);
        i=0;
        while(i<=rear_dq)
            printf("%d ",deque_arr[i++]);
    }
    printf("\n");
}/*End of display() */

