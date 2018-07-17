#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define N NULL
typedef struct ll
{
    int d;
    struct ll *n;
}node;
node* gn(int data)
{
    node *x=(node*)malloc(sizeof(node));
    x->d=data;
    return x;
}
void insert(node **h,int data)
{
    node *x=gn(data);
    if(*h==N)
    {
        x->n=N;
        *h=x;
    }
    else
    {
        x->n=*h;
        *h=x;
    }
}
/*node* reverse(node *h)
{
    node *prev=N;
    node *curr=h;
    node *next;
    while(curr!=N)
    {
        next=curr->n;
        curr->n=prev;
        prev=curr;
        curr=next;
    }
    h=prev;
    return h;
}*/
int ispallindrome(node *h,node *r)
{
    if(h==N && r==N)
        return 1;
    while(h!=N && r!=N)
    {
        if(h->d!=r->d)
            return 0;
        h=h->n;
        r=r->n;
    }
    return 1;
}
void display(node *h)
{
    while(h!=N)
    {
        printf(" %d",h->d);
        h=h->n;
    }
}
int main()
{
    int d,t,n;
    node *h=N,*r=N;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&d);
            insert(&h,d);
        }
        node *t=h;
        while(t!=N)
        {
            insert(&r,t->d);
            t=t->n;
        }
        display(h);
        printf("\n");
        display(r);
        printf("\n");
        if(ispallindrome(h,r))
        printf("1\n");
        else
        printf("0\n");
    }
    /*
    printf("Enter your data(0 to terminate) \n");
    do
    {
        scanf("%d",&d);
        if(d==0)
            break;
        insert(&h,d);
    }while(d!=0);
    printf("\n");
    display(h);
    printf("\n");
    r=reverse(h);
    display(r);*/
    return 0;
}
