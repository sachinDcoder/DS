#include<stdio.h>
#include<stdlib.h>
void InsertNode();
void DeleteNode();
void VeiwNodes();
struct node
{
    int info;
    struct node *link;
};
struct node *START = NULL;
struct node *CreateNode()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    return(n);
};
int main()
{
    int ch;
    printf("1. Add value in the list at last\n");
    printf("2. delete first value\n");
    printf("3. view list\n");
    printf("4. exit\n");

    while(1)
    {
        printf("enter your choice : ");
        fflush(stdin);
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            InsertNode();
            break;
        case 2:
            DeleteNode();
            break;
        case 3:
            VeiwNodes();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice\n");
        }
    }
    return 0;
}
void InsertNode()
{
    struct node *temp,*t;
    temp=CreateNode();
    printf("enter a number to be added : ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(START==NULL)
        START=temp;
    else
    {
        t=START;
        while(t->link!=NULL)
            t=t->link;
        t->link=temp;
    }
}
void DeleteNode()
{
    struct node *r;
    if(START==NULL)
        printf("list is empty\n");
    else
    {
        r=START;
        START=START->link;
        free(r);
    }
}
void VeiwNodes()
{
    struct node *t;
    if(START==NULL)
        printf("list is empty\n");
    else
    {
        t=START;
        while(t!=NULL)
        {
            printf("%d ",t->info);
            t=t->link;
        }
        printf("\n");
    }
}
