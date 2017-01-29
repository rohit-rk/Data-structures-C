#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 100
struct BST
{
    int data;
    struct BST *lchild, *rchild;
};

struct BST *stack_bst[max];
int top_bst=-1;

void push_bst(struct BST *);
struct BST *pop_bst();
int ifempty_bst();
void insert_bst(struct BST *, struct BST *);
void inorder_bst(struct BST  *);
void nr_inorder_bst(struct BST *);
void preorder_bst(struct BST *);
void nr_preorder_bst(struct BST *);
void postorder_bst(struct BST *);
void nr_postorder_bst(struct BST *);
struct BST *search_bst(struct BST *, int,struct BST **);
void print(struct BST *,int k1,int k2);

void print(struct BST *root,int k1,int k2)
{
    struct BST *node=root;
    while(1)
    {
        while(node->lchild!=NULL)
        {
            push_bst(node);
            node=node->lchild;
        }
        while(node->rchild==NULL)
        {
            if((node->data>=k1 )& (node->data<=k2))
               {
                   printf("\t%d",node->data);
               }
            if(ifempty_bst())
                return;
            node=pop_bst();
        }
        if((node->data>=k1)&(node->data<=k2))
            {printf("\t%d",node->data);}
        node=node->rchild;
    }
}
/*
 Get new Node
 */
struct BST *get_node()
{
    struct BST *temp;
    temp = (struct BST *) malloc(sizeof(struct BST));
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

/*Function gives Height of the tree*/
int height(struct BST *tree)
{
    int l_ht,r_ht;
    if(tree==NULL)
        return 0;
    l_ht=height(tree->lchild);
    r_ht=height(tree->rchild);
    if(l_ht>r_ht)
        return 1+l_ht;
    else
        return 1+r_ht;
}

struct BST *bstdel(struct BST *ptr, int dkey)
{
	struct BST *tmp, *succ;

	if( ptr == NULL)
	{
		printf("dkey not found\n");
		return(ptr);
	}
	if( dkey < ptr->data )/*delete from left subtree*/
		ptr->lchild = bstdel(ptr->lchild, dkey);
	else if( dkey > ptr->data )/*delete from right subtree*/
		ptr->rchild = bstdel(ptr->rchild, dkey);
	else
	{
		/*key to be deleted is found*/
		if( ptr->lchild!=NULL  &&  ptr->rchild!=NULL )  /*2 children*/
		{
			succ=ptr->rchild;
			while(succ->lchild)
				succ=succ->lchild;
			ptr->data=succ->data;
			ptr->rchild = bstdel(ptr->rchild, succ->data);
		}
		else
		{
			tmp = ptr;
			if( ptr->lchild != NULL ) /*only left child*/
				ptr = ptr->lchild;
			else if( ptr->rchild != NULL) /*only right child*/
				ptr = ptr->rchild;
			else	/* no child */
				ptr = NULL;
			free(tmp);
		}
	}
	return ptr;
}/*End of del( )*/

struct BST *bstMin(struct BST *ptr)
{
	if(ptr==NULL)
		return NULL;
	else if(ptr->lchild==NULL)
        return ptr;
	else
		return bstMin(ptr->lchild);
}/*End of min()*/

struct BST *bstMax(struct BST *ptr)
{
	if(ptr==NULL)
		return NULL;
	else if(ptr->rchild==NULL)
        return ptr;
	else
		return bstMax(ptr->rchild);
}/*End of max()*/
/*Function gives Height of the node*/
int node_height(struct BST *tree,int item)
{
    struct BST *node,*parent;
    node=search_bst(tree,item,&parent);
    return height(node);
}

void bst()
{
    int choice;
    char ans = 'N';
    int key,ht;
    struct BST *new_node, *root, *tmp, *parent;
    root = NULL;
    system("cls");
    int k1,k2;
    printf("\t\t\t\tBinary Search Tree\n");
    do
    {
        printf("\n0.Exit");
        printf("\n1.Create");
        printf("\n2.Search");
        printf("\n3.Delete");
        printf("\n4.Recursive Traversals");
        printf("\n5.Non Recursive Traversals");
        printf("\n6.preorder Traversal");
		printf("\n7.inorder Traversal");
		printf("\n8.postorder Traversal");
		printf("\n9.Find minimum and maximum");
        printf("\n10.Height of the Tree");
        printf("\n11.print elements in range k1 to k2");
        printf("\n12.To go back");
        printf("\nEnter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                system("cls");
                printf("\t\t\t\tBinary Search Tree\n");
                new_node = get_node();
                printf("\nEnter The Element ");
                scanf("%d", &new_node->data);

                if (root == NULL) /* Tree is not Created */
                    root = new_node;
                else
                    insert_bst(root, new_node);

                printf("\nWant To enter More Elements?(y/n)\n\n\n\n\n\n");
                ans = getch();
            }
            while (ans == 'y');
            break;

        case 2:
            system("cls");
            printf("\t\t\t\tBinary Search Tree\n");
            printf("\nEnter Element to be searched :");
            scanf("%d", &key);

            tmp = search_bst(root, key, &parent);
            printf("\nParent of node %d is %d\n\n\n\n\n\n", tmp->data, parent->data);
            break;
        case 3:
			printf("Enter the key to be deleted : ");
			scanf("%d",&key);
			root = bstdel(root,key);
        case 4:
            system("cls");
            printf("\t\t\t\tBinary Search Tree\n");
            if (root == NULL)
                printf("Tree Is Not Created\n\n\n\n\n\n");
            else
            {
                printf("\nThe inorder display : ");
                inorder_bst(root);
                printf("\nThe preorder display : ");
                preorder_bst(root);
                printf("\nThe postorder display : ");
                postorder_bst(root);
                printf("\n\n\n\n\n\n");
            }
            break;
        case 5:
            system("cls");
            printf("\t\t\t\tBinary Search Tree\n");
            if (root == NULL)
                printf("Tree Is Not Created\n\n\n\n\n\n");
            else
            {
                printf("\nThe inorder display : ");
                nr_inorder_bst(root);
                printf("\nThe preorder display : ");
                nr_preorder_bst(root);
                printf("\nThe postorder display : ");
                nr_postorder_bst(root);
                printf("\n\n\n\n\n\n");
            }
            break;
        case 6:
			preorder_bst(root);
			break;
        case 7:
			inorder_bst(root);
			break;
        case 8:
			postorder_bst(root);
			break;
        case 9:
			tmp = bstMin(root);
			if(tmp!=NULL)
				printf("Minimum key is %d\n", tmp->data );
			tmp = bstMax(root);
			if(tmp!=NULL)
				printf("Maximum key is %d\n", tmp->data );
			break;
        case 10:
            system("cls");
            printf("\t\t\t\tBinary Search Tree\n");
            ht=height(root);
            printf("\nHeight of the tree is :%d\n\n\n\n\n\n",ht);
            break;
        case 11:
            system("cls");
            printf("\t\t\t\tBinary Search Tree\n");
            printf("Enter k1: ");
            scanf("%d",&k1);
            printf("Enter k2: ");
            scanf("%d",&k2);
            print(root,k1,k2);
            break;
        case 12:
			return;
			break;
        }
    }
    while (choice != 0);
}
/*
 This function is for creating a binary search tree
 */
