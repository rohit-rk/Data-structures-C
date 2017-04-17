#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *link;
};

struct node *create_list_s(struct node *start);
void display_s(struct node *start);
void search_s(struct node *start,int data);
struct node *addatbeg_s(struct node *start,int data);
struct node *addatend_s(struct node *start,int data);
struct node *addafter_s(struct node *start,int data,int item);
struct node *addbefore_s(struct node *start,int data,int item );
struct node *addatpos_s(struct node *start,int data,int pos);
struct node *del_s(struct node *start,int data);
struct node *reverse_s(struct node *start);

linkedlist_s()
{
    struct node *start=NULL;
    int ch,data,item,pos;
    printf("\t\t\t\tSINGLE LINKED LIST");
    while(1)
    {
        printf("\n\n\n\n\n");
        printf("1.Create List\n");
        printf("2.display\n");
        printf("3.search\n");
        printf("4. Add at beginning\n");
        printf("5.Add at end\n");
        printf("6.Add after node\n");
        printf("7.Add before node\n");
        printf("8.Add at position\n");
        printf("9.delete\n");
        printf("10.reverse\n");
        printf("11.TO GO BACK\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            start=create_list_s(start);
            break;
        case 2:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            display_s(start);
            break;
        case 3:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be searched : ");
            scanf("%d",&data);
            search_s(start,data);
            break;
        case 4:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start=addatbeg_s(start,data);
            break;
        case 5:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start=addatend_s(start,data);
            break;
        case 6:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the element after which to insert : ");
            scanf("%d",&item);
            start=addafter_s(start,data,item);
            break;
        case 7:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the element before which to insert : ");
            scanf("%d",&item);
            start=addbefore_s(start,data,item);
            break;
        case 8:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the position at which to insert : ");
            scanf("%d",&pos);
            start=addatpos_s(start,data,pos);
            break;
        case 9:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be deleted : ");
            scanf("%d",&data);
            start=del_s(start, data);
            break;
        case 10:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            start=reverse_s(start);
            break;
        case 11:
            return;
            break;
        default:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Wrong choice\n");
        }
    }
}

struct node *create_list_s(struct node *start)
{
    int i,n,data;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    start=NULL;
    if(n==0)
        return start;

    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    start=addatbeg_s(start,data);

    for(i=2; i<=n; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        start=addatend_s(start,data);
    }
    return start;
}

void display_s(struct node *start)
{
    struct node *p;
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
        p=p->link;
    }
    printf("\n\n");
}

void search_s(struct node *start,int item)
{
    struct node *p=start;
    int pos=1;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            printf("Item %d found at position %d\n",item,pos);
            return;
        }
        p=p->link;
        pos++;
    }
    printf("Item %d not found in list\n",item);
}

struct node *addatbeg_s(struct node *start,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=start;
    start=tmp;
    return start;
}

struct node *addatend_s(struct node *start,int data)
{
    struct node *p,*tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    p=start;
    while(p->link!=NULL)
        p=p->link;
    p->link=tmp;
    tmp->link=NULL;
    return start;
}

struct node *addafter_s(struct node *start,int data,int item)
{
    struct node *tmp,*p;
    p=start;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            tmp=(struct node *)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            return start;
        }
        p=p->link;
    }
    printf("%d not present in the list\n",item);
    return start;
}

struct node *addbefore_s(struct node *start,int data,int item)
{
    struct node *tmp,*p;
    if(start==NULL )
    {
        printf("List is empty\n");
        return start;
    }

    if(item==start->info)
    {
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->link=start;
        start=tmp;
        return start;
    }
    p=start;
    while(p->link!=NULL)
    {
        if(p->link->info==item)
        {
            tmp=(struct node *)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            return start;
        }
        p=p->link;
    }
    printf("%d not present in the list\n",item);
    return start;
}

struct node *addatpos_s(struct node *start,int data,int pos)
{
    struct node *tmp,*p;
    int i;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    if(pos==1)
    {
        tmp->link=start;
        start=tmp;
        return start;
    }
    p=start;
    for(i=1; i<pos-1 && p!=NULL; i++)
        p=p->link;
    if(p==NULL)
        printf("There are less than %d elements\n",pos);
    else
    {
        tmp->link=p->link;
        p->link=tmp;
    }
    return start;
}

struct node *del_s(struct node *start,int data)
{
    struct node *tmp,*p;
    if(start==NULL)
    {
        printf("List is empty\n");
        return start;
    }

    if(start->info==data)
    {
        tmp=start;
        start=start->link;
        free(tmp);
        return start;
    }
    p=start;
    while(p->link!=NULL)
    {
        if(p->link->info==data)
        {
            tmp=p->link;
            p->link=tmp->link;
            free(tmp);
            return start;
        }
        p=p->link;
    }
    printf("Element %d not found\n",data);
    return start;
}

struct node *reverse_s(struct node *start)
{
    struct node *prev, *ptr, *next;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;
    return start;
}
