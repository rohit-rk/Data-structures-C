#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
}*rear=NULL;

void insert(int item);
int del();
void display();
int isEmpty();
int peek();

main()
{
    int choice,item;
    printf ("\t\t\t\tImplementation of Circular Queue with Linked list\n");
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
            system("clear");
            printf ("\t\t\t\tImplementation of Circular Queue with Linked list\n");
            printf("Input the element for adding in queue : ");
            scanf("%d",&item);
            insert(item);
            break;
        case 2:
            system("clear");
            printf ("\t\t\t\tImplementation of Circular Queue with Linked list\n");
            item=del();
            printf("Deleted element is  %d\n",item);
            break;
        case 3:
            system("clear");
            printf ("\t\t\t\tImplementation of Circular Queue with Linked list\n");
            printf("Element at the front is %d\n",peek());
            break;
        case 4:
            system("clear");
            printf ("\t\t\t\tImplementation of Circular Queue with Linked list\n");
            display();
            break;
        case 5:
            system("clear");
            printf ("\t\t\t\tImplementation of Circular Queue with Linked list\n");
            return;
            break;
        }
    }
}
void insert(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=item;
	if(tmp==NULL)
	{
		printf("Memory not available\n");
		return;
	}

	if( isEmpty() ) /*If queue is empty */
	{
		rear=tmp;
		tmp->link=rear;
	}
	else
	{
		tmp->link=rear->link;
		rear->link=tmp;
		rear=tmp;
	}
}/*End of insert()*/
del()
{
	int item;
	struct node *tmp;
	if( isEmpty() )
	{
		printf("Queue underflow\n");
		exit(1);
	}
	if(rear->link==rear)  /*If only one element*/
	{
		tmp=rear;
		rear=NULL;
	}
	else
	{
		tmp=rear->link;
		rear->link=rear->link->link;
	}
	item=tmp->info;
	free(tmp);
	return item;
}/*End of del()*/
int peek()
{
	if( isEmpty() )
	{
		printf("Queue underflow\n");
		exit(1);
	}
	return rear->link->info;
}/* End of peek() */
int isEmpty()
{
	if( rear == NULL )
		return 1;
	else
		return 0;
}/*End of isEmpty()*/
void display()
{
	struct node *p;
	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue is :\n");
	p=rear->link;
	do
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=rear->link);
	printf("\n");
}/*End of display()*/

