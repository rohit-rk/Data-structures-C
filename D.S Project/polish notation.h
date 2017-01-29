#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50
void push_p(long int symbol);
long int pop_p();
void infix_to_postfix();
long int eval_post();
int priority(char symbol);
int isEmpty();
int white_space(char);

char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;

int white_space(char symbol)
{
    if( symbol == BLANK || symbol == TAB )
        return 1;
    else
        return 0;
}/*End of white_space()*/

void polish()
{
    long int value;
    char ch;
    top=-1;
    system("cls");
    printf ("\t\t\t\tPOLISH NOTATION and EVALUATION\n");
    printf("Enter infix : ");
    gets(infix);
    infix_to_postfix();
    printf("Postfix : %s\n",postfix);
    printf("want to evaluate expression");
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y')
    {
        value=eval_post();
        printf("Value of expression : %ld\n",value);
    }
    printf("PRESS ANY BUTTON TO GO BACK");
    getch();
    return;
}/*End of main()*/

void infix_to_postfix()
{
    unsigned int i,p=0;
    char next;
    char symbol;
    for(i=0; i<strlen(infix); i++)
    {
        symbol=infix[i];
        if(!white_space(symbol))
        {
            switch(symbol)
            {
            case '(':
                push_p(symbol);
                break;
            case ')':
                while((next=pop_p())!='(')
                    postfix[p++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while( !isEmpty( ) &&  priority(stack[top])>= priority(symbol) )
                    postfix[p++]=pop_p();
                push_p(symbol);
                break;
            default: /*if an operand comes*/
                postfix[p++]=symbol;
            }
        }
    }
    while(!isEmpty( ))
        postfix[p++]=pop_p();
    postfix[p]='\0'; /*End postfix with'\0' to make it a string*/
}/*End of infix_to_postfix()*/

/*This function returns the priority of the operator*/
int priority(char symbol)
{
    switch(symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default :
        return 0;
    }
}/*End of priority()*/

void push_p(long int symbol)
{
    if(top>MAX)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top]=symbol;
}/*End of push_p()*/

long int pop_p()
{
    if( isEmpty() )
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return (stack[top--]);
}/*End of pop_p()*/
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}/*End of isEmpty()*/


long int eval_post()
{
    long int a,b,temp,result;
    unsigned int i;

    for(i=0; i<strlen(postfix); i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
            push_p(postfix[i]-'0');
        else
        {
            a=pop_p();
            b=pop_p();
            switch(postfix[i])
            {
            case '+':
                temp=b+a;
                break;
            case '-':
                temp=b-a;
                break;
            case '*':
                temp=b*a;
                break;
            case '/':
                temp=b/a;
                break;
            case '%':
                temp=b%a;
                break;
            case '^':
                temp=pow(b,a);
            }
            push_p(temp);
        }
    }
    result=pop_p();
    return result;
}/*End of eval_post */
