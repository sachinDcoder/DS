/*implement a double ended queue by using doubly circular linked list*/
#include<stdio.h>
#include<stdlib.h>
#define N NULL
typedef struct c_dll
{
    int d;
    struct c_dll *p,*n;
}node;
node* gn(int z)
{
    node *x=(node*)malloc(sizeof(node));
    x->d=z;
    return x;
}
void enqueueR(node **r,int z)
{
    node *x=gn(z);
    if(*r==N)
    {
        x->p=x;
        x->n=x;
    }
    else
    {
        x->p=*r;
        x->n=(*r)->n;
        (*r)->n->p=x;
        (*r)->n=x;
    }
    *r=x;
}
void enqueueF(node **r,int z)
{
    node *x=gn(z);
    if(*r==N)
    {
        x->p=x;
        x->n=x;
        *r=x;
    }
    else
    {
        x->p=*r;
        x->n=(*r)->n;
        (*r)->n->p=x;
        (*r)->n=x;
    }
}
int dequeueF(node **r)
{
    int z;
    node *t=(*r)->n;
    if(*r==N)
        return;
    else
    {
        z=t->d;
        if((*r)->n==*r)
            free(*r);
        else
        {
            t->n->p=*r;
            (*r)->n=t->n;
            free(t);
        }
    }
    return z;
}
int dequeueR(node **r)
{
    int z;
    node *t=*r;
    if(*r==N)
        return;
    else
    {
        z=t->d;
        if((*r)->n==*r)
            free(*r);
        else
        {
            (*r)->n->p=(*r)->p;
            (*r)->p->n=(*r)->n;
            (*r)=(*r)->p;
            free(t);
        }
    }
    return z;
}
void display(node *r)
{
    node *t=r;
    do
    {
        printf(" %d",t->n->d);
        t=t->n;
    }while(t!=r);
}
int main()
{
    node *r=N;
    int choice,data;
    while(1)
    {
        printf("\nEnter your choice from the following\n");
        printf("1. insert in front\n");
        printf("2. insert in rear\n");
        printf("3. delete from front\n");
        printf("4. delete from rear\n");
        printf("5. display\n");
        printf("6. exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the data to inserted in front : ");
                scanf("%d",&data);
                enqueueF(&r,data);
                break;
            case 2:
                printf("\nEnter the data to inserted in rear : ");
                scanf("%d",&data);
                enqueueR(&r,data);
                break;
            case 3:
                printf("The deleted item from front is %d\n",dequeueF(&r));
                break;
            case 4:
                printf("The deleted item from rear is %d\n",dequeueR(&r));
                break;
            case 5:
                display(r);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\ninvalid choice\n");
        }
    }
}

