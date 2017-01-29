programs_list()
{
    int i;
    int choicelink;
    system("cls");
    for(i=0;i<105;i++)
        printf("=");
    printf("\n\t\t\t\tLINKED LIST\n");
    for(i=0;i<105;i++)
        printf("=");
    while(1)
    {
        printf("\n1.Single linked list\n") ;
        printf("2.Double linked list\n");
        printf("3.Circular linked list\n");
        printf("4.To go back\n");
        printf("Enter your choice =");
        scanf("%d",&choicelink);
        switch(choicelink)
        {
        case 1:
            system("cls");
            printf("\t\t\t\tLINKED LIST\n");
            linkedlist_s();
            break;
        case 2:
            system("cls");
            printf("\t\t\t\tLINKED LIST\n");
            linkedlist_d();
            break;
        case 3:
            system("cls");
            printf("\t\t\t\tLINKED LIST\n");
            linkedlist_c();
            break;
        case 4:
            main();
            break;
        }
        system("pause");
        system("cls");
    }
}

programs_stack()
{
    int i;
    int choicestack;
    system("cls");
    for(i=0;i<105;i++)
        printf("=");
    printf("\n\t\t\t\tSTACKS\n");
    for(i=0;i<105;i++)
        printf("=");
    while(1)
    {
        printf("\n1.Array stack\n") ;
        printf("2.Linked list stack\n");
        printf("3.Double stack\n");
        printf("4.Polish notation\n");
        printf("5.To go back\n");
        printf("Enter your choice =");
        scanf("%d",&choicestack);
        switch(choicestack)
        {
        case 1:
            system("cls");
            printf("\t\t\t\tSTACKS\n");
            stack_a();
            break;
        case 2:
            system("cls");
            printf("\t\t\t\tSTACKS\n");
            stack_l();
            break;
        case 3:
            system("cls");
            printf("\t\t\t\tSTACKS\n");
            stack_2();
            break;
        case 4:
            system("cls");
            printf("\t\t\t\tSTACKS\n");
            polish();
            break;
        case 5:
            main();
            break;
        }
        system("pause");
        system("cls");
    }
}

program_queue()
{
    int i;
    int choicequeue;
    system("cls");
    for(i=0;i<105;i++)
        printf("=");
    printf("\n\t\t\t\tQUEUES\n");
    for(i=0;i<105;i++)
        printf("=");
    while(1)
    {
        printf("\n1.Array queue\n") ;
        printf("2.Linked list queue\n");
        printf("3.Circular array queue\n");
        printf("4.Circular linked queue\n");
        printf("5.Double ended queue\n");
        printf("6.To go back\n");
        printf("Enter your choice =");
        scanf("%d",&choicequeue);
        switch(choicequeue)
        {
        case 1:
            system("cls");
            printf("\t\t\t\tQUEUES\n");
            queue_a();
            break;
        case 2:
            system("cls");
            printf("\t\t\t\tQUEUES\n");
            queue_l();
            break;
        case 3:
            system("cls");
            printf("\t\t\t\tQUEUES\n");
            cqueue_a();
            break;
        case 4:
            system("cls");
            printf("\t\t\t\tQUEUES\n");
            cqueue_l();
            break;
        case 5:
            system("cls");
            printf("\t\t\t\tQUEUES\n");
            dq();
            break;
        case 6:
            main();
            break;
        }
        system("pause");
        system("cls");
    }
}
program_sort()
{
    int i;
    int choicesort;
    system("cls");
    for(i=0;i<105;i++)
        printf("=");
    printf("\n\t\t\t\tSORTING TECHNIQUES\n");
    for(i=0;i<105;i++)
        printf("=");
    while(1)
    {
        printf("\n1.Bubble sort\n") ;
        printf("2.Selection sort\n");
        printf("3.Insertion sort\n");
        printf("4.Merge sort\n");
        printf("5.Quick sort\n");
        printf("6.Heap sort\n");
        printf("7.To go back\n");
        printf("Enter your choice =");
        scanf("%d",&choicesort);
        switch(choicesort)
        {
        case 1:
            system("cls");
            printf("\t\t\t\tSORTING TECHNIQUES\n");
            bubblesort();
            break;
        case 2:
            system("cls");
            printf("\t\t\t\tSORTING TECHNIQUES\n");
            selectionsort();
            break;
        case 3:
            system("cls");
            printf("\t\t\t\tSORTING TECHNIQUES\n");
            insertionsort();
            break;
        case 4:
            system("cls");
            printf("\t\t\t\tSORTING TECHNIQUES\n");
            mergesort();
            break;
        case 5:
            system("cls");
            printf("\t\t\t\tSORTING TECHNIQUES\n");
            quicksort();
            break;
        case 6:
            system("cls");
            printf("\t\t\t\tSORTING TECHNIQUES\n");
            heapsort();
            break;
        case 7:
            main();
            break;
        }
        system("pause");
        system("cls");
    }
}
program_search()
{
    int i;
    int choicesearch;
    system("cls");
    for(i=0;i<105;i++)
        printf("=");
    printf("\n\t\t\t\tSEARCHING TECHNIQUES\n");
    for(i=0;i<105;i++)
        printf("=");
    while(1)
    {
        printf("\n1.Linear search\n") ;
        printf("2.Binary search\n");
        printf("3.Fibonacci search\n");
        printf("4.To go back\n");
        printf("Enter your choice =");
        scanf("%d",&choicesearch);
        switch(choicesearch)
        {
        case 1:
            system("cls");
            printf("\t\t\t\tSEARCHING TECHNIQUES\n");
            linearsearch();
            break;
        case 2:
            system("cls");
            printf("\t\t\t\tSEARCHING TECHNIQUES\n");
            binarysearch();
            break;
        case 3:
            system("cls");
            printf("\t\t\t\tSEARCHING TECHNIQUES\n");
            fibonaccisearch();
            break;
        case 4:
            main();
            break;
        }
        system("pause");
        system("cls");
    }
}
program_trees()
{
    int i;
    int choicetree;
    system("cls");
    for(i=0;i<105;i++)
        printf("=");
    printf("\n\t\t\t\tTREES\n");
    for(i=0;i<105;i++)
        printf("=");
    while(1)
    {
        printf("\n1.Complete binary tree\n") ;
        printf("2.Binary search tree \n");
        printf("3.BST Threaded tree\n");
        printf("4.Expression tree\n");
        printf("5.Heap tree\n");
        printf("6.AVL tree\n");
        printf("7.To go back\n");
        printf("Enter your choice =");
        scanf("%d",&choicetree);
        switch(choicetree)
        {
        case 1:
            system("cls");
            printf("\t\t\t\tTREES\n");
            binarytree();
            break;
        case 2:
            system("cls");
            printf("\t\t\t\tTREES\n");
            bst();
            break;
        case 3:
            system("cls");
            printf("\t\t\t\tTREES\n");
            threaded();
            break;
        case 4:
            system("cls");
            printf("\t\t\t\tTREES\n");
            expressiontree();
            break;
        case 5:
            system("cls");
            printf("\t\t\t\tTREES\n");
            heaptree();
            break;
        case 6:
            system("cls");
            printf("\t\t\t\tTREES\n");
            avl();
            break;
        case 7:
            main();
            break;
        }
        system("pause");
        system("cls");
    }
}
