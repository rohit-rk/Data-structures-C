#include<stdio.h>
#include<stdlib.h>
struct node_ql
{
	int info;
	struct node_ql *link_ql;
}*front_ql=NULL,*rear_ql=NULL;

void insert_ql(int item);
int del_ql();
int peek_ql();
int isEmpty_ql();
void display_ql();

void queue_l()
{
    int choice,item;
    printf ("\t\t\t\tImplementation of Queue with link_qled list\n");
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
            system("clear");
            printf ("\t\t\t\tImplementation of Queue with link_qled list\n");
            printf("Input the element for adding in queue : ");
            scanf("%d",&item);
            insert_ql(item);
            break;
        case 2:
            system("clear");
            printf ("\t\t\t\tImplementation of Queue with link_qled list\n");
            item=del_ql();
            printf("Deleted element is  %d\n",item);
            break;
        case 3:
            system("clear");
            printf ("\t\t\t\tImplementation of Queue with link_qled list\n");
            printf("Element at the front is %d\n",peek_ql());
            break;
        case 4:
            system("clear");
            printf ("\t\t\t\tImplementation of Queue with link_qled list\n");
            display_ql();
            break;
        case 5:
            system("clear");
            printf ("\t\t\t\tImplementation of Queue with link_qled list\n");
            return;
            break;
        }
    }
}
void insert_ql(int item)
{
	struct node_ql *tmp;
	tmp=(struct node_ql *)malloc(sizeof(struct node_ql));
	if(tmp==NULL)
	{
		printf("Memory not available\n");
		return;
	}
	tmp->info = item;
	tmp->link_ql=NULL;
	if(front_ql==NULL)
		front_ql=tmp;
	else
		rear_ql->link_ql=tmp;
	rear_ql=tmp;
}

int del_ql()
{
	struct node_ql *tmp;
	int item;
	if( isEmpty_ql( ) )
	{
		printf("Queue Underflow\n");

	}
	tmp=front_ql;
	item=tmp->info;
	front_ql=front_ql->link_ql;
	free(tmp);
	return item;
}

int peek_ql()
{
	if( isEmpty_ql( ) )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return front_ql->info;
}

int isEmpty_ql()
{
	if(front_ql==NULL)
		return 1;
	else
		return 0;

}

void display_ql()
{
	struct node_ql *ptr;
	ptr=front_ql;
	if(isEmpty_ql())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link_ql;
	}
	printf("\n\n");
}
