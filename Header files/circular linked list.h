#include<stdio.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *link;
};

struct node *create_list_c(struct node *);
void display_c(struct node *);
void search_c(struct node *,int );
struct node *addatbeg_c(struct node *,int );
struct node *addatend_c(struct node *,int );
struct node *addafter_c(struct node *,int ,int );
struct node *del_c(struct node *,int );

struct node *addtoempty(struct node *last,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    last=tmp;
    last->link=last;
    return last;
}
struct node *create_list_c(struct node *last)
{
    int i,n,data;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    last=NULL;
    if(n==0)
        return last;
    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    last=addtoempty(last,data);

    for(i=2; i<=n; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        last=addatend_c(last,data);
    }
    return last;
}


struct node *addatbeg_c(struct node *last,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=last->link;
    last->link=tmp;
    return last;
}

struct node *addatend_c(struct node *last,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=last->link;
    last->link=tmp;
    last=tmp;
    return last;
}

struct node *addafter_c(struct node *last,int data,int item)
{
    struct node *tmp,*p;
    p=last->link;
    do
    {
        if(p->info==item)
        {
            tmp=(struct node *)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            if(p==last)
                last=tmp;
            return last;
        }
        p=p->link;
    }
    while(p!=last->link);
    printf("%d not present in the list\n",item);
    return last;
}

struct node *del_c(struct node *last,int data)
{
    struct node *tmp,*p;
    if(last==NULL)
    {
        printf("List is empty\n");
        return last;
    }

    if(last->link==last && last->info==data)
    {
        tmp=last;
        last=NULL;
        free(tmp);
        return last;
    }

    if(last->link->info==data)
    {
        tmp=last->link;
        last->link=tmp->link;
        free(tmp);
        return last;
    }

    p=last->link;
    while(p->link!=last)
    {
        if(p->link->info==data)
        {
            tmp=p->link;
            p->link=tmp->link;
            free(tmp);
            return last;
        }
        p=p->link;
    }

    if(last->info==data)
    {
        tmp=last;
        p->link=last->link;
        last=p;
        free(tmp);
        return last;
    }
    printf("Element %d not found\n",data);
    return last;
}

void display_c(struct node *last)
{
    struct node *p;
    if(last==NULL)
    {
        printf("List is empty\n");
        return;
    }
    p=last->link;
    do
    {
        printf("%d ",p->info);
        p=p->link;
    }
    while(p!=last->link);
    printf("\n");
}

linkedlist_c()
{
    struct node *start=NULL;
    int ch=1,data,item,pos;
    printf("\t\t\t\tCIRCULAR LINKED LIST");
    while(ch!=0)
    {
        printf("\n\n\n\n\n");
        printf("1.Create List\n");
        printf("2.display\n");
        printf("3. Add at beginning\n");
        printf("4.Add at end\n");
        printf("5.Add after node\n");
        printf("6.delete\n");
        printf("7.To go back\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            start=create_list_c(start);
            break;
        case 2:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            display_c(start);
            break;
        case 3:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start=addatbeg_c(start,data);
            break;
        case 4:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            start=addatend_c(start,data);
            break;
        case 5:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            printf("Enter the element after which to insert : ");
            scanf("%d",&item);
            start=addafter_c(start,data,item);
            break;
        case 6:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Enter the element to be deleted : ");
            scanf("%d",&data);
            start=del_c(start, data);
            break;
            case 7:
                return;
                break;
        default:
            system("clear");
            printf("\t\t\t\tSINGLE LINKED LIST\n");
            printf("Wrong choice\n");
        }
    }
}
