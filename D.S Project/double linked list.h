#include<stdio.h>
#include<malloc.h>
struct node_dll
{
    int info;
    struct node_dll *next,*prev;
};

struct node_dll *create_list_d(struct node_dll *start);
void display_d(struct node_dll *start);
void search_d(struct node_dll *start,int data);
struct node_dll *addatbeg_d(struct node_dll *start,int data);
struct node_dll *addatend_d(struct node_dll *start,int data);
struct node_dll *addafter_d(struct node_dll *start,int data,int item);
struct node_dll *addbefore_d(struct node_dll *start,int data,int item );
struct node_dll *del_d(struct node_dll *start,int data);
struct node_dll *reverse_d(struct node_dll *start);
struct node_dll *addtoempty_d(struct node_dll *start,int data);

void search_d(struct node_dll *start,int item)
{
    struct node_dll *p=start;
    int pos=1;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            printf("Item %d found at position %d\n",item,pos);
            return;
        }
        p=p->next;
        pos++;
    }
    printf("Item %d not found in list\n",item);
}


struct node_dll *create_list_d(struct node_dll *start)
{
    int i,n,data;
    printf("Enter the number of node_dlls : ");
    scanf("%d",&n);
    start=NULL;
    if(n==0)
        return start;
    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    start=addtoempty_d(start,data);

    for(i=2; i<=n; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        start=addatend_d(start,data);
    }
    return start;
}
void display_d(struct node_dll *start)
{
    struct node_dll *p;
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    p=start;
    printf("List is :\n");
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n");
}

struct node_dll *addtoempty_d(struct node_dll *start,int data)
{
    struct node_dll *tmp;
    tmp=(struct node_dll *)malloc(sizeof(struct node_dll));
    tmp->info=data;
    tmp->prev=NULL;
    tmp->next=NULL;
    start=tmp;
    return start;
}

struct node_dll *addatbeg_d(struct node_dll *start,int data)
{
    struct node_dll *tmp;
    tmp = (struct node_dll *)malloc(sizeof(struct node_dll));
    tmp->info=data;
    tmp->prev=NULL;
    tmp->next=start;
    start->prev=tmp;
    start=tmp;
    return start;
}
struct node_dll *addatend_d(struct node_dll *start,int data)
{
    struct node_dll *tmp,*p;
    tmp=(struct node_dll *)malloc(sizeof(struct node_dll));
    tmp->info=data;
    p=start;
    while(p->next!=NULL)
        p=p->next;
    p->next=tmp;
    tmp->next=NULL;
    tmp->prev=p;
    return start;
}
struct node_dll *addafter_d(struct node_dll *start,int data,int item)
{
    struct node_dll *tmp,*p;
    tmp=(struct node_dll *)malloc(sizeof(struct node_dll));
    tmp->info=data;
    p=start;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            tmp->prev=p;
            tmp->next=p->next;
            if(p->next!=NULL)
                p->next->prev=tmp;
            p->next=tmp;
            return start;
        }
        p=p->next;
    }
    printf("%d not present in the list\n\n",item);
    return start;
}
struct node_dll *addbefore_d(struct node_dll *start,int data,int item)
{
    struct node_dll *tmp,*q;
    if(start==NULL )
    {
        printf("List is empty\n");
        return start;
    }
    if(start->info==item)
    {
        tmp = (struct node_dll *)malloc(sizeof(struct node_dll));
        tmp->info=data;
        tmp->prev=NULL;
        tmp->next=start;
        start->prev=tmp;
        start=tmp;
        return start;
    }
    q=start;
    while(q!=NULL)
    {
        if(q->info==item)
        {
            tmp=(struct node_dll *)malloc(sizeof(struct node_dll));
            tmp->info=data;
            tmp->prev=q->prev;
            tmp->next = q;
            q->prev->next=tmp;
            q->prev=tmp;
            return start;
        }
        q=q->next;
    }
    printf("%d not present in the list\n",item);
    return start;
}
struct node_dll *del_d(struct node_dll *start,int data)
{
    struct node_dll *tmp;
    if(start==NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if(start->next==NULL)	/*only one node_dll in the list*/
        {if(start->info==data)
        {
            tmp=start;
            start=NULL;
            free(tmp);
            return start;
        }
        else
        {
            printf("Element %d not found\n",data);
            return start;
        }
        }
    if(start->info==data)
    {
        tmp=start;
        start=start->next;
        start->prev=NULL;
        free(tmp);
        return start;
    }

    tmp=start->next;
    while(tmp->next!=NULL )
    {
        if(tmp->info==data)
        {
            tmp->prev->next=tmp->next;
            tmp->next->prev=tmp->prev;
            free(tmp);
            return start;
        }
        tmp=tmp->next;
    }

    if(tmp->info==data)
    {
        tmp->prev->next=NULL;
        free(tmp);
        return start;
    }
    printf("Element %d not found\n",data);
    return start;
}

struct node_dll *reverse_d(struct node_dll *start)
{
    struct node_dll *p1,*p2;
    p1=start;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    start=p1;
    printf("List reverse_dd\n");
    return start;
}
void linkedlist_d()
{
    struct node_dll *start=NULL;
    int ch,data,item;
    printf("\t\t\t\tDOUBLE LINKED LIST");
    while(1)
    {
        printf("\n\n\n\n\n");
        printf("1.Create List\n");
        printf("2.display\n");
        printf("3.search\n");
        printf("4.Add at beginning\n");
        printf("5.Add at end\n");
        printf("6.Add after node_dll\n");
        printf("7.Add before node_dll\n");
        printf("8.Delete\n");
        printf("9.reverse\n");
        printf("10.To go back\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            system("clear");
            printf("\t\t\t\tDOUBLE LINKED LIST\n");
            start=create_list_d(start);
            break;
        case 2:
            system("clear");
            printf("\t\t\t\tDOUBLE LINKED LIST\n");
            display_d(start);
            break;
        case 3:
            system("clear");
            printf("\t\t\t\tDOUBLE LINKED LIST\n");
            printf("Enter the element to be searched : ");
            scanf("%d",&data);
            search_d(start,data);
            break;
        case 4:
            system("clear");
            printf("\t\t\t\tDOUBLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start=addatbeg_d(start,data);
            break;
        case 5:
            system("clear");
            printf("\t\t\t\tDOUBLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start=addatend_d(start,data);
            break;
        case 6:
            system("clear");
            printf("\t\t\t\tDOUBLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the element after which to insert : ");
            scanf("%d",&item);
            start=addafter_d(start,data,item);
            break;
        case 7:
            system("clear");
            printf("\t\t\t\tDOUBLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the element before which to insert : ");
            scanf("%d",&item);
            start=addbefore_d(start,data,item);
            break;

        case 8:
            system("clear");
            printf("\t\t\t\tDOUBLE LINKED LIST\n");
            printf("Enter the element to be deleted : ");
            scanf("%d",&data);
            start=del_d(start, data);
            break;
        case 9:
            system("clear");
            printf("\t\t\t\tDOUBLE LINKED LIST\n");
            start=reverse_d(start);
            break;
        case 10:
            return;
            break;
        default:
            system("clear");
            printf("\t\t\t\tDOUBLE LINKED LIST\n");
            printf("Wrong choice\n");
        }
    }
}
