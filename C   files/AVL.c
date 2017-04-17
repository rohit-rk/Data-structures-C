#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 100
struct AVL
{
    int data;
    int bal;
    struct AVL *lchild, *rchild;
};
struct AVL *insert(struct AVL *, int);
struct AVL *rotate_right(struct AVL *);
struct AVL *rotate_left(struct AVL *);
struct AVL *left_check(struct AVL *, int *);
struct AVL *left_balance(struct AVL *);
struct AVL *right_check(struct AVL *, int *);
struct AVL * right_balance(struct AVL *);



struct AVL *rotate_right(struct AVL *pptr)
{
    struct AVL *aptr;
    aptr = pptr->lchild;
    pptr->lchild = aptr->rchild;
    aptr->rchild = pptr;
    return aptr;
}

struct AVL *rotate_left(struct AVL *pptr)
{
    struct AVL *aptr;
    aptr = pptr->rchild;
    pptr->rchild = aptr->lchild;
    aptr->lchild = pptr;
    return aptr;
}

struct AVL *insert(struct AVL *root, int item)
{
    static int taller;
    if(root==NULL)
    {
        root = (struct AVL *) malloc(sizeof(struct AVL));
        root->lchild = NULL;
        root->rchild = NULL;
        root->bal = 0;
        taller = 1;
    }
    if (item < root->data)
    {
        root->lchild = insert(root->lchild, item);
        if(taller)
            root = left_check(root,&taller);
    }

    else if (item > root->data)
    {
        root->rchild = insert(root->rchild, item);
        if(taller)
            root = right_check(root,&taller);
    }
    else
        printf("\nDuplicate Keys\n");
}

struct AVL *left_check(struct AVL *pptr, int *taller)
{
    switch(pptr->bal)
    {
    case 0:
        pptr->bal = 1;
        break;
    case 1:
        pptr = left_balance(pptr);
        *taller = 0;
        break;
    case -1:
        pptr->bal = 0;
        *taller = 0;
        break;
    }
    return pptr;
}

struct AVL *left_balance(struct AVL *pptr)
{
    struct AVL *bptr,*aptr = pptr->lchild;
    if(aptr->bal==1)
    {
        aptr->bal = 0;
        pptr->bal = 0;
        pptr = rotate_right(pptr);
    }
    else
    {
        bptr = aptr->rchild;
        switch(bptr->bal)
        {
        case 0:
            pptr->bal = 0;
            aptr->bal = 0;
            break;
        case -1:
            pptr->bal = 0;
            aptr->bal = 1;
            break;
        case 1:
            pptr->bal = -1;
            aptr->bal = 0;
            break;
        }
        bptr->bal = 0;
        pptr->lchild = rotate_left(pptr->lchild);
        pptr = rotate_right(pptr);
    }
    return pptr;
}

struct AVL *right_check(struct AVL *pptr, int *taller)
{
    switch(pptr->bal)
    {
    case 0:
        pptr->bal = -1;
        break;
    case -1:
        pptr = right_balance(pptr);
        *taller = 0;
        break;
    case 1:
        pptr->bal = 0;
        *taller = 0;
        break;
    }
    return pptr;
}

struct AVL * right_balance(struct AVL *pptr)
{
    struct AVL *bptr,*aptr = pptr->rchild;
    if(aptr->bal == -1)
    {
        aptr->bal = 0;
        pptr->bal = 0;
        pptr = rotate_left(pptr);
    }
    else
    {
        bptr = aptr->lchild;
        switch(bptr->bal)
        {
        case 0:
            pptr->bal = 0;
            aptr->bal = 0;
            break;
        case -1:
            pptr->bal = 1;
            aptr->bal = 0;
            break;
        case 1:
            pptr->bal = 0;
            aptr->bal = -1;
            break;
        }
        bptr->bal = 0;
        pptr->rchild = rotate_right(pptr->rchild);
        pptr = rotate_left(pptr);
    }
    return pptr;
}

void inorder_avl(struct AVL *temp)
{
    if(temp != NULL)
    {
        inorder_avl(temp->lchild);
        printf("\t%d", temp->data);
        inorder_avl(temp->rchild);
    }
}
/*
 This function displays the tree in preorder_avl fashion recursively
 */
void preorder_avl(struct AVL *temp)
{
    if(temp != NULL)
    {
        printf("\t%d", temp->data);
        preorder_avl(temp->lchild);
        preorder_avl(temp->rchild);
    }
}

/*
 This function displays the tree in postorder_avl fashion recursively
 */
void postorder_avl(struct AVL *temp)
{
    if(temp != NULL)
    {
        postorder_avl(temp->lchild);
        postorder_avl(temp->rchild);
        printf("\t%d", temp->data);
    }
}
struct AVL *search(struct AVL *root, int key, struct AVL **parent)
{
    struct AVL *temp;
    temp = root;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("\nThe %d Element is Present", temp->data);
            return temp;
        }
        *parent = temp;

        if (temp->data > key)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }
    return NULL;
}
main()
{
    int key,choice;
    char ans='y';
    struct AVL *root,*tmp,*parent;
    root = NULL;
    tmp = NULL;
    parent = NULL;
    system("clear");
    printf("\t\t\t\tAVL TREE\n");
    do
    {
        printf("\n0.Exit");
        printf("\n1.Create");
        printf("\n2.Search");
        printf("\n3.Recursive Traversals");
        printf("\n4.Non Recursive Traversals");
        printf("\n5.To go back");
        printf("\nEnter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                system("clear");
                printf("\t\t\t\tAVL TREE\n");
                printf("\nEnter The Element ");
                scanf("%d", &key);
                root=insert(root, key);
                printf("\nWant To enter More Elements?(y/n)\n\n\n\n\n\n");
                ans = getch();
            }
            while (ans == 'y');
            break;

        case 2:
            system("clear");
            printf("\t\t\t\tAVL TREE\n");
            printf("\nEnter Element to be searched :");
            scanf("%d", &key);

            tmp = search(root, key, &parent);
            if(tmp==NULL)
            {
                printf("\nThe Element is not  Present");
                continue;
            }
            printf("\nParent of node %d is %d\n\n\n\n\n\n", tmp->data, parent->data);
            break;

        case 3:
            system("clear");printf("\t\t\t\tAVL TREE\n");
            if (root == NULL)
                printf("Tree Is Not Created\n\n\n\n\n\n");
            else
            {
                printf("\nThe inorder_avl display : ");
                inorder_avl(root);
                printf("\nThe preorder_avl display : ");
                preorder_avl(root);
                printf("\nThe postorder_avl display : ");
                postorder_avl(root);
                printf("\n\n\n\n\n\n");
            }
            break;
        case 4:
            printf("\t\t\t\tAVL TREE\n");
            return;
            break;
        }
    }
    while (choice != 0);
}
