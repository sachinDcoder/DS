#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *prev,*next;
};
struct node *start=NULL;
void insertNodein1st()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    printf("enter a number");
    scanf("%d",&n->info);
    n->prev=NULL;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else
    {
        start->prev=n;
        n->next=start;
        start=n;
    }
}
void deleteFirstNode()
{
    struct node *r;
    if(start==NULL)
        printf("list is empty");
    else
    {
        r=start;
        start=start->next;
        start->prev=NULL;
        free(r);
    }
}
void viewList()
{
    struct node *t;
    if(start==NULL)
        printf("list is empty");
    else
    {
        t=start;
        while(t!=NULL)
        {
            printf("%d ",t->info);
            t=t->next;
        }
        printf("\n");
    }
}
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
            insertNodein1st();
            break;
        case 2:
            deleteFirstNode();
            break;
        case 3:
            viewList();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice\n");
        }
    }
    return 0;
}






