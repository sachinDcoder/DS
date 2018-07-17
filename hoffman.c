#include<stdio.h>
#include<stdlib.h>
#define N NULL
typedef struct q_tr
{
    int pri;
    char ch;
    struct q_tr *r,*l,*n;
}node;
node* gn(char ch,int pri)
{
    node *x=(node *)malloc(sizeof(node));
    x->pri=pri;
    x->ch=ch;
    x->l=N;
    x->r=N;
    return x;
}
void insert(node **h,char ch,int pri)
{
    node *t=*h,*x=gn(ch,pri);
    if(*h==N || (*h)->pri > pri)
    {
        x->n=*h;
        *h=x;
    }
    else
    {
        while(t->n!=N && t->n->pri <= pri)
            t=t->n;
        x->n=t->n;
        t->n=x;
    }
}
node* del(node **h)
{
    node *t;
    char z;
    if(*h==N)
        return N;
    else
    {
        t=*h;
        *h=(*h)->n;
    }
    return t;
}
int count_node(node *h)
{
    int c=1;
    if(h==N)
        return 0;
    else
    {
        while(h->n!=N)
        {
            c++;
            h=h->n;
        }
    }
    return c;
}
void insert_h(node **h,node *c)
{
    node *t=*h;
    if(*h==N || (*h)->pri > c->pri)
    {
        c->n=*h;
        *h=c;
    }
    else
    {
        while(t->n!=N && t->n->pri <= c->pri)
            t=t->n;
        c->n=t->n;
        t->n=c;
    }
}
node* merge(node *h1,node *h2)
{
    node *h3=(node*)malloc(sizeof(node));
    h3->pri=h1->pri+h2->pri;
    if(h3==N)
    {
        return;
    }
    else if(h1->r==N && h1->l==N && h2->r!=N && h2->l!=N)
    {
        h3->l=h2;
        h3->r=h1;
    }
    else if(h1->r!=N && h1->l!=N && h2->r==N && h2->l==N)
    {
        h3->r=h2;
        h3->l=h1;
    }
    else
    {
        h3->l=h1;
        h3->r=h2;
    }
    return h3;
}
node* hoffman(node **h)
{
    node *a,*b,*c;
    while(count_node(*h)!=1)
    {
        a=del(h);
        b=del(h);
        c=merge(a,b);
        insert_h(h,c);
    }
    return c;
}

/*node* findmin(node *h)
{
    node *pt=N,*min=h,*t=h->n;;
    while(t!=N)
    {
        if(pt->n->pri < t->pri)
            min=t;
    }
    return t;
}*/
void inorder(node *h)
{
    if(h==N)
        return;
    else
    {
        inorder(h->l);
        printf("%4d",h->pri);
        inorder(h->r);
    }
}
void preorder(node *h)
{
    if(h==N)
        return;
    else
    {
        printf("%4d",h->pri);
        preorder(h->l);
        preorder(h->r);
    }
}
void postorder(node *h)
{
    if(h==N)
        return;
    else
    {
        postorder(h->l);
        postorder(h->r);
        printf("%4d",h->pri);
    }
}
int main()
{
    char data;
    int priority;
    node *h=N,*hof=N;
    printf("Enter your data (0 to terminate) and priority : \n");
    while(1)
    {
        printf("Enter data : ");
        scanf("%s",&data);
        if(data=='0')
            break;
        printf("Enter its priority : ");
        scanf("%d",&priority);
        printf("\n");
        insert(&h,data,priority);
    }
    hof=hoffman(&h);
    preorder(hof);
    printf("\n");
    inorder(hof);
    printf("\n");
    postorder(hof);
    printf("\n");
    return 0;
}
