#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<header.h>
void main()
{
    int i;
    int choice;
    system("cls");
    show();
    getout();
    getch();
    system("cls");
    show();
    while(choice)
    {
        printf("\nPROGRAMS:\n");
        printf("\t1.LINKED LISTS\n");
        printf("\t2.STACKS\n");
        printf("\t3.QUEUES\n");
        printf("\t4.SORTING\n");
        printf("\t5.SEARCHING\n");
        printf("\t6.TREES\n");
        printf("\t7.VECTORS\n");
        printf("\t8.Array Elements Sum\n");
        printf("\t9.Sorting File Data\n");
        printf("\t10.Exit\n");
        printf("Enter your choice:  ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            programs_list();
            break;
        case 2:
            programs_stack();
            break;
        case 3:
            program_queue();
            break;
        case 4:
            program_sort();
            break;
        case 5:
            program_search();
            break;
        case 6:
            program_trees();
            break;
        case 7:
            vect();
            break;
        case 8:
            arraysum();
            break;
        case 9:
            sortfiles();
            break;
        case 10:
            system("cls");
            getout();
            exit(0);
            break;
        default:
            printf("\n\t Invalid choice\n");
        }
        system("pause");
        system("cls");
        main();
    }
}

