#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
struct tree
{
    char data;
    struct tree *left,*right;
};
int top_exp=-1;
struct tree *stack_exp[20];
struct tree *node;
void push_exp(struct tree* node)
{
    stack_exp[++top_exp]=node;
}
struct tree * pop_exp()
{
    return(stack_exp[top_exp--]);
}
int check(char ch)
{
if(ch=='+'||ch=='-'||ch=='/'||ch=='*')
return 2;
else
return 1;
}
/* Calculating the value of postfix expression using recursion */
int cal(struct tree *node)
{
    int ch;
    ch=check(node->data);
    if(ch==1)
    return node->data-48;
    else if(ch==2)
    {
        if(node->data=='+')
            return cal(node->left)+cal(node->right);
        if(node->data=='-')
            return cal(node->left)-cal(node->right);
        if(node->data=='*')
            return cal(node->left)*cal(node->right);
        if(node->data=='/')
            return cal(node->left)/cal(node->right);
    }
}/* Displaying all node in order */
void inorder(struct tree *node)
{
    if(node!=NULL)
    {
    inorder(node->left);
    printf("%c",node->data);
    inorder(node->right);
    }
}
// Checking operator and operands making simple operand node and pushing into stack
void operand(char b)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=b;
    node->left=NULL;
    node->right=NULL;
    push_exp(node);
}
/* making operator node than pop-up two nodes from stack and adding into operator node and finally push node into stack  */
void operators(char a)
{
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=a;
    node->right=pop_exp();
    node->left=pop_exp();
    push_exp(node);
}
void expressiontree()
{
    int p,ans,i;
    char s[20];
    printf("\t\t\t\t EXPRESSION TREE \n");
    printf("Enter the expression in postfix form \n");
    fflush(stdin);
    gets(s);
    int k;
    k=strlen(s);
    for(i=0;s[i]!='\0';i++)
        {
            p=check(s[i]);
            if(p==1)
            operand(s[i]);
            else if(p==2)
            operators(s[i]);
        }
    ans=cal(stack_exp[top_exp]);
    printf("\nThe value of the postfix expression you entered is %d\n",ans);
    printf("\nThe inorder traversal of the tree is \n");
    inorder(stack_exp[top_exp]);
    printf("\nPRESS ANY BUTTON TO GO BACK");
    getch();
    return;
}
