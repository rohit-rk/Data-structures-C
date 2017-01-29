#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
}*front=NULL,*rear=NULL;

void insert(int item);
int del();
int peek();
int isEmpty();
void display();

main()
{
    int choice,item;
    printf ("\t\t\t\tImplementation of Queue with Linked list\n");
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
            printf ("\t\t\t\tImplementation of Queue with Linked list\n");
            printf("Input the element for adding in queue : ");
            scanf("%d",&item);
            insert(item);
            break;
        case 2:
            system("cls");
            printf ("\t\t\t\tImplementation of Queue with Linked list\n");
            item=del();
            printf("Deleted element is  %d\n",item);
            break;
        case 3:
            system("cls");
            printf ("\t\t\t\tImplementation of Queue with Linked list\n");
            printf("Element at the front is %d\n",peek());
            break;
        case 4:
            system("cls");
            printf ("\t\t\t\tImplementation of Queue with Linked list\n");
            display();
            break;
        case 5:
            system("cls");
            printf ("\t\t\t\tImplementation of Queue with Linked list\n");
            return;
            break;
        }
    }
}
void insert(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Memory not available\n");
		return;
	}
	tmp->info = item;
	tmp->link=NULL;
	if(front==NULL)
		front=tmp;
	else
		rear->link=tmp;
	rear=tmp;
}

int del()
{
	struct node *tmp;
	int item;
	if( isEmpty( ) )
	{
		printf("Queue Underflow\n");

	}
	tmp=front;
	item=tmp->info;
	front=front->link;
	free(tmp);
	return item;
}

int peek()
{
	if( isEmpty( ) )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return front->info;
}

int isEmpty()
{
	if(front==NULL)
		return 1;
	else
		return 0;

}

void display()
{
	struct node *ptr;
	ptr=front;
	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link;
	}
	printf("\n\n");
}
