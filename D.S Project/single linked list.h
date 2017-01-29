#include<stdio.h>
#include<malloc.h>
struct node_sll
{
    int info;
    struct node_sll *link;
};

struct node_sll *create_list_s(struct node_sll *start);
void display_s(struct node_sll *start);
void search_s(struct node_sll *start,int data);
struct node_sll *addatbeg_s(struct node_sll *start,int data);
struct node_sll *addatend_s(struct node_sll *start,int data);
struct node_sll *addafter_s(struct node_sll *start,int data,int item);
struct node_sll *addbefore_s(struct node_sll *start,int data,int item );
struct node_sll *addatpos_s(struct node_sll *start,int data,int pos);
struct node_sll *del_s(struct node_sll *start,int data);
struct node_sll *reverse_s(struct node_sll *start);

void linkedlist_s()
{
    struct node_sll *start=NULL;
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
        printf("6.Add after node_sll\n");
        printf("7.Add before node_sll\n");
        printf("8.Add at position\n");
        printf("9.delete\n");
        printf("10.reverse\n");
        printf("11.TO GO BACK\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            start=create_list_s(start);
            break;
        case 2:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            display_s(start);
            break;
        case 3:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be searched : ");
            scanf("%d",&data);
            search_s(start,data);
            break;
        case 4:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start=addatbeg_s(start,data);
            break;
        case 5:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start=addatend_s(start,data);
            break;
        case 6:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the element after which to insert : ");
            scanf("%d",&item);
            start=addafter_s(start,data,item);
            break;
        case 7:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the element before which to insert : ");
            scanf("%d",&item);
            start=addbefore_s(start,data,item);
            break;
        case 8:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the position at which to insert : ");
            scanf("%d",&pos);
            start=addatpos_s(start,data,pos);
            break;
        case 9:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be deleted : ");
            scanf("%d",&data);
            start=del_s(start, data);
            break;
        case 10:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            start=reverse_s(start);
            break;
        case 11:
            return;
            break;
        default:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Wrong choice\n");
        }
    }
}

struct node_sll *create_list_s(struct node_sll *start)
{
    int i,n,data;
    printf("Enter the number of node : ");
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

void display_s(struct node_sll *start)
{
    struct node_sll *p;
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

void search_s(struct node_sll *start,int item)
{
    struct node_sll *p=start;
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

struct node_sll *addatbeg_s(struct node_sll *start,int data)
{
    struct node_sll *tmp;
    tmp=(struct node_sll *)malloc(sizeof(struct node_sll));
    tmp->info=data;
    tmp->link=start;
    start=tmp;
    return start;
}

struct node_sll *addatend_s(struct node_sll *start,int data)
{
    struct node_sll *p,*tmp;
    tmp=(struct node_sll *)malloc(sizeof(struct node_sll));
    tmp->info=data;
    p=start;
    while(p->link!=NULL)
        p=p->link;
    p->link=tmp;
    tmp->link=NULL;
    return start;
}

struct node_sll *addafter_s(struct node_sll *start,int data,int item)
{
    struct node_sll *tmp,*p;
    p=start;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            tmp=(struct node_sll *)malloc(sizeof(struct node_sll));
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

struct node_sll *addbefore_s(struct node_sll *start,int data,int item)
{
    struct node_sll *tmp,*p;
    if(start==NULL )
    {
        printf("List is empty\n");
        return start;
    }

    if(item==start->info)
    {
        tmp=(struct node_sll *)malloc(sizeof(struct node_sll));
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
            tmp=(struct node_sll *)malloc(sizeof(struct node_sll));
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

struct node_sll *addatpos_s(struct node_sll *start,int data,int pos)
{
    struct node_sll *tmp,*p;
    int i;
    tmp=(struct node_sll *)malloc(sizeof(struct node_sll));
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

struct node_sll *del_s(struct node_sll *start,int data)
{
    struct node_sll *tmp,*p;
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

struct node_sll *reverse_s(struct node_sll *start)
{
    struct node_sll *prev, *ptr, *next;
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
