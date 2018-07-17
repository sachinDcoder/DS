#include<stdio.h>
#include<stdlib.h>
#define N NULL
typedef struct linkedlist
{
    int d;
    struct linkedlist *n;
}node;
node* gn(int data)
{
    node *x;
    x=(node*)malloc(sizeof(node));
    x->d=data;
    return x;
}
void append(node **h,int data)
{
    node *x;
    x=gn(data);
    x->n=N;
    if(*h==N)
        *h=x;
    else
    {
        node *t=*h;
        while(t->n!=N)
            t=t->n;
        t->n=x;
    }
}
void addbeg(node **h,int data)
{
    node *x;
    x=gn(data);
    x->n=*h;
    *h=x;
}
void display(node *h)
{
    while(h!=N)
    {
       printf(" %d",h->d);
       h=h->n;
    }
}
void insert(node *y,int data)
{
    node *x;
    x=gn(data);
    x->n=y->n;
    y->n=x;
}
node* searchp(node *h,int z)
{
    node *p=N;
    while(h!=N)
    {
        if(h->d==z)
            return p;
        else
        {
            p=h;
            h=h->n;
        }
    }
}
void addbefore (node **h,int z,int data)
{
    if((*h)->d==z)
        addbeg(h,data);
    else
    {
        node *p=searchp(h,z);
        if(p!=N)
            insert(p,data);
    }
}
node* search(node *h,int z)
{
    while(h!=N)
    {
        if(h->d==z)
            return h;
        else
            h=h->n;
    }
}
void addafter (node **h,int z,int data)
{
    if((*h)->d==z)
        addbeg(h,data);
    else
    {
        node *p=search(h,z);
        insert(p,data);
    }
}
int delbeg(node **h)
{
    int a;
    node *p;
    if(*h!=N)
    {
        p=*h;
        *h=(*h)->n;
        a=p->d;
        free(p);
        return a;
    }
}
int del(node *p)
{
    node *t=p->n;
    p->n=t->n;
    int z=t->d;
    free(t);
    return z;
}
void deleteN(node **h,int z)
{
    int data;
    if((*h)->d==z)
        data=delbeg(h);
    else
    {
        node *p=searchp(h,z);
        if(p!=N)
            data=del(p);
    }
}
int delAtEnd(node **h)
{
    int data;
    node *t=*h,*p=N;
    if(*h==N)
        return;
    while(t->n!=N)
    {
        p=t;
        t=t->n;
    }
    data=t->d;
    p->n=N;
    free(t);
    return data;
}
void reverse(node **h)
{
    node *a=N,*b=*h,*c;
    do
    {
        c=b->n;
        b->n=a;
        a=b;
        b=c;
    }while(b!=N);
    *h=a;
}
main()
{
    node *h=N;
    int choice,z,data;
    printf("1. append\n");
    printf("2. add at beginning\n");
    printf("3. insert before\n");
    printf("4. insert after\n");
    printf("5. delete at beginning\n");
    printf("6. delete\n");
    printf("7. delete at end\n");
    printf("8. reverse the list\n");
    printf("9. display\n");
    printf("0. exit\n");
    while(1)
    {
        printf("\nenter a choice from above : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter the data to append : ");
                scanf("%d",&data);
                append(&h,data);
                break;
            case 2:
                printf("enter the data to add at beginning : ");
                scanf("%d",&data);
                addbeg(&h,data);
                break;
            case 3:
                printf("enter the data before which you want to insert : ");
                scanf("%d",&z);
                printf("enter the data to insert : ");
                scanf("%d",&data);
                addbefore(&h,z,data);
                break;
            case 4:
                printf("enter the data after which you want to insert : ");
                scanf("%d",&z);
                printf("enter the data to insert : ");
                scanf("%d",data);
                addafter(&h,z,data);
                break;
            case 5:
                printf(" the deleted item is %d\n",delbeg(&h));
                break;
            case 6:
                printf("enter the value to be deleted : ");
                scanf("%d",&z);
                deleteN(&h,z);
                break;
            case 7:
                printf(" the deleted item is %d\n",delAtEnd(&h));
                break;
            case 8:
                reverse(&h);
                printf("the list has been reversed\n");
                break;
            case 9:
                display(h);
                break;
            case 0:
                exit(0);
        }
    }
    return 0;
}





