#include<stdio.h>
#include<malloc.h>
typedef struct
{
    int rno;
    char name[20];
    int sem;
    char branch[3];
} st;
void sortfiles()
{
    st *p[10];
    int i,j=0;
    system("cls");
    printf("\t\t\t\tPROGRAM TO SORT DATA FROM FILES\n");
    for(i=0; i<10; i++)
    {
        p[i]=(st*)calloc(1,sizeof(st));
    }
    st *t=NULL;

    FILE *fp1=fopen("student.txt","r");
    if(fp1==NULL)
    {
        printf("file unable to open");
        return ;
    }
    i=0;
    while(!feof(fp1))
    {
        ///printf("reading a block of data...%d\n",i);
        fscanf(fp1,"%d%s%d%s",&(p[i]->rno),p[i]->name,&(p[i]->sem),p[i]->branch);
        ///printf("read a block of data\n");
        i++;
    }
    fclose(fp1);
    p[i]=NULL;
    for(i=0; p[i]!=NULL; i++)
    {
        for(j=0; p[j]!=NULL; j++)
        {
            if((p[j]->rno)>=p[i]->rno)
            {
                t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
            j++;
        }
        i++;
    }
    printf("out of sorting\n");
    i++;
    p[i]=NULL;
    i=0;
    FILE *fp2=fopen("sort.txt","w");
    if(fp2==NULL)
    {
        printf("\nunable to create the file...");
        return ;
    }
    while(p[i]!=NULL)
    {
        ///printf("writing a block of data...");
        printf("%d %s %d %s \n",p[i]->rno,p[i]->name,p[i]->sem,p[i]->branch);
        if(p[i]!=NULL)
            fprintf(fp2,"%d %s %d %s \n",p[i]->rno,p[i]->name,p[i]->sem,p[i]->branch);
        ///printf("wrote a block of data");
        i++;
    }
    fclose(fp2);
    i=0;
    FILE *fp=fopen("sort.txt","r");
    printf("Contents of the file are:\n\n\n");
    while(!feof(fp))
    {
        printf("%c",fgetc(fp));
    }
    printf("PRESS ANY BUTTON TO GO BACK");
    getch();
    return;
}
