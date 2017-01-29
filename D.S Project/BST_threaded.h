#include <stdio.h>
#include <stdlib.h>

typedef enum {false,true} boolean;

struct node *in_succ(struct node *p);
struct node *in_pred(struct node *p);
struct node *insert_thread(struct node *root, int ikey);
struct node *del_thread(struct node *root, int dkey);
struct node *case_a(struct node *root, struct node *par,struct node *ptr);
struct node *case_b(struct node *root,struct node *par,struct node *ptr);
struct node *case_c(struct node *root, struct node *par,struct node *ptr);

void inorder_thread( struct node *root);
void preorder_thread( struct node *root);

struct node
{
    struct node *left;
    boolean lthread;
    int info;
    boolean rthread;
    struct node *right;
};

void threaded()
{
    int choice,num;
    struct node *root=NULL;
    system("cls");
    printf("\t\t\t\tBinary Search Tree(Threaded)\n");
    while(1)
    {
        printf("\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.inorder Traversal\n");
        printf("4.preorder Traversal\n");
        printf("5.Quit\n");
        printf("6.To go back\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            system("cls");
            printf("\t\t\t\tBinary Search Tree(Threaded)\n");
            printf("Enter the number to be inserted : ");
            scanf("%d",&num);
            root = insert_thread(root,num);
            break;
        case 2:
            system("cls");
            printf("\t\t\t\tBinary Search Tree(Threaded)\n");
            printf("Enter the number to be deleted : ");
            scanf("%d",&num);
            root = del_thread(root,num);
            break;
        case 3:
            system("cls");
            printf("\t\t\t\tBinary Search Tree(Threaded)\n");
            inorder_thread(root);
            break;
        case 4:
            system("cls");
            printf("\t\t\t\tBinary Search Tree(Threaded)\n");
            preorder_thread(root);
            break;
        case 5:
            system("cls");
            printf("\t\t\t\tBinary Search Tree(Threaded)\n");
            exit(1);
        case 6:
            system("cls");
            printf("\t\t\t\tBinary Search Tree(Threaded)\n");
            return;
        default:
            system("cls");
            printf("\t\t\t\tBinary Search Tree(Threaded)\n");
            printf("Wrong choice\n");
        }/*End of switch */
    }/*End of while */
}/*End of main( )*/

struct node *insert_thread(struct node *root, int ikey)
{
    struct node *tmp,*par,*ptr;

    int found=0;

    ptr = root;
    par = NULL;

    while( ptr!=NULL )
    {
        if( ikey == ptr->info)
        {
            found =1;
            break;
        }
        par = ptr;
        if(ikey < ptr->info)
        {
            if(ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if(ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    if(found)
        printf("Duplicate key");
    else
    {

        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=ikey;
        tmp->lthread = true;
        tmp->rthread = true;
        if(par==NULL)
        {
            root=tmp;
            tmp->left=NULL;
            tmp->right=NULL;
        }
        else if( ikey < par->info )
        {
            tmp->left=par->left;
            tmp->right=par;
            par->lthread=false;
            par->left=tmp;
        }
        else
        {
            tmp->left=par;
            tmp->right=par->right;
            par->rthread=false;
            par->right=tmp;
        }
    }
    return root;
}/*End of insert( )*/

struct node *del_thread(struct node *root, int dkey)
{
    struct node *par,*ptr;

    int found=0;

    ptr = root;
    par = NULL;

    while( ptr!=NULL)
    {
        if( dkey == ptr->info)
        {
            found =1;
            break;
        }
        par = ptr;
        if(dkey < ptr->info)
        {
            if(ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if(ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    if(found==0)
        printf("dkey not present in tree");
    else if(ptr->lthread==false && ptr->rthread==false)/*2 children*/
        root = case_c(root,par,ptr);
    else if(ptr->lthread==false )/*only left child*/
        root = case_b(root, par,ptr);
    else if(ptr->rthread==false)/*only right child*/
        root = case_b(root, par,ptr);
    else /*no child*/
        root = case_a(root,par,ptr);
    return root;
}/*End of del( )*/

struct node *case_a(struct node *root, struct node *par,struct node *ptr )
{
    if(par==NULL) /*root node to be deleted*/
        root=NULL;
    else if(ptr==par->left)
    {
        par->lthread=true;
        par->left=ptr->left;
    }
    else
    {
        par->rthread=true;
        par->right=ptr->right;
    }
    free(ptr);
    return root;
}/*End of case_a( )*/

struct node *case_b(struct node *root,struct node *par,struct node *ptr)
{
    struct node *child,*s,*p;

    /*Initialize child*/
    if(ptr->lthread==false)
        child=ptr->left;
    else
        child=ptr->right;


    if(par==NULL )
        root=child;
    else if( ptr==par->left)
        par->left=child;
    else
        par->right=child;

    s=in_succ(ptr);
    p=in_pred(ptr);

    if(ptr->lthread==false) /*if ptr has left subtree */
        p->right=s;
    else
    {
        if(ptr->rthread==false) /*if ptr has right subtree*/
            s->left=p;
    }

    free(ptr);
    return root;
}
struct node *case_c(struct node *root, struct node *par,struct node *ptr)
{
    struct node *succ,*parsucc;
    parsucc = ptr;
    succ = ptr->right;
    while(succ->left!=NULL)
    {
        parsucc = succ;
        succ = succ->left;
    }

    ptr->info = succ->info;

    if(succ->lthread==true && succ->rthread==true)
        root = case_a(root, parsucc,succ);
    else
        root = case_b(root, parsucc,succ);
    return root;
}
struct node *in_succ(struct node *ptr)
{
    if(ptr->rthread==true)
        return ptr->right;
    else
    {
        ptr=ptr->right;
        while(ptr->lthread==false)
            ptr=ptr->left;
        return ptr;
    }
}
struct node *in_pred(struct node *ptr)
{
    if(ptr->lthread==true)
        return ptr->left;
    else
    {
        ptr=ptr->left;
        while(ptr->rthread==false)
            ptr=ptr->right;
        return ptr;
    }
}

void inorder_thread( struct node *root)
{
    struct node *ptr;
    if(root == NULL )
    {
        printf("Tree is empty");
        return;
    }

    ptr=root;
    /*Find the leftmost node */
    while(ptr->lthread==false)
        ptr=ptr->left;

    while( ptr!=NULL )
    {
        printf("%d ",ptr->info);
        ptr=in_succ(ptr);
    }
}

void preorder_thread(struct node *root )
{
    struct node *ptr;
    if(root==NULL)
    {
        printf("Tree is empty");
        return;
    }
    ptr=root;

    while(ptr!=NULL)
    {
        printf("%d ",ptr->info);
        if(ptr->lthread==false)
            ptr=ptr->left;
        else if(ptr->rthread==false)
            ptr=ptr->right;
        else
        {
            while(ptr!=NULL && ptr->rthread==true)
                ptr=ptr->right;
            if(ptr!=NULL)
                ptr=ptr->right;
        }
    }
}

