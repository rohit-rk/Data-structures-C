#include <stdio.h>
#define MAXSIZE 5
struct stack
{
    int stk[MAXSIZE];
    int top_sa;
};
typedef struct stack STACK;
STACK s;
void push_sa(void);
int  pop_sa(void);
void display_sa(void);
void stack_a()
{
    int choice;
    int option = 1;
    s.top_sa = -1;

    printf("\t\t\t\tSTACK OPERATION\n");
    while (option)
    {
        printf("\n");
        printf("1-->push\n");
        printf("2-->pop\n");
        printf("3-->display\n");
        printf("4-->To go back\n");
        printf("\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            printf("\t\t\t\tSTACK OPERATION\n");
            push_sa();
            break;
        case 2:
            system("cls");
            printf("\t\t\t\tSTACK OPERATION\n");
            pop_sa();
            break;
        case 3:
            system("cls");
            printf("\t\t\t\tSTACK OPERATION\n");
            display_sa();
            break;
        case 4:
            system("cls");
            printf("\t\t\t\tSTACK OPERATION\n");
            return;
        }

    }
}
void push_sa ()
{
    int num;
    if (s.top_sa == (MAXSIZE - 1))
    {
        printf("Stack is Full\n");
        return;
    }
    else
    {
        printf("Enter the element to be pushed\n");
        scanf("%d", &num);
        s.top_sa = s.top_sa + 1;
        s.stk[s.top_sa]=num;
    }
    return;
}
int pop_sa ()
{
    int num;
    if (s.top_sa == - 1)
    {
        printf("Stack is Empty\n");
        return (s.top_sa);
    }
    else
    {
        num = s.stk[s.top_sa];
        printf("poped element is = %d", s.stk[s.top_sa]);
        s.top_sa = s.top_sa - 1;
    }
    return(num);
}
void display_sa ()
{
    int i;
    if (s.top_sa == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("\n The status of the stack is \n");
        for (i = s.top_sa; i >= 0; i--)
        {
            printf("%d\n", s.stk[i]);
        }
    }
    printf("\n");
}
