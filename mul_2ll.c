#include<stdio.h>
#include<malloc.h>
typedef struct ll
{
    int data;
    struct ll *next;
}node;
node* gn(int data)
{
    node *x=(node*)malloc(sizeof(node));
    x->data=data;
    return x;
}
void append(node **h,int data)
{
    node *x=gn(data);
    x->next=NULL;
    if(*h==NULL)
    {
        *h=x;
    }
    else
    {
        node *t=*h;
        while(t->next!=NULL)
            t=t->next;
        t->next=x;
    }
}
int count(node *h)
{
    int c=0;
    while(h!=NULL)
    {
        c++;
        h=h->next;
    }
    return c;
}
long mul(node *h,long c1)
{
    long z;
    if(h==NULL)
        return 0;
    z=mul(h->next,c1/10);
    return (z+(h->data)*c1);
}
long  multiplyTwoLists (node* l1, node* l2)
{
    long c2=1,c1=1,m1,m2,mult;
    int c=count(l1);
    while(--c)
    {
        c1*=10;
    }
    m1=mul(l1,c1);
    c=count(l2);
    while(--c)
    {
        c2*=10;
    }
    m2=mul(l2,c2);
    printf("m1=%ld m2=%ld\n",m1,m2);
    mult=m1*m2;
    return mult;
}
int main()
{
    int data,n;
    node *h1=NULL,*h2=NULL;
    printf("Enter the size of 1st linked list : ");
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&data);
        append(&h1,data);
    }
    printf("Enter the size of 2nd linked list : ");
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&data);
        append(&h2,data);
    }
    printf("multiplied value : %ld",multiplyTwoLists (h1,h2));
    return 0;
}