void insert_bst(struct BST *root, struct BST *new_node)
{
    if (new_node->data < root->data)
    {
        if (root->lchild == NULL)
            root->lchild = new_node;
        else
            insert_bst(root->lchild, new_node);
    }

    if (new_node->data > root->data)
    {
        if (root->rchild == NULL)
            root->rchild = new_node;
        else
            insert_bst(root->rchild, new_node);
    }
}
/*
 This function is for searching the node from
 binary Search Tree
 */
struct BST *search_bst(struct BST *root, int key, struct BST **parent)
{
    struct BST *temp;
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
/*
 This function displays the tree in inorder fashion recursively
 */
void inorder_bst(struct BST *temp)
{
    if(temp != NULL)
    {
        inorder_bst(temp->lchild);
        printf("\t%d", temp->data);
        inorder_bst(temp->rchild);
    }
}
/*
 This function displays the tree in preorder_bst fashion recursively
 */
void preorder_bst(struct BST *temp)
{
    if(temp != NULL)
    {
        printf("\t%d", temp->data);
        preorder_bst(temp->lchild);
        preorder_bst(temp->rchild);
    }
}

/*
 This function displays the tree in postorder_bst fashion recursively
 */
void postorder_bst(struct BST *temp)
{
    if(temp != NULL)
    {
        postorder_bst(temp->lchild);
        postorder_bst(temp->rchild);
        printf("\t%d", temp->data);
    }
}

/*This is push function to stack_bst*/
void push_bst(struct BST *item)
{
    if(top_bst==(max-1))
    {
        printf("stack Overflow\n");
        return;
    }
    top_bst++;
    stack_bst[top_bst]=item;
}

/*This is pop function to stack_bst*/
struct BST *pop_bst()
{
    struct BST *item;
    if(top_bst==-1)
    {
        printf("stack Underflow\n");
        exit(1);
    }
    item=stack_bst[top_bst];
    top_bst--;
    return item;
}

/*This is a function to check if stack_bst is empty*/
int ifempty_bst()
{
    if(top_bst==-1)
        return 1;
    else
        return 0;
}

/*
 This function displays the tree in inorder_bst fashion non recursively
 */
void nr_inorder_bst(struct BST *temp)
{
    struct BST *node=temp;
    while(1)
    {
        while(node->lchild!=NULL)
        {
            push_bst(node);
            node=node->lchild;
        }
        while(node->rchild==NULL)
        {
            printf("\t%d",node->data);
            if(ifempty_bst())
                return;
            node=pop_bst();
        }
        printf("\t%d",node->data);
        node=node->rchild;
    }
}
/*
 This function displays the tree in preorder_bst fashion non recursively
 */
void nr_preorder_bst(struct BST *temp)
{
    struct BST *node=temp;
    push_bst(node);
    while(!ifempty_bst())
    {
        node=pop_bst();
        printf("\t%d",node->data);
        if(node->rchild!=NULL)
            push_bst(node->rchild);
        if(node->lchild!=NULL)
            push_bst(node->lchild);
    }
}

/*
 This function displays the tree in postorder_bst fashion non recursively
 */
void nr_postorder_bst(struct BST *temp)
{
    struct BST *ptr=temp,*node=temp;
    while(1)
    {
        while(node->lchild!=NULL)
        {
            push_bst(node);
            node=node->lchild;
        }
        while(node->rchild==NULL||node->rchild==ptr)
        {
            printf("\t%d",node->data);
            ptr=node;
            if(ifempty_bst())
                return;
            node=pop_bst();
        }
        push_bst(node);
        node=node->rchild;
    }
}
