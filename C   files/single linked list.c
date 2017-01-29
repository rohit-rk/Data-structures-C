#include<stdio.h>
struct node
{
    int info;
    struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item );
struct node *addatpos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);

main()
{
    struct node *start=NULL;
    int ch,data,item,pos;
    printf("\t\t\t\tSINGLE LINKED LIST");
    while(1)
    {
        printf("\n\n\n\n\n");
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Search\n");
        printf("4. Add at beginning\n");
        printf("5.Add at end\n");
        printf("6.Add after node\n");
        printf("7.Add before node\n");
        printf("8.Add at position\n");
        printf("9.Delete\n");
        printf("10.Reverse\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            start=create_list(start);
            break;
        case 2:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            display(start);
            break;
        case 3:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be searched : ");
            scanf("%d",&data);
            search(start,data);
            break;
        case 4:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start=addatbeg(start,data);
            break;
        case 5:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start=addatend(start,data);
            break;
        case 6:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the element after which to insert : ");
            scanf("%d",&item);
            start=addafter(start,data,item);
            break;
        case 7:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the element before which to insert : ");
            scanf("%d",&item);
            start=addbefore(start,data,item);
            break;
        case 8:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the position at which to insert : ");
            scanf("%d",&pos);
            start=addatpos(start,data,pos);
            break;
        case 9:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be deleted : ");
            scanf("%d",&data);
            start=del(start, data);
            break;
        case 10:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            start=reverse(start);
            break;
        default:
            system("cls");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Wrong choice\n");
        }
    }
}

struct node *create_list(struct node *start)
{
    int i,n,data;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    start=NULL;
    if(n==0)
        return start;

    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    start=addatbeg(start,data);

    for(i=2; i<=n; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        start=addatend(start,data);
    }
    return start;
}

void display(struct node *start)
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

void search(struct node *start,int item)
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

struct node *addatbeg(struct node *start,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=start;
    start=tmp;
    return start;
}

struct node *addatend(struct node *start,int data)
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

struct node *addafter(struct node *start,int data,int item)
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

struct node *addbefore(struct node *start,int data,int item)
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

struct node *addatpos(struct node *start,int data,int pos)
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

struct node *del(struct node *start,int data)
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

struct node *reverse(struct node *start)
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
