#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
}*rear_cl=NULL;

void insert_cl(int item);
int del_cl();
void display_cl();
int isEmpty_cl();
int peek_cl();
cqueue_l()
{
    int choice,item;
    printf ("\t\t\t\tImplementation of Circular Queue with Linked list\n");
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
            printf ("\t\t\t\tImplementation of Circular Queue with Linked list\n");
            printf("Input the element for adding in queue : ");
            scanf("%d",&item);
            insert_cl(item);
            break;
        case 2:
            system("cls");
            printf ("\t\t\t\tImplementation of Circular Queue with Linked list\n");
            item=del_cl();
            printf("Deleted element is  %d\n",item);
            break;
        case 3:
            system("cls");
            printf ("\t\t\t\tImplementation of Circular Queue with Linked list\n");
            printf("Element at the front is %d\n",peek_cl());
            break;
        case 4:
            system("cls");
            printf ("\t\t\t\tImplementation of Circular Queue with Linked list\n");
            display_cl();
            break;
        case 5:
            system("cls");
            printf ("\t\t\t\tImplementation of Circular Queue with Linked list\n");
            return;
            break;
        }
    }
}
void insert_cl(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=item;
	if(tmp==NULL)
	{
		printf("Memory not available\n");
		return;
	}

	if( isEmpty_cl() ) /*If queue is empty */
	{
		rear_cl=tmp;
		tmp->link=rear_cl;
	}
	else
	{
		tmp->link=rear_cl->link;
		rear_cl->link=tmp;
		rear_cl=tmp;
	}
}/*End of insert()*/
del_cl()
{
	int item;
	struct node *tmp;
	if( isEmpty_cl() )
	{
		printf("Queue underflow\n");
		exit(1);
	}
	if(rear_cl->link==rear_cl)  /*If only one element*/
	{
		tmp=rear_cl;
		rear_cl=NULL;
	}
	else
	{
		tmp=rear_cl->link;
		rear_cl->link=rear_cl->link->link;
	}
	item=tmp->info;
	free(tmp);
	return item;
}/*End of del()*/
int peek_cl()
{
	if( isEmpty_cl() )
	{
		printf("Queue underflow\n");
		exit(1);
	}
	return rear_cl->link->info;
}/* End of peek() */
int isEmpty_cl()
{
	if( rear_cl == NULL )
		return 1;
	else
		return 0;
}/*End of isEmpty_cl()*/
void display_cl()
{
	struct node *p;
	if(isEmpty_cl())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue is :\n");
	p=rear_cl->link;
	do
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=rear_cl->link);
	printf("\n");
}/*End of display()*/

