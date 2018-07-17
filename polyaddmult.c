#include<stdio.h>
#include<stdlib.h>
#define N NULL
typedef struct nd
{
    float c;
    int e;
    struct nd *n;
}node;
node* gn(float c,int e)
{
    node *x;
    x=(node *)malloc(sizeof(node));
    x->c=c;
    x->e=e;
    return x;
}
void append(node **p,float c,int e)
{
    node *t,*x=gn(c,e);
    x->n=N;
    if(*p==N)
        *p=x;
    else
    {
        t=*p;
        while(t->n!=N)
            t=t->n;
        t->n=x;
    }
}
node* padd(node *p1,node *p2)
{
    node *p3=N;
    while(p1!=N && p2!=N)
    {
        if(p1->e>p2->e)
        {
            append(&p3,p1->c,p1->e);
            p1=p1->n;
        }
        else if(p1->e<p2->e)
        {
            append(&p3,p2->c,p2->e);
            p2=p2->n;
        }
        else
        {
            append(&p3,(p2->c) + (p1->c),p2->e);
            p2=p2->n;
            p1=p1->n;
        }
    }
    while(p1!=N)
    {
        append(&p3,p1->c,p1->e);
        p1=p1->n;
    }
    while(p2!=N)
    {
        append(&p3,p2->c,p2->e);
        p2=p2->n;
    }
    return p3;
}
void dellist(node **s)
{
    node *t=N;
    while(*s!=N)
    {
        t=*s;
        *s=(*s)->n;
        free(t);
    }
}
node* pmult(node *p1,node *p2)
{
    node *t=N,*p3=N,*r=N;
    if(p1==N && p2==N)
        return;
    else if(p1==N && p2!=N)
        return p2;
    else if(p2==N && p1!=N)
        return p1;
    else
    {
        while(p2!=N)
        {
            t=p1;
            while(t!=N)
            {
                append(&r,(p2->c) * (t->c),(p2->e) + (t->e));
                t=t->n;
            }
            p3=padd(p3,r);
            p2=p2->n;
            dellist(&r);
        }
    }
    return p3;
}
void display(node *p)
{
    while(p!=N)
    {
        printf(" %.2fx^%d +",p->c,p->e);
        p=p->n;
    }
    printf("\b\n");
}
main()
{
    node *p1=N,*p2=N,*p3=N,*p4=N;
    float cof;
    int exp,i=1;
    char ch,choice;
    printf("enter the 1st polynomial\n");
    while(1)
    {
        printf("enter coefficient and exponent for %d term\n",i++);
        scanf("%f%d",&cof,&exp);
        append(&p1,cof,exp);
        printf("wanna enter more for 1st polynomial??..enter y or Y..otherwise any key : ");
        scanf("%s",&ch);
        if(ch=='y' || ch=='Y')
            continue;
        else
            break;
    }
    display(p1);
    i=1;
    printf("enter the 2nd polynomial\n");
    while(1)
    {
        printf("enter the %d term\n",i++);
        scanf("%f%d",&cof,&exp);
        append(&p2,cof,exp);
        printf("wanna enter more for 2nd polynomial??..enter y or Y..otherwise any key :");
        scanf("%s",&ch);
        if(ch=='y' || ch=='Y')
            continue;
        else
            break;
    }
    display(p2);
    printf("addition : ");
    p3=padd(p1,p2);
    display(p3);
    printf("multiplication : ");
    p4=pmult(p1,p2);
    display(p4);
    return 0;
}








